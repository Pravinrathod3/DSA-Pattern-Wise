#include<bits/stdc++.h>
using namespace std;

class Heap{

   

    public:
     vector<int> a;

    void insert(vector<int>& arr){
        a = arr;
        int n = a.size();
        for(int index=(n-1)/2; index>=0; index--){
           heapify(index, n);
        }

    }

    void heapify(int i, int n){
        int largest = i;
        int left = (i * 2) + 1;
        int right = (i * 2) + 2;

        if(left < n && a[largest] < a[left]){
            largest = left;
        }

        if(right < n && a[largest] < a[right]){
            largest = right;
        }

        if(largest != i){
            swap(a[largest], a[i]);
            heapify(largest, n);
        }
    }

    void print(){
        for(auto it: a){
            cout<<it<<" ";
        }
        cout<<"Printed"<<endl;
    }
};

int main(){
    Heap h1;
    vector<int> a ={15, 21, 30, 1, 9, 22};
    h1.insert(a);
    h1.print();
}