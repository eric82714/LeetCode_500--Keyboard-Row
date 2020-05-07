class Solution {
public:
    vector<string> findWords(vector<string>& words) {
        map<char, int> keyboard = {{'q',1}, {'w',1}, {'e',1}, {'r',1}, {'t',1}, {'y',1}, {'u',1}, {'i',1}, {'o',1}, {'p',1}, {'a',2}, {'s',2}, {'d',2}, {'f',2}, {'g',2}, {'h',2}, {'j',2}, {'k',2}, {'l',2}, {'z',3}, {'x',3}, {'c',3}, {'v',3}, {'b',3}, {'n',3}, {'m',3}};
        
        vector<string> result;
        
        for(auto &word : words) {
            string l_word = word;
            int loc = keyboard[tolower(l_word[0])];
            bool same = true;
            for(auto &c : l_word) {
                if(keyboard[tolower(c)] != loc) {
                    same = false;
                    break;
                }
            }
            if(same) result.push_back(word);
        }
        
        return result;
    }
};
