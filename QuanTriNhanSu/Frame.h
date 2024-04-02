#pragma once
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
	wxTextCtrl* accCtrl;
	wxTextCtrl* passCtrl;
};

class LoginFrame : public BaseFrame 
{
public:	
	LoginFrame();
private:
	void OnButtonClicked(wxCommandEvent& evt);
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
	wxString userName;
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

class QLNSFrame11 : public BaseFrame //quan li chuc vu
{
public:
	QLNSFrame11(wxString accName);
private:
	wxString userName;
};

class QLNSFrame17 : public BaseFrame //quan li phong ban
{
public:
	QLNSFrame17(wxString accName);
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

class KFrame9 : public BaseFrame
{
public:
	KFrame9(wxString accName);
private:
	wxString userName;
};