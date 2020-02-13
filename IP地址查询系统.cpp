#include<stdio.h>

#include<string.h>

#include<time.h> 

#include<stdlib.h>

#include<ctype.h> 

#define size 586177

void menu();//菜单界面 

void single_ip();//单个IP地址的查询

void multiple_ip();//多个IP地址的查询

void interval_ip();//IP地址段的查询

void special_inquire(int sign);//单个IP地址的指定内容查询 

void mul_special_inquiry(int option,int sign);//多个IP地址的指定内容查询 

struct ip{
	char sp[30];            //储存ip.txt文件起始ip的字符数组 
	char ep[30];            //储存ip.txt文件终止ip的字符数组 
	char country[30]; 	    //储存ip.txt文件某个IP段对应的'国家'信息的字符数组
	char area[30];		    //储存ip.txt文件某个IP段对应的'区域'信息的字符数组
	char province[30];      //储存ip.txt文件某个IP段对应的'省份'信息的字符数组
	char city[30];          //储存ip.txt文件某个IP段对应的'城市'信息的字符数组
	char isp[30];           //储存ip.txt文件某个IP段对应的'ISP'信息的字符数组
	int sp_a;				//储存ip.txt文件起始IP的a参数的整型变量 
	int sp_b;				//储存ip.txt文件起始IP的b参数的整型变量 
	int sp_c;				//储存ip.txt文件起始IP的c参数的整型变量 
	int sp_d;				//储存ip.txt文件起始IP的d参数的整型变量 
	int ep_a;				//储存ip.txt文件终止IP的a参数的整型变量 
	int ep_b;				//储存ip.txt文件终止IP的b参数的整型变量 
	int ep_c;				//储存ip.txt文件终止IP的c参数的整型变量  
	int ep_d;				//储存ip.txt文件终止IP的d参数的整型变量 
}IP[size];					//定义一个结构体数组储存起始地址、结束地址以及对应的国家、区域、省份、城市、ISP 信息 

