// DialogVision.cpp : implementation file
//

#include "stdafx.h"
#include "VisualAutomation.h"
#include "DialogVision.h"
#include "afxdialogex.h"
#include <thread>


// CDialogVision dialog

IMPLEMENT_DYNAMIC(CDialogVision, CDialogEx)

CDialogVision::CDialogVision(CWnd* pParent /*=NULL*/)
	: CDialogEx(CDialogVision::IDD, pParent)
{
}
CDialogVision::~CDialogVision()
{
}
void CDialogVision::initVision()
{
	if (Camera::getInstance()->hasCamera == false)
	{
		Camera::getInstance()->initCamera();
	}
	Detection::getInstance()->imgWnd = &imageViewer;
	__hook(&Detection::enableOut, Detection::getInstance(), &CDialogVision::setEnable);
}
void CDialogVision::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_VALUE_X, labelValueX);
	labelValueX.SetWindowTextW(_T("45"));
	DDX_Control(pDX, IDC_VALUE_Y, labelValueY);
	DDX_Control(pDX, IDC_VALUE_ROT, labelValueRot);
	DDX_Control(pDX, IDC_VISION_IMG, imageViewer);
	DDX_Control(pDX, IDC_STATUS_TEXT, statusText);

	CFont m_Font1;
	LOGFONT logFont;
	//m_Font1.CreatePointFont(150, _T("Arial Bold"));
	m_Font1.CreateFontW(300, 300, 0, 0, FW_BOLD, FALSE, FALSE, 0, ANSI_CHARSET, OUT_DEFAULT_PRECIS, CLIP_DEFAULT_PRECIS, DEFAULT_QUALITY, DEFAULT_PITCH, _T("Arial Bold"));
	statusText.SetFont(&m_Font1); 
}


BEGIN_MESSAGE_MAP(CDialogVision, CDialogEx)
	ON_BN_CLICKED(IDC_BUTTON1, &CDialogVision::OnBnClickedButton1)
	ON_BN_CLICKED(IDCANCEL, &CDialogVision::OnBnClickedCancel)
	ON_BN_CLICKED(IDC_BUTTON2, &CDialogVision::OnBnClickedButton2)
	ON_BN_CLICKED(IDC_BUTTON3, &CDialogVision::OnBnClickedButton3)
END_MESSAGE_MAP()


// CDialogVision message handlers


void CDialogVision::OnBnClickedButton1()
{
	
	Point2i offset= Detection::getInstance()->getOffset();	CString str;
	CString val;
	val.Format(_T("%d"), (Constants::getInstance()->getInitialX() + offset.x));
	str.Format(_T("%d mm"), (Constants::getInstance()->getInitialY() + offset.x));
	labelValueX.SetWindowTextW(str);
	PLCCom::getInstance()->setPointValue(_T("EscPosX"),val);
	str.Format(_T("%d mm"), offset.y);
	val.Format(_T("%d"), offset.y);
	labelValueY.SetWindowTextW(str);
	PLCCom::getInstance()->setPointValue(_T("EscPosY"), val);
//	PLCCom::getInstance()->setPointValue(_T("robotEnableOut"), _T("true"));
	val.Format(_T("%d"), Constants::getInstance()->getInitialRot());
	PLCCom::getInstance()->setPointValue(_T("EscRot"), val);
	PLCCom::getInstance()->setPointValue(_T("VisaoOk"), _T("false"));
}


void CDialogVision::OnBnClickedCancel()
{
	// TODO: Add your control notification handler code here
	Detection::getInstance()->destroyWnd();
	Sleep(50);
	CDialogEx::OnCancel();
}
void CDialogVision::setEnable(int i){
	statusText.SetWindowTextW(_T("ENABLE OUT"));
}


void CDialogVision::OnBnClickedButton2()
{
	Detection::getInstance()->enableRead();
	statusText.SetWindowTextW(_T("ENABLE READ"));
}

void __cdecl CDialogVision::waitForRobot(void * parg)
{
	while (Constants::getInstance()->isAuto)
	{
		bool maq = PLCCom::getInstance()->getPointValue(_T("robotDentroMaq"));

		if (maq)
			break;
		Sleep(500);
	}
	_endthread;
}
void CDialogVision::initThread()
{
	while (Constants::getInstance()->isAuto)
	{
		bool maq = PLCCom::getInstance()->getPointValue(_T("robotDentroMaq"));
		if (maq)
			break;
		Sleep(500);
	}
}

void CDialogVision::OnBnClickedButton3()
{
	// TODO: Add your control notification handler code here
	Constants::getInstance()->isAuto = !Constants::getInstance()->isAuto;

//	_beginthread(&CDialogVision::waitForRobot, 0, NULL);

	if (Constants::getInstance()->isAuto == true)
	{
		thread wait(&CDialogVision::initThread, this);

		wait.join();
	}
}
