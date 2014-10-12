#include<iostream>
#include<stack>
#include<vector>
using namespace std;

template<class Object>
class Stack{
    
    public:
        Stack();
        
        void pop();
        void push(const Object& x);
        bool empty() const;
        int size();
        const Object& top() const;
    
    private:
        vector<Object> theArray;
        int topOfStack;
    };

//create the stack
template<class Object>
Stack<Object>::Stack():theArray(1){
    topOfStack = -1;
}

//insert x into the stack
template<class Object>
void Stack<Object>::push(const Object& x){
    
    if(topOfStack == theArray.size()-1){
        theArray.resize(theArray.size()*2-1);
    }
    theArray[++topOfStack] = x;
}

//return the most recently inserted item in the stack
template<class Object>
const Object& Stack<Object>::top() const{
    if(empty()){
        cout << "Stack is Empty" << endl;
    }
    return theArray[topOfStack];
}

//test id stack is logically empty
template<class Object>
bool Stack<Object>::empty() const{
    return topOfStack == -1;
}

//remove the most recently inserted item from the stack
template<class Object>
void Stack<Object>::pop(){
    if(empty()){
        cout << "Stack is empty!" << endl;
    }
    topOfStack --;
}

int main(){
    
    Stack<char> s;
    char x = 'a';
    
    s.push('w');
    //cout << s.top() << endl;
    //cout << x << endl;
    
    cout << s.size() << endl;
    
    
    system("pause");
    return 0;
}
