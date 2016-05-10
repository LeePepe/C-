//
//  BinaryTree.hpp
//  C++
//
//  Created by 李天培 on 16/5/4.
//  Copyright © 2016年 lee. All rights reserved.
//

#ifndef BinaryTree_hpp
#define BinaryTree_hpp

#include <iostream>
#include <vector>
#include <queue>
#include <stack>

#define EMPTY_ELE '#'

class BinaryTree {
public:
    struct Node {
        char val;
        Node* left;
        Node* right;
        Node(char v, Node* l = NULL, Node* r = NULL):
        val(v), left(l), right(r) {
        }
    };
    BinaryTree(const BinaryTree&);
    BinaryTree(std::vector<char>&);
    // created by preorder and inorder
    BinaryTree(std::vector<char>& preOrder,
               std::vector<char>& inOrder);
    ~BinaryTree();
    
    Node* getRoot() const;
    void clear();
    
    static void preOrder(void (*visite)(BinaryTree::Node*), Node*);
    static void inOrder(void (*visite)(BinaryTree::Node*), Node*);
    static void postOrder(void (*visite)(BinaryTree::Node*), Node*);
    

private:
    Node * copyTree(Node * oldNode, Node * newNode);
    
    Node * root;
};

#endif /* BinaryTree_hpp */
