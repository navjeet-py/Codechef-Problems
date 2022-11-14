#include<iostream>
#include<algorithm>
using namespace std;

int main(){
    int T, G, N, I, Q;
    cin >> T;
    while (T--){
        cin >> G;
        while(G--){
            cin >> I >> N >> Q;
            if (N % 2 == 0){
                cout << N / 2 << endl;
            }else{
                if(I == Q){
                    cout << N / 2 << endl;
                }else{
                    cout << N / 2 + 1 << endl;
                }
            }
        }
    }
    return 0;
}