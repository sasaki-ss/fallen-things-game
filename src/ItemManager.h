#ifndef G_ITEMMANAGER_H
#define G_ITEMMANAGER_H

#include <vector>
#include <memory>
#include "Object.h"

class Item;
class Player;
class Score;

class ItemManager final :public Object {
private:
	std::vector<std::unique_ptr<Item>> _items;
	int _next;
	int _cnt;
	bool _isEmp;
	bool _isGen;

	Player* _player;
	Score*	_score;

	void GenItem();
public:
	ItemManager(Component* comp);
	~ItemManager();
	bool init()override;
	void end()override;
	void update()override;
	void draw()override;
};

#endif // !G_ITEMMANAGER_H
