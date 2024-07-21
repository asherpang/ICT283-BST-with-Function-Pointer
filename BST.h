#ifndef BST_H
#define BST_H

#include <iostream>
#include "Date.h"

template <class T>
class Bst {
private:
    template <class U>
    struct Node {
        U data;
        Node* left;
        Node* right;

        Node(U value) : data(value), left(nullptr), right(nullptr) {}
    };

    Node<T>* root;

    Node<T>* Insert(Node<T>* node, T value);
    void DeleteTree(Node<T>* node);
    Node<T>* Search(Node<T>* node, T value);
    void InOrder(Node<T>* node, void (*func)(T));
    void PreOrder(Node<T>* node, void (*func)(T));
    void PostOrder(Node<T>* node, void (*func)(T));

public:
    Bst();
    ~Bst();

    void Insert(T value);
    void DeleteTree();
    bool Search(T value);
    void InOrder(void (*func)(T));
    void PreOrder(void (*func)(T));
    void PostOrder(void (*func)(T));
};

template <class T>
Bst<T>::Bst() : root(nullptr) {}

template <class T>
Bst<T>::~Bst() {
    DeleteTree();
}

template <class T>
typename Bst<T>::template Node<T>* Bst<T>::Insert(Node<T>* node, T value) {
    if (node == nullptr) {
        return new Node<T>(value);
    }
    if (value < node->data) {
        node->left = Insert(node->left, value);
    } else if (value > node->data) {
        node->right = Insert(node->right, value);
    }
    // If value == node->data, do not insert the duplicate
    return node;
}

template <class T>
void Bst<T>::Insert(T value) {
    root = Insert(root, value);
}

template <class T>
void Bst<T>::DeleteTree(Node<T>* node) {
    if (node == nullptr) return;
    DeleteTree(node->left);
    DeleteTree(node->right);
    delete node;
}

template <class T>
void Bst<T>::DeleteTree() {
    DeleteTree(root);
    root = nullptr;
}

template <class T>
typename Bst<T>::template Node<T>* Bst<T>::Search(Node<T>* node, T value) {
    if (node == nullptr || node->data == value) {
        return node;
    }
    if (value < node->data) {
        return Search(node->left, value);
    } else {
        return Search(node->right, value);
    }
}

template <class T>
bool Bst<T>::Search(T value) {
    return Search(root, value) != nullptr;
}

template <class T>
void Bst<T>::InOrder(Node<T>* node, void (*func)(T)) {
    if (node == nullptr) return;
    InOrder(node->left, func);
    func(node->data);
    InOrder(node->right, func);
}

template <class T>
void Bst<T>::InOrder(void (*func)(T)) {
    InOrder(root, func);
}

template <class T>
void Bst<T>::PreOrder(Node<T>* node, void (*func)(T)) {
    if (node == nullptr) return;
    func(node->data);
    PreOrder(node->left, func);
    PreOrder(node->right, func);
}

template <class T>
void Bst<T>::PreOrder(void (*func)(T)) {
    PreOrder(root, func);
}

template <class T>
void Bst<T>::PostOrder(Node<T>* node, void (*func)(T)) {
    if (node == nullptr) return;
    PostOrder(node->left, func);
    PostOrder(node->right, func);
    func(node->data);
}

template <class T>
void Bst<T>::PostOrder(void (*func)(T)) {
    PostOrder(root, func);
}

#endif // BST_H
