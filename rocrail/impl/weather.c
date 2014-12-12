/*
 Rocrail - Model Railroad Software

 Copyright (C) 2002-2014 Rob Versluis, Rocrail.net

 This program is free software; you can redistribute it and/or
 modify it under the terms of the GNU General Public License
 as published by the Free Software Foundation; either version 3
 of the License, or (at your option) any later version.

 This program is distributed in the hope that it will be useful,
 but WITHOUT ANY WARRANTY; without even the implied warranty of
 MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 GNU General Public License for more details.

 You should have received a copy of the GNU General Public License
 along with this program; if not, write to the Free Software
 Foundation, Inc., 59 Temple Place - Suite 330, Boston, MA  02111-1307, USA.
*/


#include "rocrail/impl/weather_impl.h"

#include <time.h>

#include "rocs/public/mem.h"
#include "rocs/public/trace.h"
#include "rocs/public/node.h"
#include "rocs/public/thread.h"
#include "rocs/public/strtok.h"
#include "rocs/public/list.h"

#include "rocrail/public/app.h"
#include "rocrail/public/control.h"
#include "rocrail/public/output.h"
#include "rocrail/public/model.h"

#include "rocrail/wrapper/public/Weather.h"
#include "rocrail/wrapper/public/Sunrise.h"
#include "rocrail/wrapper/public/Sunset.h"
#include "rocrail/wrapper/public/Night.h"
#include "rocrail/wrapper/public/Output.h"
#include "rocrail/wrapper/public/Color.h"


static int instCnt = 0;

/** ----- OBase ----- */
static void __del( void* inst ) {
  if( inst != NULL ) {
    iOWeatherData data = Data(inst);
    /* Cleanup data->xxx members...*/
    
    freeMem( data );
    freeMem( inst );
    instCnt--;
  }
  return;
}

static const char* __name( void ) {
  return name;
}

static unsigned char* __serialize( void* inst, long* size ) {
  return NULL;
}

static void __deserialize( void* inst,unsigned char* bytestream ) {
  return;
}

static char* __toString( void* inst ) {
  return NULL;
}

static int __count( void ) {
  return instCnt;
}

static struct OBase* __clone( void* inst ) {
  return NULL;
}

static Boolean __equals( void* inst1, void* inst2 ) {
  return False;
}

static void* __properties( void* inst ) {
  return NULL;
}

static const char* __id( void* inst ) {
  return NULL;
}

static void* __event( void* inst, const void* evt ) {
  return NULL;
}

