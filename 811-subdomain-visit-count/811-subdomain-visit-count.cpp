class Solution {
public:
    vector<string> subdomainVisits(vector<string>& cpdomains) {
        unordered_map <string, int> cnt;
        for (int i = 0; i < cpdomains.size(); i++) {
            int brk = cpdomains[i].find(' ');
            string num = cpdomains[i].substr(
                0, brk);
            string domains = cpdomains[i].substr(
                brk + 1, cpdomains[i].length() - brk);
            
            //cout << num << " " << domains << "\n";
            
            cnt[domains] += stoi(num);
            int f = domains.find('.');
            
            while (f != -1) {
                domains = domains.substr(
                    f+1, domains.length() - f);
                cnt[domains] += stoi(num);
                f = domains.find('.');
                //cout << domains << " ";
            }      
        }
        
        vector<string> ans;
        
        for (auto it = cnt.begin(); it != cnt.end();
            it++) {
            string add = to_string(it->second);
            add += " " + it->first;
            ans.push_back(add);
        }
        
        return ans;
        
    }
};