//check if the stack is logically empty

#inculde<iostrream>
#include<vector>
#include<struck>
using namespace std;

template<class Object>
bool Stack<Object>::empty() const{
    
    return topOfStack == -1;
}

int main(){
    
    Stack<int> s;
    
    for(int i=0; i<10; i++){
        s.push(i);
    }
    
    while(!s.empty()){
        cout << s.top() << endl;
    }
    
    system("pause");
    return 0;
}
