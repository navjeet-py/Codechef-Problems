#include <iostream>
#include "cmath"
#include<bits/stdc++.h>

using namespace std;

#define range(i, a, b) for(int i = a; i < b; i++)

void print_array(int arr[], int N) {
    range(i, 0, N) cout << arr[i] << ' ';
    cout << endl;
}


int main() {

    int N, M;
    cin >> N >> M;
    string chef, cntry;
    map<string, string> country;
    map<string, int> chef_vote, country_vote;
    range(i, 0, N) {
        cin >> chef >> cntry;
        country[chef] = cntry;
        chef_vote[chef] = 0;
        country_vote[cntry] = 0;
    }
    int mxchef = 0, mxcntry = 0;
    range(i, 0, M) {
        cin >> chef;
        chef_vote[chef]++;
        country_vote[country[chef]]++;
        mxchef = max(mxchef, chef_vote[chef]);
        mxcntry = max(mxcntry, country_vote[country[chef]]);
    }
    int n = 0;
    for (auto x:country_vote) {
        if (x.second == mxcntry && n == 0) {
            cntry = x.first;
            n = 1;
        } else if (x.second == mxcntry && n == 1) {
            if (cntry > x.first)
                cntry = x.first;
        }
    }
    n = 0;
    for (auto x:chef_vote) {
        if (x.second == mxchef && n == 0) {
            chef = x.first;
            n = 1;
        } else if (x.second == mxchef && n == 1) {
            if (chef > x.first)
                chef = x.first;
        }
    }
    cout << cntry << "\n" << chef;


    return 0;
}