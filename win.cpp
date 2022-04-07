#include "win.h"

Win::Win(QWidget *parent) : QWidget(parent) //класс окна
{
     //codec = QTextCodec::codecForName("Windows-1251"); //таблица кодов русского языка 1251
     //setWindowTitle(codec->toUnicode("Возведение в квадрат"));
     setWindowTitle("Squarting"); //изменение заголовка окна
     frame = new QFrame(this); //рамка
     frame->setFrameShadow(QFrame::Raised); //установка тени рамки
     frame->setFrameShape(QFrame::Panel); //установка формы рамки
     //inputLabel = new QLabel(codec->toUnicode("Введите число:"), this);
     inputLabel = new QLabel("Enter the number:", this); //текст
     inputEdit = new QLineEdit("", this); //пустой строчной редактор ввода
     //проверка ввода:
     StrValidator *v = new StrValidator(inputEdit);
     inputEdit->setValidator(v);
     //outputLabel = new QLabel(codec->toUnicode("Результат:"), this);
     outputLabel = new QLabel("Result:", this); //виджет вывода результата
     outputEdit = new QLineEdit("", this);//пустая строка вывода
     //nextButton = new QPushButton(codec->toUnicode("Следующее"), this);
     nextButton = new QPushButton("Next", this); //виджет-кнопка "Следующее"
     //exitButton = new QPushButton(codec->toUnicode("Выход"), this);
     exitButton = new QPushButton("Exit", this); //виджет-кнопка "Выход"


     /*компановка приложения*/
     QVBoxLayout *vLayout1 = new QVBoxLayout(frame); //первый компановщик вертикального размещения:
     //вижджеты, им размещенные:
     vLayout1->addWidget(inputLabel);
     vLayout1->addWidget(inputEdit);
     vLayout1->addWidget(outputLabel);
     vLayout1->addWidget(outputEdit);
     vLayout1->addStretch();


     QVBoxLayout *vLayout2 = new QVBoxLayout();  //второй компановщик вертикального размещения:
     //вижджеты, им размещенные:
     vLayout2->addWidget(nextButton);
     vLayout2->addWidget(exitButton);
     vLayout2->addStretch();

     QHBoxLayout *hLayout = new QHBoxLayout(this);     //компановщик горизонтального размещения:
     //вижджеты, им размещенные:
     hLayout->addWidget(frame);
     hLayout->addLayout(vLayout2);
     begin();
     //подключение сигналов и слотов:
     connect (exitButton, SIGNAL(clicked(bool)), this, SLOT(close())); //сигнал кнопки "Выход" и закрытие
     connect (nextButton, SIGNAL(clicked(bool)), this, SLOT(begin())); //сигнал кнопки "Следующее" и повторный ввод и вычисление
     connect (inputEdit, SIGNAL(returnPressed()), this, SLOT(calc())); //сигнал нажатия вне окна ввода и вычисление результата
}


void Win::begin() // метод начальной настройки интерфейса
{
     inputEdit->clear(); //очистка окна ввода
     //кнопка "Следующее" скрыта не принимает и не обрабатывает сообщений:
     nextButton->setEnabled(false);
     nextButton->setDefault(false);
     //виджет ввода принимает сообщения
     inputEdit->setEnabled(true);
     //виджеты вывода скрыты и не принимают сообщений
     outputLabel->setVisible(false);
     outputEdit->setVisible(false);
     outputEdit->setEnabled(false);
     //ввод клавиатуры фокусируется на виджете ввода
     inputEdit->setFocus();
}


void Win::calc() //метод вычисления квадрата числа
{
     bool Ok=true; float r,a;
     QString str = inputEdit->text(); //текст окна ввода сохраняем в строку
     a = str.toDouble(&Ok); //строку с входным числом сохраняем в число
     if (Ok) { //если число получено
         r = a * a;
         str.setNum(r); //в строку записываем результат
         outputEdit->setText(str); //выводим результат в виджет вывода
         inputEdit->setEnabled(false);
         //показываем виджеты вывода и разрешаем им принимать сообщения
         outputLabel->setVisible(true);
         outputEdit->setVisible(true);
         nextButton->setDefault(true);
         nextButton->setEnabled(true);
         //фокусируем на кнопку "следующее"
         nextButton->setFocus();
     }
     else //если число не получено, выкидываем окно "Возведение в квадрат." с предупреждением "Введено неверное значение."
     if (!str.isEmpty()) {

         //QMessageBox msgBox(QMessageBox::Information, codec->toUnicode("Возведение в квадрат."),
         //codec->toUnicode("Введено неверное значение."), QMessageBox::Ok);
         QMessageBox msgBox(QMessageBox::Information, "Squarting", "Wrong value entered", QMessageBox::Ok);
         msgBox.exec();
     }
}
