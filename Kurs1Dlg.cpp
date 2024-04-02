
// Kurs1Dlg.cpp : файл реализации
//

#include "stdafx.h"
#include "Kurs1.h"
#include "Kurs1Dlg.h"
#include "afxdialogex.h"
#include "resource.h"
#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// Диалоговое окно CAboutDlg используется для описания сведений о приложении

class CAboutDlg : public CDialogEx
{
public:
	CAboutDlg();

// Данные диалогового окна
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_ABOUTBOX };
#endif

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // поддержка DDX/DDV

// Реализация
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


// диалоговое окно CKurs1Dlg



CKurs1Dlg::CKurs1Dlg(CWnd* pParent /*=NULL*/)
	: CDialogEx(IDD_KURS1_DIALOG, pParent)
	,m_A(0)
	,m_Fi(0)
	, m_ScShift()
	, m_bInited(false)
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CKurs1Dlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_EDIT_A, m_edA);
	DDX_Control(pDX, IDC_EDIT_FI, m_EdFi);
	DDX_Control(pDX, IDC_SLIDER_SCALE, m_SliderScale);
}

BEGIN_MESSAGE_MAP(CKurs1Dlg, CDialogEx)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_BN_CLICKED(IDOK, &CKurs1Dlg::OnBnClickedOk)
	ON_BN_CLICKED(ID_WINDOW_TILE_VERT, &CKurs1Dlg::OnBnClickedWindowTileVert)
	ON_EN_CHANGE(IDC_EDIT_A, &CKurs1Dlg::OnEnChangeEditA)
	ON_EN_CHANGE(IDC_EDIT_FI, &CKurs1Dlg::OnEnChangeEditFi)
	ON_BN_CLICKED(IDC_BUT_SCUP, &CKurs1Dlg::OnBnClickedButScup)
	ON_BN_CLICKED(IDC_BUT_SCDN, &CKurs1Dlg::OnBnClickedButScdn)
	//ON_BN_CLICKED(IDC_BTN_SC_UP, &CKurs1Dlg::OnBnClickedBtnScUp)
	ON_NOTIFY(NM_CUSTOMDRAW, IDC_SLIDER_SCALE, &CKurs1Dlg::OnNMCustomdrawSliderScale)
	ON_NOTIFY(TRBN_THUMBPOSCHANGING, IDC_SLIDER_SCALE, &CKurs1Dlg::OnTRBNThumbPosChangingSliderScale)
	ON_NOTIFY(NM_RELEASEDCAPTURE, IDC_SLIDER_SCALE, &CKurs1Dlg::OnNMReleasedcaptureSliderScale)
END_MESSAGE_MAP()


// обработчики сообщений CKurs1Dlg

BOOL CKurs1Dlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// Добавление пункта "О программе..." в системное меню.

	// IDM_ABOUTBOX должен быть в пределах системной команды.
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

	// Задает значок для этого диалогового окна.  Среда делает это автоматически,
	//  если главное окно приложения не является диалоговым
	SetIcon(m_hIcon, TRUE);			// Крупный значок
	SetIcon(m_hIcon, FALSE);		// Мелкий значок

	// TODO: добавьте дополнительную инициализацию
	m_paint.SubclassDlgItem(IDC_GRAPH, this);

	m_Calc.Scale(m_ScShift.ScaleX);
	CRect rc;
	m_paint.GetClientRect(&rc);
	m_ScShift.ShiftX = rc.CenterPoint().x;
	m_ScShift.ShiftY = rc.CenterPoint().y;
	m_Calc.Shift(CPoint(m_ScShift.ShiftX, m_ScShift.ShiftY));
	m_SliderScale.SetRange(1, 10, TRUE);
	m_SliderScale.SetPos(10);

	m_bInited = true;
	return TRUE;  // возврат значения TRUE, если фокус не передан элементу управления
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

