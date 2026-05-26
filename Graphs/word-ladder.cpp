class Solution {
public:
    /*
    Time Complexity: $O(M^2 * N), where M is the length of each word and N is the total number of words in the input list. 
                     For each word popped from the queue, we iterate $M$ times, and inside that loop, we create a new string 
                     copy which takes O(M) time to modify/hash.
                     
    Space Complexity: O(M.N) to hold the string states inside our hash set data structure and the underlying BFS memory footprint queue.
    */

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
