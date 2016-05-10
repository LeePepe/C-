//
//  MinimalSpanningTrees.hpp
//  C++
//
//  Created by 李天培 on 16/5/9.
//  Copyright © 2016年 lee. All rights reserved.
//

#ifndef MinimalSpanningTrees_hpp
#define MinimalSpanningTrees_hpp

#include "../Matrix/Matrix.hpp"

Matrix prim(const Matrix graph) {
    assert(graph.getRow() == graph.getColums());
    int n = graph.getRow(); // node count.
    Matrix tree(n, n);
    
    
    
    return tree;
}

#endif /* MinimalSpanningTrees_hpp */
