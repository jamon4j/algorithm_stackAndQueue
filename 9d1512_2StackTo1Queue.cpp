/*
 *	Author:zjj
 *	Date:2014/11/16 15.52
 *  Desc:九度OJ1512：用两个栈来实现一个队列，完成队列的Push和Pop操作。
		队列中的元素为int类型。
 *  Method:入队可直接入栈1；出队则判断栈2为空则将栈1内容导入栈2，然后判断栈2若不为空，则出栈，否则输出-1 
 */
 
#include<stdio.h>
#include<stack>
#include<string.h>
#define SIZE 1001

using namespace std;
stack<int> sPush;//入队栈 
stack<int> sPop;//出队栈

int Push(int x)
{
	sPush.push(x);
	return 1;
}

int Pop()
{
	/*出队栈为空时，将入队栈元素倒入出队栈*/
	if(sPop.empty())
	{
		while(!sPush.empty())
		{
			sPop.push(sPush.top());
			sPush.pop();
		}
	} 
	/*出队栈不为空，输出并弹出栈，否则输出-1*/ 
	if(!sPop.empty())
	{
		printf("%d\n",sPop.top());
		sPop.pop();
	}
	else
	{
		printf("-1\n");
	}
	return 1;
}

int main()
{
	
	char str[10];
	int n;
	while(scanf("%d",&n)!=EOF)
	{
		int x;
		scanf("%s",str);
		if(strcmp(str,"PUSH") == 0)	//strcmp?? 
		{
			scanf("%d",&x);
			Push(x);
		}
		else
		{
			Pop();
		}
	}
	return 1;
}

/*
样例输入：
3
PUSH 10
POP
POP
样例输出：
10
-1
*/
