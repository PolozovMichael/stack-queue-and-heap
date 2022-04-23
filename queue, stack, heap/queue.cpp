#include <iostream>
using namespace std;

class Queue {
public:
    int front, back, size;
    unsigned int capacity;
    int* array;
};

Queue* createQueue(unsigned capacity) {
    Queue* queue = new Queue();
    queue->capacity = capacity;
    queue->front = queue->size = 0;
    queue->back = capacity - 1;
    queue->array = new int[queue->capacity];
    return queue;
}
 
int isFull(Queue* queue) {
    return (queue->size == queue->capacity);
}

int isEmpty(Queue* queue) {
    return (queue->size == 0);
}

void enqueue(Queue* queue, int item) {
    if (isFull(queue))
        return;
    queue->back = (queue->back + 1) % queue->capacity;
    queue->array[queue->back] = item;
    queue->size = queue->size + 1;
    cout << item << " enqueued to queue\n";
}

int dequeue(Queue* queue) {
    if (isEmpty(queue)) return -1000;
    int item = queue->array[queue->front];
    queue->front = (queue->front + 1) % queue->capacity;
    queue->size = queue->size - 1;
    return item;
}

int front(Queue* queue) {
    if (isEmpty(queue))
        return -1000;
    return queue->array[queue->front];
}

int back(Queue* queue) {
    if (isEmpty(queue))
        return -1000;
    return queue->array[queue->back];
}
 
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    Queue* queue = createQueue(1000);
    enqueue(queue, rand() % 100);
    enqueue(queue, rand() % 100);
    enqueue(queue, rand() % 100);
    enqueue(queue, rand() % 100);
    enqueue(queue, rand() % 100);
    cout << dequeue(queue) << " removed\n";
    cout << "Front item is " << front(queue) << "\n";
    cout << "Back item is " << back(queue) << "\n";
    return 0;
}