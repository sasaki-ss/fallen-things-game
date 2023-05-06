#ifndef G_FPS_H
#define G_FPS_H

class Fps final {
private:
	long long	_startTime;
	int			_fps;
public:
	Fps();
	void init();
	void update();
	void wait();

	void setFps(int fps) { _fps = fps; }
};

#endif // !G_FPS_H
