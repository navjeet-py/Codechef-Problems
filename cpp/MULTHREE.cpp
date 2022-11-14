#include <bits/stdc++.h>
using namespace std;

typedef long long big;


void mult3() {

	big digits = 0, d0 = 0, d1 = 0;
	cin >> digits >> d0 >> d1;

	if(digits == 2) {

		if((d0 + d1) % 3 == 0)
			cout << "YES\n";
		else
			cout << "NO\n";

		return;
	}

	big d2 = (d0 + d1) % 10;
	big sum = d0 + d1 + d2;
	big d3 = sum % 10;

	if(d3 == 0) {

		if(sum % 3 == 0)
			cout << "YES\n";
		else
			cout << "NO\n";

		return;
	}

	big group_sum = 20;
	big n_groups = (digits - 3) / 4;
	big left = (digits - 3) % 4;

	sum += (group_sum * n_groups);

	for(int i = 0; i < left; i += 1) {

		sum += d3;
		d3 = (2 * d3) % 10;
	}

	if(sum % 3 == 0)
		cout << "YES\n";
	else
		cout << "NO\n";

}


int main() {

	int q = 0;
	cin >> q;

	while(q-- > 0)
		mult3();

	return 0;
}