class Solution {
public:
    bool multiplyMatrix(int mat1[4][4], int mat2[4][4], int res[4][4]) {

        // Step 1: Create a vector to store the multiplied matrix
        vector<vector<int>> temp(4, vector<int>(4, 0));

        // Step 2: Perform multiplication and store in temp
        for (int i = 0; i < 4; i++) {
            for (int j = 0; j < 4; j++) {
                for (int k = 0; k < 4; k++) {
                    temp[i][j] += mat1[i][k] * mat2[k][j];
                }
            }
        }

        // Step 3: Compare temp with res
        for (int i = 0; i < 4; i++) {
            for (int j = 0; j < 4; j++) {
                if (temp[i][j] != res[i][j]) {
                    return false;
                }
            }
        }

        return true;
    }
};