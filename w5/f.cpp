#include <bits/stdc++.h>

using namespace std;

class MaxHeap{
    public: 
    vector<int> a;

    int parent(int i) {return (i - 1)/ 2;}
    int left(int i) {return 2 * i + 1;}
    int right(int i) {return 2 * i + 1;}

    void siftUp(int i){
        while(i > 0 and a[parent(i)] < a[i]){
            swap(a[parent(i)], a[i]);
            i = parent(i);
        }
    }

    void insert(int k){
        a.push_back(k);
        int i = a.size() - 1;
        siftUp(i);
    }

    void heapify(int i ){
        int largest = i; 
        if(i < a.size() and a[left(i)] > a[i]){
            largest = left(i);
        }

        if(i < a.size() and a[right(i)] > a[largest]){
            largest = right(i);
        }

        if(i != largest){
            swap (a[i], a[largest]);
            heapify(largest);
        }
    }
    void print(){
        for(int i = 0; i < a.size(); i++){
            cout << a[i] << " ";
        }
    }
};

int main(){
    MaxHeap *heap = new MaxHeap();
    int n; cin >> n;
    while(n--){
        int x; 
        cin >> x;
        heap -> insert(x);
    }

    heap -> print();
}