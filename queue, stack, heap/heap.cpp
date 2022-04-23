#include<iostream>
#include<climits>
using namespace std;

void swap(int *x, int *y);
  
class MinHeap {
    int *arr;
    int capacity;
    int size;
    public:
        MinHeap(int capacity);
        void MinHeapify(int );

        int parent(int i) { return (i-1)/2; }
        int left(int i) { return (2*i + 1); }
        int right(int i) { return (2*i + 2); }
        
        int extractMin();
        void remove(int i, int new_val);
        int getMin() { return arr[0]; }
        void deleteKey(int i);
        void insert(int k);
};
  
MinHeap::MinHeap(int cap1)
{
    size = 0;
    capacity = cap1;
    arr = new int[cap1];
}
  
void MinHeap::insert(int k)
{
    if (size == capacity)
    {
        cout << "Overflow\n";
        return;
    }
  
    size++;
    int i = size - 1;
    arr[i] = k;
  
    while (i != 0 && arr[parent(i)] > arr[i])
    {
       swap(&arr[i], &arr[parent(i)]);
       i = parent(i);
    }
}

void MinHeap::remove(int i, int new_val)
{
    arr[i] = new_val;
    while (i != 0 && arr[parent(i)] > arr[i])
    {
       swap(&arr[i], &arr[parent(i)]);
       i = parent(i);
    }
}
  
int MinHeap::extractMin()
{
    if (size <= 0)
        return INT_MAX;
    if (size == 1)
    {
        size--;
        return arr[0];
    }
  
    int root = arr[0];
    arr[0] = arr[size-1];
    size--;
    MinHeapify(0);
  
    return root;
}
  
void MinHeap::deleteKey(int i)
{
    remove(i, INT_MIN);
    extractMin();
}

void MinHeap::MinHeapify(int i)
{
    int l = left(i);
    int r = right(i);
    int smallest = i;
    if (l < size && arr[l] < arr[i])
        smallest = l;
    if (r < size && arr[r] < arr[smallest])
        smallest = r;
    if (smallest != i)
    {
        swap(&arr[i], &arr[smallest]);
        MinHeapify(smallest);
    }
}

void swap(int *x, int *y)
{
    int temp = *x;
    *x = *y;
    *y = temp;
}

int main()
{
    MinHeap heap1(10);
    heap1.insert(3);
    heap1.insert(2);
    heap1.deleteKey(1);
    heap1.insert(15);
    heap1.insert(5);
    heap1.insert(4);
    heap1.insert(45);
    cout << heap1.extractMin() << " ";
    cout << heap1.getMin() << " ";
    heap1.remove(3, 2);
    cout << heap1.getMin();
    return 0;
}