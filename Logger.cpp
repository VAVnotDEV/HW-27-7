#include "Logger.h"
#include <iostream>

Logger::Logger()
{
	_file.open(_filename, std::ios::in | std::ios::out | std::ios::app);
}
Logger::~Logger()
{
	_file.close();
}
void Logger::writeLog(const std::string& s)
{
	std::this_thread::sleep_for(std::chrono::seconds(1));

	_sh_mutex.lock();
	_file << s << std::endl;
	_sh_mutex.unlock();

}

void Logger::readLog()
{
	std::string line;

	std::this_thread::sleep_for(std::chrono::seconds(3));

	_sh_mutex.lock_shared();
	_file.seekg(0, std::ios::beg);
	std::getline(_file, line);
	std::cout << line << std::endl;
	_sh_mutex.unlock_shared();
}
