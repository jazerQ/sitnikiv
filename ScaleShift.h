#pragma once
#include "stdafx.h"
class CScaleShift
{
public:
	CScaleShift();
	virtual ~CScaleShift();
protected:
	CPoint m_ptC;//center point
	double m_Scale;
public:
	void Scale(double newSc);
	void Shift(CPoint &ptNew);
	CPoint ToGraph(double x, double y);
};

