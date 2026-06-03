/*
    The idea in this question is to construct graph out of raw dataset.
    Time: O(C), where C is total number of characters in all words
    Space: O(1), space is constant because it is bound with 26 characters
*/



#include<iostream>
#include<unordered_set>
#include<unordered_map>
using namespace std;

string findOrder(string dict[], int N, int K) {
    // Initialize inDegree array
    unordered_map<char, int> inDegree;
    for(int i = 0; i < N; i++) {
        for(char ch : dict[i]) {
            if (!inDegree.count(ch)) {
                inDegree[ch] = 0;
            }
        }
    }
    
    // Construct Graph
    unordered_map<char, unordered_set<char>> graph;

    for(int i = 0; i < N - 1; i++) {
        string word1 = dict[i];
        string word2 = dict[i + 1];        
        int ptr = 0;

        while(ptr < min(word1.size(), word2.size()) && word1[ptr] == word2[ptr]) ptr++;

        // if word1 = "abcd" and word2 = "abc" -> invalid case(cannot exist in dictonary)
        if(ptr == word2.size() && word1.size() > word2.size()) return "";

        if(ptr < word1.size() && ptr < word2.size()) {
            char u = word1[ptr];
            char v = word2[ptr];
            if(graph[u].find(v) == graph[u].end()) {
                graph[u].insert(v);
                inDegree[v]++;
            }
        }
    }
    
    // Get Order using Topo-Sort
    string order;
    queue<char> q;
    for(auto it : inDegree) {
        if(it.second == 0) {
            q.push(it.first);
        }
    }


    while(!q.empty()) {
        char ch = q.front();
        q.pop();

        order.push_back(ch);
        for(char nbr : graph[ch]) {
            inDegree[nbr]--;
            if(inDegree[nbr] == 0) {
                q.push(nbr);
            }
        }
    }

    if(order.size() == inDegree.size()) return order;
    return "";
}

int main() {
    // string dict[] = {"baa", "abcd", "abca", "cab", "cad"};
    string dict[] = {"caa","aaa","aab"};
    string order = findOrder(dict, 3, 3);    
    cout << order << endl;

    return 0;
}
