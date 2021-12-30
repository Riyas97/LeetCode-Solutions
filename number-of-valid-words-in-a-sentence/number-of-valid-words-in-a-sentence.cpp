class Solution {
public:
    int countValidWords(string sentence) {
        int num = 0;
        bool hasHyp = false;
        bool hasPunc = false;
        bool isWord = true;
        bool start = true;
        
        for (int i = 0; i < sentence.length(); i++) {
            if (sentence[i] == '-') {
                if (hasHyp) {
                    isWord = false;
                } else if (start) {
                    isWord = false;
                    hasHyp = true;
                } else if (i == sentence.length() - 1 || 
                   sentence[i+1] - 'a' < 0 || 
                   sentence[i+1] - 'a' > 25) {
                    isWord = false;
                    hasHyp = true;
                } else {
                    hasHyp = true;
                }
            } else if (sentence[i] - 'a' >= 0 &&
                   sentence[i+1] - 'a' <= 25) {
                if (start) {
                    start = false;
                }
            } else if (sentence[i] - '0' >= 0 && 
                      sentence[i] - '0' <= 9) {
                isWord = false;
            } else if (isspace(sentence[i])) {
                if (!start && isWord) {
                    cout << i << " ";
                    num++;
                }
                hasHyp = false;
                hasPunc = false;
                start = true;
                isWord = true;
            } else {
                //punctuation
                if (hasPunc) {
                    isWord = false;
                } else if (start && 
                           (i != sentence.length() - 1 && 
                           !isspace(sentence[i+1]))) {
                    isWord = false;
                    hasPunc = true;
                } else if (start) {
                    start = false;
                
                } else if (i != sentence.length() - 1 && 
                   sentence[i+1] - 'a' >= 0 && 
                   sentence[i+1] - 'a' <= 25) {
                    isWord = false;
                    hasPunc = true;
                } else if (i != sentence.length() - 1 && 
                   sentence[i+1] == '-') {
                    isWord = false;
                    hasPunc = true;
                } else {
                    hasPunc = true;
                }
            }
            
            if (!isspace(sentence[i]) && i == 
                sentence.length() - 1 && isWord && !start) {
                
                num++;
            } 
            
        }
        return num;
    }
};