#include <iostream>
#include <cmath>
using namespace std;

int main()
{
    int n, key;
    cin >> n;

    int arr[n];

    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }

    cin >> key;

    int step = sqrt(n);
    int prev = 0;

    while (arr[min(step, n) - 1] < key)
    {
        prev = step;
        step += sqrt(n);

        if (prev >= n)
        {
            cout << "Not Present";
            return 0;
        }
    }

    for (int i = prev; i < min(step, n); i++)
    {
        if (arr[i] == key)
        {
            cout << "Present";
            return 0;
        }
    }

    cout << "Not Present";

    return 0;
}