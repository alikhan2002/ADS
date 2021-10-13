#include <bits/stdc++.h>

using namespace std;


class MaxHeap{
    public:
    vector <long long> a;

    int parent(int i){ return (i - 1 )>> 1;}; // (i - 1 )/ 2
    int left(int i){ return (i << 1) + 1;}; // i * 2 + 1
    int right(int i){ return (i << 1) + 2;};//i * 2 + 2

    int getMax(){
        return a[0];
    }
    void siftUp(int i) {
        while (i > 0 && a[parent(i)] < a[i]) {
            swap(a[parent(i)], a[i]);
            i = parent(i);
        }
    }
    void heapify_down(int i){
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
            heapify_down(largest);
        }else{
            cout << largest + 1 << "\n";
        }
    }

    void insert(long long k) {
        a.push_back(k);
        int i = a.size() - 1;
        siftUp(i);
    }


    void decreaseKey(int i, int new_value) {
        a[i] = a[i] - new_value;
        heapify_down(i);
    }

    void print() {
        for (int i = 0; i < a.size(); i++)
            cout << a[i] << " ";
        cout << endl;
    }

};
int main() {
    long long n, x;
    cin >> n;
    MaxHeap *heap =  new MaxHeap();
    for (int i = 0; i < n; i++) {
        cin >> x;
        heap->insert(x);
    }
    long long m , k, q;
    cin >> m;
    for(int i = 0; i < m; i++){
        cin >> k >> q;
        heap -> decreaseKey(k - 1, q);
    }
    // for (int i = 0; i < n; i++) { // O(n * logn)

    // }
    heap -> print();

    return 0;
}
