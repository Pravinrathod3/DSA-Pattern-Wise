#include<bits/stdc++.h>
using namespace std;

class maxheap{
    int *arr;
    int size;
    int max_size;

    public:

     maxheap(int n){
        arr = new int(n);
        size = 0;
        max_size = n;
     }

     void insert(int num){
        if(size > max_size){
            cout<<"Heap overflow"<<endl;
            return;
        }

        arr[size] = num;
        int index = size;
        size++;

        while(index > 0 && arr[(index-1) / 2] < arr[index]){
            swap(arr[(index-1) / 2], arr[index]);
            index = (index-1) / 2;
        }

        cout<<arr[index]<<" is inserted at"<<index<<endl;
     }

     void print(){
        for(int i=0; i<size; i++){
            cout<<arr[i]<<" ";
        }
        cout<<endl;
     }

     void deletes(){
        if(size == 0){
            cout<<"Under flow"<<endl;
        }

        cout<<arr[0]<<" is deleted"<<endl;

        arr[0] = arr[size-1];
        size--;

        if(size == 0) return;

        heapify(0);
     }

     void heapify(int i){
         while(arr[i] < arr[(2 * i) + 1] || arr[i] < arr[(2 * i) + 2]){
            if(arr[(2 * i) + 1] > arr[(2 * i) + 2]){
                swap(arr[i], arr[(2 * i) + 1]);
                i = (2 * i) + 1;
            }
            else{
                swap(arr[i], arr[(2 * i) + 2]);
                i = (2 * i) + 2;
            }
         }
     }
};

int main(){
    maxheap heap(6);

    heap.insert(4);
    heap.insert(42);
    heap.insert(44);
    heap.insert(2);
    heap.deletes();
    heap.print();
    heap.deletes();
    heap.print();
}