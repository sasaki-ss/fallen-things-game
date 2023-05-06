#ifndef G_AQITEM_H
#define G_AQITEM_H

#include "Item.h"

class AqItem final : public Item {
private:
	int _score;
public:
	AqItem(Vector2 pos, int score, Component* comp);
	~AqItem();
	bool init()override;
	void end()override;
	void update()override;
	void draw()override;

	int Acquisition() {
		_isActive = false;
		return _score;
	}
};

#endif // !G_AQITEM_H
