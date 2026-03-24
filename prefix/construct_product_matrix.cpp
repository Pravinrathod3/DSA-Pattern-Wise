class Solution {
public:

    int mod = 12345;

    vector<vector<int>> constructProductMatrix(vector<vector<int>>& grid) {
    
        int m = grid.size();
        int n = grid[0].size();

        vector<vector<int>> p(m, vector<int> (n));

        vector<int> arr;  // we can also do this without using extra space by directly calculating prefix and suffix in the same loop but here we are using extra space for better understanding of the concept

        for(int i=0; i<m; i++){
            for(int j=0; j<n; j++){
               arr.push_back(grid[i][j] % mod); // we are taking mod here to avoid overflow and also to keep the numbers manageable as we are multiplying them later on and it can easily exceed the range of int if we don't take mod here
            }
        }

        int size = m*n ;

        vector<int> prefix(size), suffix(size);
        prefix[0] = 1;
        suffix[size-1] = 1;

        for(int i=1; i<size; i++){
           prefix[i] = (prefix[i-1] * arr[i-1]) % mod ;
        }

        for(int i=size-2; i>=0; i--){
           suffix[i] = (suffix[i+1] * arr[i+1]) % mod;
        }

        for(int i=0; i<size; i++){
            int ans = (prefix[i] * suffix[i]) % mod;
            p[i/n][i%n] = ans;  // we are using i/n to get the row index and i%n to get the column index in the original grid and we are storing the result in the product matrix p
        }

        return p;
    }
};