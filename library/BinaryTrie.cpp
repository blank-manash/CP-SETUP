struct Trie {
	struct node {
		node* kids[2];
		int cnt;
		node() {
			this->kids[0] = this->kids[1] = NULL;
			this->cnt = 0;
		}
	};
	node *head;
	Trie() {
		this->head = new node();
		this->insert(0);
	}
	void insert(int x ) {
		node *curr = head;
		for( int bit = 30; bit >= 0; bit--) {
			int b = ( x >> bit) & 1;
			if(curr->kids[b] == NULL) curr->kids[b] = new node();
			curr = curr->kids[b];
			curr->cnt++;
		}
	}
	void remove( int x ) {
		node *curr = head;
		for( int bit = 30; bit >= 0; bit--) {
			int b = ( x >> bit ) & 1;
			curr = curr->kids[b];
			curr->cnt--;
		}
	}
	int minxor( int x ) {
		int ans = 0;
		node *curr = head;
		for( int bit = 30; bit >= 0; bit--) {
			int b = ( x >> bit ) & 1;
			if(curr->kids[b] && curr->kids[b]->cnt > 0 ) {
				curr = curr->kids[b];
			} else ans |= ( 1 << bit ), curr = curr->kids[!b];
		}
		return ans;
	}
	int maxxor( int x ) {
		int ans = 0;
		node *curr = head;
		for( int bit = 30; bit >= 0; bit-- ) {
			int b = (x >> bit ) & 1;
			if(curr->kids[!b] != NULL and curr->kids[!b]->cnt > 0 ) {
				ans |= ( 1 << bit );
				curr = curr->kids[!b];
			} else curr = curr->kids[b];
		}
		return ans;
	}
};
