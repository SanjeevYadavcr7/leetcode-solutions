/*
    Time Complexity  : O(E.LogE) -->  O(E.α(N))) for DSU(connecting nodes) + O(E.LogE) for sorting emails
    Space Complexity : O(N + E)  -->  O(N) for building DSU + O(E) for building map
    where,
    N = no. of accounts
    K = Maximum email in one account
    E = Total number of emails ~(N.K)
*/

class DisjointSet {
private:
    vector<int> rank, parent;
public:
    DisjointSet(int N) {
        rank.resize(N, 0);
        parent.resize(N);

        for(int i = 0; i < N; i++) parent[i] = i;
    }

    int getUltimateParent(int node) {
        if(parent[node] == node) return node;
        return parent[node] = getUltimateParent(parent[node]);
    }

    void connectNodes(int u, int v) {
        int rootU = getUltimateParent(u);
        int rootV = getUltimateParent(v);

        if(rootU != rootV) {
            if(rank[rootU] < rank[rootV]) {
                parent[rootU] = rootV;
            } else if(rank[rootU] > rank[rootV]) {
                parent[rootV] = rootU;
            } else {
                rank[rootV]++;
                parent[rootU] = rootV;
            }
        }
    }
};

class Solution {
public:
    vector<vector<string>> accountsMerge(vector<vector<string>>& accounts) {
        int n = accounts.size();
        unordered_map<string, int> emailToAcc;

        DisjointSet dsu(n);

        // Step 1: Traverse accounts and build the DSU connections
        for(int i = 0; i < n; i++) {
            for(int j = 1; j < accounts[i].size(); j++) {
                string email = accounts[i][j];

                if(emailToAcc.find(email) != emailToAcc.end()) {
                    dsu.connectNodes(i, emailToAcc[email]);
                } else {
                    emailToAcc[email] = i;
                }
            }
        }


        // Step 2: Store accountID -->  [all emails]
        unordered_map<int, vector<string>> accountIdToEmails;
        for(auto [email, accID] : emailToAcc) {
            int root = dsu.getUltimateParent(accID);
            accountIdToEmails[root].push_back(email);
        }


        // Step 3: Return result by storing emails with username
        vector<vector<string>> result;
        for(auto [accID, emails] : accountIdToEmails) {
            sort(emails.begin(), emails.end());

            vector<string> accountRow = {accounts[accID][0]};
            accountRow.insert(accountRow.end(), emails.begin(), emails.end());

            result.push_back(accountRow);
        }

        return result;
    }
};
