#include<iostream>
#include<vector>
using namespace std;

int maxSubSum3(const vector<int>& a){ //the driver
    
    //return maxSumRec(a, 0, a.size()-1);
}

int main(){
    
    vector<int> a(8);
    
    a[0] = 4; a[1] = -3; 
    a[2] = 5; a[3] = -2;
    a[4] = -1; a[5] = 2;
    a[6] = 6; a[7] = -2;
    
    int maxSum = 0;
    maxSum = maxSubSum3(a);
    
    cout << "The max sum is: " << maxSum << endl;
    
    for(int i=0; i<a.size(); i++){
        cout << a[i] << endl;
    }
    
    system("pause");
    
}
