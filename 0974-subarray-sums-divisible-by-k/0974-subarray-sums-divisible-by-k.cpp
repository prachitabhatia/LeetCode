class Solution {
public:
    int subarraysDivByK(vector<int>& nums, int k) {
        unordered_map<int,int> hash;
        hash[0] = 1; //setting frequency of 0 as 1.
        int prefixSum = 0;
        int count = 0;

        for(auto i : nums){
            prefixSum += i;
            int rem =((prefixSum % k) + k) % k;
            count += hash[rem];
            hash[rem]++;
        }
        return count;
    }
};