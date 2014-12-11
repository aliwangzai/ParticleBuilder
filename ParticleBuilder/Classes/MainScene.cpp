#include "MainScene.h"
#include "qdebug.h"
#include "AppDelegate.h"
#include "entitymanager.h"
#include "qpropertylineeditorfactory.h"
#include "ParticleProperties.h"
USING_NS_CC;
static MainScene * s_pMainScene;


CCScene* MainScene::createScene()
{
	Scene *scene = Scene::create();
	MainScene *layer = MainScene::create();
	layer->setTag(100);
	scene->addChild(layer);
	return scene;
}


MainScene::MainScene()
{
	s_pMainScene = this ;
	_emitter = NULL;
	_mainwindow = new ParticleEditorWindow;
	_canMoveBg = false;
}

ParticleEditorWindow * MainScene::getMainWindow()
{
	return _mainwindow;
}

void MainScene::initPs( std::string & filePath )
{
	if (_emitter != NULL)
		_emitter->removeFromParentAndCleanup(true);
	_emitter = ParticleSystemQuad::create(filePath);
	_emitter->setPosition(220,400);
	addChild(_emitter);
}

void MainScene::resetPs( ValueMap & dict , double maxparticles )
{
	Point oldP = _emitter->getPosition();
	dict[pnameof(PP::maxParticles)] = maxparticles;
	_emitter->removeFromParentAndCleanup(true);
	_emitter = ParticleSystemQuad::create(dict);
	_emitter->setPosition(oldP);
	addChild(_emitter);
}

void MainScene::changeBg( std::string & filePath )
{
	_bg->setVisible(true);
	Texture2D * tex = TextureCache::getInstance()->addImage(filePath);
	_bg->setTexture(tex);
	Size size = tex->getContentSize();
	_bg->setTextureRect(Rect(0,0,size.width,size.height) );

}

void MainScene::removeBg()
{
	_bg->setVisible(false);
}



void MainScene::onEnter()
{
	LayerColor::onEnter();

	//_emitter->setPosition(200,200);
	//_window.readplist("example/Galaxy.plist");
	//NotificationCenter::getInstance()->postNotification("MainSceneCreated");
	_mainwindow->openExample("example/Galaxy.plist");
}

MainScene * MainScene::getInstance()
{
	return s_pMainScene;
}


void MainScene::addTouchSupport()
{
	auto _listener = EventListenerTouchOneByOne::create();
	_listener->onTouchBegan = CC_CALLBACK_2(MainScene::touchBegan, this);
	_listener->onTouchMoved = CC_CALLBACK_2(MainScene::touchMoved, this);
	_listener->onTouchEnded = CC_CALLBACK_2(MainScene::touchEnded, this);
	_eventDispatcher->addEventListenerWithSceneGraphPriority(_listener , this);
}


// on "init" you need to initialize your instance
bool MainScene::init()
{
	LayerColor::initWithColor(Color4B::BLACK);

	_bg = Sprite::create();
	_bg->setPosition(220,400);
	_bg->setVisible(false);
	addChild(_bg);

	addTouchSupport();
	return true;
}


bool MainScene::touchBegan(Touch* touch , Event* event)
{
	if (_canMoveBg)
	{
		return true;
	}
    CCParticleSystem * particle = _emitter;	
    Point p = touch->getLocation();
    if (particle->getEmitterMode() == ParticleSystem::Mode::GRAVITY) 
    {
        particle->setPosition(p);
        //QPropertyLineEditorFactory * factory = (QPropertyLineEditorFactory*)(EntityManager::get(EntityManager::ID_line_editor_factory));
        //factory->Property(PP::sourcePositionx)->setValue(particle->getPosition().x);
        //factory->Property(PP::sourcePositiony)->setValue(particle->getPosition().y);
    }
    else 
    {
        particle->setPosition(p);
        //QPropertyLineEditorFactory * factory = (QPropertyLineEditorFactory*)(EntityManager::get(EntityManager::ID_line_editor_factory));
        //factory->Property(PP::sourcePositionx)->setValue(particle->getPosition().x);
        //factory->Property(PP::sourcePositiony)->setValue(particle->getPosition().y);
    }
    return true;
}

void MainScene::touchMoved(Touch* touch , Event* )
{
    CCPoint p = touch->getLocation();
    CCPoint plast = touch->getPreviousLocation();
    CCPoint p_vector = p - plast;
	if (_canMoveBg && _bg->isVisible())
	{
		_bg->setPosition(_bg->getPosition() + p_vector);
		return ;
	}
	CCParticleSystem * particle = _emitter;	
    if (particle->getEmitterMode() == ParticleSystem::Mode::GRAVITY) 
    {
        //particle->setPosition(ccpAdd(p_vector , particle->getSourcePosition()));
		particle->setPosition(p);
        //QPropertyLineEditorFactory * factory = (QPropertyLineEditorFactory*)(EntityManager::get(EntityManager::ID_line_editor_factory));
        //factory->Property(PP::sourcePositionx)->setValue(particle->getPosition().x);
        //factory->Property(PP::sourcePositiony)->setValue(particle->getPosition().y);
    }
    else 
    {
        particle->setPosition(ccpAdd(p_vector , particle->getPosition()));
        //QPropertyLineEditorFactory * factory = (QPropertyLineEditorFactory*)(EntityManager::get(EntityManager::ID_line_editor_factory));
        //factory->Property(PP::sourcePositionx)->setValue(particle->getPosition().x);
        //factory->Property(PP::sourcePositiony)->setValue(particle->getPosition().y);
    }

}

void MainScene::touchEnded(Touch*, Event* )
{


}

void MainScene::toggleHidden()
{
	_bg->setVisible(!_bg->isVisible());
}

void MainScene::toggleMove(bool b )
{
	_canMoveBg = b;
}
