#include "particleeditorwindow.h"
#include "ui_particleeditorwindow.h"
#include "ParticleProperties.h"
#include "qpropertylineeditorfactory.h"
#include "qpropertylineeditorgroup.h"
#include "qsliderlineeditor.h"
#include "entitymanager.h"
#include "zlib.h"
#include "dialog_savetexture.h"
#include "dialog_about.h"
#include "flowlayout.h"
#include <QObject>
#include <QToolBar>
#include <QFileDialog>
#include <QColorDialog>
#include <QMessageBox>
#include "MainScene.h"



#define EXAMPLE_DIR "example"


#define MSGBOX_SAVED(FILEPATH) QMessageBox::information(this , "Info" ," \"" +  FILEPATH + "\" saved" ,QMessageBox::Ok);

ParticleEditorWindow::ParticleEditorWindow(): m_isExample(false),
	m_isEmbed(false) ,
	m_hasSaved(true) ,
	m_hasLinked2File(false),
    ui(new Ui::ParticleEditorWindow)
{
    ui->setupUi(this);
        
    setWindowTitle(WINDOW_NAME );
	setWindowFlags( Qt::WindowTitleHint |Qt::WindowTitleHint | Qt::WindowMinMaxButtonsHint | Qt::WindowSystemMenuHint|Qt::WindowCloseButtonHint);
    my_new(); 
    createActions();
    createTooBar();

    m_Factory = new QPropertyLineEditorFactory();
    EntityManager::reg(EntityManager::ID_line_editor_factory , m_Factory);
    // particles 
    QPropertyLineEditorGroup * lineGroup_particle = new QPropertyLineEditorGroup(ui->name_particleProperties , m_Factory);
    lineGroup_particle->setMargins(0,0,0,0);
    AddProperty(lineGroup_particle , PP::duration);
    AddProperty(lineGroup_particle,PP::maxParticles );
    AddProperty(lineGroup_particle ,PP::particleLifespan );
    AddProperty(lineGroup_particle ,PP::particleLifespanVariance );
    AddProperty(lineGroup_particle ,PP::startParticleSize );
    AddProperty(lineGroup_particle ,PP::startParticleSizeVariance );
    AddProperty(lineGroup_particle ,PP::finishParticleSize);
    AddProperty(lineGroup_particle ,PP::finishParticleSizeVariance);
    AddProperty(lineGroup_particle ,PP::angle );
    AddProperty(lineGroup_particle ,PP::angleVariance );
    AddProperty(lineGroup_particle ,PP::rotationStart );
    AddProperty(lineGroup_particle ,PP::rotationStartVariance);
    AddProperty(lineGroup_particle ,PP::rotationEnd );
    AddProperty(lineGroup_particle ,PP::rotationEndVariance);
    
    //Emitter Type - Gravity Configuration. 
    m_emitterType_gravity = new QPropertyLineEditorGroup(ui->name_emitter_type , m_Factory);
    m_emitterType_gravity->setMargins(0,0,20,0);
    AddProperty(m_emitterType_gravity, PP::speed);
    AddProperty(m_emitterType_gravity,PP::speedVariance);
    AddProperty(m_emitterType_gravity,PP::gravityx );
    AddProperty(m_emitterType_gravity,PP::gravityy );
    AddProperty(m_emitterType_gravity,PP::radialAcceleration );
    AddProperty(m_emitterType_gravity,PP::radialAccelVariance);
    AddProperty(m_emitterType_gravity,PP::tangentialAcceleration);
    AddProperty(m_emitterType_gravity,PP::tangentialAccelVariance );
    //Emitter Type - Radial Configuration.
    m_emitterType_radial = new QPropertyLineEditorGroup(ui->name_emitter_type, m_Factory);
    m_emitterType_radial->setMargins(0,0,20,0);
    AddProperty(m_emitterType_radial, PP::maxRadius);
    AddProperty(m_emitterType_radial, PP::maxRadiusVariance);
    AddProperty(m_emitterType_radial, PP::minRadius );
    AddProperty(m_emitterType_radial, PP::rotatePerSecond );
    AddProperty(m_emitterType_radial, PP::rotatePerSecondVariance);
    m_emitterType_radial->hide();


    
    //ParticleEmitter Position .
    QPropertyLineEditorGroup * lineGroup_emitterPos = new QPropertyLineEditorGroup(ui->name_emitterPosition, m_Factory);
    lineGroup_emitterPos->setMargins(0,0,0,0);
    //AddProperty(lineGroup_emitterPos,PP::sourcePositionx);
    AddProperty(lineGroup_emitterPos,PP::sourcePositionVariancex);
    //AddProperty(lineGroup_emitterPos,PP::sourcePositiony);
    AddProperty(lineGroup_emitterPos,PP::sourcePositionVariancey );
    
    //start Color
    QPropertyLineEditorGroup * lineGroup_startColor = new QPropertyLineEditorGroup(ui->name_startColor, m_Factory);

    AddHSliderProperty(lineGroup_startColor ,PP::startColorRed );  
    AddHSliderProperty(lineGroup_startColor ,PP::startColorGreen );   
    AddHSliderProperty(lineGroup_startColor ,PP::startColorBlue );   
    AddHSliderProperty(lineGroup_startColor ,PP::startColorAlpha );   
    
    //start color var 
    QPropertyLineEditorGroup * lineGroup_startColorVar = new QPropertyLineEditorGroup(ui->name_startColorVar, m_Factory);
    AddHSliderProperty(lineGroup_startColorVar,PP::startColorVarianceRed );  
    AddHSliderProperty(lineGroup_startColorVar,PP::startColorVarianceGreen );  
    AddHSliderProperty(lineGroup_startColorVar,PP::startColorVarianceBlue );   
    AddHSliderProperty(lineGroup_startColorVar,PP::startColorVarianceAlpha );  
    
    //end color
    QPropertyLineEditorGroup * lineGroup_endColor = new QPropertyLineEditorGroup(ui->name_endColor, m_Factory);
    AddHSliderProperty(lineGroup_endColor,PP::finishColorRed );  
    AddHSliderProperty(lineGroup_endColor,PP::finishColorGreen );   
    AddHSliderProperty(lineGroup_endColor,PP::finishColorBlue );    
    AddHSliderProperty(lineGroup_endColor,PP::finishColorAlpha );   
    //end color var
    QPropertyLineEditorGroup * lineGroup_endColorVar = new QPropertyLineEditorGroup(ui->name_endColorVar, m_Factory);
    AddHSliderProperty(lineGroup_endColorVar,PP::finishColorVarianceRed );         
    AddHSliderProperty(lineGroup_endColorVar,PP::finishColorVarianceGreen );       
    AddHSliderProperty(lineGroup_endColorVar,PP::finishColorVarianceBlue );         
    AddHSliderProperty(lineGroup_endColorVar,PP::finishColorVarianceAlpha );        
   
    //bg color
    
    QPropertyLineEditorGroup * lineGroup_bgColorVar = new QPropertyLineEditorGroup(ui->name_bgColorVar, m_Factory);
    AddHSliderProperty(lineGroup_bgColorVar,PP::bg_color_r );         
    AddHSliderProperty(lineGroup_bgColorVar,PP::bg_color_g );       
    AddHSliderProperty(lineGroup_bgColorVar,PP::bg_color_b );         
    AddHSliderProperty(lineGroup_bgColorVar,PP::bg_color_a );    
    m_Factory->Property(PP::bg_color_a)->setValue(255);
    //connect(lineGroup ,SIGNAL(propertyValueChanged(QPropertyLineEditor*,double)) ,SLOT(propertyValueChanged(QPropertyLineEditor*,double)));
    connect(m_Factory, SIGNAL(propertyValueChanged(IPropertyEditor*,double)),this,SLOT(propertyValueChanged(IPropertyEditor*,double)));

	
}

