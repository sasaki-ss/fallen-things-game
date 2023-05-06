#ifndef G_COLLISION_H
#define G_COLLISION_H

#include "Vector2.h"

class Collision final {
public:
	static bool isHitBoxToBox(Vector2 v, float w, float h, Vector2 v2, float w2, float h2) {
		if (v.x + w >= v2.x && v.x <= v2.x + w2 && v.y + h >= v2.y && v.y <= v2.y + h2) {
			return true;
		}

		return false;
	}
};
#endif // !G_COLLISION_H
