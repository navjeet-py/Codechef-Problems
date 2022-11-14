#include <iostream>
using namespace std;

int main() {
	int T;
	string S;
	cin >> T;
	while(T--){
	      cin >> S;
	      int first = 0, second = 0;
	      bool white = false;
	      for(char i: S){
	            if (i == 'W') white = true;
	            else if (white) second++;
	            else first++;
	      }
	      if (first == second) cout << "Chef" << endl;
	      else cout << "Aleksa" << endl;
	}
	return 0;
}
