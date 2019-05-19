#ifndef UTILITIES_OBJECTMOCKS_H
#define UTILITIES_OBJECTMOCKS_H

#include "Object.h"

class ObjectSubClass;
typedef std::shared_ptr<ObjectSubClass> ObjectSubClassPtr;
class ObjectSubClass : public Object{
public:
    static ObjectSubClassPtr getNewInstance(){
        return ObjectSubClassPtr(new ObjectSubClass());
    }
    virtual ~ObjectSubClass() {}
protected:
    ObjectSubClass() : Object() {}
};

class ObjectDummy;
typedef std::shared_ptr<ObjectDummy> ObjectDummyPtr;
class ObjectDummy : public Object{
public:
    static ObjectDummyPtr getNewInstance(){
        return ObjectDummyPtr(new ObjectDummy());
    }
    virtual ~ObjectDummy() {}
protected:
    ObjectDummy() : Object() {}
};

#endif //UTILITIES_OBJECTMOCKS_H