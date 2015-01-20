#include "stdafx.h"
#include "PLCCom.h"


PLCCom::PLCCom()
{
}


PLCCom::~PLCCom()
{
	instanceFlag = false;
}

bool PLCCom::instanceFlag = false;
PLCCom* PLCCom::single = NULL;

PLCCom* PLCCom::getInstance()
{
	if (!instanceFlag)
	{
		single = new PLCCom();
		instanceFlag = true;
		return single;
	}
	else
	{
		return single;
	}
}

void PLCCom::setComControl(CSSCXServerCommunicationControl *control)
{
	this->control = control;
}
void PLCCom::setPLC(CString plcName)
{
	this->PLCName = plcName;
}
COleVariant PLCCom::getPLCs()
{
	long lbound, ubound, nElements;
	COleVariant varData;
	varData = control->GetListPLCs();
	return(varData);
}
COleVariant PLCCom::getPoints()
{
	long lbound, ubound, nElements;
	COleVariant varData;
	varData = control->GetListPoints(this->PLCName);
	return(varData);
}
CString PLCCom::processOutput(COleVariant varData)
{
	COleVariant varTemp;
	CString strData;

	if (varData.vt == VT_BOOL){
		varTemp.ChangeType(VT_BSTR, &varData);
		strData = varTemp.bstrVal;
		if (strData != "0")
			strData = "true";
		else
			strData = "false";
	}
	else{
		varTemp.ChangeType(VT_BSTR, &varData);
		strData = varTemp.bstrVal;
	}

	return(strData);
}
COleVariant PLCCom::getPointValue(CString point)
{
	COleVariant varData;
	varData = this->control->GetValue(point);

	return(varData);
}
COleVariant PLCCom::processInput(CString value)
{
	value.MakeUpper();
	COleVariant var(value);

	if (value.Find(_T(".")) != -1){
		var.ChangeType(VT_R8);
	}
	else if (value == "TRUE"){
		var.vt = VT_BOOL;
		var = (short)1;
	}
	else if (value == "FALSE"){
		var.vt = VT_BOOL;
		var = (short)0;
	}
	else{
		var.ChangeType(VT_I4);
	}
	return(var);
}
int PLCCom::setPointValue(CString point, CString value)
{
	COleVariant var = this->processInput(value);
	this->control->SetValue(point, var);

	return(1);
}