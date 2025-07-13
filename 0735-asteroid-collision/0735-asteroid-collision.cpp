class Solution {
public:
    vector<int> asteroidCollision(vector<int>& asteroids) {
        vector<int> st;
        for(int i =0;i<asteroids.size();i++){
            if(asteroids[i]>0){
                st.push_back(asteroids[i]);
            }else{
                //so if -ve we see if st is not empty and has a positive int and less than the -ve one then we remove it
                while(!st.empty() && st.back()>0 && st.back()< abs(asteroids[i])){
                    st.pop_back();
                }
                //now if st not empty and top is same then pop it and no push of -ve one
                if(!st.empty() && st.back()==abs(asteroids[i])) st.pop_back();
                //so if negative we put to stack only if stack is already empty or if the top of it is negative 
                else if(st.empty() || st.back()<0) st.push_back(asteroids[i]);
            }
        }
        return st;
    }
};