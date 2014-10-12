//return the most recently item in the stack
#include<iostream>
#include<vector>
#include<stack>
using namespace std;

template<class Object>
const Object& Stack<Object>::top() const{
    
    if(empty()){
        throw UnderFlowException();
    }
    return theArray[topOfStack];
}

int main(){
    
    Stack<int> s;
    
    for(int i=0; i<10; i++){
        s.push(i);
    }
    
    s.top();
    
    system("pause");
    return 0;
}
