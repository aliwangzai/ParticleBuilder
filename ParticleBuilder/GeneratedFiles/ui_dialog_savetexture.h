/********************************************************************************
** Form generated from reading UI file 'dialog_savetexture.ui'
**
** Created by: Qt User Interface Compiler version 5.3.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_DIALOG_SAVETEXTURE_H
#define UI_DIALOG_SAVETEXTURE_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QDialog>
#include <QtWidgets/QDialogButtonBox>
#include <QtWidgets/QFrame>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QRadioButton>
#include <QtWidgets/QVBoxLayout>

QT_BEGIN_NAMESPACE

class Ui_Dialog_SaveTexture
{
public:
    QVBoxLayout *verticalLayout;
    QFrame *frame;
    QGridLayout *gridLayout;
    QRadioButton *m_option_embed;
    QRadioButton *m_option_save;
    QLineEdit *m_filename;
    QDialogButtonBox *buttonBox;

    void setupUi(QDialog *Dialog_SaveTexture)
    {
        if (Dialog_SaveTexture->objectName().isEmpty())
            Dialog_SaveTexture->setObjectName(QStringLiteral("Dialog_SaveTexture"));
        Dialog_SaveTexture->resize(283, 109);
        verticalLayout = new QVBoxLayout(Dialog_SaveTexture);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        frame = new QFrame(Dialog_SaveTexture);
        frame->setObjectName(QStringLiteral("frame"));
        frame->setFrameShape(QFrame::StyledPanel);
        frame->setFrameShadow(QFrame::Raised);
        gridLayout = new QGridLayout(frame);
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        m_option_embed = new QRadioButton(frame);
        m_option_embed->setObjectName(QStringLiteral("m_option_embed"));

        gridLayout->addWidget(m_option_embed, 0, 0, 1, 1);

        m_option_save = new QRadioButton(frame);
        m_option_save->setObjectName(QStringLiteral("m_option_save"));

        gridLayout->addWidget(m_option_save, 1, 0, 1, 1);

        m_filename = new QLineEdit(frame);
        m_filename->setObjectName(QStringLiteral("m_filename"));

        gridLayout->addWidget(m_filename, 1, 1, 1, 1);


        verticalLayout->addWidget(frame);

        buttonBox = new QDialogButtonBox(Dialog_SaveTexture);
        buttonBox->setObjectName(QStringLiteral("buttonBox"));
        buttonBox->setOrientation(Qt::Horizontal);
        buttonBox->setStandardButtons(QDialogButtonBox::Cancel|QDialogButtonBox::Ok);

        verticalLayout->addWidget(buttonBox);


        retranslateUi(Dialog_SaveTexture);
        QObject::connect(buttonBox, SIGNAL(accepted()), Dialog_SaveTexture, SLOT(accept()));
        QObject::connect(buttonBox, SIGNAL(rejected()), Dialog_SaveTexture, SLOT(reject()));

        QMetaObject::connectSlotsByName(Dialog_SaveTexture);
    } // setupUi

    void retranslateUi(QDialog *Dialog_SaveTexture)
    {
        Dialog_SaveTexture->setWindowTitle(QApplication::translate("Dialog_SaveTexture", "Dialog", 0));
        m_option_embed->setText(QApplication::translate("Dialog_SaveTexture", "Embed Texture", 0));
        m_option_save->setText(QApplication::translate("Dialog_SaveTexture", "Save Texture :", 0));
    } // retranslateUi

};

namespace Ui {
    class Dialog_SaveTexture: public Ui_Dialog_SaveTexture {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_DIALOG_SAVETEXTURE_H
