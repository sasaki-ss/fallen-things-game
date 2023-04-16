#ifndef G_SYSTEM_H
#define G_SYSTEM_H

#include "Vector2.h"
#include <string>

class System final {
private:
	Vector2 _windowPos;
	std::string _windowTitle;
public:
	bool init();
	void run();
	void end();

	void setWindowPos(Vector2 pos) { _windowPos = pos; }
	void setWindowTitle(std::string name) { _windowTitle = name; }
};

#endif // !G_SYSTEM_H
