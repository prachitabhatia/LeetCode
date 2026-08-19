class Solution {
public:
    int maximumPopulation(vector<vector<int>>& logs) {
        int arr[101]={0};
        for(int i = 0; i < logs.size(); i++){
            arr[logs[i][0]-1950]++;
            arr[logs[i][1]-1950]--;
        }
        for(int i = 1; i < 101; i++){
            arr[i] = arr[i] + arr[i-1];
        }
        
        int maxPopulationIndex = 0;
        int maxPopulation = 0;
        
        for(int i = 0; i < 101; i++){
            if(arr[i] > maxPopulation){
                maxPopulationIndex = i + 1950;
                maxPopulation = arr[i];
            }
        }
        return maxPopulationIndex;
    }
};