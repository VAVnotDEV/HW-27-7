#include "Message.h"

Message::Message(std::string form, std::string message, std::string to) : _form(form), _message(message), _to(to) {}


std::string Message::collectData()
{
	return "F:" + _form + " M:" + _message + " T:" + _to;
}