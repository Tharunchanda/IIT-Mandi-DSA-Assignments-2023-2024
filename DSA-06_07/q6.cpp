#include <bits/stdc++.h>
using namespace std;
//https://www.geeksforgeeks.org/strongly-connected-components/
class GFG {
public:
	bool dfs(int curr, int des, vector<vector<int> >& adj,vector<int>& vis){
		if (curr == des) {
			return true;
		}
		vis[curr] = 1;
		for (auto x : adj[curr]) {
			if (!vis[x]) {
				if (dfs(x, des, adj, vis)) {
					return true;
				}
			}
		}
		return false;
	}
	bool isPath(int src, int des, vector<vector<int> >& adj){
		vector<int> vis(adj.size() + 1, 0);
		return dfs(src, des, adj, vis);
	}

	vector<vector<int> > findSCC(int n,vector<vector<int> >& a){
		vector<vector<int> > ans;
		vector<int> is_scc(n + 1, 0);

		vector<vector<int> > adj(n + 1);

		for (int i = 0; i < a.size(); i++) {
			adj[a[i][0]].push_back(a[i][1]);
		}

		// Traversing all the vertices
		for (int i = 1; i <= n; i++) {
			if (!is_scc[i]) {
				vector<int> scc;
				scc.push_back(i);

				for (int j = i + 1; j <= n; j++) {
					if (!is_scc[j] && isPath(i, j, adj)
						&& isPath(j, i, adj)) {
						is_scc[j] = 1;
						scc.push_back(j);
					}
				}
				ans.push_back(scc);
			}
		}
		return ans;
	}
};

int main(){

	GFG obj;
	int V = 5;
	vector<vector<int> > edges{{ 1, 3 }, { 1, 4 }, { 2, 1 }, { 3, 2 }, { 4, 5 }};
	vector<vector<int> > ans = obj.findSCC(V, edges);
	cout << "Strongly Connected Components are:\n";
	for (auto x : ans) {
		for (auto y : x) {
			cout << y << " ";
		}
		cout << "\n";
	}
}
