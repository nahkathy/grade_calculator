#include "grade_calculator.h"
#include "ui_grade_calculator.h"
#include <vector>

grade_calculator::grade_calculator(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::grade_calculator)
{
    ui->setupUi(this);

//Connect Homework Sliders to Spinners
   QObject::connect(ui->horizontalSlider, SIGNAL(valueChanged(int)), ui->spinBox, SLOT(setValue(int)));
   QObject::connect(ui->horizontalSlider_2, SIGNAL(valueChanged(int)), ui->spinBox_2, SLOT(setValue(int)));
   QObject::connect(ui->horizontalSlider_3, SIGNAL(valueChanged(int)), ui->spinBox_3, SLOT(setValue(int)));
   QObject::connect(ui->horizontalSlider_4, SIGNAL(valueChanged(int)), ui->spinBox_4, SLOT(setValue(int)));
   QObject::connect(ui->horizontalSlider_5, SIGNAL(valueChanged(int)), ui->spinBox_5, SLOT(setValue(int)));
   QObject::connect(ui->horizontalSlider_6, SIGNAL(valueChanged(int)), ui->spinBox_6, SLOT(setValue(int)));
   QObject::connect(ui->horizontalSlider_7, SIGNAL(valueChanged(int)), ui->spinBox_7, SLOT(setValue(int)));
   QObject::connect(ui->horizontalSlider_8, SIGNAL(valueChanged(int)), ui->spinBox_8, SLOT(setValue(int)));
   //Connect Homework Spinners to Sliders
   QObject::connect(ui->spinBox, SIGNAL(valueChanged(int)), ui->horizontalSlider, SLOT(setValue(int)));
   QObject::connect(ui->spinBox_2, SIGNAL(valueChanged(int)), ui->horizontalSlider_2, SLOT(setValue(int)));
   QObject::connect(ui->spinBox_3, SIGNAL(valueChanged(int)), ui->horizontalSlider_3, SLOT(setValue(int)));
   QObject::connect(ui->spinBox_4, SIGNAL(valueChanged(int)), ui->horizontalSlider_4, SLOT(setValue(int)));
   QObject::connect(ui->spinBox_5, SIGNAL(valueChanged(int)), ui->horizontalSlider_5, SLOT(setValue(int)));
   QObject::connect(ui->spinBox_6, SIGNAL(valueChanged(int)), ui->horizontalSlider_6, SLOT(setValue(int)));
   QObject::connect(ui->spinBox_7, SIGNAL(valueChanged(int)), ui->horizontalSlider_7, SLOT(setValue(int)));
   QObject::connect(ui->spinBox_8, SIGNAL(valueChanged(int)), ui->horizontalSlider_8, SLOT(setValue(int)));

   //Connect Exam Sliders to Spinners and vice versa
   QObject::connect(ui->spinBox_9, SIGNAL(valueChanged(int)), ui->horizontalSlider_9, SLOT(setValue(int)));
   QObject::connect(ui->spinBox_10, SIGNAL(valueChanged(int)), ui->horizontalSlider_10, SLOT(setValue(int)));
   QObject::connect(ui->spinBox_11, SIGNAL(valueChanged(int)), ui->horizontalSlider_11, SLOT(setValue(int)));
   QObject::connect(ui->horizontalSlider_9, SIGNAL(valueChanged(int)), ui->spinBox_9, SLOT(setValue(int)));
   QObject::connect(ui->horizontalSlider_10, SIGNAL(valueChanged(int)), ui->spinBox_10, SLOT(setValue(int)));
   QObject::connect(ui->horizontalSlider_11, SIGNAL(valueChanged(int)), ui->spinBox_11, SLOT(setValue(int)));

   //Radio Button Schemes
   ui->radioButton->setChecked(true);
   QObject::connect(ui->radioButton, SIGNAL(clicked(bool)), this, SLOT(make_schemeA()));
   QObject::connect(ui->radioButton, SIGNAL(clicked(bool)), this, SLOT(change_value(bool)));
   QObject::connect(ui->radioButton_2, SIGNAL(clicked(bool)), this, SLOT(make_schemeB()));
   QObject::connect(ui->radioButton_2, SIGNAL(clicked(bool)), this, SLOT(change_value(bool)));

   //Update overall score whenever something is moved
    QObject::connect(ui->spinBox, SIGNAL(valueChanged(int)), this, SLOT(update_overall(int)));
    QObject::connect(ui->spinBox_2, SIGNAL(valueChanged(int)), this, SLOT(update_overall(int)));
    QObject::connect(ui->spinBox_3, SIGNAL(valueChanged(int)), this, SLOT(update_overall(int)));
    QObject::connect(ui->spinBox_4, SIGNAL(valueChanged(int)), this, SLOT(update_overall(int)));
    QObject::connect(ui->spinBox_5, SIGNAL(valueChanged(int)), this, SLOT(update_overall(int)));
    QObject::connect(ui->spinBox_6, SIGNAL(valueChanged(int)), this, SLOT(update_overall(int)));
    QObject::connect(ui->spinBox_7, SIGNAL(valueChanged(int)), this, SLOT(update_overall(int)));
    QObject::connect(ui->spinBox_8, SIGNAL(valueChanged(int)), this, SLOT(update_overall(int)));
    QObject::connect(ui->spinBox_9, SIGNAL(valueChanged(int)), this, SLOT(update_overall(int)));
    QObject::connect(ui->spinBox_10, SIGNAL(valueChanged(int)), this, SLOT(update_overall(int)));
    QObject::connect(ui->spinBox_11, SIGNAL(valueChanged(int)), this, SLOT(update_overall(int)));

    QObject::connect(ui->actionClose, SIGNAL(triggered(bool)), this, SLOT(close()));
}

grade_calculator::~grade_calculator()
{
    delete ui;
}

void grade_calculator::update_overall(int)
{
    int hw1 = ui->spinBox->value();
    int hw2 = ui->spinBox_2->value();
    int hw3 = ui->spinBox_3->value();
    int hw4 = ui->spinBox_4->value();
    int hw5 = ui->spinBox_5->value();
    int hw6 = ui->spinBox_6->value();
    int hw7 = ui->spinBox_7->value();
    int hw8 = ui->spinBox_8->value();

    int hw_sum = hw1 + hw2 + hw3 + hw4 + hw5 + hw6 + hw7 + hw8;

    int mid1 = ui->spinBox_9->value();
    int mid2 = ui->spinBox_10->value();
    int final = ui->spinBox_11->value();

    int highest_midterm;
    if (mid1 > mid2) highest_midterm = mid1;
    else highest_midterm = mid2;

    double hw_percent = static_cast<double>(hw_sum)/800;

    double avg = 0;
    if (SchemeA == true) {
        avg = (static_cast<double>(hw_percent)*0.25 + 0.20*mid1 + 0.20*mid2 + 0.35*final);
    }
    if (SchemeA == false) {
        avg = (static_cast<double>(hw_percent)*0.25 + 0.30*highest_midterm + 0.44*final);
    }

    ui->score_value->setText(QString::number(avg));
    return;
}

void grade_calculator::make_schemeA()
{
    SchemeA = true;
}
void grade_calculator::make_schemeB()
{
    SchemeA = false;
}

void grade_calculator::change_value(bool)
{
    this->update_overall(1);
}


