#include <bits/stdc++.h>

using namespace std;

unordered_set<string> visited;

set<string> get_mails(string& start_mail, unordered_map<string, vector<string>>& adj) {
    stack<string> mystack;
    mystack.push(start_mail);
    set<string> result;
    visited.insert(start_mail);

    while (!mystack.empty()) {
        string node = mystack.top();
        mystack.pop();
        result.insert(node);

        for (string s : adj[node]) {
            if (visited.count(s) == 0) {
                mystack.push(s);
                visited.insert(s);
            }
        }
    }
    return result;
}

vector<vector<string>> accountsMerge(vector<vector<string>>& accounts) {
    unordered_map<string, vector<string>> adj;
    for (int i = 0; i < accounts.size(); i++) {
        // Hesapta sadece isim varsa atla
        if (accounts[i].size() <= 1) continue; 
        
        string first_mail = accounts[i][1];
        for (int j = 2; j < accounts[i].size(); j++) {
            adj[first_mail].push_back(accounts[i][j]);
            adj[accounts[i][j]].push_back(first_mail);
        }
    }

    vector<vector<string>> overall;    

    for (int i = 0; i < accounts.size(); i++) {
        if (accounts[i].size() <= 1) continue;
        
        string first_mail = accounts[i][1];
        
        if (visited.count(first_mail) == 0) {
            vector<string> inner;
            inner.push_back(accounts[i][0]); 

            set<string> result = get_mails(first_mail, adj);
            for (string s : result) inner.push_back(s);
            
            overall.push_back(inner);
        }
    }

    return overall;
}