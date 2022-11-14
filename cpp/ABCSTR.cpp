#include <iostream>
#include <unordered_map>
#include <vector>

using namespace std;


int  main(){
    string str;
    cin >> str;
    long long int  N = str.length();
    long long int  mainArr[N+1][2];
    mainArr[0][0] = 0;
    mainArr[0][1] = 0;

    for (long long int  i = 0; i < N; i++){

        if (str[i] == 'A'){
            mainArr[i+1][0] = mainArr[i][0] + 1;
            mainArr[i+1][1] = mainArr[i][1];
        }
        else if (str[i] == 'B'){
            mainArr[i+1][0] = mainArr[i][0] - 1;
            mainArr[i+1][1] = mainArr[i][1] + 1;
        }
        else if (str[i] == 'C'){
            mainArr[i+1][0] = mainArr[i][0];
            mainArr[i+1][1] = mainArr[i][1] - 1;
        }
    }

    unordered_map<string, int > mp;

    for (long long int i = 0; i <= N; i++){
        string p = to_string(mainArr[i][0]) + '/' + to_string(mainArr[i][1]);
        if (mp.find(p) == mp.end() ){
            mp[p] = 1;
        }
        else{
            mp[p]++;
        }
    }
    long long int  answer = 0;
    for(auto & it : mp){
        long long int k = it.second;
        answer += (k*(k-1))/2;
        
    }
    cout << answer << endl;

}