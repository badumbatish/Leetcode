class Solution {
public:
    bool isCircularSentence(string sentence) {
        bool circular = true;

        for (int i = 1; i < sentence.size() - 1; i++) {
            if (sentence[i] == ' ') {
                if ( sentence[i-1] != sentence[i+1]) return false;
            }
        }    

        return sentence.front() == sentence.back();
    }
};