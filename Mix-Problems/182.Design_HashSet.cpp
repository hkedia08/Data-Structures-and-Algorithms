// https://leetcode.com/problems/design-hashset/

// implementation using vector
class MyHashSet
{
public:
    vector<int> m;
    MyHashSet()
    {
        int s = 1e6 + 1;
        m.resize(s);
    }

    void add(int key)
    {
        m[key] = 1;
    }

    void remove(int key)
    {
        m[key] = 0;
    }

    bool contains(int key)
    {
        return m[key];
    }
};

// implementation using linked list chaining method
class MyHashSet
{
public:
    vector<list<int>> m;
    int s;
    MyHashSet()
    {
        // it can be used anything linked list will handle collision
        s = 100;
        m.resize(s);
    }
    // this is simple hash function
    int hash(int key)
    {
        return key % s;
    }
    // this will return iterator to key
    list<int>::iterator search(int key)
    {
        int i = hash(key);
        return (find(m[i].begin(), m[i].end(), key));
    }

    void add(int key)
    {
        if (contains(key))
            return;
        int i = hash(key);
        m[i].push_back(key);
    }

    void remove(int key)
    {
        if (!contains(key))
            return;
        int i = hash(key);
        m[i].erase(search(key));
    }

    bool contains(int key)
    {
        int i = hash(key);
        if (search(key) != m[i].end())
            return true;
        else
            return false;
    }
};