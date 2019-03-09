#include <bits/stdc++.h>

#define fore(i, s, e) for(int i = s; i < e; i++)
#define pb push_back
using namespace std;

const int N = 2e5;

int g[N][N];
bool visited[N][N];
queue<int> nextX;
queue<int> nextY;
int movementsA[] = {1, 0, -1, 0};
int movementsB[] = {0, 1, 0, -1};


void bfs(int x = 0, int y = 0) {

  int actualx, actualy;
  while(!nextX.empty()){

    actualx = nextX.front();
    actualy = nextY.front();
    nextX.pop_front();
    nextY.pop_front();

    for(int i = 0; i < 4; i++){
      x = actualx + movementsA[i];
      y = actualy + movementsB[i];
      if (!visited[x][y] && !g[x][y]){
          nextX.push(x);
          nextY.push(y);
          visited[x][y] = true;
      }
    }
  }
}

int main() {
  int a, b, n, m;
  cin >> n >> m;
  fore(i, 0, n)
    fore(j, 0, m)
      cin >> g[i][j];
  cout << "Where do you start?" << endl;
  cin >> a >> b;
  if(g[a][b]){
    cout << "Where do you go?" << endl;
    cin >> n >> m;
    if(g[n][m]){
      visited[a][b] = true;
      nextX.push(a); nextY.push(b);
      bfs(a, b);
      if(visited[n][m]) cout << "It's possible." << endl;
      else cout << "It's not possible." << endl;
    }
  } else {
    cout << "You can't start if you're in a blocked cell."
  }
  return 0;
}
