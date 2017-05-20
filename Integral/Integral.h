#pragma once  //______________________________________ Integral.h  
#include "Resource.h"
class Integral : public Win::Dialog
{
public:
	Integral()
	{
	}
	~Integral()
	{
	}
protected:
	//______ Wintempla GUI manager section begin: DO NOT EDIT AFTER THIS LINE
	Win::Label lb1;
	Win::Label lb2;
	Win::Textbox tbxA;
	Win::Textbox tbxB;
	Win::Label lb3;
	Win::Textbox tbxSteps;
	Win::Button radioSimpson;
	Win::Button radioTrapezoidal;
	Win::Button btCalcular;
	Win::Textbox tbxSalida;
protected:
	Win::Gdi::Font fontArial014A;
	void GetDialogTemplate(DLGTEMPLATE& dlgTemplate)
	{
		dlgTemplate.cx = Sys::Convert::PixelToDlgUnitX(506);
		dlgTemplate.cy = Sys::Convert::PixelToDlgUnitY(590);
		dlgTemplate.style = WS_CAPTION | WS_POPUP | WS_SYSMENU | WS_VISIBLE | DS_CENTER | DS_MODALFRAME;
	}
	//_________________________________________________
	void InitializeGui()
	{
		this->Text = L"Integral";
		lb1.Create(NULL, L"a=", WS_CHILD | WS_VISIBLE | SS_LEFT | SS_WINNORMAL, 11, 10, 47, 25, hWnd, 1000);
		lb2.Create(NULL, L"b=", WS_CHILD | WS_VISIBLE | SS_LEFT | SS_WINNORMAL, 9, 49, 49, 25, hWnd, 1001);
		tbxA.Create(WS_EX_CLIENTEDGE, NULL, WS_CHILD | WS_TABSTOP | WS_VISIBLE | ES_AUTOHSCROLL | ES_LEFT | ES_WINNORMALCASE, 63, 11, 86, 25, hWnd, 1002);
		tbxB.Create(WS_EX_CLIENTEDGE, NULL, WS_CHILD | WS_TABSTOP | WS_VISIBLE | ES_AUTOHSCROLL | ES_LEFT | ES_WINNORMALCASE, 63, 48, 86, 25, hWnd, 1003);
		lb3.Create(NULL, L"Steps=", WS_CHILD | WS_VISIBLE | SS_LEFT | SS_WINNORMAL, 167, 9, 48, 25, hWnd, 1004);
		tbxSteps.Create(WS_EX_CLIENTEDGE, NULL, WS_CHILD | WS_TABSTOP | WS_VISIBLE | ES_AUTOHSCROLL | ES_LEFT | ES_WINNORMALCASE, 221, 10, 85, 25, hWnd, 1005);
		radioSimpson.Create(NULL, L"Simpson", WS_CHILD | WS_TABSTOP | WS_VISIBLE | BS_AUTORADIOBUTTON | BS_LEFT | BS_VCENTER, 323, 14, 87, 26, hWnd, 1006);
		radioTrapezoidal.Create(NULL, L"Trapezoidal", WS_CHILD | WS_TABSTOP | WS_VISIBLE | BS_AUTORADIOBUTTON | BS_LEFT | BS_VCENTER, 322, 40, 88, 26, hWnd, 1007);
		btCalcular.Create(NULL, L"Calcular", WS_CHILD | WS_TABSTOP | WS_VISIBLE | BS_PUSHBUTTON | BS_CENTER | BS_VCENTER, 419, 9, 72, 28, hWnd, 1008);
		tbxSalida.Create(WS_EX_CLIENTEDGE, NULL, WS_CHILD | WS_TABSTOP | WS_VISIBLE | ES_AUTOHSCROLL | ES_MULTILINE | ES_READONLY | ES_LEFT | ES_WINNORMALCASE, 9, 90, 490, 493, hWnd, 1009);
		fontArial014A.Create(L"Arial", 14, false, false, false, false);
		lb1.Font = fontArial014A;
		lb2.Font = fontArial014A;
		tbxA.Font = fontArial014A;
		tbxB.Font = fontArial014A;
		lb3.Font = fontArial014A;
		tbxSteps.Font = fontArial014A;
		radioSimpson.Font = fontArial014A;
		radioTrapezoidal.Font = fontArial014A;
		btCalcular.Font = fontArial014A;
		tbxSalida.Font = fontArial014A;
	}
	//_________________________________________________
	void radioSimpson_Click(Win::Event& e);
	void radioTrapezoidal_Click(Win::Event& e);
	void btCalcular_Click(Win::Event& e);
	void Window_Open(Win::Event& e);
	//_________________________________________________
	bool EventHandler(Win::Event& e)
	{
		if (radioSimpson.IsEvent(e, BN_CLICKED)) { radioSimpson_Click(e); return true; }
		if (radioTrapezoidal.IsEvent(e, BN_CLICKED)) { radioTrapezoidal_Click(e); return true; }
		if (btCalcular.IsEvent(e, BN_CLICKED)) { btCalcular_Click(e); return true; }
		return false;
	}
};
