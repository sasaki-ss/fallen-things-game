#ifndef G_TITLECREATE_H
#define G_TITLECREATE_H

#include "ISceneCreate.h"
#include "Title.h"

class TitleCreate final : public ISceneCreate {
public:
	Scene* createScene(Component* comp) { return new Title(comp); }
};

#endif // !G_TITLECREATE_H

