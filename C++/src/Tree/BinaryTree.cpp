//
//  BinaryTree.cpp
//  C++
//
//  Created by 李天培 on 16/5/4.
//  Copyright © 2016年 lee. All rights reserved.
//

#include "BinaryTree.hpp"



BinaryTree::Node* recursionBuild(std::vector<char>& preorder,
                                 unsigned long preLeft,
                                 unsigned long preRight,
                                 std::vector<char>& inorder,
                                 unsigned long inLeft,
                                 unsigned long inRight) {
    if (preLeft > preRight || preRight == preorder.size() ||
        inLeft > inRight || inRight == inorder.size())
        return NULL;
    
    unsigned long i = 0;
    
    BinaryTree::Node* node = new BinaryTree::Node(preorder[preLeft]);
    
    for (i = inLeft; i <= inRight; i++) {
        if (inorder[i] == node->val) {
            break;
        }
    }
    
    node->left =  recursionBuild(preorder,
                                 preLeft + 1, preLeft + i - inLeft,
                                 inorder,
                                 inLeft, i - 1);
    node->right = recursionBuild(preorder,
                                 preLeft + i - inLeft + 1, preRight,
                                 inorder,
                                 i + 1, inRight);
    
    return node;
}


BinaryTree::BinaryTree(const BinaryTree &old) {
    root = NULL;
    root = copyTree(old.getRoot(), root);
}

BinaryTree::BinaryTree(std::vector<char> & preorder,
                       std::vector<char> & inorder) {
    root = NULL;
    unsigned long preSize = preorder.size();
    unsigned long inSize = inorder.size();
    if (preSize == 0 || preSize != inSize) {
        return;
    }
    
    root = recursionBuild(preorder, 0, preSize - 1,
                          inorder, 0, inSize - 1);
}



BinaryTree::BinaryTree(std::vector<char> & elements) {
    unsigned long size = elements.size();
    int index = 0;
    std::queue<Node*> queue;
    if (elements.empty() ||elements[index] == EMPTY_ELE) {
        root = NULL;
    } else {
        root = new Node(elements[index]);
        queue.push(root);
        index += 1;
        while (index < size && !queue.empty()) {
            Node* temp = queue.front();
            queue.pop();
            if (elements[index] != EMPTY_ELE) {
                temp->left = new Node(elements[index]);
                queue.push(temp->left);
            }
            index += 1;
            if (index >= size) {
                break;
            }
            if (elements[index] != EMPTY_ELE) {
                temp->right = new Node(elements[index]);
                queue.push(temp->right);
            }
            index += 1;
        }
    }
}

BinaryTree::Node* BinaryTree::copyTree(BinaryTree::Node *oldNode,
                                       BinaryTree::Node *newNode) {
    if (oldNode == NULL) {
        newNode = NULL;
        return newNode;
    }
    
    newNode = new Node(oldNode->val);
    newNode->left = copyTree(oldNode->left, newNode->left);
    newNode->right = copyTree(oldNode->right, oldNode->right);
    return newNode;
}


BinaryTree::Node* BinaryTree::getRoot() const {
    return root;
}

BinaryTree::~BinaryTree() {
    clear();
}

void BinaryTree::clear() {
    std::queue<Node*> queue;
    if (root != NULL) {
        queue.push(root);
    }
    while (!queue.empty()) {
        Node * temp = queue.front();
        queue.pop();
        if (temp->left != NULL)
            queue.push(temp->left);
        if (temp->right != NULL)
            queue.push(temp->right);
        delete temp;
    }
}

void BinaryTree::preOrder(void (*visite)(Node*), Node * r = NULL) {
    Node *temp = r;
    if (temp == NULL) {
        return;
    } else {
        visite(temp);
        preOrder(visite, temp->left);
        preOrder(visite, temp->right);
    }
}

void BinaryTree::inOrder(void (*visite)(Node*), Node * r = NULL) {
    Node *temp = r;
    if (temp == NULL) {
        return;
    } else {
        inOrder(visite, temp->left);
        visite(temp);
        inOrder(visite, temp->right);
    }
}

void BinaryTree::postOrder(void (*visite)(Node*), Node * r = NULL) {
    Node *temp = r;
    if (temp == NULL) {
        return;
    } else {
        postOrder(visite, temp->left);
        postOrder(visite, temp->right);
        visite(temp);
    }
}


