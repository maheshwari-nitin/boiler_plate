#include <bits/stdc++.h>
using namespace std;

const int N = 200000;

vector <int> tree(2 * N);

int n;

void build(vector <int> & arr){
	for(int i = 0; i < n; i++){
		tree[n + i] = arr[i];
	}

	for (int i = n - 1; i > 0; --i){
		tree[i] = tree[i << 1] + tree[i << 1 | 1];
	}
}

void updateNode(int p, int value){
	tree[p + n] = value;
	p = p + n;

	for (int i = p; i > 1; i >>= 1)
        tree[i>>1] = tree[i] + tree[i^1];
}

int query(int l, int r) 
{ 
    int res = 0;
    
    // query logic 
    
    return res;
}


int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	
	return 0;
}
