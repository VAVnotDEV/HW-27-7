#include"Logger.h"
#include "Message.h"
//Добавьте в ваш проект чата логгирование сообщений от других участников чата и своих сообщений.
//
//Для этого напишите класс Logger, через который будет проходить вся работа с файлом логов.
//Сохраняйте сообщения в файл на диске, можете назвать его log.txt.При создании объекта логгера должно производиться открытие файла, а при его разрушении — закрытие файла(концепт RAII).
//
//Реализуйте в классе два метода :
//
//запись строки логов в файл;
//чтение одной строки из файла.
//Конечно же, запись и чтение должны быть потокобезопасными — при одновременном вызове нескольких потоков с записью в файл и чтением из файла, не должно происходить взаимоблокировок и гонок данных.
//
//Не забывайте про принципы инкапсуляции : код, пользующийся вашими методами чтения и записи, не должен знать про многопоточность.


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