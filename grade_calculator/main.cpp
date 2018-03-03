#include "grade_calc.h"
#include <QApplication>
#include <QPushButton>
#include <QLabel>
#include <QSlider>
#include <QSpinBox>
#include <QHBoxLayout>

int main(int argc, char *argv[])
{
    QApplication app(argc, argv);

    QWidget *window = new QWidget;

    QLabel *label = new QLabel("Hw 1");
    QSlider *slider = new QSlider(Qt::Horizontal);
    slider->setRange(0, 100);
    slider->setValue(0);
    QSpinBox *spinbox = new QSpinBox;
    spinbox->setRange(0, 100);

    QObject::connect(slider, SIGNAL(valueChanged(int)), spinbox, SLOT(setValue(int)));
    QObject::connect(spinbox, SIGNAL(valueChanged(int)), slider, SLOT(setValue(int)));

    QHBoxLayout *layout = new QHBoxLayout;
    layout->addWidget(label);
    layout->addWidget(slider);
    layout->addWidget(spinbox);
    window->setLayout(layout);
    window->show();

    return app.exec();
}
