#include <bits/stdc++.h>

using namespace std;

class MaxHeap{
    public: 
    vector<long long int> a;

    int parent(int i) {return (i - 1)/ 2;}
    int left(int i) {return 2 * i + 1;}
    int right(int i) {return 2 * i + 2;}

    void siftUp(int i){
        while(i > 0 and a[parent(i)] > a[i]){
            swap(a[i], a[parent(i)]);
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

        if(left(i) < a.size() && a[left(i)] > a[i]){
            largest = left(i);
        }

        if(right(i) < a.size() && a[right(i)] > a[largest]){
            largest = right(i);
        }

        if(largest != i){
            swap(a[largest], a[i]);
            heapify(largest);
        }
    }
     void heapify_up(int i){
        if (i && a[parent(i)] < a[i]){
            swap(a[i], a[parent(i)]);
 
            heapify_up(parent(i));
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
    for(int i = 0; i < n; i++){
        int x; 
        cin >> x;
        heap->insert(x);

    }
    for(int i = n - 1; i >= 0; i--){
        heap -> heapify(i);
    }
    // for(int i = 0; i < n; i++){
    //     heap -> heapify_up(i);
    // }
    heap -> print();
}