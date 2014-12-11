/********************************************************************************
** Form generated from reading UI file 'testqtcocos.ui'
**
** Created by: Qt User Interface Compiler version 5.3.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_TESTQTCOCOS_H
#define UI_TESTQTCOCOS_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QDockWidget>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenu>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_CCGEditor
{
public:
    QWidget *centralWidget;
    QMenuBar *menuBar;
    QMenu *menuAbout;
    QToolBar *mainToolBar;
    QStatusBar *statusBar;
    QDockWidget *cocos2dwindow;
    QWidget *dockWidgetContents;

    void setupUi(QMainWindow *CCGEditor)
    {
        if (CCGEditor->objectName().isEmpty())
            CCGEditor->setObjectName(QStringLiteral("CCGEditor"));
        CCGEditor->resize(600, 400);
        centralWidget = new QWidget(CCGEditor);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        CCGEditor->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(CCGEditor);
        menuBar->setObjectName(QStringLiteral("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 600, 23));
        menuAbout = new QMenu(menuBar);
        menuAbout->setObjectName(QStringLiteral("menuAbout"));
        CCGEditor->setMenuBar(menuBar);
        mainToolBar = new QToolBar(CCGEditor);
        mainToolBar->setObjectName(QStringLiteral("mainToolBar"));
        CCGEditor->addToolBar(Qt::TopToolBarArea, mainToolBar);
        statusBar = new QStatusBar(CCGEditor);
        statusBar->setObjectName(QStringLiteral("statusBar"));
        CCGEditor->setStatusBar(statusBar);
        cocos2dwindow = new QDockWidget(CCGEditor);
        cocos2dwindow->setObjectName(QStringLiteral("cocos2dwindow"));
        dockWidgetContents = new QWidget();
        dockWidgetContents->setObjectName(QStringLiteral("dockWidgetContents"));
        cocos2dwindow->setWidget(dockWidgetContents);
        CCGEditor->addDockWidget(static_cast<Qt::DockWidgetArea>(1), cocos2dwindow);

        menuBar->addAction(menuAbout->menuAction());

        retranslateUi(CCGEditor);

        QMetaObject::connectSlotsByName(CCGEditor);
    } // setupUi

    void retranslateUi(QMainWindow *CCGEditor)
    {
        CCGEditor->setWindowTitle(QApplication::translate("CCGEditor", "testqtcocos", 0));
        menuAbout->setTitle(QApplication::translate("CCGEditor", "about", 0));
    } // retranslateUi

};

namespace Ui {
    class CCGEditor: public Ui_CCGEditor {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_TESTQTCOCOS_H
