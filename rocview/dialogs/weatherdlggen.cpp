///////////////////////////////////////////////////////////////////////////
// C++ code generated with wxFormBuilder (version Sep  8 2010)
// http://www.wxformbuilder.org/
//
// PLEASE DO "NOT" EDIT THIS FILE!
///////////////////////////////////////////////////////////////////////////

#include "weatherdlggen.h"

///////////////////////////////////////////////////////////////////////////

WeatherDlgGen::WeatherDlgGen( wxWindow* parent, wxWindowID id, const wxString& title, const wxPoint& pos, const wxSize& size, long style ) : wxDialog( parent, id, title, pos, size, style )
{
	this->SetSizeHints( wxDefaultSize, wxDefaultSize );
	
	wxBoxSizer* bSizer1;
	bSizer1 = new wxBoxSizer( wxVERTICAL );
	
	m_WeatherBook = new wxNotebook( this, wxID_ANY, wxDefaultPosition, wxDefaultSize, 0 );
	m_IndexPanel = new wxPanel( m_WeatherBook, wxID_ANY, wxDefaultPosition, wxDefaultSize, wxTAB_TRAVERSAL );
	wxBoxSizer* bSizer5;
	bSizer5 = new wxBoxSizer( wxVERTICAL );
	
	m_IndexList = new wxListBox( m_IndexPanel, wxID_ANY, wxDefaultPosition, wxDefaultSize, 0, NULL, 0 ); 
	bSizer5->Add( m_IndexList, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxEXPAND, 5 );
	
	wxBoxSizer* bSizer6;
	bSizer6 = new wxBoxSizer( wxHORIZONTAL );
	
	m_AddWeather = new wxButton( m_IndexPanel, wxID_ANY, wxT("Add"), wxDefaultPosition, wxDefaultSize, 0 );
	bSizer6->Add( m_AddWeather, 0, wxALL|wxALIGN_CENTER_VERTICAL, 5 );
	
	m_DeleteWeather = new wxButton( m_IndexPanel, wxID_ANY, wxT("Delete"), wxDefaultPosition, wxDefaultSize, 0 );
	bSizer6->Add( m_DeleteWeather, 0, wxALL|wxALIGN_CENTER_VERTICAL, 5 );
	
	m_ActivateWeather = new wxButton( m_IndexPanel, wxID_ANY, wxT("Activate"), wxDefaultPosition, wxDefaultSize, 0 );
	bSizer6->Add( m_ActivateWeather, 0, wxALL|wxALIGN_CENTER_VERTICAL, 5 );
	
	bSizer5->Add( bSizer6, 0, wxEXPAND, 5 );
	
	m_IndexPanel->SetSizer( bSizer5 );
	m_IndexPanel->Layout();
	bSizer5->Fit( m_IndexPanel );
	m_WeatherBook->AddPage( m_IndexPanel, wxT("Index"), true );
	m_DayPanel = new wxPanel( m_WeatherBook, wxID_ANY, wxDefaultPosition, wxDefaultSize, wxTAB_TRAVERSAL );
	wxBoxSizer* bSizer2;
	bSizer2 = new wxBoxSizer( wxVERTICAL );
	
	wxFlexGridSizer* fgSizer1;
	fgSizer1 = new wxFlexGridSizer( 0, 2, 0, 0 );
	fgSizer1->AddGrowableCol( 1 );
	fgSizer1->SetFlexibleDirection( wxBOTH );
	fgSizer1->SetNonFlexibleGrowMode( wxFLEX_GROWMODE_SPECIFIED );
	
	m_labID = new wxStaticText( m_DayPanel, wxID_ANY, wxT("ID"), wxDefaultPosition, wxDefaultSize, 0 );
	m_labID->Wrap( -1 );
	fgSizer1->Add( m_labID, 0, wxALL|wxALIGN_RIGHT|wxALIGN_CENTER_VERTICAL, 5 );
	
	m_ID = new wxTextCtrl( m_DayPanel, wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize, 0 );
	fgSizer1->Add( m_ID, 0, wxALL|wxEXPAND|wxALIGN_CENTER_VERTICAL, 5 );
	
	m_labOutputs = new wxStaticText( m_DayPanel, wxID_ANY, wxT("Outputs"), wxDefaultPosition, wxDefaultSize, 0 );
	m_labOutputs->Wrap( -1 );
	fgSizer1->Add( m_labOutputs, 0, wxALL|wxALIGN_RIGHT|wxALIGN_CENTER_VERTICAL, 5 );
	
	m_Outputs = new wxTextCtrl( m_DayPanel, wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize, 0 );
	m_Outputs->SetMinSize( wxSize( 160,-1 ) );
	
	fgSizer1->Add( m_Outputs, 0, wxALL|wxEXPAND|wxALIGN_CENTER_VERTICAL, 5 );
	
	m_labMaxBri = new wxStaticText( m_DayPanel, wxID_ANY, wxT("Max brightness"), wxDefaultPosition, wxDefaultSize, 0 );
	m_labMaxBri->Wrap( -1 );
	fgSizer1->Add( m_labMaxBri, 0, wxALL|wxALIGN_RIGHT|wxALIGN_CENTER_VERTICAL, 5 );
	
	m_MaxBri = new wxSpinCtrl( m_DayPanel, wxID_ANY, wxT("0"), wxDefaultPosition, wxSize( 80,-1 ), wxSP_ARROW_KEYS, 0, 255, 0 );
	fgSizer1->Add( m_MaxBri, 0, wxALL|wxALIGN_CENTER_VERTICAL, 5 );
	
	m_labMinBri = new wxStaticText( m_DayPanel, wxID_ANY, wxT("Min brightness"), wxDefaultPosition, wxDefaultSize, 0 );
	m_labMinBri->Wrap( -1 );
	fgSizer1->Add( m_labMinBri, 0, wxALL|wxALIGN_RIGHT|wxALIGN_CENTER_VERTICAL, 5 );
	
	m_MinBri = new wxSpinCtrl( m_DayPanel, wxID_ANY, wxEmptyString, wxDefaultPosition, wxSize( 80,-1 ), wxSP_ARROW_KEYS, 0, 255, 0 );
	fgSizer1->Add( m_MinBri, 0, wxALL|wxALIGN_CENTER_VERTICAL, 5 );
	
	m_labColorSliding = new wxStaticText( m_DayPanel, wxID_ANY, wxT("Color sliding"), wxDefaultPosition, wxDefaultSize, 0 );
	m_labColorSliding->Wrap( -1 );
	fgSizer1->Add( m_labColorSliding, 0, wxALL|wxALIGN_CENTER_VERTICAL|wxALIGN_RIGHT, 5 );
	
	m_ColorSliding = new wxSpinCtrl( m_DayPanel, wxID_ANY, wxEmptyString, wxDefaultPosition, wxSize( 80,-1 ), wxSP_ARROW_KEYS, 0, 120, 0 );
	fgSizer1->Add( m_ColorSliding, 0, wxALL|wxALIGN_CENTER_VERTICAL, 5 );
	
	bSizer2->Add( fgSizer1, 0, wxEXPAND, 5 );
	
	m_SlidingDaylight = new wxCheckBox( m_DayPanel, wxID_ANY, wxT("Sliding daylight"), wxDefaultPosition, wxDefaultSize, 0 );
	bSizer2->Add( m_SlidingDaylight, 0, wxALL, 5 );
	
	m_SunriseBox = new wxStaticBoxSizer( new wxStaticBox( m_DayPanel, wxID_ANY, wxT("Sunrise") ), wxVERTICAL );
	
	wxFlexGridSizer* fgSizer2;
	fgSizer2 = new wxFlexGridSizer( 0, 4, 0, 0 );
	fgSizer2->SetFlexibleDirection( wxBOTH );
	fgSizer2->SetNonFlexibleGrowMode( wxFLEX_GROWMODE_SPECIFIED );
	
	m_labSunriseTime = new wxStaticText( m_DayPanel, wxID_ANY, wxT("Time"), wxDefaultPosition, wxDefaultSize, 0 );
	m_labSunriseTime->Wrap( -1 );
	fgSizer2->Add( m_labSunriseTime, 0, wxALL|wxALIGN_RIGHT|wxALIGN_CENTER_VERTICAL, 5 );
	
	m_SunriseHour = new wxSpinCtrl( m_DayPanel, wxID_ANY, wxT("0"), wxDefaultPosition, wxSize( 70,-1 ), wxSP_ARROW_KEYS, 0, 23, 0 );
	fgSizer2->Add( m_SunriseHour, 0, wxALIGN_CENTER_VERTICAL|wxALIGN_CENTER_HORIZONTAL|wxTOP|wxBOTTOM|wxLEFT, 5 );
	
	m_staticText5 = new wxStaticText( m_DayPanel, wxID_ANY, wxT(":"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText5->Wrap( -1 );
	fgSizer2->Add( m_staticText5, 0, wxALL|wxALIGN_CENTER_VERTICAL|wxALIGN_CENTER_HORIZONTAL, 5 );
	
	m_SunriseMin = new wxSpinCtrl( m_DayPanel, wxID_ANY, wxT("0"), wxDefaultPosition, wxSize( 70,-1 ), wxSP_ARROW_KEYS, 0, 59, 0 );
	fgSizer2->Add( m_SunriseMin, 0, wxALIGN_CENTER_VERTICAL|wxALIGN_CENTER_HORIZONTAL|wxTOP|wxBOTTOM|wxRIGHT, 5 );
	
	m_SunriseBox->Add( fgSizer2, 0, 0, 5 );
	
	wxFlexGridSizer* fgSizer8;
	fgSizer8 = new wxFlexGridSizer( 0, 4, 0, 0 );
	fgSizer8->SetFlexibleDirection( wxBOTH );
	fgSizer8->SetNonFlexibleGrowMode( wxFLEX_GROWMODE_SPECIFIED );
	
	m_labRGBSunrise = new wxStaticText( m_DayPanel, wxID_ANY, wxT("RGB"), wxDefaultPosition, wxDefaultSize, 0 );
	m_labRGBSunrise->Wrap( -1 );
	fgSizer8->Add( m_labRGBSunrise, 0, wxALL|wxALIGN_CENTER_VERTICAL|wxALIGN_RIGHT, 5 );
	
	m_SunriseRed = new wxSpinCtrl( m_DayPanel, wxID_ANY, wxT("0"), wxDefaultPosition, wxSize( 80,-1 ), wxSP_ARROW_KEYS, 0, 255, 0 );
	fgSizer8->Add( m_SunriseRed, 0, wxALL, 5 );
	
	m_SunriseGreen = new wxSpinCtrl( m_DayPanel, wxID_ANY, wxT("0"), wxDefaultPosition, wxSize( 80,-1 ), wxSP_ARROW_KEYS, 0, 255, 0 );
	fgSizer8->Add( m_SunriseGreen, 0, wxALL, 5 );
	
	m_SunriseBlue = new wxSpinCtrl( m_DayPanel, wxID_ANY, wxT("0"), wxDefaultPosition, wxSize( 80,-1 ), wxSP_ARROW_KEYS, 0, 255, 0 );
	fgSizer8->Add( m_SunriseBlue, 0, wxALL, 5 );
	
	m_SunriseBox->Add( fgSizer8, 0, 0, 5 );
	
	bSizer2->Add( m_SunriseBox, 1, wxEXPAND|wxALL, 5 );
	
	m_NoonBox = new wxStaticBoxSizer( new wxStaticBox( m_DayPanel, wxID_ANY, wxT("Noon") ), wxVERTICAL );
	
	wxFlexGridSizer* fgSizer811;
	fgSizer811 = new wxFlexGridSizer( 0, 4, 0, 0 );
	fgSizer811->SetFlexibleDirection( wxBOTH );
	fgSizer811->SetNonFlexibleGrowMode( wxFLEX_GROWMODE_SPECIFIED );
	
	m_labRGBNoon = new wxStaticText( m_DayPanel, wxID_ANY, wxT("RGB"), wxDefaultPosition, wxDefaultSize, 0 );
	m_labRGBNoon->Wrap( -1 );
	fgSizer811->Add( m_labRGBNoon, 0, wxALL|wxALIGN_CENTER_VERTICAL|wxALIGN_RIGHT, 5 );
	
	m_NoonRed = new wxSpinCtrl( m_DayPanel, wxID_ANY, wxT("0"), wxDefaultPosition, wxSize( 80,-1 ), wxSP_ARROW_KEYS, 0, 255, 0 );
	fgSizer811->Add( m_NoonRed, 0, wxALL, 5 );
	
	m_NoonGreen = new wxSpinCtrl( m_DayPanel, wxID_ANY, wxT("0"), wxDefaultPosition, wxSize( 80,-1 ), wxSP_ARROW_KEYS, 0, 255, 0 );
	fgSizer811->Add( m_NoonGreen, 0, wxALL, 5 );
	
	m_NoonBlue = new wxSpinCtrl( m_DayPanel, wxID_ANY, wxT("0"), wxDefaultPosition, wxSize( 80,-1 ), wxSP_ARROW_KEYS, 0, 255, 0 );
	fgSizer811->Add( m_NoonBlue, 0, wxALL, 5 );
	
	m_NoonBox->Add( fgSizer811, 1, wxEXPAND, 5 );
	
	bSizer2->Add( m_NoonBox, 0, wxEXPAND|wxALL, 5 );
	
	m_SunsetBox = new wxStaticBoxSizer( new wxStaticBox( m_DayPanel, wxID_ANY, wxT("Sunset") ), wxVERTICAL );
	
	wxFlexGridSizer* fgSizer21;
	fgSizer21 = new wxFlexGridSizer( 0, 4, 0, 0 );
	fgSizer21->SetFlexibleDirection( wxBOTH );
	fgSizer21->SetNonFlexibleGrowMode( wxFLEX_GROWMODE_SPECIFIED );
	
	m_labSunsetTime = new wxStaticText( m_DayPanel, wxID_ANY, wxT("Time"), wxDefaultPosition, wxDefaultSize, 0 );
	m_labSunsetTime->Wrap( -1 );
	fgSizer21->Add( m_labSunsetTime, 0, wxALL|wxALIGN_RIGHT|wxALIGN_CENTER_VERTICAL, 5 );
	
	m_SunsetHour = new wxSpinCtrl( m_DayPanel, wxID_ANY, wxT("0"), wxDefaultPosition, wxSize( 70,-1 ), wxSP_ARROW_KEYS, 0, 23, 0 );
	fgSizer21->Add( m_SunsetHour, 0, wxALIGN_CENTER_VERTICAL|wxALIGN_CENTER_HORIZONTAL|wxTOP|wxBOTTOM|wxLEFT, 5 );
	
	m_staticText51 = new wxStaticText( m_DayPanel, wxID_ANY, wxT(":"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText51->Wrap( -1 );
	fgSizer21->Add( m_staticText51, 0, wxALL|wxALIGN_CENTER_VERTICAL|wxALIGN_CENTER_HORIZONTAL, 5 );
	
	m_SunsetMin = new wxSpinCtrl( m_DayPanel, wxID_ANY, wxT("0"), wxDefaultPosition, wxSize( 70,-1 ), wxSP_ARROW_KEYS, 0, 59, 0 );
	fgSizer21->Add( m_SunsetMin, 0, wxALIGN_CENTER_VERTICAL|wxALIGN_CENTER_HORIZONTAL|wxTOP|wxBOTTOM|wxRIGHT, 5 );
	
	m_SunsetBox->Add( fgSizer21, 0, 0, 5 );
	
	wxFlexGridSizer* fgSizer81;
	fgSizer81 = new wxFlexGridSizer( 0, 4, 0, 0 );
	fgSizer81->SetFlexibleDirection( wxBOTH );
	fgSizer81->SetNonFlexibleGrowMode( wxFLEX_GROWMODE_SPECIFIED );
	
	m_labRGBSunset = new wxStaticText( m_DayPanel, wxID_ANY, wxT("RGB"), wxDefaultPosition, wxDefaultSize, 0 );
	m_labRGBSunset->Wrap( -1 );
	fgSizer81->Add( m_labRGBSunset, 0, wxALL|wxALIGN_CENTER_VERTICAL|wxALIGN_RIGHT, 5 );
	
	m_SunsetRed = new wxSpinCtrl( m_DayPanel, wxID_ANY, wxT("0"), wxDefaultPosition, wxSize( 80,-1 ), wxSP_ARROW_KEYS, 0, 255, 0 );
	fgSizer81->Add( m_SunsetRed, 0, wxALL, 5 );
	
	m_SunsetGreen = new wxSpinCtrl( m_DayPanel, wxID_ANY, wxT("0"), wxDefaultPosition, wxSize( 80,-1 ), wxSP_ARROW_KEYS, 0, 255, 0 );
	fgSizer81->Add( m_SunsetGreen, 0, wxALL, 5 );
	
	m_SunsetBlue = new wxSpinCtrl( m_DayPanel, wxID_ANY, wxT("0"), wxDefaultPosition, wxSize( 80,-1 ), wxSP_ARROW_KEYS, 0, 255, 0 );
	fgSizer81->Add( m_SunsetBlue, 0, wxALL, 5 );
	
	m_SunsetBox->Add( fgSizer81, 1, wxEXPAND, 5 );
	
	bSizer2->Add( m_SunsetBox, 0, wxEXPAND|wxALL, 5 );
	
	m_DayPanel->SetSizer( bSizer2 );
	m_DayPanel->Layout();
	bSizer2->Fit( m_DayPanel );
	m_WeatherBook->AddPage( m_DayPanel, wxT("Day"), false );
	m_NightPanel = new wxPanel( m_WeatherBook, wxID_ANY, wxDefaultPosition, wxDefaultSize, wxTAB_TRAVERSAL );
	wxFlexGridSizer* fgSizer5;
	fgSizer5 = new wxFlexGridSizer( 0, 2, 0, 0 );
	fgSizer5->AddGrowableCol( 1 );
	fgSizer5->SetFlexibleDirection( wxBOTH );
	fgSizer5->SetNonFlexibleGrowMode( wxFLEX_GROWMODE_SPECIFIED );
	
	m_labOutputsNight = new wxStaticText( m_NightPanel, wxID_ANY, wxT("Outputs"), wxDefaultPosition, wxDefaultSize, 0 );
	m_labOutputsNight->Wrap( -1 );
	fgSizer5->Add( m_labOutputsNight, 0, wxALL|wxALIGN_RIGHT|wxALIGN_CENTER_VERTICAL, 5 );
	
	m_OutputsNight = new wxTextCtrl( m_NightPanel, wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize, 0 );
	m_OutputsNight->SetMinSize( wxSize( 160,-1 ) );
	
	fgSizer5->Add( m_OutputsNight, 0, wxALL|wxALIGN_CENTER_VERTICAL|wxEXPAND, 5 );
	
	m_labBrightnessNight = new wxStaticText( m_NightPanel, wxID_ANY, wxT("Brightness"), wxDefaultPosition, wxDefaultSize, 0 );
	m_labBrightnessNight->Wrap( -1 );
	fgSizer5->Add( m_labBrightnessNight, 0, wxALL|wxALIGN_RIGHT|wxALIGN_CENTER_VERTICAL, 5 );
	
	m_BrightnessNight = new wxSpinCtrl( m_NightPanel, wxID_ANY, wxEmptyString, wxDefaultPosition, wxSize( 80,-1 ), wxSP_ARROW_KEYS, 0, 255, 0 );
	fgSizer5->Add( m_BrightnessNight, 0, wxALL|wxALIGN_CENTER_VERTICAL, 5 );
	
	m_labRGBNight = new wxStaticText( m_NightPanel, wxID_ANY, wxT("RGB"), wxDefaultPosition, wxDefaultSize, 0 );
	m_labRGBNight->Wrap( -1 );
	fgSizer5->Add( m_labRGBNight, 0, wxALL|wxALIGN_RIGHT|wxALIGN_CENTER_VERTICAL, 5 );
	
	wxFlexGridSizer* fgSizer6;
	fgSizer6 = new wxFlexGridSizer( 0, 3, 0, 0 );
	fgSizer6->SetFlexibleDirection( wxBOTH );
	fgSizer6->SetNonFlexibleGrowMode( wxFLEX_GROWMODE_SPECIFIED );
	
	m_RedNight = new wxSpinCtrl( m_NightPanel, wxID_ANY, wxEmptyString, wxDefaultPosition, wxSize( 80,-1 ), wxSP_ARROW_KEYS, 0, 255, 0 );
	fgSizer6->Add( m_RedNight, 0, wxALL, 5 );
	
	m_GreenNight = new wxSpinCtrl( m_NightPanel, wxID_ANY, wxEmptyString, wxDefaultPosition, wxSize( 80,-1 ), wxSP_ARROW_KEYS, 0, 255, 0 );
	fgSizer6->Add( m_GreenNight, 0, wxALL, 5 );
	
	m_BlueNight = new wxSpinCtrl( m_NightPanel, wxID_ANY, wxEmptyString, wxDefaultPosition, wxSize( 80,-1 ), wxSP_ARROW_KEYS, 0, 255, 0 );
	fgSizer6->Add( m_BlueNight, 0, wxALL, 5 );
	
	fgSizer5->Add( fgSizer6, 0, wxALIGN_CENTER_VERTICAL, 5 );
	
	m_NightPanel->SetSizer( fgSizer5 );
	m_NightPanel->Layout();
	fgSizer5->Fit( m_NightPanel );
	m_WeatherBook->AddPage( m_NightPanel, wxT("Night"), false );
	m_ThemePanel = new wxPanel( m_WeatherBook, wxID_ANY, wxDefaultPosition, wxDefaultSize, wxTAB_TRAVERSAL );
	wxBoxSizer* bSizer3;
	bSizer3 = new wxBoxSizer( wxVERTICAL );
	
	m_ThemeList = new wxListBox( m_ThemePanel, wxID_ANY, wxDefaultPosition, wxDefaultSize, 0, NULL, 0 ); 
	bSizer3->Add( m_ThemeList, 1, wxALL|wxEXPAND, 5 );
	
	wxBoxSizer* bSizer4;
	bSizer4 = new wxBoxSizer( wxHORIZONTAL );
	
	m_ThemeAdd = new wxButton( m_ThemePanel, wxID_ANY, wxT("Add"), wxDefaultPosition, wxDefaultSize, 0 );
	bSizer4->Add( m_ThemeAdd, 0, wxALL, 5 );
	
	m_ThemeModify = new wxButton( m_ThemePanel, wxID_ANY, wxT("Modify"), wxDefaultPosition, wxDefaultSize, 0 );
	bSizer4->Add( m_ThemeModify, 0, wxALL, 5 );
	
	m_ThemeDelete = new wxButton( m_ThemePanel, wxID_ANY, wxT("Delete"), wxDefaultPosition, wxDefaultSize, 0 );
	bSizer4->Add( m_ThemeDelete, 0, wxALL, 5 );
	
	bSizer3->Add( bSizer4, 0, wxEXPAND|wxBOTTOM, 5 );
	
	wxFlexGridSizer* fgSizer9;
	fgSizer9 = new wxFlexGridSizer( 0, 2, 0, 0 );
	fgSizer9->AddGrowableCol( 1 );
	fgSizer9->SetFlexibleDirection( wxBOTH );
	fgSizer9->SetNonFlexibleGrowMode( wxFLEX_GROWMODE_SPECIFIED );
	
	m_labThemeID = new wxStaticText( m_ThemePanel, wxID_ANY, wxT("ID"), wxDefaultPosition, wxDefaultSize, 0 );
	m_labThemeID->Wrap( -1 );
	fgSizer9->Add( m_labThemeID, 0, wxALL|wxALIGN_RIGHT|wxALIGN_CENTER_VERTICAL, 5 );
	
	m_ThemeID = new wxTextCtrl( m_ThemePanel, wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize, 0 );
	fgSizer9->Add( m_ThemeID, 0, wxALL|wxALIGN_CENTER_VERTICAL|wxEXPAND, 5 );
	
	m_labThemeOutputs = new wxStaticText( m_ThemePanel, wxID_ANY, wxT("Outputs"), wxDefaultPosition, wxDefaultSize, 0 );
	m_labThemeOutputs->Wrap( -1 );
	fgSizer9->Add( m_labThemeOutputs, 0, wxALL|wxALIGN_RIGHT|wxALIGN_CENTER_VERTICAL, 5 );
	
	m_ThemeOutputs = new wxTextCtrl( m_ThemePanel, wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize, 0 );
	fgSizer9->Add( m_ThemeOutputs, 0, wxALL|wxEXPAND|wxALIGN_CENTER_VERTICAL, 5 );
	
	m_labThemeSound = new wxStaticText( m_ThemePanel, wxID_ANY, wxT("Sound"), wxDefaultPosition, wxDefaultSize, 0 );
	m_labThemeSound->Wrap( -1 );
	fgSizer9->Add( m_labThemeSound, 0, wxALL|wxALIGN_RIGHT|wxALIGN_CENTER_VERTICAL, 5 );
	
	m_ThemeSound = new wxTextCtrl( m_ThemePanel, wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize, 0 );
	fgSizer9->Add( m_ThemeSound, 0, wxALL|wxEXPAND|wxALIGN_CENTER_VERTICAL, 5 );
	
	m_labThemeDim = new wxStaticText( m_ThemePanel, wxID_ANY, wxT("Dim"), wxDefaultPosition, wxDefaultSize, 0 );
	m_labThemeDim->Wrap( -1 );
	fgSizer9->Add( m_labThemeDim, 0, wxALL|wxALIGN_RIGHT|wxALIGN_CENTER_VERTICAL, 5 );
	
	wxFlexGridSizer* fgSizer10;
	fgSizer10 = new wxFlexGridSizer( 0, 2, 0, 0 );
	fgSizer10->SetFlexibleDirection( wxBOTH );
	fgSizer10->SetNonFlexibleGrowMode( wxFLEX_GROWMODE_SPECIFIED );
	
	m_ThemeDim = new wxSpinCtrl( m_ThemePanel, wxID_ANY, wxEmptyString, wxDefaultPosition, wxSize( 80,-1 ), wxSP_ARROW_KEYS, 0, 100, 0 );
	fgSizer10->Add( m_ThemeDim, 0, wxALIGN_CENTER_VERTICAL|wxTOP|wxBOTTOM|wxLEFT, 5 );
	
	m_labThemeDimPercent = new wxStaticText( m_ThemePanel, wxID_ANY, wxT("%"), wxDefaultPosition, wxDefaultSize, 0 );
	m_labThemeDimPercent->Wrap( -1 );
	fgSizer10->Add( m_labThemeDimPercent, 0, wxALIGN_CENTER_VERTICAL|wxTOP|wxBOTTOM|wxRIGHT, 5 );
	
	fgSizer9->Add( fgSizer10, 0, 0, 5 );
	
	m_labThemeTime = new wxStaticText( m_ThemePanel, wxID_ANY, wxT("Time"), wxDefaultPosition, wxDefaultSize, 0 );
	m_labThemeTime->Wrap( -1 );
	fgSizer9->Add( m_labThemeTime, 0, wxALL|wxALIGN_RIGHT|wxALIGN_CENTER_VERTICAL, 5 );
	
	wxFlexGridSizer* fgSizer11;
	fgSizer11 = new wxFlexGridSizer( 0, 3, 0, 0 );
	fgSizer11->SetFlexibleDirection( wxBOTH );
	fgSizer11->SetNonFlexibleGrowMode( wxFLEX_GROWMODE_SPECIFIED );
	
	m_ThemeHour = new wxSpinCtrl( m_ThemePanel, wxID_ANY, wxEmptyString, wxDefaultPosition, wxSize( 75,-1 ), wxSP_ARROW_KEYS, 0, 23, 0 );
	fgSizer11->Add( m_ThemeHour, 0, wxTOP|wxBOTTOM|wxLEFT, 5 );
	
	m_labThemeTimeSep = new wxStaticText( m_ThemePanel, wxID_ANY, wxT(":"), wxDefaultPosition, wxDefaultSize, 0 );
	m_labThemeTimeSep->Wrap( -1 );
	fgSizer11->Add( m_labThemeTimeSep, 0, wxALIGN_CENTER_VERTICAL|wxALIGN_CENTER_HORIZONTAL|wxTOP|wxBOTTOM, 5 );
	
	m_ThemeMinute = new wxSpinCtrl( m_ThemePanel, wxID_ANY, wxEmptyString, wxDefaultPosition, wxSize( 75,-1 ), wxSP_ARROW_KEYS, 0, 59, 0 );
	fgSizer11->Add( m_ThemeMinute, 0, wxTOP|wxBOTTOM|wxRIGHT, 5 );
	
	fgSizer9->Add( fgSizer11, 0, wxEXPAND|wxALIGN_CENTER_VERTICAL, 5 );
	
	m_labThemeDuration = new wxStaticText( m_ThemePanel, wxID_ANY, wxT("Duration"), wxDefaultPosition, wxDefaultSize, 0 );
	m_labThemeDuration->Wrap( -1 );
	fgSizer9->Add( m_labThemeDuration, 0, wxALL|wxALIGN_CENTER_VERTICAL|wxALIGN_RIGHT, 5 );
	
	m_ThemeDuration = new wxSpinCtrl( m_ThemePanel, wxID_ANY, wxEmptyString, wxDefaultPosition, wxSize( 100,-1 ), wxSP_ARROW_KEYS, 0, 1440, 0 );
	fgSizer9->Add( m_ThemeDuration, 0, wxALL|wxALIGN_CENTER_VERTICAL, 5 );
	
	m_labThemeRandom = new wxStaticText( m_ThemePanel, wxID_ANY, wxT("Random"), wxDefaultPosition, wxDefaultSize, 0 );
	m_labThemeRandom->Wrap( -1 );
	fgSizer9->Add( m_labThemeRandom, 0, wxALL|wxALIGN_RIGHT|wxALIGN_CENTER_VERTICAL, 5 );
	
	m_ThemeRandom = new wxCheckBox( m_ThemePanel, wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize, 0 );
	fgSizer9->Add( m_ThemeRandom, 0, wxALL|wxALIGN_CENTER_VERTICAL, 5 );
	
	bSizer3->Add( fgSizer9, 0, wxEXPAND, 5 );
	
	m_ThemePanel->SetSizer( bSizer3 );
	m_ThemePanel->Layout();
	bSizer3->Fit( m_ThemePanel );
	m_WeatherBook->AddPage( m_ThemePanel, wxT("Theme"), false );
	
	bSizer1->Add( m_WeatherBook, 1, wxEXPAND | wxALL, 5 );
	
	m_StdButtons = new wxStdDialogButtonSizer();
	m_StdButtonsOK = new wxButton( this, wxID_OK );
	m_StdButtons->AddButton( m_StdButtonsOK );
	m_StdButtonsApply = new wxButton( this, wxID_APPLY );
	m_StdButtons->AddButton( m_StdButtonsApply );
	m_StdButtonsCancel = new wxButton( this, wxID_CANCEL );
	m_StdButtons->AddButton( m_StdButtonsCancel );
	m_StdButtonsHelp = new wxButton( this, wxID_HELP );
	m_StdButtons->AddButton( m_StdButtonsHelp );
	m_StdButtons->Realize();
	bSizer1->Add( m_StdButtons, 0, wxALL|wxEXPAND|wxALIGN_RIGHT, 5 );
	
	this->SetSizer( bSizer1 );
	this->Layout();
	bSizer1->Fit( this );
	
	this->Centre( wxBOTH );
	
	// Connect Events
	m_IndexList->Connect( wxEVT_COMMAND_LISTBOX_SELECTED, wxCommandEventHandler( WeatherDlgGen::onIndexList ), NULL, this );
	m_AddWeather->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( WeatherDlgGen::onAddWeather ), NULL, this );
	m_DeleteWeather->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( WeatherDlgGen::onDeleteWeather ), NULL, this );
	m_ActivateWeather->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( WeatherDlgGen::onActivateWeather ), NULL, this );
	m_ThemeList->Connect( wxEVT_COMMAND_LISTBOX_SELECTED, wxCommandEventHandler( WeatherDlgGen::onThemeSelected ), NULL, this );
	m_ThemeAdd->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( WeatherDlgGen::onThemeAdd ), NULL, this );
	m_ThemeModify->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( WeatherDlgGen::onThemeModify ), NULL, this );
	m_ThemeDelete->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( WeatherDlgGen::onThemeDelete ), NULL, this );
	m_StdButtonsApply->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( WeatherDlgGen::onApply ), NULL, this );
	m_StdButtonsCancel->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( WeatherDlgGen::onCancel ), NULL, this );
	m_StdButtonsHelp->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( WeatherDlgGen::onHelp ), NULL, this );
	m_StdButtonsOK->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( WeatherDlgGen::onOK ), NULL, this );
}

