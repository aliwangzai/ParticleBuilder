#ifndef ENTITYMANAGER_H
#define ENTITYMANAGER_H

#include <QtCore>
class EntityManager
{
public:
    EntityManager();
    
    enum RegedObjID
    {
        ID_line_editor_factory
    };
    
    static QMap<int , void *> m_id2obj;
    
    static void reg(int id , void * obj)
    {
        m_id2obj.insert(id , obj);
    }
    static void * get(int id)
    {
        return m_id2obj.value(id);
    }

};

#endif // ENTITYMANAGER_H
