#include "dialog_savetexture.h"
#include "ui_dialog_savetexture.h"

Dialog_SaveTexture::Dialog_SaveTexture(QString defaultText, QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Dialog_SaveTexture)
{
    ui->setupUi(this);
    ui->m_filename->setText(defaultText);
    ui->m_option_embed->setChecked(true);
}
QString Dialog_SaveTexture::getFileName()
{
    return ui->m_filename->text();
}

Dialog_SaveTexture::~Dialog_SaveTexture()
{
    delete ui;
}

void Dialog_SaveTexture::on_name_option_embed_toggled(bool checked)
{
    if (checked )
    {
        ui->m_filename->setEnabled(false);
        
    }
}

void Dialog_SaveTexture::on_name_option_save_toggled(bool checked)
{
    if (checked )
    {
        ui->m_filename->setEnabled(true);

    }
}

void Dialog_SaveTexture::on_buttonBox_accepted()
{
    if (ui->m_option_embed->isChecked())
    {
        m_optionId = Embed;
    }
    else if (ui->m_option_save->isChecked())
    {
        m_optionId = SaveAs;
    }
    
}
