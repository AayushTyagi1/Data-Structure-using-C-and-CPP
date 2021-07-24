class Solution
{
public:
    string isKSortedArray(int arr[], int n, int k)
    {
        priority_queue<int, vector<int>, greater<int>> pq;
        //if(n==k) return "Yes";

        for (int i = 0; i < k; i++)
        {
            pq.push(arr[i]);
        }
        int ind = 0;
        for (int i = k; i < n; i++)
        {
            arr[ind++] = pq.top();
            pq.pop();
            pq.push(arr[i]);
        }
        while (!pq.empty())
        {
            arr[ind++] = pq.top();
            pq.pop();
        }
    }
};