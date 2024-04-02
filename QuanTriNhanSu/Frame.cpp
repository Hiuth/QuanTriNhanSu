﻿#include <wx/wx.h>
#include "Frame.h"
#include <iostream>
#include <stack>
using namespace std;

stack<wxFrame*> frameStack;

//font
wxFont ConsolasB(wxFontInfo(40).FaceName("Eras Bold ITC"));
wxFont Calibri(wxFontInfo(15).FaceName("Calibri"));
wxFont CalibriB(wxFontInfo(15).FaceName("Calibri").Bold());
wxFont SCalibri(wxFontInfo(12).FaceName("Calibri"));
wxFont CalibriBI(wxFontInfo(40).FaceName("Calibri").Bold().Italic());

//window size
int windowHeight = 540;
int windowWidth = 960;

BaseFrame::BaseFrame(const wxString& title) : wxFrame(NULL, wxID_ANY, title, wxPoint(280,140), wxSize(windowWidth, windowHeight)) {}

void BaseFrame::OnBackClicked(wxCommandEvent& evt) {
	if (!frameStack.empty()) {
		this->Destroy();
		frameStack.top()->Show();
		frameStack.pop();
	}
}

void BaseFrame::OnClose(wxCloseEvent& evt) {
	//tắt tất cả các cửa số còn hoạt động - tắt lâu nhưng ko có chạy ngầm :D
	while (!wxTopLevelWindows.empty()) {
		wxTopLevelWindows[0]->Close();
	}
}

void BaseFrame::CreateMenu(wxWindow* parent, wxString userName) {
	wxPanel* menu = new wxPanel(parent, wxID_ANY, wxPoint(0, 0), wxSize(960, 25));
	menu->SetBackgroundColour(wxColour(255, 255, 255));

	wxButton* back = new wxButton(menu, wxID_ANY, "Back", wxPoint(5, 5), wxSize(40, 15), wxNO_BORDER);
	back->SetBackgroundColour(wxColour(255, 255, 255));
	back->SetFont(SCalibri);
	back->Bind(wxEVT_BUTTON, &BaseFrame::OnBackClicked, this);
	wxString welcome = "Welcome, ";
	welcome = welcome.append(userName);
	welcome = welcome.append("!");
	int wlocate = 850 - userName.length() * 8;
	wxStaticText* welcomeText = new wxStaticText(menu, wxID_ANY, welcome, wxPoint(wlocate, 3), wxSize(-1, 12));
	welcomeText->SetFont(SCalibri);
}

void BaseFrame::OnSearch(wxCommandEvent& evt) {
	wxTextCtrl* textCtrl = dynamic_cast<wxTextCtrl*>(evt.GetEventObject());
	if (textCtrl && textCtrl->GetValue() == "Search") {
		textCtrl->SetValue("");
	}
}

void BaseFrame::UnSearch(wxFocusEvent& evt) {
	wxTextCtrl* textCtrl = dynamic_cast<wxTextCtrl*>(evt.GetEventObject());
	if (textCtrl && textCtrl->GetValue() == "") {
		textCtrl->SetValue("Search");
		textCtrl->SetForegroundColour(wxColour(178, 178, 178));
	}
	evt.Skip();
}

LoginFrame::LoginFrame() : BaseFrame("HUMAN RESOURCES MANAGERMENT") {
	wxPanel* panel = new wxPanel(this);
	
	//frame1
	wxStaticText* text1 = new wxStaticText(panel, wxID_ANY, "LOGIN", wxPoint(370, 120));
	text1->SetFont(ConsolasB);

	//account
	wxStaticText* text2 = new wxStaticText(panel, wxID_ANY, "Account", wxPoint(250, 200));
	text2->SetFont(Calibri);
	wxTextCtrl* space2 = new wxTextCtrl(panel, wxID_ANY, "", wxPoint(370, 190), wxSize(300, 35));
	wxFont font = space2->GetFont();
	font.SetPointSize(15);
	space2->SetFont(font);
	accCtrl = space2;

	//password
	wxStaticText* text3 = new wxStaticText(panel, wxID_ANY, "Password", wxPoint(250, 250));
	text3->SetFont(Calibri);
	wxTextCtrl* space3 = new wxTextCtrl(panel, wxID_ANY, "", wxPoint(370, 240), wxSize(300, 35), wxTE_PASSWORD);
	font = space3->GetFont();
	font.SetPointSize(15);
	space3->SetFont(font);
	passCtrl = space3;

	//next button
	wxButton* button1 = new wxButton(panel, wxID_ANY, "Next", wxPoint(650, 300), wxSize(80, 40));
	button1->SetFont(Calibri);

	//event
	button1->Bind(wxEVT_BUTTON, &LoginFrame::OnButtonClicked, this);
	Bind(wxEVT_CLOSE_WINDOW, &BaseFrame::OnClose, this);
}

