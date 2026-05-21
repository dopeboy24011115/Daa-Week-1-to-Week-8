#include <iostream>
using namespace std;

int main()
{
    int n, k, count = 0;
    cin >> n;

    int arr[n];

    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }

    cin >> k;

    for (int i = 0; i < n; i++)
    {
        for (int j = i + 1; j < n; j++)
        {
            if (abs(arr[i] - arr[j]) == k)
                count++;
        }
    }

    cout << "Pairs = " << count;

    return 0;
}