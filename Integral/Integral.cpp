#include "stdafx.h"  //________________________________________ Integral.cpp
#include "Integral.h"
#include <math.h>
#define PI 3.14159265358979323846 
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
	double a = tbxA.DoubleValue;
	double b = tbxB.DoubleValue;
	double steps = tbxSteps.DoubleValue;
	double delta = (b - a) / steps;
	double area = 0.0;
	double x, y;
	double suma;
	double sumatoria = 0.0;
	wstring texto;
	for (int i = 1; i <= steps; i++)
	{
		x = (a + i)*delta;
		//y = sin(x * PI / 180);
		y = sin(x);
		suma = x + y;
		Sys::Format(texto, L"%f\r\t%f\r\t%f\r\n", x, y, suma);
		tbxSalida.Text += texto;
		if (radioTrapezoidal.Checked == true)
		{
			sumatoria =sumatoria+ (2 * y);
		}
		if (radioSimpson.Checked == true)
		{
			if (i % 2 == 0)
			{
				sumatoria =sumatoria+ (2 * y);
			}
			else
			{
				sumatoria =sumatoria+ (4 * y);
			}
		}
		
	}
	if (radioTrapezoidal.Checked == true)
	{
		area=(delta*sumatoria)/2;
	}
	if (radioSimpson.Checked == true)
	{
		area = (delta*sumatoria) / 3;
	}
	Sys::Format(texto, L"Area= %f", area);
	tbxSalida.Text += texto;
}

void Integral::radioSimpson_Click(Win::Event& e)
{
}

void Integral::radioTrapezoidal_Click(Win::Event& e)
{
}

