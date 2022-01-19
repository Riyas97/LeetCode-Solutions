class Solution {
public:
    int uniqueMorseRepresentations(vector<string>& words) {
        vector<string> vect {".-","-...","-.-.","-..",".","..-.","--.","....","..",".---","-.-",".-..","--","-.","---",".--.","--.-",".-.","...","-","..-","...-",".--","-..-","-.--","--.."};
        
        unordered_set <string> us;
        
        for (int i = 0; i < words.size(); i++) {
            string str = "";
            for (int j = 0; j < words[i].length(); j++) {
                str += vect[words[i][j] - 'a'];                
            }
            us.insert(str);
        }
        
        return us.size();
    }
};