
// stopwatchView.cpp : implementation of the CstopwatchView class
//

#include "pch.h"
#include "framework.h"
// SHARED_HANDLERS can be defined in an ATL project implementing preview, thumbnail
// and search filter handlers and allows sharing of document code with that project.
#ifndef SHARED_HANDLERS
#include "stopwatch.h"
#endif

#include "stopwatchDoc.h"
#include "stopwatchView.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CstopwatchView

IMPLEMENT_DYNCREATE(CstopwatchView, CView)

BEGIN_MESSAGE_MAP(CstopwatchView, CView)
	// Standard printing commands
	ON_COMMAND(ID_FILE_PRINT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, &CView::OnFilePrintPreview)
END_MESSAGE_MAP()

// CstopwatchView construction/destruction

CstopwatchView::CstopwatchView() noexcept
{
	
	m_strStopWatch = _T("00:00.00");
	m_nCount = 0;
	m_nMinute = 0;
	m_nSecond = 0;
	m_nMSec = 0;
	m_bStopWatchRun = false;


}

CstopwatchView::~CstopwatchView()
{
}

BOOL CstopwatchView::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: Modify the Window class or styles here by modifying
	//  the CREATESTRUCT cs

	return CView::PreCreateWindow(cs);
}

// CstopwatchView drawing

void CstopwatchView::OnDraw(CDC* /*pDC*/)
{
	CstopwatchDoc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	

	if (!pDoc)
		return;

	// TODO: add draw code for native data here
}


// CstopwatchView printing

BOOL CstopwatchView::OnPreparePrinting(CPrintInfo* pInfo)
{
	// default preparation
	return DoPreparePrinting(pInfo);
}

void CstopwatchView::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: add extra initialization before printing
}

void CstopwatchView::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: add cleanup after printing
}


// CstopwatchView diagnostics

#ifdef _DEBUG
void CstopwatchView::AssertValid() const
{
	CView::AssertValid();
}

void CstopwatchView::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CstopwatchDoc* CstopwatchView::GetDocument() const // non-debug version is inline
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CstopwatchDoc)));
	return (CstopwatchDoc*)m_pDocument;
}
#endif //_DEBUG


// CstopwatchView message handlers


int CstopwatchView::OnTimer()
{
	// TODO: Add your implementation code here.
	m_nMinute += 1;
	m_nSecond += 1;
	m_nMSec += 1;
	m_strStopWatch.Format(_T("%02d: %02d. %02d"), m_nMinute, m_nSecond, m_nMSec);
	Invalidate();
	return 0;
}


bool CstopwatchView::OnLButtonDown()
{
	
	// TODO: Add your implementation code here.
	if (m_bStopWatchRun== false) {
		SetTimer(0, 10, NULL);
		m_bStopWatchRun = true;
		return false;
	}
	else {
		KillTimer(0);
		m_bStopWatchRun = false;
		return true;
	}
	
	//return false;
}



int CstopwatchView::OnKeyDown()
{
	CString nChar;
	// TODO: Add your implementation code here.

	if (m_bStopWatchRun) {

		if (nChar == VK_SPACE) {
			m_strRecord = [];
			m_nCount += 1;
		}
		if (m_nCount == 30) {
			memset(m_strRecord, 0, sizeof(m_strRecord));
			m_nCount = 0;
		}
	}
	Invalidate();
	return 0;
}
