//
//  Inheritance.hpp
//  C++
//
//  Created by 李天培 on 16/3/24.
//  Copyright © 2016年 lee. All rights reserved.
//

#ifndef Inheritance_hpp
#define Inheritance_hpp

#include <stdio.h>
#include <iostream>

using namespace std;

class baseA {
public:
    int publicA;
    baseA();
    ~baseA();
};

class baseB {
public:
    int publicB;
    baseB();
    ~baseB();
};

class derivedA: public baseA {
public:
    derivedA();
    ~derivedA();
};

class derivedB: public baseA, public baseB {
public:
    int publicB;
    derivedB();
    ~derivedB();
};

class C: public derivedA, public derivedB {
public:
    int publicB;
    C();
    ~C();
};


#endif /* Inheritance_hpp */
