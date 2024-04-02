#pragma once


// CMyGraph
#include "IfaceKurs.h"
class CMyGraph : public CStatic
{
	DECLARE_DYNAMIC(CMyGraph)

public:
	CMyGraph();
	virtual ~CMyGraph();

protected:
	DECLARE_MESSAGE_MAP()
	std::vector<CPoint> m_vecP;
public:
	afx_msg void OnPaint();
	int GetVecPt(IfaceKurs const *iface);
};


