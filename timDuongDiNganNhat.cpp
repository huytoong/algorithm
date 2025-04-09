#include <bits/stdc++.h>
#define ii pair<int, int>
using namespace std;
int n, m, s;
vector<ii> adj[1005];

void nhap()
{
  cout << "nhap lan luot so dinh, so cach, dinh bat dau: ";
  cin >> n >> m >> s;
  for (int i = 0; i < m; i++)
  {
    int x, y, w;
    cout << "Duong di tu dinh x toi dinh y co chi phi w | x,y,w = ";
    cin >> x >> y >> w;
    adj[x].push_back({y, w});
    adj[y].push_back({x, w});
  }
}

void timDuongDiNganNhat()
{
  priority_queue<ii, vector<ii>, greater<ii>> q;
  q.push({0, s});
  vector<int> d(n + 1, 1e9);
  d[s] = 0;
  while (!q.empty())
  {
    ii t = q.top();
    q.pop();
    int dis = t.first, u = t.second;
    for (ii e : adj[u])
    {
      int v = e.first, w = e.second;
      if (d[v] > d[u] + w)
      {
        d[v] = d[u] + w;
        q.push({d[v], v});
      }
    }
  }
  for (int i = 1; i <= n; i++)
  {
    cout << "Chi phi de di tu dinh " << s << " toi dinh " << i << " la:" << d[i] << endl;
  }
}

int main(){
  nhap();
  timDuongDiNganNhat();
}
