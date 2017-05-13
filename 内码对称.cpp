/////////////////////////////////////////////////////////////////
//description：C++中int型整数内码是一个32位的01序列，该01序列有些
//是对称的，有些是不对称的。对于给定的一个整数，在一些场合，需要判
//断其整数内码的对称性					      
//input：输入中含有一些整数n（0<=n<=2^32）		       
//output:统计其中一共有多少个其内码对称的整数，输出之            
//sample input：0					      
//		1					      
//		2147483649
//		2
//		3
//sample output：2
/////////////////////////////////////////////////////////////////

#include <iostream>
using namesapce std;

int main()
{
	unsigned long int n;
	int cnt = 0;
	while (cin>>n)
	{
		int i = 0;
		for (i = 0; i < 16; i++)
		{
			unsigned long int max = 1 << (31 - i);
			unsigned long int min = 1 << i;
			bool ma = n&max;
			bool mi = n&min;

			if((ma) != (mi))
				break;
		}
		if(i == 16)
		cnt++;
	}
	cout << cnt << endl;
	return 0;
}

//解释：整数n在计算机内部实际上是以一串二进制的01
//序列进行存储，所以如果该数字的内码是对称的话，
//可以直接使用求与的方法来检验对称的位置上0/1是否
//对称。声明max用来和序列的前16位的第31-i位进行与
//运算，min用来和后16位的第i位进行与运算，如果对称
//的位置上数字相等，则计数器cnt++