/** ----- OWeather ----- */
static void __doDaylight(iOWeather weather, int hour, int min, Boolean shutdown ) {
  iOWeatherData data = Data(weather);
  iOModel model = AppOp.getModel();
  iOList list = ListOp.inst();
  iOList nightList = ListOp.inst();

  TraceOp.trc( name, TRCLEVEL_INFO, __LINE__, 9999, "do daylight at %02d:%02d on %s", hour, min, wWeather.getoutputs(data->props) );

  iOStrTok tok = StrTokOp.inst( wWeather.getoutputs(data->props), ',' );
  while( StrTokOp.hasMoreTokens(tok) ) {
    const char* id = StrTokOp.nextToken(tok);
    iOOutput output = ModelOp.getOutput(model, id);
    if( output != NULL ) {
      ListOp.add(list, (obj)output);
    }
  };
  StrTokOp.base.del(tok);

  if( ListOp.size(list) > 0 ) {
    iONode sunriseProps = wWeather.getsunrise(data->props);
    iONode sunsetProps  = wWeather.getsunset(data->props);
    iONode nightProps   = wWeather.getnight(data->props);

    if( sunriseProps == NULL ) {
      sunriseProps = NodeOp.inst(wSunrise.name(), data->props, ELEMENT_NODE );
      NodeOp.addChild(data->props, sunriseProps);
      wSunrise.sethour(sunriseProps, 6) ;
    }
    if( sunsetProps == NULL ) {
      sunsetProps = NodeOp.inst(wSunset.name(), data->props, ELEMENT_NODE );
      NodeOp.addChild(data->props, sunsetProps);
      wSunset.sethour(sunsetProps, 18) ;
    }
    if( nightProps == NULL ) {
      nightProps = NodeOp.inst(wNight.name(), data->props, ELEMENT_NODE );
      NodeOp.addChild(data->props, nightProps);
    }

    iOStrTok tok = StrTokOp.inst( wNight.getoutputs(nightProps), ',' );
    while( StrTokOp.hasMoreTokens(tok) ) {
      const char* id = StrTokOp.nextToken(tok);
      iOOutput output = ModelOp.getOutput(model, id);
      if( output != NULL ) {
        ListOp.add(nightList, (obj)output);
      }
    };
    StrTokOp.base.del(tok);



    int sunrise = wSunrise.gethour(sunriseProps) * 60 + wSunrise.getminute(sunriseProps);
    int noon    = 12 * 60;
    int sunset  = wSunset.gethour(sunsetProps) * 60 + wSunset.getminute(sunsetProps);

    float maxbri     = wWeather.getmaxbri(data->props);
    float minbri     = wWeather.getminbri(data->props);
    float percent    = 0.0;
    float brightness = 0.0;

    int daylight  = sunset - sunrise;
    int minutes   = hour * 60 + min;

    Boolean adjustBri = False;

    if( minutes <= noon && minutes > sunrise) {
      float range = noon - sunrise;
      percent = (100.0 / range) * (float)(minutes - sunrise);
      float l_brightness = (percent * maxbri) / 100.0;
      if( l_brightness != brightness ) {
        brightness = l_brightness;
        adjustBri = True;
      }
    }

    if( minutes > noon && minutes < sunset) {
      float range = sunset - noon;
      percent = 100.0 - ((100.0 / range) * (float)(minutes - noon));
      float l_brightness = (percent * maxbri) / 100.0;

      if( l_brightness != brightness ) {
        brightness = l_brightness;
        adjustBri = True;
      }
    }

    if(adjustBri || shutdown) {
      int LAMPS = ListOp.size(list);
      float segment = 180.0 / (float)(LAMPS-1);
      int n = 0;
      float angle = (180.0 / (float)(sunset - sunrise)) * (minutes-sunrise);

      for( n = 0; n < LAMPS; n++) {
        iOOutput output = (iOOutput)ListOp.get(list, n);
        int lampBri = 0;
        float lampangle = segment * n;
        if( lampangle + segment > angle && lampangle < angle + segment ) {
          float lampPercent = 0.0;

          if( angle < lampangle )
            lampPercent = 100.0 - ((100.0 / segment) * (lampangle - angle));
          else
            lampPercent = 100.0 - ((100.0 / segment) * (angle - lampangle));

          lampBri = (lampPercent * brightness) / 100.0;
        }
        else {
          lampBri = 0;
        }

        iONode cmd = NodeOp.inst( wOutput.name(), NULL, ELEMENT_NODE);
        wOutput.setaddr(cmd, wOutput.getaddr(OutputOp.base.properties(output)));
        TraceOp.trc( name, TRCLEVEL_INFO, __LINE__, 9999,
            "lamp %s brightness=%d(of %.2f), lampAngle=%.2f sunAngle=%.2f dayminutes=%d sunrise=%d sunset=%d",
            wOutput.getid(OutputOp.base.properties(output)), lampBri, brightness, lampangle, angle, minutes, sunrise, sunset );
        wOutput.setvalue(cmd, lampBri);
        wOutput.setcmd(cmd, shutdown?wOutput.off:wOutput.value);
        OutputOp.cmd(output, cmd, False);

      }
      adjustBri = False;
    }

    if( minutes+30 > sunset || minutes < sunrise-30 || shutdown ) {
      /* Night. */
      if( ListOp.size(nightList) > 0 ) {
        int LAMPS = ListOp.size(nightList);
        int bri = wNight.getbri(nightProps);
        int n = 0;

        if( minutes+30 > sunset ) {
          if( sunset - minutes > 0 ) {
            float l_bri = bri;
            l_bri = l_bri - ((l_bri / 30.0) * (sunset - minutes));
            bri = (int)l_bri;
          }
        }

        if( minutes-30 < sunrise ) {
          if( minutes - sunrise > 0 ) {
            float l_bri = bri;
            l_bri = l_bri - ((l_bri / 30.0) * (minutes - sunrise));
            bri = (int)l_bri;
          }
        }

        TraceOp.trc( name, TRCLEVEL_INFO, __LINE__, 9999, "night brightness=%d of %d", bri, wNight.getbri(nightProps));

        for( n = 0; n < LAMPS; n++) {
          iOOutput output = (iOOutput)ListOp.get(nightList, n);
          iONode cmd   = NodeOp.inst( wOutput.name(), NULL, ELEMENT_NODE);
          iONode color = NodeOp.inst( wColor.name(), cmd, ELEMENT_NODE);
          NodeOp.addChild( cmd, color );
          wOutput.setaddr(cmd, wOutput.getaddr(OutputOp.base.properties(output)));
          wOutput.setvalue(cmd, bri);
          wColor.setred(color, wNight.getred(nightProps));
          wColor.setgreen(color, wNight.getgreen(nightProps));
          wColor.setblue(color, wNight.getblue(nightProps));
          wOutput.setcmd(cmd, shutdown?wOutput.off:wOutput.value);
          OutputOp.cmd(output, cmd, False);
        }
      }
    }

  }
  ListOp.base.del(list);
  ListOp.base.del(nightList);

}


