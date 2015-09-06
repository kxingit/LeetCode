/*
 * tag
 * Given n nodes labeled from 0 to n - 1 and a list of undirected edges (each edge is a pair of nodes), 
 * write a function to check whether these edges make up a valid tree.
 */
class Solution {
  public:
    bool validTree(int n, vector<pair<int, int>>& edges) {
      vector<vector<int>> neighbors(n);
      for (auto e : edges) {
	neighbors[e.first].push_back(e.second);
	neighbors[e.second].push_back(e.first);
      }
      vector<bool> onpath(n, false), visited(n, false);
      if (hasCycle(neighbors, 0, -1, onpath, visited))
	return false;
      for (bool v : visited)
	if (!v) return false; 
      return true;
    }
  private:
    bool hasCycle(vector<vector<int>>& neighbors, int kid, int parent, vector<bool>& onpath, vector<bool>& visited) {
      if (onpath[kid]) return true;
      onpath[kid] = visited[kid] = true;
      for (auto neigh : neighbors[kid])
	if (neigh != parent && hasCycle(neighbors, neigh, kid, onpath, visited))
	  return true;
      return onpath[kid] = false;
    }
};
