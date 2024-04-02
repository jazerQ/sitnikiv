
// Kurs1Dlg.h : ���� ���������
//

#pragma once

#include "MyGraph.h"
#include "Calc.h"
#include "IfaceKurs.h"
#include "afxwin.h"
// ���������� ���� CKurs1Dlg
class CKurs1Dlg : public CDialogEx 
	, IfaceKurs
{
// ��������
public:
	CKurs1Dlg(CWnd* pParent = NULL);	// ����������� �����������

// ������ ����������� ����
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_KURS1_DIALOG };
#endif

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// ��������� DDX/DDV


// ����������
protected:
	HICON m_hIcon;

	// ��������� ������� ����� ���������
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnBnClickedOk();
	CMyGraph m_paint;
	CCalc m_Calc;
	std::vector<CPoint> m_vecPt;
	void Risovat(double A, double Phase);
	afx_msg void OnBnClickedWindowTileVert();
	virtual int GetVecPt(std::vector<CPoint> &vec) const override;
	afx_msg void OnEnChangeEditA();
protected:
	CEdit m_edA;
	double m_A;
};
