class Solution {
public:
    vector<int> canSeePersonsCount(vector<int>& heights) {
        vector <int> ans (heights.size(), 0);
        stack <int> st;
        st.push(heights.size() - 1);
        ans[ans.size() - 1] = 0;
        
        for (int i = heights.size() - 2; i >= 0; i--) {
            
            
            
            int count = 0;
            
            while (!st.empty() && 
                   heights[i] > heights[st.top()]) {
                //cout << i << " " << st.top() << "\n";
                st.pop();
                count++;
            }
            
            ans[i] = count;
            
            if (!st.empty()) {
                ans[i]++;
            }
            
            st.push(i);
            
        }
        
        return ans;
    }
    
};