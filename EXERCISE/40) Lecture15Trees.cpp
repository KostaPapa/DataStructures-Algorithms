#include<iostream>
using namespace std;

template<class Object>
class BinaryNode;

template<class Object>
class BinaryTree;

template<class Object>
class BinaryNode{
public:
    BinaryNode(const Object& element = Object(), BinaryNode* lhs = NULL, BinaryNode* rhs = NULL):
        element(element), lhs(lhs), rhs(rhs){}
    
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

template<class Object>
class BinaryTree{
public:
    BinaryTree():root(NULL) {}
    BinaryTree(const Object& rootItem):root(new Node(rootItem)) {}
    BinaryTree(const BinaryTree& rhs):root(NULL){*this = rhs;}
    
    ~BinaryTree(){makeEmpty();}
    
    const BinaryTree& operator = (const BinaryTree& rhs);
    
    //Recursive Traversal
    void printPreOrder() const{if(root!=NULL) return root->printPreOrder();}
    void printPostOrder() const{if(root!=NULL) return root->printPostOrder();}
    void printInOrder() const{if(root!=NULL) return root->printInOeder();}
    
    void makeEmpty(){makeEmtpy(root);}
    bool isEmpty() { return root == NULL;}
    
    //Combine t1 and t2
    void merge (const Object& rootItem, BinaryTree& t1, BinaryTree& t2);
    
    int size() const {return Node::size(root);}
    int height() const {return Node::height(root);}
private:
    typedef BinaryNode<Object>Node;
    Node* root;
    void makeEmpty(BinaryNode<Object> *& t);    
};


template<class Object>
void BinaryNode<Object>::printPreOrder() const{
    
    cout << element << endl;
    if(lhs != NULL)
        return lhs->printPreOrder();
    if(rhs != NULL)
        return rhs->printPreOrder();
}










                    













