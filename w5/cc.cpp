#include <bits/stdc++.h>

using namespace std;

class MaxHeap{
    public:
    vector<int> a;

    int parent(int i){ return (i - 1 )>> 1;}; // (i - 1 )/ 2
    int left(int i){ return (i << 1) + 1;}; // i * 2 + 1
    int right(int i){ return (i << 1) + 2;}

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
        if(a.size() < i) return; 
        int largest = i;
        if (left(i) < a.size() && a[left(i)] > a[i]) {
            largest = left(i);
        }
 
        if (right(i) < a.size() && a[right(i)] > a[largest]) {
            largest = right(i);
        }
        if (largest != i)
        {
            swap(a[i], a[largest]);
            heapify(largest);
        }else{
            cout << i + 1 << " ";
        }
    }
   
    void extractMax(){
        int root_value = getMax();
        swap(a[0], a[a.size() - 1]);
        a.pop_back();
        if(a.size() > 0){
            heapify(0);
        }
        cout << root_value << "\n";
    }
};


int main(){

    MaxHeap *heap = new MaxHeap();

    int n, x; cin >> n;
    for(int i = 0; i < n; i++){
        cin >> x;
        heap -> insert(x);
    }
    for(int i = 0; i < n - 1; i++){
        heap -> extractMax();
    }

    return 0;
}