#ifndef QTVIEW_MYQUTILITIES_H
#define QTVIEW_MYQUTILITIES_H

#include <vector>
#include <QVector>

class MyQUtilities {
public:
    template<class T>
    static QVector<T> transformToQVector(std::vector<T> vector) {
        QVector<T> qVector;

        for (int i = 0; i < vector.size(); i++)
            qVector.push_back(vector[i]);

        return qVector;
    }
};

#endif //QTVIEW_MYQUTILITIES_H