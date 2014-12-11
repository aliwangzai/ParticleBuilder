/********************************************************************************
** Form generated from reading UI file 'dialog_about.ui'
**
** Created by: Qt User Interface Compiler version 5.3.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_DIALOG_ABOUT_H
#define UI_DIALOG_ABOUT_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QDialog>
#include <QtWidgets/QDialogButtonBox>
#include <QtWidgets/QFrame>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QVBoxLayout>

QT_BEGIN_NAMESPACE

class Ui_Dialog_About
{
public:
    QVBoxLayout *verticalLayout;
    QFrame *frame;
    QLabel *label;
    QLabel *label_2;
    QLabel *label_3;
    QLabel *label_4;
    QLabel *label_5;
    QLabel *label_6;
    QDialogButtonBox *buttonBox;

    void setupUi(QDialog *Dialog_About)
    {
        if (Dialog_About->objectName().isEmpty())
            Dialog_About->setObjectName(QStringLiteral("Dialog_About"));
        Dialog_About->resize(380, 172);
        QSizePolicy sizePolicy(QSizePolicy::Fixed, QSizePolicy::Fixed);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(Dialog_About->sizePolicy().hasHeightForWidth());
        Dialog_About->setSizePolicy(sizePolicy);
        Dialog_About->setMaximumSize(QSize(380, 172));
        verticalLayout = new QVBoxLayout(Dialog_About);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        frame = new QFrame(Dialog_About);
        frame->setObjectName(QStringLiteral("frame"));
        frame->setFrameShape(QFrame::StyledPanel);
        frame->setFrameShadow(QFrame::Raised);
        label = new QLabel(frame);
        label->setObjectName(QStringLiteral("label"));
        label->setGeometry(QRect(150, 60, 181, 16));
        label_2 = new QLabel(frame);
        label_2->setObjectName(QStringLiteral("label_2"));
        label_2->setGeometry(QRect(160, 80, 131, 16));
        label_2->setTextInteractionFlags(Qt::LinksAccessibleByMouse|Qt::TextSelectableByMouse);
        label_3 = new QLabel(frame);
        label_3->setObjectName(QStringLiteral("label_3"));
        label_3->setGeometry(QRect(130, 20, 221, 16));
        label_4 = new QLabel(frame);
        label_4->setObjectName(QStringLiteral("label_4"));
        label_4->setGeometry(QRect(190, 40, 81, 16));
        label_5 = new QLabel(frame);
        label_5->setObjectName(QStringLiteral("label_5"));
        label_5->setGeometry(QRect(0, 0, 141, 121));
        label_5->setPixmap(QPixmap(QString::fromUtf8(":/images/icon.png")));
        label_6 = new QLabel(frame);
        label_6->setObjectName(QStringLiteral("label_6"));
        label_6->setGeometry(QRect(160, 100, 141, 16));

        verticalLayout->addWidget(frame);

        buttonBox = new QDialogButtonBox(Dialog_About);
        buttonBox->setObjectName(QStringLiteral("buttonBox"));
        buttonBox->setOrientation(Qt::Horizontal);
        buttonBox->setStandardButtons(QDialogButtonBox::Cancel|QDialogButtonBox::Ok);

        verticalLayout->addWidget(buttonBox);


        retranslateUi(Dialog_About);
        QObject::connect(buttonBox, SIGNAL(accepted()), Dialog_About, SLOT(accept()));
        QObject::connect(buttonBox, SIGNAL(rejected()), Dialog_About, SLOT(reject()));

        QMetaObject::connectSlotsByName(Dialog_About);
    } // setupUi

    void retranslateUi(QDialog *Dialog_About)
    {
        Dialog_About->setWindowTitle(QApplication::translate("Dialog_About", "About", 0));
        label->setText(QApplication::translate("Dialog_About", "Copyright 2012-2014 By Warren", 0));
        label_2->setText(QApplication::translate("Dialog_About", "Email: wac056@163.com", 0));
        label_3->setText(QApplication::translate("Dialog_About", "Cocos2d Particle Builder for Windows", 0));
        label_4->setText(QApplication::translate("Dialog_About", "Version 1.4.0", 0));
        label_5->setText(QString());
        label_6->setText(QApplication::translate("Dialog_About", "Welcome your feedback", 0));
    } // retranslateUi

};

namespace Ui {
    class Dialog_About: public Ui_Dialog_About {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_DIALOG_ABOUT_H
