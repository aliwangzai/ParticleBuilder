#ifndef QPROPERTYLINEEDITORFACTORY_H
#define QPROPERTYLINEEDITORFACTORY_H

#include <QtCore>
#include "qpropertylineeditor.h"
#include "qpropertylineeditorgroup.h"
class QPropertyLineEditorFactory :public QObject
{
    Q_OBJECT
public:
	QList <QPropertyLineEditorGroup*> *m_groups;
    QPropertyLineEditorFactory();
	~QPropertyLineEditorFactory()
	{
		delete m_groups;
	}

    
    void add(QPropertyLineEditorGroup* group);
    
    IPropertyEditor * Property(int id);
 
signals:
    void propertyValueChanged(IPropertyEditor * editor , double value);
    
public slots:
    void changeValue(IPropertyEditor * editor , double value)
    {
        emit propertyValueChanged(editor , value);
    }

};

#endif // QPROPERTYLINEEDITORFACTORY_H
