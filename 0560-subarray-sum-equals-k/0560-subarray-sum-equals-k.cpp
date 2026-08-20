class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        map<int,int> hash;
        hash[0] = 1; //setting frequency of 0 as 1
        int prefixSum = 0;
        int count = 0;

        for(auto i : nums){
            prefixSum += i;
            if(hash.find(prefixSum - k) != hash.end()){
                count += hash[prefixSum - k];
            }
            hash[prefixSum]++;
        }   
        return count;
    }
};