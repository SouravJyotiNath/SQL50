class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        int n = intervals.size();
        vector<vector<int>> ans;
        sort(begin(intervals), end(intervals));
        ans.push_back(intervals[0]);
        for(int i = 1; i<n; i++){
                if(intervals[i][0] <= ans.back()[1]){
                        ans.back()[1] = max(ans.back()[1], intervals[i][1]);
                }else{
                        ans.push_back(intervals[i]);
                }
        }
        return ans;
    }
};