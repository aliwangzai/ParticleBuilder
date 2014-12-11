#include "qsliderlineeditor.h"
#include "ui_qsliderlineeditor.h"

QSliderLineEditor::QSliderLineEditor(QWidget *parent,int id, QString name, double min, double max, double step) :
    IPropertyEditor(parent),
    ui(new Ui::QSliderLineEditor)
{
    ui->setupUi(this); 
    this->id = id;

    ui->name_text->setText(name);
    ui->name_slider->setMinimum(min);
    ui->name_slider->setMaximum(max);
    ui->name_slider->setSingleStep(step);
    
    ui->name_val->setText(QString::number(ui->name_slider->value()));
    

}
 

QSliderLineEditor::~QSliderLineEditor()
{
    delete ui;
}


void QSliderLineEditor::on_name_slider_valueChanged(int value)
{
    ui->name_val->setText(QString::number(value));
    emit this->valueChanged(value);
}


void QSliderLineEditor::setValue(double val)
{
    ui->name_slider->setValue(val);
    ui->name_val->setText(QString::number((int)val));
}

double QSliderLineEditor::getValue()
{
    return ui->name_slider->value();
}

