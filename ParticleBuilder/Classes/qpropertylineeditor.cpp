#include "qpropertylineeditor.h"
#include "ui_qpropertylineeditor.h"

QPropertyLineEditor::QPropertyLineEditor(QWidget *parent,int id, QString name, double min, double max, double step) :
    IPropertyEditor(parent),
    ui(new Ui::QPropertyLineEditor)
{
    ui->setupUi(this);
    this->id = id;
    //default type.
    setDataType(QVariant::Int);
  
    //qDebug()<<m_label->text();
    ui->name_PropertyName->setText(name);
    ui->name_propertyadjust->setMinimum(min);
    ui->name_propertyadjust->setMaximum(max);
    ui->name_propertyadjust->setSingleStep(step);

    ui->name_propertyvalue->setMinimum(min);
    ui->name_propertyvalue->setMaximum(max);
    ui->name_propertyvalue->setSingleStep(step);
    
}



QPropertyLineEditor::~QPropertyLineEditor()
{
    delete ui;
}


QPropertyLineEditor *QPropertyLineEditor::setFrame(int shape ,int shadow)
{
    ui->name_frame->setFrameShadow((QFrame::Shadow)shadow);
    ui->name_frame->setFrameShape((QFrame::Shape)shape);
    return this;
}

void QPropertyLineEditor::setValue(double val)
{
    ui->name_propertyadjust->setValue(val);
    ui->name_propertyvalue->setValue(val);
}

double QPropertyLineEditor::getValue()
{
    return ui->name_propertyvalue->value();
}


QPropertyLineEditor *QPropertyLineEditor::setDataType(int type)
{
    if (type == QVariant::Double)
    {
        ui->name_propertyvalue->setDecimals(2);
    }else if (type == QVariant::Int)
    {
        ui->name_propertyvalue->setDecimals(0);
    }
    return this; 
}


void QPropertyLineEditor::on_name_propertyadjust_valueChanged(int value)
{
    ui->name_propertyvalue->setValue(value);
    emit this->valueChanged(value);
}

void QPropertyLineEditor::on_name_propertyvalue_valueChanged(double value)
{
    ui->name_propertyadjust->setValue(value);
    emit this->valueChanged(value);
}

QPropertyLineEditor * QPropertyLineEditor::setDisplaySlider( bool bol )
{
	ui->name_propertyadjust->setVisible(bol);
	return this;
}

QPropertyLineEditor * QPropertyLineEditor::setLabelWidth( int width )
{
	ui->name_PropertyName->setFixedWidth(width);
	return this;
}