int main()//主函数 
{
	int i,j=0,h=0,flag=0,x,num,len,m;
	FILE *fp; 
	long location;
	char *buffer;
	system("color 2F"); //改变界面背景及字体颜色 8灰，4红 
	/*主界面*/
	printf("=========================================================================\n");
	printf("#                                                                       #\n");
	printf("#                      欢迎进入IP地址查询系统                           #\n");
	printf("#                                                                       #\n");
	printf("=========================================================================\n\n");
	//将IP地址txt文件转入内存生成IP库以便后续的查询 
	fp=fopen("D:\\ip查询\\ip_2.txt","rb");
	
	if(NULL==fp)//判断文件是否打开成功 
	{
		printf("File failed to open\n");
		exit(1);
	}
	                                
	fseek(fp,0,SEEK_END);//移动文件读写指针至文件末尾 
	
	location=ftell(fp);//返回当前文件指针的位置（此处在文件末尾处），即获取文件的大小  
	
	rewind(fp);//设置文件度读写指针位置至文件开头，即复原操作 
	
	buffer=(char *)malloc(location+1);//分配该文件所需内存并获取其首地址 
	
	memset(buffer,0,location+1);//将该内存内的内容清零 
	
	if (NULL ==buffer)//检验内存是否分配成功 
	{
	printf("Memory malloc failed.\n");
	exit(1);
	}
	
	fread(buffer,sizeof(char),location,fp);
	
	fclose(fp);	//关闭文件
	
	for(i=0;i<location;i++)//遍历内存中导入的txt文件 
	{
		if(buffer[i]=='|')//以'|'为分隔符分别将起始地址、结束地址、国家、区域、省份、城市、ISP
		{                 //赋值给结构体中对应的成员 
			flag+=1;
			if(buffer[i]=='|'&&flag==1)//起始IP的赋值 
			{
				for(j,x=0;j<i;j++)
				{
					IP[h].sp[x]=buffer[j];
					x++;
				}
				j=i+1;
			}
			
			if(buffer[i]=='|'&&flag==2)//终止IP的赋值 
			{
				for(j,x=0;j<i;j++)
				{
					IP[h].ep[x]=buffer[j];
					x++;
				}
				j=i+1;
			}
			
			if(buffer[i]=='|'&&flag==3)//IP地址所对应的国家信息的赋值 
			{
				for(j,x=0;j<i;j++)
				{
					IP[h].country[x]=buffer[j];
					x++;
				}
				if(strcmp(IP[h].country,"0")==0)//如果其国家信息为"0"，则将其替换为"未知”
				{
					strcpy(IP[h].country,"未知"); 
				}
				j=i+1;
			}
			
			if(buffer[i]=='|'&&flag==4)//IP地址所对应的地区信息的赋值 
			{
				for(j,x=0;j<i;j++)
				{
					IP[h].area[x]=buffer[j];
					x++;
				}
				if(strcmp(IP[h].area,"0")==0)//如果其地区信息为"0"，则将其替换为"未知”
				{
					strcpy(IP[h].area,"未知"); 
				}
				j=i+1;
			}
			
			if(buffer[i]=='|'&&flag==5)//IP地址所对应的省份信息的赋值 
			{
				for(j,x=0;j<i;j++)
				{
					IP[h].province[x]=buffer[j];
					x++;
				}
				if(strcmp(IP[h].province,"0")==0)//如果其省份信息为"0"，则将其替换为"未知” 
				{
					strcpy(IP[h].province,"未知"); 
				}
				j=i+1;
			}
			
			if(buffer[i]=='|'&&flag==6)//IP地址所对应的城市信息的赋值 
			{
				for(j,x=0;j<i;j++)
				{
					IP[h].city[x]=buffer[j];
					x++;
				}
				if(strcmp(IP[h].city,"0")==0)//如果其城市信息为"0"，则将其替换为"未知”
				{
					strcpy(IP[h].city,"未知");  
				}
				j=i+1;
			}	
		}
		
		if(buffer[i]=='\n') //IP地址所对应的ISP信息的赋值 
		{
			for(j,x=0;j<i;j++)
			{
				IP[h].isp[x]=buffer[j];
				x++;
			}
			if(IP[h].isp[0]=='0')//如果其ISP信息为"0"，则将其替换为"未知”
			{
				strcpy(IP[h].isp,"未知"); 
			}
			j=i+1;
			h++;
			flag=0;
		}	
	}
	strcpy(IP[h].isp,"内网IP");//最后一条起始IP和终止IP对应的ISP信息的赋值
	flag=0;
	x=0;
	num=0;
	for(i=0;i<586177;i++)
	{
		//各个结构体起始IP的a,b,c,d的参数分离 
		for(j=0;j<strlen(IP[i].sp);j++) 
		{
			if(IP[i].sp[j]=='.')
			{
				flag++;
				len=j-x;
			}
			if(IP[i].sp[j]=='.'&&flag==1)//起始IP的参数a的赋值 
			{
				for(m=0;m<len;m++)
				{
					num=10*num+(IP[i].sp[x]-'0');
					x++;
				}
				IP[i].sp_a=num;
				x=j+1;
				num=0;
			}	
			if(IP[i].sp[j]=='.'&&flag==2)//起始IP的参数b的赋值 
			{
				for(m=0;m<len;m++)
				{
					num=10*num+(IP[i].sp[x]-'0');
					x++;
				}
				IP[i].sp_b=num;
				x=j+1;
				num=0;
			}
			if(IP[i].sp[j]=='.'&&flag==3)//起始IP的参数c的赋值 
			{
				for(m=0;m<len;m++)
				{
					num=10*num+(IP[i].sp[x]-'0');
					x++;
				}
				IP[i].sp_c=num;
				x=j+1;
				num=0;
			}
			if(j==strlen(IP[i].sp)-1)//起始IP的参数d的赋值 
			{
				len=j-x+1;
				for(m=0;m<len;m++)
				{
					num=10*num+(IP[i].sp[x]-'0');
					x++;
				}
				IP[i].sp_d=num;
				x=0;
				num=0;
				flag=0;
			}
		}
	}
	x=0;//重置参数 
	flag=0;//重置参数 
	num=0;//重置参数 
	for (i=0;i<586177;i++)
	{
		//终止IP的a,b,c,d的四个参数分离 
		for(j=0;j<strlen(IP[i].ep);j++) 
		{
			if(IP[i].ep[j]=='.')
			{
				flag++;
				len=j-x;
			}
			if(IP[i].ep[j]=='.'&&flag==1)//终止IP的参数a的赋值 
			{
				for(m=0;m<len;m++)
				{
					num=10*num+(IP[i].ep[x]-'0');
					x++;
				}
				IP[i].ep_a=num;
				x=j+1;
				num=0;
			}
			if(IP[i].ep[j]=='.'&&flag==2)//终止IP的参数b的赋值
			{
				for(m=0;m<len;m++)
				{
					num=10*num+(IP[i].ep[x]-'0');
					x++;
				}
				IP[i].ep_b=num;
				x=j+1;
				num=0;
			}
			if(IP[i].ep[j]=='.'&&flag==3)//终止IP的参数c的赋值
			{
				for(m=0;m<len;m++)
				{
					num=10*num+(IP[i].ep[x]-'0');
					x++;
				}
				IP[i].ep_c=num;
				x=j+1;
				num=0;
			}
			if(j==strlen(IP[i].ep)-1)//终止IP的参数d的赋值
			{
				len=j-x+1;
				for(m=0;m<len;m++)
				{
					num=10*num+(IP[i].ep[x]-'0');
					x++;
				}
				IP[i].ep_d=num;
				x=0;
				num=0;
				flag=0;
			}
		}
	}
	while(1)//死循环防止用户输入错误按键 
	{
		menu();//调用菜单函数 
		
		scanf("%d",&x);//用户输入来选择要进行的操作 
		
		getchar();//读掉回车 
		
		/*对于用户所输入的按键进行处理*/
		if(x==4)
		{
			printf("***********************谢谢您的使用，再见！***************************\n");
			break;	
		}	
		
		switch(x)//对于用户输入的不同按键进行对应函数的调用 
		{
			case 1:
				printf("TIP:您的输入格式应为：“1.1.1.1”，按回车键开始查询\n"); 
				single_ip();    //1-单个ip查询 
				break;
			case 2:
				printf("TIP:您的输入格式应为：在输入的每个IP地址后加上回车键，最后按control+z+回车键开始查询\n");
				multiple_ip();  //2-多个ip查询 
				break;
			case 3:
				printf("TIP:您的输入格式应为：“1.1.1.1-2.2.2.2”，按回车键开始查询\n"); 
				interval_ip();  //3-ip段查询 
				break;
			case 4:
				free(buffer);//释放内存 
				printf("***********************谢谢您的使用，再见！***************************\n");
				break;	
			default:
				printf("按键输入错误，请重新输入！\n");
		} 
	} 
	return 0;	
}

