#include <iostream>
#include <cmath>
using namespace std;

int main() {
	int T, N, K, a;
	cin >> T;
	while (T--){
	    cin >> N >> K;
	    int p = 0, q = 0;


	    for (int i = 0; i < N; i++){
	        cin >> a;
	        p += min(a,K);
	        q += a;
	    }
	    cout << q - p << endl;
	}
	return 0;
}
