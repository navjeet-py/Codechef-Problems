#include <iostream>
#include <queue>
#include <list>

using namespace std;
#define range(i, a, b) for(i = a; i < b; i++)

int i, j, k, testcase;
int mod = 1000000007;

void print_array(int array[], int n) {
    range(i, 0, n) cout << array[i] << ' ';
    cout << endl;
}

void print_bool_array(bool array[], int n) {
    range(i, 0, n) cout << array[i] << ' ';
    cout << endl;
}

int returnVal(char x) {
    return (int) x - 97;
}


class Graph {
    int V;
    list<int> *adj;

public:
    explicit Graph(int V) {
        this->V = V;
        adj = new list<int>[V];
    }

    void addEdge(int x, int y) {
        adj[x].push_back(y);
        adj[y].push_back(x);
    }

    void printAdjList() {
        range(i, 0, V) {
            for (int x:adj[i])cout << x << ' ';
            cout << endl;
        }
    }

    void dfs(int node, bool visited[], int component[], int cnt) {
        visited[node] = true;
        component[node] = cnt;
        list<int>::iterator pp;
        for (pp = adj[node].begin(); pp != adj[node].end(); ++pp)
            if (!visited[*pp])
                dfs(*pp, visited, component, cnt);
    }

    void level_wise(int root, int level[]) {
        queue<int> que;
        int x;
        bool visited[V];
        range(i, 0, V) visited[i] = false;
        que.push(root);
        level[root] = 0;
        visited[root] = true;
        while (!que.empty()) {
            x = que.front();
            que.pop();
            list<int>::iterator pp;
            for (pp = adj[x].begin(); pp != adj[x].end(); ++pp) {
                if (!visited[*pp]) {
                    que.push(*pp);
                    level[*pp] = level[x] + 1;
                    visited[*pp] = true;
                }
            }
        }

    }

    void connected_components(int component[]) {
        bool visited[V];
        range(i, 0, V) visited[i] = false;
        int cnt = 0;
        range(i, 0, V) {
            if (!visited[i]) {
                dfs(i, visited, component, cnt);
                cnt++;
            }
        }
    }
};


int main() {

    int T, N, a, b;
    cin >> T;
    while (T--) {
        cin >> N;
        Graph g(N);
        range(i, 0, N - 1) {
            cin >> a >> b;
            g.addEdge(a - 1, b - 1);
        }
        int levels[N];
        range(i, 0, N) levels[i] = -1;
        g.level_wise(0, levels);
        range(i, 0, N){
            if (levels[i] % 2 == 0) cout << 1 << ' ';
            else cout << 2 << ' ';
        }
        cout << endl;
    }


    return 0;
}
