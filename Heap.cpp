
#include <iostream>
using namespace std;
int heap[1000];
int last_index = -1;
int get_min()
{
    if (last_index == -1)
    {
        cout << "MinHeap is empty" << endl;
        return -1;
    }
    return heap[0];
}

int parent(int i)
{
    return (i - 1) / 2;
}
void heapifyUp(int i)
{
    while (1)
    {
        if (i == 0)
            break;
        if (heap[parent(i)] < heap[i])
            break;

        // swap
        int temp = heap[parent(i)];
        heap[parent(i)] = heap[i];
        heap[i] = temp;

        i = parent(i);
    }
}

void insert(int x)
{
    last_index++;
    heap[last_index] = x;
    heapifyUp(last_index);
}

int leftChild(int i)
{
    return 2 * i + 1;
}

int rightChild(int i)
{
    return 2 * i + 2;
}

void heapifyDown(int i)
{

    if (leftChild(i) > last_index)
    {
        return;
    }
    int mi_node = -1;
    if (rightChild(i) > last_index)
    {
        mi_node = leftChild(i);
    }
    else if (heap[leftChild(i)] < heap[rightChild(i)])
    {
        mi_node = leftChild(i);
    }
    else
    {
        mi_node = rightChild(i);
    }

    if (heap[i] <= heap[mi_node])
    {
        return;
    }

    // swap
    int temp = heap[i];
    heap[i] = heap[mi_node];
    heap[mi_node] = temp;

    heapifyDown(mi_node);
}
int extractMin()
{
    if (last_index == -1)
    {
        cout << "MinHeap is empty" << endl;
        return -1;
    }
    int ret = heap[0];
    heap[0] = heap[last_index];
    last_index--;
    heapifyDown(0);
    return ret;
}

int main()
{

    insert(10);
    insert(11);
    insert(7);
    insert(40);
    insert(23);
    cout << extractMin() << endl;
    cout << extractMin() << endl;
    cout << extractMin() << endl;
    cout << extractMin() << endl;
    cout << extractMin() << endl;
    cout << extractMin() << endl;
    cout << get_min() << endl;
    return 0;
}

/*#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
class MaxHeap
{

    int *arr;
    int size;
    int total_size;

public:
    MaxHeap(int n)
    {
        arr = new int[n];
        size = 0;
        total_size = n;
    }

    void insert(int value)
    {
        if (size == total_size)
        {
            cout << "Heap Overflow" << endl;
            return;
        }

        arr[size] = value;
        int index = size;
        size++;

        while (index > 0 && arr[(index - 1) / 2] < arr[index])
        {
            swap(arr[index], arr[(index - 1) / 2]);
            index = (index - 1) / 2;
        }
        cout << index << " is inserted into the heap" << endl;
    }

    void print()
    {
        for (int i = 0; i < size; i++)
        {
            cout << arr[i] << " ";
        }
        cout << endl;
    }

    void Heapify(int index)
    {
        int largest = index;
        int left = 2 * index + 1;
        int right = 2 * index + 2;

        if (left < size && arr[left] > arr[largest])
        {
            largest = left;
        }
        if (left < size && arr[right] > arr[largest])
            largest = right;
        if (largest != index)
        {
            swap(arr[index], arr[largest]);
            Heapify(largest);
        }
    }

    void Delete()
    {
        if (size == 0)
        {
            cout << "Heap Underflow" << endl;
            return;
        }

        cout << arr[0] << " delete successfully" << endl;
        arr[0] = arr[size - 1];
        size--;

        if (size == 0)
            return;

        Heapify(0);
    }
};

int main()
{

    MaxHeap h1(6);
    h1.insert(56);
    h1.insert(556);
    h1.insert(343);
    h1.insert(6);
    h1.insert(5600);
    h1.print();
    return 0;
}*/

/*#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

void Heapify(int arr[],int index,int n){
    int target=index;
    int left=index*2+1;
    int right=index*2+2;
  
  if(left<n && arr[target]<arr[left]){
    target=left;
  }
  if(right<n && arr[target]<arr[right]){
    target=right;
  }

  if(index!=target){
    swap(arr[index],arr[target]);
    Heapify(arr,target,n);
  }

}

void insert(int arr[],int n){
    //StepDown process....
    for(int i=n/2-1;i>=0;i--){
        Heapify(arr,i,n);
    }
}
void sort(int arr[],int n){
    for(int i=n-1;i>0;i--){
        swap(arr[i],arr[0]);
        Heapify(arr,0,i);
    }
}
void print(int arr[],int n){
    for(int i=0;i<n;i++){
        cout<<arr[i]<<" ";
    }
    cout<<endl;
}
int main(){
    int n;
    cin>>n;
    int arr[n];
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    insert(arr,n);
    print(arr,n);
    sort(arr,n);
    print(arr,n);
    return 0;
}*/