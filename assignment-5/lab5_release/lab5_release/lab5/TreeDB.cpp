
#include <iostream>
#include <sstream>
#include <string>
#include <stdio.h>

using namespace std;

#include "TreeDB.h"

/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
TreeDB::TreeDB() {
    (*this).root = NULL;
    (*this).probesCount = 0;
}

TreeDB::~TreeDB(){
    if (root == NULL) return;
    delete_tree(root);
    root = NULL;
}

// helper function to facilitate recursion
void TreeDB::delete_tree(TreeNode* treeNode) {
    // base case
    if (treeNode == NULL) return;
    
    // else there is at least one node
    
    // delete left subtree
    delete_tree(treeNode->getLeft());
    
    // delete right subtree
    delete_tree(treeNode->getRight());
    
    // delete the node
    delete treeNode;
}

bool TreeDB::insert(DBentry* newEntry){
    if (newEntry == NULL) return false; // nothing to insert
    if (root == NULL) {
        // base case
        TreeNode* newNode = new TreeNode(newEntry);
        root = newNode;
        return true;
    }
    
    return insert_BST(newEntry, root);
}


bool TreeDB::insert_BST(DBentry* entry, TreeNode* root){
    // base case
    if (root == NULL) {
        root = new TreeNode(entry);
        return true;
    }
    
    if (entry->getName().compare(root->getEntry()->getName()) == 0) {
        return false; // key(name) exists
    }
    
    if (entry->getName().compare(root->getEntry()->getName()) < 0) {
        // entry has key less than current node
        if (root->getLeft() == NULL){
            // no left child
            TreeNode* newLeft = new TreeNode(entry);
            root->setLeft(newLeft);
            return true;
        } else {
            return insert_BST(entry, root->getLeft());
        }
    } else {
        // entry has key greater than current node
        if (root->getRight() == NULL) {
            // no right child
            TreeNode* newRight = new TreeNode(entry);
            root->setRight(newRight);
            return true;
        } else {
            return insert_BST(entry, root->getRight());
        }
        
    }
}

DBentry* TreeDB::find(string name){
    probesCount = 0;
    return search_BST(name, root);
}

DBentry* TreeDB::search_BST(string name, TreeNode* root) {
    if (root == NULL) return NULL;
    
    if (root->getEntry()->getName().compare(name) == 0) {
        probesCount = probesCount + 1;
        return root->getEntry();
    } else if (root->getEntry()->getName().compare(name) < 0) {
        probesCount = probesCount + 1;
        return search_BST(name, root->getRight());
    } else {
        probesCount = probesCount + 1;
        return search_BST(name, root->getLeft());
    }
}

bool TreeDB::remove(string name) {
    if (root == NULL) return false;
    
    return remove_BST(name, root);
    
}

void TreeDB::findParent(TreeNode*& curr, string name, TreeNode*& parent) {
    while (curr != NULL && curr->getEntry()->getName().compare(name) != 0) {
        parent = curr;
        
        // if name is less than the current treenode, go to left subtree
        if (name.compare(curr->getEntry()->getName()) < 0) {
            curr = curr->getLeft();
        } 
        
        // name is greater than current treenode, go to right subtree
        else {
            curr = curr->getRight();
        }
    }
}

bool TreeDB::remove_BST(string name, TreeNode*& root) {
    // pointer to store parent node of current node
    TreeNode* parent = NULL;
    
    // start with root
    TreeNode* curr = root;
    
    // search for the node in the BST and set its parent
    findParent(curr, name, parent);
    
    // return false if not found in BST
    if (curr == NULL) {
        return false;
    }
    
    // three cases to consider
    
    // 1. treenode to be deleted has no children
    if (curr->getLeft() == NULL && curr->getRight() == NULL) {
        // if node to be deleted is not a root node
        // set its children to NULL
        if (curr != root) {
            if (parent->getLeft() == curr) {
                parent->setLeft(NULL);
            } else {
                parent->setRight(NULL);
            }
        } 
        // to be deleted is root
        else {
            root = NULL;
        }
        
        delete curr;
    }
    
    // 2. has two children
    else if (curr->getLeft() && curr->getRight()) {
        TreeNode* maxNodeLeft = maxNode(curr->getLeft());
        
        // store value of the node to be moved to position to be deleted
        string name = maxNodeLeft->getEntry()->getName();
        unsigned int ipAddress = maxNodeLeft->getEntry()->getIPaddress();
        bool status = maxNodeLeft->getEntry()->getActive();
        
        remove_BST(maxNodeLeft->getEntry()->getName(), root);
        
        // copy value of the treenode to current treenode
        curr->getEntry()->setName(name);
        curr->getEntry()->setActive(status);
        curr->getEntry()->setIPaddress(ipAddress);  
    }
    
    // 3. treenode to be deleted has only one child
    else {
        TreeNode* child = (curr->getLeft()) ? curr->getLeft() : curr->getRight();
        // if treenode to be deleted is not root
        if (curr != root) {
            if (curr == parent->getLeft()) {
                if (curr->getLeft())
                    parent->setLeft(curr->getLeft());
                else
                    parent->setLeft(curr->getRight());
            } else {
                if (curr->getLeft())
                    parent->setRight(curr->getLeft());
                else
                    parent->setRight(curr->getRight());
            }
        }
        // else if tree node to be deleted is root
        else {
            root = child;
        }
        
        delete curr;
    }    
}

TreeNode* TreeDB::maxNode(TreeNode* root) {
    TreeNode* tmp = root;
    
    if (tmp == NULL) return NULL;
    
    // loop to the right most leaf node
    while(tmp->getRight() != NULL) {
        tmp = tmp->getRight();
    }
    
    return tmp;
}



void TreeDB::printProbes() const {
    cout << probesCount << endl;
}

void TreeDB::clear() {
    delete_tree(root);
    root = NULL;
}

void TreeDB:: countActive() const {
    cout << count_active_BST(root) << endl;    
}

int TreeDB::count_active_BST(TreeNode* root) const {
    if (root == NULL) return 0;
    
    if (root->getEntry()->getActive()) // active entry
        return 1 + count_active_BST(root->getLeft()) + count_active_BST(root->getRight());
    else
        return 0 + count_active_BST(root->getLeft()) + count_active_BST(root->getRight());
}

ostream& operator<< (ostream& out, const TreeDB& rhs) {
    return rhs.inorder_BST(out, rhs.root);
}

ostream& TreeDB::inorder_BST(ostream& out, const TreeNode* cur) const{
    if (cur != NULL) {
        inorder_BST(out, cur->getLeft());
        if (cur->getEntry() != NULL)
            out << *(cur->getEntry());
        inorder_BST(out, cur->getRight());
    }
    
    return out;
}



