#include "BinarySearchTree.h"

// constructors
Node::Node(int value) : data(value), left(nullptr), right(nullptr) {}
BinarySearchTree::BinarySearchTree() : root(nullptr) {}

// insert helper function
Node* BinarySearchTree::insertHelper(Node* root, int value) {
    
    // if tree is empty
    if (root == nullptr) {
        return new Node(value);
    }
    // if tree is NOT empty, use recursion
    else if (value <= root->data) {
        root->left = insertHelper(root->left, value);
    }
    else {
        root->right = insertHelper(root->right, value);
    }
    return root;
}

// function to insert element into tree
void BinarySearchTree::insert(int value) {
    root = insertHelper(root, value);
}

// contains helper function
bool BinarySearchTree::containsHelper(Node* root, int value) const {
    // if tree is empty, return false
    if (root == nullptr) {
        return false;
    }
    // if root is value, return true
    if (root->data == value) {
        return true;
    }
    // recursion to search for left and right
    else if (value < root->data) {
        return containsHelper(root->left, value);
    }
    else {
        return containsHelper(root->right, value);
    }
}

// function to search for element in tree. return true if found
bool BinarySearchTree::contains(int value) const {
    return containsHelper(root, value);
}

// find helper 
Node* BinarySearchTree::findHelper(Node* root, int value) const {
    // edge cases
    if (root == nullptr || root->data == value) {
        return root;
    }
    // recursion to search for left and right
    else if (value < root->data) {
        return findHelper(root->left, value);
    }
    else {
        return findHelper(root->right, value);
    }
}

// function to find element by value
Node* BinarySearchTree::find(int value) const {
    return findHelper(root, value);
}

// min helper
Node* BinarySearchTree::minHelper(Node* root) const {
    if (root == nullptr) {
        std::cout << "[ERROR] Tree is empty.\n";
        return nullptr;
    }

    // root is not local, so cannot just use root node
    Node* current = root;
    while (current->left != nullptr) {
        current = current->left;
    }
    return current;
}

// function to find min element in BST. iterative implementation
Node* BinarySearchTree::min() const {
    return minHelper(root);
}

// max helper
Node* BinarySearchTree::maxHelper(Node* root) const {
    if (root == nullptr) {
        std::cout << "[ERROR] Tree is empty.\n";
        return nullptr;
    }

    // root is not local, so cannot just use root node
    Node* current = root;
    while (current->right != nullptr) {
        current = current->right;
    }
    return current;
}

// function to find max element in BST. iterative implementation
Node* BinarySearchTree::max() const {
    return maxHelper(root);
}

// find height helper function. counting edges from root
int BinarySearchTree::findHeightHelper(Node* root) const {
    if (root == nullptr) {
        return -1;
    }
    int leftHeight = findHeightHelper(root->left);
    int rightHeight = findHeightHelper(root->right);

    return std::max(leftHeight, rightHeight) + 1;
}

// function to find height of BST. count edges from root
int BinarySearchTree::findHeight() const {
    return findHeightHelper(root);
}

// get balance factor of node
int BinarySearchTree::getBalanceFactor(Node* root) const {
    if (root == nullptr) {
        return -1;
    }
    else {
        return (findHeightHelper(root->left) - findHeightHelper(root->right));
    }
}

// function to level order traverse the tree
void BinarySearchTree::levelOrderTraversal() const {
    if (root == nullptr) {
        return;
    }
    std::queue<Node*> discoveredNodeQueue;
    discoveredNodeQueue.push(root);

    // while queue is not empty 
    while(!discoveredNodeQueue.empty()) {
        Node* current = discoveredNodeQueue.front();
        std::cout << current->data << ' ';
        if (current->left != nullptr) {
            discoveredNodeQueue.push(current->left);
        }
        if (current->right != nullptr) {
            discoveredNodeQueue.push(current->right);
        }
        discoveredNodeQueue.pop();
    }

    std::cout << '\n';
}

