class Solution {
    stack<int> st;
public:
    vector<int> asteroidCollision(vector<int>& asteroids) {
        
        int n = asteroids.size();
        int num;
        vector<int> output;

        for(int i = 0; i < n; i++){
            if(st.empty()){
                st.push(asteroids[i]);
                continue;
            }

            //collision is possible only in this one case.
            if(asteroids[i] < 0 && st.top() > 0){
                
                int current = asteroids[i];
                bool destroyed = false;
                while(!st.empty() && st.top() > 0){

                    if(abs(current) > st.top()){
                        st.pop();
                        //we wait to add asteroid[i] by checking with the new top first
                    }
                    else if(abs(current) == st.top()){
                        st.pop();
                        destroyed = true;
                        break;
                        //no need to add asteriod[i] cuz destroyed
                    }
                    else{
                        destroyed = true;
                        break;
                    }
                }

                if(!destroyed){
                    st.push(current);
                }
            }

            else{
                st.push(asteroids[i]);
            }
        }
        int size = st.size();
        output.resize(size);
        for(int i = size-1; i >= 0; i--){
            output[i] = st.top();
            st.pop();
        }
        return output;
    }
};