ParticleEditorWindow::~ParticleEditorWindow()
{
    delete ui;
	delete m_Factory;
}

void ParticleEditorWindow::createActions()
{
    
//    mAct_new = new QAction(QIcon(":/images/new.png"), tr("&New"), this);
//    mAct_new->setStatusTip(tr("new a plist file"));
//    connect(mAct_new, SIGNAL(triggered()), this, SLOT(act_new()));
    
    mAct_Open = new QAction(QIcon(":/images/open.png"), tr("&Open"), this);
    mAct_Open->setStatusTip(tr("Open a plist file"));
    connect(mAct_Open, SIGNAL(triggered()), this, SLOT(act_open()));

    mAct_Save = new QAction(QIcon(":/images/save.png"), tr("&Save"), this);
    mAct_Save->setStatusTip(tr("Save plist file"));
    connect(mAct_Save, SIGNAL(triggered()), this, SLOT(act_save()));
    
    mAct_Saveas = new QAction(QIcon(":/images/saveas.png"), tr("&Save As"), this);
    mAct_Saveas->setStatusTip(tr("Save As new plist file"));
    connect(mAct_Saveas, SIGNAL(triggered()), this, SLOT(act_saveas()));
    
    m_ActAbout = new QAction(QIcon(":/images/about.png"), tr("&About"), this);
    connect(m_ActAbout, SIGNAL(triggered()), this, SLOT(act_about()));
    
    mAct_Play = new QAction(QIcon(":/images/play.png"), tr("&Play"), this);
    connect(mAct_Play, SIGNAL(triggered()), this, SLOT(act_play()));
    
    
    mAct_example = new QAction(QIcon(":/images/example.png"), tr("&Example"), this);
    connect(mAct_example, SIGNAL(triggered()), this, SLOT(act_open_exampleMenu()));
   
    //examples sub menu
    m_menu_example = new QMenu("examples",this);
    //m_menu_example->setFixedWidth(150);
    QDir folder(EXAMPLE_DIR);
    QFileInfoList subFiles = folder.entryInfoList();

    for (int i = 0; i < subFiles.size(); ++i) {
        QString fileName = subFiles.at(i).fileName();
        if(fileName.isNull()||fileName.isEmpty())continue;
        if(!fileName.endsWith("plist"))continue;
        QAction * _actExample = new QAction(this);
        _actExample->setText(fileName);
        _actExample->setData(QVariant(subFiles.at(i).absoluteFilePath()) );
        connect(_actExample, SIGNAL(triggered()),this, SLOT(act_openExample()) );
        m_menu_example->addAction(_actExample);
    }
    mAct_example->setMenu(m_menu_example);
    
    //recent files sub menu
    m_openMenu = new QMenu("One", this);
    QAction* openAct = m_openMenu->addAction(QIcon(":/images/open.png"), tr("&Open"));
    //m_openMenu->setFixedWidth(150);
    
    connect(openAct, SIGNAL(triggered()), this, SLOT(act_open()));
    m_openMenu->addSeparator();
    mAct_Open->setMenu(m_openMenu);
    for (int i = 0; i < MaxRecentFiles; ++i) {
        recentFileActs[i] = new QAction(this);
        recentFileActs[i]->setVisible(false);
        connect(recentFileActs[i], SIGNAL(triggered()),
                this, SLOT(openRecentFile()));
        m_openMenu->addAction(recentFileActs[i]);
    }
    m_openMenu->addSeparator();

   QAction * clearAct = m_openMenu->addAction(QIcon(":/images/clear.png"), tr("&Clear"));
   connect(clearAct, SIGNAL(triggered()), this, SLOT(act_clearRecent()));

}

