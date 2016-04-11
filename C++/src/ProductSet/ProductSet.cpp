//
//  ProductSet.cpp
//  C++
//
//  Created by 李天培 on 16/4/6.
//  Copyright © 2016年 lee. All rights reserved.
//

#include "ProductSet.hpp"

ProductSet::ProductSet(Set a, Set b) {
    first = a;
    second = b;
}

Set ProductSet::getFirstSet() const {
    return first;
}

Set ProductSet::getSecondSet() const {
    return second;
}
