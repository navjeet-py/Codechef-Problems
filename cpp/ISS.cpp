#include "bits/stdc++.h"

using namespace std;

#define ll long long int
#define max_N 4000010

static ll d[max_N];

// Prime Factorisation sieve from geeksforgeeks
// https://www.geeksforgeeks.org/prime-factorization-using-sieve-olog-n-multiple-queries/
void spf_sieve() {
    d[1] = 1;
    for (ll i = 2; i < max_N; i++)
        d[i] = i;
    for (ll i = 4; i < max_N; i += 2)
        d[i] = 2;
    for (ll i = 3; i * i < max_N; i++) {
        if (d[i] == i) {
            for (ll j = i * i; j < max_N; j += i)
                if (d[j] == j)
                    d[j] = i;
        }
    }
}

map<ll, ll> factorise(ll x) {
    map<ll, ll> factors;
    while (x != 1) {
        factors[d[x]]++;
        x = x / d[x];
    }
    return factors;
}

ll exponent(ll base, ll p)  {
    return ((ll) (0.4 + pow(base, p)));
}


int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;
    spf_sieve();
    for (int test_case = 0; test_case < t; test_case++) {
        ll K;
        cin >> K;
        map<ll, ll> factors = factorise(4 * K + 1);
        ll sum_of_gcd = 1;

        for (pair<int, int> prime_power: factors) {
            ll prime = prime_power.first;
            ll power = prime_power.second;
            ll calculated = exponent(prime, power - 1);
            sum_of_gcd *= ((power + 1) * calculated * prime - power * calculated);
        }
        cout << (2 * K + sum_of_gcd / 2) << '\n';
    }


    return 0;
}