void ParticleEditorWindow::createTooBar()
{
    QToolBar *fileToolBar = addToolBar(tr("Open"));
    //fileToolBar->addAction(mAct_new);
    fileToolBar->addAction(mAct_Open);
    fileToolBar->addAction(mAct_Save);
    fileToolBar->addAction(mAct_Saveas);
    fileToolBar->addAction(mAct_Play);
    fileToolBar->addAction(mAct_example);
    fileToolBar->addAction(m_ActAbout);
    
    updateRecentFileActions();

}


bool isReading =false;

int ParticleEditorWindow::read(QString filename , QString & currentPngFile)
{

    //CCDictionary<std::string, CCObject*> * dict =  CCFileUtils::dictionaryWithContentsOfFileThreadSafe(filename.toLocal8Bit().data());
	ValueMap dict = FileUtils::getInstance()->getValueMapFromFile(filename.toStdString());
    isReading = true;
    for (int i = 0; i < PP::count;i++)
    {
        if (m_Factory->Property(i) ==0 )
        {
            continue;
        }
        switch(typof(i))
        {
        case QVariant::Int:
            m_Factory->Property(i)->setValue(dict[pnameof(i)].asInt());
            break;
        case QVariant::Double:
            m_Factory->Property(i)->setValue(dict[pnameof(i)].asFloat());
            break;
        case QVariant::Color:
            m_Factory->Property(i)->setValue(dict[pnameof(i)].asFloat() * 255);
            break;
        default:
            break;
        }
    }
	renewColorButton(ui->btn_startColor, m_Factory->Property(PP::startColorRed)->getValue() ,m_Factory->Property(PP::startColorGreen)->getValue() ,m_Factory->Property(PP::startColorBlue)->getValue()  );
	renewColorButton(ui->btn_endColor,m_Factory->Property(PP::finishColorRed)->getValue() ,m_Factory->Property(PP::finishColorGreen)->getValue() ,m_Factory->Property(PP::finishColorBlue)->getValue()  );

	bool extPng = dict.find("textureFileName") != dict.end();
	int isEmbed = false;
	if(extPng)
	{
        isEmbed = 0;
        std::string textfileName = dict["textureFileName"].asString();
        QString textfileNamePath = QFileInfo(filename).dir().path() +"/"+ textfileName.c_str();
        QImage image(textfileNamePath );
		int factor = MAX(image.width() ,image.height());
		if (factor >=64 )scaleImage(image,64,64);
        _png = QPixmap::fromImage(image);
		ui->name_textureImage->setPixmap(_png);
    }
	if (_png.width() ==0 )
	{
		//read texture
		unsigned char *buffer = NULL;
		unsigned char *deflated = NULL; 
		std::string textureData = dict.at("textureImageData").asString();

		auto dataLen = textureData.size();
		// if it fails, try to get it from the base64-gzipped data	
		int decodeLen = base64Decode((unsigned char*)textureData.c_str(), (unsigned int)dataLen, &buffer);
		CCAssert( buffer != NULL, "CCParticleSystem: error decoding textureImageData");
		int deflatedLen = ZipUtils::ccInflateMemory(buffer, decodeLen, &deflated);
		CCAssert( deflated != NULL, "CCParticleSystem: error ungzipping textureImageData");

		QImage image = QImage::fromData(deflated,deflatedLen );

		int factor = MAX(image.width() ,image.height());
		if (factor >=64 )scaleImage(image,64,64);
		//ui->name_cocownd->setPixmap(QPixmap::fromImage(image));
		_png = QPixmap::fromImage(image);
		ui->name_textureImage->setPixmap(_png);
		free(buffer );
		free(deflated);
		isEmbed = 1;
	}

    _png.save("default.png","png");
    currentPngFile = dict[pnameof(PP::textureFileName)].asString().c_str();
    //read blend func 
    int blend_src = dict[pnameof(PP::blendFuncSource )].asInt();
    int blend_dst = dict[pnameof(PP::blendFuncDestination )].asInt();
    ui->name_blendsrc->setCurrentIndex(ui->name_blendsrc->findText(p_blendFucNameOfVal(blend_src)));
    ui->name_blenddst->setCurrentIndex(ui->name_blendsrc->findText(p_blendFucNameOfVal(blend_dst)));
    //

    // read emitter mode 
//    emitterType
    int emitterType = dict[pnameof(PP::emitterType)].asInt();
    ui->name_eimitterType->setCurrentIndex(emitterType);

    
    isReading = false;
    return isEmbed;
}



