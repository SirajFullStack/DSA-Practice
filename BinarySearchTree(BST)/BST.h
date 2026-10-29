#ifndef BST_H
#define BST_H

#include <iostream>
#include "Node.h"
using namespace std;

class BST {
    Node* root;
    int *arr1, *arr2, *arr;
    int top1, top2, top;

    // ---------- private helpers (each defined in its own .cpp) ----------
    Node* insert(Node* node, int v);                 // insert.cpp
    bool  search(Node* node, int target);            // search.cpp
    Node* deletion(Node* node, int v);               // deletion.cpp
    void  clearTree(Node*& node);                    // clearTree.cpp
    void  PreOrder(Node* node);                      // preorder.cpp
    void  InOrder(Node* node);                       // inorder.cpp
    void  PostOrder(Node* node);                     // postorder.cpp
    int   Height(Node* node);                        // height.cpp
    int   max(Node* node);                           // maxValue.cpp
    int   min(Node* node);                           // minValue.cpp
    int   countNodes(Node* node);                    // countNodes.cpp
    void  count_leaf(Node* node, int& count);        // countLeaf.cpp
    int   find_successor(int val);                   // successor.cpp
    int   find_Predecessor(int val);                 // predecessor.cpp

    // min distance
    void push_arr1(int v);
    void push_arr2(int v);
    void pop_arr1();
    void pop_arr2();
    void inorderToArr1(Node* node);
    void Distance();
    int  Min_dis(Node* node);                        // minDistance.cpp

    // max distance
    int  Max_dis(Node* node);                        // maxDistance.cpp

    // kth helpers
    void push(int v);                                // kthHelpers.cpp
    void pop();
    void inorderToArr(Node* node);
    int  kth_smallest_sum(int k);                    // kthSmallestSum.cpp
    int  kth_Largest_sum(int k);                     // kthLargestSum.cpp

public:
    BST();                                           // BST.cpp
    ~BST();

    void insert(int v);
    bool search(int v);
    void deletion(int v);
    void clearTree();
    void PreOrder();
    void InOrder();
    void PostOrder();
    int  Height();
    int  max();
    int  min();
    int  countNodes();
    int  count_leaf();
    void find_successor();
    void find_Predecessor();
    int  Min_dis();
    int  Max_dis();
    int  kth_smallest_sum();
    int  kth_Largest_sum();
};

#endif
