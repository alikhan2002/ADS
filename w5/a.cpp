#include <bits/stdc++.h>

using namespace std;


class MaxHeap{
    public:
    vector <long long> a;

    int parent(int i){ return i - 1 >> 1;}; // i / 2
    int left(int i){ return i + 1 << 1 + 1;}; // i * 2
    int right(int i){ return i << 1 + 2;};//i * 2 + 1

    int getMax(){
        return a[0];
    }
    void siftUp(int i) {
        while (i > 0 && a[parent(i)] < a[i]) {
            swap(a[parent(i)], a[i]);
            i = parent(i);
        }
        // cout << i << " ";
    }
    void siftUp_ind(int i) {
        while (i > 0 && a[parent(i)] < a[i]) {
            swap(a[parent(i)], a[i]);
            i = parent(i);
        }
        cout << i + 1 << "\n";
    }

    void insert(long long k) {
        a.push_back(k);
        int i = a.size() - 1;
        siftUp(i);
    }


    void heapify(int i) {
        if (left(i) > a.size() - 1)
            return;
        
        int j = left(i);
        if (right(i) < a.size() && a[left(i)] > a[right(i)])
            j = right(i);
        if (a[i] > a[j]) {
            swap(a[i], a[j]);
            heapify(j);
        }
    }
    long long x;
    int getIndex(){
        for(int i = 0; i < a.size(); i++ ){
            if(a[i] == x ) return i + 1;
        }
        return 1;
    }
    void decreaseKey(int i, int new_value) {
        a[i] = new_value;
        heapify(i);
    }

    void increaseKey(int i, long long new_value) {
        a[i] = a[i] + new_value;
        x = a[i];
        siftUp_ind(i);
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
        heap -> increaseKey(k - 1, q);
        // cout << heap -> parent(k - 1) << " \n";
        // cout << heap->getIndex() << "\n";
    }
    // for (int i = 0; i < n; i++) { // O(n * logn)

    // }
    heap -> print();

    return 0;
}
