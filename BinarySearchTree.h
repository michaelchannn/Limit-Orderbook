#ifndef BINARY_SEARCH_TREE_H
#define BINARY_SEARCH_TREE_H

#include <iostream>
#include <queue>

// define node class
class Node {
    public: 
        int data{}; // value of node
        Node* left {}; // pointer to left node
        Node* right {}; // pointer to right node

       
        Node(int value); // constructor
};

class BinarySearchTree {
    private:
        Node* root {};
        
        Node* insertHelper(Node* node, int value);
        bool containsHelper(Node* node, int value) const;
        int findHeightHelper(Node* root) const;
        void preOrderTraversalHelper(Node* root) const;
        void inOrderTraversalHelper(Node* root) const;
        void postOrderTraversalHelper(Node* root) const;
        bool isBinarySearchTreeHelper(Node* root, int minValue, int maxValue) const;
        Node* deleteNodeHelper(Node* root, int value);
        Node* minHelper(Node* root) const;
        Node* maxHelper(Node* root) const;
        Node* findHelper(Node* root, int value) const;
        Node* getSuccessorHelper(Node* root, int value) const;

    public:
        
        
        // constructor
        BinarySearchTree();

        // function to insert
        void insert(int value);

        // functiont to search for element in tree. return true if found
        bool contains(int value) const;

        // function to find min element in BST. iterative implementation
        Node* min() const;

        // function to find max element in BST. iterative implementation
        Node* max() const;

        // function to find height of BST. counting edges from root
        int findHeight() const;

        // get balance factor of node
        int getBalanceFactor(Node* root) const;

        // function to level order traversal
        void levelOrderTraversal() const;

        // function to depth first pre-order traversal
        void preOrderTraversal() const;

        // function to depth first in-order traversal
        void inOrderTraversal() const;

        // function to depth first post-order traversal
        void postOrderTraversal() const;

        // function to check if binary tree is binary search tree
        bool isBinarySearchTree() const;

        // function to delete node
        void deleteNode(int value);

        // function to find element by value
        Node* find(int value) const;

        // function to get successor of value 
        Node* getSuccessor(int value) const;
        
};

#endif
