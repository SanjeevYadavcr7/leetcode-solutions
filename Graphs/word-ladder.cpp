class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        unordered_set<string> visited(wordList.begin(), wordList.end());

        if(visited.find(endWord) == visited.end()) return 0;

        queue<string> words;
        words.push(beginWord); // Push begin word as first node

        int transformations = 1; // Count includes the starting word

        while(!words.empty()) {
            int levelSize = words.size();

            while(levelSize--) {
                string word = words.front();
                words.pop();

                if(word == endWord) return transformations;

                for(int i = 0; i < word.size(); i++) {
                    char originalChar = word[i];
                    for(char ch = 'a'; ch <= 'z'; ch++) {
                        word[i] = ch;
                        if(visited.find(word) != visited.end()) {
                            words.push(word);
                            visited.erase(word);
                        }
                    }
                    word[i] = originalChar;
                }
            }
            transformations++;
        }
        return 0; // No sequence found
    }
};
