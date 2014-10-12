// Cubic maximum contigous subsequence sum algorithm
// seqStart and seqEnd respresent the actual best sequence

template <class Comparable>

Comparable maxSubsequenceSum (const vector<Comparable>& a, int& seqStart, int& seqEnd){
           
           int n = a.size();
           Comparable maxSum = 0;
           
           for(int i=0; i<n; i++){
                   for(int j=i; j<n; j++){
                           Comparable thisSum = 0;
                           for(int k=i; i<=j; k++){
                                   thisSum += a[k];
                           }
                           if (thisSum > max){
                                       maxSum = thisSum;
                                       seqStart = i;
                                       seqEnd = j;
                           }
                   }
           }
           return maxSum;
}