static void __checkWeatherThemes(iOWeather weather, int hour, int min ) {
  iOWeatherData data = Data(weather);

  TraceOp.trc( name, TRCLEVEL_DEBUG, __LINE__, 9999, "check weather themes at %02d:%02d", hour, min );
}


static void __makeWeather( void* threadinst ) {
  iOThread        th = (iOThread)threadinst;
  iOWeather  weather = (iOWeather)ThreadOp.getParm(th);
  iOWeatherData data = Data(weather);

  iOControl control = AppOp.getControl();
  int lastMin = 0;
  int loopCnt = 10;

  TraceOp.trc( name, TRCLEVEL_INFO, __LINE__, 9999, "make weather started..." );

  while( data->run ) {
    if( loopCnt >= 10 ) {
      loopCnt = 0;
      long t = ControlOp.getTime(control);
      struct tm* ltm = localtime( &t );
      int hour = ltm->tm_hour;
      int min  = ltm->tm_min;

      if( lastMin != ltm->tm_min ) {
        TraceOp.trc( name, TRCLEVEL_INFO, __LINE__, 9999, "weather time is %02d:%02d", hour, min );
        __doDaylight(weather, hour, min, False );
        __checkWeatherThemes(weather, hour, min );
        lastMin = min;
      }
    }
    else {
      loopCnt++;
    }

    ThreadOp.sleep(100);
  }
  __doDaylight(weather, 0, 0, True );

  TraceOp.trc( name, TRCLEVEL_INFO, __LINE__, 9999, "make weather ended..." );

}

static void _halt( iOWeather inst ) {
  iOWeatherData data = Data(inst);
  data->run = False;
  ThreadOp.sleep(120);
}


/**  */
static struct OWeather* _inst( iONode ini ) {
  iOWeather __Weather = allocMem( sizeof( struct OWeather ) );
  iOWeatherData data = allocMem( sizeof( struct OWeatherData ) );
  MemOp.basecpy( __Weather, &WeatherOp, 0, sizeof( struct OWeather ), data );

  /* Initialize data->xxx members... */
  data->props = ini;
  data->run = True;

  data->makeWeather = ThreadOp.inst( "makeWeather", __makeWeather, __Weather );
  ThreadOp.start( data->makeWeather );

  instCnt++;
  return __Weather;
}


/* ----- DO NOT REMOVE OR EDIT THIS INCLUDE LINE! -----*/
#include "rocrail/impl/weather.fm"
/* ----- DO NOT REMOVE OR EDIT THIS INCLUDE LINE! -----*/
