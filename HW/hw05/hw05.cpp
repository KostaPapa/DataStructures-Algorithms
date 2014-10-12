#include <iostream>
#include <functional> 
#include <string>
#include <exception>
#include <stack>
#include <vector>
#include <queue>

using namespace std;

class DSException
{
public:
    DSException( const string & msg = "" ) : message( msg )
	{ }
    virtual ~DSException( )
	{ }
    virtual string toString( ) const
#ifndef NO_RTTI
	{ return "Exception " + string( typeid( *this ).name( ) ) + ": " + what( ); }
#else
	{ return "Exception " + string( ": " ) + what( ); }
#endif
    virtual string what( ) const
	{ return message; }
	
private:
    string message;
};

class GraphException : public DSException 
{
public:
    GraphException( const string & msg = "" ) : DSException( msg )
	{ }
};

class NullPointerException : public DSException
{
public:
    NullPointerException( const string & msg = "" ) : DSException( msg )
	{ }
};

class IndexOutOfBoundsException : public DSException
{
public:
    IndexOutOfBoundsException( const string & msg = "" ) : DSException( msg )
	{ }
    IndexOutOfBoundsException( int idx, int sz, const string & msg = "" )
	: DSException( msg ), index( idx ), size( sz ) { }
	
    int getIndex( ) const
	{ return index; }
    int getSize( ) const
	{ return size; }
	
private:
    int index;
    int size;      
};

class ArrayIndexOutOfBoundsException : public IndexOutOfBoundsException 
{
public:
    ArrayIndexOutOfBoundsException( const string & msg = "" )
	: IndexOutOfBoundsException ( msg ) { }
    ArrayIndexOutOfBoundsException( int idx, int sz, const string & msg = "" )
	: IndexOutOfBoundsException( idx, sz, msg ) { }
};

class StringIndexOutOfBoundsException : public IndexOutOfBoundsException 
{
public:
    StringIndexOutOfBoundsException( const string & msg = "" ) 
	: IndexOutOfBoundsException ( msg ) { }
    StringIndexOutOfBoundsException( int idx, int sz, const string & msg = "" )
	: IndexOutOfBoundsException( idx, sz, msg ) { }
};

class UnderflowException : public DSException
{
public:
    UnderflowException( const string & msg = "" ) : DSException( msg )
	{ }
};

class OverflowException : public DSException
{
public:
    OverflowException( const string & msg = "" ) : DSException( msg )
	{ }
};

class ItemNotFoundException : public DSException
{
public:
    ItemNotFoundException( const string & msg = "" ) : DSException( msg )
	{ }
};

class DuplicateItemException : public DSException
{
public:
    DuplicateItemException( const string & msg = "" ) : DSException( msg )
	{ }
};

class IteratorException : public DSException
{
public:
    IteratorException( const string & msg = "" ) : DSException( msg )
	{ }
};

class IteratorOutOfBoundsException : public IteratorException
{
public:
    IteratorOutOfBoundsException( const string & msg = "" ) : IteratorException( msg )
	{ }
};

class IteratorUninitializedException : public IteratorException
{
public:
    IteratorUninitializedException( const string & msg = "" ) : IteratorException( msg )
	{ }
};

class IteratorMismatchException : public IteratorException
{
public:
    IteratorMismatchException( const string & msg = "" ) : IteratorException( msg )
	{ }
};

class BadArgumentException : public DSException
{
public:
    BadArgumentException( const string & msg = "" ) : DSException( msg )
	{ }
};
template <class Comparable>
class BinarySearchTree;

template <class Comparable>
class BinarySearchTreeWithRank;

template <class Comparable>
class BinaryNode
{
    Comparable  element;
    BinaryNode *left;
    BinaryNode *right;
    int size;
	
    BinaryNode( const Comparable & theElement, BinaryNode *lt,
			   BinaryNode *rt, int sz = 1 )
	: element( theElement ), left( lt ), right( rt ), size( sz ) { }
	
    void printPreOrder( ) const;
    void printPostOrder( ) const;
    void printInOrder( ) const;	
	
    friend class BinarySearchTree<Comparable>;
    friend class BinarySearchTreeWithRank<Comparable>;
};

// Print the tree rooted at current node using preorder traversal.
template <class Comparable>
void BinaryNode<Comparable>::printPreOrder( ) const
{
    cout << element << endl;                  // Node
    if( left != NULL )
        left->printPreOrder( );               // Left
    if( right != NULL )
        right->printPreOrder( );              // Right
}

