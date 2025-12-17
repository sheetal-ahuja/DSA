    void interchange(vector<vector<int>>& arr, int r, int c) {

    for (int i = 0; i < r; i++) {
        swap(arr[i][0], arr[i][c - 1]);
    }

    // print
    for (int i = 0; i < r; i++) {
        for (int j = 0; j < c; j++) {
            cout << arr[i][j] << " ";
        }
        cout << endl;
    }
}