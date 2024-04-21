#include <wx/wx.h>
#include <wx/grid.h>
#include "HeThong.h"
#include "TraVe.h"
#include "Frame.h"
#include "NhanVien.h"
#include <iostream>
#include <string>
#include <stack>
using namespace std;

stack<wxFrame*> frameStack;

//khai bao
HeThong* hethong = new HeThong();
TraVe* trave = new TraVe();
NhanVien* nhanvien = new NhanVien();

//font
wxFont ConsolasB(wxFontInfo(40).FaceName("Eras Bold ITC")); //tiêu đề đẹp, lớn
wxFont Calibri(wxFontInfo(15).FaceName("Calibri")); //Chữ cái bình thường
wxFont CalibriB(wxFontInfo(15).FaceName("Calibri").Bold()); //Chữ bình thường in hoa
wxFont CalibriI(wxFontInfo(15).FaceName("Calibri").Italic()); //Chữ bình thường in hoa

wxFont SCalibri(wxFontInfo(12).FaceName("Calibri")); //Chữ bé trên menu, thanh search
wxFont SCalibriB(wxFontInfo(12).FaceName("Calibri").Bold()); //Chữ bé trên grid

wxFont MCalibriB(wxFontInfo(20).FaceName("Calibri").Bold());
wxFont MCalibri(wxFontInfo(20).FaceName("Calibri"));
wxFont MCalibriI(wxFontInfo(20).FaceName("Calibri").Italic());

wxFont LCalibriB(wxFontInfo(30).FaceName("Calibri").Bold()); //Chữ lớn in hoa
wxFont LCalibri(wxFontInfo(30).FaceName("Calibri")); //Chữ lớn

wxFont CalibriBI(wxFontInfo(40).FaceName("Calibri").Bold().Italic()); //Chữ to tiêu đề lớn
wxFont SCalibriBI(wxFontInfo(30).FaceName("Calibri").Bold().Italic()); //Chữ to tiêu đề vừa
wxFont SSCalibriBI(wxFontInfo(25).FaceName("Calibri").Bold().Italic()); //Chữ to tiêu đề nhỏ

//window size
int windowHeight = 540;
int windowWidth = 960;

BaseFrame::BaseFrame(const wxString& title) : wxFrame(NULL, wxID_ANY, title, wxPoint(280, 140), wxSize(windowWidth, windowHeight)/*, wxDEFAULT_FRAME_STYLE & ~(wxRESIZE_BORDER | wxMAXIMIZE_BOX)*/) {}

void BaseFrame::OnBackClicked(wxCommandEvent& evt) {
	if (!frameStack.empty()) {
		this->Hide();
		frameStack.top()->Show();
		frameStack.pop();
	}
}

void BaseFrame::OnClose(wxCloseEvent& evt) {
	this->Destroy();
	while (!frameStack.empty()) {
		frameStack.top()->Destroy();
		frameStack.pop();
	}

	/*tắt tất cả các cửa số còn hoạt động - tắt lâu nhưng ko có chạy ngầm :D*/
	while (!wxTopLevelWindows.empty()) {
		wxTopLevelWindows[0]->Close();
	}
}

