#ifndef G_ITEMMANAGER_H
#define G_ITEMMANAGER_H

#include <vector>
#include "Object.h"

class Item;

class ItemManager final :public Object {
private:
	std::vector<Item*> _items;
public:
	ItemManager();
	~ItemManager();
	bool init();
	void end();
	void update();
	void draw();
};

#endif // !G_ITEMMANAGER_H
