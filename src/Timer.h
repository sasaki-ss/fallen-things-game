#ifndef G_TIMER_H
#define G_TIMER_H

#include "Object.h"

class Timer final : public Object {
private:
	int _timeLeft;		//�c�莞��
	int _lastTime;		//�O�t���[���̎���
public:
	Timer();
	~Timer(){}
	bool init()override;
	void end()override;
	void update()override;

	int getTimeLeft();
};

#endif // !G_TIMER_H
