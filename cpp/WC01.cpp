#include <iostream>
using namespace std;
#define range(i, a, b) for(i = a; i < b; i++)

int i, j, k;
void print_array(int array[], int n){
    range(i, 0, n) cout << array[i] << ' ';
    cout << endl;
}

int main() {

    int N;
    cin >> N;
    int start[N], end[N];
    range(i, 0, N)cin >> start[i];
    range(i, 0, N)cin >> end[i];
    int done[N];
    int done_cnt = 0;
    int last = 0;
    range(i, 0, N){
        if (start[i] >= last ){
            last = end[i];
            done[done_cnt] = i;
            done_cnt++;
        }
    }
    print_array(done, done_cnt);

    return 0;
}
