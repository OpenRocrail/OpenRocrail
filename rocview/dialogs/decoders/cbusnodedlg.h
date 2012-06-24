/*
 Rocrail - Model Railroad Software

 Copyright (C) 2002-2012 Rob Versluis, Rocrail.net

 Without an official permission commercial use is not permitted.
 Forking this project is not permitted.

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

#ifndef __cbusnodedlg__
#define __cbusnodedlg__

/**
@file
Subclass of cbusnodedlggen, which is generated by wxFormBuilder.
*/
#include "wx/timer.h"

#include "cbusnodedlggen.h"
#include "rocs/public/node.h"
#include "rocs/public/queue.h"

typedef struct {
  int cfg;
  int addr;
  int nn;
} Port;

typedef struct {
  int cfg;
  int swaddr;
  int swnn;
  int fbaddr;
  int left;
  int right;
  int speedL;
  int speedR;
} Servo;

#define SERVOCONF_POLAR  0x01
#define SERVOCONF_EXTSEN 0x02
#define SERVOCONF_BOUNCE 0x04


/** Implementing cbusnodedlggen */
class CBusNodeDlg : public cbusnodedlggen
{
  Port m_Ports[16];
  Servo m_Servo[4];
  int m_SOD;
  bool m_SaveOutputState;
  bool m_ShortEvents;
  bool m_SODAll;
  int m_PulseTime;
  int m_GC2IgnorePortTest;
  int m_CANID;
  iONode m_CBus;

  void initLabels();
  void init(iONode event);
  void initIndex();
  void initVarList(iONode node);
  void initEvtList(iONode node);
  void initType(int manu, int mtype, const char* ver);
  void selectPage4Type( int manu, int mtype );
  const char* getType( int manu, int mtype );
  const char* getTypeDesc( int manu, int mtype );
  const char* getManu( int manu );
  iONode getNode(int nr, int mtype, int manu, const char* ver, int canid=0);
  iONode getNodeVar(int nn, int mtype, int nr, int val);
  iONode getNodeEvent(int nn, int mtype, int evnn, int evaddr, int evnr, int evval);
  void gc2GetPort(int port, int* conf, int* nn, int* addr);
  void gc2SetPort(int port, int conf, int nn, int addr);
  void varGet(int nr);
  void varSet( int idx, int val, bool update );
  void eventGetAll();
  void initGC2Var(int nr, int val);
  void initGC2Event(int idx, int nn, int addr);
  void setLearn();
  void setUnlearn();
  void eventSet( int nn, int addr, int idx, int val, bool update );
  void initGC7Var(int nr, int val);
  void initGC6Var(int nr, int val);
  void initGC4Var(int nr, int val);
  void initGC1eVar(int nr, int val);
  void initGCLNVar(int nr, int val);
  void initGCLNEvent(int idx, int nn, int addr);
  void initGC6Event(int idx, int nn, int addr);
  void initGC4Event(int idx, int nn, int addr);
  void gc6GetServoConf(int servo, int idx, int* conf);
  void gc6GetServoEvent(int servo, int idx, int* nn, int* addr);
  void gc6SetServoConf(int servo, int idx, int conf);
  void gc6SetServoEvent(int idx, int nn, int addr);
  void gc6UpdateServoEvent(int servo);
  void initGC8Var(int nr, int val);
  void initGC8Event(int idx, int nn, int addr);

  wxTimer* m_Timer;
  iOQueue m_Queue;
  int m_GC2SetIndex;
  int m_GC6SetIndex;
  int m_GC4SetIndex;
  int m_GC1eSetIndex;
  int m_GCLNSetIndex;
  int m_GC8SetIndex;

  int m_SetPage;
  bool m_bGC2GetAll;
  bool m_bGC2SetAll;
  bool m_bGC7GetAll;
  bool m_bGC6GetAll;
  bool m_bGC6SetAll;
  bool m_bGC4GetAll;
  bool m_bGC4SetAll;
  bool m_bGC1eGetAll;
  bool m_bGC1eSetAll;
  bool m_bGCLNGetAll;
  bool m_bGCLNSetAll;
  bool m_bGC8GetAll;
  bool m_bGC8SetAll;

