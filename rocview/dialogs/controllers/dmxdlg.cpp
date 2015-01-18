/*
 Rocrail - Model Railroad Software

 Copyright (C) 2002-2015 Rob Versluis, Rocrail.net

 This program is free software; you can redistribute it and/or
 modify it under the terms of the GNU General Public License
 as published by the Free Software Foundation; either version 2
 of the License, or (at your option) any later version.

 This program is distributed in the hope that it will be useful,
 but WITHOUT ANY WARRANTY; without even the implied warranty of
 MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 GNU General Public License for more details.

 You should have received a copy of the GNU General Public License
 along with this program; if not, write to the Free Software
 Foundation, Inc., 59 Temple Place - Suite 330, Boston, MA  02111-1307, USA.
*/


#include "dmxdlg.h"

#include "rocview/public/guiapp.h"

#include "rocrail/wrapper/public/DigInt.h"
#include "rocrail/wrapper/public/DMX.h"

DmxDlg::DmxDlg( wxWindow* parent, iONode props ):dmxdlggen( parent )
{
  m_Props = props;
  initLabels();
  // Resize
  GetSizer()->Layout();
  GetSizer()->Fit(this);
  GetSizer()->SetSizeHints(this);
  initValues();
}

void DmxDlg::onCancel( wxCommandEvent& event )
{
  EndModal(0);
}

void DmxDlg::onHelp( wxCommandEvent& event )
{
  wxGetApp().openLink( "dmx:artnet" );
}

void DmxDlg::onOK( wxCommandEvent& event )
{
  evaluate();
  EndModal( wxID_OK );
}

void DmxDlg::initLabels() {
  m_labIID->SetLabel(wxGetApp().getMsg( "iid" ));
  m_labHost->SetLabel(wxGetApp().getMsg( "host" ));
  m_labFixturChannels->SetLabel(wxGetApp().getMsg( "fixturchannels" ));
}

void DmxDlg::initValues() {
  iONode dmxini = wDigInt.getdmx(m_Props);
  if( dmxini == NULL ) {
    dmxini = NodeOp.inst(wDMX.name(), m_Props, ELEMENT_NODE);
    NodeOp.addChild(m_Props, dmxini);
  }

  m_IID->SetValue( wxString( wDigInt.getiid( m_Props ), wxConvUTF8 ) );
  m_Host->SetValue( wxString( wDigInt.gethost( m_Props ), wxConvUTF8 ) );
  m_FixturChannels->SetValue(wDMX.getfixturchannels(dmxini));
}

bool DmxDlg::evaluate() {
  iONode dmxini = wDigInt.getdmx(m_Props);
  wDigInt.setiid( m_Props, m_IID->GetValue().mb_str(wxConvUTF8) );
  wDigInt.sethost( m_Props, m_Host->GetValue().mb_str(wxConvUTF8) );
  wDMX.setfixturchannels(dmxini, m_FixturChannels->GetValue());
  return true;
}