// При добавлении кнопки свертывания в диалоговое окно нужно воспользоваться приведенным ниже кодом,
//  чтобы нарисовать значок.  Для приложений MFC, использующих модель документов или представлений,
//  это автоматически выполняется рабочей областью.

void CKurs1Dlg::OnPaint()
{
	if (IsIconic())
	{
		CPaintDC dc(this); // контекст устройства для рисования

		SendMessage(WM_ICONERASEBKGND, reinterpret_cast<WPARAM>(dc.GetSafeHdc()), 0);

		// Выравнивание значка по центру клиентского прямоугольника
		int cxIcon = GetSystemMetrics(SM_CXICON);
		int cyIcon = GetSystemMetrics(SM_CYICON);
		CRect rect;
		GetClientRect(&rect);
		int x = (rect.Width() - cxIcon + 1) / 2;
		int y = (rect.Height() - cyIcon + 1) / 2;

		// Нарисуйте значок
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

// Система вызывает эту функцию для получения отображения курсора при перемещении
//  свернутого окна.
HCURSOR CKurs1Dlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}



void CKurs1Dlg::OnBnClickedOk()
{
	SetWindowText(L"Привет курсовая");

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
	Risovat(m_A, m_Fi);
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


void CKurs1Dlg::ScaleShift()
{
	m_Calc.Scale(m_ScShift.ScaleX);
	m_Calc.Shift(CPoint(m_ScShift.ShiftX, m_ScShift.ShiftY));
}

void CKurs1Dlg::OnEnChangeEditFi()
{
	CString strA;
	m_EdFi.GetWindowText(strA);

	m_Fi = _wtof(strA);
	OnBnClickedWindowTileVert();
}


void CKurs1Dlg::OnBnClickedButScup()
{
	/*m_ScShift.ScaleX *= 1.25;
	m_ScShift.ScaleY = m_ScShift.ScaleX;
	ScaleShift();
	OnBnClickedWindowTileVert();*/
	m_SliderScale.SetPos(m_SliderScale.GetPos() - 1);
	LRESULT res;
	OnNMReleasedcaptureSliderScale(nullptr, &res);
}


void CKurs1Dlg::OnBnClickedButScdn()
{
	/*m_ScShift.ScaleX /= 1.25;
	m_ScShift.ScaleY = m_ScShift.ScaleX;
	ScaleShift();
	OnBnClickedWindowTileVert();*/
	m_SliderScale.SetPos(m_SliderScale.GetPos() + 1);
	LRESULT res;
	OnNMReleasedcaptureSliderScale(nullptr, &res);
}




void CKurs1Dlg::OnNMCustomdrawSliderScale(NMHDR *pNMHDR, LRESULT *pResult)
{
	LPNMCUSTOMDRAW pNMCD = reinterpret_cast<LPNMCUSTOMDRAW>(pNMHDR);
	// TODO: Add your control notification handler code here
	*pResult = 0;
}


void CKurs1Dlg::OnTRBNThumbPosChangingSliderScale(NMHDR *pNMHDR, LRESULT *pResult)
{
	// This feature requires Windows Vista or greater.
	// The symbol _WIN32_WINNT must be >= 0x0600.
	NMTRBTHUMBPOSCHANGING *pNMTPC = reinterpret_cast<NMTRBTHUMBPOSCHANGING *>(pNMHDR);
	int nPos = m_SliderScale.GetPos()-10;
	m_ScShift.ScaleX = nPos ? 1.25 * nPos : 1;
	*pResult = 0;
}


void CKurs1Dlg::OnNMReleasedcaptureSliderScale(NMHDR *pNMHDR, LRESULT *pResult)
{
	// TODO: Add your control notification handler code here
	if (!m_bInited)
		return;
	int nPos = 10 - m_SliderScale.GetPos();
	m_ScShift.ScaleX = nPos ? 1.25 * nPos : 1;
	ScaleShift();
	OnBnClickedWindowTileVert();
	*pResult = 0;
}