void menu()
{
	/**菜单界面的设计**/
	printf("************************请输入所需操作**************************\n");
	printf("$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$\n");
	printf("$                       1.单个IP地址查询                       $\n");
	printf("$                       2.多个IP地址查询                       $\n");
	printf("$                       3.IP地址段查询                         $\n");
	printf("$                       4.退出IP地址查询系统                   $\n");
	printf("$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$\n\n");
	printf("请选择：");
}

void single_ip()
{
	int i,a,b,c,d,a1,b1,c1,d1,a2,b2,c2,d2,sign;
	char option_1,option_3; 
	long start,end;
	double sum;
	printf("请您输入要查询的IP地址：\n");
	while(1)//死循环避免用户输入错误 
	{
		scanf("%d.%d.%d.%d",&a,&b,&c,&d);//用户输入要查询的IP地址 
		getchar();
		if(a<0||b<0||c<0||d<0||a>255||b>255||c>255||d>255)//判断用户输入是否合法 
		{
			printf("您的IP地址输入有误，请重新输入："); 
		}
		else
		{
			start=clock(); 
			for(i=0;i<586177;i++)//遍历所有结构体 
			{
				//判断用户输入IP所在结构体的算法如下：
				a1=a-IP[i].sp_a;
				a2=a-IP[i].ep_a;
				b1=b-IP[i].sp_b;
				b2=b-IP[i].ep_b;
				c1=c-IP[i].sp_c;
				c2=c-IP[i].ep_c;
				d1=d-IP[i].sp_d;
				d2=d-IP[i].ep_d;
				//如果用户输入的IP地址不在该结构体储存的起始ip和终止ip的范围内则跳过接着查找下一个
				if((a1<0)||(a1==0&&b1<0)||(a1==0&&b1==0&&c1<0)||(a1==0&&b1==0&&c1==0&&d1<0)||
				(a2>0)||(a2==0&&b2>0)||(a2==0&&b2==0&&c2>0)||(a2==0&&b2==0&&c2==0&&d2>0))
				{
					continue;
				}
				//如果输入的ip符合该结构体储存的起始ip和终止ip的范围内则标记该结构体的下标，跳出循环 
				else
				{
					sign=i;
					break;
				}
			} 
			end=clock();
			sum=10*(double)(end-start)/CLOCKS_PER_SEC;//计算本次查询运行时间
			printf("请问您需要对指定内容进行查询吗？\n");
			printf("Y:是       N：否\n");
			printf("请选择："); 
			while(1)//死循环避免用户输入不合法按键 
			{
				scanf("%c",&option_1);//用户输入 
				getchar();
				if(toupper(option_1)=='Y'||option_1=='Y')//保证用户输入大小写的'Y'均可 
				{
					special_inquire(sign);	//调用单个ip指定内容查询函数
					printf("quiry time: %f ms\n",sum);//输出本次查询运行时间
					system("pause");
					printf("\n");
					break;
				} 
				else if(toupper(option_1)=='N'||option_1=='N')//保证用户输入大小写的'N'均可 
				{                                             //用户不进行指定内容查询，直接输出所有对应信息
					printf("★★★★★★★★★★★★★★★★★★★★★★★★★★★★★★★★★★\n");
		   			printf("★                      您的查询结果如下                          ★\n"); 
					printf("★★★★★★★★★★★★★★★★★★★★★★★★★★★★★★★★★★\n");
					printf("国家：%s   省份：%s   城市：%s   ISP：%s\n",IP[sign].country,IP[sign].province,IP[sign].city,IP[sign].isp); //输出ip对应信息 
					printf("quiry time: %f ms      \n",sum);//输出查询运行时间
					printf("★★★★★★★★★★★★★★★★★★★★★★★★★★★★★★★★★★\n");
					system("pause"); 
					printf("\n"); 
					printf("请问您是否需要保存？\n");//询问用户是否需要保存 
					printf("Y:是       N：否\n");
					printf("请选择："); 
					while(1)//死循环避免用户输入不合法按键 
					{
						scanf("%c",&option_3);
						getchar(); 
						if(toupper(option_3)=='Y'||option_3=='Y')//保证用户输入大小写的'Y'均可 
						{
							FILE *fp;
							fp=fopen("D:\\picture_and_text\\z.txt","a+");
							if(NULL==fp)//判断文件是否打开成功 
							{
								printf("File failed to open\n");
								exit(1);
							}
							fprintf(fp,"%d.%d.%d.%d               ",a,b,c,d);
							fprintf(fp,"国家：%s      省份：%s      城市：%s      运营商：%s      \n",IP[sign].country,IP[sign].province,IP[sign].city,IP[sign].isp);
							fclose(fp);
							printf("信息保存成功！\n\n\n");
							break;
						} 
						else if(toupper(option_3)=='N'||option_3=='N')//保证用户输入大小写的'N'均可
						{                                            
							printf("本次查询结束！\n\n\n"); //如果用户不保存则结束本次查询 
							break;
						} 
						else//用户输入不合法，提示用户重新输入
						{
							printf("您的输入有误，请重新输入:");
						} 
					}
					break;
				} 
				else//用户输入不合法，提示用户重新输入 
				{
					printf("您的输入有误，请重新输入：");
				} 
			}
			break; //查询结束跳出死循环 
		}
	}
}

