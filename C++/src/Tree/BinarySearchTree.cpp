//
//  BinarySearchTree.cpp
//  C++
//
//  Created by 李天培 on 16/5/10.
//  Copyright © 2016年 lee. All rights reserved.
//

#include "BinarySearchTree.hpp"

BinarySearchTree::BinarySearchTree() {
    root = NULL;
}

BinarySearchTree::BinarySearchTree(const std::vector<int> & elements) {
    root = NULL;
    unsigned long size = elements.size();
    for (int i = 0; i < size; i++) {
        insertNode(elements[i]);
    }
}

bool BinarySearchTree::insertNode(int element) {
    Node *temp = root;
    if (temp == NULL) {
        temp = new Node(element);
        root = temp;
        return true;
    } else {
        while (temp != NULL) {
            if (temp->val == element) {
                return false;
            } else if (temp->val > element) {
                if (temp->left == NULL) {
                    temp->left = new Node(element);
                    return true;
                } else {
                    temp = temp->left;
                }
            } else {
                if (temp->right == NULL) {
                    temp->right = new Node(element);
                    return true;
                } else {
                    temp = temp->right;
                }
            }
        }
    }
    return false;
}

bool BinarySearchTree::searchNode(int element) {
    Node *temp = root;
    while (temp != NULL) {
        if (temp->val == element) {
            return true;
        } else if (temp->val > element) {
            temp = temp->left;
        } else {
            temp = temp->right;
        }
    }
    return false;
}

bool BinarySearchTree::deleteNode(int element) {
    Node *temp = root;
    Node *parent = root;
    while (temp != NULL) {
        if (temp->val == element) {
            // delete element
            if (temp->left == NULL && temp->right == NULL) {
                if (parent->left == temp) {
                    parent->left = NULL;
                } else {
                    parent->right = NULL;
                }
                delete temp;
            } else if (temp->left == NULL) {
                if (parent->left == temp) {
                    parent->left = temp->right;
                } else {
                    parent->right = temp->right;
                }
                delete temp;
            } else if (temp->right == NULL) {
                if (parent->left == temp) {
                    parent->left = temp->left;
                } else {
                    parent->right = temp->left;
                }
                delete temp;
            } else {
                Node *s = temp->left;
                Node *q = temp;
                while (s->right != NULL) {
                    q = s;
                    s = s->right;
                }
                temp->val = s->val;
                if (q != temp) {
                    q->right = s->left;
                } else {
                    q->left = s->left;
                }
            }
            // finish delete
            return true;
        } else if (temp->val > element) {
            parent = temp;
            temp = temp->left;
        } else {
            parent = temp;
            temp = temp->right;
        }
    }
    return false;
}

BinarySearchTree::Node* BinarySearchTree::getRoot() const {
    return root;
}
