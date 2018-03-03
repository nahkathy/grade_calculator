#include "grade_calc.h"
#include <QApplication>
#include <QPushButton>
#include <QLabel>
#include <QSlider>
#include <QSpinBox>
#include <QHBoxLayout>
#include <QVBoxLayout>

int main(int argc, char *argv[])
{
    QApplication app(argc, argv);

    //Create Homework Sliders
    QWidget *hw_sliders = new QWidget;
    QVBoxLayout *vlayout = new QVBoxLayout;

   for (int i = 1; i < 9; i++) {
    QWidget *window = new QWidget;
    QLabel *label = new QLabel;
    QString name = "Hw " + QString::number(i);
    label->setText(name);
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

    vlayout->addWidget(window);
   }
    hw_sliders->setLayout(vlayout);
    hw_sliders->show();

    return app.exec();
}
