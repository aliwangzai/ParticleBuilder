#ifndef PARTICLEPROPERTIES_H
#define PARTICLEPROPERTIES_H


#include "QtCore"

#define nameof(id) PP::instance()->getParticleProp(id)->realName

#define pnameof(id) PP::instance()->getParticleProp(id)->pname.toStdString()

#define typof(id) PP::instance()->getParticleProp(id)->type

#define p_min(id) PP::instance()->getParticleProp(id)->min

#define p_max(id) PP::instance()->getParticleProp(id)->max

#define p_blendFucNameOfVal(val) PP::instance()->getTextByValue(val)

#define p_blendFucValOfName(val) PP::instance()->getValByText(val)
class PP
{

public:
    enum propertyEnum
    {
        angle = 0  ,
        angleVariance ,
        duration,
        emitterType,
        startParticleSize,
        startParticleSizeVariance,
        finishParticleSize,
        finishParticleSizeVariance,
        gravityx,
        gravityy,
        maxParticles,
        maxRadius,
        maxRadiusVariance,
        minRadius,
        particleLifespan,
        particleLifespanVariance,
        rotatePerSecond,
        rotatePerSecondVariance,
        rotationEnd,
        rotationEndVariance,
        rotationStart,
        rotationStartVariance,
        sourcePositionVariancex,
        sourcePositionVariancey,
        sourcePositionx,
        sourcePositiony,
        speed,
        speedVariance,
        startColorAlpha,
        startColorBlue,
        startColorGreen,
        startColorRed,
        startColorVarianceAlpha,
        startColorVarianceBlue,
        startColorVarianceGreen,
        startColorVarianceRed,
        finishColorAlpha,
        finishColorBlue,
        finishColorGreen,
        finishColorRed,
        finishColorVarianceAlpha,
        finishColorVarianceBlue,
        finishColorVarianceGreen,
        finishColorVarianceRed,
        tangentialAccelVariance,
        tangentialAcceleration,
        radialAccelVariance,
        radialAcceleration,
        
        textureFileName,
        blendFuncDestination ,
        blendFuncSource ,
        
        bg_color_r,
        bg_color_g,
        bg_color_b,
        bg_color_a,
        
        count = 50
    };
    
    struct sParticle
    {
        int id;
        QString pname;
        QString realName;
        int type;
        float min;
        float max;
        
        sParticle(int id, QString pname , QString realName , int type ,float min , float max)
        {
            this->id=  id;
            this->pname=  pname;
            this->realName = realName;
            this->type = type;
            this->min = min;
            this->max = max;
        }
    };
    
    QList<sParticle> m_particleP;

	static bool m_isInit;


	QStringList m_blend_strList;
	QVector<int> m_blend_val;

