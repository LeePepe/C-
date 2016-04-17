//
//  Relation.cpp
//  C++
//
//  Created by 李天培 on 16/4/9.
//  Copyright © 2016年 lee. All rights reserved.
//

#include "Relation.hpp"

Relation::Relation(BooleanMatrix const & m): matrix(m) {
}

Relation Relation::complementary() const {
    Relation temp(matrix);
    for (int i = 1; i <= matrix.getRow(); i++) {
        for (int j = 1; j <= matrix.getColums(); j++) {
            temp.matrix.replace(!temp.matrix.getElement(i, j), i, j);
        }
    }
    return temp;
}

Relation Relation::inverse() const {
    Relation inverseR(matrix.transpose());
    return inverseR;
}

Relation Relation::operator&(const Relation &r) {
    Relation temp(matrix & r.matrix);
    return temp;
}

Relation Relation::operator|(const Relation &r) {
    Relation temp(matrix | r.matrix);
    return temp;
}