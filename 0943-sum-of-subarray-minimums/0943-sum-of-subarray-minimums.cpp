class Solution {
public:
    vector<int> findnse(vector<int> &arr){
        vector<int> nse(arr.size(), arr.size());
        stack<int> st;
        for(int i = arr.size() - 1; i >= 0; i--){
            while(!st.empty() && arr[st.top()] >= arr[i]){
                st.pop();
            }
            nse[i] = st.empty() ? arr.size() : st.top();
            st.push(i);
        }
        return nse;
    }

    vector<int> findpse(vector<int> &arr){
        vector<int> pse(arr.size(), -1);
        stack<int> st;
        for(int i = 0; i < arr.size(); i++){
            while(!st.empty() && arr[st.top()] > arr[i]){//edge case so only > here(imp)
                st.pop();
            }
            pse[i] = st.empty() ? -1 : st.top();
            st.push(i);
        }
        return pse;
    }

    int sumSubarrayMins(vector<int>& arr) {
        int total = 0;
        int mod = 1e9 + 7; // Corrected MOD value
        vector<int> nse = findnse(arr);
        vector<int> pse = findpse(arr);
        
        for(int i = 0; i < arr.size(); i++){
            int left = i - pse[i];
            int right = nse[i] - i;
            total = (total + (1LL * right * left * arr[i]) % mod) % mod; // Fixed multiplication-> the 1LL for long long
        }
        return total;
    }
};
