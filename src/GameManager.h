#ifndef G_GAMEMANAGER_H
#define G_GAMEMANAGER_H

#include "Object.h"

class Timer;

class GameManager final :public Object {
private:
	Timer* _timer;
public:
	GameManager(Component* comp);
	bool init();
	void end();
	void update();
};

#endif // !G_GAMEMANAGER_H
