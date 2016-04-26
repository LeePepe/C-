//
//  BinaryRelation.cpp
//  C++
//
//  Created by 李天培 on 16/4/7.
//  Copyright © 2016年 lee. All rights reserved.
//

#include "BinaryRelation.hpp"

BinaryRelation::BinaryRelation(BooleanMatrix const &m, Set const &s) : Relation(m) , set(s) {
}


int BinaryRelation::inDegree(int x) {
    if (set.isInSet(x)) {
        int pos = getSetElePos(x);
        int sum = 0;
        for (int i = 1; i <= matrix.getRow(); i++) {
            sum += matrix.getElement(i, pos);
        }
        return sum;
    }
    return -1;
}

int BinaryRelation::outDegree(int x) {
    if (set.isInSet(x)) {
        int pos = getSetElePos(x);
        int sum = 0;
        for (int i = 1; i <= matrix.getColums(); i++) {
            sum += matrix.getElement(pos, i);
        }
        return sum;
    }
    return -1;
}

int BinaryRelation::getSetElePos(int x) {
    for (int i = 1; i <= set.getSize(); i++) {
        if (set.get(i) == x) return i;
    }
    return -1;
}

BinaryRelation BinaryRelation::pathOfLength(int n) {
    BooleanMatrix tempBM = matrix;
    for (int i = 1; i < n; i++) {
        tempBM = tempBM.BooleanProduct(matrix);
    }
    BinaryRelation temp(tempBM, set);
    return temp;
}

bool BinaryRelation::isReflexive() const {
    for (int i = 1; i <= matrix.getRow(); i++) {
        if (matrix.getElement(i, i) == 0) {
            return false;
        }
    }
    return true;
}

bool BinaryRelation::isIrreflexive() const {
    for (int i = 1; i <= matrix.getRow(); i++) {
        if (matrix.getElement(i, i) == 1) {
            return false;
        }
    }
    return true;
}

bool BinaryRelation::isSymmetric() const {
    for (int i = 1; i <= matrix.getRow(); i++) {
        for (int j = 1; j <= matrix.getColums(); j++) {
            if (matrix.getElement(i, j) == 1 &&
                matrix.getElement(j, i) == 0) {
                return false;
            }
        }
    }
    return true;
}

bool BinaryRelation::isAsymmetric() const {
    for (int i = 1; i <= matrix.getRow(); i++) {
        for (int j = 1; j <= matrix.getColums(); j++) {
            if (matrix.getElement(i, j) == 1 &&
                matrix.getElement(j, i) == 1) {
                return false;
            }
        }
    }
    return true;
}

bool BinaryRelation::isAntisymmetric() const {
    for (int i = 1; i <= matrix.getRow(); i++) {
        for (int j = 1; j <= matrix.getColums(); j++) {
            if (i != j &&
                matrix.getElement(i, j) == 1 &&
                matrix.getElement(j, i) == 1) {
                return false;
            }
        }
    }
    return true;
}

bool BinaryRelation::isTransitive() const {
    for (int i = 1; i <= matrix.getRow(); i++) {
        for (int j = 1; j <= matrix.getColums(); j++) {
            for (int k = 1; k <= matrix.getRow(); k++) {
                if (matrix.getElement(i, k) == 1 &&
                    matrix.getElement(k, j) == 1 &&
                    matrix.getElement(i, j) == 0) {
                    return false;
                }
            }
        }
    }
    return true;
}

bool BinaryRelation::isEquivalence() const {
    return ((*this).isReflexive() &&
            (*this).isSymmetric() &&
            (*this).isTransitive());
}

BinaryRelation BinaryRelation::composition(const BinaryRelation & br) {
    BooleanMatrix m = matrix.BooleanProduct(br.getBooleanMatrix());
    return BinaryRelation(m, set);
}

BinaryRelation BinaryRelation::reflexiveClosure() const {
    int size
    BooleanMatrix identify(matrix.getRow(), matrix.getColums());
    for (int i = 1; i <= identify.getRow(); i++) {
        identify.replace(1, i, i);
    }
    return BinaryRelation(identify | matrix, set);
}

BinaryRelation BinaryRelation::symmetricClosure() const {
    return BinaryRelation(inverse().getBooleanMatrix() | matrix, set);
}

BinaryRelation BinaryRelation::transitiveClosure() const {
    int n = matrix.getRow();
    BooleanMatrix temp(matrix);
    for (int k = 1; k <= n; k++) {
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= n; j++) {
                temp.replace(temp.getElement(i, j) |
                             (temp.getElement(i, k) &
                              temp.getElement(k, j)),
                             i, j);
            }
        }
    }
    return BinaryRelation(temp, set);
}

