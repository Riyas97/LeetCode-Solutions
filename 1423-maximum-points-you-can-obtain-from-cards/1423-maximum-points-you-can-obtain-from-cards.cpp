class Solution {
public:
    int maxScore(vector<int>& cardPoints, int k) {
        vector <int> vect (k, 0);
        int sum = 0;
        for (int i = 0; i < k; i++) {
            sum += cardPoints[i];
            vect[i] = sum;
        }
        int score = sum;
        
        if (k == cardPoints.size()) {
            return score;
        }
        
        sum = 0;
        int k1 = 1;
        for (int i = cardPoints.size() - 1; 
             i > cardPoints.size() - 1 - k; i--) {
            sum += cardPoints[i];
            
            if (i == cardPoints.size() - k) {
                score = max(score, sum);
            } else {
                int total = sum + vect[k-1-k1];
                score = max(total, score);
                k1++;    
            }
        }
        
        return score;
    }
};