#include <iostream>
#include <cmath>
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
    int T, N, M, a, b;
    cin >> T;
    while (T--) {
        cin >> N >> M;
        Graph g(N);
        range(j, 0, M) {
            cin >> a >> b;
            g.addEdge(a - 1, b - 1);
        }
        int components[N];
        range(i, 0, N) components[i] = -1;
        g.connected_components(components);
        long long int counts[N];
        range(i, 0, N) counts[i] = 0;
        range(i, 0, N) counts[components[i]]++;
//        print_array(counts, N);
        long long int ways = 1;
        int cnt = 0;
        range(i, 0, N) {
            if (counts[i] == 0) {
                break;
            } else {
                ways = (ways * counts[i]) % mod;
                cnt++;
            }
        }
        cout << cnt << ' ' << ways << endl;


    }

    return 0;
}
