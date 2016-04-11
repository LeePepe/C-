//
//  Logic.cpp
//  C++
//
//  Created by 李天培 on 16/2/25.
//  Copyright © 2016年 lee. All rights reserved.
//

#include "Logic.hpp"

Logic::Logic() {
    formula = "";
}

Logic::Logic(std::string f) {
    formula = f;
    
}

bool Logic::inputFormula(std::string f) {
    formula = f;
    return true;
}

std::string Logic::getFormula() {
    return formula;
}

std::string Logic::getTruthTable() {
    for (int index = 0; index < formula.length(); index++) {
        if (formula[index] == '~') {
            
        }
    }
    return "";
}

