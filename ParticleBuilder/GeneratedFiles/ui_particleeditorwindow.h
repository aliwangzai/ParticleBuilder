/********************************************************************************
** Form generated from reading UI file 'particleeditorwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.3.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_PARTICLEEDITORWINDOW_H
#define UI_PARTICLEEDITORWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QCheckBox>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QDockWidget>
#include <QtWidgets/QFrame>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QTabWidget>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_ParticleEditorWindow
{
public:
    QWidget *centralwidget;
    QVBoxLayout *verticalLayout;
    QWidget *name_cocownd;
    QTabWidget *tabWidget;
    QWidget *tab;
    QHBoxLayout *horizontalLayout_2;
    QGroupBox *name_startColor;
    QPushButton *btn_startColor;
    QGroupBox *name_startColorVar;
    QWidget *tab_2;
    QHBoxLayout *horizontalLayout_5;
    QGroupBox *name_endColor;
    QPushButton *btn_endColor;
    QGroupBox *name_endColorVar;
    QWidget *tab_3;
    QHBoxLayout *horizontalLayout_4;
    QGroupBox *name_bgColorVar;
    QPushButton *btn_bgColor;
    QGroupBox *groupBox;
    QPushButton *changeButton;
    QLabel *label_bg;
    QPushButton *removeButton;
    QCheckBox *box_move;
    QDockWidget *dockWidget_2;
    QWidget *dockWidgetContents_2;
    QVBoxLayout *verticalLayout_5;
    QFrame *name_particleProperties;
    QDockWidget *dockWidget00;
    QWidget *dockWidgetContents_5;
    QFrame *frame_2;
    QHBoxLayout *horizontalLayout_3;
    QLabel *name_textureImage;
    QPushButton *pushButton;
    QDockWidget *dockWidget_7;
    QWidget *dockWidgetContents_7;
    QGridLayout *gridLayout_2;
    QFrame *name_blendFunc;
    QGridLayout *gridLayout_3;
    QComboBox *name_blendsrc;
    QPushButton *name_blendNormal;
    QPushButton *name_blendAdditive;
    QComboBox *name_blenddst;
    QLabel *label;
    QLabel *label_2;
    QDockWidget *dockWidget_5;
    QWidget *dockWidgetContents_8;
    QVBoxLayout *verticalLayout_4;
    QFrame *frame;
    QHBoxLayout *horizontalLayout;
    QLabel *label_3;
    QComboBox *name_eimitterType;
    QFrame *name_emitter_type;
    QGroupBox *name_emitterPosition;

    void setupUi(QMainWindow *ParticleEditorWindow)
    {
        if (ParticleEditorWindow->objectName().isEmpty())
            ParticleEditorWindow->setObjectName(QStringLiteral("ParticleEditorWindow"));
        ParticleEditorWindow->resize(1040, 689);
        QSizePolicy sizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(ParticleEditorWindow->sizePolicy().hasHeightForWidth());
        ParticleEditorWindow->setSizePolicy(sizePolicy);
        ParticleEditorWindow->setMinimumSize(QSize(0, 0));
        ParticleEditorWindow->setToolButtonStyle(Qt::ToolButtonTextUnderIcon);
        centralwidget = new QWidget(ParticleEditorWindow);
        centralwidget->setObjectName(QStringLiteral("centralwidget"));
        verticalLayout = new QVBoxLayout(centralwidget);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        name_cocownd = new QWidget(centralwidget);
        name_cocownd->setObjectName(QStringLiteral("name_cocownd"));
        name_cocownd->setMinimumSize(QSize(320, 482));
        name_cocownd->setMaximumSize(QSize(1234789, 16777215));

        verticalLayout->addWidget(name_cocownd);

        tabWidget = new QTabWidget(centralwidget);
        tabWidget->setObjectName(QStringLiteral("tabWidget"));
        tabWidget->setMinimumSize(QSize(0, 150));
        tabWidget->setMaximumSize(QSize(16777215, 150));
        tabWidget->setElideMode(Qt::ElideNone);
        tab = new QWidget();
        tab->setObjectName(QStringLiteral("tab"));
        horizontalLayout_2 = new QHBoxLayout(tab);
        horizontalLayout_2->setObjectName(QStringLiteral("horizontalLayout_2"));
        name_startColor = new QGroupBox(tab);
        name_startColor->setObjectName(QStringLiteral("name_startColor"));
        name_startColor->setMaximumSize(QSize(123465, 300));
        btn_startColor = new QPushButton(name_startColor);
        btn_startColor->setObjectName(QStringLiteral("btn_startColor"));
        btn_startColor->setGeometry(QRect(180, 40, 21, 23));
        btn_startColor->setStyleSheet(QStringLiteral("background-color: rgb(80, 80, 80);"));

        horizontalLayout_2->addWidget(name_startColor);

        name_startColorVar = new QGroupBox(tab);
        name_startColorVar->setObjectName(QStringLiteral("name_startColorVar"));
        name_startColorVar->setMinimumSize(QSize(0, 0));
        name_startColorVar->setMaximumSize(QSize(16777215, 300));

        horizontalLayout_2->addWidget(name_startColorVar);

        tabWidget->addTab(tab, QString());
        tab_2 = new QWidget();
        tab_2->setObjectName(QStringLiteral("tab_2"));
        horizontalLayout_5 = new QHBoxLayout(tab_2);
        horizontalLayout_5->setObjectName(QStringLiteral("horizontalLayout_5"));
        name_endColor = new QGroupBox(tab_2);
        name_endColor->setObjectName(QStringLiteral("name_endColor"));
        name_endColor->setMaximumSize(QSize(123456, 300));
        btn_endColor = new QPushButton(name_endColor);
        btn_endColor->setObjectName(QStringLiteral("btn_endColor"));
        btn_endColor->setGeometry(QRect(180, 40, 21, 23));
        btn_endColor->setStyleSheet(QStringLiteral("background-color: rgb(80, 80, 80);"));

        horizontalLayout_5->addWidget(name_endColor);

        name_endColorVar = new QGroupBox(tab_2);
        name_endColorVar->setObjectName(QStringLiteral("name_endColorVar"));
        name_endColorVar->setMaximumSize(QSize(16777215, 300));

        horizontalLayout_5->addWidget(name_endColorVar);

        tabWidget->addTab(tab_2, QString());
        tab_3 = new QWidget();
        tab_3->setObjectName(QStringLiteral("tab_3"));
        horizontalLayout_4 = new QHBoxLayout(tab_3);
        horizontalLayout_4->setObjectName(QStringLiteral("horizontalLayout_4"));
        name_bgColorVar = new QGroupBox(tab_3);
        name_bgColorVar->setObjectName(QStringLiteral("name_bgColorVar"));
        btn_bgColor = new QPushButton(name_bgColorVar);
        btn_bgColor->setObjectName(QStringLiteral("btn_bgColor"));
        btn_bgColor->setGeometry(QRect(180, 40, 21, 23));
        btn_bgColor->setStyleSheet(QStringLiteral("background-color: rgb(80, 80, 80);"));

        horizontalLayout_4->addWidget(name_bgColorVar);

        groupBox = new QGroupBox(tab_3);
        groupBox->setObjectName(QStringLiteral("groupBox"));
        groupBox->setStyleSheet(QStringLiteral(""));
        groupBox->setFlat(true);
        changeButton = new QPushButton(groupBox);
        changeButton->setObjectName(QStringLiteral("changeButton"));
        changeButton->setGeometry(QRect(100, 20, 71, 23));
        label_bg = new QLabel(groupBox);
        label_bg->setObjectName(QStringLiteral("label_bg"));
        label_bg->setGeometry(QRect(0, 30, 91, 71));
        label_bg->setStyleSheet(QLatin1String("background-color: rgb(179, 179, 179);\n"
"border:2px solid gray;\n"
"border-radius:10px;"));
        label_bg->setAlignment(Qt::AlignCenter);
        removeButton = new QPushButton(groupBox);
        removeButton->setObjectName(QStringLiteral("removeButton"));
        removeButton->setGeometry(QRect(100, 50, 71, 23));
        box_move = new QCheckBox(groupBox);
        box_move->setObjectName(QStringLiteral("box_move"));
        box_move->setGeometry(QRect(130, 80, 71, 16));

        horizontalLayout_4->addWidget(groupBox);

        tabWidget->addTab(tab_3, QString());

        verticalLayout->addWidget(tabWidget);

        ParticleEditorWindow->setCentralWidget(centralwidget);
        dockWidget_2 = new QDockWidget(ParticleEditorWindow);
        dockWidget_2->setObjectName(QStringLiteral("dockWidget_2"));
        dockWidget_2->setMinimumSize(QSize(260, 116));
        dockWidget_2->setFeatures(QDockWidget::DockWidgetFloatable|QDockWidget::DockWidgetMovable);
        dockWidget_2->setAllowedAreas(Qt::AllDockWidgetAreas);
        dockWidgetContents_2 = new QWidget();
        dockWidgetContents_2->setObjectName(QStringLiteral("dockWidgetContents_2"));
        verticalLayout_5 = new QVBoxLayout(dockWidgetContents_2);
        verticalLayout_5->setObjectName(QStringLiteral("verticalLayout_5"));
        name_particleProperties = new QFrame(dockWidgetContents_2);
        name_particleProperties->setObjectName(QStringLiteral("name_particleProperties"));
        name_particleProperties->setFrameShape(QFrame::StyledPanel);
        name_particleProperties->setFrameShadow(QFrame::Raised);

        verticalLayout_5->addWidget(name_particleProperties);

        dockWidget_2->setWidget(dockWidgetContents_2);
        ParticleEditorWindow->addDockWidget(static_cast<Qt::DockWidgetArea>(1), dockWidget_2);
        dockWidget00 = new QDockWidget(ParticleEditorWindow);
        dockWidget00->setObjectName(QStringLiteral("dockWidget00"));
        dockWidget00->setMinimumSize(QSize(131, 130));
        dockWidget00->setMaximumSize(QSize(524287, 130));
        dockWidget00->setFeatures(QDockWidget::DockWidgetFloatable|QDockWidget::DockWidgetMovable);
        dockWidgetContents_5 = new QWidget();
        dockWidgetContents_5->setObjectName(QStringLiteral("dockWidgetContents_5"));
        frame_2 = new QFrame(dockWidgetContents_5);
        frame_2->setObjectName(QStringLiteral("frame_2"));
        frame_2->setGeometry(QRect(70, 10, 101, 91));
        frame_2->setMaximumSize(QSize(128, 128));
        frame_2->setStyleSheet(QLatin1String("background-color: rgb(179, 179, 179);\n"
"border:2px solid gray;\n"
"border-radius:10px;"));
        frame_2->setFrameShape(QFrame::Panel);
        frame_2->setFrameShadow(QFrame::Sunken);
        horizontalLayout_3 = new QHBoxLayout(frame_2);
        horizontalLayout_3->setObjectName(QStringLiteral("horizontalLayout_3"));
        name_textureImage = new QLabel(frame_2);
        name_textureImage->setObjectName(QStringLiteral("name_textureImage"));
        name_textureImage->setMinimumSize(QSize(0, 0));
        name_textureImage->setMaximumSize(QSize(64, 64));
        name_textureImage->setStyleSheet(QStringLiteral("background-color: rgb(80, 80, 80);"));
        name_textureImage->setFrameShape(QFrame::NoFrame);
        name_textureImage->setFrameShadow(QFrame::Raised);
        name_textureImage->setAlignment(Qt::AlignCenter);

        horizontalLayout_3->addWidget(name_textureImage);

        pushButton = new QPushButton(dockWidgetContents_5);
        pushButton->setObjectName(QStringLiteral("pushButton"));
        pushButton->setGeometry(QRect(180, 80, 20, 21));
        pushButton->setMaximumSize(QSize(20, 16777215));
        pushButton->setStyleSheet(QLatin1String("\n"
" QPushButton {\n"
"	border:2px solid gray;\n"
"     border-radius: 10px;\n"
"\n"
"\n"
" }\n"
" QPushButton:pressed {\n"
"     border:2px solid black;\n"
" }"));
        dockWidget00->setWidget(dockWidgetContents_5);
        ParticleEditorWindow->addDockWidget(static_cast<Qt::DockWidgetArea>(2), dockWidget00);
        dockWidget_7 = new QDockWidget(ParticleEditorWindow);
        dockWidget_7->setObjectName(QStringLiteral("dockWidget_7"));
        dockWidget_7->setMinimumSize(QSize(280, 95));
        dockWidget_7->setMaximumSize(QSize(524287, 95));
        dockWidget_7->setFeatures(QDockWidget::DockWidgetFloatable|QDockWidget::DockWidgetMovable);
        dockWidgetContents_7 = new QWidget();
        dockWidgetContents_7->setObjectName(QStringLiteral("dockWidgetContents_7"));
        gridLayout_2 = new QGridLayout(dockWidgetContents_7);
        gridLayout_2->setObjectName(QStringLiteral("gridLayout_2"));
        name_blendFunc = new QFrame(dockWidgetContents_7);
        name_blendFunc->setObjectName(QStringLiteral("name_blendFunc"));
        name_blendFunc->setMaximumSize(QSize(16777215, 80));
        gridLayout_3 = new QGridLayout(name_blendFunc);
        gridLayout_3->setObjectName(QStringLiteral("gridLayout_3"));
        gridLayout_3->setHorizontalSpacing(2);
        gridLayout_3->setVerticalSpacing(0);
        gridLayout_3->setContentsMargins(0, 0, 0, 0);
        name_blendsrc = new QComboBox(name_blendFunc);
        name_blendsrc->setObjectName(QStringLiteral("name_blendsrc"));

        gridLayout_3->addWidget(name_blendsrc, 0, 1, 1, 1);

        name_blendNormal = new QPushButton(name_blendFunc);
        name_blendNormal->setObjectName(QStringLiteral("name_blendNormal"));
        name_blendNormal->setMaximumSize(QSize(60, 123465));

        gridLayout_3->addWidget(name_blendNormal, 0, 2, 1, 1);

        name_blendAdditive = new QPushButton(name_blendFunc);
        name_blendAdditive->setObjectName(QStringLiteral("name_blendAdditive"));
        name_blendAdditive->setMaximumSize(QSize(60, 16777215));

        gridLayout_3->addWidget(name_blendAdditive, 1, 2, 1, 1);

        name_blenddst = new QComboBox(name_blendFunc);
        name_blenddst->setObjectName(QStringLiteral("name_blenddst"));

        gridLayout_3->addWidget(name_blenddst, 1, 1, 1, 1);

        label = new QLabel(name_blendFunc);
        label->setObjectName(QStringLiteral("label"));

        gridLayout_3->addWidget(label, 0, 0, 1, 1);

        label_2 = new QLabel(name_blendFunc);
        label_2->setObjectName(QStringLiteral("label_2"));
        label_2->setMaximumSize(QSize(30, 16777215));

        gridLayout_3->addWidget(label_2, 1, 0, 1, 1);


        gridLayout_2->addWidget(name_blendFunc, 0, 0, 1, 1);

        dockWidget_7->setWidget(dockWidgetContents_7);
        ParticleEditorWindow->addDockWidget(static_cast<Qt::DockWidgetArea>(1), dockWidget_7);
        dockWidget_5 = new QDockWidget(ParticleEditorWindow);
        dockWidget_5->setObjectName(QStringLiteral("dockWidget_5"));
        dockWidget_5->setMinimumSize(QSize(250, 158));
        dockWidget_5->setFeatures(QDockWidget::DockWidgetFloatable|QDockWidget::DockWidgetMovable);
        dockWidgetContents_8 = new QWidget();
        dockWidgetContents_8->setObjectName(QStringLiteral("dockWidgetContents_8"));
        verticalLayout_4 = new QVBoxLayout(dockWidgetContents_8);
        verticalLayout_4->setObjectName(QStringLiteral("verticalLayout_4"));
        frame = new QFrame(dockWidgetContents_8);
        frame->setObjectName(QStringLiteral("frame"));
        frame->setMaximumSize(QSize(16777215, 30));
        frame->setFrameShape(QFrame::StyledPanel);
        frame->setFrameShadow(QFrame::Sunken);
        horizontalLayout = new QHBoxLayout(frame);
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        horizontalLayout->setContentsMargins(-1, 0, -1, 0);
        label_3 = new QLabel(frame);
        label_3->setObjectName(QStringLiteral("label_3"));

        horizontalLayout->addWidget(label_3);

        name_eimitterType = new QComboBox(frame);
        name_eimitterType->setObjectName(QStringLiteral("name_eimitterType"));

        horizontalLayout->addWidget(name_eimitterType);


        verticalLayout_4->addWidget(frame);

        name_emitter_type = new QFrame(dockWidgetContents_8);
        name_emitter_type->setObjectName(QStringLiteral("name_emitter_type"));
        name_emitter_type->setFrameShape(QFrame::NoFrame);
        name_emitter_type->setFrameShadow(QFrame::Plain);

        verticalLayout_4->addWidget(name_emitter_type);

        name_emitterPosition = new QGroupBox(dockWidgetContents_8);
        name_emitterPosition->setObjectName(QStringLiteral("name_emitterPosition"));
        name_emitterPosition->setMaximumSize(QSize(16777215, 140));

        verticalLayout_4->addWidget(name_emitterPosition);

        dockWidget_5->setWidget(dockWidgetContents_8);
        ParticleEditorWindow->addDockWidget(static_cast<Qt::DockWidgetArea>(2), dockWidget_5);

        retranslateUi(ParticleEditorWindow);

        tabWidget->setCurrentIndex(2);


        QMetaObject::connectSlotsByName(ParticleEditorWindow);
    } // setupUi

    void retranslateUi(QMainWindow *ParticleEditorWindow)
    {
        ParticleEditorWindow->setWindowTitle(QApplication::translate("ParticleEditorWindow", "MainWindow", 0));
        name_startColor->setTitle(QApplication::translate("ParticleEditorWindow", "Start Color", 0));
        btn_startColor->setText(QString());
        name_startColorVar->setTitle(QApplication::translate("ParticleEditorWindow", "Start Color Var", 0));
        tabWidget->setTabText(tabWidget->indexOf(tab), QApplication::translate("ParticleEditorWindow", "Start Color", 0));
        name_endColor->setTitle(QApplication::translate("ParticleEditorWindow", "End Color", 0));
        btn_endColor->setText(QString());
        name_endColorVar->setTitle(QApplication::translate("ParticleEditorWindow", "End Color Var", 0));
        tabWidget->setTabText(tabWidget->indexOf(tab_2), QApplication::translate("ParticleEditorWindow", "End Color", 0));
        name_bgColorVar->setTitle(QApplication::translate("ParticleEditorWindow", "Background Color", 0));
        btn_bgColor->setText(QString());
        groupBox->setTitle(QApplication::translate("ParticleEditorWindow", "Background Image", 0));
        changeButton->setText(QApplication::translate("ParticleEditorWindow", "Change", 0));
        label_bg->setText(QString());
        removeButton->setText(QApplication::translate("ParticleEditorWindow", "Hide/Show", 0));
        box_move->setText(QApplication::translate("ParticleEditorWindow", "Move", 0));
        tabWidget->setTabText(tabWidget->indexOf(tab_3), QApplication::translate("ParticleEditorWindow", "Background", 0));
        dockWidget_2->setWindowTitle(QApplication::translate("ParticleEditorWindow", "Particle Properties", 0));
        dockWidget00->setWindowTitle(QApplication::translate("ParticleEditorWindow", "Particle Texture", 0));
        name_textureImage->setText(QString());
        pushButton->setText(QApplication::translate("ParticleEditorWindow", "...", 0));
        dockWidget_7->setWindowTitle(QApplication::translate("ParticleEditorWindow", "Blend Function", 0));
        name_blendsrc->clear();
        name_blendsrc->insertItems(0, QStringList()
         << QApplication::translate("ParticleEditorWindow", "GL_ZERO", 0)
         << QApplication::translate("ParticleEditorWindow", "GL_ONE", 0)
         << QApplication::translate("ParticleEditorWindow", "GL_SRC_COLOR", 0)
         << QApplication::translate("ParticleEditorWindow", "GL_ONE_MINUS_SRC_COLOR", 0)
         << QApplication::translate("ParticleEditorWindow", "GL_SRC_ALPHA", 0)
         << QApplication::translate("ParticleEditorWindow", "GL_ONE_MINUS_SRC_ALPHA", 0)
         << QApplication::translate("ParticleEditorWindow", "GL_DST_COLOR", 0)
         << QApplication::translate("ParticleEditorWindow", "GL_ONE_MINUS_DST_COLOR", 0)
         << QApplication::translate("ParticleEditorWindow", "GL_DST_ALPHA", 0)
         << QApplication::translate("ParticleEditorWindow", "GL_ONE_MINUS_DST_ALPHA", 0)
         << QApplication::translate("ParticleEditorWindow", "GL_SRC_ALPHA_SATURATE", 0)
        );
        name_blendNormal->setText(QApplication::translate("ParticleEditorWindow", "Normal", 0));
        name_blendAdditive->setText(QApplication::translate("ParticleEditorWindow", "Additive", 0));
        name_blenddst->clear();
        name_blenddst->insertItems(0, QStringList()
         << QApplication::translate("ParticleEditorWindow", "GL_ZERO", 0)
         << QApplication::translate("ParticleEditorWindow", "GL_ONE", 0)
         << QApplication::translate("ParticleEditorWindow", "GL_SRC_COLOR", 0)
         << QApplication::translate("ParticleEditorWindow", "GL_ONE_MINUS_SRC_COLOR", 0)
         << QApplication::translate("ParticleEditorWindow", "GL_SRC_ALPHA", 0)
         << QApplication::translate("ParticleEditorWindow", "GL_ONE_MINUS_SRC_ALPHA", 0)
         << QApplication::translate("ParticleEditorWindow", "GL_DST_COLOR", 0)
         << QApplication::translate("ParticleEditorWindow", "GL_ONE_MINUS_DST_COLOR", 0)
         << QApplication::translate("ParticleEditorWindow", "GL_DST_ALPHA", 0)
         << QApplication::translate("ParticleEditorWindow", "GL_ONE_MINUS_DST_ALPHA", 0)
         << QApplication::translate("ParticleEditorWindow", "GL_SRC_ALPHA_SATURATE", 0)
        );
        label->setText(QApplication::translate("ParticleEditorWindow", "Src", 0));
        label_2->setText(QApplication::translate("ParticleEditorWindow", "Dst:", 0));
        dockWidget_5->setWindowTitle(QApplication::translate("ParticleEditorWindow", "Particle Emitter Properties", 0));
        label_3->setText(QApplication::translate("ParticleEditorWindow", "Emitter Type", 0));
        name_eimitterType->clear();
        name_eimitterType->insertItems(0, QStringList()
         << QApplication::translate("ParticleEditorWindow", "Gravity", 0)
         << QApplication::translate("ParticleEditorWindow", "Radial", 0)
        );
        name_emitterPosition->setTitle(QString());
    } // retranslateUi

};

namespace Ui {
    class ParticleEditorWindow: public Ui_ParticleEditorWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_PARTICLEEDITORWINDOW_H
