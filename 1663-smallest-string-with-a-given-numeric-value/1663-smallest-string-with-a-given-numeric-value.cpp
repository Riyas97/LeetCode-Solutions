class Solution {
public:
    string getSmallestString(int n, int k) {
        string ans(n, 'a');
        for (int i = n-1; i >= 0; i--) {
            //cout << i << "\n";
            int num = i + 26;
            if (k > num) {
                //ans = "z" + ans;
                ans[i] = 'z';
                k -= 26;
            } else {
                int diff = k - i;
                char lett = 'a' + (diff-1);
                ans[i] = lett;
                k -= diff;
            }
        }
        
        return ans;
    }
};