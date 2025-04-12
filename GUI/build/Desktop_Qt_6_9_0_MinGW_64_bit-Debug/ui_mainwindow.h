/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 6.9.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QGraphicsView>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QSpinBox>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTextBrowser>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralwidget;
    QGridLayout *gridLayout_2;
    QGridLayout *gridLayout;
    QSpinBox *newProcessspinBox;
    QVBoxLayout *verticalLayout_2;
    QLabel *label_2;
    QLabel *label_3;
    QVBoxLayout *verticalLayout;
    QTextBrowser *textBrowser;
    QTextBrowser *textBrowser_2;
    QLabel *label_4;
    QLabel *label_5;
    QSpacerItem *horizontalSpacer;
    QLabel *label;
    QPushButton *newProccesButton;
    QLabel *label_6;
    QGraphicsView *graphicsView;
    QPushButton *pushButton;
    QSpinBox *spinBox;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName("MainWindow");
        MainWindow->resize(1069, 656);
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName("centralwidget");
        gridLayout_2 = new QGridLayout(centralwidget);
        gridLayout_2->setObjectName("gridLayout_2");
        gridLayout = new QGridLayout();
        gridLayout->setObjectName("gridLayout");
        newProcessspinBox = new QSpinBox(centralwidget);
        newProcessspinBox->setObjectName("newProcessspinBox");

        gridLayout->addWidget(newProcessspinBox, 5, 1, 1, 1);

        verticalLayout_2 = new QVBoxLayout();
        verticalLayout_2->setObjectName("verticalLayout_2");
        label_2 = new QLabel(centralwidget);
        label_2->setObjectName("label_2");

        verticalLayout_2->addWidget(label_2);

        label_3 = new QLabel(centralwidget);
        label_3->setObjectName("label_3");

        verticalLayout_2->addWidget(label_3);


        gridLayout->addLayout(verticalLayout_2, 5, 3, 1, 1);

        verticalLayout = new QVBoxLayout();
        verticalLayout->setObjectName("verticalLayout");
        textBrowser = new QTextBrowser(centralwidget);
        textBrowser->setObjectName("textBrowser");

        verticalLayout->addWidget(textBrowser);

        textBrowser_2 = new QTextBrowser(centralwidget);
        textBrowser_2->setObjectName("textBrowser_2");

        verticalLayout->addWidget(textBrowser_2);


        gridLayout->addLayout(verticalLayout, 5, 4, 1, 1);

        label_4 = new QLabel(centralwidget);
        label_4->setObjectName("label_4");
        QFont font;
        font.setBold(true);
        font.setItalic(true);
        label_4->setFont(font);

        gridLayout->addWidget(label_4, 4, 0, 1, 1);

        label_5 = new QLabel(centralwidget);
        label_5->setObjectName("label_5");

        gridLayout->addWidget(label_5, 5, 0, 1, 1);

        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Policy::Expanding, QSizePolicy::Policy::Minimum);

        gridLayout->addItem(horizontalSpacer, 5, 2, 1, 1);

        label = new QLabel(centralwidget);
        label->setObjectName("label");
        QFont font1;
        font1.setPointSize(48);
        font1.setBold(true);
        label->setFont(font1);

        gridLayout->addWidget(label, 1, 1, 1, 3, Qt::AlignmentFlag::AlignHCenter);

        newProccesButton = new QPushButton(centralwidget);
        newProccesButton->setObjectName("newProccesButton");

        gridLayout->addWidget(newProccesButton, 7, 0, 1, 1);

        label_6 = new QLabel(centralwidget);
        label_6->setObjectName("label_6");

        gridLayout->addWidget(label_6, 6, 0, 1, 1);

        graphicsView = new QGraphicsView(centralwidget);
        graphicsView->setObjectName("graphicsView");

        gridLayout->addWidget(graphicsView, 2, 1, 2, 3);

        pushButton = new QPushButton(centralwidget);
        pushButton->setObjectName("pushButton");

        gridLayout->addWidget(pushButton, 3, 4, 1, 1);

        spinBox = new QSpinBox(centralwidget);
        spinBox->setObjectName("spinBox");

        gridLayout->addWidget(spinBox, 6, 1, 1, 1);


        gridLayout_2->addLayout(gridLayout, 1, 0, 1, 1);

        MainWindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(MainWindow);
        menubar->setObjectName("menubar");
        menubar->setGeometry(QRect(0, 0, 1069, 25));
        MainWindow->setMenuBar(menubar);
        statusbar = new QStatusBar(MainWindow);
        statusbar->setObjectName("statusbar");
        MainWindow->setStatusBar(statusbar);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "MainWindow", nullptr));
        label_2->setText(QCoreApplication::translate("MainWindow", "Average Waiting Time = ", nullptr));
        label_3->setText(QCoreApplication::translate("MainWindow", "Average Turnaround Time =", nullptr));
        label_4->setText(QCoreApplication::translate("MainWindow", "Adding a new process", nullptr));
        label_5->setText(QCoreApplication::translate("MainWindow", "Burst time:", nullptr));
        label->setText(QCoreApplication::translate("MainWindow", "Gantt Chart", nullptr));
        newProccesButton->setText(QCoreApplication::translate("MainWindow", "Add process", nullptr));
        label_6->setText(QCoreApplication::translate("MainWindow", "Arrival time :", nullptr));
        pushButton->setText(QCoreApplication::translate("MainWindow", "Draw Gant Chart", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
