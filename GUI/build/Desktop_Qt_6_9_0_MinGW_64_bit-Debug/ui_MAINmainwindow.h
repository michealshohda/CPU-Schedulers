/********************************************************************************
** Form generated from reading UI file 'MAINmainwindow.ui'
**
** Created by: Qt User Interface Compiler version 6.9.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINMAINWINDOW_H
#define UI_MAINMAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MAINmainwindow
{
public:
    QWidget *centralwidget;
    QGridLayout *gridLayout;
    QGridLayout *gridLayout_2;
    QSpacerItem *horizontalSpacer_2;
    QHBoxLayout *horizontalLayout_3;
    QLabel *label;
    QComboBox *comboBox;
    QSpacerItem *verticalSpacer;
    QHBoxLayout *horizontalLayout;
    QLabel *label2;
    QLineEdit *nbprocesses;
    QSpacerItem *horizontalSpacer_3;
    QSpacerItem *verticalSpacer_3;
    QSpacerItem *horizontalSpacer_6;
    QSpacerItem *verticalSpacer_2;
    QLabel *labelpic;
    QSpacerItem *horizontalSpacer_5;
    QSpacerItem *horizontalSpacer_4;
    QHBoxLayout *horizontalLayout_2;
    QSpacerItem *horizontalSpacer;
    QPushButton *Next;
    QPushButton *finish;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *MAINmainwindow)
    {
        if (MAINmainwindow->objectName().isEmpty())
            MAINmainwindow->setObjectName("MAINmainwindow");
        MAINmainwindow->resize(800, 600);
        centralwidget = new QWidget(MAINmainwindow);
        centralwidget->setObjectName("centralwidget");
        gridLayout = new QGridLayout(centralwidget);
        gridLayout->setObjectName("gridLayout");
        gridLayout_2 = new QGridLayout();
        gridLayout_2->setObjectName("gridLayout_2");
        horizontalSpacer_2 = new QSpacerItem(40, 20, QSizePolicy::Policy::Expanding, QSizePolicy::Policy::Minimum);

        gridLayout_2->addItem(horizontalSpacer_2, 7, 2, 1, 1);

        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setObjectName("horizontalLayout_3");
        label = new QLabel(centralwidget);
        label->setObjectName("label");

        horizontalLayout_3->addWidget(label);

        comboBox = new QComboBox(centralwidget);
        comboBox->setObjectName("comboBox");

        horizontalLayout_3->addWidget(comboBox);


        gridLayout_2->addLayout(horizontalLayout_3, 5, 0, 1, 3);

        verticalSpacer = new QSpacerItem(20, 40, QSizePolicy::Policy::Minimum, QSizePolicy::Policy::Expanding);

        gridLayout_2->addItem(verticalSpacer, 0, 2, 1, 1);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName("horizontalLayout");
        label2 = new QLabel(centralwidget);
        label2->setObjectName("label2");

        horizontalLayout->addWidget(label2);

        nbprocesses = new QLineEdit(centralwidget);
        nbprocesses->setObjectName("nbprocesses");

        horizontalLayout->addWidget(nbprocesses);


        gridLayout_2->addLayout(horizontalLayout, 7, 0, 1, 2);

        horizontalSpacer_3 = new QSpacerItem(40, 20, QSizePolicy::Policy::Preferred, QSizePolicy::Policy::Minimum);

        gridLayout_2->addItem(horizontalSpacer_3, 5, 3, 1, 1);

        verticalSpacer_3 = new QSpacerItem(20, 40, QSizePolicy::Policy::Minimum, QSizePolicy::Policy::Expanding);

        gridLayout_2->addItem(verticalSpacer_3, 8, 2, 1, 1);

        horizontalSpacer_6 = new QSpacerItem(40, 20, QSizePolicy::Policy::Expanding, QSizePolicy::Policy::Minimum);

        gridLayout_2->addItem(horizontalSpacer_6, 7, 3, 1, 1);

        verticalSpacer_2 = new QSpacerItem(20, 40, QSizePolicy::Policy::Minimum, QSizePolicy::Policy::Expanding);

        gridLayout_2->addItem(verticalSpacer_2, 3, 2, 1, 1);

        labelpic = new QLabel(centralwidget);
        labelpic->setObjectName("labelpic");
        labelpic->setAutoFillBackground(false);
        labelpic->setFrameShape(QFrame::Shape::NoFrame);
        labelpic->setTextFormat(Qt::TextFormat::PlainText);
        labelpic->setScaledContents(false);

        gridLayout_2->addWidget(labelpic, 1, 2, 1, 1);

        horizontalSpacer_5 = new QSpacerItem(40, 20, QSizePolicy::Policy::Expanding, QSizePolicy::Policy::Minimum);

        gridLayout_2->addItem(horizontalSpacer_5, 1, 3, 1, 1);

        horizontalSpacer_4 = new QSpacerItem(40, 20, QSizePolicy::Policy::Expanding, QSizePolicy::Policy::Minimum);

        gridLayout_2->addItem(horizontalSpacer_4, 1, 1, 1, 1);


        gridLayout->addLayout(gridLayout_2, 1, 1, 1, 1);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName("horizontalLayout_2");
        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Policy::Expanding, QSizePolicy::Policy::Minimum);

        horizontalLayout_2->addItem(horizontalSpacer);

        Next = new QPushButton(centralwidget);
        Next->setObjectName("Next");

        horizontalLayout_2->addWidget(Next);

        finish = new QPushButton(centralwidget);
        finish->setObjectName("finish");

        horizontalLayout_2->addWidget(finish);


        gridLayout->addLayout(horizontalLayout_2, 2, 1, 1, 1);

        MAINmainwindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(MAINmainwindow);
        menubar->setObjectName("menubar");
        menubar->setGeometry(QRect(0, 0, 800, 25));
        MAINmainwindow->setMenuBar(menubar);
        statusbar = new QStatusBar(MAINmainwindow);
        statusbar->setObjectName("statusbar");
        MAINmainwindow->setStatusBar(statusbar);

        retranslateUi(MAINmainwindow);

        QMetaObject::connectSlotsByName(MAINmainwindow);
    } // setupUi

    void retranslateUi(QMainWindow *MAINmainwindow)
    {
        MAINmainwindow->setWindowTitle(QCoreApplication::translate("MAINmainwindow", "CPU Scheduler", nullptr));
        label->setText(QCoreApplication::translate("MAINmainwindow", "which scheduler?", nullptr));
        label2->setText(QCoreApplication::translate("MAINmainwindow", "How many processes?:", nullptr));
        labelpic->setText(QString());
        Next->setText(QCoreApplication::translate("MAINmainwindow", "Next", nullptr));
        finish->setText(QCoreApplication::translate("MAINmainwindow", "Finish", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MAINmainwindow: public Ui_MAINmainwindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINMAINWINDOW_H
