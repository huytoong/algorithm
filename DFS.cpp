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

void DFS(int u)
{
  if (found) return;
  cout << u << ' ';
  if (u == n) {
    found = true;
    return;
  }
  visited[u] = true;
  for (int v : adj[u])
  {
    if (!visited[v])
    {
      DFS(v);
    }
  }
}
int main()
{
  nhap();
  DFS(1); // gia su di tu dinh 1 toi dinh lon nhat
  if(!found){
    cout << endl<< "not found";
  }
}