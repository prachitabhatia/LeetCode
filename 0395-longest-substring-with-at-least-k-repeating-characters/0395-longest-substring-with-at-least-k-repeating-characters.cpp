class Solution {
public:
    int solve(string s, int k){
        vector<int> counts(26,0);
        bool valid = true;

        //counting frequencies.
        for(int i = 0; i < s.size(); i++){
            counts[s[i]-'a']++;
        }

        //base case for recursion
        for(int i = 0; i < s.size(); i++){
            if(counts[s[i]-'a'] < k){
                valid = false;
                break;
            }        
        }
        if(valid){
            return s.size();
        }

        char bad;
        for(int i = 0; i < s.size(); i++){
            if(counts[s[i]-'a'] < k){
                bad = s[i];
                break;
            }
        }

        int ans = 0;
        int start = 0;
        for(int i = 0; i < s.size(); i++){
            if(s[i]==bad){
                if(i > start){
                    ans = max(ans, solve(s.substr(start,i-start),k));
                }
                start = i + 1;
            }
        }
        if(start < s.size()){
            ans = max(ans,solve(s.substr(start),k));
        }
        return ans;
    }

    int longestSubstring(string s, int k) {
        return solve(s,k);
    }
};