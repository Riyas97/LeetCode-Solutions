class Solution {
public:
    int minDominoRotations(vector<int>& tops, vector<int>& bottoms) {
        unordered_map <int, int> count;
        unordered_map <int, int> bcount;
        unordered_map <int, int> tcount;
        vector<int> vect;
        for (int i = 0; i < tops.size(); i++) {
            int n1 = tops[i];
            int n2 = bottoms[i];
            tcount[n1]++;
            bcount[n2]++;
            if (n1 == n2) {
                count[n1]++;
                if (count[n1] == tops.size()) {
                    vect.push_back(
                        max(tcount[n1], bcount[n2]));
                }
            } else {
                count[n1]++;
                count[n2]++;
                if (count[n1] == tops.size()) {
                    vect.push_back(
                        max(tcount[n1], bcount[n1]));
                }
                if (count[n2] == tops.size()) {
                    vect.push_back(
                        max(tcount[n2], bcount[n2]));
                }
            }
        }
        
        if (vect.size() == 0) {
            return -1;
        }
        
        sort(vect.begin(), vect.end());
        
        return tops.size() - vect[vect.size() - 1];
        
    }
};