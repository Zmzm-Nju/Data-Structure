#define _CRT_SECURE_NO_WARNINGS
#include<cmath>
#include<cstdio>
using namespace std;
struct Position
{
	double x;
	double y;
	double z;
	double distance;
	Position* left;
	Position* right;
	Position(double sx, double sy, double sz) :left(NULL), right(NULL) 
	{
		x = sx; y = sy; z = sz;
		distance = sqrt(pow(x, 2) + pow(y, 2) + pow(z, 2));
	};
};
void Insert(Position* p, Position*& root);
double Delete(Position*& root); //删除一个节点
int main()
{
	int num = 0, del = 0;
	double  x = 0, y = 0, z = 0;
	scanf("%d", &num);
	char ch = '\0';
	Position* root = NULL;
	for (int i = 0; i < num; i++)
	{
		scanf(" %c", &ch);
		if (ch == 'A')
		{
			scanf("%lf%lf%lf", &x, &y, &z);
			Position* p = new Position(x, y, z);
			Insert(p, root);
		}
		else if (ch == 'Q')
		{
			scanf("%d", &del);
			double sum = 0;
			for (int i = 0; i < del; i++)
				sum += Delete(root);
			printf("%.5lf\n", sum / del);
		}
	}
	return 0;
}

void Insert(Position* p, Position*& root)
{
	if (root == NULL)root = p;
	else if (root->distance > p->distance)Insert(p, root->left);
	else Insert(p, root->right);
}
double Delete(Position* &root)
{
	double val = 0;
	Position* pre = NULL, *p = root;
	while (p->left != NULL)
	{
		pre = p;
		p = p->left;
	}
	if (pre == NULL)
	{
		val = root->distance;
		Position* cur = root;
		root = root->right;
		delete cur;
	}
	else if (p->right == NULL)
	{
		val = p->distance;
		delete p;
		pre->left = NULL;
	}
	else
	{
		val = p->distance;
		Position* q = p->right;
		while (q->left != NULL)q = q->left;
		p->x = q->x; p->y = q->y; p->z = q->z;
		p->distance = q->distance;
		Delete(p->right);
	}
	return val;
}