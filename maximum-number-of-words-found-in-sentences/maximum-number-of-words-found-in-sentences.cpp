class Solution {
public:
    int mostWordsFound(vector<string>& sentences) {
        int ans = -1;
        for (int i = 0; i < sentences.size(); i++) {
            stringstream ss (sentences[i]);
            int num = 0;
            string temp;
            while (getline(ss, temp, ' ')) {
                num++;
            }
            ans = max(ans, num);
        }
        return ans;
    }
};