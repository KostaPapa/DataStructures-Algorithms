#include<iostream>
using namespace std;

template<class Object>
class BinaryNode{
public:
    BinaryNode(const Object& element = Object(), BinaryNode* lhs = NULL, BinaryNode* rhs = NULL);
public:
    Object element;
    BinaryNode* lhs;
    BinaryNode* rhs;
};
