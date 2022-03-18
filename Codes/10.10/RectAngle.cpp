#define _CRT_SECURE_NO_WARNINGS
#include<cstdio>
using namespace std;
template<class T>
class Stack
{
public:
	Stack(int size) :top(-1), Maxsize(size)
	{ element = new T[Maxsize];}
	void Push(T x) { element[++top] = x; }
	void Pop(T& x) { x = element[top--]; }
	bool isEmpty() { return top == -1; }
	T getTop() { return element[top]; }
	~Stack() { delete[]element; }
private:
	T* element;
	int top;
	int Maxsize;
};
int main()
{
	int test = 0, col = 0;
	long long space = 0, max_space = 0;
	scanf("%d", &test);                 //记录用例数
	for (int i = 0; i < test; i++)
	{
		space = 0, max_space = 0;
		scanf("%d", &col);             //该用例的列数
		int* Height = new int[col];
		for (int j = 0; j < col; j++)
			scanf("%d", &Height[j]);   //接收数据
		int top = 0;
		Stack<int> st(col);            //建立栈
		for (int j = 0; j < col; j++)  //建立单调递增的栈
		{
			if (st.isEmpty() || Height[st.getTop()] <= Height[j])
				st.Push(j);            //新元素大，下标直接入栈
			else
			{
				while (!st.isEmpty() && Height[st.getTop()] > Height[j])
				{
					st.Pop(top);
					space = (long long)(j - top) * Height[top];
					if (space > max_space)
						max_space = space;
				}                       //否则，将栈顶元素一一退出，直到栈空或者<= 新元素
				st.Push(top);
				Height[top] = Height[j];
			}
		}
		while (!st.isEmpty())
		{
			st.Pop(top);
			space = (long long)(col - top) * Height[top];
			if (space > max_space)
				max_space = space;
		}
		printf("%lld\n", max_space);
		delete[]Height;
	}
	return 0;
}
	//int test = 0, col = 0;
	//int left = 0, right = 0;
	//long long temp = 0, space = 0;
	//int Rect[100000];
	//scanf("%d",&test);//记录用例数
	//for (int i = 0; i < test; i++)
	//{
	//	scanf("%d", &col);     //该用例的列数
	//	temp = 0, space = 0;   //清零
	//	for (int j = 0; j < col; j++)
	//		scanf("%d", &Rect[j]);
	//	for (int j = 0; j < col; j++)
	//	{
	//		if (Rect[j] == Rect[j + 1])continue;
	//		left = right = j;
	//		for (int k = j - 1; k >= 0; k--)
	//			if (Rect[k] >= Rect[j])
	//				left = k;
	//			else  break;
	//		for (int k = j + 1; k < col; k++)
	//			if (Rect[k] >= Rect[j])
	//				right = k;
	//			else  break;
	//		temp = (long long)Rect[j] * (right - left + 1);
	//		if (temp > space)  space = temp;
	//	}
	//	printf("%lld\n", space);
	//}