/*
Implement priority queues using heaps.

Made By: Gaurav Baweja
*/
#include<bits/stdc++.h>
using namespace std;

class priorityQueue
{
    vector <int> arr;
    int size = 0;
    void swap(int &a, int &b)
    {
        int c = b;
        b = a;
        a = c;
    }
    int get_parent(int index)
    {
        return (index - 1) / 2;
    }
    void maxheapify(int index)
    {
        int max_index = index;
        int left_index = 2 * index + 1;
        int right_index = 2 * index + 2;
        if(left_index < size && arr[left_index] > arr[max_index])
            max_index = left_index;
        if(right_index < size && arr[right_index] > arr[max_index])
            max_index = right_index;
        if(max_index != index)
        {
            swap(arr[max_index], arr[index]);
            maxheapify(max_index);
        }
    }
    public:
    void insert(int key)
    {
        size++;
        arr.push_back(0);
        increase_key(size - 1, key);
    }
    void increase_key(int index, int key)
    {
        arr[index] = key;
        while ((index > 0) && (arr[get_parent(index)] < arr[index]))
        {
            swap(arr[get_parent(index)], arr[index]);
            index = get_parent(index);
        }
    }
    void decrease_key(int index, int key)
    {
        arr[index] = key;
        maxheapify(index);

    }
    int maximum()
    {
        return arr[0];
    }
    int extract_max()
    {
        int max = arr[0];
        arr[0] = arr[size - 1];
        size--;
        maxheapify(0);
        return max;
    }
    void display()
    {
        for(int i = 0; i < size; i++)
            cout << arr[i] << ' ';
        cout << endl;
    }
};

main()
{
    priorityQueue pq;
    pq.insert(20);
    pq.insert(10);
    pq.insert(15);
    pq.insert(1);
    pq.insert(9);
    pq.insert(18);
    pq.insert(12);
    pq.insert(16);
    pq.insert(5);
    pq.insert(3);
    pq.display();
    pq.increase_key(9, 23);
    pq.decrease_key(1, 2);
    pq.display();
    cout << pq.maximum();
    return 0;
}