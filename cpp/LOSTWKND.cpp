#include <iostream>
#include <vector>
#include <unordered_map>
#include <queue>

using namespace std;


int  main(){
    int T;
    cin >> T;
    int a, b, c,d,e,f;
    while(T--){
        cin >> a >> b >> c >> d >> e >> f;
        a = (a+b+c+d+e) * f;
        if (a <= 120){
            cout << "No" << endl;
        }
        else{
            cout << "Yes" << endl;
        }
    }


}