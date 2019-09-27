#include <iostream>


/* run this program using the console pauser or add your own getch, system("pause") or input loop */
class mystack{
public:
	int top;
	int *array;
	int length;
	mystack(int length){
		length = length;
		array = new int[length];
		top = 0;
	}
	int get_num();
	void push_one(int one);
	int pop_one();
};
int mystack::get_num(){
	return top;
}
void mystack::push_one(int one){
	if (top == length){
		cout << "full stack !" << endl;
	}
	else {
		array[top++] = one;
	}
}
int mystack::pop_one(){
	if (top == 0){
		cout << "empty stack" << endl;
		return -1;
	}
	else {
		return array[--top];
	}
}



int main(int argc, char** argv) {
	mystack *test = new mystack(10);
	return 0;
}
