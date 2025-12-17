//Linear Search TC-> O(n) SC-> O(1)
class Solution{
    int search(vector<int>& arr, int x) {
        // code here
        int n = arr.size();
        for(int i = 0; i<n; i++){
            if(arr[i]==x){
                return i;
            }
        }
        return -1;
    }
}
