#include <iostream>
#include <vector>
//Question:�������n��쳲��������е�ֵ 
//Question: ��ŵ������
//Question: ���ӳ������⣬һ�����ӵ�һ��n���ң�һ��Ե�ǰ����������һ�룬��֪��day�컹ʣm������n 

using namespace std;


int solution(int n){
	if (n == 1 || n == 2){
		return 1;
	}
	return solution(n-1) + solution(n-2);
}


int hanio(int num, int x, char A, char B, char C){
	// num ������Ҫ�ƶ���������
	// x ������Ҫ�ƶ����⼸�����ӣ�������Ǹ�����Ƕ���
	// A��B��C �����ҵ��ƶ������� �ƶ�A�ϵ����Ӿ���B���յ�C 
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

