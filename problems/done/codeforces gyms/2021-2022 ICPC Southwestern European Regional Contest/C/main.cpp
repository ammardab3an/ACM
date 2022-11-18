#include<bits/stdc++.h>

using namespace std;

#define endl '\n'

mt19937 rnd(chrono::steady_clock::now().time_since_epoch().count());

struct node {

  node *l, *r;
  int pos, key, mn, mx;
  int val, g;

  node(int position, int value) {
    l = r = nullptr;
    mn = mx = pos = position;
    key = rnd();
    val = g = value;
  }

  void pull() {
    g = val;
    if(l) g = max(g, l->g);
    if(r) g = max(g, r->g);
    mn = (l ? l->mn : pos);
    mx = (r ? r->mx : pos);
  }
};

//memory O(n)
struct treap {

  node *root;
  treap() {
    root = nullptr;
  }

  void split(node *t, int pos, node *&l, node *&r) {
    if (t == nullptr) {
      l = r = nullptr;
      return;
    }
    if (t->pos < pos) {
      split(t->r, pos, l, r);
      t->r = l;
      l = t;
    } else {
      split(t->l, pos, l, r);
      t->l = r;
      r = t;
    }
    t->pull();
  }
  node* merge(node *l, node *r) {
    if (!l || !r) return l ? l : r;
    if (l->key < r->key) {
      l->r = merge(l->r, r);
      l->pull();
      return l;
    }
    r->l = merge(l, r->l);
    r->pull();
    return r;
  }
  bool find(int pos) {
    node *t = root;
    while (t) {
      if (t->pos == pos) return true;
      if (t->pos > pos) t = t->l;
      else t = t->r;
    }
    return false;
  }
  void upd(node *t, int pos, int val) {
    if (t->pos == pos) {
      t->val = val;
      t->pull();
      return;
    }
    if (t->pos > pos) upd(t->l, pos, val);
    else upd(t->r, pos, val);
    t->pull();
  }
  void insert(int pos, int val) { //set a_pos = val
    if (find(pos)) upd(root, pos, val);
    else {
      node *l, *r;
      split(root, pos, l, r);
      root = merge(merge(l, new node(pos, val)), r);
    }
  }
  int query(node *t, int st, int en) {
    if (t->mx < st || en < t->mn) return 0;
    if (st <= t->mn && t->mx <= en) return t->g;
    int ans = (st <= t->pos && t->pos <= en ? t->val : 0);
    if (t->l) ans = max(ans, query(t->l, st, en));
    if (t->r) ans = max(ans, query(t->r, st, en));
    return ans;
  }
  int query(int l, int r) { //gcd of a_i such that l <= i <= r
    if (!root) return 0;
    return query(root, l, r);
  }
  void print(node *t) {
    if (!t) return;
    print(t->l);
    cout << t->val << " ";
    print(t->r);
  }
};

//total memory along with treap = nlogn
struct ST {
  ST *l, *r;
  treap t;
  int b, e;
  ST() {
    l = r = nullptr;
  }
  ST(int st, int en) {
    l = r = nullptr;
    b = st, e = en;
  }
  void fix(int pos) {
    int val = 0;
    if (l) val = max(val, l->t.query(pos, pos));
    if (r) val = max(val, r->t.query(pos, pos));
    t.insert(pos, val);
  }
  void upd(int x, int y, int val) { //set a[x][y] = val
    if (e < x || x < b) return;
    if (b == e) {
      t.insert(y, val);
      return;
    }
    if (b != e) {
      if (x <= (b + e) / 2) {
        if (!l) l = new ST(b, (b + e) / 2);
        l->upd(x, y, val);
      } else {
        if (!r) r = new ST((b + e) / 2 + 1, e);
        r->upd(x, y, val);
      }
    }
    fix(y);
  }
  int query(int i, int j, int st, int en) { //gcd of a[x][y] such that i <= x <= j && st <= y <= en
    if (e < i || j < b) return 0;
    if (i <= b && e <= j) return t.query(st, en);
    int ans = 0;
    if (l) ans = max(ans, l->query(i, j, st, en));
    if (r) ans = max(ans, r->query(i, j, st, en));
    return ans;
  }
};

signed main(){

    int n, v;
    cin >> n >> v;

    n++;
    vector<int> vec_t(n);
    vector<int> vec_x(n);
    vec_t[0] = 0;
    vec_x[0] = 0;

    for(int i = 1; i < n; i++){
        cin >> vec_t[i];
        vec_t[i]*=v;
    }
    for(int i = 1; i < n; i++){
        cin >> vec_x[i];
    }

    vector<int> tmp;
    for(int i = 0; i < n; i++){
        int t = vec_t[i];
        int x = vec_x[i];
        tmp.push_back(x);
        tmp.push_back(-x);
        tmp.push_back(t+x);
        tmp.push_back(t-x);
    }

    sort(tmp.begin(), tmp.end());
    tmp.resize(unique(tmp.begin(), tmp.end())-tmp.begin());

    int sz = tmp.size();

    ST t0(0, sz-1);
    ST t1(0, sz-1);

    vector<int> dp(n);

    for(int i = n-1; i >= 0; i--){

        int t = vec_t[i];
        int x = vec_x[i];

        int nx = lower_bound(tmp.begin(), tmp.end(), x)-tmp.begin();
        int nt_x = lower_bound(tmp.begin(), tmp.end(), t-x)-tmp.begin();
        int q0 = t0.query(nx, sz-1, nt_x, sz-1);

        int _nx = lower_bound(tmp.begin(), tmp.end(), -x)-tmp.begin();
        int ntx = lower_bound(tmp.begin(), tmp.end(), t+x)-tmp.begin();
        int q1 = t1.query(_nx, sz-1, ntx, sz-1);

        dp[i] = max(q0, q1) + 1;

        t0.upd(nx, nt_x, dp[i]);
        t1.upd(_nx, ntx, dp[i]);
    }

    cout << dp[0]-1 << endl;
}
