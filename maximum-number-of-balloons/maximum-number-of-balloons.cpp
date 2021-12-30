class Solution {
public:
    int maxNumberOfBalloons(string text) {
        vector<int> v1 (26, 0);
        
        for (int i = 0; i < text.size(); i++) {
            v1[text[i] - 'a']++;
        }
          
        int ans = min({v1[0],v1[1], v1[11] / 2, v1[14] / 2, 
                       v1[13]});
        return ans;
        
    }
};