ccColor4F ccc4f( float r ,float g, float b , float a )
{
    Color4F color4f(r,g,b,a);
    return color4f;
}

ValueMap ParticleEditorWindow::getDict()
{
	ValueMap dict;
    for (int i = 0; i < PP::count;i++)
    {
        if (m_Factory->Property(i) ==0 )
        {
            continue;
        }
        float value = m_Factory->Property(i)->getValue();
        std::string pname = pnameof(i);
        if (typof(i) ==QVariant::Color)
		{
			dict[pname] = value / 0xff;
		}else
		{
			dict[pname] = value;
		}
    }
    //texture file name
    CCString * text_filename = new CCString();
	dict[pnameof(PP::textureFileName)] = Value("default.png");

    //blend func.
	dict[pnameof(PP::blendFuncSource)] = p_blendFucValOfName(ui->name_blendsrc->currentText());
	dict[pnameof(PP::blendFuncDestination)] = p_blendFucValOfName(ui->name_blenddst->currentText());
    //emitter mode
	dict[pnameof(PP::emitterType)] = ui->name_eimitterType->currentIndex();
 
    return dict;
}


void ParticleEditorWindow::propertyValueChanged(IPropertyEditor *editor, double value)
{
	if (isReading ) return;
    //CCParticleSystem_Ext * particleExt = MyScene::curParticle();
	//if ( particleExt == 0 ) return;
	my_valueChanged();
    CCParticleSystem * particle = MainScene::getInstance()->getPs();

    switch(editor->id)
    {
    case PP::sourcePositionx:
        particle->setSourcePosition(ccp( value , particle->getSourcePosition().y));
        if (particle->getDuration()!=-1.0f)
            break;
        return;
    case PP::sourcePositiony:
        particle->setSourcePosition(ccp( particle->getSourcePosition().x,  value));
        if (particle->getDuration()!=-1.0f)
            break;
        return;
    case PP::sourcePositionVariancex:
        particle->setPosVar(ccp(value ,particle->getPosVar().y));
        break;
    case PP::sourcePositionVariancey:
        particle->setPosVar(ccp( particle->getPosVar().x , value));
        break;
    case PP::speed:
        particle->setSpeed(value);
        break;
    case PP::speedVariance:
        particle->setSpeedVar(value);
        break;
    case PP::gravityx:
        particle->setGravity( ccp ( value , particle->getGravity().y) ) ; 
        break;
    case PP::gravityy:
        particle->setGravity( ccp(  particle->getGravity().x , value) );
        break;
    case PP::radialAcceleration:
        particle->setRadialAccel(value);
        break;
    case PP::radialAccelVariance:
        particle->setRadialAccelVar(value);
        break;
    case PP::tangentialAcceleration:
        particle->setTangentialAccel(value);
        break;
    case PP::tangentialAccelVariance:
        particle->setTangentialAccelVar(value);
        break;
    case PP::maxParticles:
    {
        particle->stopSystem();
		MainScene::getInstance()->resetPs(getDict() ,value);
//         CCDictionary<std::string ,CCObject*> * dict = getDict();
//         MyScene::reloadMyParticle(QDir::currentPath() ,dict ,value);
//         dict->release();
        return;
    }
    case PP::particleLifespan:
        particle->setLife(value);
        break;
    case PP::particleLifespanVariance:
        particle->setLifeVar(value);
        break;
    case PP::startParticleSize:
        particle->setStartSize(value);
        break;
    case PP::startParticleSizeVariance:
        particle->setStartSizeVar(value);
        break;
    case PP::finishParticleSize:
        particle->setEndSize(value);
        break;
    case PP::finishParticleSizeVariance:
        particle->setEndSizeVar(value);
        break;
    case PP::angle:
        particle->setAngle(value);
        break;
    case PP::angleVariance:
        particle->setAngleVar(value);
        break;
    case PP::rotationStart:
        particle->setStartSpin(value);
        break;
    case PP::rotationStartVariance:
        particle->setStartSpinVar(value);
        break;
    case PP::rotationEnd:
        particle->setEndSpin(value);
        break;
    case PP::rotationEndVariance:
        particle->setEndSpinVar(value);
        break;
    case PP::duration:
        particle->setDuration(value);
        particle->resetSystem();
        break;
    // radial mode
    case PP::maxRadius:
        particle->setStartRadius(value);
        break;
    case PP::maxRadiusVariance:
        particle->setStartRadiusVar(value);
        break;
    case PP::minRadius:
        particle->setEndRadius(value);
    case PP::rotatePerSecond:
        particle->setRotatePerSecond(value);        
        break;
    case PP::rotatePerSecondVariance:
        particle->setRotatePerSecondVar(value);
        break;
   }
    
    ccColor4F cs4 = particle->getStartColor();
    ccColor4F ce4 = particle->getEndColor();
    ccColor4F csv4 = particle->getStartColorVar();
    ccColor4F cev4 = particle->getEndColorVar();
    CCLayerColor * _myscene = MainScene::getInstance();
    ccColor3B bgC3 = MainScene::getInstance()->getColor();
    switch(editor->id)
    {
    // color setting.  
    case PP::startColorRed:
        particle->setStartColor(Color4F(value/ 255 ,cs4.g,  cs4.b ,cs4.a));
        break;
    case PP::startColorGreen:
        particle->setStartColor(Color4F(cs4.r,value/ 255 ,  cs4.b ,cs4.a));
        break;
    case PP::startColorBlue:
        particle->setStartColor(Color4F(cs4.r,cs4.g,  value/ 255 ,cs4.a));
        break;
    case PP::startColorAlpha:
        particle->setStartColor(Color4F(cs4.r,cs4.g,  cs4.b ,value/ 255));
        break;
    case PP::startColorVarianceRed:
        particle->setStartColorVar(Color4F(value/ 255,csv4.g,  csv4.b ,csv4.a));
        break;
    case PP::startColorVarianceGreen:
        particle->setStartColorVar(Color4F(csv4.r,value/ 255,  csv4.b ,csv4.a));
        break;
    case PP::startColorVarianceBlue:
        particle->setStartColorVar(Color4F(csv4.r,csv4.g, value/ 255 ,csv4.a));
        break;
    case PP::startColorVarianceAlpha:
        particle->setStartColorVar(Color4F(csv4.r,csv4.g,  csv4.b ,value/ 255));
        break;
 
    case PP::finishColorRed:
        particle->setEndColor(Color4F(value/ 255,ce4.g,  ce4.b ,ce4.a));
        break;
    case PP::finishColorGreen:
        particle->setEndColor(Color4F(ce4.r,value/ 255 ,  ce4.b ,ce4.a));
        break;
    case PP::finishColorBlue:
        particle->setEndColor(Color4F(ce4.r,ce4.g,  value/ 255 ,ce4.a));
        break;
    case PP::finishColorAlpha:
        particle->setEndColor(Color4F(ce4.r,ce4.g,  ce4.b ,value/ 255));
        break;
    case PP::finishColorVarianceRed:
        particle->setEndColorVar(Color4F(value/ 255,cev4.g,  cev4.b ,cev4.a));
        break;
    case PP::finishColorVarianceGreen:
        particle->setEndColorVar(Color4F(cev4.r,value/ 255,  cev4.b ,cev4.a));
        break;
    case PP::finishColorVarianceBlue:
        particle->setEndColorVar(Color4F(cev4.r,cev4.g, value/ 255 ,cev4.a));
        break;
    case PP::finishColorVarianceAlpha:
        particle->setEndColorVar(Color4F(cev4.r,cev4.g,  cev4.b ,value/ 255));
        break;
    case PP::bg_color_r:
        _myscene->setColor(ccc3(value , bgC3.g, bgC3.b));
        break;
    case PP::bg_color_g:
        _myscene->setColor(ccc3(bgC3.r , value, bgC3.b));
        break;
    case PP::bg_color_b:
        _myscene->setColor(ccc3(bgC3.r  , bgC3.g, value));
        break;
    case PP::bg_color_a:
        _myscene->setOpacity(value);
        break;
    }
	renewColorButton(ui->btn_startColor, m_Factory->Property(PP::startColorRed)->getValue() ,m_Factory->Property(PP::startColorGreen)->getValue() ,m_Factory->Property(PP::startColorBlue)->getValue()  );
	renewColorButton(ui->btn_endColor,  m_Factory->Property(PP::finishColorRed)->getValue() ,m_Factory->Property(PP::finishColorGreen)->getValue() ,m_Factory->Property(PP::finishColorBlue)->getValue()  );
	renewColorButton(ui->btn_bgColor , m_Factory->Property(PP::bg_color_r)->getValue() ,m_Factory->Property(PP::bg_color_g)->getValue() ,m_Factory->Property(PP::bg_color_b)->getValue()  );
    if (particle->getDuration()!= -1.0f)
    {
        particle->resetSystem();
    }

}

