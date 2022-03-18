#include<iostream>
#include<cstring>
using namespace std;
void Sub(char* A, char* B, char* Result);
#define Maxsize 301 
int main()
{
	char A[Maxsize] = "0";
	char B[Maxsize] = "0";
	char Result[Maxsize] = "0";
	cin >> A >> B;
	int SF = 0;
	if (strcmp(A, B) == 0)
	{
		cout << 0 << endl;
		return 0;
	}//两数相等单独判断
	if (strlen(A) > strlen(B))
	{
		SF = 0;
		Sub(A, B, Result);
	}//A长，符号为正，用A-B
	else if (strlen(A) < strlen(B))
	{
		SF = 1;
		Sub(B, A, Result);
	}//B长，符号为负，用B-A
	else 
	{
		int i = 0;
		while (A[i] == B[i]) i++;//已知A与B不等，必能找到不同位
		if (A[i] > B[i])
		{
			SF = 0;
			Sub(A, B, Result);
		}
		else
		{
			SF = 1;
			Sub(B, A, Result);
		}
	}
	if (SF == 1) cout << "-" << Result << endl;
	else cout << Result << endl;
	return 0;
}

void Sub(char* A, char* B, char* Result)//确定了A>B再做减法
{
	Result[strlen(A)] = A[strlen(A)];//先加结束符
	int i = strlen(A) - 1, j = strlen(B) - 1;
	int sub = 0;//记录借位
	for (; i >= 0 && j >= 0; i--, j--)
	{	
		Result[i] = A[i] - B[j] + '0' - sub;
		if (Result[i] < '0')
		{
			Result[i] += 10;
			sub = 1;
		}
		else sub = 0;
	}
	if (i >= 0)
	{
		while (i >= 0)
		{
			Result[i] = A[i] - sub;//复制A高位的，注意最后一次借位
			if (Result[i] < '0')
			{
				Result[i] += 10;
				sub = 1;
			}
			else sub = 0;
			i--;
		}
	}
	int zero = 0;
	for (; Result[zero] == '0'; zero++);//数出Result最前面0的个数
	int m = strlen(Result) - zero;
	for (int i = 0; i <= m; i++)
		Result[i] = Result[i + zero];  //去0
}