class Solution {
public:
    int countStudents(vector<int>& students, vector<int>& sandwiches) {

        int n = students.size();
        int eaten = 0;
        int count = 0; //how many consecutive students have rejected the sandwich on top.

        while(!students.empty() && count < students.size()){
            if(students[0] == sandwiches[0]){
                students.erase(students.begin());
                sandwiches.erase(sandwiches.begin());
                eaten++;
                count = 0;
            }
            else{
                int temp = students[0];
                students.erase(students.begin());
                students.push_back(temp);
                count++;
            }
            
        }
        return n-eaten;
    }
};