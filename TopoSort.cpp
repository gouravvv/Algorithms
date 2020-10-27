    vector<int> store;
void bfs() {
  vector<int> indegree(n + 1, 0);
  for (int i = 1; i <= n; i++)
    for (int j : graph[i]) indegree[j]++;
  queue<int> q;
  for (int i = 1; i <= n; i++)
    if (indegree[i] == 0) q.push(i);
  while (!q.empty()) {
    int v = q.front();
    store.push_back(v);
    q.pop();
    for (int i : graph[v]) {
      indegree[i]--;
      if (indegree[i] == 0)
        q.push(i);
    }
  }

}
// if store.size()<n means their exists a cycle
// and No topo sort exist
void topological_sort() {
  store.clear();
  bfs();
}
