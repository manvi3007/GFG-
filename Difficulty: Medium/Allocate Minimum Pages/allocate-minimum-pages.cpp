class Solution {
  public:
    int check (vector<int> &arr, int k){
        int stud = 1;
        int pages = 0;
       
        
        for (int i = 0; i < arr.size(); i++) {
    if (pages + arr[i] <= k) {
        pages += arr[i];
    } else {
        stud++;
        pages = arr[i];
    }
}
        return stud;
    }
    int findPages(vector<int> &arr, int k) {
        // code here
        if (k > arr.size()){
            return -1;
        }
        int low = *max_element(arr.begin(),arr.end());
        int sum = 0;
        for (int i = 0; i < arr.size() ; i++){
            sum += arr[i];
        }
        int high = sum;
        
        while (low <= high){
            int mid = low + (high - low)/2;
            int che = check(arr,mid);
            if (che > k){
                low = mid +1;
            }
            else {
                high = mid -1;
            }
        }
        return low;}
};