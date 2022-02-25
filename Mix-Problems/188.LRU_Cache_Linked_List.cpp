// https://leetcode.com/problems/lru-cache/

// Linked list implementation
class LRUCache
{
public:
    map<int, int> m;
    list<int> l;
    map<int, list<int>::iterator> address;
    int cap, siz;
    LRUCache(int capacity)
    {
        cap = capacity;
        siz = 0;
    }

    int get(int key)
    {
        // not present
        if (m.find(key) == m.end())
            return -1;
        auto it = address[key];
        l.erase(it);
        address.erase(key);
        l.push_front(key);
        address[key] = l.begin();
        return m[key];
    }

    void put(int key, int value)
    {
        if (m.find(key) != m.end())
        {
            auto it = address[key];
            l.erase(it);
            address.erase(key);
            m.erase(key);
            siz--;
        }
        // function of LRU here
        if (siz == cap)
        {
            int k = l.back();
            auto it = address[k];
            l.erase(it);
            m.erase(k);
            address.erase(k);
            siz--;
        }
        // MRU
        l.push_front(key);
        address[key] = l.begin();
        m[key] = value;
        siz++;
    }
};
