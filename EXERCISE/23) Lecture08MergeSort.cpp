#include<iostream>
#include<vector>
using namespace std;

template<class Comparable>
void mergeSort(vector<Comparable>& a);

template<class Comparable>
void mergeSort(vector<Comparable>& a, vector<Comparable>& tmpArray, int left, int right);

template<class Comparable>
void merge(vector<Comparable>& a, vector<Comparable>& tmpArray, int leftPos, int rightPos, int rightEnd);

/*                              */

template<class Comparable>
void mergeSort(vector<Comparable>& a){
    
    vector<Comparable> tmpArray(a.size());
    
    merge(a, tmpArray, 0, a.size()- 1);
    
}

template<class Comparable>
void merge(vector<Comparable>& a, vector<Comparable>& tmpArray, int leftPos, int rightPos, int rightEnd){
    
    int leftEnd = rightPos - 1;
    int tmpPos = leftPos;
    int numElements = rightEnd - leftPos + 1;
    
    while(leftPos <= leftEnd && rightPos <= rightEnd){
        if(a[leftPos] <= a[rightPos]){
            tmpArray[tmpPos++] = a[leftPos++];
        }
        else{
            tmpArray[tmpPos++] = a[rightPos++];
        }
    }
    cout << "Index[0]: " <<tmpArray[0] << endl;
    cout << "Index[1]: " << tmpArray[1] << endl;
    cout << "Index[2]: " << tmpArray[2] << endl;
}

int main(){
    
    vector<int> a;
    
    //a.push_back(43);
    //a.push_back(37);
    //a.push_back(20);
    a.push_back(25);
    a.push_back(4);
    a.push_back(72);
    //a.push_back(15);
    //a.push_back(19);
    
    cout << "Unsorted Vector: " << endl;
    for(int i=0; i<a.size(); i++){
        cout << a[i] << " ";
    }
    cout << endl;
    
    mergeSort(a);
    
    cout << "Sorted Vector: " << endl;
    for(int i=0; i<a.size(); i++){
        cout << a[i] << " ";
    }
    cout << endl;
    
    system("pause");
}
    
