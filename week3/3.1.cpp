#include <iostream>
using namespace std;

int main()
{
    int n, comp = 0, shift = 0;
    cin >> n;

    int arr[n];

    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }

    for (int i = 1; i < n; i++)
    {
        int temp = arr[i];
        int j = i - 1;

        while (j >= 0 && arr[j] > temp)
        {
            comp++;
            arr[j + 1] = arr[j];
            shift++;
            j--;
        }

        if (j >= 0)
            comp++;

        arr[j + 1] = temp;
    }

    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }

    cout << "\nComparisons = " << comp;
    cout << "\nShifts = " << shift;

    return 0;
}