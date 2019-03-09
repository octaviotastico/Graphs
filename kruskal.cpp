#include <bits/stdc++.h>
using namespace std;
#define fst first
#define snd second
#define pb(a) push_back(a)
#define mp(a, b) make_pair(a, b)
#define ll long long
const int N = 1000;
vector<pair<ll,pair<ll,ll>>> g; // Graph (cost, (x, y))
ll n, m, a, b, c, mst_weight, mst_vertex, mst_edges, father[N];

void set_fathers(){
	for(ll i = 0; i < N; i++){
		father[i] = i;
	}
}

ll father(ll x){
	if(father[x] == x) return x;
	else return father(father[x]);
}

void unite(ll a, ll b){
	ll father_a = father(a);
	ll father_b = father(b);
	father[father_a] = father_b;
}

void kruskal(){
	set_fathers();
	sort(g.begin(), g.end());

	while(mst_vertex < n - 1 or mst_edges < m){
		a = g[mst_edges].snd.fst;
		b = g[mst_edges].snd.snd;
		w = g[mst_edges].fst;
		if(father(a) != father(b)){
			unite(a, b);
			mst_weight += w;
			mst_vertex++;
		}
		mst_edges++;
	}
}


int main(){
	cin >> n >> m;
	for(ll i = 0; i < m; i++){
		cin >> a >> b >> c;
		g.pb(mp(c, mp(a,b)));
	}
	kruskal(0);
	return 0;
}
