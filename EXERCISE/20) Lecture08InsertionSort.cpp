#include<iostream>
#include<vector>
using namespace std;

void insertionSort(vector<int>& a){
    
    int j;
    
    for(int p = 1; p < a.size(); p++){
        
        int tmp = a[p];
        
        for(j = p; j > 0 && tmp < a[j - 1]; j--){
            a[j] = a[j - 1];
        }
        a[j] = tmp;
    }
}

int main(){
    
    vector<int> a;
    a.push_back(17);
    a.push_back(20);
    a.push_back(43);
    a.push_back(25);
    a.push_back(4);
    a.push_back(72);
    a.push_back(15);
    
    cout << "Ansorted vector: " << endl;
    for(int i=0; i<a.size(); i++){
        cout << a[i] << " ";
    }
    cout << endl;
    insertionSort(a);
    cout << "Sorted vector: " << endl;
    for(int i=0; i<a.size(); i++){
        cout << a[i] << " ";
    }
    
    
    system("pause");
}
