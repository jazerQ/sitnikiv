#include "stdafx.h"
#include "Calc.h"
#define _USE_MATH_DEFINES
#include "math.h"

CCalc::CCalc()
{
}


CCalc::~CCalc()
{
}

CPoint CCalc::GetPoint(double phi)
{
	double x, y;
	x = m_a*sin(phi);
	y = m_a*sin(2 * phi + m_f);
	return ToGraph(x,y);
}

size_t CCalc::GetVseTochki(std::vector<CPoint>& vecPt)
{
	vecPt.clear();
	for (double phi = 0; phi <= 2.* M_PI; phi += M_PI / 180.)
	{
		CPoint pt = GetPoint(phi);
		vecPt.push_back(pt);
	}
	return vecPt.size();
}

