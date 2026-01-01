
// ListControlDlg.h : header file
//

#pragma once


// CListControlDlg dialog
class CListControlDlg : public CDialogEx
{
// Construction
public:
	CListControlDlg(CWnd* pParent = nullptr);	// standard constructor

// Dialog Data
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_LISTCONTROL_DIALOG };
#endif

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV support


// Implementation
protected:
	HICON m_hIcon;

	// Generated message map functions
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	DECLARE_MESSAGE_MAP()
public:
	CListCtrl m_listStudent;
	CString m_strDept;
	CString m_strID;
	CString m_strName;
	CString m_strSelctItem;
};
