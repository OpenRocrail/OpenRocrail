/* Rocrail - Model Railroad Software Copyright (C) 2002-2014 Rob Versluis, Rocrail.net This program is free software; you can redistribute it and/or modify it under the terms of the GNU General Public License as published by the Free Software Foundation; either version 3 of the License, or (at your option) any later version. This program is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU General Public License for more details. You should have received a copy of the GNU General Public License along with this program; if not, write to the Free Software Foundation, Inc., 59 Temple Place - Suite 330, Boston, MA  02111-1307, USA.*/#include "weatherdlg.h"#include "rocview/public/guiapp.h"#include "rocrail/wrapper/public/Weather.h"#include "rocrail/wrapper/public/Sunrise.h"#include "rocrail/wrapper/public/Noon.h"#include "rocrail/wrapper/public/Sunset.h"#include "rocrail/wrapper/public/Night.h"#include "rocrail/wrapper/public/Output.h"#include "rocrail/wrapper/public/ModelCmd.h"#include "rocrail/wrapper/public/WeatherTheme.h"WeatherDlg::WeatherDlg( wxWindow* parent, iONode props ):WeatherDlgGen( parent ){  m_Props = props;  initLabels();  GetSizer()->Fit(this);  GetSizer()->SetSizeHints(this);  GetSizer()->Layout();  initValues();  initThemeIndex();}void WeatherDlg::onCancel( wxCommandEvent& event ){  EndModal(0);}void WeatherDlg::initLabels() {  SetTitle(wxGetApp().getMsg( "weather" ));  m_WeatherBook->SetPageText( 0, wxGetApp().getMsg( "day" ) );  m_WeatherBook->SetPageText( 1, wxGetApp().getMsg( "night" ) );  m_WeatherBook->SetPageText( 2, wxGetApp().getMsg( "theme" ) );  m_SunriseBox->GetStaticBox()->SetLabel( wxGetApp().getMsg( "sunrise" ) );  m_NoonBox->GetStaticBox()->SetLabel( wxGetApp().getMsg( "noon" ) );  m_SunsetBox->GetStaticBox()->SetLabel( wxGetApp().getMsg( "sunset" ) );  m_labOutputs->SetLabel( wxGetApp().getMsg( "outputs" ) );  m_labMaxBri->SetLabel( wxGetApp().getMsg( "maxbri" ) );  m_labMinBri->SetLabel( wxGetApp().getMsg( "minbri" ) );  m_labColorSliding->SetLabel( wxGetApp().getMsg( "colorsliding" ) );  m_SlidingDaylight->SetLabel( wxGetApp().getMsg( "slidingdaylight" ) );  m_labSunriseTime->SetLabel( wxGetApp().getMsg( "time" ) );  m_labSunsetTime->SetLabel( wxGetApp().getMsg( "time" ) );  m_labRGBSunrise->SetLabel( wxGetApp().getMsg( "rgb" ) );  m_labRGBNoon->SetLabel( wxGetApp().getMsg( "rgb" ) );  m_labRGBSunset->SetLabel( wxGetApp().getMsg( "rgb" ) );  m_labOutputsNight->SetLabel( wxGetApp().getMsg( "outputs" ) );  m_labBrightnessNight->SetLabel( wxGetApp().getMsg( "brightness" ) );  m_ThemeAdd->SetLabel( wxGetApp().getMsg( "add" ) );  m_ThemeModify->SetLabel( wxGetApp().getMsg( "modify" ) );  m_ThemeDelete->SetLabel( wxGetApp().getMsg( "delete" ) );  m_labThemeID->SetLabel( wxGetApp().getMsg( "id" ) );  m_labThemeOutputs->SetLabel( wxGetApp().getMsg( "outputs" ) );  m_labThemeSound->SetLabel( wxGetApp().getMsg( "sound" ) );  m_labThemeDim->SetLabel( wxGetApp().getMsg( "dim" ) );  m_labThemeTime->SetLabel( wxGetApp().getMsg( "time" ) );  m_labThemeDuration->SetLabel( wxGetApp().getMsg( "duration" ) );  m_labThemeRandom->SetLabel( wxGetApp().getMsg( "random" ) );}void WeatherDlg::initValues() {  m_Outputs->SetValue( wxString(wWeather.getoutputs(m_Props),wxConvUTF8) );  m_MaxBri->SetValue( wWeather.getmaxbri(m_Props) );  m_MinBri->SetValue( wWeather.getminbri(m_Props) );  m_ColorSliding->SetValue( wWeather.getcolorsliding(m_Props) );  m_SlidingDaylight->SetValue(wWeather.isslidingdaylight(m_Props)?true:false);  iONode sunrise = wWeather.getsunrise(m_Props);  if( sunrise == NULL ) {    sunrise = NodeOp.inst(wSunrise.name(), m_Props, ELEMENT_NODE );    NodeOp.addChild(m_Props, sunrise);  }  m_SunriseHour->SetValue( wSunrise.gethour( sunrise ) );  m_SunriseMin->SetValue( wSunrise.getminute( sunrise ) );  m_SunriseRed->SetValue( wSunrise.getred( sunrise ) );  m_SunriseGreen->SetValue( wSunrise.getgreen( sunrise ) );  m_SunriseBlue->SetValue( wSunrise.getblue( sunrise ) );  iONode noon = wWeather.getnoon(m_Props);  if( noon == NULL ) {    noon = NodeOp.inst(wNoon.name(), m_Props, ELEMENT_NODE );    NodeOp.addChild(m_Props, noon);  }  m_NoonRed->SetValue( wNoon.getred( noon ) );  m_NoonGreen->SetValue( wNoon.getgreen( noon ) );  m_NoonBlue->SetValue( wNoon.getblue( noon ) );  iONode sunset = wWeather.getsunset(m_Props);  if( sunset == NULL ) {    sunset = NodeOp.inst(wSunset.name(), m_Props, ELEMENT_NODE );    NodeOp.addChild(m_Props, sunset);  }  m_SunsetHour->SetValue( wSunset.gethour( sunset ) );  m_SunsetMin->SetValue( wSunset.getminute( sunset ) );  m_SunsetRed->SetValue( wSunset.getred( sunset ) );  m_SunsetGreen->SetValue( wSunset.getgreen( sunset ) );  m_SunsetBlue->SetValue( wSunset.getblue( sunset ) );  iONode night = wWeather.getnight(m_Props);  if( night == NULL ) {    night = NodeOp.inst(wNight.name(), m_Props, ELEMENT_NODE );    NodeOp.addChild(m_Props, night);  }  m_OutputsNight->SetValue( wxString(wNight.getoutputs(night),wxConvUTF8) );  m_BrightnessNight->SetValue( wNight.getbri(night) );  m_RedNight->SetValue( wNight.getred(night) );  m_GreenNight->SetValue( wNight.getgreen(night) );  m_BlueNight->SetValue( wNight.getblue(night) );}bool WeatherDlg::evaluate() {  wWeather.setoutputs( m_Props, m_Outputs->GetValue().mb_str(wxConvUTF8) );  wWeather.setmaxbri(m_Props, m_MaxBri->GetValue() );  wWeather.setminbri(m_Props, m_MinBri->GetValue() );  wWeather.setcolorsliding(m_Props, m_ColorSliding->GetValue() );  wWeather.setslidingdaylight(m_Props, m_SlidingDaylight->IsChecked()?True:False);  iONode sunrise = wWeather.getsunrise(m_Props);  wSunrise.sethour( sunrise, m_SunriseHour->GetValue() );  wSunrise.setminute( sunrise, m_SunriseMin->GetValue() );  wSunrise.setred( sunrise, m_SunriseRed->GetValue() );  wSunrise.setgreen( sunrise, m_SunriseGreen->GetValue() );  wSunrise.setblue( sunrise, m_SunriseBlue->GetValue() );  iONode noon = wWeather.getnoon(m_Props);  wNoon.setred( noon, m_NoonRed->GetValue() );  wNoon.setgreen( noon, m_NoonGreen->GetValue() );  wNoon.setblue( noon, m_NoonBlue->GetValue() );  iONode sunset = wWeather.getsunset(m_Props);  wSunset.sethour( sunset, m_SunsetHour->GetValue() );  wSunset.setminute( sunset, m_SunsetMin->GetValue() );  wSunset.setred( sunset, m_SunsetRed->GetValue() );  wSunset.setgreen( sunset, m_SunsetGreen->GetValue() );  wSunset.setblue( sunset, m_SunsetBlue->GetValue() );  iONode night = wWeather.getnight(m_Props);  wNight.setoutputs( night, m_OutputsNight->GetValue().mb_str(wxConvUTF8) );  wNight.setbri(night, m_BrightnessNight->GetValue() );  wNight.setred(night, m_RedNight->GetValue() );  wNight.setgreen(night, m_GreenNight->GetValue() );  wNight.setblue(night, m_BlueNight->GetValue() );  return true;}void WeatherDlg::onOK( wxCommandEvent& event ){  evaluate();  evaluateTheme();  if( !wxGetApp().isStayOffline() ) {    /* Notify RocRail. */    iONode cmd = NodeOp.inst( wModelCmd.name(), NULL, ELEMENT_NODE );    wModelCmd.setcmd( cmd, wModelCmd.modify );    NodeOp.addChild( cmd, (iONode)NodeOp.base.clone( m_Props ) );    wxGetApp().sendToRocrail( cmd );    cmd->base.del(cmd);  }  else {    wxGetApp().setLocalModelModified(true);  }  EndModal( wxID_OK );}void WeatherDlg::onHelp( wxCommandEvent& event ) {  wxGetApp().openLink( "weather" );}void WeatherDlg::initThemeValues() {  if( m_ThemeList->GetSelection() != wxNOT_FOUND ) {    iONode weathertheme = (iONode)m_ThemeList->GetClientData(m_ThemeList->GetSelection());    m_ThemeID->SetValue( wxString(wWeatherTheme.getid(weathertheme),wxConvUTF8) );    m_ThemeOutputs->SetValue( wxString(wWeatherTheme.getoutputs(weathertheme),wxConvUTF8) );    m_ThemeSound->SetValue( wxString(wWeatherTheme.getsound(weathertheme),wxConvUTF8) );    m_ThemeDim->SetValue( wWeatherTheme.getdim(weathertheme) );    m_ThemeHour->SetValue( wWeatherTheme.gethour(weathertheme) );    m_ThemeMinute->SetValue( wWeatherTheme.getminute(weathertheme) );    m_ThemeDuration->SetValue( wWeatherTheme.getduration(weathertheme) );    m_ThemeRandom->SetValue( wWeatherTheme.israndom(weathertheme) ? true:false);  }  else {    m_ThemeID->SetValue( wxString("",wxConvUTF8) );    m_ThemeOutputs->SetValue( wxString("",wxConvUTF8) );    m_ThemeSound->SetValue( wxString("",wxConvUTF8) );    m_ThemeDim->SetValue( 0 );    m_ThemeHour->SetValue( 0 );    m_ThemeMinute->SetValue( 0 );    m_ThemeDuration->SetValue( 0 );    m_ThemeRandom->SetValue( false);  }}void WeatherDlg::initThemeIndex() {  int prevSel = m_ThemeList->GetSelection();  m_ThemeList->Clear();  iONode weathertheme = wWeather.getweathertheme(m_Props);  while( weathertheme != NULL ) {    m_ThemeList->Append( wxString(wWeatherTheme.getid(weathertheme),wxConvUTF8), weathertheme );    weathertheme = wWeather.nextweathertheme(m_Props, weathertheme);  }  if( prevSel != wxNOT_FOUND ) {    m_ThemeList->SetSelection( prevSel );  }}bool WeatherDlg::evaluateTheme() {  if( m_ThemeList->GetSelection() != wxNOT_FOUND ) {    iONode weathertheme = (iONode)m_ThemeList->GetClientData(m_ThemeList->GetSelection());    wWeatherTheme.setid( weathertheme, m_ThemeID->GetValue().mb_str(wxConvUTF8) );    wWeatherTheme.setoutputs( weathertheme, m_ThemeOutputs->GetValue().mb_str(wxConvUTF8) );    wWeatherTheme.setsound( weathertheme, m_ThemeSound->GetValue().mb_str(wxConvUTF8) );    wWeatherTheme.setdim( weathertheme, m_ThemeDim->GetValue() );    wWeatherTheme.sethour( weathertheme, m_ThemeHour->GetValue() );    wWeatherTheme.setminute( weathertheme, m_ThemeMinute->GetValue() );    wWeatherTheme.setduration( weathertheme, m_ThemeDuration->GetValue() );    wWeatherTheme.setrandom( weathertheme, m_ThemeRandom->IsChecked() ? True:False);    initThemeIndex();  }  return true;}void WeatherDlg::onThemeSelected( wxCommandEvent& event ) {  initThemeValues();}void WeatherDlg::onThemeAdd( wxCommandEvent& event ) {  int i = m_ThemeList->FindString( _T("NEW") );  if( i == wxNOT_FOUND ) {    iONode weathertheme = NodeOp.inst( wWeatherTheme.name(), m_Props, ELEMENT_NODE );    NodeOp.addChild( m_Props, weathertheme );    wWeatherTheme.setid( weathertheme, "NEW" );    initThemeValues();    m_ThemeList->Append( _T("NEW"), weathertheme );  }  m_ThemeList->SetStringSelection( _T("NEW") );  m_ThemeList->SetFirstItem( _T("NEW") );  initThemeValues();}void WeatherDlg::onThemeModify( wxCommandEvent& event ) {  evaluateTheme();}void WeatherDlg::onThemeDelete( wxCommandEvent& event ) {  if( m_ThemeList->GetSelection() != wxNOT_FOUND ) {    iONode weathertheme = (iONode)m_ThemeList->GetClientData(m_ThemeList->GetSelection());    if( weathertheme != NULL ) {      NodeOp.removeChild(m_Props, weathertheme);      m_ThemeList->Clear();      initThemeIndex();      initThemeValues();    }  }}