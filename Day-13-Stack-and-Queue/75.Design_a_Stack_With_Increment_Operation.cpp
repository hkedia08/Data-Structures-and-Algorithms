// https://leetcode.com/problems/design-a-stack-with-increment-operation/

class CustomStack
{
public:
    int size = 0;
    int count = -1;
    int arr[1000];
    CustomStack(int maxSize)
    {
        size = maxSize;
    }

    void push(int x)
    {
        if (count < size - 1)
        {
            count++;
            arr[count] = x;
        }
    }

    int pop()
    {
        if (count != -1)
        {
            int res = arr[count];
            count--;
            return res;
        }
        return -1;
    }

    void increment(int k, int val)
    {
        for (int i = 0; i < min(k, count + 1); i++)
        {
            arr[i] += val;
        }
    }
};

/**
 * Your CustomStack object will be instantiated and called as such:
 * CustomStack* obj = new CustomStack(maxSize);
 * obj->push(x);
 * int param_2 = obj->pop();
 * obj->increment(k,val);
 */