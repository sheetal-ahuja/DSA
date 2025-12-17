//TC-> O(logn) 
class Solution {
public:
    int search(vector<int>& arr, int k) {
        int n = arr.size();
        int start = 0;
        int end = n-1;

        while(start<=end){
            int mid = (start+end)/2;
            if(arr[mid]==k){
                return mid;
            }
            if(arr[mid]<k){
                start = mid+1;
            }
            if(arr[mid]>k){
                end = mid-1;
            }
        }
        return -1;
    }
};