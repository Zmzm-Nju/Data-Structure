#include<iostream>
using namespace std;
#define IsNumber(x)  ('0'<= x && x <= '9') ? true : false
#define CharToNumber(x) x - '0'
int icp(char ch);
int isp(char ch);                    //����ջ��ջ�����ȼ�
void Translate(char* In, char* Post);//��׺ת��׺��ʾ
int  Caculate(char* Post);           //�����׺���ʽ
int main()
{
	char Infix[1024];
	char Postfix[1024];
	cin >> Infix;                    //������׺��ʽ���ʽ
	Translate(Infix, Postfix);       //ת�����ʽ��ʽ
	int result = Caculate(Postfix);  //�����׺���ʽ
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
		}                                              //����ֱ����ջ
		if (top == -1 || icp(In[i]) > isp(Stack[top]))
			Stack[++top] = In[i];                      //���ȼ��ߣ�ֱ����ջ
		else if (icp(In[i]) < isp(Stack[top])){
			Post[j] = Stack[top--];
			j++; continue;
		}                                             //���ȼ��ͣ�ջ��Ԫ�س�ջ���Ҳ�������һ���ַ�
		else{
			if (Stack[top--] == '(');
			else continue;
		}                                             //���ȼ���ͬ��ջ��Ԫ�س�ջ�����Ϊ��������������һ���ַ�
		i++;
	}
	while (top != -1) Post[j++] = Stack[top--];      //����ʣ�������
	Post[j] = '\0';                                  //��������β
}

int  Caculate(char* Post) 
{
	int Stack_num[200] = { 0 };
	char Stack_ope[200] = { 0 };        //�������������ջ
	int num_top = -1, ope_top = -1;     //����ջ��ָ��
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