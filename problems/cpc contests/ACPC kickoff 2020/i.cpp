
#include <bits/stdc++.h>

using namespace std;

bool CAN(int i, int j, string &a, string &s, int k){

	if((i == (int)a.size()) || (j == (int)s.size())){
		
		if(k >= abs((int)a.size()-i+1 -((int)s.size()-j+1)))
			return true;
		else 
			return false;
	}
		
	
	if(a[i] == s[j]) 
		if(CAN(i+1, j+1, a, s, k)) return true;
		
	if(k > 0) if(CAN(i+1, j+1, a, s, k-1)) return true;
	if(k > 0) if(CAN(i+1, j, a, s, k-1)) return true;
	
	return false;
}


bool COMP(pair<string, int> &p1, pair<string, int> &p2){
	return p1.first.size() <= p2.first.size();
}


int main(){
    
	freopen("corrector.in", "r", stdin);
	
	int t; cin >> t; while(t--){
    	
    	int n; cin >> n;
    	
    	vector< pair<string, int> > vec(n);
    	
    	for(int i = 0; i < n; i++){
    		cin >> vec[i].first;
    		vec[i].second = i;
    	}
		
		sort(vec.begin(), vec.end(), COMP);
		
    	vector<int> lens(n);
    	for(int i = 0; i < n; i++) 
    		lens[i] = vec[i].first.size();

    	int q; cin >> q; while(q--){
	
	   		string s; int k;
    		cin >> s >> k;
    		
    		vector<int> ans;
				
			int l = 0; 
			int r = n-1;
			int res = n-1;
			int szS = s.size();
			while(l <= r){
				int mid = (l+r)/2;
				if(lens[mid] >= szS){
					res = mid;
					r = mid-1;
				}
				else{
					l = mid+1;
				}
			}
			
			for(int i = res; i < n; i++){
				if(CAN(0, 0, vec[i].first, s, k)) 
					ans.push_back(vec[i].second);
			}
			
			if(ans.size()) sort(ans.begin(), ans.end());
	
			if(ans.size()){
				for(int i = 0; i < (int)ans.size(); i++)
					cout << ans[i] << ' ';
				cout << endl;
			}
			else{
				cout << -1 << endl;
			}
    	}
    }	
}
