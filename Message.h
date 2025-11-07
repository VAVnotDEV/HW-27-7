#pragma once
#include <string>
#include <iostream>
class Message
{
public:
	Message(std::string form, std::string message, std::string to);
	~Message() {}

	std::string collectData();
private:
	std::string _form;
	std::string _message;
	std::string _to;
};


