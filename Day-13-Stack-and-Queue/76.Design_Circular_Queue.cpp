// https://leetcode.com/problems/design-circular-queue/

class MyCircularQueue
{
public:
    int f, r, sz, len;
    vector<int> cq;
    MyCircularQueue(int k)
    {
        f = 0, r = 0, len = 0;
        sz = k;
        cq.assign(k, -1);
    }

    bool enQueue(int value)
    {
        if (isFull())
            return false;
        len++;
        cq[r] = value;
        r = (r + 1) % sz;
        return true;
    }

    bool deQueue()
    {
        if (isEmpty())
            return false;
        len--;
        cq[f] = -1;
        f = (f + 1) % sz;
        return true;
    }

    int Front()
    {
        if (isEmpty())
            return -1;
        return cq[f];
    }

    int Rear()
    {
        if (isEmpty())
            return -1;
        int index = r - 1;
        if (index < 0)
            index = index + sz;
        return cq[index];
    }

    bool isEmpty()
    {
        if (len == 0)
            return true;
        return false;
    }

    bool isFull()
    {
        if (len == sz)
            return true;
        return false;
    }
};

/**
 * Your MyCircularQueue object will be instantiated and called as such:
 * MyCircularQueue* obj = new MyCircularQueue(k);
 * bool param_1 = obj->enQueue(value);
 * bool param_2 = obj->deQueue();
 * int param_3 = obj->Front();
 * int param_4 = obj->Rear();
 * bool param_5 = obj->isEmpty();
 * bool param_6 = obj->isFull();
 */