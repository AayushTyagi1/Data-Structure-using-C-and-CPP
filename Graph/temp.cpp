#include <bits/stdc++.h>
using namespace std;

class petrolPump
{
public:
    int petrol;
    int distance;
};
int printTour(petrolPump arr[], int n)
{
    int start;
    for (int i = 0; i < n; i++)
    {
        if (arr[i].petrol >= arr[i].distance)
        {
            start = i;
            break;
        }
    }
    int curr_petrol = 0;
    int i;
    for (i = start; i < n;)
    {
        curr_petrol += (arr[i].petrol - arr[i].distance);
        if (curr_petrol < 0)
        {
            i++;
            for (; i < n; i++)
            {
                if (arr[i].petrol >= arr[i].distance)
                {
                    start = i;
                    curr_petrol = 0;
                    break;
                }
            }
        }
        else
            i++;
    }
    if (curr_petrol < 0)
    {
        return -1;
    }

    for (int j = 0; j < start; j++)
    {

        curr_petrol += (arr[j].petrol - arr[j].distance);
        if (curr_petrol < 0)
        {
            return -1;
        }
    }
    return start;
}
int main()
{
    petrolPump arr[] = {{6, 4}, {3, 6}, {7, 3}};

    int n = sizeof(arr) / sizeof(arr[0]);
    int start = printTour(arr, n);

    (start == -1) ? cout << "No solution"
                  : cout << "Start = " << start;

    return 0;
}