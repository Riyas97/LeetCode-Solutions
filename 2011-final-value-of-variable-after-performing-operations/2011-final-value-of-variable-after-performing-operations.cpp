class Solution {
public:
    int finalValueAfterOperations(vector<string>& operations) {
        int inc = 0;
        int dec = 0;
        for (int i = 0; i < operations.size(); i++) {
            if (operations[i] == "++X" || 
               operations[i] == "X++") {
                inc++;
            } else {
                dec--;
            }
        }
        return inc + dec;
    }
};