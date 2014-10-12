#include<iostream>
#include<list>
using namespace std;

template<class Object>
class Stack{
    public:
        Stack();
        Stack(const Object& rhs);
        ~Stack;
        
        bool empty() const;
        const Object& top() const;
        void pop();
        void push(const Object& x);
        const Stack& operator=(const Stack& rhs);
        
    private:
        struct LisrNode{
            Object element;
            ListNode *next;
            ListNode(const Object& theElement, ListNode * n = NULL)
            : element(theElement), next(n){}
        };
        ListNode *topOfStack;
    };

int main(){
    
    system("pause");
}
    
    
