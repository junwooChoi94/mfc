
// stopwatch.h : main header file for the stopwatch application
//
#pragma once

#ifndef __AFXWIN_H__
	#error "include 'pch.h' before including this file for PCH"
#endif

#include "resource.h"       // main symbols


// CstopwatchApp:
// See stopwatch.cpp for the implementation of this class
//

class CstopwatchApp : public CWinApp
{
public:
	CstopwatchApp() noexcept;


// Overrides
public:
	virtual BOOL InitInstance();
	virtual int ExitInstance();

// Implementation
	afx_msg void OnAppAbout();
	DECLARE_MESSAGE_MAP()
};

extern CstopwatchApp theApp;
