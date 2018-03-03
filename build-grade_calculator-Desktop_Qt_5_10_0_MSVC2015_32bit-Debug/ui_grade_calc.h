/********************************************************************************
** Form generated from reading UI file 'grade_calc.ui'
**
** Created by: Qt User Interface Compiler version 5.10.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_GRADE_CALC_H
#define UI_GRADE_CALC_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_grade_calc
{
public:
    QMenuBar *menuBar;
    QToolBar *mainToolBar;
    QWidget *centralWidget;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *grade_calc)
    {
        if (grade_calc->objectName().isEmpty())
            grade_calc->setObjectName(QStringLiteral("grade_calc"));
        grade_calc->resize(400, 300);
        menuBar = new QMenuBar(grade_calc);
        menuBar->setObjectName(QStringLiteral("menuBar"));
        grade_calc->setMenuBar(menuBar);
        mainToolBar = new QToolBar(grade_calc);
        mainToolBar->setObjectName(QStringLiteral("mainToolBar"));
        grade_calc->addToolBar(mainToolBar);
        centralWidget = new QWidget(grade_calc);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        grade_calc->setCentralWidget(centralWidget);
        statusBar = new QStatusBar(grade_calc);
        statusBar->setObjectName(QStringLiteral("statusBar"));
        grade_calc->setStatusBar(statusBar);

        retranslateUi(grade_calc);

        QMetaObject::connectSlotsByName(grade_calc);
    } // setupUi

    void retranslateUi(QMainWindow *grade_calc)
    {
        grade_calc->setWindowTitle(QApplication::translate("grade_calc", "grade_calc", nullptr));
    } // retranslateUi

};

namespace Ui {
    class grade_calc: public Ui_grade_calc {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_GRADE_CALC_H
