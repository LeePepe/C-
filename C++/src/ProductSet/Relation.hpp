//
//  Relation.hpp
//  C++
//
//  Created by 李天培 on 16/4/9.
//  Copyright © 2016年 lee. All rights reserved.
//

#ifndef Relation_hpp
#define Relation_hpp

#include <iostream>
#include "../Matrix/BooleanMatrix.hpp"

class Relation {
protected:
    BooleanMatrix matrix;
public:
    Relation(BooleanMatrix const &);
    
};
#endif /* Relation_hpp */
