
// Kurs1Dlg.cpp : ���� ����������
//

#include "stdafx.h"
#include "Kurs1.h"
#include "Kurs1Dlg.h"
#include "afxdialogex.h"
#include "resource.h"
#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// ���������� ���� CAboutDlg ������������ ��� �������� �������� � ����������

class CAboutDlg : public CDialogEx
{
public:
	CAboutDlg();

// ������ ����������� ����
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_ABOUTBOX };
#endif

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // ��������� DDX/DDV

// ����������
protected:
	DECLARE_MESSAGE_MAP()
};

CAboutDlg::CAboutDlg() : CDialogEx(IDD_ABOUTBOX)
{
}

void CAboutDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(CAboutDlg, CDialogEx)
END_MESSAGE_MAP()


// ���������� ���� CKurs1Dlg



CKurs1Dlg::CKurs1Dlg(CWnd* pParent /*=NULL*/)
	: CDialogEx(IDD_KURS1_DIALOG, pParent)
	,m_A(0)
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CKurs1Dlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_EDIT_A, m_edA);
}

BEGIN_MESSAGE_MAP(CKurs1Dlg, CDialogEx)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_BN_CLICKED(IDOK, &CKurs1Dlg::OnBnClickedOk)
	ON_BN_CLICKED(ID_WINDOW_TILE_VERT, &CKurs1Dlg::OnBnClickedWindowTileVert)
	ON_EN_CHANGE(IDC_EDIT_A, &CKurs1Dlg::OnEnChangeEditA)
END_MESSAGE_MAP()


// ����������� ��������� CKurs1Dlg

BOOL CKurs1Dlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// ���������� ������ "� ���������..." � ��������� ����.

	// IDM_ABOUTBOX ������ ���� � �������� ��������� �������.
	ASSERT((IDM_ABOUTBOX & 0xFFF0) == IDM_ABOUTBOX);
	ASSERT(IDM_ABOUTBOX < 0xF000);

	CMenu* pSysMenu = GetSystemMenu(FALSE);
	if (pSysMenu != NULL)
	{
		BOOL bNameValid;
		CString strAboutMenu;
		bNameValid = strAboutMenu.LoadString(IDS_ABOUTBOX);
		ASSERT(bNameValid);
		if (!strAboutMenu.IsEmpty())
		{
			pSysMenu->AppendMenu(MF_SEPARATOR);
			pSysMenu->AppendMenu(MF_STRING, IDM_ABOUTBOX, strAboutMenu);
		}
	}

	// ������ ������ ��� ����� ����������� ����.  ����� ������ ��� �������������,
	//  ���� ������� ���� ���������� �� �������� ����������
	SetIcon(m_hIcon, TRUE);			// ������� ������
	SetIcon(m_hIcon, FALSE);		// ������ ������

	// TODO: �������� �������������� �������������
	m_paint.SubclassDlgItem(IDC_GRAPH, this);

	m_Calc.Scale(10);
	CRect rc;
	m_paint.GetClientRect(&rc);
	m_Calc.Shift(rc.CenterPoint());
	return TRUE;  // ������� �������� TRUE, ���� ����� �� ������� �������� ����������
}

void CKurs1Dlg::OnSysCommand(UINT nID, LPARAM lParam)
{
	if ((nID & 0xFFF0) == IDM_ABOUTBOX)
	{
		CAboutDlg dlgAbout;
		dlgAbout.DoModal();
	}
	else
	{
		CDialogEx::OnSysCommand(nID, lParam);
	}
}

// ��� ���������� ������ ����������� � ���������� ���� ����� ��������������� ����������� ���� �����,
//  ����� ���������� ������.  ��� ���������� MFC, ������������ ������ ���������� ��� �������������,
//  ��� ������������� ����������� ������� ��������.

void CKurs1Dlg::OnPaint()
{
	if (IsIconic())
	{
		CPaintDC dc(this); // �������� ���������� ��� ���������

		SendMessage(WM_ICONERASEBKGND, reinterpret_cast<WPARAM>(dc.GetSafeHdc()), 0);

		// ������������ ������ �� ������ ����������� ��������������
		int cxIcon = GetSystemMetrics(SM_CXICON);
		int cyIcon = GetSystemMetrics(SM_CYICON);
		CRect rect;
		GetClientRect(&rect);
		int x = (rect.Width() - cxIcon + 1) / 2;
		int y = (rect.Height() - cyIcon + 1) / 2;

		// ��������� ������
		dc.DrawIcon(x, y, m_hIcon);
	}
	else
	{
		CDialogEx::OnPaint();
		CPaintDC dc(this);
		POINT pt1 = { 0,0 }, pt2 = {20,20};
		CRect rect(pt1, pt2);
		COLORREF cl = RGB(255, 0, 255);
		dc.FillSolidRect(LPCRECT(rect), cl);
		//GetClientRect(&rect);

	}
}

// ������� �������� ��� ������� ��� ��������� ����������� ������� ��� �����������
//  ���������� ����.
HCURSOR CKurs1Dlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}



void CKurs1Dlg::OnBnClickedOk()
{
	SetWindowText(L"������ ��������");

	//CDialogEx::OnOK();
}


void CKurs1Dlg::Risovat(double A, double Phase)
{
	m_Calc.SetPar(A, Phase);

	if (m_Calc.GetVseTochki(m_vecPt))
	{
		m_paint.GetVecPt(this);
		m_paint.Invalidate();
	}

}


void CKurs1Dlg::OnBnClickedWindowTileVert()
{
	Risovat(m_A, 1);
}

int CKurs1Dlg::GetVecPt(std::vector<CPoint>& vec) const
{
	vec = m_vecPt;
	return 0;
}


void CKurs1Dlg::OnEnChangeEditA()
{
	CString strA;
	m_edA.GetWindowText(strA);

	m_A = _wtof(strA);
	OnBnClickedWindowTileVert();
}
