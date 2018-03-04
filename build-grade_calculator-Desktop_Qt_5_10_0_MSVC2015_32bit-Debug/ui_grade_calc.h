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
#include <QtWidgets/QHBoxLayout>
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
    QWidget *course_name;
    QHBoxLayout *horizontalLayout;
    QMenuBar *menuBar;
    QToolBar *mainToolBar;
    QStatusBar *statusBar;
    QToolBar *toolBar;

    void setupUi(QMainWindow *grade_calc)
    {
        if (grade_calc->objectName().isEmpty())
            grade_calc->setObjectName(QStringLiteral("grade_calc"));
        grade_calc->resize(400, 300);
        course_name = new QWidget(grade_calc);
        course_name->setObjectName(QStringLiteral("course_name"));
        horizontalLayout = new QHBoxLayout(course_name);
        horizontalLayout->setSpacing(6);
        horizontalLayout->setContentsMargins(11, 11, 11, 11);
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        grade_calc->setCentralWidget(course_name);
        menuBar = new QMenuBar(grade_calc);
        menuBar->setObjectName(QStringLiteral("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 400, 17));
        grade_calc->setMenuBar(menuBar);
        mainToolBar = new QToolBar(grade_calc);
        mainToolBar->setObjectName(QStringLiteral("mainToolBar"));
        grade_calc->addToolBar(Qt::TopToolBarArea, mainToolBar);
        statusBar = new QStatusBar(grade_calc);
        statusBar->setObjectName(QStringLiteral("statusBar"));
        grade_calc->setStatusBar(statusBar);
        toolBar = new QToolBar(grade_calc);
        toolBar->setObjectName(QStringLiteral("toolBar"));
        grade_calc->addToolBar(Qt::TopToolBarArea, toolBar);

        retranslateUi(grade_calc);

        QMetaObject::connectSlotsByName(grade_calc);
    } // setupUi

    void retranslateUi(QMainWindow *grade_calc)
    {
        grade_calc->setWindowTitle(QApplication::translate("grade_calc", "grade_calc", nullptr));
        toolBar->setWindowTitle(QApplication::translate("grade_calc", "toolBar", nullptr));
    } // retranslateUi

};

namespace Ui {
    class grade_calc: public Ui_grade_calc {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_GRADE_CALC_H