void LoginFrame::OnButtonClicked(wxCommandEvent& evt) {
	wxString acc = accCtrl->GetValue();
	wxString pass = passCtrl->GetValue();
	if (acc == "" && pass == "") {
		frameStack.push(this);
		this->Hide();
		(new HomeFrame(accCtrl->GetValue()))->Show();
	}
	else {
		wxLogMessage("Sai tai khoan hoac mat khau");
	}
}


HomeFrame::HomeFrame(wxString accName) : BaseFrame("HOME") {
	wxPanel* panel = new wxPanel(this);
	userName = accName;
	CreateMenu(panel, userName);

	//frame2
	wxButton* button1 = new wxButton(panel, wxID_ANY, "QUAN LI\nTAI KHOAN", wxPoint(15, 40), wxSize(450, 210));
	button1->SetFont(CalibriBI);
	button1->SetBackgroundColour(wxColour(89, 102, 200));
	button1->SetForegroundColour(wxColour(255, 255, 255));
	wxButton* button2 = new wxButton(panel, wxID_ANY, "QUAN LI\nNHAN SU", wxPoint(480, 40), wxSize(450, 210));
	button2->SetFont(CalibriBI);
	button2->SetBackgroundColour(wxColour(61, 201, 113));
	button2->SetForegroundColour(wxColour(255, 255, 255));
	wxButton* button3 = new wxButton(panel, wxID_ANY, "QUAN LI\nTIEN LUONG", wxPoint(15, 265), wxSize(450, 210));
	button3->SetFont(CalibriBI);
	button3->SetBackgroundColour(wxColour(192, 162, 70));
	button3->SetForegroundColour(wxColour(255, 255, 255));
	wxButton* button4 = new wxButton(panel, wxID_ANY, "KHAC", wxPoint(480, 265), wxSize(450, 210));
	button4->SetFont(CalibriBI);
	button4->SetBackgroundColour(wxColour(193, 68, 112));
	button4->SetForegroundColour(wxColour(255, 255, 255));

	//event
	Bind(wxEVT_CLOSE_WINDOW, &BaseFrame::OnClose, this);
}

void HomeFrame::OnButton1Clicked(wxCommandEvent& evt) {
	frameStack.push(this);
	this->Hide();
	(new QLTKFrame(userName))->Show();
}

QLTKFrame::QLTKFrame(wxString accName) : BaseFrame("QUAN LI TAI KHOAN") {
	wxPanel* panel = new wxPanel(this);
	userName = accName;
	CreateMenu(panel, userName);

	//frame3
	wxStaticText* text1 = new wxStaticText(panel, wxID_ANY, "Tim kiem", wxPoint(20, 40));
	text1->SetFont(CalibriB);
	wxTextCtrl* search = new wxTextCtrl(panel, wxID_ANY, "Search", wxPoint(105, 40), wxSize(200, -1));
	search->SetFont(SCalibri);
	search->Bind(wxEVT_TEXT, &BaseFrame::OnSearch, this);
	search->Bind(wxEVT_SET_FOCUS, &BaseFrame::UnSearch, this);

	wxStaticText* text2 = new wxStaticText(panel, wxID_ANY, "Tags", wxPoint(435, 40));
	text2->SetFont(CalibriB);
	wxArrayString tags;
	tags.Add("Ten tai khoan");
	tags.Add("Quyen han");
	wxChoice* tag = new wxChoice(panel, wxID_ANY, wxPoint(480, 40), wxSize(200, -1), tags);
	tag->Select(0);
	tag->SetFont(SCalibri);

	//event
	Bind(wxEVT_CLOSE_WINDOW, &BaseFrame::OnClose, this);
}