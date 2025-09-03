// Function to find three numbers in the given array
// such that arr[smaller[i]] < arr[i] < arr[greater[i]]

class Solution {
  public:
    vector<int> find3Numbers(vector<int> &arr) {
        // Code here
        int n = arr.size();
        int mini[n];
        int maxi[n];
        mini[0] = arr[0];
        maxi[n-1]=arr[n-1];
        
        for (int i = 1; i < n; i++){
            mini[i]= min(arr[i],mini[i-1]);
            maxi[n-i-1]= max(arr[n-1-i],maxi[n-i]);
        }
        for (int i = 1; i <n-1 ;i++){
            if (arr[i] > mini[i] && arr[i] < maxi[i]){
                return{mini[i],arr[i],maxi[i]};
            }
           
    }
     return {};}
};