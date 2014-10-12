#include<iostream>
#include<vector>
#include<stack>
using namespace std;

template<class Object>
class Stack{
public:
    Stack();
    
    const Object& top() const;
    bool empty() const;
    int size();
    void pop();
    void push(Object& x);

private:
    vector<Object> theArray;
    int topOfStack;
};

int main(){
    
    Stack<int> s;
    system("pause");
    return 0;
}

