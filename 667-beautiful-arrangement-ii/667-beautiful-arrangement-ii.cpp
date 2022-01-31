class Solution {
public:
    vector<int> constructArray(int n, int k) {
        //vector <int> diff (n-1, 0);
        vector <int> ans;
        int diff = n - k;
        for (int i = 0; i < diff; i++) {
            ans.push_back(i+1);
        }
        int s1 = diff + 1;
        int s2 = n;
        bool alt = true;
        for (int i = diff; i < n; i++) {
            if (alt) {
                ans.push_back(s2);
                s2--;
                alt = false;
            } else {
                ans.push_back(s1);
                s1++;
                alt = true;
            }
        }
        return ans;
    }
};

//1 2 3 9 4 8 5 7 6
//1 1 6 5 4 3 2 1
    
    