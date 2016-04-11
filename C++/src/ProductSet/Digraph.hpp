//
//  Digraph.hpp
//  C++
//
//  Created by 李天培 on 16/4/7.
//  Copyright © 2016年 lee. All rights reserved.
//

#ifndef Digraph_hpp
#define Digraph_hpp

#include <stdio.h>
#include "../Matrices/BooleanMatrix.hpp"
#include "../Set/Set.hpp"
#include "ProductSet.hpp"
#include "Relation.hpp"

class Digraph: Relation {
private:
    Set set;
    int getSetElePos(int);
public:
    Digraph(BooleanMatrix &m, Set &s);
    int inDegree(int);
    int outDegree(int);
    
    Digraph pathOfLength(int);
    
    // Properties of Relations.    
    bool isReflexive() const;
    bool isIrreflexive() const;
    bool isSymmetric() const;
    bool isAsymmetric() const;
    bool isAntisymmetric() const;
};

#endif /* Digraph_hpp */
