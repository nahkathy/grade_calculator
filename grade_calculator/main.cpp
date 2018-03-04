#include "grade_calc.h"
#include <QApplication>
#include <QPushButton>
#include <QLabel>
#include <QSlider>
#include <QRadioButton>
#include <QComboBox>
#include <QSpinBox>
#include <QHBoxLayout>
#include <QVBoxLayout>

int main(int argc, char *argv[])
{
    QApplication app(argc, argv);

    //Create Course title Combobox
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

   //Exam Widget
   QWidget* exam_widget = new QWidget;
    //Labels
   QLabel *mid1 = new QLabel("Midterm 1");
   QLabel *mid2 = new QLabel("Midterm 2");
   QLabel *final = new QLabel("Final Exam");
    //Sliders
   QSlider *slid1 = new QSlider(Qt::Horizontal);
   slid1->setRange(0, 100);
   slid1->setValue(0);
   QSlider *slid2 = new QSlider(Qt::Horizontal);
   slid2->setRange(0, 100);
   slid2->setValue(0);
   QSlider *slidf = new QSlider(Qt::Horizontal);
   slidf->setRange(0, 100);
   slidf->setValue(0);
    //SpinBoxes
   QSpinBox *mid1spin = new QSpinBox;
   mid1spin->setRange(0, 100);
   QSpinBox *mid2spin = new QSpinBox;
   mid2spin->setRange(0, 100);
   QSpinBox *finspin = new QSpinBox;
   finspin->setRange(0, 100);
    //Connect Sliders with respective SpinBoxes
   QObject::connect(slid1, SIGNAL(valueChanged(int)), mid1spin, SLOT(setValue(int)));
   QObject::connect(mid1spin, SIGNAL(valueChanged(int)), slid1, SLOT(setValue(int)));
   QObject::connect(slid2, SIGNAL(valueChanged(int)), mid2spin, SLOT(setValue(int)));
   QObject::connect(mid2spin, SIGNAL(valueChanged(int)), slid2, SLOT(setValue(int)));
   QObject::connect(slidf, SIGNAL(valueChanged(int)), finspin, SLOT(setValue(int)));
   QObject::connect(finspin, SIGNAL(valueChanged(int)), slidf, SLOT(setValue(int)));
    //Create Schemas
   QRadioButton *schemeA = new QRadioButton;
   QRadioButton *schemeB = new QRadioButton;
   schemeA->setText("Schema A");
   schemeB->setText("Schema B");
    //Overall Score
   QWidget *score_widget = new QWidget;
   QLabel *score_text = new QLabel;
   score_text->setText("Overall Score: ");
   QLabel *score = new QLabel;
   score->setText(QString::number(3));
   QHBoxLayout *display_scores = new QHBoxLayout;
   display_scores->addWidget(score_text);
   display_scores->addWidget(score);
   score_widget->setLayout(display_scores);

   //QVBox Layout to organize them
   QVBoxLayout *layout3 = new QVBoxLayout;
   layout3->addWidget(mid1);
   layout3->addWidget(slid1);
   layout3->addWidget(mid1spin);
   layout3->addWidget(mid2);
   layout3->addWidget(slid2);
   layout3->addWidget(mid2spin);
   layout3->addWidget(final);
   layout3->addWidget(slidf);
   layout3->addWidget(finspin);
   layout3->addWidget(schemeA);
   layout3->addWidget(schemeB);
   layout3->addWidget(score_widget);

   exam_widget->setLayout(layout3);

   //Combine bottom 2 widgets with all score sliders
   QWidget *bottom_2 = new QWidget;
   QHBoxLayout *all_scores = new QHBoxLayout;
   all_scores->addWidget(hw_sliders);
   all_scores->addWidget(exam_widget);
   bottom_2->setLayout(all_scores);

   //Combine with title widget
   QWidget *entire_window = new QWidget;
   QVBoxLayout *whole_layout = new QVBoxLayout;
   whole_layout->addWidget(top_widget);
   whole_layout->addWidget(bottom_2);
   entire_window->setLayout(whole_layout);
   entire_window->show();

   return app.exec();
}
