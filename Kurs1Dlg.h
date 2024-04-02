
// Kurs1Dlg.h : файл заголовка
//

#pragma once

#include "MyGraph.h"
#include "Calc.h"
#include "IfaceKurs.h"
#include "afxwin.h"
#include "afxcmn.h"

struct Scale_Shift_s
{
	double ScaleX;
	double ScaleY;
	int ShiftX, ShiftY;
	struct Scale_Shift_s() {
		ScaleX = 1; ScaleY = 1; ShiftX = ShiftY = 100;
	}

};



// диалоговое окно CKurs1Dlg
class CKurs1Dlg : public CDialogEx 
	, IfaceKurs
{
// Создание
public:
	CKurs1Dlg(CWnd* pParent = NULL);	// стандартный конструктор

// Данные диалогового окна
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_KURS1_DIALOG };
#endif

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// поддержка DDX/DDV


// Реализация
protected:
	HICON m_hIcon;

	// Созданные функции схемы сообщений
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
	CEdit m_EdFi;
	double m_A;
	double m_Fi;
	Scale_Shift_s m_ScShift;
	bool m_bInited;
protected:
	void ScaleShift();
public:
	afx_msg void OnEnChangeEditFi();
	afx_msg void OnBnClickedButScup();
	afx_msg void OnBnClickedButScdn();
	//afx_msg void OnBnClickedBtnScUp();
	
	afx_msg void OnNMCustomdrawSliderScale(NMHDR *pNMHDR, LRESULT *pResult);
public:
	CSliderCtrl m_SliderScale;
	afx_msg void OnTRBNThumbPosChangingSliderScale(NMHDR *pNMHDR, LRESULT *pResult);
	afx_msg void OnNMReleasedcaptureSliderScale(NMHDR *pNMHDR, LRESULT *pResult);
};
