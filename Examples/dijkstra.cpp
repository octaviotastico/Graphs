
/*

This is an example of using the dijkstra algorithm to solve this problem:

http://matcomgrader.com/problem/9549/highway-decommission/

*/

#include <bits/stdc++.h>
using namespace std;
#define fst first
#define snd second
#define pb(a) push_back(a)
#define mp(a, b) make_pair(a, b)
#define ll long long
const int N = 1e4;
vector <pair<pair<ll,ll>, ll>> g[N];
ll n, m, cityA, cityB, length, y, cost, ret, maintenance, best[N], bestM[N];

void dijkstra(ll x) {
	memset(best, -1, sizeof best);
    memset(bestM, -1, sizeof bestM);
	priority_queue<pair<pair<ll,ll>, ll>> queue;
	best[x] = 0; bestM[x] = 0;
	queue.push(mp(mp(best[x], x), bestM[x]));
	while(queue.size()){
		cost = -queue.top().fst.fst;
    	y = queue.top().fst.snd;
        maintenance = -queue.top().snd;
		queue.pop();
        if(cost > best[y]) continue;
		for(ll i = 0; i < g[y].size(); i++){
			x = g[y][i].fst.fst;
			cost = g[y][i].fst.snd;
            maintenance = g[y][i].snd;
			if(best[x] < 0 or best[y] + cost < best[x]){
				best[x] = best[y] + cost; bestM[x] = maintenance;
                queue.push(mp(mp(-best[x], x), -maintenance));
			} else if((best[y] + cost == best[x]) && (bestM[x] > maintenance)){
				best[x] = best[y] + cost; bestM[x] = maintenance;
                queue.push(mp(mp(-best[x], x), -maintenance));
            }
		}
	}
}

int main(){
    cin >> n >> m;
    for(ll i = 0; i < m; i++){
        cin >> cityA >> cityB >> length >> maintenance;
        cityA--; cityB--;
        g[cityA].pb(mp(mp(cityB, length), maintenance));
        g[cityB].pb(mp(mp(cityA, length), maintenance));
    }
	dijkstra(0);
	for(ll i = 0; i < n; i++)
		ret+=bestM[i];
    cout << ret;
    return 0;
}
