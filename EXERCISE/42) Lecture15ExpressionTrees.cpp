#include<iostream>
using namespace std;

template<class Object>
class BinaryNode;

template<class Object>
class BinaryTree;

template<class Object>
class BinaryNode{
public:
    BinaryNode(const Object& element = Object(), BinaryNode* lhs = NULL, BinaryNode& rhs = NULL):
        element(element), lhs(lhs), rhs(rhs){}
        
        //Size and Height
        static int size(BinaryNode* t);
        static int height(BinaryNode* t);
        
        //Traversals
        void printPreOrder() const;
        void printPostOrder() const;
        void printInOrder() const;
        
        //Dublicate (to copy lhs subtree, rhs subtree)
        BinaryNode* dublicate() const;
public:
    Object element;
    BinaryNode* lhs;
    BinaryNode* rhs;
};

template<class Object>
class BinaryTree{
public:
    //make root null
    BinaryTree():root(NULL){}
    //create rootItem on the heap
    BinaryTree(const Object& rootItem):root(new Node(rootItem)){}
    //create operator =
    BinaryTree(const BinaryTree& rhs):root(NULL){*this = rhs;}
    
    //Destructor
    ~BinaryTree(){makeEmpty();}
    
    //operator
    const BinaryTree& operator= (const BinaryTree& rhs);
    
    //Traverslas and Empty check
    void printPreOrder() const{if(root!=NULL) root->printPreOrder();}
    void printPostOrder() const{if(root!=NULL) root->printPostOrder();}
    void printInOrder() const{if(root!=NULL) root->printInOrder();}

    void makeEmpty(){makeEmpty(root);}
    bool isEmpty(){return root == NULL;}
    
    //t1, t2 combination
    void merge(const Object& rootItem, const BinaryTree& t1, const BinaryTree& t2);
    
    int size() const{return Node::size(root);}
    int height() const{return Node::height(root);}
    
private:
    typedef BinaryNode<Object> Node;
    Node* root;
    void makeEmpty(BinaryNode<Object> * & t);
};
    
//traversals method
template<class Object>
void BinaryNode<Object>::printPreOrder() const{
    cout << element << endl;
    if(lhs!=NULL)
        lhs->printPreOder();
    if(rhs!=NULL)
        rhs->printPreOrder();
}

template<class Object>
void BinaryNode<Object>::printPostOrder() const{
    if(lhs!=NULL)
        lhs->printPostOrder();
    if(rhs!=NULL)
        rhs->printPostOrder();
        
    cout << element << endl;
}

template<class Object>
void BinaryNode<Object>::printInOrder() const{
    if(lhs!=NULL)
        lhs->printInOrder();
    cout << element << endl;
    if(rhs!=NULL)
        rhs->printInOrder();
}

//Traversal Copy of the Tree
template<class Object>
BinaryNode<Object>* BinaryNode<Object>::dublicate() const{
    
    BinaryNode<Object> *root = new BinaryNode<Object>(element);
    
    if(lhs!=NULL)
        root->lhs = lhs->dublicate();
    if(rhs!=NULL)
        root->rhs = rhs->dublicate();
    return root;
}
    
    
    















































