#include<bits/stdc++.h>
using namespace std;

int main()
{
    long long int T, N, laddus, rank;
    string nationality, activity;
    cin >> T;
    while(T--){
        cin >> N >> nationality;
        laddus = 0;
        while(N--){
            cin >> activity;
            if(activity == "CONTEST_WON"){
                cin >> rank;
                if (rank <= 20){
                    laddus += (300 + (20 - rank));
                }else{
                    laddus += 300;
                }
            }
            else if (activity == "TOP_CONTRIBUTOR"){
                laddus += 300;
            }
            else if (activity == "BUG_FOUND"){
                cin >> rank;
                laddus += rank;
            }
            else if (activity == "CONTEST_HOSTED"){
                laddus += 50;
            }
        }
        long long int a = 400;
        if (nationality == "INDIAN"){
            a = 200;
        }
        cout << laddus / a << endl;
    }
    return 0;
}
