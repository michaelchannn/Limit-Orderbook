#include "HFTLOB.h"

// constructor for book class
Book::Book(): buyTree(nullptr), sellTree(nullptr), highestBuy(nullptr), lowestSell(nullptr) {}

// helper function to insert a new limit into BST 
Limit* Book::addNewLimit (Limit* root, Limit* newLimit) {
    // if tree is empty
    if (root == nullptr) {
        return newLimit;
    }
    // if tree is NOT empty
    Limit* current = root;
    Limit* parent = nullptr;
    while (current) {
        parent = current;
        if (newLimit->limitPrice < current->limitPrice) {
            current = current->leftChild;
        } 
        else {
            current = current->rightChild;
        }
    }
    newLimit->parent = parent;
    if (newLimit->limitPrice < parent->limitPrice) {
        parent->leftChild = newLimit;
    }
    else {
        parent->rightChild = newLimit;
    }
    return root;
}

// helper function to find max element in BST. iterative implementation
Limit* Book::findMax(Limit* root) const {
    while (root && root->rightChild != nullptr) {
        root = root->rightChild;
    }
    return root;
}

// helper function to find min element in BST. iterative implementation
Limit* Book::findMin(Limit* root) const {
    while (root && root->leftChild != nullptr) {
        root = root->leftChild;
    }
    return root;
}



