#include"Logger.h"
#include "Message.h"
//ƒобавьте в ваш проект чата логгирование сообщений от других участников чата и своих сообщений.
//
//ƒл¤ этого напишите класс Logger, через который будет проходить вс¤ работа с файлом логов.
//—охран¤йте сообщени¤ в файл на диске, можете назвать его log.txt.ѕри создании объекта логгера должно производитьс¤ открытие файла, а при его разрушении Ч закрытие файла(концепт RAII).
//
//–еализуйте в классе два метода :
//
//запись строки логов в файл;
//чтение одной строки из файла.
// онечно же, запись и чтение должны быть потокобезопасными Ч при одновременном вызове нескольких потоков с записью в файл и чтением из файла, не должно происходить взаимоблокировок и гонок данных.
//
//Ќе забывайте про принципы инкапсул¤ции : код, пользующийс¤ вашими методами чтени¤ и записи, не должен знать про многопоточность.


int main()
{
	Logger log;
	Message m1 ("Denis", "Hi, Alex!", "Alex");
	Message m2("Alex", "Hi, Denis!", "Denis");
	Message m3("John", "Never gonna give you up", "Rick");

	std::thread w1(&Logger::writeLog, &log, m1.collectData());
	std::thread w2(&Logger::writeLog, &log, m2.collectData());
	std::thread w3(&Logger::writeLog, &log, m3.collectData());

	std::thread r1(&Logger::readLog, &log);
	std::thread r2(&Logger::readLog, &log);
	std::thread r3(&Logger::readLog, &log);

	w1.join();
	w2.join();
	w3.join();

	r1.join();
	r2.join();
	r3.join();

	std::thread(&Logger::readLog, &log).join();
	return 0;
}