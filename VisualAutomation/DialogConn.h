#pragma once
#include "sscxservercommunicationcontrol.h"
#include "afxwin.h"
#include "PLCCom.h"


// CDialogConn dialog

class CDialogConn : public CDialogEx
{
	DECLARE_DYNAMIC(CDialogConn)


public:
	CDialogConn(CWnd* pParent = NULL);   // standard constructor
	virtual ~CDialogConn();

// Dialog Data
	enum { IDD = IDD_DIALOG_CONN };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support


	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnBnClickedOk();
	afx_msg void OnBnClickedCancel();
	CSSCXServerCommunicationControl m_Lite;
	afx_msg void OnBnClickedButtonLoad();
	CString GetSelectdPLC();
	CString GetSelectdPoint();
	CComboBox m_cmbPLC;
	CComboBox m_cmbPoint;
	void GetPLCs();
	void GetPoints();
	afx_msg void OnCbnSelchangeComboPlc();
	afx_msg void OnBnClickedButton1();
	afx_msg void OnBnClickedButton2();
	afx_msg void OnEnChangeInputVal();
};
