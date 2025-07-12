#include <iostream>
using namespace std;

void printer(int *a, int n)
{
    for (int i = 0; i < n; i++)
    {
        cout << a[i] << " ";
    }
    cout << endl;
}

void bubblesort(int *a, int n)
{
    int issorted = 0;
    for (int i = 0; i < n - 1; i++)
    {
        issorted = 1;
        for (int j = 0; j < n - i - 1; j++)
        {
            if (a[j] > a[j + 1])
            {
                int temp = a[j];
                a[j] = a[j + 1];
                a[j + 1] = temp;
                issorted = 0;
            }
        }
        if (issorted)
        {
            return;
        }
    }
}

int main()
{
    int a[] = {5, 6, 1, 2, 9, 5, 2, 4};
    int n = sizeof(a) / sizeof(a[0]);

    cout << "array before sorting: ";
    printer(a, n);

    bubblesort(a, n);

    cout << "array after sorting: ";
    printer(a, n);
    return 0;
};