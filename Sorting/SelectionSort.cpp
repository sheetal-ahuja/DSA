class Solution {
  public:
    // Function to perform selection sort on the given array.
    int selectionSort(vector<int> &arr) {
        // code here
        int n = arr.size();
        for(int i = 0; i<n-1; i++){
            int mini = arr[i];
            int minindex = 0;
            for(int j = i+1; j<n; j++){
                if(arr[j]<mini)
                {
                    mini = arr[j];
                    swap(arr[i],arr[j]);
                }
            }
        }
    }
};

// TC-> O(N2) Space-> O(1)
