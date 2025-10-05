#include<bits/stdc++.h>
class Solution {
  public:
    int kthElement(vector<int> &a, vector<int> &b, int k) {
        // code here
        int n1 = a.size();
        int n2 = b.size();
        if(n1>n2)return kthElement(b,a,k);
        int low = max(0,k-n2);
        int high = min (k,n1);
        int left = k;
        int n = n1 + n2;
        while(low<=high){
            int mid1 = low + (high - low)/2;
            int mid2 = left - mid1;
            int l1 = INT_MIN;
            int l2 = INT_MIN;
            int r1 = INT_MAX;
            int r2 = INT_MAX;
            if(mid1 < n1) r1 = a[mid1];
            if(mid2 < n2) r2= b[mid2];
            if(mid1 -1 >= 0 ) l1 = a[mid1-1];
            if(mid2 -1 >= 0) l2 = b[mid2-1];
            if(r1 >= l2 && r2 >= l1){
                return max(l1,l2);
                
            }
            else if (r1 < l2){
                low = mid1 +1;
            }
            else{
                high = mid1 -1;
            }
        }
        return 0;
        
    }
};