/*
Time Complexity: 
In the worst-case scenario, the runtime is bounded by the number of valid paths generated, 
up to O(26.M.N + K.M), 
where, 
M = word length
N = total count of words
K = total number of shortest path variations found.

Space Complexity: O(N.M) to maintain the distance graph profile mappings alongside the internal tracking configurations.

*/

class Solution {
using stringIntMap = unordered_map<string, int>;
using stringArray = vector<vector<string>>;
private:
    stringArray sequence;
    stringIntMap wordLevelMap;
    bool foundEnd = false;

    stringIntMap getWordLevelMap(string beg, string end, vector<string>& wordList) {
        stringIntMap resMap;
        queue<string> words;
        unordered_set<string> dict(wordList.begin(), wordList.end());

        if(dict.find(end) == dict.end()) return resMap;

        words.push(beg);
        dict.erase(beg);
        int level = 0;

        while(!words.empty()) {
            int size = words.size();

            while(size--) {
                string word = words.front();
                words.pop();
                
                resMap[word] = level;

                if (word == end) {
                    foundEnd = true;
                    break;
                }

                for(int i = 0; i < word.size(); i++) {
                    char originalChar = word[i];
                    for(char ch = 'a'; ch <= 'z'; ch++) {
                        word[i] = ch;
                        if(dict.find(word) != dict.end()) {
                            words.push(word);
                            dict.erase(word);
                        }
                    }
                    word[i] = originalChar;
                }
            }
            level++;
        }
        return resMap;
    }

    void dfs(string& beg, string& curr, vector<string>& seq) {
        if(curr == beg) {
            vector<string> reversePath = seq;
            reverse(reversePath.begin(), reversePath.end());
            sequence.push_back(reversePath);
            return;
        }
        
        for(int i = 0; i < curr.size(); i++) {
            int parentLevel = wordLevelMap[curr];
            char originalWord = curr[i];
            for(char ch = 'a'; ch <= 'z'; ch++) {
                curr[i] = ch;
                if(wordLevelMap.find(curr) != wordLevelMap.end() && wordLevelMap[curr] == parentLevel - 1) {
                    seq.push_back(curr);
                    dfs(beg, curr, seq);
                    seq.pop_back();
                }
            }
            curr[i] = originalWord;
        }
    }

    stringArray getLadders(string beg, string end, vector<string>& wordList) {
        vector<string> subSeq = {end};

        dfs(beg, end, subSeq);

        return sequence;
    }

public:
    vector<vector<string>> findLadders(string beginWord, string endWord, vector<string>& wordList) {
        wordLevelMap = getWordLevelMap(beginWord, endWord, wordList);
        
        // If endWord is not present in WordList, we cannot have a vaild answer
        if(!foundEnd) {
            return {};
        }

        vector<vector<string>> ladders = getLadders(beginWord, endWord, wordList);

        return ladders;
    }
};
