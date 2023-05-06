#ifndef G_ERRORPROC_H
#define G_ERRORPROC_H

#include <DxLib.h>
#include <string>

class ErrorProc final {
public:
	static void ErrorExit(std::string msg = "") {
		MessageBox(NULL, msg.c_str(), TEXT("error"), MB_ICONINFORMATION);
		DxLib_End();
		exit(EXIT_FAILURE);
	}
};



#endif // !G_ERRORPROC_H
