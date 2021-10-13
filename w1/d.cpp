#include <iostream>
#include <deque>
using namespace std;
int main(){
    string s;
    int n;
    deque<string> class9;
    deque<string> class10;
    deque<string> class11;
    while(cin >> n){
        cin >> s;
        if(n == 9) class9.push_back(s);
        if(n == 10) class10.push_back(s);
        if(n == 11) class11.push_back(s);
    }
    while (!class9.empty())
    {
        cout << "9 " << class9.front() << '\n'; 
        class9.pop_front();
    }   
    while (!class10.empty())
    {
        cout << "10 " << class10.front() << '\n'; 
        class10.pop_front();
    }   
    while (!class11.empty())
    {
        cout << "11 " << class11.front() << '\n'; 
        class11.pop_front();
    }   
        
    return 0;

}