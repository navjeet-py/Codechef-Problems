#include <iostream>
#include <cmath>
#include <unordered_map>
using namespace std;

int maxPow(long long int N){
    int ans = 1;
    while (N % 2 == 0){
        N /= 2;
        ans *= 2;
    }
    return ans*2;
}
int main() {
	int T;
	long long int TS;
	cin >> T;
	while(T--){
	    cin >> TS;
	    if (TS % 2 == 1){
	        cout << TS / 2 << endl;
	    }
	    else{
	        cout << TS/maxPow(TS) << endl;
	    }
	}
}
