#ifndef G_PLAYER_H
#define G_PLAYER_H

#include "GameObject.h"

class Keyboard;

class Player : public GameObject {
private:
	Keyboard* _kb;
public:
	Player(Component* comp);
	~Player();
	bool init()override;
	void end()override;
	void update()override;
	void draw()override;
};

#endif // !G_PLAYER_H
