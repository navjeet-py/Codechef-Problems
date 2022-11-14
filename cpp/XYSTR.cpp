#include <iostream>
using namespace std;

int main() {
	int T, N;
	cin >> T;
	string S;
	while (T--){
	    cin >> S;
	    N = S.length();
	    int i = 0;
	    int answer = 0;
	    while (i < N-1){
	        if (S[i] == 'x' and S[i+1] == 'y'){
	            i++;
	            answer++;
	        } else if (S[i] == 'y' and S[i+1] == 'x'){
                i++;
                answer++;
	        }
	        i++;
	    }
	    cout << answer << endl;
	}
}
