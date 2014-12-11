#ifndef __HELLOWORLD_SCENE_H__
#define __HELLOWORLD_SCENE_H__

#include "cocos2d.h"
using namespace cocos2d;

class ParticleEditorWindow;
class MainScene : public cocos2d::LayerColor
{
	ParticleSystem * _emitter;
	ParticleEditorWindow *  _mainwindow;
	Sprite * _bg;
	bool _canMoveBg;
public:
	ParticleSystem * getPs(){return _emitter;} 
	MainScene();
	static MainScene * getInstance();
	virtual bool init();  
	static cocos2d::CCScene* createScene();
    bool touchBegan(Touch*, Event* );
    void touchMoved(Touch*, Event* );
    void touchEnded(Touch*, Event* );
    CREATE_FUNC(MainScene);
	void addTouchSupport();
	void onEnter();
	void initPs( std::string & filePath );
	void resetPs( ValueMap & dict , double maxparticles );
	ParticleEditorWindow * getMainWindow();
	void changeBg( std::string &  filePath );
	void removeBg();
	void toggleHidden();
	void toggleMove(bool);
};

#endif // __HELLOWORLD_SCENE_H__
