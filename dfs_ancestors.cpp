#include <bits/stdc++.h>

using namespace std;

#define fore(i, s, e) for(int i = s; i < e; i++)
#define pb push_back

const int N = 2e5;
const int K = 30;
vector<int> g[N];
int depth[N], sz[N];
int F[N][K];
int tin[N], tout[N], timer = 0;

// F[Vertice][2^Ancestro]
// F[i][j] means the (2**j)-th ancestor of vertex i
// Actual node, father node, depth.
void dfs(int x, int y = 0, int l = 0) {
    F[x][0] = y;
    tin[x] = timer++;
    fore(i, 1, K) F[x][i] = F[F[x][i - 1]][i - 1];
    depth[x] = l, sz[x] = 1;
    for(int v : g[x]) if(v != y) {
        dfs(v, x, l + 1);
        sz[x] += sz[v];
    }
    tout[x] = timer++;
}

int hob(int num){
    if(!num) return 0;
    int ret = 1;
    while(num >>= 1) ret <<= 1;
    return log2(ret);
}

//Encontrar el ancestro k-esimo de un vertice.
int main() {
    int a, b, n, help, ret;
    cin >> n;
    fore(i, 0, n) {
        cin >> a >> b; a--, b--;
        g[a].pb(b);
        g[b].pb(a);
    }
    dfs(0);
    cin >> a; cin >> b; ret = a;
    while(b != 0){
      help = hob(b);
      b -= pow(2, help);
      ret = F[ret][help];
    }
    cout << ret;
    return 0;
}
