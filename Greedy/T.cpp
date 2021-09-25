int maximumUnits(vector<vector<int>> &boxTypes, int truckSize)
{
    vector<vector<int>> &boxTypes;
    for (int i = 0; i < boxes.size(); i++)
    {
        boxTypes.push_back({boxes[i], unitPerBox[i]});
    }
    sort(boxTypes.begin(), boxTypes.end(), [](vector<int> &a, vector<int> &b)
         { return a[1] > b[1]; });
    int units = 0;
    for (int i = 0; i < boxTypes.size() && truckSize > 0; i++)
    {
        if (boxTypes[i][0] <= truckSize)
        {
            truckSize -= boxTypes[i][0];
            units += boxTypes[i][0] * boxTypes[i][1];
        }
        else
        {

            units += (truckSize)*boxTypes[i][1];
            truckSize = 0;
        }
    }
    return units;
}