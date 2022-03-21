class Solution {
public:
    int numOfSubarrays(vector<int>& arr) {
        int numEven = 0;
        int numOdd = 0;
        int sum = 0;
        int ans = 0;
        for (int i = 0; i < arr.size(); i++) {
            //if (arr[i] % 2 != 0) {
            //    ans++;
            //}
            sum += arr[i];
            if (sum % 2 != 0) {
                if (numEven + 1 >= 1000000007 - ans) {
                    ans = numEven + 1 - 1000000007 + ans;
                } else {
                    ans += numEven + 1;
                }
                numOdd++;
            } else {
                if (numOdd >= 1000000007 - ans) {
                    ans = numOdd - 1000000007 + ans;
                } else {
                    ans += numOdd;
                }
                numEven++;
            }
        }
        return ans;
    }
};