void multiple_ip() 
{
	int i,a[100000],b[100000],c[100000],d[100000],a1,b1,c1,d1,a2,b2,c2,d2,sign[100000],x,count=0,option_2,h=0;
	char option_1,option_3; 
	long start,end;
	double sum;
	printf("请您输入要查询的IP地址：\n");
	while(scanf("%d.%d.%d.%d",&a[count],&b[count],&c[count],&d[count])!=EOF)//利用四个数组分别对用户输入的多个IP地址 
	{																		//的四个参数a,b,c,d进行储存 
		getchar();
		count++;//计下用户输入的IP地址的个数 
	} 
	printf("请问您需要对指定内容进行查询吗？\n");
	printf("Y:是       N：否\n");
	printf("请选择：");
	while(1)//死循环避免用户输入不合法按键 
	{
		scanf("%c",&option_1); 
		getchar();
		if(toupper(option_1)=='Y'||option_1=='Y')//保证用户输入大小写的'Y'均可 
		{
			printf("请指定您要查询的内容：\n");
			printf("1.国家     2.省份     3.城市       4.运营商\n");
			printf("请输入：");
			while(1)
			{
				scanf("%d",&option_2);
				getchar();
				if(option_2==1||option_2==2||option_2==3||option_2==4)
				{
					printf("★★★★★★★★★★★★★★★★★★★★★★★★★★★★★★★★★★\n");
		   			printf("★                    您的查询结果如下                            ★\n"); 
					printf("★★★★★★★★★★★★★★★★★★★★★★★★★★★★★★★★★★\n");
					start=clock(); 
					for(x=0;x<count;x++)
					{
						if(a[x]<0||b[x]<0||c[x]<0||d[x]<0||a[x]>255||b[x]>255||c[x]>255||d[x]>255)//判断用户输入是否合法 
						{
							printf("%d.%d.%d.%d     您输入了一个无效IP!\n",a[x],b[x],c[x],d[x]); 
						}
						else
						{
							
							for(i=0;i<586177;i++)
							{
								a1=a[x]-IP[i].sp_a;
								a2=a[x]-IP[i].ep_a;
								b1=b[x]-IP[i].sp_b;
								b2=b[x]-IP[i].ep_b;
								c1=c[x]-IP[i].sp_c;
								c2=c[x]-IP[i].ep_c;
								d1=d[x]-IP[i].sp_d;
								d2=d[x]-IP[i].ep_d;
								if((a1<0)||(a1==0&&b1<0)||(a1==0&&b1==0&&c1<0)||(a1==0&&b1==0&&c1==0&&d1<0)||
								(a2>0)||(a2==0&&b2>0)||(a2==0&&b2==0&&c2>0)||(a2==0&&b2==0&&c2==0&&d2>0))
								{
									continue;
								}
								else
								{
									sign[h]=i;//定义一个变量标记该IP对应的正确的结构体的下标以便后续的输出；
									h++;
									break; 
								}
							} 
							printf("%d.%d.%d.%d     ",a[x],b[x],c[x],d[x]);//输出用户输入的IP地址 
							mul_special_inquiry(option_2,sign[h-1]);//调用多个ip地址指定查询函数	
						}
					}
					end=clock();
					sum=10*(double)(end-start)/CLOCKS_PER_SEC;//计算本次查询运行时间
					printf("quiry time: %f ms      \n",sum);//输出本次查询运行时间
					printf("★★★★★★★★★★★★★★★★★★★★★★★★★★★★★★★★★★\n");
					system("pause");
					printf("\n");
					break;
				}
				else//用户输入不合法，提示用户重新输入 
				{
					printf("您的输入错误，请重新输入：");
				} 
			}
			break;		
		}		 
		else if(toupper(option_1)=='N'||option_1=='N')
		{
			printf("★★★★★★★★★★★★★★★★★★★★★★★★★★★★★★★★★★\n");
			printf("★                       您的查询结果如下                         ★\n"); 
			printf("★★★★★★★★★★★★★★★★★★★★★★★★★★★★★★★★★★\n");
			for(x=0;x<count;x++)
			{
				if(a[x]<0||b[x]<0||c[x]<0||d[x]<0||a[x]>255||b[x]>255||c[x]>255||d[x]>255)//判断用户输入是否合法 
				{
					printf("%d.%d.%d.%d     您输入了一个无效IP!\n",a[x],b[x],c[x],d[x]); 
				}
				else
				{
					start=clock(); 
					for(i=0;i<586177;i++)
					{
						a1=a[x]-IP[i].sp_a;
						a2=a[x]-IP[i].ep_a;
						b1=b[x]-IP[i].sp_b;
						b2=b[x]-IP[i].ep_b;
						c1=c[x]-IP[i].sp_c;
						c2=c[x]-IP[i].ep_c;
						d1=d[x]-IP[i].sp_d;
						d2=d[x]-IP[i].ep_d;
						if((a1<0)||(a1==0&&b1<0)||(a1==0&&b1==0&&c1<0)||(a1==0&&b1==0&&c1==0&&d1<0)||
						(a2>0)||(a2==0&&b2>0)||(a2==0&&b2==0&&c2>0)||(a2==0&&b2==0&&c2==0&&d2>0))
						{
							continue;
						}
						else
						{
							sign[h]=i;//定义一个变量标记该IP对应的正确的结构体的下标以便后续的输出；
							h++;
							break; 
						}
					} 
					//输出用户输入的ip及其对应的地理信息	
					printf("%d.%d.%d.%d     国家：%s   省份：%s   城市：%s   运营商：%s\n",a[x],b[x],c[x],d[x],IP[sign[h-1]].country,IP[sign[h-1]].province,IP[sign[h-1]].city,IP[sign[h-1]].isp); //输出ip对应信息 
				}
			}	
			end=clock();
			sum=10*(double)(end-start)/CLOCKS_PER_SEC;//计算本次查询运行时间
			printf("quiry time: %f ms      \n",sum);//输出本次查询运行时间
			printf("★★★★★★★★★★★★★★★★★★★★★★★★★★★★★★★★★★\n");
			system("pause");
			printf("\n");
			printf("请问您是否需要保存？\n");//询问用户是否需要保存 
			printf("Y:是       N：否\n");
			printf("请选择："); 
			while(1)//死循环避免用户输入不合法按键 
			{
				scanf("%c",&option_3);
				getchar(); 
				if(toupper(option_3)=='Y'||option_3=='Y')//保证用户输入大小写的'Y'均可 
				{
					FILE *fp;
					fp=fopen("D:\\picture_and_text\\z.txt","a+");//打开文件夹便于后续的保存 
					if(NULL==fp)//判断文件是否打开成功 
					{
						printf("File failed to open\n");
						exit(1);
					}
					for(i=0;i<count;i++)
					{
						fprintf(fp,"%d.%d.%d.%d               ",a[i],b[i],c[i],d[i]);//逐个将IP地址写入文件夹以便保存
						fprintf(fp,"国家：%s      省份：%s      城市：%s      运营商：%s      \n",IP[sign[i]].country,IP[sign[i]].province,IP[sign[i]].city,IP[sign[i]].isp);
					}
					fclose(fp);
					printf("信息保存成功！\n\n\n");
					break;
				} 
				else if(toupper(option_3)=='N'||option_3=='N')//保证用户输入大小写的'N'均可
				{                                            
					printf("本次查询结束！\n\n\n"); //如果用户不保存则结束本次查询 
					break;
				} 
				else//用户输入不合法，提示用户重新输入
				{
					printf("您的输入有误，请重新输入:");
				} 
			}
			break; 
		} 
		else//用户输入不合法，提示用户重新输入 
		{
			printf("您的输入有误，请重新新输入:");
		}
	}  
}

