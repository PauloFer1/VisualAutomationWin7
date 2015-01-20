#pragma once
#include "sscxservercommunicationcontrol.h"

class PLCCom
{
private:
	static bool instanceFlag;
	static PLCCom *single;
	CString PLCName;
public:
	PLCCom();
	virtual ~PLCCom();
	static PLCCom* getInstance();
public:
	CSSCXServerCommunicationControl* control;
	void setComControl(CSSCXServerCommunicationControl *control);
	void setPLC(CString plcName);
	COleVariant getPLCs();
	COleVariant getPoints();
	CString processOutput(COleVariant varData);
	COleVariant getPointValue(CString point);
	COleVariant processInput(CString value);
	int setPointValue(CString point, CString value);
};

