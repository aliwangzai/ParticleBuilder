#include <QtWidgets/QApplication>
#include "Classes/AppDelegate.h"
#include "Classes/CCQApplication.h"

int main(int argc, char *argv[])
{
	AppDelegate app(argc , argv);
	return cocos2d::CCQApplication::getInstance()->run();
}
