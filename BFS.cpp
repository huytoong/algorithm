#include <bits/stdc++.h>
using namespace std;

int n, m;              // dinh, canh
vector<int> adj[1005]; // danh sach canh ke
bool visited[1005];
bool found = false;

void nhap()
{
  cout << "nhap lan luot so dinh, so cach: ";
  cin >> n >> m;
  for (int i = 0; i < m; i++)
  {
    int x, y;
    cout << "Duong di tu dinh x toi dinh y, x,y = ";
    cin >> x >> y;
    adj[x].push_back(y);
    adj[y].push_back(x);
  }
  memset(visited, false, sizeof(visited));
}

void BFS(int u){
  queue<int> q;
  q.push(u);
  visited[u] = true;
  while (!q.empty())
  {
    int x = q.front();   q.pop();
    cout << x << ' ';
    if (x == n) {
      found = true;
      return;
    }
    for(int i: adj[x]){
      if(!visited[i]){
        q.push(i);
        visited[i] = true;
      }
    }
  }
}

int main(){
  nhap();
  BFS(1); //gia su di tu dinh 1 toi dinh lon nhat
  if (!found){
    cout << endl << "not found";
  }
}