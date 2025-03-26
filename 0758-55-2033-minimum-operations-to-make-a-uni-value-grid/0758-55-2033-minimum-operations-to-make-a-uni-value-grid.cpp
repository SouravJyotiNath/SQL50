class Solution {
public:
    int minOperations(vector<vector<int>>& grid, int x) {
        int m = grid.size();
        int n = grid[0].size();
        int ans = 0;
        vector<int> v;
        for(int i = 0; i<m; i++){
                for(int j = 0; j<n; j++){
                        v.push_back(grid[i][j]);
                }
        }
        int l = v.size();
        sort(v.begin(), v.end());
        int trg = v[l/2];
        for(int &it: v){
                if(it%x != trg%x){
                        return -1;
                }
                ans += abs(trg-it)/x;
        }
        return ans;
    }
};