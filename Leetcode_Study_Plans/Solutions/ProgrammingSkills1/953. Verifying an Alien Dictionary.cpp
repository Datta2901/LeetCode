class Solution {
public:
    bool isAlienSorted(vector<string>& words, string order) {
        int fre[26];
        for(int i = 0; i < order.size(); i++){
            fre[order[i] - 'a'] = i;
        }

        for(int i = 0; i < words.size(); i++){
            for(int j = 0; j < words[i].size(); j++){
                words[i][j] = fre[words[i][j] - 'a'];
            }
        }
        return is_sorted(words.begin(),words.end());
    }
}; 