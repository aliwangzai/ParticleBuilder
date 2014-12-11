#include "ccgeditor.h"
#include "Classes/AppDelegate.h"
#include "Classes/CCQGLView.h"

#include <QTimer>
#include <QDockWidget>

#include "testqtcocos.h"
#include "ui_testqtcocos.h"


CCGEditor::CCGEditor(QWidget *parent)
	: QMainWindow(parent),
	_appDelegate(NULL),
	_glWidget(NULL),
	ui(new Ui::CCGEditor)
{
	ui->setupUi(this);
}

CCGEditor::~CCGEditor()
{

}

void CCGEditor::closeEvent(QCloseEvent *)
{
	cocos2d::Director::getInstance()->end();
	qApp->quit();
}

void CCGEditor::setGLView(QWidget *glWidget)
{
	_glWidget = glWidget;

	if (_glWidget)
	{
		ui->cocos2dwindow->setWidget(_glWidget);
		//ui.SceneWidget->setWidget(_glWidget);
		setCentralWidget(ui->cocos2dwindow);
	}
}