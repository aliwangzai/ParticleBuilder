#ifndef CCGEDITOR_H
#define CCGEDITOR_H

#include <QtWidgets/QMainWindow>
#include "Classes/CCGEditor.h"

class AppDelegate;
namespace Ui {
	class CCGEditor;
}

class CCGEditor : public QMainWindow
{
	Q_OBJECT

public:
	CCGEditor(QWidget *parent = 0);
	~CCGEditor();

	void setGLView(QWidget *glWidget);

protected:
	void closeEvent(QCloseEvent *);

private:
	Ui::CCGEditor * ui;
	AppDelegate         *_appDelegate;
	QWidget             *_glWidget;
};

#endif // CCGEDITOR_H