WeatherDlgGen::~WeatherDlgGen()
{
	// Disconnect Events
	m_IndexList->Disconnect( wxEVT_COMMAND_LISTBOX_SELECTED, wxCommandEventHandler( WeatherDlgGen::onIndexList ), NULL, this );
	m_AddWeather->Disconnect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( WeatherDlgGen::onAddWeather ), NULL, this );
	m_DeleteWeather->Disconnect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( WeatherDlgGen::onDeleteWeather ), NULL, this );
	m_ActivateWeather->Disconnect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( WeatherDlgGen::onActivateWeather ), NULL, this );
	m_ThemeList->Disconnect( wxEVT_COMMAND_LISTBOX_SELECTED, wxCommandEventHandler( WeatherDlgGen::onThemeSelected ), NULL, this );
	m_ThemeAdd->Disconnect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( WeatherDlgGen::onThemeAdd ), NULL, this );
	m_ThemeModify->Disconnect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( WeatherDlgGen::onThemeModify ), NULL, this );
	m_ThemeDelete->Disconnect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( WeatherDlgGen::onThemeDelete ), NULL, this );
	m_StdButtonsApply->Disconnect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( WeatherDlgGen::onApply ), NULL, this );
	m_StdButtonsCancel->Disconnect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( WeatherDlgGen::onCancel ), NULL, this );
	m_StdButtonsHelp->Disconnect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( WeatherDlgGen::onHelp ), NULL, this );
	m_StdButtonsOK->Disconnect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( WeatherDlgGen::onOK ), NULL, this );
	
}
