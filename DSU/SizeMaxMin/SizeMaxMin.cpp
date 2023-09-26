#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

struct triple {
    int size;
    int mini;
    int maxi;
};

vector<int> parent;
vector<triple> arr;

void make_set(int v){
    parent[v] = v;
    triple t;
    t.size = 1;
    t.mini = v;
    t.maxi = v;
    arr[v] = t;
}

int get_set(int v) {
    if (parent[v] == v) return v;
    else return parent[v] = get_set(parent[v]);
}

void union_sets(int a, int b) {
    a = get_set(a);
    b = get_set(b);
    if (a != b) {
        if (arr[a].size < arr[b].size)
            swap(a, b);
        parent[b] = a;
        arr[a].size += arr[b].size;
        arr[a].maxi = max(arr[a].maxi, arr[b].maxi);
        arr[a].mini = min(arr[a].mini, arr[b].mini);
    }
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n, m;
    cin >> n >> m;
    parent.resize(n);
    arr.resize(n);
    for (int i = 0; i < n; i++) make_set(i);
    for (int i = 0; i < m; i++) {
        string command;
        int a, b;
        cin >> command;
        cin >> a;
        a--;
        if (command == "union") {
            int b;
            cin >> b;
            b--;
            union_sets(a, b);
        } else {
            int d = get_set(a);
            cout << arr[d].mini + 1 << ' ' << arr[d].maxi + 1 << ' ' << arr[d].size << '\n';
        }
    }

}
