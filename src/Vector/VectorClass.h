//
// Created by Vladislav on 12.10.2023.
//

#ifndef ALLOCATOR_VECTORCLASS_H
#define ALLOCATOR_VECTORCLASS_H

#include <iostream>
#include "VectorException.h"

template<typename T>
class VectorClass {
public:

    //region Constructors

    VectorClass(const VectorClass &rhs) :
            pSize(rhs.size()),
            pCapacity(rhs.capacity() + 5),
            pArray(new T[pCapacity]) {
        for (int i = 0; i < rhs.size(); i++) {
            pArray[i] = rhs.pArray[i];
        }
    }

    VectorClass(int elements, T value) :
            pSize(elements),
            pCapacity(elements + 5),
            pArray(new T[pCapacity]) {
        for (int i = 0; i < pSize; i++) {
            pArray[i] = value;
        }
    }

    VectorClass(const std::initializer_list<T> &list) :
            pSize(0),
            pCapacity(list.size() + 5),
            pArray(new T[pCapacity]) {
        for (int i: list) {
            pushBack(i);
        }
    }

    VectorClass() :
            pSize(0),
            pCapacity(2),
            pArray(new T[pCapacity]) {

    }

    ~VectorClass() {
        delete[] pArray;
    }


    //endregion

    //region Methods of interaction

    void resize(const size_t& newSize) {
        if (newSize <= pCapacity) return;
        T *temp = new T[pCapacity];
        memcpy(temp, pArray, sizeof(T) * pSize);
        delete[] pArray;
        pArray = temp;
        pCapacity = newSize;
    }

    void pushBack(const T& value) {
        if (pCapacity == pSize){
            resize(pSize * 2);
        }
        pArray[pSize] = value;
        ++pSize;
    }

    void popBack() {
        if (pSize == 0) {
            throw VectorException("Pop back on empty array!");
        }
        --pSize;
    }

    void insert(int index, T value) {
        if (index >= pSize or index < 0) {
            throw VectorException("Insert - index out of range");
        }
        pArray[index] = value;
    }

    void clear() {
        pSize = 0;
    }

    void erase(int index) {
        if (index < 0 or index >= pSize) {
            throw VectorException("Erase - Index out of range");
        }
        for (int i = index; i < pSize; ++i) {
            pArray[i] = pArray[i + 1];
        }
        --pSize;
    }

    T &At(int index) {
        if (index >= pSize or index < 0) {
            throw VectorException("Out of range");
        }
        return pArray[index];
    }

    T &front() {
        return pArray[0];
    }

    T &back() {
        return pArray[pSize - 1];
    }


    bool empty() const {
        return pSize == 0;
    }

    size_t size() const {
        return pSize;
    }

    size_t capacity() const {
        return pCapacity;
    }

    //endregion

    //region Redefined operators
    bool operator==(const VectorClass &rhs) const {
        if (size() != rhs.size()) {
            return false;
        }

        for (int i = 0; i < size(); i++) {
            if (pArray[i] != rhs.pArray[i]) {
                return false;
            }
        }
        return true;
    }

    bool operator!=(const VectorClass &rhs) const {
        return *this != rhs;
    }

    /*VectorClass& operator = (const VectorClass& rhs) {
        if (rhs.size() > pSize){
            delete [] pArray;
            pCapacity = rhs.pCapacity + 5;
            pArray = new T [pCapacity];
        }

        //memcpy(pArray, rhs, sizeof(T) * pSize);

        return *this;

    }*/
    T operator[](int index) const {
        if (index >= pSize or index < 0) {
            throw VectorException("Out of range");
        }
        return pArray[index];
    }

    friend std::ostream &operator<<(std::ostream &ostr, const VectorClass &rhs) {
        for (int i = 0; i < rhs.size(); ++i) {
            ostr << rhs.pArray[i] << " ";
        }


        ostr << std::endl;

        return ostr;
    }

    //endregion

private:

    //region Variables

    size_t pSize;
    size_t pCapacity;
    T *pArray;

    //endregion

};


#endif //ALLOCATOR_VECTORCLASS_H
