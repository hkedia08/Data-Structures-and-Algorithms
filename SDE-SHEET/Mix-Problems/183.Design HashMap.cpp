// https://leetcode.com/problems/design-hashmap/

class MyHashMap
{
public:
    vector<list<pair<int, int>>> m;
    int s;
    MyHashMap()
    {
        s = 100;
        m.resize(s);
    }
    int hash(int key)
    {
        return key % s;
    }
    list<pair<int, int>>::iterator search(int key)
    {
        int i = hash(key);
        list<pair<int, int>>::iterator it = m[i].begin();
        while (it != m[i].end())
        {
            if (it->first == key)
            {
                return it;
            }
            it++;
        }
        return it;
    }
    void put(int key, int value)
    {
        int i = hash(key);
        remove(key);
        m[i].push_back({key, value});
    }

    int get(int key)
    {
        int i = hash(key);
        auto it = search(key);
        if (it != m[i].end())
            return it->second;
        return -1;
    }

    void remove(int key)
    {
        int i = hash(key);
        list<pair<int, int>>::iterator it;
        it = search(key);
        if (it != m[i].end())
            m[i].erase(it);
    }
};
