#include <iostream>
#include <vector>
#include <fstream>
using namespace std;

void maxContSeq(vector<int>& sequence){
     
     int n=sequence.size();
     int maxSum=0, seqStart=0, seqEnd=0;
     int index0=0, index1=0, index2=0;
     vector<int> fourSeqVec;
     
     for(int i=0; i<n; i++){             
             cout << "i values " << i << endl;
             for(int j=i; j<n; j++){
                     int thisSum=0;
                     cout << "j values " << j << endl;
                     for(int k=i; k<=j; k++){
                             cout << "k values " << k << endl;
                             cout << "vector value at index i " << sequence[i] << endl;
                             cout << "vector value at index j " << sequence[j] << endl;
                             cout << "vector value at index k " << sequence[k] << endl;
                             thisSum = thisSum + sequence[k];
                             cout << "this sum " << thisSum << endl;
                             if(thisSum > maxSum){
                                        maxSum=thisSum;
                                        seqStart=i;
                                        seqEnd=j;
                             }
                     }
             }
     cout << endl;
     }
     cout << "Max Sum" << "\t" << "Seq Starts" << "\t" << "Seq Ends" << seqEnd << endl << endl;
     cout << maxSum << "\t" << seqStart << "\t" << seqEnd << endl;
}
                                        
                             
                     
     
int main(){
    
    vector<int> sequence;
    sequence.push_back(1);
    sequence.push_back(2);
    sequence.push_back(3);
    sequence.push_back(4);
    sequence.push_back(5);
    sequence.push_back(6);
    sequence.push_back(7);
    sequence.push_back(8);
    sequence.push_back(9);
    sequence.push_back(10);
    sequence.push_back(11);
    sequence.push_back(12);
    maxContSeq(sequence);
    
    system("pause");
    return 0;
}
    
    
     
     
