#include <iostream>
#include <fstream>
using namespace std;
struct st{
    int a[1000000];
    int top;
    int front;
    st(){
        top = -1;
        front = 0;
    }
    void push(int x){
        top++;
        a[top] = x;
    }
    int front1(){
        return a[front];
    }
    void pop(){
        front++;
    }
    int size(){
        if(top == -1) return 0;
        return top + 1 - front;
    }
};

int main(){
    string s; // сюда будем класть считанные строки
    ifstream file("input.txt"); // файл из которого читаем (для линукс путь будет выглядеть по другому)

    while(getline(file, s)){ // пока не достигнут конец файла класть очередную строку в переменную (s)
        cout << s[0] << endl; // выводим на экран
    }
    file.close(); // обязательно закрываем файл что бы не повредить его

    return 0;

}