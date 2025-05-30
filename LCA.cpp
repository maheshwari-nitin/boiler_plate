// credit to cp-algorithms

vector <vector <int>> adj;
int n, l;
int timer;
vector<int> tin, tout, depth;
vector<vector<int>> up;

void dfs(int v, int p){
    tin[v] = ++timer;
    up[v][0] = p;
    if(v != 1)depth[v] = depth[p] + 1;

    for(int i = 1; i <= l; i++){
        up[v][i] = up[up[v][i - 1]][i - 1];
    }

    for(int u : adj[v]){
        if(u != p){
            dfs(u, v);
        }
    }

    tout[v] = ++timer;
}

bool is_ancestor(int u, int v){
    return tin[u] <= tin[v] && tout[u] >= tout[v];
}

int lca(int u, int v){
    if(is_ancestor(u, v)) return u;
    if(is_ancestor(v, u)) return v;

    for(int i = l; i >= 0; i--){
        if(!is_ancestor(up[u][i], v)){
            u = up[u][i];
        }
    }

    return up[u][0];
}
