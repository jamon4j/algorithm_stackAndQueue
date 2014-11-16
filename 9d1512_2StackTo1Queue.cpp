/*
 *	Author:zjj
 *	Date:2014/11/16 15.52
 *  Desc:�Ŷ�OJ1512��������ջ��ʵ��һ�����У���ɶ��е�Push��Pop������
		�����е�Ԫ��Ϊint���͡�
 *  Method:��ӿ�ֱ����ջ1���������ж�ջ2Ϊ����ջ1���ݵ���ջ2��Ȼ���ж�ջ2����Ϊ�գ����ջ���������-1 
 */
 
#include<stdio.h>
#include<stack>
#include<string.h>
#define SIZE 1001

using namespace std;
stack<int> sPush;//���ջ 
stack<int> sPop;//����ջ

int Push(int x)
{
	sPush.push(x);
	return 1;
}

int Pop()
{
	/*����ջΪ��ʱ�������ջԪ�ص������ջ*/
	if(sPop.empty())
	{
		while(!sPush.empty())
		{
			sPop.push(sPush.top());
			sPush.pop();
		}
	} 
	/*����ջ��Ϊ�գ����������ջ���������-1*/ 
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
�������룺
3
PUSH 10
POP
POP
���������
10
-1
*/
