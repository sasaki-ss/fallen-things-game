#ifndef G_RESULT_H
#define G_RESULT_H

#include "Scene.h"

class Result final : public Scene {
private:

public:
	Result(Component* comp);
	bool init()override;
	void end()override;
	void update()override;
	void draw()override;
};

#endif // !G_RESULT_H