void ParticleEditorWindow::act_openRenctFileMenu()
{
    QRect rect = m_openMenu->parentWidget()->geometry();
    m_openMenu->move(rect.x() ,rect.y());
    m_openMenu->show();
}

void ParticleEditorWindow::readplist(QString filePath)
{
    CCTextureCache::sharedTextureCache()->removeAllTextures();
    // open plist file , read to the editor
    QString pngfilename;
    int ret = read(filePath , pngfilename);
    //MyScene::initMyParticle(filePath);
	MainScene::getInstance()->initPs(filePath.toStdString());
	
    if(ret ==-1)return;
    bool isEmbed = ret ==1 ?true:false;
    my_open(filePath, isEmbed , pngfilename);
}

void ParticleEditorWindow::act_open()
{
	// clear the cached texture .
    QSettings settings(QString("setting.ini"),QSettings::IniFormat);
    QString dir = settings.value("lastOpenDir" , QDir::currentPath()).toString();
    QString filePath = QFileDialog::getOpenFileName(this,"Open Plist File" , dir , "plist files (*.plist);;All Files(*.*)" );
    if (!filePath.isNull())
    {
        readplist(filePath);
        setCurrentFile(filePath);
        QSettings settings(QString("setting.ini"),QSettings::IniFormat);
        QString lastOpenDir = QFileInfo(filePath).dir().path();
        settings.setValue("lastOpenDir",lastOpenDir);
    }
}

