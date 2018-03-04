#include "grade_calc.h"
#include <QApplication>
#include <QPushButton>
#include <QLabel>
#include <QSlider>
#include <QComboBox>
#include <QSpinBox>
#include <QHBoxLayout>
#include <QVBoxLayout>

int main(int argc, char *argv[])
{
    QApplication app(argc, argv);

    QWidget *top_widget = new QWidget;
    QHBoxLayout *layout1 = new QHBoxLayout;
    QLabel *course_name = new QLabel;
    course_name->setText("Course: ");
    QComboBox *box = new QComboBox;
    box->addItem("PIC 10B. Intermediate Programming");
    box->addItem("PIC 10C. Advanced Programming.");
    layout1->addWidget(course_name);
    layout1->addWidget(box);
    top_widget->setLayout(layout1);
    top_widget->show();

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

   //QWidget* exam_widget = new QWidget;
   //Create small widgets for midterms and final
   //QVBox Layout to organize them

   //QWidget* bottom_2 = new QWidget;
   //add hw_sliders and exam_widget

   //QVBoxLayout with top_widget and bottom_2

   return app.exec();
}
