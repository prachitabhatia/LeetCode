class Solution {
public:
    int numberOfSubstrings(string s) {
        unordered_map<int,int> hash;
        int subStringCount = 0;
        int left = 0;

        for(int right = 0; right < s.size(); right++){
            hash[s[right]-'a']++;
            while(hash.size()==3){
                subStringCount += s.size() - right;
                hash[s[left]-'a']--;
                if(hash[s[left]-'a'] == 0){
                    hash.erase(s[left]-'a');
                }
                left++;
            }
            
        }
        return subStringCount;
    }
};