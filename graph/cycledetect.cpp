#include <iostream>
using namespace std;

int visited[3] = {0, 0, 0};

int a[3][3] = {
    {0, 1, 0},
    {1, 0, 1},
    {0, 1, 0}
};

bool isCycle(int node, int parent)
{
    visited[node] = 1;

    for (int j = 0; j < 3; j++)
    {
        if (a[node][j] == 1)
        {
            if (!visited[j])
            {
                if (isCycle(j, node))
                {
                    return true;
                }
            }
            else if (j != parent)
            {
                return true;
            }
        }
    }
    return false;
}

int main()
{
    if (isCycle(0, -1))
        cout << "Cycle detected!" << endl;
    else
        cout << "No cycle found." << endl;

    return 0;
}
