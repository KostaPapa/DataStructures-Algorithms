#include<iostream>
using namespace std;

template<class Object>
class BinaryNode{
public:
    BinaryNode(const Object& element = Object(), BinaryNode* lhs=NULL, BinaryNode* rhs=NULL)
    : element(element), rhs(rhs), lhs(lhs) {}
    
    static int size(BinaryNode* t);
    static int height(BinaryNode* t);
    
    void printPreOrder() const;
    void printPostOrder() const;
    void printInOrder() const;
    
    BinaryNode* dublicate() const;
public:
    Object element;
    BinaryNode* lhs;
    BinaryNode* rhs;
};
