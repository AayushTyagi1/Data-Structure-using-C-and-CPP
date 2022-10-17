class Solution {
public:
    bool checkIfPangram(string sentence) {
        vector<int> characterArray(26, 0);
        for(int i=0;i<sentence.length();i++)
        {
            characterArray[sentence[i]-'a']++;
        }
        for(int i=0;i<26;i++)
        {
            if(characterArray[i]==0)
                return false;
        }
        return true;
    }
};