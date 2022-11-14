#include <iostream>

using namespace std;
#define range(i, a, b) for(i = a; i < b; i++)

int i, j, k, testcase;

void print_array(int array[], int n) {
    range(i, 0, n) cout << array[i] << ' ';
    cout << endl;
}

int main() {

    long long int T, N;
    cin >> T;
    long long int total, answer;
    long long int candies[100001];
    range(testcase, 0, T) {
        cin >> N;
        total = 0, answer = 0;

        range(i, 0, N){
            cin >> candies[i];
            total += candies[i];
        }
        long long int everyNigga = total / N;
        if (total % N != 0){
            everyNigga++;
        }
        range(i, 0, N){
            if (candies[i] < everyNigga){
                answer += (everyNigga - candies[i]);
            }
        }
        cout << answer<< endl;



    }

    return 0;
}
