#include <iostream>
#include <map>

using namespace std;

int main(){
    multimap<int, int> mp;
    mp.insert(pair< int, int >(2, 1));

    for(auto it = mp.begin(); it != mp.end(); it++){
        cout << it-> second << " ";
    }
}