#ifndef GRADE_CALCULATOR_H
#define GRADE_CALCULATOR_H

#include <QMainWindow>
#include <QPushButton>
#include <QLabel>
#include <QSlider>
#include <QRadioButton>
#include <QComboBox>
#include <QSpinBox>
#include <QHBoxLayout>
#include <QVBoxLayout>
#include <QFont>
#include <QObject>

namespace Ui {
class grade_calculator;
}

class grade_calculator : public QMainWindow
{
    Q_OBJECT

public:
    explicit grade_calculator(QWidget *parent = 0);
    ~grade_calculator();

signals:
    void compute_overall();

public slots:
    void update_overall(int unused);
    void make_schemeA();
    void make_schemeB();
    void change_value(bool);

private:
    Ui::grade_calculator *ui;
    bool SchemeA = true;
};

#endif // GRADE_CALCULATOR_H
