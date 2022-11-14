#include<bits/stdc++.h>
using namespace std;

int main()
{
    long long int Testcases;
    cin >> Testcases;
    while(Testcases--)
    {
        long long int N,K;
        cin >> N >> K;
        long long int list[N + 1];
        map<long long int,long long int>theMap;
        long long int Answer=0;
        for(int i=0; i < N; i++) cin>>list[i];
        long long int Columns[N + 1][N + 1];
        for(long long int i=0; i < N; i++)for(long long int j=0; j < N; j++) Columns[i][j]=0;

        for(int i=0; i < N; i++)
        {
            theMap.clear();
            for(long long int j=i; j < N; j++)
            {
                Columns[i][j]= (j == 0) ? 0 : Columns[i][j - 1];
                if(theMap.count(list[j]))
                {
                    if(theMap[list[j]] == 1)Columns[i][j]++;
                    Columns[i][j]++;
                }
                theMap[list[j]]++;

            }

        }

        Answer=1e18;
        long long int haha=100;
        long long int pp[101][1001];
        for(int i=0; i <= haha; i++) for(int  j=0; j <= haha; j++)pp[i][j]=0;
        for(int i=0; i < N + 1; i++)pp[1][i]=Columns[0][i - 1];
        for(int i=2; i < haha + 1; i++)pp[i][1]=0;
        for(int i=2; i < haha + 1; i++){
            for(int j=2; j < N + 1; j++){
                long long int best=1e18;
                for(int p=1;p <= j - 1;p++) best=min(best, pp[i - 1][p] + Columns[p][j - 1]);
                pp[i][j]=best;
            }
        }
        for(haha = 1; haha < 101; haha++) Answer=min(haha * K + pp[haha][N], Answer);
        cout << Answer << endl;

    }

}