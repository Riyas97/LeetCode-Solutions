class Solution {
public:
    string reformatDate(string date) {
        vector <string> v (3, "");
        
        std::istringstream ss(date);
        std::string token;
        int count = 0;
        unordered_map <string, string> m;
        m["Jan"] = "01";
        m["Feb"] = "02";
        m["Mar"] = "03";
        m["Apr"] = "04";
        m["May"] = "05";
        m["Jun"] = "06";
        m["Jul"] = "07";
        m["Aug"] = "08";
        m["Sep"] = "09";
        m["Oct"] = "10";
        m["Nov"] = "11";
        m["Dec"] = "12";
        
        while(std::getline(ss, token, ' ')) {
            v[count] = token;
            count += 1;
        }
        string d = "";
        for (int i = 0; i < v[0].length(); i++) {
            if (v[0][i] - '0' >= 0 && v[0][i] - '0' <= 9) {
                d += v[0][i];
            } else {
                break;
            }
        }
        
        if (d.length() == 1) {
            d = "0" + d;
        }
        
        string mo = m[v[1]];
        
        return v[2] + "-" + mo + "-" + d;
    }
};