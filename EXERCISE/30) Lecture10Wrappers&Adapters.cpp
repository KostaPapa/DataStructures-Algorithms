#include<iostream>
#include<vector>
#include<stack>
using namespace std;

template<class Object>
void Stack<Object>::push(const Object& x){
    
    if(topOfStack == theArray.size()-1){
        theArray.resize(theArray.size()*2-1);
    }
    theArray[++topOfStack] = x;
}

int main(){
    
    Stack<int> s;
    
    for(int i=0; i<10; ++i){
        s.push(i);
    }
    system("pause");    
    return 0;
}
