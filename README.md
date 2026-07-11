# 🚀 Leetcode Solutions | 2026

<br/>

## 💡 Topics Covered
- [x] Arrays & Hashing
- [x] Sorting & Searching
- [x] Two-Pointers
- [x] Binary Search
- [x] Backtracking
- [x] Linked Lists
- [x] Heap(Priority Queue)
- [x] Trees
- [x] Graphs
- [ ] Dynamic Programming

## ⚡ Problems Tracker
- 📋 [Revision Sheet](https://www.notion.so/33169a7a738c80e287e9d8b18231413d?v=33169a7a738c80c8b7eb000c355ae625)


## 📚 Resources
- [NeetCode 150](https://neetcode.io/)
- [Striver's SDE Sheet](https://takeuforward.org/dsa/strivers-sde-sheet-top-coding-interview-problems)
- [GFG - Must Do Coding Interview Questions](https://www.geeksforgeeks.org/dsa/must-do-coding-questions-for-companies-like-amazon-microsoft-adobe/)

<br/>

## 😃 Aha Moments
- **Top K Frequent Elements:** Bucket Sort is a non-comparison sort that achieves `O(N)` time by using array indices as buckets. It is optimal when the range of sorting values (like frequency or age) is small relative to the number of elements. If the range is significantly larger than N, space complexity makes it inefficient.

- If you are just reading the data to push it into another vector (like you did in groupAnagrams), you should actually use `const auto&`.
  ```
    for(const auto& pair : str_mp) { 
        grp_angrms.push_back(pair.second); 
    }
    
    Why const? It tells the compiler (and other engineers), "I'm going to look at this data, but I promise I won't change it." This allows the
    compiler to perform even more optimizations.
  ```
  <br/>
- Whenever you see "Longest Reapeating...", "Longest Subsequnce....", etc. then high probability is that the problem is a sliding window type problem. 
  ```
    Sliding Window solution follows this pattern :
    1. Moving right pointer to increase window size
    2. Increase right until window is valid
    3. If window is invalid, sequeeze the window by placing left pointer at a position which makes the window valid.
  ```
  <br/>
- To never forget the Monotonic Stack, imagine a line of people of different heights.
  ```
    You are walking down the line.
    If you see someone shorter than the person before them, they are "blocked" from seeing anything further.
    The moment you see someone taller, they "break" the line of sight for everyone shorter than them who came before. 
  ```
  <br/>
- The "Pick / Don't Pick" Pattern:
  ```
  The Visualization:
  Treat the problem as a strict binary decision tree.
  At every index, you have two choices: include the current number in your subset, or exclude it.
  
  The Maze Analogy:
  Backtracking is like walking through a maze.
  When you reach the end of a path (the base case idx == nums.size()), you don't start entirely over.
  You take a step backward (subset.pop_back()) to "undo" your last decision, and then walk down the alternative path.
  ```
  <br/>
  
- Word Ladder(Graph Problem)
  ```
  Optimization via State Generation vs. Selection:
  If your dictionary has 50,000 words (N) and each word is 5 characters long (L), comparing your word to 
  all other words takes 50,000 \times 5 = 250,000 operations. 
  However, generating all possible single-letter edits takes only 5 \times 26 = 130 operations. 
  Checking if those 130 words exist in an unordered_set takes O(1) time each. Always generate 
  possibilities if the search alphabet is constrained (like 26 letters).

  The Optimization:
  Never pass the subset array by value!
  Passing by reference (vector<int>& subset) ensures you are using a single, shared 
  path to explore all 2N combinations. Rather than creating expensive memory clones at every intersection.
  ```
  <br/>

- Dijkstra Algorithm(When to use vs when not to use)
  ```
  When finding the shortest path/time in a weighted graph with no restrictions on steps or edges,
  immediately reach for a priority_queue instead of a regular queue.
  This ensures you explore optimal paths first and avoids re-processing overhead.
  ```

  


