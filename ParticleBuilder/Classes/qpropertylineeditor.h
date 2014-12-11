#ifndef QPROPERTYLINEEDITOR_H
#define QPROPERTYLINEEDITOR_H

#include <QWidget>
#include <QtGui>

namespace Ui {
class QPropertyLineEditor;
}


class IPropertyEditor : public QWidget 
{
    Q_OBJECT
public:
    explicit IPropertyEditor(QWidget* parent = 0):QWidget(parent){}
    int id; 
    virtual void setValue(double val) =0 ;
    virtual double getValue() = 0;
};

class QPropertyLineEditor :public  IPropertyEditor
{
    Q_OBJECT
    
public:

    explicit QPropertyLineEditor(QWidget *parent = 0);
    QPropertyLineEditor(QWidget* parent, int id = 0, QString name = 0  , double min = 100, double max = 1, double step = 1);
    ~QPropertyLineEditor();
    
    QPropertyLineEditor * setDataType(int type);
    
	QPropertyLineEditor * setDisplaySlider(bool bol);
    QPropertyLineEditor * setLabelWidth(int width);
    
    QPropertyLineEditor *setFrame(int shape, int shadow);
public :
    
    void setValue(double val);
    double getValue();

signals :
    void valueChanged(double value);
    
    
private slots:
    
    void on_name_propertyadjust_valueChanged(int value);
    
    void on_name_propertyvalue_valueChanged(double arg1);
    
private:
    Ui::QPropertyLineEditor *ui;
    
};

#endif // QPROPERTYLINEEDITOR_H
