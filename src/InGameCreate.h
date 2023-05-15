#ifndef G_INGAMECREATE_H
#define G_INGAMECREATE_H

#include "ISceneCreate.h"
#include "InGame.h"

class InGameCreate final : public ISceneCreate {
public:
	Scene* createScene(Component* comp){ return new InGame(comp); }
};

#endif // !G_INGAMECREATE_H
