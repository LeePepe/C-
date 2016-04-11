//
//  main.cpp
//  C++
//
//  Created by 李天培 on 16/2/25.
//  Copyright © 2016年 lee. All rights reserved.
//

#include "header.h"

using std::cin;
using std::cout;
using std::endl;
using std::string;

void displayProductSet(ProductSet temp) {
    int *a, *b;
    
    a = temp.getFirstSet().getMembers();
    b = temp.getSecondSet().getMembers();
    
    cout << "{";
    for (int i = 0; i < temp.getFirstSet().getSize(); i++) {
        for (int j = 0; j < temp.getSecondSet().getSize(); j++) {
            cout << ((i + j) != 0 ? "," : "")
            << "(" << a[i] << "," << b[j] << ")";
        }
    }
    cout << "}" << endl;
}

void displaySet(int* members, int size) {
    std::sort(members, members + size);
    std::cout << "{";
    for (int i = 0; i < size; i++) {
        if (i < size - 1) std::cout << members[i] << ", ";
        else std::cout << members[i];
    }
    std::cout << "}" << std::endl;
}

void testBooleanMatrix() {
    cout << "TEST BOOLEAN MATRIX" << endl;

    int r = 0, c = 0;
    cin >> r >> c;
    BooleanMatrix m1(r, r);
    BooleanMatrix m2(r, r);
    BooleanMatrix m3(r, c);
    
    for (int i = 1; i <= r; i++) {
        for (int j = 1; j <= r; j++) {
            int t = 0;
            cin >> t;
            m1.replace(t, i, j);
        }
    }
    for (int i = 1; i <= r; i++) {
        for (int j = 1; j <= r; j++) {
            int t = 0;
            cin >> t;
            m2.replace(t, i, j);
        }
    }
    
    
    for (int i = 1; i <= r; i++) {
        for (int j = 1; j <= c; j++) {
            int t = 0;
            cin >> t;
            m3.replace(t, i, j);
        }
    }
    
    m1.display();
    m2.display();
    m3.display();
    (m1 | m2).display();
    (m1 & m2).display();
    (m1.BooleanProduct(m3)).display();
    
}

void testDigraph() {
    cout << "TEST DIGRAPH" << endl;
    BooleanMatrix matrix(5, 5);
    for (int i = 1; i <= 5; i++) {
        for (int j = 1; j <= 5; j++) {
            bool t = true;
            int x;
            cin >> x;
            t = (x == 1) ? 1 : 0;
            matrix.replace(t, i, j);
        }
    }
    
    Set set;
    int test[5];
    for (int i = 0; i < 5; i++) {
        cin >> test[i];
        set.append(test[i]);
    }
    
    Digraph d(matrix, set);
    int x;
    cin >> x;
    cout << test[x] << "'s in degree" << d.inDegree(test[x]) << endl;
    
    cin >> x;
    cout << test[x] << "'s out degree" << d.outDegree(test[x]) << endl;
    
    matrix.display();
}

void testProductSet() {
    Set a;
    Set b;
    
    int n = 0;
    // number of set a
    cin >> n;
    for (int i = 0; i < n; i++) {
        int temp = 0;
        cin >> temp;
        a.append(temp);
    }
    
    // number of set b
    cin >> n;
    for (int i = 0; i < n; i++) {
        int temp = 0;
        cin >> temp;
        b.append(temp);
    }
    
    ProductSet test(a, b);
    displaySet(test.getFirstSet().getMembers(), test.getFirstSet().getSize());
    displaySet(test.getSecondSet().getMembers(), test.getSecondSet().getSize());
    
    displayProductSet(test);
}

int main() {
    testBooleanMatrix();
    testDigraph();
    testProductSet();
}

//int main() {
//    cout << "\ncreat base A" << endl;
//    baseA ba;
//    cout << "\ncreat base B" << endl;
//    baseB bb;
//    cout << "\ncreat derived A" << endl;
//    derivedA da;
//    cout << "\ncreat derived B" << endl;
//    derivedB db;
//    cout << "\ncreat C" << endl;
//    C c;
//    cout << "\ndestructor" << endl;
//
//    
//    return 0;
//}

