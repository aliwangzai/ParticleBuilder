#include "qpropertylineeditorfactory.h"

QPropertyLineEditorFactory::QPropertyLineEditorFactory()
{
	m_groups = new QList<QPropertyLineEditorGroup*>();
}

void QPropertyLineEditorFactory::add(QPropertyLineEditorGroup *group)
{
    m_groups->push_back(group);
    connect(group, SIGNAL(propertyValueChanged(IPropertyEditor*,double)) , this,SLOT(changeValue(IPropertyEditor*,double)));
}

IPropertyEditor *QPropertyLineEditorFactory::Property(int id)
{
    for (int i = 0;i <m_groups->length();i++)
    {
        QPropertyLineEditorGroup *group = m_groups->at(i);
        if (group->Contains(id))
            return group->Property(id);

    }
    return 0;
}

