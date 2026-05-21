#include <iostream>
using namespace std;

int main()
{
    int n;
    cin >> n;

    int arr[n];

    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }

    bool found = false;

    for (int k = 0; k < n; k++)
    {
        int i = 0;
        int j = n - 1;

        while (i < j)
        {
            int sum = arr[i] + arr[j];

            if (sum == arr[k] && i != k && j != k)
            {
                cout << i << " " << j << " " << k;
                found = true;
                break;
            }
            else if (sum < arr[k])
                i++;
            else
                j--;
        }

        if (found)
            break;
    }

    if (!found)
        cout << "No such indices";

    return 0;
}