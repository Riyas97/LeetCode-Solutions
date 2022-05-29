class Solution {
public:
    string discountPrices(string sentence, int discount) {
        string ans = "";
        stringstream ss(sentence);
        string substr;
        while(ss >> substr) {
            string word = substr;
            if (substr[0] == '$' && substr.length() > 1) {
                bool isValid = true;
                for (int i = 1; i < substr.length(); i++) {
                    if (substr[i] == '$' || substr[i] - '0' < 0 || substr[i] - '0' > 9) {
                        isValid = false;
                        break;
                    }
                }
                if (isValid) {
                    string num = substr.substr(1, substr.length()-1);
                    long long money = stoll(num);
                    double discounted = ((100 - discount) / 100.00) * (money);
                    long long discounted1 = (long long)(discounted * 100 + 0.5);
                    double discounted2 = (double) (discounted1)/(double)100;
                    discounted2 += 0.005;
                    //cout << "here is " << discounted << " " << discounted1  << " " << discounted2 << "\n";
                    
                    string discountedstr = to_string(discounted2);
                    int index = discountedstr.find('.');
                    word = '$' + discountedstr.substr(0, index+2+1);
                } 
            }
            ans += word + " ";
            //cout << substr << "\n";
        }
        return ans.substr(0, ans.length()-1);
    }
};