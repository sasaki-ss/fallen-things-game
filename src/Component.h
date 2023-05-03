#ifndef G_COMPONENT_H
#define G_COMPONENT_H

#include <memory>
#include <random>

#include "Keyboard.h"
#include "SceneManager.h"

struct Component {
	std::mt19937 rand;
	std::unique_ptr<Keyboard> keyboard;
	std::unique_ptr<SceneManager> sceneMgr;
};

#endif // !G_COMPONENT_H
