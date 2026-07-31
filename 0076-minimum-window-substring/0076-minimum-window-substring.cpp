class Solution {
public:
    string minWindow(string s, string t) {
        unordered_map<char,int> hash;
        int left = 0;
        int required = t.size();
        int start = 0;
        int minLen = INT_MAX;

        for(int i = 0; i < t.size(); i++){  //storing elements of t in a hash
            hash[t[i]]++;
        }

        for(int right = 0; right < s.size(); right++){
            if(hash[s[right]] > 0){
                required--;
            }
            hash[s[right]]--;

            while(required == 0){  //valid window found
                if(right - left + 1 < minLen){
                    minLen = right - left + 1;
                    start = left;  //indicates where the minimum substring starts
                }
                hash[s[left]]++;

                if(hash[s[left]]>0){
                    required++;
                }
                left++;
            }


        }
        if(minLen == INT_MAX){
                return "";
            }
        return s.substr(start,minLen);            
    }
};