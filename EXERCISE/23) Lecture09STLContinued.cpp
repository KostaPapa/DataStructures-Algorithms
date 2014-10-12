#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

template<class InputItr, class Predicate>
InputItr find_if(InputItr first, InputItr last, Predicate pred){
    
    for(; first != last; first ++){
        if(pred(*first)) break;
        return first;
    }
}

bool isOdd(int i){
    return ((i%2) == 1);
}

int main(){
    
    vector<int> myVec;
    vector<int>::iterator it;
    
    myVec.push_back(10);
    myVec.push_back(25);
    myVec.push_back(40);
    myVec.push_back(55); 
    
    it = find_if(myVec.begin(), myVec.end(), isOdd);
    cout << *it << endl;
    
    system("pause");
}
