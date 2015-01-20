#if !defined(AFX_SSCXSERVERCOMMUNICATIONCONTROL1_H__A603279C_C664_4BAB_BD4D_7C2DD2DCE288__INCLUDED_)
#define AFX_SSCXSERVERCOMMUNICATIONCONTROL1_H__A603279C_C664_4BAB_BD4D_7C2DD2DCE288__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// Machine generated IDispatch wrapper class(es) created by Microsoft Visual C++

// NOTE: Do not modify the contents of this file.  If this class is regenerated by
//  Microsoft Visual C++, your modifications will be overwritten.

/////////////////////////////////////////////////////////////////////////////
// CSSCXServerCommunicationControl wrapper class

class CSSCXServerCommunicationControl : public CWnd
{
protected:
	DECLARE_DYNCREATE(CSSCXServerCommunicationControl)
public:
	CLSID const& GetClsid()
	{
		static CLSID const clsid
			= { 0x28e12b23, 0xa3da, 0x11d3, { 0xbb, 0x81, 0x0, 0x10, 0x5a, 0x9b, 0x96, 0xf5 } };
		return clsid;
	}
	virtual BOOL Create(LPCTSTR lpszClassName,
		LPCTSTR lpszWindowName, DWORD dwStyle,
		const RECT& rect,
		CWnd* pParentWnd, UINT nID,
		CCreateContext* pContext = NULL)
	{
		return CreateControl(GetClsid(), lpszWindowName, dwStyle, rect, pParentWnd, nID);
	}

	BOOL Create(LPCTSTR lpszWindowName, DWORD dwStyle,
		const RECT& rect, CWnd* pParentWnd, UINT nID,
		CFile* pPersist = NULL, BOOL bStorage = FALSE,
		BSTR bstrLicKey = NULL)
	{
		return CreateControl(GetClsid(), lpszWindowName, dwStyle, rect, pParentWnd, nID,
			pPersist, bStorage, bstrLicKey);
	}

	// Attributes
public:

	// Operations
public:
	void AboutBox();
	CString GetProjectName();
	void SetProjectName(LPCTSTR lpszNewValue);
	void SetDefaultPLC(LPCTSTR PLC);
	VARIANT GetValue(LPCTSTR Point);
	void SetValue(LPCTSTR Point, const VARIANT& newValue);
	VARIANT GetAr(const VARIANT& index);
	void SetAr(const VARIANT& index, const VARIANT& newValue);
	VARIANT GetDm(short index);
	void SetDm(short index, const VARIANT& newValue);
	VARIANT GetHr(const VARIANT& index);
	void SetHr(const VARIANT& index, const VARIANT& newValue);
	VARIANT GetIr(const VARIANT& index);
	void SetIr(const VARIANT& index, const VARIANT& newValue);
	VARIANT GetLr(short index);
	void SetLr(short index, const VARIANT& newValue);
	VARIANT GetSr(short index);
	void SetSr(short index, const VARIANT& newValue);
	VARIANT GetTc(short index);
	void SetTc(short index, const VARIANT& newValue);
	VARIANT GetEm(short bank, short index);
	void SetEm(short bank, short index, const VARIANT& newValue);
	VARIANT GetA(short index);
	void SetA(short index, const VARIANT& newValue);
	VARIANT GetC(short index);
	void SetC(short index, const VARIANT& newValue);
	VARIANT GetCio(const VARIANT& index);
	void SetCio(const VARIANT& index, const VARIANT& newValue);
	VARIANT GetD(short index);
	void SetD(short index, const VARIANT& newValue);
	VARIANT GetDr(short index);
	void SetDr(short index, const VARIANT& newValue);
	VARIANT GetG(short index);
	void SetG(short index, const VARIANT& newValue);
	VARIANT GetSt(short index);
	void SetSt(short index, const VARIANT& newValue);
	VARIANT GetT(short index);
	void SetT(short index, const VARIANT& newValue);
	VARIANT GetE(short bank, short index);
	void SetE(short bank, short index, const VARIANT& newValue);
	VARIANT GetTk(short index);
	VARIANT GetH(const VARIANT& index);
	void SetH(const VARIANT& index, const VARIANT& newValue);
	VARIANT GetW(const VARIANT& index);
	void SetW(const VARIANT& index, const VARIANT& newValue);
	void OpenPLC(LPCTSTR PLC);
	void ClosePLC(LPCTSTR PLC);
	VARIANT GetReadArea(LPCTSTR Area, long Size, long RetType, long Wait);
	void WriteArea(LPCTSTR Area, long Size, const VARIANT& newVal, long Wait);
	VARIANT GetListPoints(LPCTSTR PLC);
	VARIANT GetListPLCs();
	void GetData(LPCTSTR PLC, LPCTSTR Point, double UpdateRate, long Update);
	void StopData(LPCTSTR PLC, LPCTSTR Point);
	BOOL GetDisplayErrors();
	void SetDisplayErrors(BOOL bNewValue);
	BOOL GetIsPointValid(LPCTSTR Point, LPCTSTR PLC);
	BOOL Active(LPCTSTR strPLCDeviceName);
	VARIANT RawFINS(const VARIANT& variantMessage, LPCTSTR PLC, long varReturnType, long Unit, BOOL ignoreError);
	VARIANT TCGetStatus(LPCTSTR bstrDeviceName);
	void TCRemoteLocal(LPCTSTR bstrDeviceName, long nCommand);
	BOOL IsBadQuality(LPCTSTR PLC, LPCTSTR Point);
	DATE GetClockRead(LPCTSTR PLC);
	void ClockWrite(LPCTSTR PLC, DATE Date);
	VARIANT GetValues(LPCTSTR Point);
	void SetValues(LPCTSTR Point, const VARIANT& newValue);
	VARIANT GetRunMode(LPCTSTR PLC);
	void SetRunMode(LPCTSTR PLC, const VARIANT& newValue);
	VARIANT GetTypeName(LPCTSTR PLC);
	void Help();
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_SSCXSERVERCOMMUNICATIONCONTROL1_H__A603279C_C664_4BAB_BD4D_7C2DD2DCE288__INCLUDED_)