// pre-order traversal helper
void BinarySearchTree::preOrderTraversalHelper(Node* root) const { 
    if (root == nullptr) {
        return;
    }
    std::cout << root->data << ' ';
    preOrderTraversalHelper(root->left);
    preOrderTraversalHelper(root->right);
}

// function to depth first pre-order traversal
void BinarySearchTree::preOrderTraversal() const {
    preOrderTraversalHelper(root);
}

// in-order traversal helper
void BinarySearchTree::inOrderTraversalHelper(Node* root) const {
    if (root == nullptr) {
        return;
    }
    inOrderTraversalHelper(root->left);
    std::cout << root->data << ' ';
    inOrderTraversalHelper(root->right);
}

// function to depth first in-order traversal
void BinarySearchTree::inOrderTraversal() const {
    inOrderTraversalHelper(root);
}

// post-order traversal helper
void BinarySearchTree::postOrderTraversalHelper(Node* root) const {
    if (root == nullptr) {
        return;
    }
    postOrderTraversalHelper(root->left);
    postOrderTraversalHelper(root->right);
    std::cout << root->data << ' ';
}

// function to depth first post-order traversal
void BinarySearchTree::postOrderTraversal() const {
    postOrderTraversalHelper(root);
}

// is binary search tree helper
bool BinarySearchTree::isBinarySearchTreeHelper(Node* root, int minValue, int maxValue) const {
    if (root == nullptr) {
        return true;
    }
    if (root->data > minValue && root->data < maxValue
        && isBinarySearchTreeHelper(root->left, minValue, root->data)
        && isBinarySearchTreeHelper(root->right, root->data, maxValue)) {
            return true;
    }
    else {
        return false;
    }
}

// function to check if binary tree is binary search tree (more for general binary trees)
bool BinarySearchTree::isBinarySearchTree() const  {
    return isBinarySearchTreeHelper(root, INT_MIN, INT_MAX);
}

// delete Node helper 
Node* BinarySearchTree::deleteNodeHelper(Node* root, int value) {
    if (root == nullptr) {
        return nullptr;
    }
    // node to be deleted in left sub tree
    else if (value < root->data) {
        root->left = deleteNodeHelper(root->left, value);
    }
    // node to be deleted in right sub tree
    else if (value > root->data) {
        root->right = deleteNodeHelper(root->right, value);
    }
    // found the node to be deleted
    else {
        // case 1: no children
        if (root->left == nullptr && root->right == nullptr) {
            delete root;
            root = nullptr; // to handle dangling pointer
        }
        // case 2: 1 child
        else if (root->left == nullptr) {
            Node* temp = root;
            root = root->right;
            delete temp;
        }
        else if (root->right == nullptr) {
            Node* temp = root;
            root = root->left;
            delete temp;
        }
        // case 3: 2 child
        else {
            Node* temp = minHelper(root->right);
            root->data = temp->data;
            root->right = deleteNodeHelper(root->right, temp->data);
        }
    }

    return root;
}

// function to delete node
void BinarySearchTree::deleteNode(int value) {
    root = deleteNodeHelper(root, value);
}

// function to find inorder successor of value in a BST 
Node* BinarySearchTree::getSuccessorHelper(Node* root, int value) const {
    Node* current = findHelper(root, value);
    // if value not found, return nullptr
    if (current == nullptr) {
        return nullptr;
    }
    // case 1: node has right subtree
    if (current->right != nullptr) {
        return minHelper(current->right);
    }
    // case 2: node has no right subtree
    else {
        Node* successor = nullptr;
        Node* ancestor = root;
        while(ancestor != current) {
            if (current->data < ancestor->data) {
                successor = ancestor;
                ancestor = ancestor->left;
            }
            else {
                ancestor = ancestor->right;
            }
        }
        return successor;
    }


}

// function to get successor of value
Node* BinarySearchTree::getSuccessor(int value) const {
    return getSuccessorHelper(root, value);
}
