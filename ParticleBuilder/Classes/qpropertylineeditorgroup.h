#ifndef QPROPERTYLINEEDITORGROUP_H
#define QPROPERTYLINEEDITORGROUP_H

#include <QtGui>
#include "qpropertylineeditor.h"
#include <QtCore>
#include "flowlayout.h"

class QPropertyLineEditorFactory;
class QPropertyLineEditorGroup : public QWidget
{
    Q_OBJECT

public:
    FlowLayout * m_FlowLayout;
    QPropertyLineEditorGroup(QWidget *parent , QPropertyLineEditorFactory * factory  = 0);
    
    void setLableAutoFixed();
    
    QMap <QString , IPropertyEditor*> m_name2Editors;
    QMap <int , IPropertyEditor*> m_id2Editors;
    
    void AddProperty(QString name , IPropertyEditor * lineEditor);

    QPropertyLineEditor * AddProperty(int id ,QString name, double min = 0, double max = 100  );

    bool Contains(int id );
    IPropertyEditor *Property(int id );
    QList<QString> allProperties()
    {
        return m_name2Editors.keys();
    }
    void setMargins(int left, int top, int right, int bottom)
    {
        m_FlowLayout->setContentsMargins(left,top,right,bottom);
    }
    
    QList<int> allIds();
    QPropertyLineEditor *AddProperty(IPropertyEditor *pleditor);
    IPropertyEditor *AddHSliderProperty(IPropertyEditor *pleditor);
signals:
    void propertyValueChanged(IPropertyEditor * editor, double value);
    
    
public slots:
    void changeValue(double value);
};

#endif // QPROPERTYLINEEDITORGROUP_H
