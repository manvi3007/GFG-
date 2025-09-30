class Solution {
  public:
    bool check(vector<int> &st,int m , int k){
        int n = st.size();
        int last = st[0];
        int nu = 1;
        for (int i = 1; i < n ; i++){
            if (st[i] - last >= m){
                nu++;
                last = st[i];
            }
            
        }
        if(nu >= k){
            return true;
        }
        else{
            return false;
        }
    }
    int aggressiveCows(vector<int> &stalls, int k) {
        int low = 1;
        int n = stalls.size();
        sort(stalls.begin(),stalls.end());
        int high = stalls[n-1]-stalls[0];
        while(low <= high){
            int mid = low + (high - low)/2;
            if(check(stalls,mid,k)==true){
                low = mid +1;
            }
            else{
                high = mid -1 ;
            }
        }
        return high;
    }
};