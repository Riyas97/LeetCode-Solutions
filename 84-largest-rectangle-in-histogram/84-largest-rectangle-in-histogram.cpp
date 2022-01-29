class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        stack <int> st;
        st.push(heights.size() - 1);
        int ans = heights[heights.size() - 1];
        for (int i = heights.size() - 2; i >= 0; i--) {
            while (!st.empty() && heights[st.top()] > heights[i]) {
                int ind = st.top();
                int num = heights[st.top()];
                st.pop();
                int ele = 1;
                if (!st.empty()) {
                    ele = st.top() - i - 1;
                } else {
                    ele = heights.size() - 1 - i;
                }
                int find = num * ele;
                ans = max(ans, find);
            }
            st.push(i);
        }
        
        while (!st.empty()) {
            int ind = st.top();
            int num = heights[st.top()];
            st.pop();
            int ele = 1;
            if (!st.empty()) {
                ele = st.top();
            } else {
                ele = heights.size();
            }
            int find = num * ele;
            ans = max(ans, find);
        }
        
        return ans;
        
    }
};