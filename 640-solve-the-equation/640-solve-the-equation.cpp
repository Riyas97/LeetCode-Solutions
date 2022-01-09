class Solution {
public:
    string solveEquation(string equation) {
        
        bool left = true;
        string number = "";
        int leftx = 0;
        int leftnum = 0;
        int rightnum = 0;
        int sign = 1;
        
        for (int i = 0; i < equation.size(); i++) {
            //cout << leftx << " " << leftnum << " " << rightnum << "\n";
            if (left) {
                if (equation[i] == 'x') {
                    if (number != "") {
                        int xnum = stoi(number);
                        xnum *= sign;
                        number = "";
                        leftx += xnum;
                    } else {
                        int xnum = 1;
                        xnum *= sign;
                        leftx += xnum;
                    }
                } else if (equation[i] == '+') {
                    if (number != "") {
                        int xnum = stoi(number);
                        xnum *= sign;
                        number = "";
                        leftnum += xnum;
                    } 
                    
                    sign = 1;
                } else if (equation[i] == '-') {
                    if (number != "") {
                        int xnum = stoi(number);
                        xnum *= sign;
                        number = "";
                        leftnum += xnum;
                    } 
                    
                    sign = -1;
                } else if (equation[i] == '=') {
                    if (number != "") {
                        int xnum = stoi(number);
                        xnum *= sign;
                        number = "";
                        leftnum += xnum;
                    } 
                    sign = 1;
                    left = false;
                } else {
                    // number
                    number.push_back(equation[i]);
                }
            } else {
                if (equation[i] == 'x') {
                    if (number != "") {
                        int xnum = stoi(number);
                        xnum *= sign;
                        number = "";
                        leftx -= xnum;
                    } else {
                        int xnum = 1;
                        xnum *= sign;
                        leftx -= xnum;
                    }
                } else if (equation[i] == '+') {
                    if (number != "") {
                        int xnum = stoi(number);
                        xnum *= sign;
                        number = "";
                        rightnum += xnum;
                    } 
                    
                    sign = 1;
                } else if (equation[i] == '-') {
                    if (number != "") {
                        int xnum = stoi(number);
                        xnum *= sign;
                        number = "";
                        rightnum += xnum;
                    } 
                    
                    sign = -1;
                } else {
                    // number
                    number.push_back(equation[i]);
                }
            }
            
        }
        
        if (number != "") {
            int xnum = stoi(number);
            xnum *= sign;
            rightnum += xnum;
        } 
        
        if (leftx == 0 && rightnum - leftnum == 0) {
            return "Infinite solutions";
        } else if (leftx == 0) {
            return "No solution";
        } else if (rightnum - leftnum == 0) {
            return "x=0";
        } 
        int num = (rightnum - leftnum) / leftx;
        string ans = to_string(num);
        return "x=" + ans;
    }
};