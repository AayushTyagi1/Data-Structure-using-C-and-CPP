class RandomizedSet {
    unordered_map<int, int> mp;
    vector<int> arr;
public:
    RandomizedSet() {
        
    }
    
    bool insert(int val) {
        if(mp.find(val)!=mp.end())
            return false;
        mp[val]=arr.size();
        arr.push_back(val);
        return true;
    }
    
    bool remove(int val) {
        if(mp.find(val)==mp.end()) return false;
        int n = arr.size()-1;
        swap(arr[mp[val]], arr[n]);
        arr.pop_back();
        mp[arr[mp[val]]] = mp[val];
        mp.erase(val);
        return true;
    }
    
    int getRandom() {
        return arr[rand()%arr.size()];
    }
};


/**
 * Your RandomizedSet object will be instantiated and called as such:
 * RandomizedSet* obj = new RandomizedSet();
 * bool param_1 = obj->insert(val);
 * bool param_2 = obj->remove(val);
 * int param_3 = obj->getRandom();
 */