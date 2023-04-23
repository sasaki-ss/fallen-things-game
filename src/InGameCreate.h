#ifndef G_INGAMECREATE_H
#define G_INGAMECREATE_H

#include "ISceneCreate.h"

struct Component;

class InGameCreate final : public ISceneCreate {
public:
	Scene* createScene(Component* comp);
};

#endif // !G_INGAMECREATE_H
