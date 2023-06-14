#include "Timer.h"

#include <DxLib.h>

Timer::Timer():
	Object(),
	_timeLeft(0),
	_lastTime(0) {

}

bool Timer::init() {
	_timeLeft = 20 * 1000;
	_lastTime = GetNowCount();

	return true;
}
void Timer::end() {

}

void Timer::update() {
	int currentTime = GetNowCount();
	_timeLeft -= (currentTime - _lastTime);
	_lastTime = GetNowCount();
}

int Timer::getTimeLeft() {
	if (_timeLeft <= 0) {
		return 0;
	}

	return _timeLeft / 1000 + 1;
}