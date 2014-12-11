#ifndef CCPARTICLESYSTEM_EXT_H
#define CCPARTICLESYSTEM_EXT_H
#include "cocos2d.h"
#include "QDebug"
#include "ParticleProperties.h"
using namespace cocos2d;

class CCParticleSystem_Ext : public CCNode
{
public:
    CCParticleSystem *last;
    CCParticleSystem * m_current;

    void reloadParticle(QString pngPath , CCDictionary<std::string ,CCObject*> *  dict ,int maxParticles)
    {
        last = m_current;
		last->stopSystem();
        CCFileUtils::setResourcePath(pngPath.toLocal8Bit());
		m_current  = new CCParticleSystemQuad();
        m_current->initWithDictionary(dict);
        m_current->setTexture(last->getTexture());
        m_current->autorelease(); 
        if (m_current->getEmitterMode() == 0)
        {
            CCPoint sourcePos = m_current->getPosition(); 
            m_current->setPosition(ccp(0,0));
            m_current->setSourcePosition(sourcePos);
        }
		this->addChild(m_current);
        this->setPosition(ccp(0,0));
        
    }
    
    
    void loadNewPList(QString file , int maxParticles)
    {
        last = m_current;
		last->stopSystem();
        last->setIsVisible(false);
        newParticle(file , maxParticles);
    }

	void newParticle(QString file , int maxParticles)
	{
        //CCFileUtils::setResourcePath(QFileInfo(file).dir().path().toLocal8Bit());
		m_current  = new CCParticleSystemQuad();
		if (maxParticles == -1)
		{
            m_current->initWithFile(QFileInfo(file).fileName().toLocal8Bit());
        }else 
        {
            //CCDictionary<std::string, CCObject*> *dict = CCFileUtils::dictionaryWithContentsOfFileThreadSafe(file.toLocal8Bit()); 
			CCDictionary<std::string, CCObject*> *dict = CCFileUtils::dictionaryWithContentsOfFileThreadSafe(file.toLocal8Bit()); 
            QString s = QString::number(maxParticles);
            CCString s_max(s.toLocal8Bit());
			dict->removeObjectForKey(std::string(pnameof(PP::maxParticles).toLocal8Bit()));
            dict->setObject( &s_max,  std::string(pnameof(PP::maxParticles).toLocal8Bit()));
            m_current->initWithDictionary(dict);
			dict->release();
        }
        if (m_current->getEmitterMode() == 0)
        {
            CCPoint sourcePos = m_current->getPosition(); 
            m_current->setPosition(ccp(0,0));
            m_current->setSourcePosition(sourcePos);
            qDebug()<< sourcePos.x <<"/" <<sourcePos.y;
        }else if (m_current->getEmitterMode() ==1)
        {
            m_current->setPositionType(kCCPositionTypeGrouped);
//            m_current->setPosition(m_current->getSourcePosition());
            CCPoint sourcePos = m_current->getPosition(); 
            m_current->setSourcePosition(sourcePos);
            qDebug() <<"type 2 :" << sourcePos.x <<"/" <<sourcePos.y;
        }
        m_current->autorelease(); 

		this->addChild(m_current);
        
	}

    CCParticleSystem_Ext(QString file , int maxParticles)
    {
		newParticle(file , maxParticles);
        this->autorelease();
    }
    CCParticleSystem_Ext();
};

#endif // CCPARTICLESYSTEM_EXT_H
