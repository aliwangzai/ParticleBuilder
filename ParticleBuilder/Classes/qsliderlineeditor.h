#ifndef QSLIDERLINEEDITOR_H
#define QSLIDERLINEEDITOR_H

#include <QWidget>
#include "QtGui"
#include "qpropertylineeditor.h"
namespace Ui {
class QSliderLineEditor;
}

class QSliderLineEditor : public IPropertyEditor
{
    Q_OBJECT
    
public:
    explicit QSliderLineEditor(QWidget *parent,int id, QString name,double min, double max, double step);
    ~QSliderLineEditor();
    
    void setValue(double val);
    double getValue();
private slots:
    void on_name_slider_valueChanged(int value);

    
signals :
    void valueChanged(double value);
    
    
private:
    Ui::QSliderLineEditor *ui;


};

#endif // QSLIDERLINEEDITOR_H
