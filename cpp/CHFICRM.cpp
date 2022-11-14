#include <iostream>
#include <unordered_map>
using namespace std;

int main() {
	int T, N;
	cin >> T;
	while (T--){
	    cin >> N;
	    unordered_map<int, int> mp;
	    mp[5] = 0;
	    mp[10] = 0;
	    mp[15] = 0;
	    int coin[N];
	    for (int i = 0; i < N; i++){
	        cin >> coin[i];
	    }
	    string ans = "YES";
	    for (int i = 0; i < N; i++){
	        if (coin[i] == 5){
	            mp[5] += 1;
	        }else if(coin[i] == 10){
	            if (mp[5] > 0){
                    mp[5] -= 1;
                    mp[10] += 1;
	            }
	            else{
	                ans = "NO";
                    break;
	            }
	        }
	        else{
	            if (mp[10] > 0){
	                mp[10] -= 1;
	            }else if (mp[5] > 1){
	                mp[5] -= 2;
	            }else{
	                ans = "NO";
                    break;
	            }
	        }
	    }
	    cout << ans << endl;

	}
}
