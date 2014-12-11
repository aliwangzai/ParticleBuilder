/********************************************************************************
** Form generated from reading UI file 'qsliderlineeditor.ui'
**
** Created by: Qt User Interface Compiler version 5.3.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_QSLIDERLINEEDITOR_H
#define UI_QSLIDERLINEEDITOR_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QSlider>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_QSliderLineEditor
{
public:
    QHBoxLayout *horizontalLayout;
    QLabel *name_text;
    QSlider *name_slider;
    QLabel *name_val;

    void setupUi(QWidget *QSliderLineEditor)
    {
        if (QSliderLineEditor->objectName().isEmpty())
            QSliderLineEditor->setObjectName(QStringLiteral("QSliderLineEditor"));
        QSliderLineEditor->resize(150, 16);
        QSizePolicy sizePolicy(QSizePolicy::Minimum, QSizePolicy::Minimum);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(QSliderLineEditor->sizePolicy().hasHeightForWidth());
        QSliderLineEditor->setSizePolicy(sizePolicy);
        QSliderLineEditor->setMinimumSize(QSize(150, 0));
        QSliderLineEditor->setMaximumSize(QSize(150, 123465));
        horizontalLayout = new QHBoxLayout(QSliderLineEditor);
        horizontalLayout->setSpacing(0);
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        horizontalLayout->setContentsMargins(0, 0, 0, 0);
        name_text = new QLabel(QSliderLineEditor);
        name_text->setObjectName(QStringLiteral("name_text"));
        name_text->setMinimumSize(QSize(30, 0));
        name_text->setMaximumSize(QSize(30, 16777215));

        horizontalLayout->addWidget(name_text);

        name_slider = new QSlider(QSliderLineEditor);
        name_slider->setObjectName(QStringLiteral("name_slider"));
        name_slider->setMinimumSize(QSize(73, 0));
        name_slider->setMaximumSize(QSize(60, 16777215));
        name_slider->setStyleSheet(QLatin1String("\n"
"QSlider\n"
"{\n"
"height:10px;}\n"
"\n"
"\n"
" QSlider::groove:horizontal {\n"
"     border: 1px solid #999999;\n"
"     height: 2px; /* the groove expands to the size of the slider by default. by giving it a height, it has a fixed size */\n"
"     background: qlineargradient(x1:0, y1:0, x2:0, y2:1, stop:0 #B1B1B1, stop:1 #c4c4c4);\n"
"     margin: 2px 0;\n"
" }\n"
"\n"
" QSlider::handle:horizontal {\n"
"     background: qlineargradient(x1:0, y1:0, x2:1, y2:1, stop:0 #b4b4b4, stop:1 #8f8f8f);\n"
"     border: 1px solid #5c5c5c;\n"
"     width: 5px;\n"
"     margin: -4px 0; /* handle is placed by default on the contents rect of the groove. Expand outside the groove */\n"
"     border-radius: 1px;\n"
" }\n"
""));
        name_slider->setOrientation(Qt::Horizontal);

        horizontalLayout->addWidget(name_slider);

        name_val = new QLabel(QSliderLineEditor);
        name_val->setObjectName(QStringLiteral("name_val"));
        name_val->setMinimumSize(QSize(20, 0));
        name_val->setMaximumSize(QSize(20, 16777215));
        name_val->setAlignment(Qt::AlignLeading|Qt::AlignLeft|Qt::AlignVCenter);

        horizontalLayout->addWidget(name_val);


        retranslateUi(QSliderLineEditor);

        QMetaObject::connectSlotsByName(QSliderLineEditor);
    } // setupUi

    void retranslateUi(QWidget *QSliderLineEditor)
    {
        QSliderLineEditor->setWindowTitle(QApplication::translate("QSliderLineEditor", "Form", 0));
        name_text->setText(QApplication::translate("QSliderLineEditor", "Text", 0));
        name_val->setText(QApplication::translate("QSliderLineEditor", "0", 0));
    } // retranslateUi

};

namespace Ui {
    class QSliderLineEditor: public Ui_QSliderLineEditor {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_QSLIDERLINEEDITOR_H
