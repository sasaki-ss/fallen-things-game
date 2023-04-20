#ifndef G_AQITEM_H
#define G_AQITEM_H

#include "Item.h"

class AqItem final : public Item {
private:
	float _fallSpped;
public:
	AqItem(Vector2 pos);
	~AqItem();
	bool init();
	void end();
	void update();
	void draw();
};

#endif // !G_AQITEM_H
