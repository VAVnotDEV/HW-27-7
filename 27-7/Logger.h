#pragma once
#include <fstream>
#include <string>
#include "Message.h"
#include <shared_mutex>

class Logger
{
public:
	Logger();
	~Logger();
	void writeLog(const std::string& s);
	void readLog();

private:
	std::fstream _file;
	std::shared_mutex _sh_mutex;
	std::string _filename = "log.txt";
};