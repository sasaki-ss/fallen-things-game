#ifndef G_ITEM_H
#define G_ITEM_H

#include "GameObject.h"

class Item : public GameObject {
private:

public:
	Item(){}
	Item(Vector2 pos){}
	virtual ~Item() {}
	virtual bool init() = 0;
	virtual void end() = 0;
	virtual void update() = 0;
	virtual void draw() = 0;
};

#endif // !G_ITEM_H
