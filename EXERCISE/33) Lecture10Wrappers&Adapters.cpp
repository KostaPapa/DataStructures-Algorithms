//remove the most recent elemnt inserted on the stack

#include<iostream>
#include<stack>
#include<vector>
using namespace std;

template<class Object>
void Stack<Object>::pop(){
    
    if(empty()){
        throw UnderFlowException();
    }
    return topOfStack--;
}

int main(){
    
    Stack<int> s;
    
    for(int i=0; i<10; i++){
        s.push(i);
    }
    
    while(!s.empty()){
        cout << s.top() << endl;
        s.pop();
    }
    
    system("pause")
    return 0;
}