  unsigned char m_GC4AllowedRFID[5][5];

protected:
	// Handlers for cbusnodedlggen events.
	void onOK( wxCommandEvent& event );
  void onSetNodeNumber( wxCommandEvent& event );
  void onIndexSelect2( wxListEvent& event );
  void onIndexActivated( wxListEvent& event );
  void onVarSelect( wxCommandEvent& event );
  void onVarValue( wxSpinEvent& event );
  void onVarBit( wxCommandEvent& event );
  void onVarGet( wxCommandEvent& event );
  void onVarSet( wxCommandEvent& event );
  void onEventSelect( wxCommandEvent& event );
  void onEventGetAll( wxCommandEvent& event );
  void onEventAdd( wxCommandEvent& event );
  void onEventDelete( wxCommandEvent& event );
  void onEvtGetVar( wxCommandEvent& event );
  void onEV( wxSpinEvent& event );
  void onEVBit( wxCommandEvent& event );
  void onLearn( wxCommandEvent& event );
  void onUnlearn( wxCommandEvent& event );
  void onEvtClearAll( wxCommandEvent& event );
  void onHexFile( wxCommandEvent& event );
  void onHEXFileSend( wxCommandEvent& event );
  void onBootmode( wxCommandEvent& event );
  void onResetBoot( wxCommandEvent& event );
  void onGC2GetAll( wxCommandEvent& event );
  void onGC2SetAll( wxCommandEvent& event );
  void onGC2Test( wxCommandEvent& event );
  void onGC2Set( wxCommandEvent& event );
  void onSoD( wxCommandEvent& event );
  void onVarValueText( wxCommandEvent& event );
  void onEVText( wxCommandEvent& event );
  void onQuery( wxCommandEvent& event );
  void onGC7ShowDate( wxCommandEvent& event );
  void onGC7ShowTemp( wxCommandEvent& event );
  void onGC7PosDisplay( wxCommandEvent& event );
  void onGC7Intensity( wxScrollEvent& event );
  void onGC7GetAll( wxCommandEvent& event );
  void onGC7SetCanID( wxCommandEvent& event );
  void OnServoSelect( wxCommandEvent& event );
  void OnServoLeftAngle( wxScrollEvent& event );
  void OnServoRightAngle( wxScrollEvent& event );
  void OnServoSpeed( wxScrollEvent& event );
  void OnServoRelay( wxCommandEvent& event );
  void onGC6GetAll( wxCommandEvent& event );
  void onGC6SetAll( wxCommandEvent& event );
  void OnExtSensors( wxCommandEvent& event );
  void OnBounce( wxCommandEvent& event );
  void onGC4GetAll( wxCommandEvent& event );
  void onGC4SetAll( wxCommandEvent& event );
  void onGC1eGetAll( wxCommandEvent& event );
  void onGC1eSetAll( wxCommandEvent& event );
  void onGC1eIdleWatchDog( wxCommandEvent& event );
  void onGC2PortType1( wxCommandEvent& event );
  void onGC2PortType2( wxCommandEvent& event );
  void onGC2PortType3( wxCommandEvent& event );
  void onGC2PortType4( wxCommandEvent& event );
  void onGC2PortType5( wxCommandEvent& event );
  void onGC2PortType6( wxCommandEvent& event );
  void onGC2PortType7( wxCommandEvent& event );
  void onGC2PortType8( wxCommandEvent& event );
  void onGC2PortType9( wxCommandEvent& event );
  void onGC2PortType10( wxCommandEvent& event );
  void onGC2PortType11( wxCommandEvent& event );
  void onGC2PortType12( wxCommandEvent& event );
  void onGC2PortType13( wxCommandEvent& event );
  void onGC2PortType14( wxCommandEvent& event );
  void onGC2PortType15( wxCommandEvent& event );
  void onGC2PortType16( wxCommandEvent& event );
  void onGCLNGetAll( wxCommandEvent& event );
  void onGCLNSetAll( wxCommandEvent& event );
  void onGC8GetAll( wxCommandEvent& event );
  void onGC8SetAll( wxCommandEvent& event );


public:
	/** Constructor */
	CBusNodeDlg( wxWindow* parent, iONode event );
  CBusNodeDlg( wxWindow* parent );
  void event( iONode event );
  void onSetPage(wxCommandEvent& event);
  void OnTimer(wxTimerEvent& event);

};

#endif // __cbusnodedlg__
