#ifndef VITS_SYSTEM
#define VITS_SYSTEM

#include <string>

class System {
public:
	static void init();
	static int exit(int status);

	static std::string pexec();
	static bool chdir(std::string);
	static std::string pwd();
	static std::string arch();
	static std::string user();
	static std::string os();

};

#endif