void interval_ip()
{
	int i,a,b,c,d,a1,b1,c1,d1,a2,b2,c2,d2,sign1,sign2,a_1,b_1,c_1,d_1,x;
	char option_1,option_3;
	int option_2; 
	long start,end;
	double sum;
	printf("请您输入要查询的IP地址段：\n");
	while(1)//死循环避免用户输入错误 
	{
		scanf("%d.%d.%d.%d-%d.%d.%d.%d",&a,&b,&c,&d,&a_1,&b_1,&c_1,&d_1);//用户输入一个IP地址区间 
		getchar();
		a1=a_1-a; 
		b1=b_1-b;
		c1=c_1-c;
		d1=d_1-d;
		if(a<0||b<0||c<0||d<0||a>255||b>255||c>255||d>255||a_1<0||b_1<0||c_1<0||d_1<0||a_1>255||b_1>255||c_1>255||d_1>255||
		(a1<0)||(a1==0&&b1<0)||(a1==0&&b1==0&&c1<0)||(a1==0&&b1==0&&c1==0&&d1<0))//判断用户输入是否合法 
		{
			printf("您的IP地址输入有误，请重新输入："); //判断用户输入是否合法 
		}
		else
		{
			start=clock(); 
			for(i=0;i<586177;i++)
			{
				a1=a-IP[i].sp_a;
				a2=a-IP[i].ep_a;
				b1=b-IP[i].sp_b;
				b2=b-IP[i].ep_b;
				c1=c-IP[i].sp_c;
				c2=c-IP[i].ep_c;
				d1=d-IP[i].sp_d;
				d2=d-IP[i].ep_d;
				if((a1<0)||(a1==0&&b1<0)||(a1==0&&b1==0&&c1<0)||(a1==0&&b1==0&&c1==0&&d1<0)||
				(a2>0)||(a2==0&&b2>0)||(a2==0&&b2==0&&c2>0)||(a2==0&&b2==0&&c2==0&&d2>0))
				{
					continue;
				}
				else
				{
					sign1=i;//标记用户输入的起始ip所在的结构体的下标 
					break; 
				}
			} 
			for(i=0;i<586177;i++)
			{
				a1=a_1-IP[i].sp_a;
				a2=a_1-IP[i].ep_a;
				b1=b_1-IP[i].sp_b;
				b2=b_1-IP[i].ep_b;
				c1=c_1-IP[i].sp_c;
				c2=c_1-IP[i].ep_c;
				d1=d_1-IP[i].sp_d;
				d2=d_1-IP[i].ep_d;
				if((a1<0)||(a1==0&&b1<0)||(a1==0&&b1==0&&c1<0)||(a1==0&&b1==0&&c1==0&&d1<0)||
				(a2>0)||(a2==0&&b2>0)||(a2==0&&b2==0&&c2>0)||(a2==0&&b2==0&&c2==0&&d2>0))
				{
					continue;
				}
				else
				{
					sign2=i;//标记用户输入的终止ip所在的结构体的下标 
					break; 
				}
			} 
			printf("请问您需要对指定内容进行查询吗？\n");
			printf("Y:是       N：否\n");
			printf("请选择："); 
			while(1)//死循环避免用户输入不合法按键 
			{
				scanf("%c",&option_1);
				getchar();
				if(toupper(option_1)=='Y'||option_1=='Y')//保证用户输入大小写的'Y'均可 
				{
					printf("请指定您要查询的内容：\n");
					printf("1.国家     2.省份     3.城市       4.运营商\n");
					printf("请输入：");
					while(1)
					{
						scanf("%d",&option_2);//用户选择指定查询的内容 
						getchar();
						if(option_2==1||option_2==2||option_2==3||option_2==4)
						{
							printf("★★★★★★★★★★★★★★★★★★★★★★★★★★★★★★★★★★\n");
							printf("★                      您的查询结果如下                          ★\n"); 
							printf("★★★★★★★★★★★★★★★★★★★★★★★★★★★★★★★★★★\n");
							for(x=sign1;x<=sign2;x++)//遍历用户输入的IP区段所包含的所有结构体 
							{
								if(x==sign1) 
								{
									//特判：判断用户输入的起始IP是否和其包含的第一个结构体的终止IP相等
									if(a==IP[sign1].ep_a&&b==IP[sign1].ep_b&&c==IP[sign1].ep_c&&d==IP[sign1].ep_d)
									{
										printf("%d.%d.%d.%d          ",a,b,c,d);//相等则只输出该结构体的终止IP 
										mul_special_inquiry(option_2,sign1);//输出用户指定的对应该IP的信息 
									}
									else
									{
										printf("%d.%d.%d.%d-%s          ",a,b,c,d,IP[sign1].ep);//不相等则输出用户输入的起始IP到该结构体的终止IP的一个区段 
										mul_special_inquiry(option_2,sign1); //输出用户指定的对应该IP区间的信息 
									} 
								}
								if(x==sign2)
								{
									//特判：判断用户输入的终止IP是否和其包含的第一个结构体的起始IP相等{
									if(a_1==IP[sign2].sp_a&&b_1==IP[sign2].sp_b&&c_1==IP[sign2].sp_c&&d_1==IP[sign2].sp_d)
									{
										printf("%d.%d.%d.%d          ",a_1,b_1,c_1,d_1);//相等则只输出该结构体的起始IP 
										mul_special_inquiry(option_2,sign2);//输出用户指定的对应该IP的信息 
									
									}
									else 
									{
										printf("%s-%d.%d.%d.%d          ",IP[sign2].sp,a_1,b_1,c_1,d_1);//不相等则输出该结构体的起始IP到用户输入的终止IP的一个区段 
										mul_special_inquiry(option_2,sign2); //输出用户指定的对应该IP区间的信息 
									
									}
								}
								if(x>sign1&&x<sign2)
								{
									printf("%s-%s          ",IP[x].sp,IP[x].ep);	//输出IP地址段 
									mul_special_inquiry(option_2,x);//调用'多个ip地址指定查询函数'	
								}
							}
							end=clock();
							sum=10*(double)(end-start)/CLOCKS_PER_SEC;//计算查询运行时间
							printf("quiry time: %f ms      \n",sum);//输出本次查询运行时间
							printf("★★★★★★★★★★★★★★★★★★★★★★★★★★★★★★★★★★\n");
							system("pause"); 
							printf("\n\n"); 
							break;
						}
						else//用户输入不合法，提示用户重新输入 
						{
							printf("您的输入错误，请重新输入：");
						} 	
					}
					break; 
				}		 
				else if(toupper(option_1)=='N'||option_1=='N')//用户不进行指定内容查询 
				{
					printf("★★★★★★★★★★★★★★★★★★★★★★★★★★★★★★★★★★\n");
					printf("★                     您的查询结果如下                           ★\n"); 
					printf("★★★★★★★★★★★★★★★★★★★★★★★★★★★★★★★★★★\n");
					for(x=sign1;x<=sign2;x++)//遍历用户输入的IP段所包含的结构体 
					{
						if(x==sign1) 
						{
							if(a==IP[sign1].ep_a&&b==IP[sign1].ep_b&&c==IP[sign1].ep_c&&d==IP[sign1].ep_d)
							{
								printf("%d.%d.%d.%d        国家：%s    省份：%s    城市：%s    运营商：%s\n",a,b,c,d,IP[sign1].country,IP[sign1].province,IP[sign1].city,IP[sign1].isp);
							}
							else
							{
								printf("%d.%d.%d.%d-%s        国家：%s    省份：%s    城市：%s    运营商：%s\n",a,b,c,d,IP[sign1].ep,IP[sign1].country,IP[sign1].province,IP[sign1].city,IP[sign1].isp);
							}
						} 
						if(x==sign2)
						{
							if(a_1==IP[sign2].sp_a&&b_1==IP[sign2].sp_b&&c_1==IP[sign2].sp_c&&d_1==IP[sign2].sp_d)
							{
								printf("%d.%d.%d.%d        国家：%s    省份：%s    城市：%s    运营商：%s\n",a_1,b_1,c_1,d_1,IP[sign2].country,IP[sign2].province,IP[sign2].city,IP[sign2].isp);
							}
							else 
							{
								printf("%s-%d.%d.%d.%d        国家：%s    省份：%s    城市：%s    运营商：%s\n",IP[sign2].sp,a_1,b_1,c_1,d_1,IP[sign2].country,IP[sign2].province,IP[sign2].city,IP[sign2].isp);
							}
						}
						if(x>sign1&&x<sign2)
						{
							printf("%s-%s        国家：%s    省份：%s    城市：%s    运营商：%s\n",IP[x].sp,IP[x].ep,IP[x].country,IP[x].province,IP[x].city,IP[x].isp);	
						}	
					}
					end=clock();
					sum=10*(double)(end-start)/CLOCKS_PER_SEC;//计算查询运行时间	
					printf("quiry time: %f ms      \n",sum);//输出本次查询运行时间
					printf("★★★★★★★★★★★★★★★★★★★★★★★★★★★★★★★★★★\n");
					system("pause");
					printf("\n\n");
					printf("请问您是否需要保存？\n");//询问用户是否需要保存 
					printf("Y:是       N：否\n");
					printf("请选择："); 
					while(1)//死循环避免用户输入不合法按键 
					{
						scanf("%c",&option_3);
						getchar(); 
						if(toupper(option_3)=='Y'||option_3=='Y')//保证用户输入大小写的'Y'均可 
						{
							FILE *fp;
							fp=fopen("D:\\picture_and_text\\z.txt","a+");
							if(NULL==fp)//判断文件是否打开成功 
							{
								printf("File failed to open\n");
								exit(1);
							}
							for(x=sign1;x<=sign2;x++)//遍历用户输入的IP区段所包含的所有结构体 
							{
								if(x==sign1) 
								{
									//特判：判断用户输入的起始IP是否和其包含的第一个结构体的终止IP相等
									if(a==IP[x].ep_a&&b==IP[x].ep_b&&c==IP[x].ep_c&&d==IP[x].ep_d)
									{
										fprintf(fp,"%d.%d.%d.%d          ",a,b,c,d);//相等则只保存该结构体的终止IP 
										fprintf(fp,"国家：%s      省份：%s      城市：%s      运营商：%s      \n",IP[x].country,IP[x].province,IP[x].city,IP[x].isp);
									}
									else
									{
										fprintf(fp,"%d.%d.%d.%d-%s          ",a,b,c,d,IP[x].ep);//不相等则保存用户输入的起始IP到该结构体的终止IP的一个区段 
										fprintf(fp,"国家：%s      省份：%s      城市：%s      运营商：%s      \n",IP[x].country,IP[x].province,IP[x].city,IP[x].isp);
									}
								}
								if(x==sign2)
								{
									//特判：判断用户输入的终止IP是否和其包含的第一个结构体的起始IP相等{
									if(a_1==IP[x].sp_a&&b_1==IP[x].sp_b&&c_1==IP[x].sp_c&&d_1==IP[x].sp_d)
									{
										fprintf(fp,"%d.%d.%d.%d          ",a_1,b_1,c_1,d_1);//相等则只保存该结构体的起始IP  
										fprintf(fp,"国家：%s      省份：%s      城市：%s      运营商：%s      \n",IP[x].country,IP[x].province,IP[x].city,IP[x].isp);
									}
									else 
									{
										fprintf(fp,"%s-%d.%d.%d.%d          ",IP[x].sp,a_1,b_1,c_1,d_1);//不相等则保存该结构体的起始IP到用户输入的终止IP的一个区段 
										fprintf(fp,"国家：%s      省份：%s      城市：%s      运营商：%s      \n",IP[x].country,IP[x].province,IP[x].city,IP[x].isp);
									} 
								}	
								if(x>sign1&&x<sign2)
								{
									fprintf(fp,"%s-%s          国家：%s      省份：%s      城市：%s      运营商：%s      \n",IP[x].sp,IP[x].ep,IP[x].country,IP[x].province,IP[x].city,IP[x].isp);
								}
							}
							fclose(fp);
							printf("保存信息成功！\n\n\n");
							break;
						} 
						else if(toupper(option_3)=='N'||option_3=='N')//保证用户输入大小写的'N'均可
						{                                            
							printf("本次查询结束！\n\n\n"); //如果用户不保存则结束本次查询 
							break;
						} 
						else//用户输入不合法，提示用户重新输入
						{
							printf("您的输入有误，请重新输入:");
						} 
					}
					break; 
				} 
				else//用户输入不合法，提示用户重新输入 
				{
					printf("您的输入有误，请从新输入:");
				}
			}
			break;
		}
	}
}

