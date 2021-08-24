#include "headers.h"

class RandomizedSet {
    unordered_map<int, int> _map;
    vector<int> _vals;

   public:
    /** Initialize your data structure here. */
    RandomizedSet() {}

    /** Inserts a value to the set. Returns true if the set did not already
     * contain the specified element. */
    bool insert(int val) {
        if (_map.find(val) != _map.end()) return false;
        int pos = _vals.size();
        _map[val] = pos;
        _vals.push_back(val);
        return true;
    }

    /** Removes a value from the set. Returns true if the set contained the
     * specified element. */
    bool remove(int val) {
        if (_map.find(val) == _map.end()) return false;
        int pos = _map[val];
        _vals[pos] = _vals.back();
        _map[_vals.back()] = pos;
        _map.erase(val);
        _vals.pop_back();
        return true;
    }

    /** Get a random element from the set. */
    int getRandom() {
        if (_vals.empty()) return NULL;
        return _vals[rand() % _vals.size()];
    }
};

/**
 * Your RandomizedSet object will be instantiated and called as such:
 * RandomizedSet* obj = new RandomizedSet();
 * bool param_1 = obj->insert(val);
 * bool param_2 = obj->remove(val);
 * int param_3 = obj->getRandom();
 */