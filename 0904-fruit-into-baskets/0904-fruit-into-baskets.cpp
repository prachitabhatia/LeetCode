class Solution {
public:
    int totalFruit(vector<int>& fruits) {
        unordered_map<int,int> hash; 
        int left = 0;
        int len = 0;
        int maxLen = 0;

        for(int right = 0; right < fruits.size(); right++){
            hash[fruits[right]]++; 

            while(hash.size()>2){
                hash[fruits[left]]--;
                if(hash[fruits[left]]==0){
                    hash.erase(fruits[left]);
                }
                left++;
            }

            len = right - left + 1;
            maxLen = max(len,maxLen);

        }    
        return maxLen;    
    }
};