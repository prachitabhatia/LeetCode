class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {

        vector<vector<int>> quadruplets;
        int n = nums.size();
        sort(nums.begin(),nums.end());
        long long sum;

        for(int i = 0; i < n; i++){
            for(int j = i+1; j < n; j++){
                if(i > 0 && nums[i] == nums[i-1]){
                    continue;
                }
                if(j > i+1 && nums[j] == nums[j-1]){
                    continue;
                }

                int p1 = j+1;
                int p2 = n-1;

                while(p1 < p2){
                    sum = (long long)nums[i] + nums[j] + nums[p1] + nums[p2];
                    if(sum == target){
                        quadruplets.push_back({nums[i], nums[j], nums[p1], nums[p2]});
                        p1++;
                        p2--;

                        while(p1 < p2 && nums[p1] == nums[p1-1]){
                            p1++;
                        }
                        while(p1 < p2 && nums[p2] == nums[p2+1]){
                            p2--;
                        }
                    }
                    else if(sum < target){
                        p1++;
                    }
                    else if(sum > target){
                        p2--;
                    }
                }
            }
        }
        return quadruplets;
    }
};