void BaseFrame::CreateMenu(wxWindow* parent, wxString userName) {
	wxPanel* menu = new wxPanel(parent, wxID_ANY, wxPoint(0, 0), wxSize(960, 25));
	menu->SetBackgroundColour(wxColour(255, 255, 255));

	backbutton = new wxButton(menu, wxID_ANY, "Back", wxPoint(10, 5), wxSize(40, 15), wxNO_BORDER);
	backbutton->SetBackgroundColour(wxColour(255, 255, 255));
	backbutton->SetFont(SCalibri);
	backbutton->Bind(wxEVT_BUTTON, &BaseFrame::OnBackClicked, this);
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

void CenteredTextEditor::Show(bool show, wxGridCellAttr* attr)
{
	wxGridCellTextEditor::Show(show, attr);
	if (show)
	{
		wxTextCtrl* textCtrl = dynamic_cast<wxTextCtrl*>(m_control);
		if (textCtrl)
		{
			textCtrl->SetWindowStyle(textCtrl->GetWindowStyle() | wxTE_CENTRE);
		}
	}
}

LoginFrame::LoginFrame() : BaseFrame("HUMAN RESOURCES MANAGERMENT") {
	wxPanel* panel = new wxPanel(this);

	//frame1
	wxStaticText* text1 = new wxStaticText(panel, wxID_ANY, "LOGIN", wxPoint(370, 120));
	text1->SetFont(ConsolasB);

	//account
	wxStaticText* text2 = new wxStaticText(panel, wxID_ANY, "Account", wxPoint(250, 200));
	text2->SetFont(Calibri);
	wxTextCtrl* space2 = new wxTextCtrl(panel, wxID_ANY, "", wxPoint(370, 190), wxSize(300, 35), wxTE_PROCESS_ENTER);
	wxFont font = space2->GetFont();
	font.SetPointSize(15);
	space2->SetFont(font);
	accCtrl = space2;

	//password
	wxStaticText* text3 = new wxStaticText(panel, wxID_ANY, "Password", wxPoint(250, 250));
	text3->SetFont(Calibri);
	wxTextCtrl* space3 = new wxTextCtrl(panel, wxID_ANY, "", wxPoint(370, 240), wxSize(300, 35), wxTE_PASSWORD | wxTE_PROCESS_ENTER);
	font = space3->GetFont();
	font.SetPointSize(15);
	space3->SetFont(font);
	passCtrl = space3;

	//next button
	wxButton* button1 = new wxButton(panel, wxID_ANY, "Next", wxPoint(650, 300), wxSize(80, 40));
	button1->SetFont(Calibri);

	//event
	button1->Bind(wxEVT_BUTTON, &LoginFrame::OnButtonClicked, this);
	space2->Bind(wxEVT_TEXT_ENTER, &LoginFrame::EnterText, this);
	space3->Bind(wxEVT_TEXT_ENTER, &LoginFrame::EnterText, this);
	Bind(wxEVT_KEY_DOWN, &LoginFrame::EnterDown, this);
	Bind(wxEVT_CLOSE_WINDOW, &BaseFrame::OnClose, this);
}

void LoginFrame::Next() {
	wxString acc = accCtrl->GetValue();
	wxString pass = passCtrl->GetValue();
	if (hethong->CheckAccount(acc.ToStdString(), pass.ToStdString())) {
		frameStack.push(this);
		this->Hide();
		(new HomeFrame(accCtrl->GetValue()))->Show();
	}
	else {
		wxLogMessage("Sai tai khoan hoac mat khau");
	}
}

void LoginFrame::OnButtonClicked(wxCommandEvent& evt) {
	Next();
}

void LoginFrame::EnterDown(wxKeyEvent& evt) {
	if (evt.GetKeyCode() == WXK_RETURN) {
		Next();
	}
}

void LoginFrame::EnterText(wxCommandEvent& evt) {
	Next();
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
	if (hethong->CheckData(userName.ToStdString(), "admin")) {
		frameStack.push(this);
		this->Hide();
		(new QLTKFrame(userName))->Show();
	}
	else {
		wxLogMessage("Khong co quyen truy cap!");
	}
}

void HomeFrame::OnButton2Clicked(wxCommandEvent& evt) {
	if (hethong->CheckData(userName.ToStdString(), "admin")) {
		frameStack.push(this);
		this->Hide();
		(new QLNSFrame(userName))->Show();
	}
	else if (hethong->CheckData(userName.ToStdString(), "QuanLyNhanSu")) {
		frameStack.push(this);
		this->Hide();
		(new QLNSFrame(userName))->Show();
	}
	else {
		wxLogMessage("Khong co quyen truy cap!");
	}
}

void HomeFrame::OnButton3Clicked(wxCommandEvent& evt) {
	if (hethong->CheckData(userName.ToStdString(), "admin")) {
		frameStack.push(this);
		this->Hide();
		(new QLTLFrame(userName))->Show();
	}
	else if (hethong->CheckData(userName.ToStdString(), "QuanLyTienLuong")) {
		frameStack.push(this);
		this->Hide();
		(new QLTLFrame(userName))->Show();
	}
	else {
		wxLogMessage("Khong co quyen truy cap!");
	}
}

void HomeFrame::OnButton4Clicked(wxCommandEvent& evt) {
	frameStack.push(this);
	this->Hide();
	(new KFrame(userName))->Show();
}

QLTKFrame::QLTKFrame(wxString accName) : BaseFrame("QUAN LI TAI KHOAN") {
	wxPanel* panel = new wxPanel(this); //panel chính
	tagPanel = new wxPanel(panel, wxID_ANY, wxPoint(0, 25), wxSize(960, 100));
	table = new wxPanel(panel, wxID_ANY, wxPoint(0, 100), wxSize(720, 401));
	wxPanel* buttonPanel = new wxPanel(panel, wxID_ANY, wxPoint(720, 100), wxSize(240, 401));
	userName = accName;
	CreateMenu(panel, userName);

<<<<<<< HEAD
	SearchBar
	wxStaticText* text1 = new wxStaticText(tagPanel, wxID_ANY, "Tim kiem", wxPoint(20, 15));
	text1->SetFont(CalibriB);
	search = new wxTextCtrl(tagPanel, wxID_ANY, "Nhap noi dung tim kiem...", wxPoint(105, 15), wxSize(200, -1));
	search->SetFont(SCalibri);
<<<<<<< HEAD
	search->SetForegroundColour(wxColour(125, 125, 125));
	Tags bar
=======
	search->SetForegroundColour(wxColour(125, 125, 125));

	Tags bar
>>>>>>> a38727b7b5e322803b4a36883de601f0c0af3f25
=======
	//Tags bar
>>>>>>> 10b8fde0f8544a344b59b6ed3a59f95781c1f3eb
	wxStaticText* text2 = new wxStaticText(tagPanel, wxID_ANY, "Tags", wxPoint(435, 15));
	text2->SetFont(CalibriB);
	wxArrayString tags;
	tags.Add("Ten tai khoan");
	tags.Add("Quyen Admin");
	tags.Add("Quyen quan li nhan su");
	tags.Add("Quyen quan li tien luong");
	tag = new wxChoice(tagPanel, wxID_ANY, wxPoint(480, 15), wxSize(200, -1), tags);
	tag->Select(0);
	tag->SetFont(SCalibri);
	tag->Connect(wxEVT_COMMAND_CHOICE_SELECTED, wxCommandEventHandler(QLTKFrame::OnTagChoice));

	//SearchBar
	wxStaticText* text1 = new wxStaticText(tagPanel, wxID_ANY, "Tim kiem", wxPoint(20, 15));
	text1->SetFont(CalibriB);

	search = new wxTextCtrl(tagPanel, wxID_ANY, "Nhap noi dung tim kiem...", wxPoint(105, 15), wxSize(200, -1));
	search->SetFont(SCalibri);

	wxButton* searchButton = new wxButton(tagPanel, wxID_ANY, "SEARCH", wxPoint(690, 12), wxSize(90, 32));
	searchButton->SetFont(SCalibriB);
	searchButton->SetBackgroundColour(wxColour(180, 180, 180));
	wxButton* refreshButton = new wxButton(tagPanel, wxID_ANY, "REFRESH", wxPoint(790, 12), wxSize(90, 32));
	refreshButton->SetFont(SCalibriB);
	refreshButton->SetBackgroundColour(wxColour(100, 180, 120));

	//button
	wxButton* delButton = new wxButton(buttonPanel, wxID_ANY, "XOA TAI KHOAN", wxPoint(25, 0), wxSize(180, 50));
	delButton->SetForegroundColour(wxColour(255, 255, 255));
	delButton->SetBackgroundColour(wxColour(190, 80, 80));
	delButton->SetFont(CalibriB);
	wxButton* adjButton = new wxButton(buttonPanel, wxID_ANY, "SUA TAI KHOAN", wxPoint(25, 70), wxSize(180, 50));
	adjButton->SetForegroundColour(wxColour(255, 255, 255));
	adjButton->SetBackgroundColour(wxColour(80, 85, 155));
	adjButton->SetFont(CalibriB);
	wxButton* addButton = new wxButton(buttonPanel, wxID_ANY, "THEM TAI KHOAN", wxPoint(25, 320), wxSize(180, 50));
	addButton->SetForegroundColour(wxColour(255, 255, 255));
	addButton->SetBackgroundColour(wxColour(80, 155, 85));
	addButton->SetFont(CalibriB);

	//event
	this->Bind(wxEVT_SHOW, &QLTKFrame::OnShow, this);
	addButton->Bind(wxEVT_BUTTON, &QLTKFrame::OnAddButton, this);
	delButton->Bind(wxEVT_BUTTON, &QLTKFrame::OnDelButton, this);
	adjButton->Bind(wxEVT_BUTTON, &QLTKFrame::OnAdjButton, this);
	searchButton->Bind(wxEVT_BUTTON, &QLTKFrame::OnSearchButton, this);
	refreshButton->Bind(wxEVT_BUTTON, &QLTKFrame::OnRefreshButton, this);
	Bind(wxEVT_CLOSE_WINDOW, &BaseFrame::OnClose, this);
}

void QLTKFrame::OnSearchButton(wxCommandEvent& evt) {
	if (grid != nullptr) {
		grid->Destroy();
	}
	grid = new wxGrid(table, wxID_ANY, wxPoint(20, 0), wxSize(gridWidth, gridHeight));
	wxString searchContent = search->GetValue();
	int tagContent = tag->GetSelection();
	if (tag->GetSelection() > 0) {
		tagContent++;
	}
	vector<string> attributes = trave->ReturnName_of_Column("TaiKhoan");

	if (searchContent == "" || searchContent == "Nhap noi dung tim kiem..." || searchContent == "Nhap vao 0 hoac 1") {
		this->UpdateData();
	}
	else {
		nRow = trave->ReturnLineSearch("TaiKhoan", attributes[tagContent], searchContent.ToStdString());
		nCol = trave->ReturnColumn("TaiKhoan");
		grid->CreateGrid(nRow, nCol);

		grid->SetColLabelValue(0, "Ten tai khoan");
		grid->SetColLabelValue(1, "Mat khau");
		grid->SetColLabelValue(2, "Quyen quan li\ntai khoan");
		grid->SetColLabelValue(3, "Quyen quan li\nnhan su");
		grid->SetColLabelValue(4, "Quyen quan li\ntien luong");

		if (message != nullptr) {
			message->Destroy();
			message = nullptr;
		}
		if (nRow == 0) {
			nRow = 1;
			grid->AppendRows(1);
			message = new wxStaticText(tagPanel, wxID_ANY, "Khong co du lieu de in", wxPoint(105, 45));
			message->SetFont(SCalibriB);
			message->SetForegroundColour(wxColour(155, 20, 20));
		}
		else {
			std::string nRowStr = std::to_string(nRow);
			std::string messageStr = "Tim thay " + nRowStr + " ket qua";
			message = new wxStaticText(tagPanel, wxID_ANY, messageStr, wxPoint(105, 45));
			message->SetFont(SCalibriB);
			message->SetForegroundColour(wxColour(155, 20, 20));
			vector<Node> taikhoan = hethong->Search(attributes[tagContent], searchContent.ToStdString());
			for (int s = 0; s < nRow; s++) {
				grid->SetCellValue(s, 0, taikhoan[s].GetAccountName());
				grid->SetCellValue(s, 1, taikhoan[s].GetPassword());
				if (taikhoan[s].GetAdmin()) {
					grid->SetCellValue(s, 2, "Co");
					grid->SetCellTextColour(s, 2, wxColour(0, 125, 0));
				}
				else {
					grid->SetCellValue(s, 2, "Khong");
					grid->SetCellTextColour(s, 2, wxColour(125, 0, 0));
				}
				if (taikhoan[s].GetHRM()) {
					grid->SetCellValue(s, 3, "Co");
					grid->SetCellTextColour(s, 3, wxColour(0, 125, 0));
				}
				else {
					grid->SetCellValue(s, 3, "Khong");
					grid->SetCellTextColour(s, 3, wxColour(125, 0, 0));
				}
				if (taikhoan[s].GetFM()) {
					grid->SetCellValue(s, 4, "Co");
					grid->SetCellTextColour(s, 4, wxColour(0, 125, 0));
				}
				else {
					grid->SetCellValue(s, 4, "Khong");
					grid->SetCellTextColour(s, 4, wxColour(125, 0, 0));
				}
			}
		}
		this->CreateTable();
	}
	evt.Skip();
}

void QLTKFrame::OnTagChoice(wxCommandEvent& evt) {
	wxChoice* choice = (wxChoice*)evt.GetEventObject();
	int selection = choice->GetSelection();
	if (selection > 0) {
		wxLogMessage("Neu tim kiem, hay nhap vao o tim kiem gia tri 0 (khong co quyen) hoac 1 (co quyen)");
	}
}

void QLTKFrame::OnRefreshButton(wxCommandEvent& evt) {
	if (grid != nullptr) {
		grid->Destroy();
	}
	grid = new wxGrid(table, wxID_ANY, wxPoint(20, 0), wxSize(gridWidth, gridHeight));
	this->UpdateData();
	evt.Skip();
}

void QLTKFrame::UpdateData() {
	nRow = trave->ReturnLine("TaiKhoan", "TenTaiKhoan");
	nCol = trave->ReturnColumn("TaiKhoan");
	grid->CreateGrid(nRow, nCol);

	grid->SetColLabelValue(0, "Ten tai khoan");
	grid->SetColLabelValue(1, "Mat khau");
	grid->SetColLabelValue(2, "Quyen quan li\ntai khoan");
	grid->SetColLabelValue(3, "Quyen quan li\nnhan su");
	grid->SetColLabelValue(4, "Quyen quan li\ntien luong");

	if (message != nullptr) {
		message->Destroy();
		message = nullptr;
	}
	if (nRow == 0) {
		nRow = 1;
		grid->AppendRows(1);
		message = new wxStaticText(tagPanel, wxID_ANY, "Khong co du lieu de in", wxPoint(105, 45));
		message->SetFont(SCalibriB);
		message->SetForegroundColour(wxColour(155, 20, 20));
	}
	else {
		vector<Node> taikhoan = hethong->TakeAllAccount();
		for (int s = 0; s < nRow; s++) {
			grid->SetCellValue(s, 0, taikhoan[s].GetAccountName());
			grid->SetCellValue(s, 1, taikhoan[s].GetPassword());
			if (taikhoan[s].GetAdmin()) {
				grid->SetCellValue(s, 2, "Co");
				grid->SetCellTextColour(s, 2, wxColour(0, 125, 0));
			}
			else {
				grid->SetCellValue(s, 2, "Khong");
				grid->SetCellTextColour(s, 2, wxColour(125, 0, 0));
			}
			if (taikhoan[s].GetHRM()) {
				grid->SetCellValue(s, 3, "Co");
				grid->SetCellTextColour(s, 3, wxColour(0, 125, 0));
			}
			else {
				grid->SetCellValue(s, 3, "Khong");
				grid->SetCellTextColour(s, 3, wxColour(125, 0, 0));
			}
			if (taikhoan[s].GetFM()) {
				grid->SetCellValue(s, 4, "Co");
				grid->SetCellTextColour(s, 4, wxColour(0, 125, 0));
			}
			else {
				grid->SetCellValue(s, 4, "Khong");
				grid->SetCellTextColour(s, 4, wxColour(125, 0, 0));
			}
		}
	}
	this->CreateTable();
}

void QLTKFrame::CreateTable() {
	grid->SetDefaultCellFont(Calibri);
	grid->SetDefaultCellAlignment(wxALIGN_CENTER, wxALIGN_CENTER);
	grid->SetGridLineColour(wxColour(0, 0, 0));
	grid->SetLabelBackgroundColour(wxColour(25, 55, 135));
	grid->SetLabelTextColour(wxColour(255, 255, 255));
	grid->SetLabelFont(CalibriB);

	grid->EnableEditing(false);
	grid->EnableDragCell(false);
	grid->EnableDragColSize(false);
	grid->EnableDragRowSize(false);

	wxClientDC dc(grid);

	wxSize s = dc.GetTextExtent(grid->GetRowLabelValue(0));
	int tw = s.GetWidth();
	int th = s.GetHeight();
	wxSize s1 = dc.GetTextExtent(grid->GetColLabelValue(0));
	int tw1 = s1.GetWidth();
	wxSize s2 = dc.GetTextExtent(grid->GetColLabelValue(1));
	int tw2 = s2.GetWidth();
	wxSize s3 = dc.GetTextExtent(grid->GetColLabelValue(2));
	int tw3 = s3.GetWidth();
	wxSize s4 = dc.GetTextExtent(grid->GetColLabelValue(3));
	int tw4 = s4.GetWidth();
	wxSize s5 = dc.GetTextExtent(grid->GetColLabelValue(4));
	int tw5 = s5.GetWidth();
	int th5 = s5.GetHeight();

	int sum = tw + tw1 + tw2 + tw3 + tw4 + tw5;
	grid->SetRowLabelSize((gridWidth - sum) / 6 + tw * 3);
	grid->SetColSize(0, (gridWidth - sum) / 6 + tw1 + tw1 / 2);
	grid->SetColSize(1, (gridWidth - sum) / 6 + tw2 + tw2 / 2);
	grid->SetColSize(2, (gridWidth - sum) / 6 + tw3 * 0.8);
	grid->SetColSize(3, (gridWidth - sum) / 6 + tw4 * 0.8);
	grid->SetColSize(4, (gridWidth - sum) / 6 + tw5 * 0.8);

	int sum1 = th * nRow + th5 * 2;
	int curColHeight = grid->GetColLabelSize();
	int curRowHeight = grid->GetRowLabelSize();
	if (sum1 * 2 < gridHeight) {
		grid->SetDefaultRowSize((gridHeight - sum1 - th5 * 2) / nRow + th);
		grid->SetColLabelSize(curColHeight + th5 * 2);
	}
	else {
		grid->SetColLabelSize(curColHeight + th5 * 2);
		grid->AutoSizeRows(false);
	}
}

void QLTKFrame::OnDClick(wxGridEvent& evt)
{
	int row = evt.GetRow();
	grid->SelectRow(row);
	evt.Skip();
}

void QLTKFrame::OnShow(wxShowEvent& evt) {
	if (evt.IsShown()) {
		if (grid != nullptr) {
			grid->Destroy();
		}
		grid = new wxGrid(table, wxID_ANY, wxPoint(20, 0), wxSize(gridWidth, gridHeight));
		this->UpdateData();
	}
	evt.Skip();
}

QLTKFrameMini::QLTKFrameMini(wxArrayInt selectedRows, wxGrid* grid) : BaseFrame("Thong tin muon thay doi") {
	this->SetSize(wxSize(460, 260));
	this->SetPosition(wxPoint(540,285));
	panel = new wxPanel(this, wxID_ANY);
	gr = grid;
	numRows = selectedRows;

	wxStaticText* thuoctinh = new wxStaticText(panel, wxID_ANY, "Thuoc tinh", wxPoint(45, 40));
	thuoctinh->SetFont(CalibriB);
	wxArrayString tags;
	tags.Add("Ten tai khoan");
	tags.Add("Mat khau");
	tags.Add("Quyen Admin");
	tags.Add("Quyen quan li nhan su");
	tags.Add("Quyen quan li tien luong");
	attribute = new wxChoice(panel, wxID_ANY, wxPoint(140, 40), wxSize(240, -1), tags);
	attribute->SetFont(Calibri);
	attribute->Select(0);

	wxStaticText* noidung = new wxStaticText(panel, wxID_ANY, "Noi dung", wxPoint(45, 100));
	noidung->SetFont(CalibriB);
	AdjValue = new wxTextCtrl(panel, wxID_ANY, "", wxPoint(140, 100), wxSize(240, 30));
	AdjValue->SetFont(Calibri);

	wxButton* ok = new wxButton(panel, wxID_ANY, "Luu", wxPoint(350, 160), wxSize(80, 40));
	ok->SetFont(CalibriB);
	ok->SetBackgroundColour(wxColour(10, 80, 155));
	ok->SetForegroundColour(wxColour(255, 255, 255));
	wxButton* cancel = new wxButton(panel, wxID_ANY, "Huy", wxPoint(20, 160), wxSize(80, 40));
	cancel->SetFont(CalibriB);
	cancel->SetBackgroundColour(wxColour(155, 15, 15));
	cancel->SetForegroundColour(wxColour(255, 255, 255));

	//event
	ok->Bind(wxEVT_BUTTON, &QLTKFrameMini::OnSave, this);
	cancel->Bind(wxEVT_BUTTON, &QLTKFrameMini::OnCancel, this);
	Bind(wxEVT_CLOSE_WINDOW, &QLTKFrameMini::OnCloseMini, this);
}

void QLTKFrameMini::OnSave(wxCommandEvent& evt) {
	vector<string> att = trave->ReturnName_of_Column("TaiKhoan");
	int select = attribute->GetSelection();
	string adj = AdjValue->GetValue().ToStdString();
	wxString value = gr->GetCellValue(numRows[0], 0);
	if (adj=="") {
		if (warning != nullptr) {
			warning->Destroy();
			warning = nullptr;
		}
		warning = new wxStaticText(panel, wxID_ANY, "Vui long nhap vao noi dung muon chinh sua", wxPoint(140, 130));
	}
	else {
		hethong->EditAccount(att[select], adj, value.ToStdString());
		wxLogMessage("An nut Refresh de cap nhat lai du lieu");
		this->Destroy();
	}
	evt.Skip();
}

void QLTKFrameMini::OnCancel(wxCommandEvent& evt) {
	this->Destroy();
}

void QLTKFrameMini::OnCloseMini(wxCloseEvent& evt) {
	this->Destroy();
}

void QLTKFrame::OnAdjButton(wxCommandEvent& evt) {
	wxArrayInt selectedRows = grid->GetSelectedRows();
	if (selectedRows.size() != 1) {
		wxLogMessage("Vui long chon 1 tai khoan de chinh sua!");
	}
	else{
		QLTKFrameMini* mini = new QLTKFrameMini(selectedRows, grid);
		mini->Show();
	}
	evt.Skip();
}

void QLTKFrame::OnDelButton(wxCommandEvent& evt) {
	wxArrayInt selectedRows = grid->GetSelectedRows();
	int numSelectedRows = selectedRows.Count();
	for (int i = 0; i < numSelectedRows; i++) {
		if (!selectedRows.IsEmpty()) {
			int row = selectedRows[i];
			wxString value = grid->GetCellValue(row, 0);
			hethong->deleteAccount(value.ToStdString());
		}
	}
	if (grid != nullptr) {
		grid->Destroy();
	}
	grid = new wxGrid(table, wxID_ANY, wxPoint(20, 0), wxSize(gridWidth, gridHeight));
	this->UpdateData();
	evt.Skip();
}

void QLTKFrame::OnAddButton(wxCommandEvent& evt) {
	frameStack.push(this);
	this->Hide();
	(new QLTKFrame2(userName))->Show();
	evt.Skip();
}

QLTKFrame2::QLTKFrame2(wxString accName) : BaseFrame("NUMBER OF ACCOUNT") {
	wxPanel* panel = new wxPanel(this);
	userName = accName;
	CreateMenu(panel, userName);

	wxPanel* fake = new wxPanel(panel, wxID_ANY, wxPoint(140, 130), wxSize(670, 210));
	fake->SetBackgroundColour(wxColour(0, 0, 0));

	wxPanel* smallpanel = new wxPanel(fake, wxID_ANY, wxPoint(5, 5), wxSize(660, 200));
	smallpanel->SetBackgroundColour(wxColour(120, 220, 150));
	smallpanel->GetBorder();

	wxButton* next = new wxButton(panel, wxID_ANY, "NEXT", wxPoint(730, 350), wxSize(80, 40));
	next->SetFont(CalibriB);

	wxStaticText* text = new wxStaticText(smallpanel, wxID_ANY, "SO TAI KHOAN MUON THEM MOI:", wxPoint(45, 35));
	text->SetFont(LCalibriB);

	int wid = text->GetBestSize().GetWidth();

	textCtrl = new wxGrid(smallpanel, wxID_ANY, wxPoint(45, 90), wxSize(wid - 5, 70));
	textCtrl->CreateGrid(1, 1);
	textCtrl->SetRowLabelSize(0);
	textCtrl->SetColLabelSize(0);
	textCtrl->SetRowSize(0, 70);
	textCtrl->SetColSize(0, wid - 5);
	textCtrl->SetCellValue(0, 0, "Ex: 5 or 10");
	textCtrl->SetCellFont(0, 0, MCalibriI);
	textCtrl->SetCellAlignment(0, 0, wxALIGN_CENTER, wxALIGN_CENTER);
	textCtrl->SetDefaultEditor(new CenteredTextEditor);
	textCtrl->ForceRefresh();

	//event
	Bind(wxEVT_CLOSE_WINDOW, &BaseFrame::OnClose, this);
	textCtrl->Bind(wxEVT_GRID_CELL_CHANGED, &QLTKFrame2::OnChange, this);
	next->Bind(wxEVT_BUTTON, &QLTKFrame2::Next, this);
}

void QLTKFrame2::OnChange(wxGridEvent& evt) {
	value = textCtrl->GetCellValue(0, 0);
}

void QLTKFrame2::Next(wxCommandEvent& evt) {
	if (value.ToInt(&num)) {
		frameStack.push(this);
		this->Hide();
		(new QLTKFrame3(userName, num, num))->Show();
	}
	else {
		wxLogMessage("Vui long nhap vao 1 con so");
	}
}

QLTKFrame3::QLTKFrame3(wxString accName, int num, int fnum) : BaseFrame("Nhap thong tin chi tiet")
{
	panel = new wxPanel(this);
	userName = accName;
	fnumb = fnum;
	numb = num;
	CreateMenu(panel, userName);
	backbutton->Unbind(wxEVT_BUTTON, &BaseFrame::OnBackClicked, this);
	backbutton->Hide();

	wxString loop = "LOOP ";
	loop = loop.append(wxString::Format(wxT("%d"), fnumb - numb + 1));
	loop = loop.append("/");
	loop = loop.append(wxString::Format(wxT("%d"), fnumb));
	int lwid = 850 - userName.length() * 10;

	wxStaticText* text = new wxStaticText(panel, wxID_ANY, loop, wxPoint(lwid, 30));
	text->SetFont(CalibriI);
	text->SetForegroundColour(wxColour(125, 125, 125));

	int startx = 50;
	int starty = 140;
	int stx = 150;
	int spacex = 10;
	int spacey = 40;
	int wid = 450;
	int hei = 40;
	int x = startx;
	int y = starty;
	int t = 3;

	wxStaticText* tentaikhoan = new wxStaticText(panel, wxID_ANY, "Ten tai khoan", wxPoint(startx, y));
	tentaikhoan->SetFont(MCalibriB);
	x += spacex + stx;
	space1 = new wxTextCtrl(panel, wxID_ANY, "", wxPoint(x, y - t), wxSize(wid, hei));
	space1->SetFont(MCalibri);
	y += spacey + hei;

	wxStaticText* matkhau = new wxStaticText(panel, wxID_ANY, "Mat khau", wxPoint(startx, y));
	matkhau->SetFont(MCalibriB);
	space2 = new wxTextCtrl(panel, wxID_ANY, "", wxPoint(x, y - t), wxSize(wid, hei));
	space2->SetFont(MCalibri);
	y += spacey + hei;

	wxStaticText* quyenhan = new wxStaticText(panel, wxID_ANY, "Quyen han", wxPoint(startx, y));
	quyenhan->SetFont(MCalibriB);
	wxArrayString choices;
	choices.Add("Choose one");
	choices.Add("Quyen quan li tai khoan (Admin)");
	choices.Add("Quyen quan li nhan su");
	choices.Add("Quyen quan li tien luong");
	choice = new wxChoice(panel, wxID_ANY, wxPoint(x, y - t), wxSize(wid / 4 * 5, -1), choices);
	choice->Select(0);
	choice->SetFont(MCalibri);
	y += spacey + hei;

	wxButton* next = new wxButton(panel, wxID_ANY, "NEXT", wxPoint(700, y), wxSize(120, 40));
	next->SetFont(CalibriB);
	next->SetBackgroundColour(wxColour(75, 150, 235));
	wxButton* skip = new wxButton(panel, wxID_ANY, "SKIP", wxPoint(startx, y), wxSize(120, 40));
	skip->SetFont(CalibriB);
	skip->SetBackgroundColour(wxColour(200, 190, 255));

	//event
	Bind(wxEVT_CLOSE_WINDOW, &BaseFrame::OnClose, this);
	next->Bind(wxEVT_BUTTON, &QLTKFrame3::Check, this);
	skip->Bind(wxEVT_BUTTON, &QLTKFrame3::Skip, this);
}

void QLTKFrame3::Check(wxCommandEvent& evt) {
	int tkx = space1->GetPosition().x;
	int tky = space1->GetPosition().y;
	int mkx = space2->GetPosition().x;
	int mky = space2->GetPosition().y;
	int cx = choice->GetPosition().x;
	int cy = choice->GetPosition().y;
	if (warning1 != nullptr) {
		warning1->Destroy();
		warning1 = nullptr;
	}
	if (warning2 != nullptr) {
		warning2->Destroy();
		warning2 = nullptr;
	}
	if (warning3 != nullptr) {
		warning3->Destroy();
		warning3 = nullptr;
	}
	if (!hethong->check6Number(space1->GetValue().ToStdString())) {
		warning1 = new wxStaticText(panel, wxID_ANY, "Ten tai khoan phai co do dai nhieu hon 6 ki tu", wxPoint(tkx, tky + 45), wxSize(400, -1));
		warning1->SetFont(CalibriB);
		warning1->SetForegroundColour(wxColour(155, 20, 20));
	}
	if (!hethong->check6Number(space2->GetValue().ToStdString())) {
		warning2 = new wxStaticText(panel, wxID_ANY, "Mat khau phai co do dai nhieu hon 6 ki tu", wxPoint(mkx, mky + 45));
		warning2->SetFont(CalibriB);
		warning2->SetForegroundColour(wxColour(155, 20, 20));
	}
	int selectedIndex = choice->GetSelection();
	if (selectedIndex == 0) {
		warning3 = new wxStaticText(panel, wxID_ANY, "Xin chon quyen truy cap cho tai khoan", wxPoint(cx, cy + 45));
		warning3->SetFont(CalibriB);
		warning3->SetForegroundColour(wxColour(155, 20, 20));
	}
	if (hethong->checkName("TenTaiKhoan", space1->GetValue().ToStdString())) {
		warning1 = new wxStaticText(panel, wxID_ANY, "Ten tai khoan da co, vui long nhap ten khac", wxPoint(tkx, tky + 45));
		warning1->SetFont(CalibriB);
		warning1->SetForegroundColour(wxColour(155, 20, 20));
	}
	if (!hethong->CheckSpacebar(space1->GetValue().ToStdString())) {
		warning1 = new wxStaticText(panel, wxID_ANY, "Ten tai khoan khong duoc co khoang cach", wxPoint(tkx, tky + 45), wxSize(400, -1));
		warning1->SetFont(CalibriB);
		warning1->SetForegroundColour(wxColour(155, 20, 20));
	}
	if (!hethong->CheckSpacebar(space2->GetValue().ToStdString())) {
		warning2 = new wxStaticText(panel, wxID_ANY, "Mat khau khong duoc co khoang cach", wxPoint(mkx, mky + 45));
		warning2->SetFont(CalibriB);
		warning2->SetForegroundColour(wxColour(155, 20, 20));
	}
	if (hethong->check6Number(space1->GetValue().ToStdString()) &&
		hethong->check6Number(space2->GetValue().ToStdString()) && 
		selectedIndex != 0 &&
		!hethong->checkName("TenTaiKhoan", space1->GetValue().ToStdString()) &&
		hethong->CheckSpacebar(space1->GetValue().ToStdString()) &&
		hethong->CheckSpacebar(space2->GetValue().ToStdString())) {
		Next();
	}
}

void QLTKFrame3::Next() {
	string tenTK = space1->GetValue().ToStdString();
	string passTK = space2->GetValue().ToStdString();
	bool Admin = false;
	bool QuanLiNhanSu = false;
	bool QuanLiTienLuong = false;

	int selectedIndex = choice->GetSelection();
	if (selectedIndex != wxNOT_FOUND) {
		switch (selectedIndex) {
		case 1: 
			Admin = true;
			break;
		case 2: 
			QuanLiNhanSu = true;
			break;
		case 3: 
			QuanLiTienLuong = true;
			break;
		}
	}
	Node* tk = new Node(tenTK, passTK, Admin, QuanLiNhanSu, QuanLiTienLuong);
	hethong->CreateAccount(tk);
	numb--;
	BackToData();
}

void QLTKFrame3::Skip(wxCommandEvent& evt) {
	fnumb = fnumb - numb + 1;
	numb = 0;
	BackToData();
}

void QLTKFrame3::BackToData() {
	if (numb == 0)
	{
		this->Destroy();
		for (int i = 0; i < fnumb; i++) {
			frameStack.top()->Destroy();
			frameStack.pop();
		}
		frameStack.top()->Show();
		frameStack.pop();
	}
	else {
		frameStack.push(this);
		this->Hide();
		(new QLTKFrame3(userName, numb, fnumb))->Show();
	}
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
	(new QLNSFrame10(userName))->Show();
}

void QLNSFrame::OnButton3Clicked(wxCommandEvent& evt) {
	frameStack.push(this);
	this->Hide();
	(new QLNSFrame16(userName))->Show();
}

QLNSFrame2::QLNSFrame2(wxString accName) : BaseFrame("QUAN LI HO SO NHAN VIEN") {
	wxPanel* panel = new wxPanel(this);
	userName = accName;
	CreateMenu(panel, userName);

	//event
	Bind(wxEVT_CLOSE_WINDOW, &BaseFrame::OnClose, this);
}

QLNSFrame10::QLNSFrame10(wxString accName) : BaseFrame("QUAN LI CHUC VU") {
	wxPanel* panel = new wxPanel(this);
	userName = accName;
	CreateMenu(panel, userName);

	//event
	Bind(wxEVT_CLOSE_WINDOW, &BaseFrame::OnClose, this);
}

QLNSFrame16::QLNSFrame16(wxString accName) : BaseFrame("QUAN LI PHONG BAN") {
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
	if (hethong->CheckData(userName.ToStdString(), "admin") || hethong->CheckData(userName.ToStdString(), "QuanLyNhanSu") || hethong->CheckData(userName.ToStdString(), "QuanLyTienLuong")) {
		frameStack.push(this);
		this->Hide();
		(new KFrame2(userName))->Show();
	}
	else {
		wxLogMessage("Khong co quyen truy cap!");
	}
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
	button1->Bind(wxEVT_BUTTON, &KFrame2::OnButton1Clicked, this);
	button2->Bind(wxEVT_BUTTON, &KFrame2::OnButton2Clicked, this);
	Bind(wxEVT_CLOSE_WINDOW, &BaseFrame::OnClose, this);
}

void KFrame2::OnButton1Clicked(wxCommandEvent& evt) {
	frameStack.push(this);
	this->Hide();
	(new KFrame3(userName))->Show();
}

void KFrame2::OnButton2Clicked(wxCommandEvent& evt) {
	frameStack.push(this);
	this->Hide();
	(new KFrame6(userName))->Show();
}

KFrame3::KFrame3(wxString accName) : BaseFrame("QUAN LI BAO HIEM") {
	wxPanel* panel = new wxPanel(this);
	userName = accName;
	CreateMenu(panel, userName);

	//event
	Bind(wxEVT_CLOSE_WINDOW, &BaseFrame::OnClose, this);
}

KFrame6::KFrame6(wxString accName) : BaseFrame("QUAN LI KHEN THUONG, KI LUAT") {
	wxPanel* panel = new wxPanel(this);
	userName = accName;
	CreateMenu(panel, userName);

	//event
	Bind(wxEVT_CLOSE_WINDOW, &BaseFrame::OnClose, this);
}