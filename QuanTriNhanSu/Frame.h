#pragma once
#include "Hethong.h"
#include <wx/grid.h>
#include <wx/wx.h>
#include <iostream>
using namespace std;

class BaseFrame : public wxFrame
{
public:
	BaseFrame(const wxString& title);
	void OnBackClicked(wxCommandEvent& evt);
	void OnClose(wxCloseEvent& evt);
	void UpdateSoon(wxCommandEvent& evt);
	void CreateMenu(wxWindow* parent, wxString userName);
};

class CenteredTextEditor : public wxGridCellTextEditor
{
public:
	void Show(bool show, wxGridCellAttr* attr) override;
};

class LoginFrame : public BaseFrame
{
public:
	LoginFrame();
private:
	void Next();
	void OnButtonClicked(wxCommandEvent& evt);
	void EnterDown(wxKeyEvent& evt);
	void EnterText(wxCommandEvent& evt);
	wxTextCtrl* accCtrl;
	wxTextCtrl* passCtrl;
};

class HomeFrame : public BaseFrame
{
public:
	HomeFrame(wxString accName);
private:
	void OnButton1Clicked(wxCommandEvent& evt);
	void OnButton2Clicked(wxCommandEvent& evt);
	void OnButton3Clicked(wxCommandEvent& evt);
	void OnButton4Clicked(wxCommandEvent& evt);
	wxString userName;
};

class QLTKFrame : public BaseFrame
{
public:
	QLTKFrame(wxString accName);
private:
	void OnAddButton(wxCommandEvent& evt);
	void OnAdjButton(wxCommandEvent& evt);
	void OnDelButton(wxCommandEvent& evt);
	wxString userName;
	wxGrid* grid;
	wxPanel* table;
	void UpdateData(int, int);
	void OnShow(wxShowEvent& evt);
	void OnDClick(wxGridEvent& evt);
};

class QLTKFrame2 : public BaseFrame {
public:
	QLTKFrame2(wxString accName);
private:
	void Next(wxCommandEvent& evt);
	void OnChange(wxGridEvent& evt);
	int num;
	wxGrid* textCtrl;
	wxString userName;
	wxString value;
};

class QLTKFrame3 : public BaseFrame {
public:
	QLTKFrame3(wxString accName, int num, int fnum);
private:
	void Check(wxCommandEvent& evt);
	void Next();
	wxPanel* panel;
	wxTextCtrl* space1;
	wxTextCtrl* space2;
	wxChoice* choice;
	wxString userName;
	int numb;
	int fnumb;
	wxStaticText* warning1;
	wxStaticText* warning2;
	wxStaticText* warning3;
	wxStaticText* warning4;
};

class QLNSFrame : public BaseFrame
{
public:
	QLNSFrame(wxString accName);
private:
	void OnButton1Clicked(wxCommandEvent& evt);
	void OnButton2Clicked(wxCommandEvent& evt);
	void OnButton3Clicked(wxCommandEvent& evt);
	wxString userName;
};

class QLNSFrame2 : public BaseFrame //quan li ho so nhan vien
{
public:
	QLNSFrame2(wxString accName);
private:
	wxString userName;
};

class QLNSFrame10 : public BaseFrame //quan li chuc vu
{
public:
	QLNSFrame10(wxString accName);
private:
	wxString userName;
};

class QLNSFrame16 : public BaseFrame //quan li phong ban
{
public:
	QLNSFrame16(wxString accName);
private:
	wxString userName;
};

class QLTLFrame : public BaseFrame
{
public:
	QLTLFrame(wxString accName);
private:
	void OnButton1Clicked(wxCommandEvent& evt);
	void OnButton2Clicked(wxCommandEvent& evt);
	void OnButton3Clicked(wxCommandEvent& evt);
	wxString userName;
};

class QLTLFrame2 : public BaseFrame //xem tat ca thong tin
{
public:
	QLTLFrame2(wxString accName);
private:
	wxString userName;
};

class QLTLFrame3 : public BaseFrame //xem, sua cham cong, luong co ban
{
public:
	QLTLFrame3(wxString accName);
private:
	wxString userName;
};

class QLTLFrame5 : public BaseFrame //xem thong tin lam them
{
public:
	QLTLFrame5(wxString accName);
private:
	wxString userName;
};

class KFrame : public BaseFrame
{
public:
	KFrame(wxString accName);
private:
	void OnButton1Clicked(wxCommandEvent& evt);
	void OnButton2Clicked(wxCommandEvent& evt);
	void OnButton3Clicked(wxCommandEvent& evt);
	void OnButton4Clicked(wxCommandEvent& evt);
	wxString userName;
};

class KFrame2 : public BaseFrame
{
public:
	KFrame2(wxString accName);
private:
	void OnButton1Clicked(wxCommandEvent& evt);
	void OnButton2Clicked(wxCommandEvent& evt);
	wxString userName;
};

class KFrame3 : public BaseFrame
{
public:
	KFrame3(wxString accName);
private:
	wxString userName;
};

class KFrame6 : public BaseFrame
{
public:
	KFrame6(wxString accName);
private:
	wxString userName;
};