// sqrt mo 

struct query{
    
    int lo, hi, idx;
    
    bool operator < (const query &other){
        
        if(lo/BLOCK != other.lo/BLOCK) return lo < other.lo;
        return lo/BLOCK % 2 ? hi > other.hi : hi < other.hi;
    }
    
} que[MMAX];


for(int i = 0; i < m; i++) {
	cin >> q[i].lo >> q[i].hi;
	q[i].lo--, q[i].hi--, q[i].idx = i;
}

sort(q, q+m);

int l = 1, r = 0;

for(int i = 0; i < m; i++){

	int cl = q[i].lo;
	int cr = q[i].hi;
	int ci = q[i].idx;

	while(r < cr) add(++r);
	while(cl < l) add(--l);
	while(cr < r) rem(r--);
	while(l < cl) rem(l++);

	ans[ci] = cans;
}
