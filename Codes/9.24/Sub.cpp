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
	}//������ȵ����ж�
	if (strlen(A) > strlen(B))
	{
		SF = 0;
		Sub(A, B, Result);
	}//A��������Ϊ������A-B
	else if (strlen(A) < strlen(B))
	{
		SF = 1;
		Sub(B, A, Result);
	}//B��������Ϊ������B-A
	else 
	{
		int i = 0;
		while (A[i] == B[i]) i++;//��֪A��B���ȣ������ҵ���ͬλ
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

void Sub(char* A, char* B, char* Result)//ȷ����A>B��������
{
	Result[strlen(A)] = A[strlen(A)];//�ȼӽ�����
	int i = strlen(A) - 1, j = strlen(B) - 1;
	int sub = 0;//��¼��λ
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
			Result[i] = A[i] - sub;//����A��λ�ģ�ע�����һ�ν�λ
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
	for (; Result[zero] == '0'; zero++);//����Result��ǰ��0�ĸ���
	int m = strlen(Result) - zero;
	for (int i = 0; i <= m; i++)
		Result[i] = Result[i + zero];  //ȥ0
}