#include "grade_calculator.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    grade_calculator w;
    w.setFixedSize(575, 440);
    w.show();

    return a.exec();
}
