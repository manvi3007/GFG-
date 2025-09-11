class Solution {
  public: 
    int merge(vector<int>& arr, int low, int mid , int high){
        int cnt = 0;
        int left = low;
        int right = mid+1;
        vector<int>temp;

        while(left <= mid && right<= high){
            if (arr[left] <= arr[right]){
                temp.push_back(arr[left]);
                left++;
               
            }
            else{
                temp.push_back(arr[right]);
                right++;
                cnt += mid-left+1;
                 
            }

        }
        while(left <= mid){
            temp.push_back(arr[left]);
            left++;
        }
        while(right <= high){
            temp.push_back(arr[right]);
            right++;
        }
        for (int i = low ; i <= high; i++){
            arr[i]=temp[i-low];
        }
        return cnt;
  
    }
    int ms (vector<int>& arr, int low,int high){
        int cnt = 0 ;
        if (low >= high) return cnt ;
        int mid = (low+high)/2;
       

        cnt += ms(arr,low,mid);
        cnt += ms(arr,mid+1,high);
        cnt += merge(arr,low,mid,high);
        return cnt;
    }
    int inversionCount(vector<int> &arr) {
        int n = arr.size();
    
      return ms(arr,0,n-1);
        
        
    }
};