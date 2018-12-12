//Authors Solution
#include <bits/stdc++.h>
#define pb push_back
#define fi first
#define se second
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

ll arr[100010], seg_t[400010], seg_lazy[400010];
int ord[100010], uord[100010], dep[100010], subt_size[100010], ancs[100010][18], now_ord;
vector<int> edge[100010];
int root_now, root_lbound, root_rbound;
// recall that global variables are initialised to 0.
void dfs(int now, int prev) {
	ord[now] = now_ord; uord[now_ord] = now; now_ord++;
	subt_size[now] = 1; ancs[now][0] = prev;
	for (int i=0;i<edge[now].size();i++) if (edge[now][i]!=prev) {
		dep[edge[now][i]] = dep[now] + 1;
		dfs(edge[now][i], now);
		subt_size[now] += subt_size[edge[now][i]];
	}
}
// 0 indexed segment tree.
void build_seg(int l, int r, int pos) {
	if (l==r) {
		seg_t[pos] = arr[uord[l]];
		return;
	}
	int mid = (l+r)>>1;
	build_seg(l, mid, 2*pos+1);
	build_seg(mid+1, r, 2*pos+2);
	seg_t[pos] = seg_t[2*pos+1] + seg_t[2*pos+2];
}

void update_seg(int l, int r, int ql, int qr, int pos, ll val) {
	if (seg_lazy[pos]) {
		seg_t[pos] += seg_lazy[pos]*(r-l+1);
		if (l!=r) {
			seg_lazy[2*pos+1] += seg_lazy[pos];
			seg_lazy[2*pos+2] += seg_lazy[pos];
		}
		seg_lazy[pos] = 0;
	}
	if (ql>r||qr<l) return;
	if (ql<=l&&r<=qr) {
		seg_t[pos] += val*(r-l+1);
		if (l!=r) {
			seg_lazy[2*pos+1] += val;
			seg_lazy[2*pos+2] += val;
		}
		return;
	}
	int mid = (l+r)>>1;
	update_seg(l, mid, ql, qr, 2*pos+1, val);
	update_seg(mid+1, r, ql, qr, 2*pos+2, val);
	seg_t[pos] = seg_t[2*pos+1] + seg_t[2*pos+2];
}

ll query_seg(int l, int r, int ql, int qr, int pos) {
	if (seg_lazy[pos]) {
		seg_t[pos] += seg_lazy[pos]*(r-l+1);
		if (l!=r) {
			seg_lazy[2*pos+1] += seg_lazy[pos];
			seg_lazy[2*pos+2] += seg_lazy[pos];
		}
		seg_lazy[pos] = 0;
	}
	if (ql>r||qr<l) return 0;
	if (ql<=l&&r<=qr) return seg_t[pos];
	int mid = (l+r)>>1;
	return query_seg(l, mid, ql, qr, 2*pos+1) + query_seg(mid+1, r, ql, qr, 2*pos+2);
}

int nth_ancs(int u, int n) {
	for (int i=16;i>=0;i--) if (n&(1<<i)) u = ancs[u][i];
	return u;
}

int LCA(int u, int v) {
	if (dep[u]<dep[v]) swap(u, v);
	int dep_dif = dep[u]-dep[v];
	u = nth_ancs(u, dep_dif);  // bringing both on same level.
	if (u==v) return u;
	for (int i=16;i>=0;i--) if (ancs[u][i]!=ancs[v][i]) {
		u = ancs[u][i];
		v = ancs[v][i];
	}
	return ancs[u][0];
}

int main() {
	ios_base::sync_with_stdio(0);
	int n, q; cin >> n >> q;
	root_now = 1, root_lbound = 0, root_rbound = n-1;
	for (int i=1;i<=n;i++) cin >> arr[i];
	for (int i=0;i<n-1;i++) {
		int a, b; cin >> a >> b;
		edge[a].pb(b); edge[b].pb(a);
	}
	dfs(1, 0); build_seg(0, n-1, 0);
	for (int j=1;j<17;j++) for (int i=1;i<=n;i++) ancs[i][j] = ancs[ancs[i][j-1]][j-1];
	// thus this lca algo required O(nlogn) preprocessing and answer query O(logn).
	for (int i=0;i<q;i++) {
		int op; cin >> op;
		if (op==1) {
			cin >> root_now;
			root_lbound = ord[root_now]; root_rbound = ord[root_now]+subt_size[root_now]-1;
		} else if (op==2) {
			int u, v; ll c; cin >> u >> v >> c;
			int in_subt_cnt = 0, origin;
			if (root_lbound<=ord[u]&&ord[u]<=root_rbound) in_subt_cnt++;
			if (root_lbound<=ord[v]&&ord[v]<=root_rbound) in_subt_cnt++;
			if (in_subt_cnt==2) {
				origin = LCA(u, v);
			} else if (in_subt_cnt==1) {
				origin = root_now;
			} else {
				int x = LCA(u, root_now), y = LCA(v, root_now), z = LCA(u, v);
				origin = dep[x]>dep[y]? x: y;
				origin = dep[z]>dep[origin]? z: origin;
			}
			if (origin==root_now) {
				update_seg(0, n-1, 0, n-1, 0, c);
			} else if (root_lbound<ord[origin]&&ord[origin]<=root_rbound) {
				update_seg(0, n-1, ord[origin], ord[origin]+subt_size[origin]-1, 0, c);
			} else if (ord[origin]<ord[root_now]&&ord[root_now]<=ord[origin]+subt_size[origin]-1) {
				update_seg(0, n-1, 0, n-1, 0, c);
				int dep_dif = dep[root_now]-dep[origin];
				int undo = nth_ancs(root_now, dep_dif-1);
				update_seg(0, n-1, ord[undo], ord[undo]+subt_size[undo]-1, 0, -c);
			} else {
				update_seg(0, n-1, ord[origin], ord[origin]+subt_size[origin]-1, 0, c);
			}
		} else {
			int origin; cin >> origin;
			ll ans;
			if (origin==root_now) {
				ans = query_seg(0, n-1, 0, n-1, 0);
			} else if (root_lbound<ord[origin]&&ord[origin]<=root_rbound) {
				ans = query_seg(0, n-1, ord[origin], ord[origin]+subt_size[origin]-1, 0);
			} else if (ord[origin]<ord[root_now]&&ord[root_now]<=ord[origin]+subt_size[origin]-1) {
				ans = query_seg(0, n-1, 0, n-1, 0);
				int dep_dif = dep[root_now]-dep[origin];
				int undo = nth_ancs(root_now, dep_dif-1);
				ans -= query_seg(0, n-1, ord[undo], ord[undo]+subt_size[undo]-1, 0);
			} else {
				ans = query_seg(0, n-1, ord[origin], ord[origin]+subt_size[origin]-1, 0);
			}
			cout << ans << endl;
		}
	}
}
