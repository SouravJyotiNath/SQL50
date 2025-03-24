class Solution {
public:
    int countDays(int days, vector<vector<int>>& meetings) {
        int st = 0;
        int last = 0;
        int ans = 0;
        sort(begin(meetings), end(meetings));
        for(auto &it : meetings){
                if(it[0] > last){
                        ans += it[0]-last-1;
                }
                last = max(last, it[1]);
        }
        if(days > last){
                ans += days-last;
        }
        return ans;
    }
};