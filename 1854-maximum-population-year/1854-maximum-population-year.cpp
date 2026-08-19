class Solution {
public:
    int maximumPopulation(vector<vector<int>>& logs) {
        int length, birth;
        map<int,int> hash;

        for(int i = 0; i < logs.size(); i++){
            length = logs[i][1] - logs[i][0];
            birth = logs[i][0];
            for(int j = 0; j < length; j++){
                hash[birth]++;
                birth++;
            }
        }

        int maxValue = 0;
        for(auto [key,value] : hash){
            maxValue = max(maxValue, value);
        }

        int maxPopulation = 0;
        for(auto[key,value]:hash){
            if(value==maxValue){
                maxPopulation = key;
                break;
            }
        }
        return maxPopulation;
    }
};