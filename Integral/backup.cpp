#include "stdafx.h"  //________________________________________ Integral.cpp
#include "Integral.h"

int APIENTRY wWinMain(HINSTANCE hInstance, HINSTANCE, LPTSTR cmdLine, int cmdShow) {
	Integral app;
	return app.BeginDialog(IDI_Integral, hInstance);
}

void Integral::Window_Open(Win::Event& e)
{
	this->radioSimpson.Checked = false;
	this->radioTrapezoidal.Checked = true;
}

void Integral::btCalcular_Click(Win::Event& e)
{

}

void Integral::radioSimpson_Click(Win::Event& e)
{
}

