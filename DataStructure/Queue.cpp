#include<iostream>
using namespace std;

class myqueue{
public:
    int length;
    int top;
    int *array;
    myqueue(int length);
    void push(int x);
    int pop();
    int get_num();
};

myqueue::myqueue(int length){
    length = length;
    array = new int[length];
    top = 0;
}

void myqueue::push(int x){
    if(top == length){
        cout<<"full"<<endl;
    }else
    {
        array[top++] = x;
    }
}

int myqueue::pop(){
    if(top == 0){
        cout<<"empty"<<endl;
        return -1;
    }else{
        int temp = array[0];
        for(int i=1;i<top;i++){
            array[i-1] = array[i];
        }
        top--;
        return temp;
    }
}

int myqueue::get_num(){
    return top;
}

int main(void){
    myqueue queue = myqueue(10);
    cout<<queue.get_num()<<endl;
    queue.push(0);
    queue.push(1);
    cout<<queue.get_num()<<endl;
    cout<<queue.pop()<<endl;
    cout<<queue.pop()<<endl;
}