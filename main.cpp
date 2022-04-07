#include "win.h"

#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication app(argc, argv); // создание объекта-приложения
    Win win(0); // создание объекта управления окном
    win.show(); // визуализация окна win
    return app.exec(); //запуск цикла обработки сообщений приложения
}
