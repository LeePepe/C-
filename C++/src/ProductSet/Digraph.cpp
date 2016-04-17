//
//  Digraph.cpp
//  C++
//
//  Created by 李天培 on 16/4/7.
//  Copyright © 2016年 lee. All rights reserved.
//

#include "Digraph.hpp"

Digraph::Digraph(BooleanMatrix const &m, Set const &s) : Relation(m) , set(s) {
}

BooleanMatrix Digraph::getBooleanMatrix() const {
    return matrix;
}

int Digraph::inDegree(int x) {
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

int Digraph::outDegree(int x) {
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

int Digraph::getSetElePos(int x) {
    for (int i = 1; i <= set.getSize(); i++) {
        if (set.get(i) == x) return i;
    }
    return -1;
}

Digraph Digraph::pathOfLength(int n) {
    BooleanMatrix tempBM = matrix;
    if (n == -1) {
        while (true) {
            if (tempBM == tempBM.BooleanProduct(matrix)) {
                break;
            }
            tempBM = tempBM.BooleanProduct(matrix);
        }
    } else {
        for (int i = 1; i < n; i++) {
            tempBM = tempBM.BooleanProduct(matrix);
        }
    }
    Digraph temp(tempBM, set);
    return temp;
}

bool Digraph::isReflexive() const {
    for (int i = 1; i <= matrix.getRow(); i++) {
        if (matrix.getElement(i, i) == 0) {
            return false;
        }
    }
    return true;
}

bool Digraph::isIrreflexive() const {
    for (int i = 1; i <= matrix.getRow(); i++) {
        if (matrix.getElement(i, i) == 1) {
            return false;
        }
    }
    return true;
}

bool Digraph::isSymmetric() const {
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

bool Digraph::isAsymmetric() const {
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

bool Digraph::isAntisymmetric() const {
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

bool Digraph::isTransitive() const {
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

