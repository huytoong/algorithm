#include <bits/stdc++.h>
using namespace std;

int n, m;              // so dinh, so canh
vector<int> adj[1005]; // danh sach ke
bool found = false;

bool DFS(int u, int depth, int maxDepth, vector<bool> &visitedDFS)
{
  if (depth > maxDepth)
    return false;
  cout << u << ' ';
  if (u == n)
    return true;

  visitedDFS[u] = true;

  for (int v : adj[u])
  {
    if (!visitedDFS[v])
    {
      if (DFS(v, depth + 1, maxDepth, visitedDFS))
        return true;
    }
  }

  return false;
}

void BFS_DFS(int start, int maxDepth)
{
  queue<int> q;
  vector<bool> visitedBFS(n + 1, false);
  q.push(start);
  visitedBFS[start] = true;

  while (!q.empty())
  {
    int u = q.front();
    q.pop();

    vector<bool> visitedDFS(n + 1, false);
    if (DFS(u, 0, maxDepth, visitedDFS))
    {
      found = true;
      return;
    }

    for (int v : adj[u])
    {
      if (!visitedBFS[v])
      {
        q.push(v);
        visitedBFS[v] = true;
      }
    }
  }
}

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
}

int main()
{
  nhap();
  int maxDepth;
  cout << "Nhap do sau toi da: ";
  cin >> maxDepth;

  BFS_DFS(1, maxDepth);

  if (!found)
    cout << "not found ";
}
