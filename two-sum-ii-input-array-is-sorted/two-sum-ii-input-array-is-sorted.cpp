class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        int a = 0;
        int b = numbers.size() - 1;
        
        while (numbers[a] + numbers[b] != target) {
            int sum = numbers[a] + numbers[b];
            if (sum < target) {
                a += 1;
            } else {
                b -= 1;
            }
        }
        vector<int> ans;
        ans.push_back(a + 1);
        ans.push_back(b + 1);
        return ans;
            
    }
};