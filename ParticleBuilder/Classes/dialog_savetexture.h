#ifndef DIALOG_SAVETEXTURE_H
#define DIALOG_SAVETEXTURE_H

#include <QDialog>
#include "QtGui"
namespace Ui {
class Dialog_SaveTexture;
}

class Dialog_SaveTexture : public QDialog
{
    Q_OBJECT
    
public:
    explicit Dialog_SaveTexture(QString defaultText , QWidget *parent = 0);
    ~Dialog_SaveTexture();
    enum Option{ Embed , SaveAs};
    QString  getFileName();
    int getOption(){return m_optionId ;}
private slots:
    void on_name_option_embed_toggled(bool checked);
    
    void on_name_option_save_toggled(bool checked);
    
    
    
    void on_buttonBox_accepted();
    
private:
    int m_optionId;
    Ui::Dialog_SaveTexture *ui;
};

#endif // DIALOG_SAVETEXTURE_H
