#ifndef G_GACHACREATE_H
#define G_GACHACREATE_H

#include "ISceneCreate.h"
#include "Gacha.h"

class GachaCreate final : public ISceneCreate {
public:
	Scene* createScene(Component* comp) { return new Gacha(comp); }
};

#endif // !G_GACHACREATE_H
