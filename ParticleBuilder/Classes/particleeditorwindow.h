#ifndef PARTICLEEDITORWINDOW_H
#define PARTICLEEDITORWINDOW_H

#include <QMainWindow>
#include <QLabel>
#include <QComboBox>
#include <QMenu>
#include <QFrame>
#include "cocos2d.h"


#define WINDOW_NAME "Cocos2d Particle Builder "

using namespace cocos2d;
namespace Ui {
class ParticleEditorWindow;
}
class IPropertyEditor;
class QPropertyLineEditorGroup;
class QPropertyLineEditor;
class QPropertyLineEditorFactory;
class QPixmap;
class QPushButton;
class ParticleEditorWindow : public QMainWindow
{
    Q_OBJECT
private:
    QWidget             *_glWidget;
	QPixmap  _png;
public:
	void setGLView(QWidget *glWidget);
    explicit ParticleEditorWindow();
    ~ParticleEditorWindow();
    void createActions();
    void createTooBar();
    
    int read(QString filename, QString &currentPngFile);
    void write(QString plistFile, QString textureFile, bool emebedPng);
    
    IPropertyEditor *AddHSliderProperty(QPropertyLineEditorGroup *group, int id);
    void updateRecentFileActions();
    void setCurrentFile(const QString &fileName);
    void readplist(QString filePath);
	void openExample( const char * );

public slots:
    void propertyValueChanged(IPropertyEditor *editor , double value);
    void act_openRenctFileMenu();
    void act_open();
    void act_save();
    void act_new();
    void act_saveas();
    void act_play();
    void act_open_exampleMenu();
    void act_openExample();
    void act_about();
    void act_clearRecent();
private slots:
    void on_name_eimitterType_currentIndexChanged(const QString &val);
    
    void on_name_blendsrc_currentIndexChanged(const QString &arg1);
    
    void on_name_blenddst_currentIndexChanged(const QString &arg1);

    
    void on_name_blendNormal_clicked();
    
    void on_name_blendAdditive_clicked();
    
    void on_pushButton_clicked();
    
	void on_btn_startColor_clicked();
	void on_btn_endColor_clicked();
	void on_changeButton_clicked();
	void on_removeButton_clicked();
	void on_box_move_stateChanged(int state);
	void on_btn_bgColor_clicked();

	//custom slots
    void openRecentFile();
    
protected:
    void closeEvent(QCloseEvent *event) ;
	void scaleImage(QImage & img,  int x , int y );
private:

    QLabel * m_labelTexture;
    QComboBox *m_eimitterType;
    QComboBox * m_blendSrc;
    QComboBox *m_blendDst;
    QAction *mAct_new;
    QAction *mAct_Open;
    QMenu * m_openMenu;
    QAction *mAct_Save;
    QAction * mAct_Saveas;
    QAction * mAct_Play;
    QAction *  mAct_example;
    QMenu * m_menu_example;
    QAction * m_ActAbout;
    QPropertyLineEditorGroup * m_emitterType_gravity;
    QPropertyLineEditorGroup * m_emitterType_radial;
    Ui::ParticleEditorWindow *ui;
    
    //**** File Operation Flag *****//
    QString m_currentPath;
    bool m_hasLinked2File;
    bool m_hasSaved;
    bool m_isEmbed;
    QString m_pngfilename;
    QString m_pngPath;
    bool m_isExample;
    void my_valueChanged()
    {
        m_hasSaved = false;
        if (!m_currentPath.isNull())
            this->setWindowTitle(QString(WINDOW_NAME ) + " - "+  m_currentPath +" * " );
    }
    void my_new()
    {
        m_hasLinked2File = false;
        m_hasSaved = true;
    }
    void my_openPng(QString pngPath , QString pngName)
    {
        this-> m_pngPath = pngPath; 
        this->m_pngfilename = pngName;
    }
    QString getCurPngName()
    {
        return m_pngfilename;
    }
    
    QString getCurPngPath()
    {
        return m_pngPath;
    }
    
    void my_openExample()
    {
        m_isExample = true;
    }
    
    void my_open(QString path, bool isEmbed , QString pngName)
    {
//        m_pngPath = QString();
//        m_pngfilename = QString();
        my_save(path,isEmbed ,pngName);
    }

    bool isExample()
    {
        return m_isExample;
    }
    
    bool isSaved()
    {
        return m_hasSaved;
    }
    QString getCurrentPath()
    {
        return m_currentPath;
    }

    bool hasLinked2File()
    {
        return m_hasLinked2File;
    }
    
    void my_save(QString path, bool isEmbed , QString pngName)
    {
        this->setWindowTitle(QString(WINDOW_NAME ) + " - "+  path );
        this->m_currentPath = path;
        this->m_isEmbed = isEmbed;
        this->m_pngfilename = pngName;
        this->m_hasSaved = true;
        m_hasLinked2File = true;
        m_isExample = false;
    }
    
    //****end ****//
    
    //need release by the caller.
    //Dictionary <std::string, CCObject *> *getDict();
    ValueMap  getDict();
    
    QPropertyLineEditor * AddProperty(QPropertyLineEditorGroup * group, int id);
	void renewColorButton(QPushButton * btn , int r,int g, int b);
	


private:
    QPropertyLineEditorFactory * m_Factory;
    #define MaxRecentFiles 10
    QAction *recentFileActs[MaxRecentFiles];
};


#endif // PARTICLEEDITORWINDOW_H
