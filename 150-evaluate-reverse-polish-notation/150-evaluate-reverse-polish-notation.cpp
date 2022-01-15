class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        stack <int> nums;
        
        for (int i = 0; i < tokens.size(); i++) {
            if (tokens[i] == "+" || 
               tokens[i] == "-" || tokens[i] == "*" ||
               tokens[i] == "/") {
                // operation
                int b = nums.top();
                nums.pop();
                int c = nums.top();
                nums.pop();
                if (tokens[i] == "+") {
                    nums.push(b+c);
                } else if (tokens[i] == "-") {
                    nums.push(c-b);
                } else if (tokens[i] == "*") {
                    nums.push(b*c);
                } else {
                    nums.push(c/b);
                }
            } else {
                int a = stoi(tokens[i]);
                nums.push(a);
            }
            
        }
        return nums.top();
    }
};