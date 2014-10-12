#include<iostream>
#include<vector>
using namespace std;

int main(){
    
    int a[] = {12, 34, 55, 32, 7, 88, 303};
    vector<int> v(a, a+7);
    vector<int>::iterator r_itr1;
    vector<int>::iterator r_itr2;
    
    r_itr1 = v.begin();
    r_itr2 = v.end();
    
    cout << v.size() << "=" << r_itr2 - r_itr1 << endl;
    
    for(int i=0; i < v.size(); i++){
        cout << "( " <<v[i] << ", " << i << " )" << endl;
    }
    
    for(r_itr1 == v.begin(); r_itr1 != v.end(); ++ r_itr1){
        cout << "( " << *r_itr1 << ", " << r_itr1 - v.begin() << " )" << endl;
    }
    
    system("pause");
}
