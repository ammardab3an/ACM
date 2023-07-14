// Problem: Organizing Containers of Balls
// Contest: HackerRank - Algorithms - Implementation
// URL: https://www.hackerrank.com/challenges/organizing-containers-of-balls/problem
// Memory Limit: 512 MB
// Time Limit: 4000 ms
// 
// Powered by CP Editor (https://cpeditor.org)


// By AmmarDab3an 

#include <bits/stdc++.h>

using namespace std;

#define ll int64_t

string ltrim(const string &);
string rtrim(const string &);
vector<string> split(const string &);

/*
 * Complete the 'organizingContainers' function below.
 *
 * The function is expected to return a STRING.
 * The function accepts 2D_INTEGER_ARRAY container as parameter.
 */

string organizingContainers(vector<vector<int>> mat) {
    
    int n = mat.size();
    
    vector<ll> sm_row(n);
    vector<ll> sm_col(n);
    for(int i = 0; i < n; i++)
    for(int j = 0; j < n; j++){
    	sm_row[i] += mat[i][j];
        sm_col[j] += mat[i][j];
    }
    
    vector<vector<int>> adj(n);
    
    for(int i = 0; i < n; i++){
    	for(int j = 0; j < n; j++){
    		if(sm_row[i] >= sm_col[j]){
    			adj[i].push_back(j);
    		}
    	}
    }
    
    vector<bool> used(n);
    vector<int> mt(n, -1);
    
    auto dfs = [&](auto self, int u)->bool{
    	
    	if(used[u]){
    		return false;
    	}
    	
    	used[u] = true;
    	for(auto v : adj[u]){
    		if(mt[v]==-1 || self(self, mt[v])){
    			mt[v] = u;
    			return true;
    		}
    	}
    	
    	return false;
    };
    
    for(int i = 0; i < n; i++){
    	used.assign(n, 0);
    	dfs(dfs, i);
    }
    
    for(int i = 0; i < n; i++){
    	if(mt[i]==-1){
    		return "Impossible";
    	}	
    }
    
    return "Possible";
}

main()
{
    // ofstream fout(getenv("OUTPUT_PATH"));

    string q_temp;
    getline(cin, q_temp);

    int q = stoi(ltrim(rtrim(q_temp)));

    for (int q_itr = 0; q_itr < q; q_itr++) {
        string n_temp;
        getline(cin, n_temp);

        int n = stoi(ltrim(rtrim(n_temp)));

        vector<vector<int>> container(n);

        for (int i = 0; i < n; i++) {
            container[i].resize(n);

            string container_row_temp_temp;
            getline(cin, container_row_temp_temp);

            vector<string> container_row_temp = split(rtrim(container_row_temp_temp));

            for (int j = 0; j < n; j++) {
                int container_row_item = stoi(container_row_temp[j]);

                container[i][j] = container_row_item;
            }
        }

        string result = organizingContainers(container);

        cout << result << "\n";
    }

    // fout.close();

    return 0;
}

string ltrim(const string &str) {
    string s(str);

    s.erase(
        s.begin(),
        find_if(s.begin(), s.end(), not1(ptr_fun<int, int>(isspace)))
    );

    return s;
}

string rtrim(const string &str) {
    string s(str);

    s.erase(
        find_if(s.rbegin(), s.rend(), not1(ptr_fun<int, int>(isspace))).base(),
        s.end()
    );

    return s;
}

vector<string> split(const string &str) {
    vector<string> tokens;

    string::size_type start = 0;
    string::size_type end = 0;

    while ((end = str.find(" ", start)) != string::npos) {
        tokens.push_back(str.substr(start, end - start));

        start = end + 1;
    }

    tokens.push_back(str.substr(start));

    return tokens;
}

