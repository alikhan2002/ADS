#include <iostream>
#include <cmath>
#include <algorithm>
using namespace std;

int main(){
    int n;
    cin >> n;
    int i = 1;
    while(n > pow(2, i)){
        i++;
    }
    cout << i;
}
