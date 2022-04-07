#ifndef WIN_H
#define WIN_H

#include <QWidget>
#include <QtGui>

//<QtGui> в моей версии Qt не подключает библиотеки виджетов, поэтому каждый подключаю отдельно.
//Также не распознается библиотека <QTextCodec>,
//поэтому всё что связано с перекодировкой в русский алфавит закомментировано, интерфейс написан на английском

//#include <QTextCodec>
#include <QFrame>
#include <QLabel>
#include <QLineEdit>
#include <QPushButton>
#include <QVBoxLayout>
#include <QMessageBox>
#include <QHBoxLayout>


class Win : public QWidget //класс окна
{
    Q_OBJECT // макрос Qt, обеспечивающий корректное создание сигналов и слотов
protected:
     //QTextCodec *codec; //для русификации интерфейса
     QFrame *frame; // рамка
     QLabel *inputLabel; // метка ввода
     QLineEdit *inputEdit; // строчный редактор ввода
     QLabel *outputLabel; // метка вывода
     QLineEdit *outputEdit; // строчный редактор вывода
     QPushButton *nextButton; // кнопка Следующее
     QPushButton *exitButton; // кнопка Выход
public:
    Win(QWidget *parent = 0); // конструктор. Родителя нет => виджет окна отображается в отдельном окне
public slots:
     void begin(); // метод начальной настройки интерфейса
     void calc(); // метод реализации вычислений

};

class StrValidator : public QValidator // класс компонента проверки ввода
{
public:
     StrValidator(QObject *parent) : QValidator(parent){} //конструктор наследуется

     virtual State validate(QString &str,int &pos) const //передается строка для проверки и позиция курсора
     {
        return Acceptable; // метод всегда принимает вводимую строку
     }
};

#endif // WIN_H
