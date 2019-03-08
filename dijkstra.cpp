#include <bits/stdc++.h>
#include <iostream>
using namespace std;

#define fst first
#define snd second
#define pb(a) push_back(a)
#define mp(a, b) make_pair(a, b)
typedef long long ll;

const int N = 1e5 + 5;
int v, y, cost, best[N];
vector<pair<int, int>> graph[N];

void dijkstra(int x) {
	memset(best, -1, sizeof best);
	priority_queue<pair<int, int>> queue;
	best[x] = 0; // First node.
	queue.push({x, -best[x]}); // Now it's {x, 0}.
	
	while(queue.size()){ // While it's not empty.
		y = queue.top().fst; // The node we're now.
		cost = -queue.top().snd; // The cost to that node.
		queue.pop(); // We don't need that node anymore.

		if(cost > best[y]) continue;
		for(int i = 0; i < graph[x].size(); i++){ // For every neighbour of x...
			v = graph[x][i].fst; // Get the node.
			cost = graph[x][i].snd; // Get it's cost.

			// If it's unvisited, or we found a better path...
			if(best[v] < 0 or best[y] + cost < best[v]){
				best[v] = best[y] + cost; // Change the cost.
				queue.push(mp(v, -best[v])); // Push that node to the queue to visit it's neighbours.
			}
		}
	}
}