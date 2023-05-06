#ifndef G_KEYBOARD_H
#define G_KEYBOARD_H

#include <vector>
#include "Object.h"

enum class KeyInputType {
	Press,
	Release
};

class Keyboard final : public Object {
private:
	std::vector<int> _keyPressCnt;
	std::vector<int> _keyReleaseCnt;
public:
	Keyboard(Component* comp);
	~Keyboard();
	bool init()override;
	void end()override;
	void update()override;

	int getInputKey(int keycode, KeyInputType inputType = KeyInputType::Press);
};

#endif // !G_KEYBOARD_H
