// z-fun

vector<int> z_function(string s) {
    int n = (int) s.length();
    vector<int> z(n);
    for (int i = 1, l = 0, r = 0; i < n; ++i) {
        if (i <= r)
            z[i] = min (r - i + 1, z[i - l]);
        while (i + z[i] < n && s[z[i]] == s[i + z[i]])
            ++z[i];
        if (i + z[i] - 1 > r)
            l = i, r = i + z[i] - 1;
    }
    return z;
}


// kmp
string pat, str;
int mem[NMAX][26];
int pat_pre[NMAX];

int nxtL(int i, char c){
	
	int &ret = mem[i][c-'a'];
	if(ret+1) return ret;
	
	while(i && pat[i] != c) i = pat_pre[i-1];
	if(pat[i] == c) i++;
	
	return ret = i;
}

void computePrefix(){
	pat_pre[0] = 0;
	for(int i = 1; i < pat.size(); i++){
		pat_pre[i] = nxtL(pat_pre[i-1], pat[i]);
	}
}


// don't forget
computePrefix()
int j = 0;
for(int i = 0; i < str.size(); i++){
	j = nxtL(j, str[i]);
	if(j==pat.size()) ans.push_back(i-pat.size()+2);
}
		