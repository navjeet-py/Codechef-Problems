#include <iostream>

using namespace std;
#define range(i, a, b) for(i = a; i < b; i++)

int i, j, k, testcase;

void print_array(int array[], int n) {
    range(i, 0, n) cout << array[i] << ' ';
    cout << endl;
}

int main() {
    string directions;
    cin >> directions;
    int N = directions.length();
    int X1, Y1, X2, Y2;
    cin >> X1 >> Y1 >> X2 >> Y2;

    // @ => y + 1
    // # => y - 1
    // $ => X + 1
    // & => X - 1

    int X = X2 - X1;
    char required_X;
    if (X > 0) required_X = '$';
    else {
        required_X = '&';
        X *= (-1);
    }
//    cout << "X  : " << X << "Required_X : " << required_X << endl;
    j = 0;
    while (X > 0 && j < N ){
        if (directions[j] == required_X){
            X -= 1;
        }
        j++;
    }

    int Y = Y2 - Y1;
    char required_Y;
    if (Y > 0) required_Y = '@';
    else {
        required_Y = '#';
        Y *= (-1);
    }
//    cout << "Y  : " << Y << "Required_Y : " << required_Y << endl;


    k = 0;
    while (Y > 0 && k < N ){
        if (directions[k] == required_Y){
            Y -= 1;
        }
        k++;
    }

    if(max(X, Y) > 0){
        cout << -1 << endl;
    }else{
        cout << max(j, k) << endl;
    }
    
    
    

    return 0;
}
