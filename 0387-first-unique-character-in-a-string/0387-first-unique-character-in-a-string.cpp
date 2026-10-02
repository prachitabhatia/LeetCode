class Solution {
public:
    int firstUniqChar(string s) {

        unordered_map<int,int> hash;

        int n = s.size();

        if(n == 1){
            return 0;
        }

        for(int i = 0; i < n; i++){
            hash[s[i] - 'a']++;
        }

        for(int i = 0; i < n; i++){
            if(hash[s[i] - 'a'] == 1){
                return i;
            }
        }
        return -1;
        
    }
};