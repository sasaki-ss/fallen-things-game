#ifndef G_DROPITEM_H
#define G_DROPITEM_H

#include "GameObject.h"

class DropItem final : public GameObject {
private:

public:
	DropItem(Vector2 pos);
	~DropItem();
	bool init();
	void end();
	void update();
	void draw();
};

#endif // !G_DROPITEM_H
