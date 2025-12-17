#include<vector>
class Solution {
  public:
    vector<int> sumTriangles(vector<vector<int>>& mat) {
        // code here
        vector<int> ans;
        int u_sum = 0;
        int l_sum = 0;
        int r_size = mat.size();
        for(int i = 0; i<r_size; i++ ){
            for(int j = i; j<r_size; j++ ){
                u_sum = u_sum + mat[i][j];
            }
        }
        
        for(int i = 0; i<r_size; i++ ){
            for(int j = i; j>=0; j-- ){
                l_sum = l_sum + mat[i][j];
            }
        }
        ans.push_back(u_sum);
        ans.push_back(l_sum);
        
        return ans;
    }
};