void special_inquire(int sign)//参数sign表示用户输入的ip对应的保存着其对应的地理信息的结构体的下标 
{
	int option;
	printf("请指定您要查询的内容：\n");
	//给用户提供四种选择 
	printf("1.国家     2.省份     3.城市       4.运营商\n");
	printf("请输入：");
	while(1)
	{
		scanf("%d",&option);//用户输入 
		getchar();
		//根据用户的输入进行对应的输出 
		if(option==1)
		{
			printf("您的查询结果为：%s\n",IP[sign].country);//输出用户指定的国家信息 
			break;
		} 
		else if(option==2)
		{
			printf("您的查询结果为：%s\n",IP[sign].province);//输出用户指定的省份信息
			break;
		} 
		else if(option==3)
		{
			printf("您的查询结果为：%s\n",IP[sign].city);//输出用户指定的城市信息
			break;
		} 
		else if(option==4)
		{
			printf("您的查询结果为：%s",IP[sign].isp);//输出用户指定的ISP信息
			break;
		} 
		else
		{
			printf("您的输入有误，请重新输入:");
		}	
	} 

} 

void mul_special_inquiry(int option,int sign)//参数sign表示用户输入的ip对应的保存着其对应的地理信息的结构体的下标 
{                                            //参数option表示用户想要指定输出的信息的对应序号  
	switch(option)//根据传入参数的不同分别进行对应的输出 
	{
		case 1://用户输入为 1 ，输出对应的国家信息 
			printf("国家：%s\n",IP[sign].country);
	 		break;
		case 2://用户输入为 2 ，输出对应的国家信息 
			printf("省份：%s\n",IP[sign].province);
			break;
		case 3://用户输入为 3 ，输出对应的国家信息 
			printf("城市：%s\n",IP[sign].city);
			break;
		case 4://用户输入为 4 ，输出对应的国家信息 
			printf("运营商：%s\n",IP[sign].isp);
			break;
		default:
			break;
	}	
} 

