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

    //Changing course
    QObject::connect(ui->comboBox, SIGNAL(currentIndexChanged(QString)), this, SLOT(change_class()));

    //Toolbar
    QObject::connect(ui->actionClose, SIGNAL(triggered(bool)), this, SLOT(close()));

}

grade_calculator::~grade_calculator()
{
    delete ui;
}

void grade_calculator::pic10c()
{
    ui->spinBox_2->setVisible(false);
    ui->spinBox_4->setVisible(false);
    ui->spinBox_6->setVisible(false);
    ui->spinBox_7->setVisible(false);
    ui->spinBox_8->setVisible(false);
    ui->horizontalSlider_2->setVisible(false);
    ui->horizontalSlider_4->setVisible(false);
    ui->horizontalSlider_6->setVisible(false);
    ui->horizontalSlider_7->setVisible(false);
    ui->horizontalSlider_8->setVisible(false);
    ui->label->setVisible(false);
    ui->label_3->setVisible(false);
    ui->label_4->setVisible(false);
    ui->label_6->setVisible(false);
    ui->label_7->setVisible(false);
    ui->label_8->setVisible(false);
    ui->label_5->setText("Hw 3");
    ui->label_9->setText("Hw 2");
    ui->label_11->setText("Midterm");
    ui->label_12->setText("Final Exam");
    ui->label_13->setText("Final Project");
}

void grade_calculator::change_class()
{
    if (ui->comboBox->currentText() == "PIC 10C. Advanced Programming.")
        this->pic10c();
    if (ui->comboBox->currentText() == "PIC 10B. Intermediate Programming.")
        this->pic10b();
}

void grade_calculator::update_overall(int)
{
    double avg = 0;
    if (ui->comboBox->currentText() == "PIC 10B. Intermediate Programming.")
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

    if (SchemeA == true) {
        avg = (static_cast<double>(hw_percent)*100*0.25 + 0.20*mid1 + 0.20*mid2 + 0.35*final);
    }
    if (SchemeA == false) {
        avg = (static_cast<double>(hw_percent)*0.25 + 0.30*highest_midterm + 0.44*final);
    }
    }
    else {
        int hw1 = ui->spinBox->value();
        int hw2 = ui->spinBox_3->value();
        int hw3 = ui->spinBox_5->value();
        int hw_sum = hw1 + hw2 + hw3;

        int midterm = ui->spinBox_9->value();
        int final = ui->spinBox_10->value();
        int proj = ui->spinBox_11->value();

        double hw_percent = static_cast<double>(hw_sum)/300;
        if (SchemeA == true) {
            avg = (static_cast<double>(hw_percent)*0.15 + 0.25*midterm + 0.3*final + 0.35*proj);
        }
        if (SchemeA == false) {
            avg = (static_cast<double>(hw_percent)*0.15 + 0.50*final + 0.35*proj);
        }
    }
    QString grade;
    if (avg >= 93.33) grade = "A";
    else if (avg > 90) grade = "A-";
    else if (avg > 86.66) grade = "B+";
    else if (avg > 83.33) grade = "B";
    else if (avg > 80.00) grade =  "B-";
    else if (avg > 76.66) grade = "C+";
    else if (avg > 73.33) grade = "C";
    else if (avg > 70) grade = "C-";

    ui->letter_grade->setText(grade);
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

void grade_calculator::pic10b()
{
    ui->spinBox_2->show();
    ui->spinBox_4->show();
    ui->spinBox_6->show();
    ui->spinBox_7->show();
    ui->spinBox_8->show();
    ui->horizontalSlider_2->show();
    ui->horizontalSlider_4->show();
    ui->horizontalSlider_6->show();
    ui->horizontalSlider_7->show();
    ui->horizontalSlider_8->show();
    ui->label->show();
    ui->label_3->show();
    ui->label_4->show();
    ui->label_6->show();
    ui->label_7->show();
    ui->label_8->show();
    ui->label_5->setText("Hw 5");
    ui->label_9->setText("Hw 3");
    ui->label_11->setText("Midterm 1");
    ui->label_12->setText("Midterm 2");
    ui->label_13->setText("Final Exam");
}


