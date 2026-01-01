
// stopwatchView.h : interface of the CstopwatchView class
//

#pragma once


class CstopwatchView : public CView
{
protected: // create from serialization only
	CstopwatchView() noexcept;
	DECLARE_DYNCREATE(CstopwatchView)

// Attributes
public:
	CstopwatchDoc* GetDocument() const;

// Operations
public:

// Overrides
public:
	virtual void OnDraw(CDC* pDC);  // overridden to draw this view
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
protected:
	virtual BOOL OnPreparePrinting(CPrintInfo* pInfo);
	virtual void OnBeginPrinting(CDC* pDC, CPrintInfo* pInfo);
	virtual void OnEndPrinting(CDC* pDC, CPrintInfo* pInfo);

// Implementation
public:
	virtual ~CstopwatchView();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// Generated message map functions
protected:
	DECLARE_MESSAGE_MAP()
public:
	// 기록된 내용의 개수
	int m_nCount;
	CString m_strStopWatch;
	CString m_strRecord[30];

	BYTE byte[26] = { 0 };
	int m_nMinute;
	int m_nSecond;
	int m_nMSec;
	bool m_bStopWatchRun;


	int OnTimer();
	bool OnLButtonDown();
	int OnKeyDown();
};

#ifndef _DEBUG  // debug version in stopwatchView.cpp
inline CstopwatchDoc* CstopwatchView::GetDocument() const
   { return reinterpret_cast<CstopwatchDoc*>(m_pDocument); }
#endif

