#include <bits/stdc++.h>

using namespace std;

class MaxHeap{
    public:
    vector<int> a;

    int parent(int i){return (i - 1)/ 2;}
    int left(int i){return 2 * i + 1;}
    int right(int i){return 2 * i + 2;}

    void siftUp(int i){
        while(i > 0 and a[parent(i)] < a[i]){
            swap(a[i], a[parent(i)]);
            i = parent(i);
        }
    }
    void heapify(int i){
        int largest = i;
        if(i < a.size() and a[i] < a[left(i)]){
            largest = left(i);
        }
        if(i < a.size() and a[largest] < a[right(i)] ){
            largest = a[right(i)];
        }

        if(i != largest){
            swap(a[i], a[largest]);
            heapify(largest);
        }
    }
    void insert(int k){
        a.push_back(k);
        int i = a.size() - 1;
        siftUp(i);
    }
    bool empty(){
        return a.size() == 0;
    }
    int getMax(){
        return a[0];
    }
};

int main(){

MaxHeap *heap = new MaxHeap();

int n, m; cin >> n >> m;

for(int i = 0; i < m; i++){
    int x;
    cin >> x;
    if(x == 1){
        if(!heap->empty()){
            heap -> 
        }
    }
    if(x == 2){
        int a; cin >> a;
        heap -> insert(x);
    }
}

}