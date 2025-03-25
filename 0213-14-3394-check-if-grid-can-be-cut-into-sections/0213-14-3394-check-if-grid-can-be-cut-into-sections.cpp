class Solution {
public:
     vector<vector<int>> merge(vector<vector<int>>& intervals) {
        int n = intervals.size();
        vector<vector<int>> ans;
        sort(begin(intervals), end(intervals));
        ans.push_back(intervals[0]);
        for(int i = 1; i<n; i++){
                if(intervals[i][0] < ans.back()[1]){
                        ans.back()[1] = max(ans.back()[1], intervals[i][1]);
                }else{
                        ans.push_back(intervals[i]);
                }
        }
        return ans;
    }
        
    bool checkValidCuts(int n, vector<vector<int>>& rectangles) {
        vector<vector<int>> hor;
        vector<vector<int>> ver;
        for(auto &it:rectangles){
                int x1 = it[0];
                int y1 = it[1];
                int x2 = it[2];
                int y2 = it[3];
                hor.push_back({x1, x2});
                ver.push_back({y1, y2});
        }
        vector<vector<int>> ans1 = merge(hor);
        vector<vector<int>> ans2 = merge(ver);
        return ans1.size() >= 3 || ans2.size() >=3;
    }
};