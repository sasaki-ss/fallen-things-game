#ifndef G_FPS_H
#define G_FPS_H

class Fps final {
private:
	long long	_startTime;
	long long	_avgStartTime;
	int			_fps;
	int			_cnt;
	double		_avgFps;
	bool		_isWait;
public:
	Fps();
	void init();
	void update();
	void wait();

	void setFps(int fps) { _fps = fps; }
	bool getIsWait() { return _isWait; }
};

#endif // !G_FPS_H
