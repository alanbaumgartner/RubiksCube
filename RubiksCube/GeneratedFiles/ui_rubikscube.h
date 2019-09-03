/********************************************************************************
** Form generated from reading UI file 'rubikscube.ui'
**
** Created by: Qt User Interface Compiler version 5.13.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_RUBIKSCUBE_H
#define UI_RUBIKSCUBE_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_RubiksCubeClass
{
public:
    QMenuBar *menuBar;
    QToolBar *mainToolBar;
    QWidget *centralWidget;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *RubiksCubeClass)
    {
        if (RubiksCubeClass->objectName().isEmpty())
            RubiksCubeClass->setObjectName(QString::fromUtf8("RubiksCubeClass"));
        RubiksCubeClass->resize(600, 400);
        menuBar = new QMenuBar(RubiksCubeClass);
        menuBar->setObjectName(QString::fromUtf8("menuBar"));
        RubiksCubeClass->setMenuBar(menuBar);
        mainToolBar = new QToolBar(RubiksCubeClass);
        mainToolBar->setObjectName(QString::fromUtf8("mainToolBar"));
        RubiksCubeClass->addToolBar(mainToolBar);
        centralWidget = new QWidget(RubiksCubeClass);
        centralWidget->setObjectName(QString::fromUtf8("centralWidget"));
        RubiksCubeClass->setCentralWidget(centralWidget);
        statusBar = new QStatusBar(RubiksCubeClass);
        statusBar->setObjectName(QString::fromUtf8("statusBar"));
        RubiksCubeClass->setStatusBar(statusBar);

        retranslateUi(RubiksCubeClass);

        QMetaObject::connectSlotsByName(RubiksCubeClass);
    } // setupUi

    void retranslateUi(QMainWindow *RubiksCubeClass)
    {
        RubiksCubeClass->setWindowTitle(QCoreApplication::translate("RubiksCubeClass", "RubiksCube", nullptr));
    } // retranslateUi

};

namespace Ui {
    class RubiksCubeClass: public Ui_RubiksCubeClass {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_RUBIKSCUBE_H