    void init()
    {
        m_particleP.push_back(sParticle(sourcePositionVariancex, "sourcePositionVariancex", "Variance X", QVariant::Double,-480, 480));             
        m_particleP.push_back(sParticle(sourcePositionVariancey,  "sourcePositionVariancey",  "Variance Y",  QVariant::Double,-480, 480));                 
        m_particleP.push_back(sParticle(sourcePositionx,      "sourcePositionx",      "Position X",      QVariant::Double,-480, 480));                                 
        m_particleP.push_back(sParticle(sourcePositiony,   "sourcePositiony",   "Position Y",   QVariant::Double,-480, 480));                               
        m_particleP.push_back(sParticle(angle , "angle", "Angle", QVariant::Double ,0, 360));                                 
        m_particleP.push_back(sParticle(angleVariance , "angleVariance", "Angle Var", QVariant::Double ,0, 360));                            
        m_particleP.push_back(sParticle(duration, "duration", "Duration", QVariant::Double,-1, 10));                                       
        m_particleP.push_back(sParticle(startParticleSize, "startParticleSize", "Start Size", QVariant::Double,0, 300));                                  
        m_particleP.push_back(sParticle(startParticleSizeVariance,  "startParticleSizeVariance",  "Star Size Var",QVariant::Double,0, 300)); 
        m_particleP.push_back(sParticle(finishParticleSize, "finishParticleSize", "Finish Size", QVariant::Double,0, 300));                                
        m_particleP.push_back(sParticle(finishParticleSizeVariance,"finishParticleSizeVariance","Finish Size Var",QVariant::Double,0, 300)); 
        m_particleP.push_back(sParticle(gravityx, "gravityx", "Gravity x", QVariant::Double,-1000, 1000));                                    
        m_particleP.push_back(sParticle(gravityy,"gravityy","Gravity y",QVariant::Double,-1000, 1000));                                     
        m_particleP.push_back(sParticle(maxParticles, "maxParticles" , "Max Particles", QVariant::Double  ,0 , 2000));                                     
        m_particleP.push_back(sParticle(maxRadius   ,  "maxRadius"   ,  "Max Radius",  QVariant::Double,0, 360));                                         
        m_particleP.push_back(sParticle(maxRadiusVariance, "maxRadiusVariance", "Max Radius Variance", QVariant::Double,0, 360));                                   
        m_particleP.push_back(sParticle(minRadius, "minRadius", "Min Radius", QVariant::Double,0, 360));                             
        m_particleP.push_back(sParticle(particleLifespan,"particleLifespan","Particle Lifespan",QVariant::Double,0, 10));                      
        m_particleP.push_back(sParticle(particleLifespanVariance,"particleLifespanVariance","Lifespan Variance",QVariant::Double ,0 , 10));        
        m_particleP.push_back(sParticle(rotatePerSecond, "rotatePerSecond", "Rotate Per Second", QVariant::Double,0, 360));                                      
        m_particleP.push_back(sParticle(rotatePerSecondVariance,"rotatePerSecondVariance","Rotate PerSecondVariance", QVariant::Double,0, 360));       
        m_particleP.push_back(sParticle(rotationEnd,"rotationEnd","Rotation End",QVariant::Double ,0, 360));                                    
        m_particleP.push_back(sParticle(rotationEndVariance,  "rotationEndVariance",  "Rotation End Variance",QVariant::Double ,0, 360));               
        m_particleP.push_back(sParticle(rotationStart,    "rotationStart",    "Rotation Start",    QVariant::Double ,0, 360));                                        
        m_particleP.push_back(sParticle(rotationStartVariance,  "rotationStartVariance",  "Rotation Start Variance", QVariant::Double ,0, 360));        
                                         
        m_particleP.push_back(sParticle(speed,     "speed" ,"Speed",     QVariant::Double,0, 1000));                                   
        m_particleP.push_back(sParticle(speedVariance,   "speedVariance",   "Speed Variance",   QVariant::Double,0, 1000));                                
        m_particleP.push_back(sParticle(tangentialAccelVariance, "tangentialAccelVariance", "Tangential Accel Variance",   QVariant::Double ,0, 1000));     
        m_particleP.push_back(sParticle(tangentialAcceleration, "tangentialAcceleration", "Tangential Acceleration",   QVariant::Double ,0, 1000));        
        m_particleP.push_back(sParticle(radialAccelVariance,  "radialAccelVariance",  "Radial Accel Variance",   QVariant::Double ,0, 1000));                
        m_particleP.push_back(sParticle(radialAcceleration, "radialAcceleration", "Radial Acceleration", QVariant::Double ,0, 1000));          
        
        m_particleP.push_back(sParticle(startColorAlpha,   "startColorAlpha" ,  "Alpha",   QVariant::Color  ,0,255));                      
        m_particleP.push_back(sParticle(startColorBlue,   "startColorBlue"   , "Blue",   QVariant::Color ,0,255));                      
        m_particleP.push_back(sParticle(startColorGreen, "startColorGreen"   ,"Green", QVariant::Color ,0,255));                         
        m_particleP.push_back(sParticle(startColorRed,  "startColorRed"      , "Red",  QVariant::Color ,0,255));                             
        m_particleP.push_back(sParticle(startColorVarianceAlpha,  "startColorVarianceAlpha",  "Alpha",  QVariant::Color ,0,255));             
        m_particleP.push_back(sParticle(startColorVarianceBlue,  "startColorVarianceBlue"   ,"Blue",  QVariant::Color ,0,255));                
        m_particleP.push_back(sParticle(startColorVarianceGreen, "startColorVarianceGreen" , "Green", QVariant::Color ,0,255));               
        m_particleP.push_back(sParticle(startColorVarianceRed,  "startColorVarianceRed"   , "Red",  QVariant::Color ,0,255));                   
        m_particleP.push_back(sParticle(finishColorAlpha,    "finishColorAlpha",  "Alpha",    QVariant::Color ,0,255));                   
        m_particleP.push_back(sParticle(finishColorBlue,    "finishColorBlue"   ,"Blue",    QVariant::Color ,0,255));                      
        m_particleP.push_back(sParticle(finishColorGreen,    "finishColorGreen" , "Green",    QVariant::Color ,0,255));                   
        m_particleP.push_back(sParticle(finishColorRed,      "finishColorRed"   , "Red",      QVariant::Color ,0,255));                     
        m_particleP.push_back(sParticle(finishColorVarianceAlpha,  "finishColorVarianceAlpha" ,  "Alpha",  QVariant::Color ,0,255));               
        m_particleP.push_back(sParticle(finishColorVarianceBlue,   "finishColorVarianceBlue"  ,   "Blue",   QVariant::Color ,0,255));                 
        m_particleP.push_back(sParticle(finishColorVarianceGreen, "finishColorVarianceGreen"  , "Green", QVariant::Color ,0,255));                 
        m_particleP.push_back(sParticle(finishColorVarianceRed,  "finishColorVarianceRed"  ,    "Red",  QVariant::Color ,0,255));        
        
        m_particleP.push_back(sParticle(emitterType, "emitterType", "Emitter Type", QVariant::Double,0,1));  
        m_particleP.push_back(sParticle(textureFileName,     "textureFileName"      ,  "textureFileName",     QVariant::String ,0, 1));                                 
        m_particleP.push_back(sParticle(blendFuncDestination , "blendFuncDestination" , "blendFuncDestination", QVariant::Double ,0, 1));           
        m_particleP.push_back(sParticle(blendFuncSource , "blendFuncSource"         ,   "blendFuncSource" , QVariant::Double,0, 1));                

        m_particleP.push_back(sParticle(bg_color_r , "Bg_Red"         ,   "Red" , QVariant::Color,0,255));            
        m_particleP.push_back(sParticle(bg_color_g , "Bg_Green"         ,   "Green" , QVariant::Color,0,255));               
        m_particleP.push_back(sParticle(bg_color_b , "Bg_Blue"         ,   "Blue" , QVariant::Color,0,255));             
        m_particleP.push_back(sParticle(bg_color_a , "Bg_Alpha"         ,   "Alpha" , QVariant::Color,0,255));                

        
        
        
		m_blend_strList << "GL_ZERO" << "GL_ONE"<< "GL_SRC_COLOR"<< "GL_ONE_MINUS_SRC_COLOR"<< "GL_SRC_ALPHA"<< "GL_ONE_MINUS_SRC_ALPHA"<< "GL_DST_ALPHA"<< "GL_ONE_MINUS_DST_ALPHA"<< "GL_DST_COLOR"
			<<"GL_ONE_MINUS_DST_COLOR"<<"GL_SRC_ALPHA_SATURATE";
		m_blend_val  << 0 << 1 << 0x300 << 0x301 <<0x302 <<0x303 <<0x304<<0x0305 <<0x306<<0x307 <<0x308;

    }

    int getValByText(QString blendFuncText)
    {
        return m_blend_val.at(m_blend_strList.indexOf(blendFuncText));
    }
    
	QString getTextByValue(int val)
	{
        return m_blend_strList.at(m_blend_val.indexOf(val));
	}

    

    PP(){}
    static PP * instance()
    {
        static PP pp;
        if(!pp.m_isInit)
        {
            pp.init();
            m_isInit = true;
        }
        return &pp;
    }

    
    sParticle *getParticleProp(int id) 
    {
        for(int i =0;i <m_particleP.size();i++)
        {
            if (m_particleP[i].id == id)
            {
                return &m_particleP[i];
            }
        }
        return 0;
    }
    

    
};


#endif // PARTICLEPROPERTIES_H

