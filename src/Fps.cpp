#include "Fps.h"

#include <DxLib.h>

Fps::Fps() :
	_startTime(),
	_avgStartTime(),
	_cnt(),
	_fps(),
	_avgFps(),
	_isWait(false) {

}

void Fps::init() {
	_startTime = GetNowHiPerformanceCount();
	_cnt = 1;
	_isWait = false;
	_fps = 60;
	_avgFps = 60.0;
}

void Fps::update() {
	_startTime = GetNowHiPerformanceCount();
}

void Fps::wait() {
	long long nowTime = GetNowHiPerformanceCount();
	double difTime = ((double)nowTime - _startTime) / 1000.0;
	printf("%f\n", difTime);
	Sleep((1000.0 / _fps) - difTime);
}