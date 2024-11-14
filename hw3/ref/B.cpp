#include <bits/stdc++.h>

using namespace std;
#define ll long long
#define MAXN 100100
int n, m, cnt, len = 200, a[MAXN];
int c[MAXN], d[MAXN], cntc, cntd;
struct node
{
	int last, flag;
	int a[410];
	node()
	{
		last = 0;
		flag = 0;
		next = pre = NULL;
	}
	void pb(int x) { a[++last] = x; }
	node *next, *pre;
} *head, *tail, pool[150100];
void push(node *p)
{
	if (p->flag == 0)
		return;
	for (int i = 1; i <= p->last / 2; i++)
		swap(p->a[i], p->a[p->last - i + 1]);
	p->flag = 0;
}
void check(node *p)
{
	if (p->last < 2 * len)
		return;
	push(p);
	node *newnode = &pool[++cnt];
	newnode->next = p->next;
	newnode->pre = p;
	if (p->next)
		p->next->pre = newnode;
	p->next = newnode;
	for (int i = p->last - len + 1; i <= p->last; i++)
	{
		newnode->pb(p->a[i]);
	}
	p->last -= len;
	if (tail == p)
		tail = newnode;
}
void pushb(node *p, int nn, int L, int R)
{
	push(p);
	int sump = nn - p->last;
	L -= sump, R -= sump;
	cntc = 0;
	cntd = 0;
	for (int i = 1; i <= p->last; i++)
	{
		if (i < L)
			continue;
		else
		{
			if (i <= R)
				d[++cntd] = p->a[i];
			else
			{
				p->a[i - (R - L + 1)] = p->a[i];
			}
		}
	}
	p->last -= R - L + 1;
	for (int i = cntd; i >= 1; i--)
	{
		push(tail);
		tail->pb(d[i]);
		check(tail);
	}
}
void print()
{
	node *p1 = head;
	while (p1)
	{
		push(p1);
		//		printf("ST:: ");
		for (int i = 1; i <= p1->last; i++)
		{
			printf("%d ", p1->a[i]);
		}
		p1 = p1->next;
	}
	cout << endl;
}
bool check2(node *p)
{
	if (p == NULL)
		return false;
	if (p->next == NULL)
		return false;
	if (p->last + p->next->last < 2 * len)
		return true;
	return false;
}
void merge(node *p1, node *p2)
{
	//	printf("merge::\n");
	//	print();
	push(p1);
	push(p2);
	for (int i = 1; i <= p2->last; i++)
		p1->pb(p2->a[i]);
	if (p2->next)
	{
		p2->next->pre = p1;
	}
	p1->next = p2->next;
	if (tail == p2)
		tail = p1;
	//	print();
}
inline int read()
{
	int x = 0, f = 1;
	char ch = getchar();
	while (ch < '0' || ch > '9')
	{
		if (ch == '-')
			f = -1;
		ch = getchar();
	}
	while (ch >= '0' && ch <= '9')
		x = x * 10 + ch - '0', ch = getchar();
	return x * f;
}

int main()
{
	//	scanf("%d%d",&n,&m);
	n = read();
	m = read();
	head = tail = &pool[++cnt];
	for (int i = 1; i <= n; i++)
	{
		tail->pb(i);
		check(tail);
	}
	node *p1, *p2, *p3, *p4;
	int l, r, suml, sumr;
	for (int i = 1; i <= m; i++)
	{
		//		scanf("%d%d",&l,&r);
		l = read();
		r = read();
		p1 = head;
		suml = p1->last;
		while (suml < l)
		{
			p1 = p1->next;
			suml += p1->last;
		}
		p2 = head;
		sumr = p2->last;
		while (sumr < r)
		{
			p2 = p2->next;
			sumr += p2->last;
		}
		//		printf("%d %d\n",p1->a[1],p2->a[1]);
		if (p1 == p2)
		{
			pushb(p1, suml, l, r);
		}
		else
		{
			pushb(p2, sumr, sumr - p2->last + 1, r);
			p3 = p2;
			p2 = p2->pre;
			while (p2 != p1)
			{
				tail->next = p2;
				p4 = p2->pre;
				p2->pre = tail;
				p2->next = NULL;
				p2->flag ^= 1;
				tail = p2;
				p2 = p4;
			}
			push(p2);
			pushb(p2, suml, l, suml);
			p1->next = p3;
			p3->pre = p1;
			//			if(p1->last == 0)
			//			{
			//				if(p1->pre) p1->pre->next = p1->next;
			//				if(p1->next) p1->next->pre = p1->pre;
			//				if(head == p1) head = p1->next;
			//			}
			//			p1 = p3;
			//			if(p1->last == 0)
			//			{
			//				if(p1->pre) p1->pre->next = p1->next;
			//				if(p1->next) p1->next->pre = p1->pre;
			//				if(head == p1) head = p1->next;
			//			}
			//				print();
			//			p1 = p1;
			//			while(p1)
			//			{
			//				while(check2(p1) == true)
			//					merge(p1, p1->next);
			//				p1 = p1->next;
			//			}
			if (check2(p1->pre) == true)
				merge(p1->pre, p1);
			else
			{
				if (check2(p1) == true)
					merge(p1, p1->next);
			}
			//			if(check2(p1->next) == true)
			//				merge(p1->next, p1->next->next);
			//			print();
		}
		//		print();
	}
	print();
	//	for(int i=1;i)
	//	for(int i=1)

	return 0;
}
//-9223372036854775807L9223372036854775806
/*
10 8
1 5
3 7
2 5
3 5
1 1
3 10
2 9
3 4
*/
