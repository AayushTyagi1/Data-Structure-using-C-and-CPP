class Solution
{
public:
    //Function to merge k sorted arrays.
    struct triplet
    {
        int val, ap, vp;
        triplet(int v, int a, int b)
        {
            val = v;
            ap = a;
            vp = v;
        }
    };
    struct mycmp
    {
        bool operator()(triplet &t1, triplet &t2)
        {
            return t1.val > t2.val;
        }
    };
    vector<int> mergeKArrays(vector<vector<int>> arr, int K)
    {
        vector<int> res;
        priority_queue<triplet, vector<triplet>, mycmp> pq;
        for (int i = 0; i < arr.size(); i++)
        {
            triplet t(arr[i][0], i, 0);
            pq.push(t);
        }
        while (!pq.empty())
        {
            triplet cur = pq.top();
            pq.pop();
            res.push_back(cur.val);
            int apos = cur.ap, vpos = cur.vp;
            if (arr[apos].size() > vpos + 1)
            {
                triplet t(arr[apos][vpos + 1], apos, vpos + 1);
                pq.push(t);
            }
        }
        return res;
    }
};