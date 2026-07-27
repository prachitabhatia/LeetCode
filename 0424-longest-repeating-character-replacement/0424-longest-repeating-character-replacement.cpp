class Solution {
public:
    int characterReplacement(string s, int k) {
        vector<int> count(26,0);
        int left = 0;
        int maximum = 0;
        int maxLen = 0;
        int nonMax, len;

        for(int right = 0; right < s.size(); right++){
            count[s[right]-'A']++;
            for(int i = 0; i < 26; i++){
                maximum = max(maximum , count[i]);
            }
            nonMax = (right-left+1)-maximum;

            while(nonMax > k){
                count[s[left]-'A']--;
                left++;
                for(int i = 0; i < 26; i++){
                    maximum = max(maximum , count[i]);
                }
                nonMax = (right-left+1)-maximum;
            }

            len = right - left + 1;
            maxLen = max(maxLen,len);
        }
        return maxLen;
    }
};