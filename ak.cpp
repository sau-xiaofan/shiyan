#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>
#include<windows.h>
int main()
{
	printf("************************************************************************\n");	Sleep(60);
	printf("***********此计算器支持加，减，乘，除，开平方，取倒数，以及括号*********\n");	Sleep(60);
	printf("zifu这个字符串为后缀表达式，如果想检验除后缀表达式请把/*和*/删除即可检验\n");	Sleep(60);
	printf("****************支持四则运算，并且考虑括号以及乘除优先级****************\n");	Sleep(60);
	printf("******************如果要加请输入+，如果要减请输入-**********************\n");	Sleep(60);
	printf("******************如果要乘请输入*，如果要除请输入/**********************\n");	Sleep(60);
	printf("***********注：输入的括号一定要是英文的()!!!输入记得调成英文************\n");	Sleep(60);
	printf("***********如果要开平方请输入数#，如果要取倒数请输入数$*****************\n");	Sleep(60);
	printf("*******************例如(1.5+20)*10+(9+1)/5,5#,9$************************\n");	Sleep(60);
	printf("***********************如果测试结束请点击右上角的X**********************\n");	Sleep(60);
	printf("*****************************祝您使用愉快！*****************************\n");	Sleep(60);
	printf("************************************************************************\n");	Sleep(60);
	while(1)
	{
		double i=0,shuzi[100]={0},zhan1[100]={0},shuzi1=0,shuzi2=0,y=1,u;//shuzi数组储存数字,zhan1为数字栈；
		int n,m,d=0,k=0,x=-1,c=0;
		char str[100]={0},zifu[100]={0},zhan2[100]={0};//zifu数组储存字符，zhan2为字符栈；
		scanf("%s",str);//str为输入计算的长数列；
		int len=strlen(str);
		char*p=str;//方便提取每一个字符；
		n=-1;//设置初始栈为空；
		m=0;
		while(1)//中缀转后缀表达式；
		{
			if(*p>='0'&&*p<='9')//遇到数；
			{
				i*=10;
				i+=*p-'0';
				m=1;
			}
			else
			{
				if(*p=='$')//取倒数
				{
					zhan1[0]=1/i;
					break;
				}
				if(*p=='#')//开平方
				{
					zhan1[0]=sqrt(i);
					break;
				}
				if(m==1&&*p=='.')//考虑小数
				{
					p=p+1;
					while(*p>='0'&&*p<='9')
					{
						y/=10;
						i+=(*p-'0')*y;
						p++;
					}
					if(*p=='$')//取倒数
					{
						zhan1[0]=1/i;
						break;
					}
					if(*p=='#')//开平方
					{
						zhan1[0]=sqrt(i);
						break;
					}
					shuzi[d]=i;
					zifu[d]='@';
					d++;
					m=0;
					i=0;
					y=1;
				}
				if(m==1&&*p!='.')//输出数
				{
					shuzi[d]=i;
					zifu[d]='@';
					d++;
					m=0;
					i=0;
				}
				if(k>len)//字符串已结束
				{
					while(n>-1)
					{
						zifu[d++]=zhan2[n--];
					}
					/*for(int l=0;l<=d;l++)//检验后缀表达式
					{
						if(zifu[l]=='@') 
							printf("%g ",shuzi[l]);
						else
							printf("%c ",zifu[l]);
					}*/
					break;
				}
				else//字符串没结束，遇到符号 
				{
					if(n==-1||*p=='(')//栈为空或遇到左括号入栈
						zhan2[++n]=*p;
					else
					if(*p==')'&&n>-1)//遇到右括号
					{
						while(zhan2[n]!='('&&n>-1)//输出栈顶元素，直到遇到左括号
						{
							zifu[d++]=zhan2[n--];
						}
						--n;
					}
					else
					if((*p=='*'||*p=='/')&&n>-1)//遇到乘除
					{
						while((zhan2[n]=='*'||zhan2[n]=='/')&&n>-1)//输出优先级大于乘除的符号出栈
						{
							zifu[d++]=zhan2[n--];
						}
						zhan2[++n]=*p;//新符号入栈
					}
					else
					if((*p=='+'||*p=='-')&&n>-1)//遇到加减
					{
						while(zhan2[n]!='('&&n>-1)//逐个输出栈顶元素
						{
							zifu[d++]=zhan2[n--];
						}
						zhan2[++n]=*p;//不为'（‘时入栈
					}
				}
			}
			p++;
			k++;
		}
		//后缀表达式求值
		for(int b=0;b<d;b++)
		{
			if(zifu[b]=='@')
				zhan1[++x]=shuzi[b];
			else
			{
				shuzi1=zhan1[x];
				shuzi2=zhan1[--x];
				switch(zifu[b])
				{
					case'+':zhan1[x]=shuzi1+shuzi2;break;
					case'-':zhan1[x]=shuzi2-shuzi1;break;
					case'*':zhan1[x]=shuzi1*shuzi2;break;
					case'/':zhan1[x]=shuzi2/shuzi1;
								if(shuzi1==0)
								{
									printf("Error!");
								}
									break;
				}
			}
		}
		printf("最终的得数为%g\n请继续输入您要测试的式子\n",zhan1[0]);//输出结果
	}
	system("pause");
	return 0;
}
