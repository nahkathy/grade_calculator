#include "grade_calc.h"
#include <QApplication>
#include <QPushButton>

int main(int argc, char *argv[])
{
    QApplication app(argc, argv);
    QPushButton *button = new QPushButton("Hello there");
    button->show();

    return app.exec();
}
