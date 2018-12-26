/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
#include "TreeNode.h"

TreeNode::TreeNode(DBentry* _entryPtr) {
    (*this).entryPtr = _entryPtr;
    (*this).left = NULL;
    (*this).right = NULL;
}

TreeNode::~TreeNode(){
    delete entryPtr;
}

DBentry* TreeNode::getEntry() const {
    return (*this).entryPtr;
}

TreeNode* TreeNode::getLeft() const {
    return (*this).left;
}

TreeNode* TreeNode::getRight() const {
    return (*this).right;
}

void TreeNode::setLeft(TreeNode* newLeft) {
    (*this).left = newLeft;
}

void TreeNode::setRight(TreeNode* newRight) {
    (*this).right = newRight;
}
