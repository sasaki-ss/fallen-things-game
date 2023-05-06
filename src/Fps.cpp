#include "Fps.h"

#include <DxLib.h>
#include "Define.h"

Fps::Fps() :
	_startTime(),
	_fps() {

}

void Fps::init() {
	_startTime = GetNowHiPerformanceCount();
	_fps = 60;
}
void Fps::update() {
	_startTime = GetNowHiPerformanceCount();
}

void Fps::wait() {
	long long nowTime = GetNowHiPerformanceCount();
	double difTime = ((double)nowTime - _startTime) / FPS_STDTIME;
	Sleep(static_cast<DWORD>((FPS_STDTIME / _fps) - difTime));
}