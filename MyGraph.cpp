// MyGraph.cpp: файл реализации
//

#include "stdafx.h"
#include "Kurs1.h"
#include "MyGraph.h"
//#include "Kurs1Dlg.h"

// CMyGraph

IMPLEMENT_DYNAMIC(CMyGraph, CStatic)

CMyGraph::CMyGraph()
{

}

CMyGraph::~CMyGraph()
{
}


BEGIN_MESSAGE_MAP(CMyGraph, CStatic)
	ON_WM_PAINT()
END_MESSAGE_MAP()



// обработчики сообщений CMyGraph




void CMyGraph::OnPaint()
{
	CPaintDC dc(this); // device context for painting
					   // TODO: Add your message handler code here
					   // Do not call CStatic::OnPaint() for painting messages
	CRect rc;
	GetClientRect(&rc);

	dc.FillSolidRect(&rc, RGB(0, 128, 128));

	CPoint pt = rc.CenterPoint();

	CPen pen1;
	pen1.CreatePen(PS_SOLID, 1, RGB(200, 200, 200));
	CPen *pOp = dc.SelectObject(&pen1);


	dc.MoveTo(0, pt.y);
	dc.LineTo(rc.right, pt.y);
	dc.MoveTo(pt.x, 0);
	dc.LineTo(pt.x, rc.bottom );

	
	//CKurs1Dlg *mainWnd = (CKurs1Dlg *)AfxGetMainWnd();
	//if(mainWnd)
	{
		//std::vector<CPoint> vecP =	mainWnd->m_vecPt;
		CPen penG;
		penG.CreatePen(PS_SOLID, 1, RGB(255, 128, 0));
		dc.SelectObject(&penG);
		for (size_t i = 0; i < m_vecP.size(); i++)
		{
			if(!i)
				dc.MoveTo(m_vecP[0]);
			else
				dc.LineTo(m_vecP[i]);
		}

	}


	dc.SelectObject(pOp);
}

int CMyGraph::GetVecPt(IfaceKurs const * iface)
{
	iface->GetVecPt(m_vecP);
	return m_vecP.size();
}
