#ifndef UTILITIES_SUBJECT_H
#define UTILITIES_SUBJECT_H

#include <memory>
#include <utilities/utilities_Export.h>
#include <vector>

class Observer;

class Subject;
typedef std::shared_ptr<Subject> SubjectPtr;
class utilities_EXPORT Subject {
protected:
    Subject(){};
public:
    virtual ~Subject(){};

public:
    virtual void attach(std::shared_ptr<Observer> observer);
    virtual void detach(std::shared_ptr<Observer> observer);
protected:
    virtual void notify();
private:
    virtual std::shared_ptr<Observer> getLockedObserver(int index);
    virtual void removeObserver(int index);

    std::vector<std::weak_ptr<Observer> > observers;
};



#endif //UTILITIES_SUBJECT_H