//
//  Logic.hpp
//  C++
//
//  Created by 李天培 on 16/2/25.
//  Copyright © 2016年 lee. All rights reserved.
//

#ifndef Logic_hpp
#define Logic_hpp

/* p&q
 * p|q
 * ~q
 * & is conjunction
 * | is dijunction
 * ~ is negation
 *
 */

#include <stdio.h>
#include <string>

class Logic {
private:
    char var[2], operation;
    
    std::string formula;
public:
    Logic();
    Logic(std::string formula);
    
    bool inputFormula(std::string formula);
    std::string getFormula();
    std::string getTruthTable();
};



#endif /* Logic_hpp */
