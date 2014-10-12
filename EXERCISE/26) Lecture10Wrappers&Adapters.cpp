#include<iostream>
#include<vector>
#include<stack>
using namespace std;

int main(){
    
    stack<int> mystack;
    mystack.push(1);
    cout << "stack: " << mystack.top() << endl;
    cout << mystack.size() << endl;
    mystack.pop();
    cout << "stack: " << mystack.empty() << endl;
    
    cout << endl;
    
    stack<string> names;
    names.push("first");
    names.push("second");
    names.push("third");
    cout << names.size() << endl;
    cout << names.top() << endl;
    names.pop();
    cout << names.top() << endl;
    cout << names.size() << endl;
    
        
    
    system("pause");
}
