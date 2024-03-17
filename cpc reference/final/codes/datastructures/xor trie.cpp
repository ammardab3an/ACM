
// xor trie 

struct node{
	
	node *nxt[2];
	
	node(){
		nxt[0] = nxt[1] = nullptr;
	}
	
	~node(){
		delete nxt[0];
		delete nxt[1];
		nxt[0] = nxt[1] = nullptr;
	}
};

struct TrieXOR{
		
	node root;
	
	void insert(int val){
		
		node *cur = &root;
		
		for(int i = 30; i >= 0; i--){
			
			bool b = (val>>i)&1;
			
			if(!cur->nxt[b]){
				cur->nxt[b] = new node();
			}
			
			cur = cur->nxt[b];
		}
	}
	
	int query(int val){
		
		int ret = 0;
		node *cur = &root;
		
		for(int i = 30; i >= 0; i--){
			
			bool b = (val>>i)&1;
			
			if(cur->nxt[!b]){
				ret ^= (1 << i);
				cur = cur->nxt[!b];
			}
			else{
				cur = cur->nxt[b];
			}
		}
		
		return ret;
	}

};

