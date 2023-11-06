#include <stdio.h>
#include <tuple>
#include <iostream>
#include <string>

using namespace std;

int main()
{
	//@Ʃ�� �ʱ�ȭ
	tuple<int, string, char> t1;
	t1 = make_tuple(21,"Nov",'M');

	//@Ʃ�� ���� ����

	cout << get<0>(t1) << endl;	//21
	cout << get<1>(t1) << endl;	//Nov
	cout << get<2>(t1) << endl;	//M
	//return 0

	//@Ʃ�� ���� ����

	int x;
	string y;
	char z;

	tie(x, y, z) = t1;
	cout << x << "" << y << "" << z << "";
	//return 0

	//@�ΰ��� Ʃ�� ����

	tuple<int, int>t1(1, 2);
	tuple<int, int>t2(3, 4);
	//tuple<int, int, int, int> t3 = tuple_cat(t1, t2);
	auto t3 = tuple_cat(t1, t2);
	cout << get<0>(t3) << " " << get<1>(t3) << " " << get<2>(t3) << " " << get<3>(t3);
	//return 0;
	
	//���δٸ� Ʃ�� ���� : swap

	cout << "Before Swap" << endl;
	cout << "t1 tuple : ";
	cout << get<0>(t1) << " " << get<1>(t1) << endl;
	cout << "t2 tuple : ";
	cout << get<0>(t2) << " " << get<1>(t2) << endl;

	t1.swap(t2); //t1�� t2 tuple�� swap
	cout << "After Swap" << endl;
	cout << "t1 tuple : ";
	cout << get<0>(t1) << " " << get<1>(t1) << endl;
	cout << "t2 tuple : ";
	cout << get<0>(t2) << " " << get<1>(t2) << endl;

	return 0;
}