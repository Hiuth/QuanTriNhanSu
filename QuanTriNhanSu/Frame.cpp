#include <wx/wx.h>
#include "Frame.h"
#include <iostream>
#include <stack>
using namespace std;

stack<wxFrame*> frameStack;

//font
wxFont ConsolasB(wxFontInfo(40).FaceName("Eras Bold ITC")); //tiêu đề đẹp, lớn
wxFont Calibri(wxFontInfo(15).FaceName("Calibri")); //Chữ cái bình thường
wxFont CalibriB(wxFontInfo(15).FaceName("Calibri").Bold()); //Chữ bình thường in hoa
wxFont SCalibri(wxFontInfo(12).FaceName("Calibri")); //Chữ bé trên menu, thanh search
wxFont CalibriBI(wxFontInfo(40).FaceName("Calibri").Bold().Italic()); //Chữ to tiêu đề lớn
wxFont SCalibriBI(wxFontInfo(30).FaceName("Calibri").Bold().Italic()); //Chữ to tiêu đề vừa
wxFont SSCalibriBI(wxFontInfo(25).FaceName("Calibri").Bold().Italic()); //Chữ to tiêu đề nhỏ

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

	wxButton* back = new wxButton(menu, wxID_ANY, "Back", wxPoint(10, 5), wxSize(40, 15), wxNO_BORDER);
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