//int main() {
//    int row = 1, columns = 1;
//    cin >> row >> columns;
//    
//    cout << "\ntest constructor" << endl;
//    Matrix m1(row, columns);
//    m1.display();
//    
//    cout << "\ntest replace" << endl;
//    for (int i = 1; i <= row; i++) {
//        for (int j = 1; j <= columns; j++) {
//            m1.replace(ELEMENT_POS(i, j) + 1, i, j);
//        }
//    }
//    m1.display();
//    
//    cout << "\ntest copy constructor" << endl;
//    Matrix m2(m1);
//    m2.display();
//    
//    cout << "\ntest zero matric" << endl;
//    Matrix m3(columns, row);
//    
//    cout << "m3 is zero Matric: " << m3.isZeroMatrix() << endl;
//    cout << "m1 is zero Matric: " << m1.isZeroMatrix() << endl;
//    
//    cout << "\ntest identifyMatrix" << endl;
//    m3 = Matrix::identifyMatrix(row);
//    m3.display();
//    
//    cout << "\ntest diagonal matric" << endl;
//    m2 = Matrix(1, 2);
//    cout << "m2 is diagonal Matric: " << m2.isDiagonalMatrix() << endl;
//    m2 = Matrix(3, 3);
//    cout << "m2 is diagonal Matric: " << m2.isDiagonalMatrix() << endl;
//    m2.replace(3, 2, 1);
//    cout << "m2 is diagonal Matric: " << m2.isDiagonalMatrix() << endl;
//    
//    cout << "\ntest zero matrix" << endl;
//    cout << "m2 is zero Matric: " << m2.isZeroMatrix() << endl;
//    m2 = Matrix(1, 2);
//    cout << "m2 is zero Matric: " << m2.isZeroMatrix() << endl;
//    
//    cout << "\ntest square matrix" << endl;
//    cout << "m2 is square Matric: " << m2.isSquareMatrix() << endl;
//    m2 = Matrix(2, 2);
//    cout << "m2 is square Matric: " << m2.isSquareMatrix() << endl;
//
//    cout << "\ntest symmetrix matrix" << endl;
//    cout << "m2 is symmetrix Matric: " << m2.isSymmetrix() << endl;
//    m2.replace(1, 1, 1);
//    cout << "m2 is symmetrix Matric: " << m2.isSymmetrix() << endl;
//    m2.replace(1, 2, 1);
//    cout << "m2 is symmetrix Matric: " << m2.isSymmetrix() << endl;
//    
//    cout << "\ntest *" << endl;
//    Matrix t1(2, 3);
//    Matrix t2(3, 2);
//    t1.replace(2, 1, 1);
//    t1.replace(3, 1, 2);
//    t1.replace(-4, 1, 3);
//    t1.replace(1, 2, 1);
//    t1.replace(2, 2, 2);
//    t1.replace(3, 2, 3);
//    t2.replace(3, 1, 1);
//    t2.replace(1, 1, 2);
//    t2.replace(-2, 2, 1);
//    t2.replace(2, 2, 2);
//    t2.replace(5, 3, 1);
//    t2.replace(-3, 3, 2);
//
//    t1.display();
//    t2.display();
//    m1 = t1 * t2;
//    m1.display();
//    
//    cout << "\ntest +" << endl;
//    Matrix t3(2, 3);
//    t3.replace(2, 1, 1);
//    t3.replace(3, 1, 2);
//    t3.replace(-4, 1, 3);
//    t3.replace(1, 2, 1);
//    t3.replace(2, 2, 2);
//    t3.replace(3, 2, 3);
//    
//    t1.display();
//    t3.display();
//    m1 = t1 + t3;
//    m1.display();
//    
//    cout << "\ntest ==" << endl;
//    cout << "t1 == t3: " << (t1 == t3) << endl;
//    
//    cout << "\ntest transpose" << endl;
//    m1.display();
//    m1.transpose().display();
//    
//    cout << "\ntest get" << endl;
//    cout << "m1:"
//    << "\nrow: " << m1.getRow()
//    << "\ncol: " << m1.getColums()
//    << "\nget element with row and col: " << m1.getElement(m1.getRow(), m1.getColums())
//    << endl;
//    m1.display();
//    
//    return 0;
//}