// Print the tree rooted at current node using postorder traversal.
template <class Comparable>
void BinaryNode<Comparable>::printPostOrder( ) const
{
    if( left != NULL )                        // Left
        left->printPostOrder( );
    if( right != NULL )                       // Right
        right->printPostOrder( );
    cout << element << endl;                  // Node
}

// Print the tree rooted at current node using inorder traversal.
template <class Comparable>
void BinaryNode<Comparable>::printInOrder( ) const
{
    if( left != NULL )                        // Left
        left->printInOrder( );
    cout << element << endl;                  // Node
    if( right != NULL )
        right->printInOrder( );               // Right
}
// BinarySearchTree class
//
// CONSTRUCTION: with no parameters or another BinarySearchTree.
//
// ******************PUBLIC OPERATIONS*********************
// void insert( x )       --> Insert x
// void remove( x )       --> Remove x
// void removeMin( )      --> Remove smallest item
// Comparable find( x )   --> Return item that matches x
// Comparable findMin( )  --> Return smallest item
// Comparable findMax( )  --> Return largest item
// bool isEmpty( )        --> Return true if empty; else false
// void makeEmpty( )      --> Remove all items
// ******************ERRORS********************************
// Exceptions are thrown by insert, remove, and removeMin if warranted

template <class Comparable>
class BinarySearchTree
{
public:
	typedef BinaryNode<Comparable> Node;
	
	BinarySearchTree( ) : root( NULL ) { } // Construct the tree.
        BinarySearchTree( const BinarySearchTree & rhs ) : root( NULL ) { *this = rhs; }// Copy constructor.
	~BinarySearchTree( ){ makeEmpty( ); } // Destructor for the tree.
	
	//const Comparable & findKth( int k ) const{ return findKth( k, BinarySearchTree<Comparable>::root )->element;}
	
	const Comparable * findKth( int k ) const
	{ return elementAt( findKth( k, BinarySearchTree<Comparable>::root ) );}
	// Return the smallest item 
        const Comparable  * findMin( ) const
	{ return elementAt( findMin( root ) ); }
        // Return the largest item in the tree	
        const Comparable  * findMax( ) const 
	{ return elementAt( findMax( root ) ); }
	// Find item x in the tree.
	// Return the matching item
        const Comparable * find( const Comparable & x ) const 
	{ return elementAt( find( x, root ) ); }
        // Test if the tree is logically empty.
	// Return true if empty, false otherwise.	
        bool isEmpty( ) const { return root == NULL;}
	
	// Make the tree logically empty.
        void makeEmpty( )
	{ makeEmpty( root ); }
	// Insert x into the tree;
	// Throws DuplicateItemException if x is already there.
        void insert( const Comparable & x )
	{ insert( x, root ); }
	// Remove x from the tree.
	// Throws ItemNotFoundException if x is not in the tree.
        void remove( const Comparable & x )
	{ remove( x, root ); }
	// Remove minimum item from the tree.
	// Throws UnderflowException if tree is empty.
        void removeMin( )
	{ removeMin( root ); }
	
	// Recursive traversals, with printing
        void printPreOrder( ) const
	{ if( root != NULL ) root->printPreOrder( ); }    
        void printInOrder( ) const
	{ if( root != NULL ) root->printInOrder( ); }    
        void printPostOrder( ) const
	{ if( root != NULL ) root->printPostOrder( ); }   
    
        void printLevelOrder()
    { if(root!=NULL) root->printPreOrder(); }
	
        const BinarySearchTree & operator=( const BinarySearchTree & rhs );
	
private:
        Node * root;
	int treeSize( Node *t ) const { return t == NULL ? 0 : t->size; }
	
        Comparable const * elementAt( Node *t ) const;
	void insert( const Comparable & x, Node * & t ) const;
	void remove( const Comparable & x, Node * & t ) const;
	void removeMin( Node * & t ) const;
        Node * findMin( Node *t ) const;
        Node * findMax( Node *t ) const;
        Node * find( const Comparable & x, Node *t ) const;
        void makeEmpty( Node * & t ) const;
        Node * clone( Node *t ) const;
	Node *findKth( int k, Node *t ) const;
};

// Deep copy.
template <class Comparable>
const BinarySearchTree<Comparable> & BinarySearchTree<Comparable>::operator=( const BinarySearchTree<Comparable> & rhs )
{
    if( this != &rhs )
    {
        makeEmpty( );
        root = clone( rhs.root );
    }
    return *this;
}

// Internal method to return NULL if the item doesn't exist, otherwise a pointer to the
//element field in node t.
template <class Comparable>
Comparable const * BinarySearchTree<Comparable>::elementAt( Node *t ) const
{
    if( t == NULL )
        return NULL;
    else
        return &(t->element);
}

