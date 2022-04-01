#include<iostream>
using namespace std;
#include"orderclass.hpp"
#include"ordermethods.hpp"
int Sum(const SeqList &l = SeqList());
int main()
{
	SeqList L1;
	SeqList L2;

	int item;
	cout << "Enter integers(0 to end):" << endl;
	cin >> item;
   while (item!=0)
	{
		L1.PushBack(item);
		cin >> item;
	}
	L2 = L1;

	int s = Sum(L2);
	cout << "Sum(L2):";
	cout << s << endl;

	SeqList L3 = L1;
	cout << "L3:";
	for (int i = 0; i < L3.GetSize();i++)
		cout << L3[i] << '\t';
	cout << endl;

	system("pause");
	return 0;
}
int Sum(const SeqList&l)
{
	int s = int();
	for (int i = 0; i < l.GetSize();++i)
		s+= l[i];
	return s;
}
