#ifndef G_TIMER_H
#define G_TIMER_H

#include "Object.h"

class Timer final : public Object {
private:
	int _timeLeft;		//残り時間
	int _lastTime;		//前フレームの時間
public:
	Timer();
	~Timer(){}
	bool init()override;
	void end()override;
	void update()override;

	int getTimeLeft();
};

#endif // !G_TIMER_H
