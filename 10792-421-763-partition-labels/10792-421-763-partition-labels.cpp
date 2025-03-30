class Solution {
public:
    vector<int> partitionLabels(string s) {
        int n = s.size();
        vector<int> ans;
        vector<int> count(26,-1);
        for(int i = 0; i<n; i++){
                int idx = s[i]-'a';
                count[idx] = i;
        }
        int i = 0; 
        while(i<n){
                int end = count[s[i]-'a'];
                int j = i;
                while(j<end){
                        end = max(end , count[s[j]-'a']);
                        j++;
                }
                ans.push_back(j-i+1);
                i = j+1;
        }
        return ans;
    }
};