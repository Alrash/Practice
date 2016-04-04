#include<iostream>
#include<algorithmn>

using namespace std;

int main()
{
    int count;

    cin >> count;
    while(count--)
    {
        int n, m;
        int arr[3655];
        int p[100];

        for (int i = 1; i < 3655; i++)
            arr[i] = 0;

        cin >> n;
        cin >> m;
        for (int i = 0; i < m; i++)
            cin >> p[i];

        for (int i = 0; i < m; i++)
        {
            for (int j = 1; j * p[i] <= n; j++)
               arr[p[i] * j] = 1;
        }
        
        int ans = 0;
        for (int i = 1; i <= n; i++)
            if (arr[i] == 1)
                ans++;

        cout << ans << endl;
    }

    return 0;
}
