class Solution {
public:
    int maxDistance(vector<int>& colors) {
        set <int> uniq;
        unordered_set <int> paint;
        int a = 0;
        for (int i = 0; i < colors.size(); i++) {
            
            int b = *uniq.begin();
            
            if (paint.find(colors[i]) == paint.end()) {
                a = max(a, i - b);
                paint.insert(colors[i]);
                uniq.insert(i);
            } else {
                if (colors[b] == colors[i]) {
                    if (uniq.size() > 1) {
                        auto bb = uniq.begin();
                        bb++;
                        a = max(a, i - *bb);
                    }
                } else {
                    a = max(a, i - b);
                }
            }
        }
        return a;
    }
};