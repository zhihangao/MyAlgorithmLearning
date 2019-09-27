#include <iostream>
#include <vector>
//Question:请求出第n项斐波那契数列的值 
//Question: 汉诺塔问题
//Question: 猴子吃桃问题，一个猴子第一天n个桃，一天吃当前桃子数量的一半，已知第day天还剩m个，求n 

using namespace std;


int solution(int n){
	if (n == 1 || n == 2){
		return 1;
	}
	return solution(n-1) + solution(n-2);
}


int hanio(int num, int x, char A, char B, char C){
	// num 代表我要移动几个盘子
	// x 代表我要移动的这几个盘子，最底下那个标号是多少
	// A、B、C 代表我的移动过程是 移动A上的盘子经过B最终到C 
	if(num==1){
		cout<< "move" << x << "from" << A << "to" << C <<endl;
		x++;
	}else{
		hanio(num-1,x-1,A,C,B);
		hanio(1,x,A,B,C);
		hanio(num-1,x-1,B,A,C);
	}
}

int monkey(int day, int peach){
	if(day==1){
		return peach;
	}else{
		return monkey(day-1, 2*peach);
	}
}

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main(int argc, char** argv) {
	int n = 10;
//	cout << solution(10) << endl;
//	hanio(4, 4, 'A', 'B', 'C');
	cout<<monkey(10,1);
	return 0;
}

