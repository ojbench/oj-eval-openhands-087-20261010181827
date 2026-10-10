#include <bits/stdc++.h>
using namespace std;

void distribute(int l, int r, long long balls, vector<int>& leaf) {
    if (balls == 0) return;
    if (r - l == 1) {
        leaf[l] ^= (balls & 1LL);
        return;
    }
    long long left = (balls + 1) / 2; // ceil
    long long right = balls / 2;      // floor
    int mid = (l + r) / 2;
    distribute(l, mid, left, leaf);
    distribute(mid, r, right, leaf);
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int D; long long n;
    if (!(cin >> D >> n)) return 0;
    int leafCount = 1 << (D - 1);
    vector<int> leaf(leafCount, 0);
    distribute(0, leafCount, n, leaf);
    // compute last ball position using binary method
    long long node = 1; // start at root (1-indexed)
    long long cur = n;
    for (int depth = 1; depth <= D - 1; ++depth) {
        if (cur % 2 == 1) {
            node = node * 2; // go left
            cur = (cur + 1) / 2;
        } else {
            node = node * 2 + 1; // go right
            cur = cur / 2;
        }
    }
    cout << node << "\n";
    for (int i = 0; i < leafCount; ++i) {
        if (i) cout << ' ';
        cout << leaf[i];
    }
    cout << "\n";
    return 0;
}
