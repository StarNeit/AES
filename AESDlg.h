// AESDlg.h : header file
//

#if !defined(AFX_AESDLG_H__878F219C_6CE2_4549_B8DC_CB9D22DD53FE__INCLUDED_)
#define AFX_AESDLG_H__878F219C_6CE2_4549_B8DC_CB9D22DD53FE__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

/////////////////////////////////////////////////////////////////////////////
// CAESDlg dialog

class CAESDlg : public CDialog
{
// Construction
public:
	CAESDlg(CWnd* pParent = NULL);	// standard constructor

// Dialog Data
	//{{AFX_DATA(CAESDlg)
	enum { IDD = IDD_AES_DIALOG };
	CEdit	m_ed2;
	CEdit	m_ed1;
	//}}AFX_DATA

	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CAESDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:
	HICON m_hIcon;

	// Generated message map functions
	//{{AFX_MSG(CAESDlg)
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	afx_msg void OnButton1();
	afx_msg void OnButton2();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_AESDLG_H__878F219C_6CE2_4549_B8DC_CB9D22DD53FE__INCLUDED_)
