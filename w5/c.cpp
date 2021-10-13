#include <bits/stdc++.h>

using namespace std;

class MaxHeap{
    public:
    vector<int> a;

    int parent(int i){return (i - 1) >> 1;}
    int left(int i){return (i + 1) << 1;}
    int right(int i){return (i + 2) << 2;}

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

    int getMax(){
        return a[0];
    }
    void heapify(int i){
        int largest = i;
        
        if(left(i) < a.size() and a[left(i)] > a[i]){
            largest = left(i);
        }

        if(right(i) < a.size() and a[right(i)] > a[largest]){
            largest = right(i);
        }
        if( i != largest){
            swap(a[i], a[largest]);
            heapify(largest);
        }else{ 
            cout << i << " ";
        }
    }
    int extractMax(){
        int root_value = getMax();
        swap(a[0], a[a.size() - 1]);
        a.pop_back();
        if(a.size() > 0){
            heapify(0);
        }
        cout << a.size() << " " << root_value << "\n";
    }
};


int main(){

    MaxHeap *heap = new MaxHeap();

    int n, x; cin >> n;
    for(int i = 0; i < n; i++){
        cin >> x;
        heap -> insert(x);
    }
    for(int i = 0; i < n; i++){
        heap -> extractMax();
    }


    return 0;
}