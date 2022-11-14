#include <iostream>
#include <cmath>

using namespace std;
int sum_of_digits(int n){
    int result = 0;
    while (n){
        result += (n%10);
        n /= 10;
    }
    return result;
}

int main() {
    int T,N,a,b;
    cin >> T;
    while(T--){
        cin >> N;
        int chef = 0;
        int morty = 0;
        for(int i = 0; i < N; i++){
            cin >> a >> b;
            if (sum_of_digits(a) > sum_of_digits(b)){
                chef++;
            } else if (sum_of_digits(a) < sum_of_digits(b)){
                morty++;
            }else{
                chef++;
                morty++;
            }
        }
        if (chef > morty)cout << 0  << ' '<< chef << endl;
        else if (chef < morty)cout << 1 << ' ' << morty << endl;
        else cout << 2 << ' ' << chef << endl;
    }
}
