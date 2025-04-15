/********************************************************************************
** Form generated from reading UI file 'cpuscheduleros.ui'
**
** Created by: Qt User Interface Compiler version 6.9.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_CPUSCHEDULEROS_H
#define UI_CPUSCHEDULEROS_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QRadioButton>
#include <QtWidgets/QScrollArea>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_CPUSchedulerOS
{
public:
    QVBoxLayout *verticalLayout_3;
    QHBoxLayout *horizontalLayout_2;
    QSpacerItem *horizontalSpacer;
    QLabel *label;
    QSpacerItem *horizontalSpacer_2;
    QVBoxLayout *mainLayout;
    QScrollArea *scrollArea;
    QWidget *scrollAreaWidgetContents;
    QGroupBox *preemptiveGroupBox;
    QVBoxLayout *verticalLayout_2;
    QRadioButton *preemptiveRadio;
    QPushButton *OK;

    void setupUi(QDialog *CPUSchedulerOS)
    {
        if (CPUSchedulerOS->objectName().isEmpty())
            CPUSchedulerOS->setObjectName("CPUSchedulerOS");
        CPUSchedulerOS->resize(828, 638);
        verticalLayout_3 = new QVBoxLayout(CPUSchedulerOS);
        verticalLayout_3->setObjectName("verticalLayout_3");
        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName("horizontalLayout_2");
        horizontalLayout_2->setContentsMargins(-1, 13, -1, -1);
        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Policy::Expanding, QSizePolicy::Policy::Minimum);

        horizontalLayout_2->addItem(horizontalSpacer);

        label = new QLabel(CPUSchedulerOS);
        label->setObjectName("label");
        label->setFrameShape(QFrame::Shape::NoFrame);

        horizontalLayout_2->addWidget(label);

        horizontalSpacer_2 = new QSpacerItem(40, 20, QSizePolicy::Policy::Expanding, QSizePolicy::Policy::Minimum);

        horizontalLayout_2->addItem(horizontalSpacer_2);


        verticalLayout_3->addLayout(horizontalLayout_2);

        mainLayout = new QVBoxLayout();
        mainLayout->setObjectName("mainLayout");
        scrollArea = new QScrollArea(CPUSchedulerOS);
        scrollArea->setObjectName("scrollArea");
        scrollArea->setWidgetResizable(true);
        scrollAreaWidgetContents = new QWidget();
        scrollAreaWidgetContents->setObjectName("scrollAreaWidgetContents");
        scrollAreaWidgetContents->setGeometry(QRect(0, 0, 802, 451));
        scrollArea->setWidget(scrollAreaWidgetContents);

        mainLayout->addWidget(scrollArea);


        verticalLayout_3->addLayout(mainLayout);

        preemptiveGroupBox = new QGroupBox(CPUSchedulerOS);
        preemptiveGroupBox->setObjectName("preemptiveGroupBox");
        verticalLayout_2 = new QVBoxLayout(preemptiveGroupBox);
        verticalLayout_2->setObjectName("verticalLayout_2");
        preemptiveRadio = new QRadioButton(preemptiveGroupBox);
        preemptiveRadio->setObjectName("preemptiveRadio");

        verticalLayout_2->addWidget(preemptiveRadio);


        verticalLayout_3->addWidget(preemptiveGroupBox);

        OK = new QPushButton(CPUSchedulerOS);
        OK->setObjectName("OK");

        verticalLayout_3->addWidget(OK);


        retranslateUi(CPUSchedulerOS);

        QMetaObject::connectSlotsByName(CPUSchedulerOS);
    } // setupUi

    void retranslateUi(QDialog *CPUSchedulerOS)
    {
        CPUSchedulerOS->setWindowTitle(QCoreApplication::translate("CPUSchedulerOS", " Scheduler Selected Details", nullptr));
        label->setText(QString());
        preemptiveGroupBox->setTitle(QCoreApplication::translate("CPUSchedulerOS", "if it is preemptive check it", nullptr));
        preemptiveRadio->setText(QCoreApplication::translate("CPUSchedulerOS", "preemptive?", nullptr));
        OK->setText(QCoreApplication::translate("CPUSchedulerOS", "OK", nullptr));
    } // retranslateUi

};

namespace Ui {
    class CPUSchedulerOS: public Ui_CPUSchedulerOS {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_CPUSCHEDULEROS_H
