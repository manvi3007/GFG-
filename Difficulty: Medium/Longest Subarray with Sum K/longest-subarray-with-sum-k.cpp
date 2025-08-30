class Solution {
public:
    int longestSubarray(vector<int>& arr, int k) {
        int maxx = 0;
        long long sum = 0;
        int n = arr.size();
        unordered_map<long long,int>mp;
        
        for (int i = 0; i <n ; i++){
            sum += arr[i];
            if (sum == k ){
                maxx = max (maxx, i+1);
            }
            
            if ( mp.find(sum-k) != mp.end()){
                maxx = max(maxx, i - mp[sum-k]);
            }
            if (mp.find(sum) == mp.end()){
                mp[sum] = i;
            }
        }
        return maxx;
    }
};
