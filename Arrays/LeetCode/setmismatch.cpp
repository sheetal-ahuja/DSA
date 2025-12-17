class Solution {
public:
    vector<int> findErrorNums(vector<int>& nums) {
        int n = nums.size();
        vector<int> ans(2);
        
        sort(nums.begin(), nums.end());

        // Step 1: find duplicate
        for (int i = 1; i < n; i++) {
            if (nums[i] == nums[i - 1]) {
                ans[0] = nums[i];
                break;
            }
        }

        // Step 2: find missing
        int expected = 1;
        for (int x : nums) {
            if (x == expected) {
                expected++;
            }
        }
        ans[1] = expected;  // first number not matched

        return ans;
    }
};
