class Solution {
public:
    int numUniqueEmails(vector<string>& emails) {
        // for strings
        unordered_set <string> set;
        
        for (int i = 0; i < emails.size(); i += 1) {
            string email = emails[i];
            
            vector <string> vect;
            
            std::istringstream ss(email);
            std::string token;

            while(std::getline(ss, token, '@')) {
                vect.push_back(token);
            }
            
            string loc = vect[0];
            string dom = vect[1];
            
            loc.erase(std::remove(loc.begin(), loc.end(), '.'), loc.end());
            if (loc.find('+') != string::npos) {
             loc.erase(loc.find('+'));   
            }
            
           
            
            string corrEmail = loc + '@' + dom;
            set.insert(corrEmail);
            
        }
        return set.size();
    }
};