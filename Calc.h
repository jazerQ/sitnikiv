#pragma once
#include "ScaleShift.h"
#include <vector>

class CCalc :
	public CScaleShift
{
public:
	CCalc();
	~CCalc();
protected:
	double m_a;
	double m_f;
public:
	CPoint GetPoint(double phi);
	void SetPar(double A, double F) { m_a = A; m_f = F; };
	size_t GetVseTochki(std::vector<CPoint> &vecPt);
};

