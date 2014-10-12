#include<iostream>
#include<vector>
#include<stack>
using namespace std;


//create stack
template<class Object>
Stack<Object>::Stack():theArray(1){
    topOfStack = -1;
}

int main(){
    
    Stack<int> s;
    system("pause");
    return 0;
}
