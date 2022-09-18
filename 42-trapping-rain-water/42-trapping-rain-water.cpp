class Solution {
public:
    int trap(vector<int>& height) {
        stack<int> st;
        int ans = 0;
        for (int i = 0; i < height.size(); i++) {
            while (!st.empty() && 
                   height[i] > height[st.top()]) {
                int prevIndex = st.top();
                st.pop();
                if (st.empty()) {
                    break;
                }
                int distance = i - st.top() - 1;
                int bounded = min(height[i], height[st.top()]) - height[prevIndex];
                ans += distance * bounded;
            }
            st.push(i);
        }
        return ans;
    }
};