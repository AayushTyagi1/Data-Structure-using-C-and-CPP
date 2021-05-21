#include <bits/stdc++.h>
using namespace std;

class CanSum
{
    map<int, int> m;

public:
    CanSum(int m, int n)
    {
    }
    int helper((int targetSum, vector<int> a)) if (targetSum == 0) return true;
    if (targetSum < 0)
        return false;
    for (auto i : a)
    {
        int remainder = targetSum - i;
        if (CanSum(remainder, a))
            return true;
    }
    return false;
};

int main()
{
    cout << CanSum(7, {2, 3}) << endl;
    cout << CanSum(7, {5, 3, 4, 7}) << endl;
    cout << CanSum(7, {2, 4}) << endl;
    cout << CanSum(8, {2, 3, 5}) << endl;
    cout << CanSum(300, {7, 14}) << endl;
}
