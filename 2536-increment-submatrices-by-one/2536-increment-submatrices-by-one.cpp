class Solution {
public:
    vector<vector<int>> rangeAddQueries(int n, vector<vector<int>>& queries) {
        vector<vector<int>> difference(n+1,vector<int> (n+1,0));
        int r1,c1,r2,c2;
        for(int i = 0; i < queries.size(); i++){
            r1 = queries[i][0];
            c1 = queries[i][1];
            r2 = queries[i][2];
            c2 = queries[i][3];
            
            difference[r1][c1]++;
            difference[r1][c2+1]--;
            difference[r2+1][c1]--;
            difference[r2+1][c2+1]++;
        }

        vector<vector<int>> prefix(n,vector<int> (n,0));
        for(int i = 0; i < n; i++){
            for(int j = 0; j < n; j++){
                prefix[i][j] = difference[i][j];
                if(i > 0){
                    prefix[i][j] += prefix[i-1][j];
                }
                if(j > 0){
                    prefix[i][j] += prefix[i][j-1];
                }
                if(i > 0 && j>0 ){
                    prefix[i][j] -= prefix[i-1][j-1];
                }
            }
        }
        return prefix;
    }
};