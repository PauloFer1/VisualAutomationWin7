#pragma once

class Constants
{
private:
	static bool instanceFlag;
	static Constants *single;
public:
	Constants();
	virtual ~Constants();
	static Constants* getInstance();
private:
	int blur;
	int cannyVal;
	int brightnessVal;
	int exposureVal;
	int constastVal;
	int zoomVal;
	bool hasThreshold;
	int typeThreshold;
	int thresholdVal;
	int objectWidth;
	int objectHeight;
	int calibrationVal;
	bool enableOut;
	bool dentroMaquina;
	bool foraMaquina;
	bool isConnectedMachine=false;
	int initialX;
	int initialY;
	int initialRot;
	int calibMM = 630;
public:
	void setBlur(int val);
	void setCanny(int val);
	void setBright(int val);
	void setExposure(int val);
	void setConstrast(int val);
	void setZoom(int val);
	void setHasThreshold(bool val);
	void setTypeThresh(int val);
	void setObjWidth(int val);
	void setObjHeight(int val);
	void setCalibVal(int val);
	void setThresholdVal(int val);
	void setInitialX(int x);
	void setInitialY(int y);
	void setInitialRot(int rot);
	void connectMachine();
	void disconnectMachine();
	void setCalibMM(int val);
	int getBlur();
	int getCanny();
	int getConstrast();
	int getZoom();
	int getExposure();
	int getObjHeight();
	int getObjWidth();
	int getTypeThresh();
	int getBright();
	bool getHasThreshold();
	int getCalibVal();
	int getThresholdVal();
	int actHorDist;
	int actVerDist;
	int getHasThresholdInt();
	int getCalibMM();
	bool checkConnection();
	int getInitialX();
	int getInitialY();
	int getInitialRot();
	bool isAuto = false;
};

