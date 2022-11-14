#include <iostream>
#include <bits/stdc++.h>

using namespace std;
#define print(x) cout << x << endl
#define pb push_back
#define vi vector<int>
#define mod 1000000007
#define MIN_INT -2147483648
#define index(c) (((int) c) - 97)
//#define int long long

// TREE OF 11 edges 11 1 2 1 3 1 4 2 5 3 6 6 9 3 7 7 10 7 11 4 8

#define range(i, a, b) for(int i = a; i < b; i++)

void print_array(int A[], int N) {
    range(i, 0, N) cout << A[i] << ' ';
    cout << endl;
}

bool prime[1000000 + 1];


void SieveOfEratosthenes(int n)
{
    // Create a boolean array
    // "prime[0..n]" and initialize
    // all entries it as true.
    // A value in prime[i] will
    // finally be false if i is
    // Not a prime, else true.
    range(i, 0, n + 1) prime[i] = true;

    for (int p = 2; p * p <= n; p++)
    {
        // If prime[p] is not changed,
        // then it is a prime
        if (prime[p])
        {
            // Update all multiples
            // of p greater than or
            // equal to the square of it
            // numbers which are multiple
            // of p and are less than p^2
            // are already been marked.
            for (int i = p * p; i <= n; i += p)
                prime[i] = false;
        }
    }
}


int32_t main() {


    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);


    int T = 1;
    cin >> T;
    SieveOfEratosthenes(1000000);

    static int dp[1000001];


    dp[0] = dp[1] = dp[2] = dp[3] = dp[4] = 0;
    range(i, 4, 1000001){
        if (prime[i] && prime[i - 2]){
            dp[i] = dp[i - 1] + 1;
        }else dp[i] = dp[i - 1];

    }


    while (T--) {
        int N;
        cin >> N;

        // Print all prime numbers
        cout << dp[N] << endl;
    }

    return 0;
}