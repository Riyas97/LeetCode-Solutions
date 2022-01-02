class Solution {
public:
    int numTeams(vector<int>& rating) {
        int sum = 0;
        for (int i = 0; i < rating.size(); i++) {
            int leftL = 0;
            int leftH = 0;
            int rightL = 0;
            int rightH = 0;

            for (int j = 0; j < i; j++) {
                if (rating[j] > rating[i]) {
                    leftH++;
                } else if (rating[j] < rating[i]) {
                    leftL++;
                }
            }
            
            for (int j = i + 1; j < rating.size(); j++) {
                if (rating[j] > rating[i]) {
                    rightH++;
                    
                } else if (rating[j] < rating[i]) {
                    rightL++;
                }
            }
            // number of left lesser * number of right higher
            // and number of left higher * number of right lesser
            int num = (leftH * rightL) + (leftL * rightH);
            sum += num;
        }
        return sum;
    }
};