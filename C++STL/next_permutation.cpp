#include <iostream>
#include <algorithm>
using namespace std;

int main()
{
	//时间复杂度比较高 最好只处理比较小的数组
	
	//next_permutation 从小到大全排列
	//如果要求排列所有情况 需要一组升序的元素
	int a[] = {1,2,3,4};
	do
	{
		for(int i = 0; i < 4; i++)
		{
			cout<<a[i]<<" ";
		}
		cout<<endl;
	}while(next_permutation(a, a+4));
	cout<<"-----------------------"<<endl;
	for(int i = 0; i < 4; i++)
	{
		cout<<a[i]<<" ";
	}
	cout<<endl;
	reverse(a,a+4);
	for(int i = 0; i < 4; i++)
	{
		cout<<a[i]<<" ";
	}
	cout<<endl<<"-----------------------"<<endl;
	
	//prev_permutation 从大到小全排列
	do
	{
		for(int i = 0; i < 4; i++)
		{
			cout<<a[i]<<" ";
		}
		cout<<endl;
	}while(prev_permutation(a, a+4));
	return 0;
}

