#include "qpropertylineeditorgroup.h"
#include "qpropertylineeditorfactory.h"

QPropertyLineEditorGroup::QPropertyLineEditorGroup(QWidget *parent   , QPropertyLineEditorFactory * factory ):QWidget(parent)
{
    m_FlowLayout = new FlowLayout(this ,-1,  0);
    m_FlowLayout->setContentsMargins(0, 12 ,-1,-1);

    factory->add(this);
}


QPropertyLineEditor *QPropertyLineEditorGroup::AddProperty(int id, QString name, double min, double max)
{
    QPropertyLineEditor * pleditor = new QPropertyLineEditor(this ,id , name, min , max , (max - min) /100);
    m_id2Editors.insert(id , pleditor);
    m_FlowLayout->addWidget(pleditor);
    connect(pleditor,SIGNAL(valueChanged(double)), this, SLOT(changeValue(double)));
    return pleditor;
}


IPropertyEditor *QPropertyLineEditorGroup::AddHSliderProperty(IPropertyEditor * pleditor)
{
    m_id2Editors.insert(pleditor->id , pleditor);
    m_FlowLayout->addWidget(pleditor);
    connect(pleditor,SIGNAL(valueChanged(double)), this, SLOT(changeValue(double)));
    return pleditor;
}



bool QPropertyLineEditorGroup::Contains(int id)
{
    return m_id2Editors.contains(id);
}

QList<int> QPropertyLineEditorGroup::allIds()
{
    return m_id2Editors.keys();
}

IPropertyEditor *QPropertyLineEditorGroup::Property(int id)
{
    return m_id2Editors.value(id);
}

void QPropertyLineEditorGroup::changeValue(double value)
{
    emit propertyValueChanged(dynamic_cast<IPropertyEditor*>(sender()) , value);
}
