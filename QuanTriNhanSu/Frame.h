#pragma once
#include <wx/wx.h>
#include <iostream>
using namespace std;

class BaseFrame : public wxFrame //BaseFrame ke thua wxframe
{
public:
	BaseFrame(const wxString& title);
	void OnBackClicked(wxCommandEvent& evt);
	void OnClose(wxCloseEvent& evt);
	void UpdateSoon(wxCommandEvent& evt);
	void CreateMenu(wxWindow* parent, wxString userName);
	void OnSearch(wxCommandEvent& evt);
	void UnSearch(wxFocusEvent& evt);
	wxTextCtrl* accCtrl;
	wxTextCtrl* passCtrl;
};

class LoginFrame : public BaseFrame //frame ke thua Baseframe ke thua wxframe
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