void BaseFrame::UpdateSoon(wxCommandEvent& evt) {
	wxLogMessage("Update Soon!");
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
	if (acc == "admin" && pass == "112233") {
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
	button1->Bind(wxEVT_BUTTON, &HomeFrame::OnButton1Clicked, this);
	button2->Bind(wxEVT_BUTTON, &HomeFrame::OnButton2Clicked, this);
	button3->Bind(wxEVT_BUTTON, &HomeFrame::OnButton3Clicked, this);
	button4->Bind(wxEVT_BUTTON, &HomeFrame::OnButton4Clicked, this);
	Bind(wxEVT_CLOSE_WINDOW, &BaseFrame::OnClose, this);
}

void HomeFrame::OnButton1Clicked(wxCommandEvent& evt) {
	frameStack.push(this);
	this->Hide();
	(new QLTKFrame(userName))->Show();
}

void HomeFrame::OnButton2Clicked(wxCommandEvent& evt) {
	frameStack.push(this);
	this->Hide();
	(new QLNSFrame(userName))->Show();
}

void HomeFrame::OnButton3Clicked(wxCommandEvent& evt) {
	frameStack.push(this);
	this->Hide();
	(new QLTLFrame(userName))->Show();
}

void HomeFrame::OnButton4Clicked(wxCommandEvent& evt) {
	frameStack.push(this);
	this->Hide();
	(new KFrame(userName))->Show();
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

QLNSFrame::QLNSFrame(wxString accName) : BaseFrame("QUAN LI NHAN SU") {
	wxPanel* panel = new wxPanel(this);
	userName = accName;
	CreateMenu(panel, userName);

	//frame
	wxButton* button1 = new wxButton(panel, wxID_ANY, "QUAN LI HO SO NHAN VIEN", wxPoint(22, 40), wxSize(900, 140));
	button1->SetFont(CalibriBI);
	button1->SetBackgroundColour(wxColour(64, 22, 204));
	button1->SetForegroundColour(wxColour(255, 255, 255));
	wxButton* button2 = new wxButton(panel, wxID_ANY, "QUAN LI CHUC VU", wxPoint(22, 190), wxSize(900, 140));
	button2->SetFont(CalibriBI);
	button2->SetBackgroundColour(wxColour(18, 132, 205));
	button2->SetForegroundColour(wxColour(255, 255, 255));
	wxButton* button3 = new wxButton(panel, wxID_ANY, "QUAN LI PHONG BAN", wxPoint(22, 340), wxSize(900, 140));
	button3->SetFont(CalibriBI);
	button3->SetBackgroundColour(wxColour(13, 190, 92));
	button3->SetForegroundColour(wxColour(255, 255, 255));

	//event
	button1->Bind(wxEVT_BUTTON, &QLNSFrame::OnButton1Clicked, this);
	button2->Bind(wxEVT_BUTTON, &QLNSFrame::OnButton2Clicked, this);
	button3->Bind(wxEVT_BUTTON, &QLNSFrame::OnButton3Clicked, this);
	Bind(wxEVT_CLOSE_WINDOW, &BaseFrame::OnClose, this);
}

void QLNSFrame::OnButton1Clicked(wxCommandEvent& evt) {
	frameStack.push(this);
	this->Hide();
	(new QLNSFrame2(userName))->Show();
}

void QLNSFrame::OnButton2Clicked(wxCommandEvent& evt) {
	frameStack.push(this);
	this->Hide();
	(new QLNSFrame11(userName))->Show();
}

void QLNSFrame::OnButton3Clicked(wxCommandEvent& evt) {
	frameStack.push(this);
	this->Hide();
	(new QLNSFrame17(userName))->Show();
}

QLNSFrame2::QLNSFrame2(wxString accName) : BaseFrame("QUAN LI HO SO NHAN VIEN") {
	wxPanel* panel = new wxPanel(this);
	userName = accName;
	CreateMenu(panel, userName);

	//event
	Bind(wxEVT_CLOSE_WINDOW, &BaseFrame::OnClose, this);
}

QLNSFrame11::QLNSFrame11(wxString accName) : BaseFrame("QUAN LI CHUC VU") {
	wxPanel* panel = new wxPanel(this);
	userName = accName;
	CreateMenu(panel, userName);

	//event
	Bind(wxEVT_CLOSE_WINDOW, &BaseFrame::OnClose, this);
}

QLNSFrame17::QLNSFrame17(wxString accName) : BaseFrame("QUAN LI PHONG BAN") {
	wxPanel* panel = new wxPanel(this);
	userName = accName;
	CreateMenu(panel, userName);

	//event
	Bind(wxEVT_CLOSE_WINDOW, &BaseFrame::OnClose, this);
}

QLTLFrame::QLTLFrame(wxString accName) : BaseFrame("QUAN LI TIEN LUONG") {
	wxPanel* panel = new wxPanel(this);
	userName = accName;
	CreateMenu(panel, userName);

	//frame
	wxButton* button1 = new wxButton(panel, wxID_ANY, "XEM TAT CA\nTHONG TIN", wxPoint(22, 45), wxSize(400, 440));
	button1->SetFont(CalibriBI);
	button1->SetBackgroundColour(wxColour(192, 18, 67));
	button1->SetForegroundColour(wxColour(255, 255, 255));
	wxButton* button2 = new wxButton(panel, wxID_ANY, "THONG TIN CHAM CONG,\nLUONG CO BAN", wxPoint(433, 45), wxSize(490, 215));
	button2->SetFont(SCalibriBI);
	button2->SetBackgroundColour(wxColour(14, 116, 194));
	button2->SetForegroundColour(wxColour(255, 255, 255));
	wxButton* button3 = new wxButton(panel, wxID_ANY, "THONG TIN\nLAM THEM", wxPoint(433, 270), wxSize(490, 215));
	button3->SetFont(SCalibriBI);
	button3->SetBackgroundColour(wxColour(14, 166, 29));
	button3->SetForegroundColour(wxColour(255, 255, 255));

	//event
	button1->Bind(wxEVT_BUTTON, &QLTLFrame::OnButton1Clicked, this);
	button2->Bind(wxEVT_BUTTON, &QLTLFrame::OnButton2Clicked, this);
	button3->Bind(wxEVT_BUTTON, &QLTLFrame::OnButton3Clicked, this);
	Bind(wxEVT_CLOSE_WINDOW, &BaseFrame::OnClose, this);
}

void QLTLFrame::OnButton1Clicked(wxCommandEvent& evt) {
	frameStack.push(this);
	this->Hide();
	(new QLTLFrame2(userName))->Show();
}

void QLTLFrame::OnButton2Clicked(wxCommandEvent& evt) {
	frameStack.push(this);
	this->Hide();
	(new QLTLFrame3(userName))->Show();
}

void QLTLFrame::OnButton3Clicked(wxCommandEvent& evt) {
	frameStack.push(this);
	this->Hide();
	(new QLTLFrame5(userName))->Show();
};

QLTLFrame2::QLTLFrame2(wxString accName) : BaseFrame("XEM TIEN LUONG") {
	wxPanel* panel = new wxPanel(this);
	userName = accName;
	CreateMenu(panel, userName);

	//event
	Bind(wxEVT_CLOSE_WINDOW, &BaseFrame::OnClose, this);
}

QLTLFrame3::QLTLFrame3(wxString accName) : BaseFrame("CHAM CONG VA LUONG CO BAN") {
	wxPanel* panel = new wxPanel(this);
	userName = accName;
	CreateMenu(panel, userName);

	//event
	Bind(wxEVT_CLOSE_WINDOW, &BaseFrame::OnClose, this);
}

QLTLFrame5::QLTLFrame5(wxString accName) : BaseFrame("LAM THEM") {
	wxPanel* panel = new wxPanel(this);
	userName = accName;
	CreateMenu(panel, userName);

	//event
	Bind(wxEVT_CLOSE_WINDOW, &BaseFrame::OnClose, this);
}

KFrame::KFrame(wxString accName) : BaseFrame("KHAC") {
	wxPanel* panel = new wxPanel(this);
	userName = accName;
	CreateMenu(panel, userName);

	//frame
	wxButton* button1 = new wxButton(panel, wxID_ANY, "QUAN LI\nCHINH SACH\nDAI NGO", wxPoint(22, 43), wxSize(400, 440));
	button1->SetFont(CalibriBI);
	button1->SetBackgroundColour(wxColour(83, 13, 170));
	button1->SetForegroundColour(wxColour(255, 255, 255));
	wxButton* button2 = new wxButton(panel, wxID_ANY, "SAP CAP NHAT", wxPoint(433, 43), wxSize(490, 215));
	button2->SetFont(SCalibriBI);
	button2->SetBackgroundColour(wxColour(20, 78, 122));
	button2->SetForegroundColour(wxColour(255, 255, 255));
	wxButton* button3 = new wxButton(panel, wxID_ANY, "HUONG DAN\nSU DUNG", wxPoint(433, 268), wxSize(240, 215));
	button3->SetFont(SSCalibriBI);
	button3->SetBackgroundColour(wxColour(22, 124, 80));
	button3->SetForegroundColour(wxColour(255, 255, 255));
	wxButton* button4 = new wxButton(panel, wxID_ANY, "RESET\nDU LIEU", wxPoint(683, 268), wxSize(240, 215));
	button4->SetFont(SSCalibriBI);
	button4->SetBackgroundColour(wxColour(184, 11, 109));
	button4->SetForegroundColour(wxColour(255, 255, 255));

	//event
	button1->Bind(wxEVT_BUTTON, &KFrame::OnButton1Clicked, this);
	button2->Bind(wxEVT_BUTTON, &BaseFrame::UpdateSoon, this);
	button3->Bind(wxEVT_BUTTON, &BaseFrame::UpdateSoon, this);
	button4->Bind(wxEVT_BUTTON, &BaseFrame::UpdateSoon, this);
	Bind(wxEVT_CLOSE_WINDOW, &BaseFrame::OnClose, this);
}

void KFrame::OnButton1Clicked(wxCommandEvent& evt) {
	frameStack.push(this);
	this->Hide();
	(new KFrame2(userName))->Show();
}

KFrame2::KFrame2(wxString accName) : BaseFrame("QUAN LI CHINH SACH DAI NGO") {
	wxPanel* panel = new wxPanel(this);
	userName = accName;
	CreateMenu(panel, userName);

	//frame
	wxButton* button1 = new wxButton(panel, wxID_ANY, "QUAN LI\nBAO HIEM", wxPoint(25, 43), wxSize(445, 440));
	button1->SetFont(CalibriBI);
	button1->SetBackgroundColour(wxColour(20, 70, 152));
	button1->SetForegroundColour(wxColour(255, 255, 255));
	wxButton* button2 = new wxButton(panel, wxID_ANY, "QUAN LI\nKHEN THUONG\nKI LUAT", wxPoint(475, 43), wxSize(445, 440));
	button2->SetFont(CalibriBI);
	button2->SetBackgroundColour(wxColour(22, 124, 80));
	button2->SetForegroundColour(wxColour(255, 255, 255));

	//event
	Bind(wxEVT_CLOSE_WINDOW, &BaseFrame::OnClose, this);
}

KFrame3::KFrame3(wxString accName) : BaseFrame("QUAN LI BAO HIEM") {
	wxPanel* panel = new wxPanel(this);
	userName = accName;
	CreateMenu(panel, userName);

	//event
	Bind(wxEVT_CLOSE_WINDOW, &BaseFrame::OnClose, this);
}

KFrame9::KFrame9(wxString accName) : BaseFrame("QUAN LI KHEN THUONG, KI LUAT") {
	wxPanel* panel = new wxPanel(this);
	userName = accName;
	CreateMenu(panel, userName);

	//event
	Bind(wxEVT_CLOSE_WINDOW, &BaseFrame::OnClose, this);
}