void ParticleEditorWindow::act_save()
{ 
    qDebug()<<isExample();
    if (isExample())
    {
        act_saveas();
        return;
    }
    if( hasLinked2File())
    {
        write(m_currentPath , m_pngfilename ,m_isEmbed);
        QFileInfo fileInfo = QFileInfo(m_currentPath);
		QString filePath = fileInfo.dir().path();
        if (!m_isEmbed)
            _png.save(filePath + "/"+ m_pngfilename , "png");
        my_save(m_currentPath , m_isEmbed , m_pngfilename);
        MSGBOX_SAVED(m_currentPath);
    }else{
        act_saveas();
    }
    
}

void ParticleEditorWindow::act_new()
{
//    if (!isSaved())
//    {
//        //not saved .ask if save.
//        QMessageBox::StandardButton button;
//        button = QMessageBox::question(this, tr("Save"),
//            QString(tr("Save Current Work ? ")),
//            QMessageBox::Save |QMessageBox::No);
//        if (button == QMessageBox::Save) {
//            act_save();
//        }
//    }
//    //clear particle.
//    CCParticleSystem_Ext * particleNode = MyScene::curParticle();
//    particleNode->m_current->stopSystem();
//    //all propety editor set to initial value;
    
//    my_new();
    
}

void ParticleEditorWindow::act_saveas()
{
    QSettings settings(QString("setting.ini"),QSettings::IniFormat);
    QString dir = settings.value("lastOpenDir" , QDir::currentPath()).toString();
    QString plistPath = QFileDialog::getSaveFileName(this,"Save Plist File" ,dir, "plist file (*.plist);;All Files(*.*)" );
    if (!plistPath.isNull())
    { 
		int first = plistPath.lastIndexOf("/")+1;
		int second =  plistPath.lastIndexOf(".");
        QString defaultName = plistPath.mid(first , second-first)+".png";
        Dialog_SaveTexture saveTextureDialog(defaultName );
        int ret = saveTextureDialog.exec();
        //user clicked ok .
        if (ret == QDialog::Accepted)
        {
            if (saveTextureDialog.getOption()==Dialog_SaveTexture::Embed)
            {
                write(plistPath , defaultName,true);
                my_save(plistPath , true , defaultName);
                MSGBOX_SAVED(plistPath);
            }
            else if(saveTextureDialog.getOption()==Dialog_SaveTexture::SaveAs) {
                QString filePath = QFileInfo(plistPath).dir().path();
                QString pngFilename = saveTextureDialog.getFileName();
                if (pngFilename.isEmpty()) pngFilename = defaultName;
                write(plistPath , pngFilename ,false);
                //save png file if user do not want to embed the texture to plist file . 
                _png.save(filePath + "/" +pngFilename , "png");
                my_save(plistPath , false , pngFilename);
                MSGBOX_SAVED(plistPath);
            }
        }
    }
}

void ParticleEditorWindow::act_play()
{
    CCParticleSystem * particleNode = MainScene::getInstance()->getPs();
    if (particleNode == 0)
        return;
    particleNode->resetSystem();
}

void ParticleEditorWindow::act_open_exampleMenu()
{
    m_menu_example->move(QCursor::pos());
    m_menu_example->show();

}

void ParticleEditorWindow::act_openExample()
{
    QAction *action = qobject_cast<QAction *>(sender());
    if(action !=0)
    {
        QString filePath = action->data().toString();
        if (QFile(filePath).exists())
            readplist(filePath);
        else
            QMessageBox::information(this, "Warnnig" , "plist file not found" , QMessageBox::Ok);
    }
    my_openExample();
}

void ParticleEditorWindow::act_about()
{
    Dialog_About aboutDialog;
    aboutDialog.exec();
    
}

void ParticleEditorWindow::act_clearRecent()
{
    QSettings settings(QString("setting.ini"),QSettings::IniFormat);
    QStringList files = settings.value("recentFileList").toStringList();
    files.clear();
    settings.setValue("recentFileList", files);
    updateRecentFileActions();
}

 
void ParticleEditorWindow::closeEvent(QCloseEvent *event)
{
    if (isSaved())
    {
		cocos2d::Director::getInstance()->end();
		qApp->quit();	
        return;
    }
    QMessageBox::StandardButton button;
    button = QMessageBox::question(this, tr("Exit Application"),
        QString(tr("Warnning : Quit without saving ?")),
        QMessageBox::Close | QMessageBox::Save |QMessageBox::Cancel);

    if (button == QMessageBox::Cancel) {
        event->ignore();  
    }
    else if (button == QMessageBox::Save) {
        event->ignore();  //ignore the event.
        if (!isSaved())
            act_save();
    }
    else if (button == QMessageBox::Close) {
        event->accept();  // the event continue exec.
		cocos2d::Director::getInstance()->end();
		qApp->quit();
    }
    
    
}




QPropertyLineEditor *ParticleEditorWindow::AddProperty(QPropertyLineEditorGroup *group, int id )
{
    return group->AddProperty(id,nameof(id), p_min(id),p_max(id))->setDataType(typof(id));
}



IPropertyEditor *ParticleEditorWindow::AddHSliderProperty(QPropertyLineEditorGroup *group, int id )
{
    QSliderLineEditor * pleditor = new QSliderLineEditor(this ,id , nameof(id), p_min(id),p_max(id) , (p_max(id) - p_min(id)) /100);
    return group->AddHSliderProperty(pleditor);
}



