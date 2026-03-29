# 🚀 Way To Google | 2026

<br/>

## 📊 Progress Overview
* **Total Problems:** 0/500
* **Easy:** 🟢 0 | **Medium:** 🟡 0 | **Hard:** 🔴 0
* **Active Revision:** [Review items marked for today's date]

## 💡 Topics Covered
- [ ] Arrays & Hashing
- [ ] Linked Lists
- [ ] Trees & Graphs
- [ ] Dynamic Programming
- [ ] Sorting & Searching

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

