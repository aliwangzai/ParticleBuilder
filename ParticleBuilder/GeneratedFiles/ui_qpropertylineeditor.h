/********************************************************************************
** Form generated from reading UI file 'qpropertylineeditor.ui'
**
** Created by: Qt User Interface Compiler version 5.3.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_QPROPERTYLINEEDITOR_H
#define UI_QPROPERTYLINEEDITOR_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QDial>
#include <QtWidgets/QDoubleSpinBox>
#include <QtWidgets/QFrame>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_QPropertyLineEditor
{
public:
    QHBoxLayout *horizontalLayout;
    QFrame *name_frame;
    QHBoxLayout *horizontalLayout_2;
    QLabel *name_PropertyName;
    QLabel *label;
    QDial *name_propertyadjust;
    QDoubleSpinBox *name_propertyvalue;
    QLabel *label_2;
    QLabel *label_3;

    void setupUi(QWidget *QPropertyLineEditor)
    {
        if (QPropertyLineEditor->objectName().isEmpty())
            QPropertyLineEditor->setObjectName(QStringLiteral("QPropertyLineEditor"));
        QPropertyLineEditor->resize(245, 30);
        QSizePolicy sizePolicy(QSizePolicy::Preferred, QSizePolicy::Minimum);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(QPropertyLineEditor->sizePolicy().hasHeightForWidth());
        QPropertyLineEditor->setSizePolicy(sizePolicy);
        QPropertyLineEditor->setMinimumSize(QSize(0, 0));
        QPropertyLineEditor->setMaximumSize(QSize(300, 2123));
        QPropertyLineEditor->setStyleSheet(QStringLiteral(""));
        horizontalLayout = new QHBoxLayout(QPropertyLineEditor);
#ifndef Q_OS_MAC
        horizontalLayout->setSpacing(6);
#endif
        horizontalLayout->setContentsMargins(0, 0, 0, 0);
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        horizontalLayout->setSizeConstraint(QLayout::SetDefaultConstraint);
        name_frame = new QFrame(QPropertyLineEditor);
        name_frame->setObjectName(QStringLiteral("name_frame"));
        name_frame->setStyleSheet(QLatin1String("QFrame#name_frame{\n"
"\n"
"border:1px solid gray;\n"
"border-left-width:0;\n"
"border-top-width:0;\n"
"border-right-width:0;\n"
"}"));
        name_frame->setFrameShape(QFrame::NoFrame);
        name_frame->setFrameShadow(QFrame::Sunken);
        horizontalLayout_2 = new QHBoxLayout(name_frame);
        horizontalLayout_2->setSpacing(1);
        horizontalLayout_2->setObjectName(QStringLiteral("horizontalLayout_2"));
        horizontalLayout_2->setContentsMargins(6, 0, 0, 0);
        name_PropertyName = new QLabel(name_frame);
        name_PropertyName->setObjectName(QStringLiteral("name_PropertyName"));
        name_PropertyName->setMinimumSize(QSize(100, 0));
        name_PropertyName->setMaximumSize(QSize(100, 16777215));
        name_PropertyName->setScaledContents(true);
        name_PropertyName->setWordWrap(true);

        horizontalLayout_2->addWidget(name_PropertyName);

        label = new QLabel(name_frame);
        label->setObjectName(QStringLiteral("label"));
        label->setMaximumSize(QSize(10, 16777215));

        horizontalLayout_2->addWidget(label);

        name_propertyadjust = new QDial(name_frame);
        name_propertyadjust->setObjectName(QStringLiteral("name_propertyadjust"));
        name_propertyadjust->setMaximumSize(QSize(28, 28));
        name_propertyadjust->setStyleSheet(QLatin1String("QDial{\n"
"color:red}"));
        name_propertyadjust->setSingleStep(0);
        name_propertyadjust->setInvertedAppearance(false);
        name_propertyadjust->setInvertedControls(false);
        name_propertyadjust->setWrapping(false);

        horizontalLayout_2->addWidget(name_propertyadjust);

        name_propertyvalue = new QDoubleSpinBox(name_frame);
        name_propertyvalue->setObjectName(QStringLiteral("name_propertyvalue"));
        QSizePolicy sizePolicy1(QSizePolicy::Fixed, QSizePolicy::Fixed);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(name_propertyvalue->sizePolicy().hasHeightForWidth());
        name_propertyvalue->setSizePolicy(sizePolicy1);
        name_propertyvalue->setMinimumSize(QSize(80, 0));
        name_propertyvalue->setMaximumSize(QSize(16777215, 16777215));
        name_propertyvalue->setStyleSheet(QStringLiteral(""));
        name_propertyvalue->setDecimals(2);
        name_propertyvalue->setMaximum(100);
        name_propertyvalue->setValue(0);

        horizontalLayout_2->addWidget(name_propertyvalue);

        label_2 = new QLabel(name_frame);
        label_2->setObjectName(QStringLiteral("label_2"));

        horizontalLayout_2->addWidget(label_2);

        horizontalLayout_2->setStretch(1, 1);
        horizontalLayout_2->setStretch(2, 1);
        horizontalLayout_2->setStretch(3, 1);

        horizontalLayout->addWidget(name_frame);

        label_3 = new QLabel(QPropertyLineEditor);
        label_3->setObjectName(QStringLiteral("label_3"));
        label_3->setFrameShape(QFrame::NoFrame);

        horizontalLayout->addWidget(label_3);


        retranslateUi(QPropertyLineEditor);

        QMetaObject::connectSlotsByName(QPropertyLineEditor);
    } // setupUi

    void retranslateUi(QWidget *QPropertyLineEditor)
    {
        QPropertyLineEditor->setWindowTitle(QApplication::translate("QPropertyLineEditor", "Form", 0));
        name_PropertyName->setText(QApplication::translate("QPropertyLineEditor", "Label", 0));
        label->setText(QApplication::translate("QPropertyLineEditor", "<!DOCTYPE HTML PUBLIC \"-//W3C//DTD HTML 4.0//EN\" \"http://www.w3.org/TR/REC-html40/strict.dtd\">\n"
"<html><head><meta name=\"qrichtext\" content=\"1\" /><style type=\"text/css\">\n"
"p, li { white-space: pre-wrap; }\n"
"</style></head><body style=\" font-family:'\345\256\213\344\275\223'; font-size:9pt; font-weight:400; font-style:normal;\">\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-size:10pt;\">:</span></p></body></html>", 0));
        label_2->setText(QString());
        label_3->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class QPropertyLineEditor: public Ui_QPropertyLineEditor {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_QPROPERTYLINEEDITOR_H
