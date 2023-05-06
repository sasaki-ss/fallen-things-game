#ifndef G_SCORE_H
#define G_SCORE_H

#include "Object.h"

class Score : public Object {
private:
	int _score;
public:
	Score(Component* comp);
	~Score(){}
	bool init()override;
	void end()override;

	void add(int value) { _score += value; }
	
	int getScore() { return _score; }
};

#endif // !G_SCORE_H
