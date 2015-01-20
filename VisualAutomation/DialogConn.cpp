// DialogConn.cpp : implementation file
//

#include "stdafx.h"
#include "VisualAutomation.h"
#include "DialogConn.h"
#include "afxdialogex.h"


// CDialogConn dialog

IMPLEMENT_DYNAMIC(CDialogConn, CDialogEx)

CDialogConn::CDialogConn(CWnd* pParent /*=NULL*/)
	: CDialogEx(CDialogConn::IDD, pParent)
{

}

CDialogConn::~CDialogConn()
{
}

void CDialogConn::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_CXSERVERCOMMUNICATIONCONTROL1, m_Lite);
	DDX_Control(pDX, IDC_COMBO_PLC, m_cmbPLC);
	DDX_Control(pDX, IDC_COMBO_POINT, m_cmbPoint);

	PLCCom::getInstance()->setComControl(&m_Lite);
}


BEGIN_MESSAGE_MAP(CDialogConn, CDialogEx)
	ON_BN_CLICKED(IDOK, &CDialogConn::OnBnClickedOk)
	ON_BN_CLICKED(IDCANCEL, &CDialogConn::OnBnClickedCancel)
	ON_BN_CLICKED(IDC_BUTTON_LOAD, &CDialogConn::OnBnClickedButtonLoad)
	ON_CBN_SELCHANGE(IDC_COMBO_PLC, &CDialogConn::OnCbnSelchangeComboPlc)
	ON_BN_CLICKED(IDC_BUTTON1, &CDialogConn::OnBnClickedButton1)
	ON_BN_CLICKED(IDC_BUTTON2, &CDialogConn::OnBnClickedButton2)
END_MESSAGE_MAP()


// CDialogConn message handlers


void CDialogConn::OnBnClickedOk()
{
	// TODO: Add your control notification handler code here
	CDialogEx::OnOK();
}


void CDialogConn::OnBnClickedCancel()
{
	// TODO: Add your control notification handler code here
	CDialogEx::OnCancel();
}


void CDialogConn::OnBnClickedButtonLoad()
{
	CFileDialog dlgFileSelect(TRUE, _T("CDM"), NULL, OFN_HIDEREADONLY | OFN_OVERWRITEPROMPT, _T("CDM Files(*.cdm)|*.CDM||"), NULL);
	if (dlgFileSelect.DoModal() == IDOK)
	{
		m_Lite.SetProjectName(dlgFileSelect.GetPathName().GetBuffer(0));
		GetPLCs();
	}
}
CString CDialogConn::GetSelectdPLC(){
	CString csSelectedPLC;
	m_cmbPLC.GetLBText(m_cmbPLC.GetCurSel(), csSelectedPLC);
	return(csSelectedPLC);
}
CString CDialogConn::GetSelectdPoint(){
	CString csSelectedPoint;
	m_cmbPoint.GetLBText(m_cmbPoint.GetCurSel(), csSelectedPoint);
	return(csSelectedPoint);
}
void CDialogConn::GetPLCs(){
	long lbound, ubound, nElements;
	COleVariant varData;
	//varData = m_Lite.GetListPLCs();
	//SAFEARRAY* pArray1 = varData.parray;manda em                                                                                                                    
	PLCCom::getInstance()->setComControl(&m_Lite);
	varData = PLCCom::getInstance()->getPLCs();
	SAFEARRAY* pArray = varData.parray;

	if (pArray)
	{
		
		SafeArrayGetLBound(pArray, 1, &lbound);
		SafeArrayGetUBound(pArray, 1, &ubound);
		nElements = ubound - lbound + 1;
		m_cmbPLC.ResetContent();
		int count = 0;

		for (; lbound <= ubound; lbound++)
		{
			VARIANT varPLCsNames;
			VariantInit(&varPLCsNames);
			if (SafeArrayGetElement(pArray, &lbound, &varPLCsNames) == S_OK)
			{
				m_cmbPLC.AddString(varPLCsNames.bstrVal);
				VariantClear(&varPLCsNames);
			}
			count++;
		}
		
		m_cmbPLC.SetCurSel(0);
	}
}
void CDialogConn::GetPoints(){
	long lbound, ubound, nElements;
	COleVariant varData;

	PLCCom::getInstance()->setPLC(GetSelectdPLC().GetBuffer(0));

	varData = PLCCom::getInstance()->getPoints();
	SAFEARRAY* pArray = varData.parray;

	if (pArray)
	{

		SafeArrayGetLBound(pArray, 1, &lbound);
		SafeArrayGetUBound(pArray, 1, &ubound);
		nElements = ubound - lbound + 1;
		m_cmbPLC.ResetContent();
		int count = 0;

		for (; lbound <= ubound; lbound++)
		{
			VARIANT varPointNames;
			VariantInit(&varPointNames);
			if (SafeArrayGetElement(pArray, &lbound, &varPointNames) == S_OK)
			{
				m_cmbPoint.AddString(varPointNames.bstrVal);
				VariantClear(&varPointNames);
			}
			count++;
		}

		m_cmbPLC.SetCurSel(0);
	}
}

void CDialogConn::OnCbnSelchangeComboPlc()
{
	GetPoints();
}


void CDialogConn::OnBnClickedButton1()
{
	COleVariant varData;
	varData = PLCCom::getInstance()->getPointValue(GetSelectdPoint());
	CString val = PLCCom::getInstance()->processOutput(varData);
	SetDlgItemText(IDC_POINT_VALU,val);
}


void CDialogConn::OnBnClickedButton2()
{
	CString value;
	GetDlgItemText(IDC_INPUT_VAL, value);
	PLCCom::getInstance()->setPointValue(this->GetSelectdPoint(), value);
}
