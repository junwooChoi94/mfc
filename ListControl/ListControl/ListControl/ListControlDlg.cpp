
// ListControlDlg.cpp : implementation file
//

#include "pch.h"
#include "framework.h"
#include "ListControl.h"
#include "ListControlDlg.h"
#include "afxdialogex.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CAboutDlg dialog used for App About

class CAboutDlg : public CDialogEx
{
public:
	CAboutDlg();

// Dialog Data
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_ABOUTBOX };
#endif

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support

// Implementation
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


// CListControlDlg dialog



CListControlDlg::CListControlDlg(CWnd* pParent /*=nullptr*/)
	: CDialogEx(IDD_LISTCONTROL_DIALOG, pParent)
	, m_strDept(_T(""))
	, m_strID(_T(""))
	, m_strName(_T(""))
	, m_strSelctItem(_T(""))
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CListControlDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);

	DDX_Control(pDX, IDC_LIST_STUDENT, m_listStudent);
	DDX_Text(pDX, IDC_EDIT_DEPT, m_strDept);
	DDX_Text(pDX, IDC_EDIT_ID, m_strID);
	DDX_Text(pDX, IDC_EDIT_NAME, m_strName);
	DDX_Text(pDX, IDC_EDIT_SELECT_ITEM, m_strSelctItem);
}

BEGIN_MESSAGE_MAP(CListControlDlg, CDialogEx)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
END_MESSAGE_MAP()


// CListControlDlg message handlers

BOOL CListControlDlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// Add "About..." menu item to system menu.

	// IDM_ABOUTBOX must be in the system command range.
	ASSERT((IDM_ABOUTBOX & 0xFFF0) == IDM_ABOUTBOX);
	ASSERT(IDM_ABOUTBOX < 0xF000);

	CMenu* pSysMenu = GetSystemMenu(FALSE);
	if (pSysMenu != nullptr)
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

	// Set the icon for this dialog.  The framework does this automatically
	//  when the application's main window is not a dialog
	SetIcon(m_hIcon, TRUE);			// Set big icon
	SetIcon(m_hIcon, FALSE);		// Set small icon

	// TODO: Add extra initialization here
	m_listStudent.InsertColumn(0, _T("순번"), LVCFMT_CENTER, 60);
	m_listStudent.InsertColumn(1, _T("학과"), LVCFMT_CENTER, 190);
	m_listStudent.InsertColumn(2, _T("학번"), LVCFMT_CENTER, 150);
	m_listStudent.InsertColumn(3, _T("이름"), LVCFMT_CENTER, 150);

	// list Control 의 선택 시 전체 행이 선택되게 하고 그리드 라인이 표시되게 스타일 변경
	m_listStudent.SetExtendedStyle(m_listStudent.GetExtendedStyle() | LVS_EX_FULLROWSELECT | LVS_EX_GRIDLINES);

	// list control  스타일 변경을 위해 콤보 상자의 초기 선택값 지정
	((CComboBox*)GetDlgItem(IDC_COMBO_STYLE))->SetCurSel(0);

	//수정 , 삭제 버튼을 비활성화
	((CButton*)GetDlgItem(IDC_BUTTON_MODIFY))->EnableWindow(FALSE);
	((CButton*)GetDlgItem(IDC_BUTTON_DELETE))->EnableWindow(FALSE);

	return TRUE;  // return TRUE  unless you set the focus to a control
}

void CListControlDlg::OnSysCommand(UINT nID, LPARAM lParam)
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

// If you add a minimize button to your dialog, you will need the code below
//  to draw the icon.  For MFC applications using the document/view model,
//  this is automatically done for you by the framework.

void CListControlDlg::OnPaint()
{
	if (IsIconic())
	{
		CPaintDC dc(this); // device context for painting

		SendMessage(WM_ICONERASEBKGND, reinterpret_cast<WPARAM>(dc.GetSafeHdc()), 0);

		// Center icon in client rectangle
		int cxIcon = GetSystemMetrics(SM_CXICON);
		int cyIcon = GetSystemMetrics(SM_CYICON);
		CRect rect;
		GetClientRect(&rect);
		int x = (rect.Width() - cxIcon + 1) / 2;
		int y = (rect.Height() - cyIcon + 1) / 2;

		// Draw the icon
		dc.DrawIcon(x, y, m_hIcon);
	}
	else
	{
		CDialogEx::OnPaint();
	}
}

// The system calls this function to obtain the cursor to display while the user drags
//  the minimized window.
HCURSOR CListControlDlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}

