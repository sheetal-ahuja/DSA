class Solution {
public:
    int countPartitions(vector<int>& nums) {
        int left = 0;
        int ans = 0;
        int sum = 0;
        int n = nums.size();
        for(int i = 0; i<n; i++)
        {
            sum = sum+nums[i];
        }

        for(int i = 0; i<n-1;i++)
        {

            left = left + nums[i];
            int right = sum - left;
            int diff = left - right;
            if(diff%2 == 0)
            {
                ans++;
            }
        }

        return ans;
    }
};