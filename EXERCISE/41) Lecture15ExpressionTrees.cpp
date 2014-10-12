#include<iostream>
using namespace std;

template<class Object>
class BinaryNode;

template<class Object>
class BinaryTree;

template <class Object>
class BinaryNode{
public:
    BinaryNode(const Object& element = Object(), BinaryNode* lhs = NULL, BinaryNode* rhs = NULL):
        element(element), lhs(lhs), rhs(rhs){}
        
        //Size and Height
        static int size(BinaryNode* t);
        static int height(BinaryNode* t);
        
        //PreOrder, PostOrder, InOrder
        void printPreOrder() const;
        void printPostOrder() const;
        void printInOrder() const;
        
        //Dublicate method used for deep copy
        BinaryNode* dublicate() const;
public:
    Object element;
    BinaryNode* lhs;
    BinaryNode* rhs;
};

template<class Object>
class BinaryTree{
public:
    BinaryTree():root(NULL){}
    BinaryTree(const Object& rootItem):root(new Node(rootItem)){}
    BinaryTree(const BinaryTree& rhs):root(NULL){*this = rhs;}
    
    ~BinaryTree(){makeEmpty();}
    
    const BinaryTree& operator = (const BinaryTree& rhs);
    
    //Recursive traversal with pritnting
    void printPreOrder() const{if(root != NULL) root->printPreOrder;}
    void printPostOrder() const{if(root!= NULL) root->printPostorder;}
    void printInOrder() const{if (root != NULL) root->printInOrder;}
    
    void makeEmpty(){ makeEmpty(root);}
    bool isEmppty() const {return root == NULL;}
    
    //t1, t2 combination
    void merge(const Object& rootItem, BinaryTree& t1, BinaryTree& t2);
    int size() const{return Node::size(root);}
    int height() const{return Node::height(root);}
private:
    typedef BinaryNode<Object> Node;
    Node* root;
    void makeEmpty(BinaryTree<Object> * & t);
};

//Print Traverssals

//Print PreOrder
template<class Object>    
void BinaryNode<Object>::printPreOrder() const{
    cout << element << endl;
    if(lhs!=NULL)
        lhs->printPreOrder();
    if(rhs!=NULL)
        rhs->printPreOrder();
}

//Print PostOrder
template<class Object>
void BinaryNode<Object>::printPostOrder() const{
    if(lhs!=NULL)
        lhs->printPostOrder;
    if(rhs!=NULL)
        rhs->printPostOrder;
    cout << element << endl;
}

//Print InOrder
template<class Object>
void BinaryNode<Object>::printInOrder() const{
    if(lhs != NULL)
        lhs->printInOrder();
    cout << element << endl;
    if(rhs != NULL)
        rhs->printInOrder();
}
    


























