class Solution {
  public:
  
    int upper(vector<int>& mat, int x){
        int low = 0;
        int high = mat.size()-1;
        int ans = mat.size();
        while(low <= high){
            int mid = low + (high - low)/2;
            if(mat[mid]>x){
                ans = mid ;
                high = mid -1;
            }
            else{
                low = mid + 1;
            }
        }
        return ans;
    }
    
    int com (vector<vector<int>> &mat, int x){
        int n = mat.size();
        int cnt = 0;
        for (int i = 0; i < n ; i++){
            cnt += upper(mat[i],x);
        }
        return cnt;
    }
    int median(vector<vector<int>> &mat) {
        // code here
        int high = INT_MIN;
        int low = INT_MAX;
        int n = mat.size();
        int m = mat[0].size();
        int k = (n*m)/2;
        for (int i = 0; i<n ; i++){
             low = min(mat[i][0],low);
             high = max(mat[i][m-1],high);
        }
        while(low <= high){
            int mid = low + (high - low)/2;
            int cc = com(mat,mid);
            if (cc > k){
                high = mid -1;
            }
            else{
                low = mid + 1;
            }
        }
        return low;
    }
};