void ParticleEditorWindow::on_name_eimitterType_currentIndexChanged(const QString &val)
{
    my_valueChanged();
    if (val.compare(val,"Radial" , Qt::CaseInsensitive)==0)
    {
        m_emitterType_radial->show();
        m_emitterType_gravity->hide();
        if (!isReading)       
        {
            CCParticleSystem * particleNode = MainScene::getInstance()->getPs();  
            if (particleNode != 0)
            {
                particleNode->setEmitterMode(kCCParticleModeRadius);
                CCPoint sourcePos = particleNode->getPosition();
                particleNode->setPosition(sourcePos);
                particleNode->resetSystem();
            }
        }
        
        // update.
        QList<int> pids = m_emitterType_radial->allIds();
        for (int i = 0 ;i < pids.size();i++)
        {
            int id = pids.at(i);
            propertyValueChanged(m_emitterType_radial->Property(id) , m_emitterType_radial->Property(id)->getValue());
        }
    }
    else if (val.compare(val,"Gravity" , Qt::CaseInsensitive)==0)
    {     
        m_emitterType_gravity->show();
        m_emitterType_radial->hide();
        if (!isReading)
        {
            CCParticleSystem * particleNode = MainScene::getInstance()->getPs();  
            if (particleNode != 0)
            {
                particleNode->setEmitterMode(kCCParticleModeGravity);
                CCPoint sourcePos = particleNode->getPosition();
                particleNode->setPosition(sourcePos);
                //particleNode->setSourcePosition(sourcePos);
                particleNode->resetSystem();
            }
        }
        // update.
        QList<int> pids = m_emitterType_gravity->allIds();
        for (int i = 0 ;i < pids.size();i++)
        {
            int id = pids.at(i);
            propertyValueChanged(m_emitterType_gravity->Property(id) , m_emitterType_gravity->Property(id)->getValue());
        } 
    }
}

void ParticleEditorWindow::write(QString plistFile ,QString textureFile , bool emebedPng)
{
    ValueMap dict = getDict();
	//blend func 
	//dict[pnameof(PP::blendFuncSource)] = p_blendFucValOfName(ui->name_blendsrc->currentText());
	//dict[pnameof(PP::blendFuncDestination)] = p_blendFucValOfName(ui->name_blenddst->currentText());
	//emitter mode 
	//dict[pnameof(PP::emitterType)] = ui->name_eimitterType->currentIndex() ;
	dict[pnameof(PP::textureFileName)] = textureFile.toStdString();


    //write texture data ;
    if(emebedPng)
    {
        // write image raw data to a bytearray .
        QByteArray src;
        QBuffer srcBuf(&src);
        srcBuf.open(QIODevice::WriteOnly);
        _png.save(&srcBuf,"png");
        srcBuf.close();
        // 2 step: zip deflate... 
        QByteArray dst;
        ulong destLen = src.length() + src.length()/ 100 + 13;
        dst.resize(destLen);
        //compress((uchar*)dst.data() ,&destLen ,(uchar*)src.data(),src.length());
		//dst = qCompress(src);
		
		compress((uchar*)dst.data() ,&destLen ,(uchar*)src.data(),src.length());
        //dst.resize(destLen);
        //base64Encode ..... .
        dst = dst.toBase64();
        //write texture data to plist file
		dict["textureImageData"] =  std::string(dst.data());
    }
    
    FileUtils::getInstance()->writeToFile(dict , plistFile.toStdString());

}

void ParticleEditorWindow::on_name_blenddst_currentIndexChanged(const QString &val)
{
    my_valueChanged();
    CCParticleSystem * particleNode = MainScene::getInstance()->getPs();
	//MainScene::getInstance()->
    if ( particleNode == 0 ) return;
    ccBlendFunc blendFuc = particleNode->getBlendFunc();
    blendFuc.dst = p_blendFucValOfName(val);
    particleNode->setBlendFunc(blendFuc);
}

void ParticleEditorWindow::on_name_blendsrc_currentIndexChanged(const QString &val)
{
    my_valueChanged();
    CCParticleSystem * particleNode = MainScene::getInstance()->getPs();
    if ( particleNode == 0 ) return;
    ccBlendFunc blendFuc = particleNode->getBlendFunc();
    blendFuc.src = p_blendFucValOfName(val);
    particleNode->setBlendFunc(blendFuc);
}



void ParticleEditorWindow::on_name_blendNormal_clicked()
{
    ui->name_blendsrc->setCurrentIndex(ui->name_blendsrc->findText("GL_SRC_ALPHA"));
    ui->name_blenddst->setCurrentIndex(ui->name_blenddst->findText("GL_ONE_MINUS_SRC_ALPHA"));
}

void ParticleEditorWindow::on_name_blendAdditive_clicked()
{
    ui->name_blendsrc->setCurrentIndex(ui->name_blendsrc->findText("GL_SRC_ALPHA"));
    ui->name_blenddst->setCurrentIndex(ui->name_blenddst->findText("GL_ONE"));
}

void ParticleEditorWindow::on_pushButton_clicked()
{
    CCParticleSystem * particleNode = MainScene::getInstance()->getPs();
    if ( particleNode == 0 ) return;
    QSettings settings(QString("setting.ini"),QSettings::IniFormat);
    QString dir = settings.value("lastOpenDir" , QDir::currentPath()).toString();
    QString filePath = QFileDialog::getOpenFileName(this,  "Open Texture File" ,dir , "Png File(*.png);;All Files(*.*)");
    if (!filePath.isNull())
    {
        QImage image(filePath );
		int factor = MAX(image.width() ,image.height());
		if (factor >=64 )scaleImage(image,64,64);
        _png = QPixmap::fromImage(image);
		ui->name_textureImage->setPixmap(_png);
        QFileInfo fileInfo = QFileInfo(filePath);
        QString pngPath = fileInfo.dir().path();
        QString pngName = fileInfo.fileName();
        particleNode->setTexture(CCTextureCache::sharedTextureCache()->addImage(pngName.toStdString().c_str()));
        my_openPng(pngPath , pngName);
    }
}

