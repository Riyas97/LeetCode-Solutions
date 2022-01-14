class Solution {
public:
    string interpret(string command) {
        string ans = "";
        for (int i = 0; i < command.length(); i++) {
            if (command[i] == 'G') {
                ans += command[i];
            } else if (command[i] == 'l') {
                ans += "al";
                i++;
            } else if (command[i] == ')') {
                ans += "o";
            }
        }
        return ans;
    }
};