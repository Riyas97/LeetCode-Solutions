class Solution {
public:
    string simplifyPath(string path) {
        string ans = "";
        stack<string> subpaths;
        stringstream ss(path);
        string sub;
        while(ss.good()) {
            string substr;
            getline(ss, substr, '/');
            cout << substr << " ";
            if (substr == "..") {
                if (!subpaths.empty()) {
                    subpaths.pop();
                }
            } else if (substr == "") {
                // ignore
            } else if (substr == ".") {
                // ignore
            }
            else {
                subpaths.push(substr);
            }
        }
        
        while (!subpaths.empty()) {
            string substr = subpaths.top();
            subpaths.pop();
            ans = substr + "/" + ans;
        }
        
        ans = "/" + ans;
        if (ans.length() > 1) {
            ans.pop_back(); // pop back last slash
        }
        
        return ans;
    }
};