void ParticleEditorWindow::setCurrentFile(const QString &fileName)
{
    QSettings settings(QString("setting.ini"),QSettings::IniFormat);
    QStringList files = settings.value("recentFileList").toStringList();
    files.removeAll(fileName);
    files.prepend(fileName);
    while (files.size() > MaxRecentFiles)
        files.removeLast();

    settings.setValue("recentFileList", files);
    updateRecentFileActions();
}

void ParticleEditorWindow::updateRecentFileActions()
{
    QSettings settings(QString("setting.ini"),QSettings::IniFormat);
    QStringList files = settings.value("recentFileList").toStringList();

    int numRecentFiles = qMin(files.size(), (int)MaxRecentFiles);

    for (int i = 0; i < numRecentFiles; ++i) {
        QString text = tr("&%1.  %2").arg(i + 1).arg(QFileInfo((files[i])).fileName());
        recentFileActs[i]->setText(text);
        recentFileActs[i]->setData(files[i]);
        recentFileActs[i]->setVisible(true);
    }
    for (int j = numRecentFiles; j < MaxRecentFiles; ++j)
        recentFileActs[j]->setVisible(false);
}

void ParticleEditorWindow::openRecentFile()
{
    QAction *action = qobject_cast<QAction *>(sender());
    if(action !=0)
    {
        QString filePath = action->data().toString();
        if (QFile(filePath).exists())
            readplist(filePath);
        else
            QMessageBox::information(this, "Warnnig" , "plist file not found" , QMessageBox::Ok);
    }
        
}

void ParticleEditorWindow::setGLView( QWidget *glWidget )
{
	_glWidget = glWidget;
	if (_glWidget)
	{
		QHBoxLayout *layout = new QHBoxLayout(ui->name_cocownd);
		layout->setMargin(0);
		layout->addWidget(glWidget);
	}
}

void ParticleEditorWindow::openExample( const char * f)
{
	readplist(f);
	my_openExample(); 
}

void ParticleEditorWindow::on_btn_startColor_clicked()
{
	QColor color = QColorDialog::getColor();
	if (color.isValid() )
	{
		m_Factory->Property(PP::startColorRed)->setValue(color.red());
		m_Factory->Property(PP::startColorGreen)->setValue(color.green());
		m_Factory->Property(PP::startColorBlue)->setValue(color.blue());
		renewColorButton(ui->btn_startColor , color.red(),color.green(),color.blue());
	}
}

void ParticleEditorWindow::renewColorButton( QPushButton * btn , int r,int g, int b )
{
	char a[100];
	sprintf(a ,"background-color: rgb(%d, %d, %d);" ,r,g,b );
	QString stylesheetstr = QString::fromUtf8(a);
	btn->setStyleSheet(stylesheetstr);
}



void ParticleEditorWindow::on_btn_endColor_clicked()
{
	QColor color = QColorDialog::getColor();
	if (color.isValid() )
	{
		m_Factory->Property(PP::finishColorRed)->setValue(color.red());
		m_Factory->Property(PP::finishColorGreen)->setValue(color.green());
		m_Factory->Property(PP::finishColorBlue)->setValue(color.blue());
		renewColorButton(ui->btn_endColor , color.red(),color.green(),color.blue());
	}
}

void ParticleEditorWindow::on_btn_bgColor_clicked()
{
	QColor color = QColorDialog::getColor();
	if (color.isValid() )
	{
		MainScene::getInstance()->setColor(Color3B(color.red(),color.green(),color.blue()));
		renewColorButton(ui->btn_bgColor , color.red(),color.green(),color.blue());
		m_Factory->Property(PP::bg_color_r)->setValue(color.red());
		m_Factory->Property(PP::bg_color_g)->setValue(color.green());
		m_Factory->Property(PP::bg_color_b)->setValue(color.blue());
	}
}

void ParticleEditorWindow::on_changeButton_clicked()
{
	QString filePath = QFileDialog::getOpenFileName(this,  "Open File" ,QString() , "Png File(*.png);;All Files(*.*)");
	if (!filePath.isNull())
	{
		QImage image(filePath );
		scaleImage(image,80,64);
		ui->label_bg->setPixmap(QPixmap::fromImage(image));
		MainScene::getInstance()->changeBg(filePath.toStdString());
	}
}

void ParticleEditorWindow::scaleImage( QImage & img, int x , int y )
{
	img = img.scaled(QSize(x,y),Qt::KeepAspectRatio,Qt::SmoothTransformation);
}


void ParticleEditorWindow::on_removeButton_clicked()
{
	MainScene::getInstance()->toggleHidden();
}


void ParticleEditorWindow::on_box_move_stateChanged(int state)	
{
	if (state == 2)
		MainScene::getInstance()->toggleMove(true);
	else
		MainScene::getInstance()->toggleMove(false);
}
