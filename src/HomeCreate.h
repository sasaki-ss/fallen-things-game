#ifndef G_HOMECREATE_H
#define G_HOMECREATE_H

#include "ISceneCreate.h"
#include "Home.h"

class HomeCreate final : public ISceneCreate {
public:
	Scene* createScene(Component* comp) { return new Home(comp); }
};

#endif // !G_HOMECREATE_H