// Internal method to insert into a subtree.
// x is the item to insert.
// t is the node that roots the tree.
// Set the new root.
// Throw DuplicateItemException if x is already in t.
template <class Comparable>
void BinarySearchTree<Comparable>::insert( const Comparable & x, Node * & t ) const
{
    if( t == NULL )
        t = new Node( x, NULL, NULL, 0 );
    else if( x < t->element )
        insert( x, t->left );
    else if( t->element < x )
        insert( x, t->right );
    else
        throw DuplicateItemException( );
	
    t->size++;
}


// Internal method to remove from a subtree.
// x is the item to remove.
// t is the node that roots the tree.
// Set the new root.
// Throw ItemNotFoundException is x is not in t.
template <class Comparable>
void BinarySearchTree<Comparable>::remove( const Comparable & x, Node * & t ) const
{
    if( t == NULL )
        throw ItemNotFoundException( );
    if( x < t->element )
        remove( x, t->left );
    else if( t->element < x )
        remove( x, t->right );
    else if( t->left != NULL && t->right != NULL ) // Two children
    {
        t->element = findMin( t->right )->element;
        removeMin( t->right );                   // Remove minimum
    }
    else
    {
        BinaryNode<Comparable> *oldNode = t;
        t = ( t->left != NULL ) ? t->left : t->right;  // Reroot t
        delete oldNode;                         // delete old root
        return;
    }
	
    t->size--;
}

// Internal method to remove minimum item from a subtree.
// t is the node that roots the tree.
// Set the new root.
// Throw UnderflowException if t is empty.
template <class Comparable>
void BinarySearchTree<Comparable>::removeMin( Node * & t ) const
{
    if( t == NULL )
        throw UnderflowException( );
    else if( t->left != NULL )
        removeMin( t->left );
    else
    {
        Node *tmp = t;
        t = t->right;
        delete tmp;
        return;
    }
	
    t->size--;
}

// Internal method to find the smallest item in a subtree t.
// Return node containing the smallest item.
//template <class Comparable>
//BinaryNode<Comparable> * BinarySearchTree<Comparable>::findMin( Node *t ) const
//{
//    if( t != NULL )
//        while( t->left != NULL )
//            t = t->left;
	
    //return t;
//}

// Internal method to find the largest item in a subtree t.
// Return node containing the largest item.
template <class Comparable>
BinaryNode<Comparable> * BinarySearchTree<Comparable>::findMax( Node *t ) const
{
    if( t != NULL )
        while( t->right != NULL )
            t = t->right;
	
    return t;
}

// Internal method to find an item in a subtree.
// x is item to search for.
// t is the node that roots the tree.
// Return node containing the matched item.
template <class Comparable>
BinaryNode<Comparable> * BinarySearchTree<Comparable>::
find( const Comparable & x, Node *t ) const
{
    while( t != NULL )
        if( x < t->element )
            t = t->left;
        else if( t->element < x )
            t = t->right;
        else
            return t;    // Match
	
    return NULL;         // Not found
}

// Internal method to make subtree empty.
template <class Comparable>
void BinarySearchTree<Comparable>::makeEmpty( Node * & t ) const
{
    if( t != NULL )
    {
        makeEmpty( t->left );
        makeEmpty( t->right );
        delete t;
    }
    t = NULL;
}

// Internal method to clone subtree.
template <class Comparable>
BinaryNode<Comparable> * BinarySearchTree<Comparable>::clone( Node * t ) const
{
    if( t == NULL )
        return NULL;
    else
        return new Node( t->element, clone( t->left ), clone( t->right ), t->size );
}

//Programming Part: A
template<class Comparable>
void BinarySearchTree<Comparable>::printLevelOrder(Node* t) const{
    queue<int> levelOrderTree; 
    while (t){
        cout << t << endl;
        if (t->left) levelOrderTree.push(t->left);
        if (t->right) levelOrderTree.push(t->right);
        t = levelOrderTree.pop();
    }
}

//Part B:1
template <class Comparable>
BinaryNode<Comparable> * BinarySearchTree<Comparable>::findMin( Node *t ) const
{
    if( t == NULL )
        throw UnderflowException( );
    if(t->left == NULL)
        return t;
    return (findMin(t->left));
}

//Part B:2
template <class Comparable>
BinaryNode<Comparable> * BinarySearchTree<Comparable>::findKthMin( const Comparable & x, Node *t ) const{
    while( t != NULL )
        if( x < t->element )
            t = t->left;
        else
            return t;
	
    return NULL;
}



