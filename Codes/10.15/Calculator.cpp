#include<iostream>
using namespace std;
#define IsNumber(x)  ('0'<= x && x <= '9') ? true : false
#define CharToNumber(x) x - '0'
int icp(char ch);
int isp(char ch);                    //计算栈内栈外优先级
void Translate(char* In, char* Post);//中缀转后缀表示
int  Caculate(char* Post);           //计算后缀表达式
int main()
{
	char Infix[1024];
	char Postfix[1024];
	cin >> Infix;                    //输入中缀形式表达式
	Translate(Infix, Postfix);       //转换表达式形式
	int result = Caculate(Postfix);  //计算后缀表达式
	cout << result << endl;
	return 0;
}
int icp(char ch)
{
	switch (ch)
	{
	case '(':return 6;
	case 'x':return 4;
	case '+':
	case '-':return 2;
	case ')':return 1;
	}
	return 0;
}
int isp(char ch)
{
	switch (ch)
	{
	case '(':return 1;
	case 'x':return 5;
	case '+':
	case '-':return 3;
	case ')':return 6;
	}
	return 0;
}
void Translate(char* In, char* Post)
{
	char Stack[200] = { '\0' };
	int i = 0, j = 0, top = -1;
	while (In[i] != '\0')
	{
		if (IsNumber(In[i])){
			Post[j] = In[i];
			i++; j++; continue;
		}                                              //数字直接入栈
		if (top == -1 || icp(In[i]) > isp(Stack[top]))
			Stack[++top] = In[i];                      //优先级高，直接入栈
		else if (icp(In[i]) < isp(Stack[top])){
			Post[j] = Stack[top--];
			j++; continue;
		}                                             //优先级低，栈顶元素出栈，且不读入下一个字符
		else{
			if (Stack[top--] == '(');
			else continue;
		}                                             //优先级相同，栈顶元素出栈，如果为‘（’，读入下一个字符
		i++;
	}
	while (top != -1) Post[j++] = Stack[top--];      //处理剩余操作符
	Post[j] = '\0';                                  //结束符收尾
}

int  Caculate(char* Post) 
{
	int Stack_num[200] = { 0 };
	char Stack_ope[200] = { 0 };        //操作数和运算符栈
	int num_top = -1, ope_top = -1;     //两个栈顶指针
	for (int i = 0; Post[i] != '\0';i++)
	{
		if (IsNumber(Post[i]))
			Stack_num[++num_top] = CharToNumber(Post[i]);
		else 
		{
			switch (Post[i])
			{
			case'+':
				Stack_num[num_top - 1] = Stack_num[num_top - 1] + Stack_num[num_top];
				Stack_num[num_top--] = 0; break;
			case'-':
				Stack_num[num_top - 1] = Stack_num[num_top - 1] - Stack_num[num_top];
				Stack_num[num_top--]=0; break;
			case'x':
				Stack_num[num_top - 1] = Stack_num[num_top - 1] * Stack_num[num_top];
				Stack_num[num_top--] = 0; break;
			}
		}
	}
	return Stack_num[0];
}