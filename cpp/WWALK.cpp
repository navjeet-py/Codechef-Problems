#include <iostream>
#include <vector>
#include <unordered_map>
#include <queue>

using namespace std;


int  main(){
    int T;
    cin >> T;
    int N ;
    long long int dis_a, dis_b;
    long long int answer = 0;
    while(T--){
        cin >> N;
        answer = 0;
        long long int speed_a[N], speed_b[N];
        dis_a = 0; dis_b = 0;
        for (int i = 0;  i < N;  i++){
            cin >> speed_a[i];
        }
        for (int i = 0;  i < N;  i++){
            cin >> speed_b[i];
        }
        for (int i = 0; i < N; i++){
            if (dis_a == dis_b and speed_a[i] == speed_b[i]){
                answer += speed_a[i];
            }
            dis_a += speed_a[i];
            dis_b += speed_b[i];
        }
        cout << answer << endl;


    }


}