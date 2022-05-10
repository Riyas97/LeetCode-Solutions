class Solution {
public:
    bool is_vowel(char c) {
        switch(tolower(c)) {
            case 'a':
            case 'e':
            case 'i':
            case 'o':
            case 'u':
                return true;
            default:
                return false;
        }
    }
    
    string toGoatLatin(string sentence) {
        stringstream ss(sentence);
        string word;
        string endA = "a";
        string ans = "";
        while(ss >> word) {
            if (is_vowel(word[0])) {
                word += "ma" + endA;
            } else {
                char lett = word[0];
                word = word.substr(1, word.length()-1);
                word.push_back(lett);
                word += "ma" + endA; 
            }
            endA.push_back('a');
            if (endA == "aa") {
                ans = word;
            } else {
                ans += " " + word;
            }
            
        }
        return ans;
    }
};