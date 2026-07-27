class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        unordered_map<char,int> index;
        int left  = 0;
        int ans = 0;
        
        for(int right = 0; right < s.size(); right++){
            if(index.count(s[right])){
                left = max(left , index[s[right]] + 1);
            }
            index[s[right]] = right; //storing index
            ans = max(ans, right-left+1);
        }
        return ans;
    }
};