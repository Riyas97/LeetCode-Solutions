class Solution {
public:
    int maxArea(int h, int w, vector<int>& horizontalCuts, vector<int>& verticalCuts) {
        int mhor = 1;
        int prevh = 0;
        sort(horizontalCuts.begin(), horizontalCuts.end());
        sort(verticalCuts.begin(), verticalCuts.end());
        for (int i = 0; i < horizontalCuts.size(); i++) {
            mhor = max(mhor, horizontalCuts[i] - prevh);
            prevh = horizontalCuts[i];
        }
        mhor = max(mhor, h - prevh);
        
        int mver = 1;
        int prevv = 0;
        for (int i = 0; i < verticalCuts.size(); i++) {
            mver = max(mver, verticalCuts[i] - prevv);
            prevv = verticalCuts[i];
        }
        mver = max(mver, w - prevv);
        
        //cout << mver << " " << mhor << " ";
        
        return (1LL*mver*mhor) % 1000000007;
    }
};