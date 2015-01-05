///////////////////////////////////////////////////////////////////////////
// C++ code generated with wxFormBuilder (version Sep  8 2010)
// http://www.wxformbuilder.org/
//
// PLEASE DO "NOT" EDIT THIS FILE!
///////////////////////////////////////////////////////////////////////////

#include "tracedlggen.h"

///////////////////////////////////////////////////////////////////////////

TraceDlgGen::TraceDlgGen( wxWindow* parent, wxWindowID id, const wxString& title, const wxPoint& pos, const wxSize& size, long style ) : wxDialog( parent, id, title, pos, size, style )
{
	this->SetSizeHints( wxDefaultSize, wxDefaultSize );
	
	wxBoxSizer* bSizer1;
	bSizer1 = new wxBoxSizer( wxVERTICAL );
	
	m_Trace = new wxListBox( this, wxID_ANY, wxDefaultPosition, wxDefaultSize, 0, NULL, wxLB_SINGLE ); 
	m_Trace->SetFont( wxFont( 9, 76, 90, 90, false, wxEmptyString ) );
	m_Trace->SetMinSize( wxSize( 600,400 ) );
	
	bSizer1->Add( m_Trace, 1, wxALL|wxEXPAND, 5 );
	
	wxFlexGridSizer* fgSizer1;
	fgSizer1 = new wxFlexGridSizer( 0, 5, 0, 0 );
	fgSizer1->AddGrowableCol( 3 );
	fgSizer1->SetFlexibleDirection( wxBOTH );
	fgSizer1->SetNonFlexibleGrowMode( wxFLEX_GROWMODE_SPECIFIED );
	
	m_labType = new wxStaticText( this, wxID_ANY, wxT("Type"), wxDefaultPosition, wxDefaultSize, 0 );
	m_labType->Wrap( -1 );
	fgSizer1->Add( m_labType, 0, wxALIGN_RIGHT|wxALIGN_CENTER_VERTICAL|wxTOP|wxBOTTOM|wxLEFT, 5 );
	
	m_ObjectType = new wxComboBox( this, wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize, 0, NULL, 0 ); 
	m_ObjectType->SetMinSize( wxSize( 140,-1 ) );
	
	fgSizer1->Add( m_ObjectType, 0, wxALL|wxALIGN_CENTER_VERTICAL, 5 );
	
	m_labID = new wxStaticText( this, wxID_ANY, wxT("ID"), wxDefaultPosition, wxDefaultSize, 0 );
	m_labID->Wrap( -1 );
	fgSizer1->Add( m_labID, 0, wxALIGN_CENTER_VERTICAL|wxALIGN_RIGHT|wxTOP|wxBOTTOM|wxLEFT, 5 );
	
	m_ID = new wxTextCtrl( this, wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize, 0 );
	fgSizer1->Add( m_ID, 0, wxALL|wxEXPAND, 5 );
	
	m_Search = new wxButton( this, wxID_ANY, wxT("Search"), wxDefaultPosition, wxDefaultSize, 0 );
	fgSizer1->Add( m_Search, 0, wxALL|wxALIGN_CENTER_VERTICAL, 5 );
	
	bSizer1->Add( fgSizer1, 0, wxEXPAND, 5 );
	
	wxBoxSizer* bSizer2;
	bSizer2 = new wxBoxSizer( wxHORIZONTAL );
	
	m_Open = new wxButton( this, wxID_ANY, wxT("Open..."), wxDefaultPosition, wxDefaultSize, 0 );
	bSizer2->Add( m_Open, 0, wxALL|wxALIGN_CENTER_VERTICAL, 5 );
	
	bSizer1->Add( bSizer2, 0, wxEXPAND, 5 );
	
	m_stdButton = new wxStdDialogButtonSizer();
	m_stdButtonOK = new wxButton( this, wxID_OK );
	m_stdButton->AddButton( m_stdButtonOK );
	m_stdButtonHelp = new wxButton( this, wxID_HELP );
	m_stdButton->AddButton( m_stdButtonHelp );
	m_stdButton->Realize();
	bSizer1->Add( m_stdButton, 0, wxEXPAND|wxALL, 5 );
	
	this->SetSizer( bSizer1 );
	this->Layout();
	bSizer1->Fit( this );
	
	this->Centre( wxBOTH );
	
	// Connect Events
	m_ObjectType->Connect( wxEVT_COMMAND_COMBOBOX_SELECTED, wxCommandEventHandler( TraceDlgGen::onObjectType ), NULL, this );
	m_Search->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( TraceDlgGen::onSearch ), NULL, this );
	m_Open->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( TraceDlgGen::onOpen ), NULL, this );
	m_stdButtonHelp->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( TraceDlgGen::onHelp ), NULL, this );
	m_stdButtonOK->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( TraceDlgGen::onOK ), NULL, this );
}

TraceDlgGen::~TraceDlgGen()
{
	// Disconnect Events
	m_ObjectType->Disconnect( wxEVT_COMMAND_COMBOBOX_SELECTED, wxCommandEventHandler( TraceDlgGen::onObjectType ), NULL, this );
	m_Search->Disconnect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( TraceDlgGen::onSearch ), NULL, this );
	m_Open->Disconnect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( TraceDlgGen::onOpen ), NULL, this );
	m_stdButtonHelp->Disconnect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( TraceDlgGen::onHelp ), NULL, this );
	m_stdButtonOK->Disconnect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( TraceDlgGen::onOK ), NULL, this );
	
}
