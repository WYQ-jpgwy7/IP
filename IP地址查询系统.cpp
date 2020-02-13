#include<stdio.h>

#include<string.h>

#include<time.h> 

#include<stdlib.h>

#include<ctype.h> 

#define size 586177

void menu();//�˵����� 

void single_ip();//����IP��ַ�Ĳ�ѯ

void multiple_ip();//���IP��ַ�Ĳ�ѯ

void interval_ip();//IP��ַ�εĲ�ѯ

void special_inquire(int sign);//����IP��ַ��ָ�����ݲ�ѯ 

void mul_special_inquiry(int option,int sign);//���IP��ַ��ָ�����ݲ�ѯ 

struct ip{
	char sp[30];            //����ip.txt�ļ���ʼip���ַ����� 
	char ep[30];            //����ip.txt�ļ���ֹip���ַ����� 
	char country[30]; 	    //����ip.txt�ļ�ĳ��IP�ζ�Ӧ��'����'��Ϣ���ַ�����
	char area[30];		    //����ip.txt�ļ�ĳ��IP�ζ�Ӧ��'����'��Ϣ���ַ�����
	char province[30];      //����ip.txt�ļ�ĳ��IP�ζ�Ӧ��'ʡ��'��Ϣ���ַ�����
	char city[30];          //����ip.txt�ļ�ĳ��IP�ζ�Ӧ��'����'��Ϣ���ַ�����
	char isp[30];           //����ip.txt�ļ�ĳ��IP�ζ�Ӧ��'ISP'��Ϣ���ַ�����
	int sp_a;				//����ip.txt�ļ���ʼIP��a���������ͱ��� 
	int sp_b;				//����ip.txt�ļ���ʼIP��b���������ͱ��� 
	int sp_c;				//����ip.txt�ļ���ʼIP��c���������ͱ��� 
	int sp_d;				//����ip.txt�ļ���ʼIP��d���������ͱ��� 
	int ep_a;				//����ip.txt�ļ���ֹIP��a���������ͱ��� 
	int ep_b;				//����ip.txt�ļ���ֹIP��b���������ͱ��� 
	int ep_c;				//����ip.txt�ļ���ֹIP��c���������ͱ���  
	int ep_d;				//����ip.txt�ļ���ֹIP��d���������ͱ��� 
}IP[size];					//����һ���ṹ�����鴢����ʼ��ַ��������ַ�Լ���Ӧ�Ĺ��ҡ�����ʡ�ݡ����С�ISP ��Ϣ 

int main()//������ 
{
	int i,j=0,h=0,flag=0,x,num,len,m;
	FILE *fp; 
	long location;
	char *buffer;
	system("color 2F"); //�ı���汳����������ɫ 8�ң�4�� 
	/*������*/
	printf("=========================================================================\n");
	printf("#                                                                       #\n");
	printf("#                      ��ӭ����IP��ַ��ѯϵͳ                           #\n");
	printf("#                                                                       #\n");
	printf("=========================================================================\n\n");
	//��IP��ַtxt�ļ�ת���ڴ�����IP���Ա�����Ĳ�ѯ 
	fp=fopen("D:\\ip��ѯ\\ip_2.txt","rb");
	
	if(NULL==fp)//�ж��ļ��Ƿ�򿪳ɹ� 
	{
		printf("File failed to open\n");
		exit(1);
	}
	                                
	fseek(fp,0,SEEK_END);//�ƶ��ļ���дָ�����ļ�ĩβ 
	
	location=ftell(fp);//���ص�ǰ�ļ�ָ���λ�ã��˴����ļ�ĩβ����������ȡ�ļ��Ĵ�С  
	
	rewind(fp);//�����ļ��ȶ�дָ��λ�����ļ���ͷ������ԭ���� 
	
	buffer=(char *)malloc(location+1);//������ļ������ڴ沢��ȡ���׵�ַ 
	
	memset(buffer,0,location+1);//�����ڴ��ڵ��������� 
	
	if (NULL ==buffer)//�����ڴ��Ƿ����ɹ� 
	{
	printf("Memory malloc failed.\n");
	exit(1);
	}
	
	fread(buffer,sizeof(char),location,fp);
	
	fclose(fp);	//�ر��ļ�
	
	for(i=0;i<location;i++)//�����ڴ��е����txt�ļ� 
	{
		if(buffer[i]=='|')//��'|'Ϊ�ָ����ֱ���ʼ��ַ��������ַ�����ҡ�����ʡ�ݡ����С�ISP
		{                 //��ֵ���ṹ���ж�Ӧ�ĳ�Ա 
			flag+=1;
			if(buffer[i]=='|'&&flag==1)//��ʼIP�ĸ�ֵ 
			{
				for(j,x=0;j<i;j++)
				{
					IP[h].sp[x]=buffer[j];
					x++;
				}
				j=i+1;
			}
			
			if(buffer[i]=='|'&&flag==2)//��ֹIP�ĸ�ֵ 
			{
				for(j,x=0;j<i;j++)
				{
					IP[h].ep[x]=buffer[j];
					x++;
				}
				j=i+1;
			}
			
			if(buffer[i]=='|'&&flag==3)//IP��ַ����Ӧ�Ĺ�����Ϣ�ĸ�ֵ 
			{
				for(j,x=0;j<i;j++)
				{
					IP[h].country[x]=buffer[j];
					x++;
				}
				if(strcmp(IP[h].country,"0")==0)//����������ϢΪ"0"�������滻Ϊ"δ֪��
				{
					strcpy(IP[h].country,"δ֪"); 
				}
				j=i+1;
			}
			
			if(buffer[i]=='|'&&flag==4)//IP��ַ����Ӧ�ĵ�����Ϣ�ĸ�ֵ 
			{
				for(j,x=0;j<i;j++)
				{
					IP[h].area[x]=buffer[j];
					x++;
				}
				if(strcmp(IP[h].area,"0")==0)//����������ϢΪ"0"�������滻Ϊ"δ֪��
				{
					strcpy(IP[h].area,"δ֪"); 
				}
				j=i+1;
			}
			
			if(buffer[i]=='|'&&flag==5)//IP��ַ����Ӧ��ʡ����Ϣ�ĸ�ֵ 
			{
				for(j,x=0;j<i;j++)
				{
					IP[h].province[x]=buffer[j];
					x++;
				}
				if(strcmp(IP[h].province,"0")==0)//�����ʡ����ϢΪ"0"�������滻Ϊ"δ֪�� 
				{
					strcpy(IP[h].province,"δ֪"); 
				}
				j=i+1;
			}
			
			if(buffer[i]=='|'&&flag==6)//IP��ַ����Ӧ�ĳ�����Ϣ�ĸ�ֵ 
			{
				for(j,x=0;j<i;j++)
				{
					IP[h].city[x]=buffer[j];
					x++;
				}
				if(strcmp(IP[h].city,"0")==0)//����������ϢΪ"0"�������滻Ϊ"δ֪��
				{
					strcpy(IP[h].city,"δ֪");  
				}
				j=i+1;
			}	
		}
		
		if(buffer[i]=='\n') //IP��ַ����Ӧ��ISP��Ϣ�ĸ�ֵ 
		{
			for(j,x=0;j<i;j++)
			{
				IP[h].isp[x]=buffer[j];
				x++;
			}
			if(IP[h].isp[0]=='0')//�����ISP��ϢΪ"0"�������滻Ϊ"δ֪��
			{
				strcpy(IP[h].isp,"δ֪"); 
			}
			j=i+1;
			h++;
			flag=0;
		}	
	}
	strcpy(IP[h].isp,"����IP");//���һ����ʼIP����ֹIP��Ӧ��ISP��Ϣ�ĸ�ֵ
	flag=0;
	x=0;
	num=0;
	for(i=0;i<586177;i++)
	{
		//�����ṹ����ʼIP��a,b,c,d�Ĳ������� 
		for(j=0;j<strlen(IP[i].sp);j++) 
		{
			if(IP[i].sp[j]=='.')
			{
				flag++;
				len=j-x;
			}
			if(IP[i].sp[j]=='.'&&flag==1)//��ʼIP�Ĳ���a�ĸ�ֵ 
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
			if(IP[i].sp[j]=='.'&&flag==2)//��ʼIP�Ĳ���b�ĸ�ֵ 
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
			if(IP[i].sp[j]=='.'&&flag==3)//��ʼIP�Ĳ���c�ĸ�ֵ 
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
			if(j==strlen(IP[i].sp)-1)//��ʼIP�Ĳ���d�ĸ�ֵ 
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
	x=0;//���ò��� 
	flag=0;//���ò��� 
	num=0;//���ò��� 
	for (i=0;i<586177;i++)
	{
		//��ֹIP��a,b,c,d���ĸ��������� 
		for(j=0;j<strlen(IP[i].ep);j++) 
		{
			if(IP[i].ep[j]=='.')
			{
				flag++;
				len=j-x;
			}
			if(IP[i].ep[j]=='.'&&flag==1)//��ֹIP�Ĳ���a�ĸ�ֵ 
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
			if(IP[i].ep[j]=='.'&&flag==2)//��ֹIP�Ĳ���b�ĸ�ֵ
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
			if(IP[i].ep[j]=='.'&&flag==3)//��ֹIP�Ĳ���c�ĸ�ֵ
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
			if(j==strlen(IP[i].ep)-1)//��ֹIP�Ĳ���d�ĸ�ֵ
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
	while(1)//��ѭ����ֹ�û�������󰴼� 
	{
		menu();//���ò˵����� 
		
		scanf("%d",&x);//�û�������ѡ��Ҫ���еĲ��� 
		
		getchar();//�����س� 
		
		/*�����û�������İ������д���*/
		if(x==4)
		{
			printf("***********************лл����ʹ�ã��ټ���***************************\n");
			break;	
		}	
		
		switch(x)//�����û�����Ĳ�ͬ�������ж�Ӧ�����ĵ��� 
		{
			case 1:
				printf("TIP:���������ʽӦΪ����1.1.1.1�������س�����ʼ��ѯ\n"); 
				single_ip();    //1-����ip��ѯ 
				break;
			case 2:
				printf("TIP:���������ʽӦΪ���������ÿ��IP��ַ����ϻس��������control+z+�س�����ʼ��ѯ\n");
				multiple_ip();  //2-���ip��ѯ 
				break;
			case 3:
				printf("TIP:���������ʽӦΪ����1.1.1.1-2.2.2.2�������س�����ʼ��ѯ\n"); 
				interval_ip();  //3-ip�β�ѯ 
				break;
			case 4:
				free(buffer);//�ͷ��ڴ� 
				printf("***********************лл����ʹ�ã��ټ���***************************\n");
				break;	
			default:
				printf("��������������������룡\n");
		} 
	} 
	return 0;	
}

void menu()
{
	/**�˵���������**/
	printf("************************�������������**************************\n");
	printf("$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$\n");
	printf("$                       1.����IP��ַ��ѯ                       $\n");
	printf("$                       2.���IP��ַ��ѯ                       $\n");
	printf("$                       3.IP��ַ�β�ѯ                         $\n");
	printf("$                       4.�˳�IP��ַ��ѯϵͳ                   $\n");
	printf("$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$\n\n");
	printf("��ѡ��");
}

void single_ip()
{
	int i,a,b,c,d,a1,b1,c1,d1,a2,b2,c2,d2,sign;
	char option_1,option_3; 
	long start,end;
	double sum;
	printf("��������Ҫ��ѯ��IP��ַ��\n");
	while(1)//��ѭ�������û�������� 
	{
		scanf("%d.%d.%d.%d",&a,&b,&c,&d);//�û�����Ҫ��ѯ��IP��ַ 
		getchar();
		if(a<0||b<0||c<0||d<0||a>255||b>255||c>255||d>255)//�ж��û������Ƿ�Ϸ� 
		{
			printf("����IP��ַ�����������������룺"); 
		}
		else
		{
			start=clock(); 
			for(i=0;i<586177;i++)//�������нṹ�� 
			{
				//�ж��û�����IP���ڽṹ����㷨���£�
				a1=a-IP[i].sp_a;
				a2=a-IP[i].ep_a;
				b1=b-IP[i].sp_b;
				b2=b-IP[i].ep_b;
				c1=c-IP[i].sp_c;
				c2=c-IP[i].ep_c;
				d1=d-IP[i].sp_d;
				d2=d-IP[i].ep_d;
				//����û������IP��ַ���ڸýṹ�崢�����ʼip����ֹip�ķ�Χ�����������Ų�����һ��
				if((a1<0)||(a1==0&&b1<0)||(a1==0&&b1==0&&c1<0)||(a1==0&&b1==0&&c1==0&&d1<0)||
				(a2>0)||(a2==0&&b2>0)||(a2==0&&b2==0&&c2>0)||(a2==0&&b2==0&&c2==0&&d2>0))
				{
					continue;
				}
				//��������ip���ϸýṹ�崢�����ʼip����ֹip�ķ�Χ�����Ǹýṹ����±꣬����ѭ�� 
				else
				{
					sign=i;
					break;
				}
			} 
			end=clock();
			sum=10*(double)(end-start)/CLOCKS_PER_SEC;//���㱾�β�ѯ����ʱ��
			printf("��������Ҫ��ָ�����ݽ��в�ѯ��\n");
			printf("Y:��       N����\n");
			printf("��ѡ��"); 
			while(1)//��ѭ�������û����벻�Ϸ����� 
			{
				scanf("%c",&option_1);//�û����� 
				getchar();
				if(toupper(option_1)=='Y'||option_1=='Y')//��֤�û������Сд��'Y'���� 
				{
					special_inquire(sign);	//���õ���ipָ�����ݲ�ѯ����
					printf("quiry time: %f ms\n",sum);//������β�ѯ����ʱ��
					system("pause");
					printf("\n");
					break;
				} 
				else if(toupper(option_1)=='N'||option_1=='N')//��֤�û������Сд��'N'���� 
				{                                             //�û�������ָ�����ݲ�ѯ��ֱ��������ж�Ӧ��Ϣ
					printf("�����������������������������������\n");
		   			printf("��                      ���Ĳ�ѯ�������                          ��\n"); 
					printf("�����������������������������������\n");
					printf("���ң�%s   ʡ�ݣ�%s   ���У�%s   ISP��%s\n",IP[sign].country,IP[sign].province,IP[sign].city,IP[sign].isp); //���ip��Ӧ��Ϣ 
					printf("quiry time: %f ms      \n",sum);//�����ѯ����ʱ��
					printf("�����������������������������������\n");
					system("pause"); 
					printf("\n"); 
					printf("�������Ƿ���Ҫ���棿\n");//ѯ���û��Ƿ���Ҫ���� 
					printf("Y:��       N����\n");
					printf("��ѡ��"); 
					while(1)//��ѭ�������û����벻�Ϸ����� 
					{
						scanf("%c",&option_3);
						getchar(); 
						if(toupper(option_3)=='Y'||option_3=='Y')//��֤�û������Сд��'Y'���� 
						{
							FILE *fp;
							fp=fopen("D:\\picture_and_text\\z.txt","a+");
							if(NULL==fp)//�ж��ļ��Ƿ�򿪳ɹ� 
							{
								printf("File failed to open\n");
								exit(1);
							}
							fprintf(fp,"%d.%d.%d.%d               ",a,b,c,d);
							fprintf(fp,"���ң�%s      ʡ�ݣ�%s      ���У�%s      ��Ӫ�̣�%s      \n",IP[sign].country,IP[sign].province,IP[sign].city,IP[sign].isp);
							fclose(fp);
							printf("��Ϣ����ɹ���\n\n\n");
							break;
						} 
						else if(toupper(option_3)=='N'||option_3=='N')//��֤�û������Сд��'N'����
						{                                            
							printf("���β�ѯ������\n\n\n"); //����û���������������β�ѯ 
							break;
						} 
						else//�û����벻�Ϸ�����ʾ�û���������
						{
							printf("����������������������:");
						} 
					}
					break;
				} 
				else//�û����벻�Ϸ�����ʾ�û��������� 
				{
					printf("���������������������룺");
				} 
			}
			break; //��ѯ����������ѭ�� 
		}
	}
}

void multiple_ip() 
{
	int i,a[100000],b[100000],c[100000],d[100000],a1,b1,c1,d1,a2,b2,c2,d2,sign[100000],x,count=0,option_2,h=0;
	char option_1,option_3; 
	long start,end;
	double sum;
	printf("��������Ҫ��ѯ��IP��ַ��\n");
	while(scanf("%d.%d.%d.%d",&a[count],&b[count],&c[count],&d[count])!=EOF)//�����ĸ�����ֱ���û�����Ķ��IP��ַ 
	{																		//���ĸ�����a,b,c,d���д��� 
		getchar();
		count++;//�����û������IP��ַ�ĸ��� 
	} 
	printf("��������Ҫ��ָ�����ݽ��в�ѯ��\n");
	printf("Y:��       N����\n");
	printf("��ѡ��");
	while(1)//��ѭ�������û����벻�Ϸ����� 
	{
		scanf("%c",&option_1); 
		getchar();
		if(toupper(option_1)=='Y'||option_1=='Y')//��֤�û������Сд��'Y'���� 
		{
			printf("��ָ����Ҫ��ѯ�����ݣ�\n");
			printf("1.����     2.ʡ��     3.����       4.��Ӫ��\n");
			printf("�����룺");
			while(1)
			{
				scanf("%d",&option_2);
				getchar();
				if(option_2==1||option_2==2||option_2==3||option_2==4)
				{
					printf("�����������������������������������\n");
		   			printf("��                    ���Ĳ�ѯ�������                            ��\n"); 
					printf("�����������������������������������\n");
					start=clock(); 
					for(x=0;x<count;x++)
					{
						if(a[x]<0||b[x]<0||c[x]<0||d[x]<0||a[x]>255||b[x]>255||c[x]>255||d[x]>255)//�ж��û������Ƿ�Ϸ� 
						{
							printf("%d.%d.%d.%d     ��������һ����ЧIP!\n",a[x],b[x],c[x],d[x]); 
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
									sign[h]=i;//����һ��������Ǹ�IP��Ӧ����ȷ�Ľṹ����±��Ա�����������
									h++;
									break; 
								}
							} 
							printf("%d.%d.%d.%d     ",a[x],b[x],c[x],d[x]);//����û������IP��ַ 
							mul_special_inquiry(option_2,sign[h-1]);//���ö��ip��ַָ����ѯ����	
						}
					}
					end=clock();
					sum=10*(double)(end-start)/CLOCKS_PER_SEC;//���㱾�β�ѯ����ʱ��
					printf("quiry time: %f ms      \n",sum);//������β�ѯ����ʱ��
					printf("�����������������������������������\n");
					system("pause");
					printf("\n");
					break;
				}
				else//�û����벻�Ϸ�����ʾ�û��������� 
				{
					printf("��������������������룺");
				} 
			}
			break;		
		}		 
		else if(toupper(option_1)=='N'||option_1=='N')
		{
			printf("�����������������������������������\n");
			printf("��                       ���Ĳ�ѯ�������                         ��\n"); 
			printf("�����������������������������������\n");
			for(x=0;x<count;x++)
			{
				if(a[x]<0||b[x]<0||c[x]<0||d[x]<0||a[x]>255||b[x]>255||c[x]>255||d[x]>255)//�ж��û������Ƿ�Ϸ� 
				{
					printf("%d.%d.%d.%d     ��������һ����ЧIP!\n",a[x],b[x],c[x],d[x]); 
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
							sign[h]=i;//����һ��������Ǹ�IP��Ӧ����ȷ�Ľṹ����±��Ա�����������
							h++;
							break; 
						}
					} 
					//����û������ip�����Ӧ�ĵ�����Ϣ	
					printf("%d.%d.%d.%d     ���ң�%s   ʡ�ݣ�%s   ���У�%s   ��Ӫ�̣�%s\n",a[x],b[x],c[x],d[x],IP[sign[h-1]].country,IP[sign[h-1]].province,IP[sign[h-1]].city,IP[sign[h-1]].isp); //���ip��Ӧ��Ϣ 
				}
			}	
			end=clock();
			sum=10*(double)(end-start)/CLOCKS_PER_SEC;//���㱾�β�ѯ����ʱ��
			printf("quiry time: %f ms      \n",sum);//������β�ѯ����ʱ��
			printf("�����������������������������������\n");
			system("pause");
			printf("\n");
			printf("�������Ƿ���Ҫ���棿\n");//ѯ���û��Ƿ���Ҫ���� 
			printf("Y:��       N����\n");
			printf("��ѡ��"); 
			while(1)//��ѭ�������û����벻�Ϸ����� 
			{
				scanf("%c",&option_3);
				getchar(); 
				if(toupper(option_3)=='Y'||option_3=='Y')//��֤�û������Сд��'Y'���� 
				{
					FILE *fp;
					fp=fopen("D:\\picture_and_text\\z.txt","a+");//���ļ��б��ں����ı��� 
					if(NULL==fp)//�ж��ļ��Ƿ�򿪳ɹ� 
					{
						printf("File failed to open\n");
						exit(1);
					}
					for(i=0;i<count;i++)
					{
						fprintf(fp,"%d.%d.%d.%d               ",a[i],b[i],c[i],d[i]);//�����IP��ַд���ļ����Ա㱣��
						fprintf(fp,"���ң�%s      ʡ�ݣ�%s      ���У�%s      ��Ӫ�̣�%s      \n",IP[sign[i]].country,IP[sign[i]].province,IP[sign[i]].city,IP[sign[i]].isp);
					}
					fclose(fp);
					printf("��Ϣ����ɹ���\n\n\n");
					break;
				} 
				else if(toupper(option_3)=='N'||option_3=='N')//��֤�û������Сд��'N'����
				{                                            
					printf("���β�ѯ������\n\n\n"); //����û���������������β�ѯ 
					break;
				} 
				else//�û����벻�Ϸ�����ʾ�û���������
				{
					printf("����������������������:");
				} 
			}
			break; 
		} 
		else//�û����벻�Ϸ�����ʾ�û��������� 
		{
			printf("������������������������:");
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
	printf("��������Ҫ��ѯ��IP��ַ�Σ�\n");
	while(1)//��ѭ�������û�������� 
	{
		scanf("%d.%d.%d.%d-%d.%d.%d.%d",&a,&b,&c,&d,&a_1,&b_1,&c_1,&d_1);//�û�����һ��IP��ַ���� 
		getchar();
		a1=a_1-a; 
		b1=b_1-b;
		c1=c_1-c;
		d1=d_1-d;
		if(a<0||b<0||c<0||d<0||a>255||b>255||c>255||d>255||a_1<0||b_1<0||c_1<0||d_1<0||a_1>255||b_1>255||c_1>255||d_1>255||
		(a1<0)||(a1==0&&b1<0)||(a1==0&&b1==0&&c1<0)||(a1==0&&b1==0&&c1==0&&d1<0))//�ж��û������Ƿ�Ϸ� 
		{
			printf("����IP��ַ�����������������룺"); //�ж��û������Ƿ�Ϸ� 
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
					sign1=i;//����û��������ʼip���ڵĽṹ����±� 
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
					sign2=i;//����û��������ֹip���ڵĽṹ����±� 
					break; 
				}
			} 
			printf("��������Ҫ��ָ�����ݽ��в�ѯ��\n");
			printf("Y:��       N����\n");
			printf("��ѡ��"); 
			while(1)//��ѭ�������û����벻�Ϸ����� 
			{
				scanf("%c",&option_1);
				getchar();
				if(toupper(option_1)=='Y'||option_1=='Y')//��֤�û������Сд��'Y'���� 
				{
					printf("��ָ����Ҫ��ѯ�����ݣ�\n");
					printf("1.����     2.ʡ��     3.����       4.��Ӫ��\n");
					printf("�����룺");
					while(1)
					{
						scanf("%d",&option_2);//�û�ѡ��ָ����ѯ������ 
						getchar();
						if(option_2==1||option_2==2||option_2==3||option_2==4)
						{
							printf("�����������������������������������\n");
							printf("��                      ���Ĳ�ѯ�������                          ��\n"); 
							printf("�����������������������������������\n");
							for(x=sign1;x<=sign2;x++)//�����û������IP���������������нṹ�� 
							{
								if(x==sign1) 
								{
									//���У��ж��û��������ʼIP�Ƿ��������ĵ�һ���ṹ�����ֹIP���
									if(a==IP[sign1].ep_a&&b==IP[sign1].ep_b&&c==IP[sign1].ep_c&&d==IP[sign1].ep_d)
									{
										printf("%d.%d.%d.%d          ",a,b,c,d);//�����ֻ����ýṹ�����ֹIP 
										mul_special_inquiry(option_2,sign1);//����û�ָ���Ķ�Ӧ��IP����Ϣ 
									}
									else
									{
										printf("%d.%d.%d.%d-%s          ",a,b,c,d,IP[sign1].ep);//�����������û��������ʼIP���ýṹ�����ֹIP��һ������ 
										mul_special_inquiry(option_2,sign1); //����û�ָ���Ķ�Ӧ��IP�������Ϣ 
									} 
								}
								if(x==sign2)
								{
									//���У��ж��û��������ֹIP�Ƿ��������ĵ�һ���ṹ�����ʼIP���{
									if(a_1==IP[sign2].sp_a&&b_1==IP[sign2].sp_b&&c_1==IP[sign2].sp_c&&d_1==IP[sign2].sp_d)
									{
										printf("%d.%d.%d.%d          ",a_1,b_1,c_1,d_1);//�����ֻ����ýṹ�����ʼIP 
										mul_special_inquiry(option_2,sign2);//����û�ָ���Ķ�Ӧ��IP����Ϣ 
									
									}
									else 
									{
										printf("%s-%d.%d.%d.%d          ",IP[sign2].sp,a_1,b_1,c_1,d_1);//�����������ýṹ�����ʼIP���û��������ֹIP��һ������ 
										mul_special_inquiry(option_2,sign2); //����û�ָ���Ķ�Ӧ��IP�������Ϣ 
									
									}
								}
								if(x>sign1&&x<sign2)
								{
									printf("%s-%s          ",IP[x].sp,IP[x].ep);	//���IP��ַ�� 
									mul_special_inquiry(option_2,x);//����'���ip��ַָ����ѯ����'	
								}
							}
							end=clock();
							sum=10*(double)(end-start)/CLOCKS_PER_SEC;//�����ѯ����ʱ��
							printf("quiry time: %f ms      \n",sum);//������β�ѯ����ʱ��
							printf("�����������������������������������\n");
							system("pause"); 
							printf("\n\n"); 
							break;
						}
						else//�û����벻�Ϸ�����ʾ�û��������� 
						{
							printf("��������������������룺");
						} 	
					}
					break; 
				}		 
				else if(toupper(option_1)=='N'||option_1=='N')//�û�������ָ�����ݲ�ѯ 
				{
					printf("�����������������������������������\n");
					printf("��                     ���Ĳ�ѯ�������                           ��\n"); 
					printf("�����������������������������������\n");
					for(x=sign1;x<=sign2;x++)//�����û������IP���������Ľṹ�� 
					{
						if(x==sign1) 
						{
							if(a==IP[sign1].ep_a&&b==IP[sign1].ep_b&&c==IP[sign1].ep_c&&d==IP[sign1].ep_d)
							{
								printf("%d.%d.%d.%d        ���ң�%s    ʡ�ݣ�%s    ���У�%s    ��Ӫ�̣�%s\n",a,b,c,d,IP[sign1].country,IP[sign1].province,IP[sign1].city,IP[sign1].isp);
							}
							else
							{
								printf("%d.%d.%d.%d-%s        ���ң�%s    ʡ�ݣ�%s    ���У�%s    ��Ӫ�̣�%s\n",a,b,c,d,IP[sign1].ep,IP[sign1].country,IP[sign1].province,IP[sign1].city,IP[sign1].isp);
							}
						} 
						if(x==sign2)
						{
							if(a_1==IP[sign2].sp_a&&b_1==IP[sign2].sp_b&&c_1==IP[sign2].sp_c&&d_1==IP[sign2].sp_d)
							{
								printf("%d.%d.%d.%d        ���ң�%s    ʡ�ݣ�%s    ���У�%s    ��Ӫ�̣�%s\n",a_1,b_1,c_1,d_1,IP[sign2].country,IP[sign2].province,IP[sign2].city,IP[sign2].isp);
							}
							else 
							{
								printf("%s-%d.%d.%d.%d        ���ң�%s    ʡ�ݣ�%s    ���У�%s    ��Ӫ�̣�%s\n",IP[sign2].sp,a_1,b_1,c_1,d_1,IP[sign2].country,IP[sign2].province,IP[sign2].city,IP[sign2].isp);
							}
						}
						if(x>sign1&&x<sign2)
						{
							printf("%s-%s        ���ң�%s    ʡ�ݣ�%s    ���У�%s    ��Ӫ�̣�%s\n",IP[x].sp,IP[x].ep,IP[x].country,IP[x].province,IP[x].city,IP[x].isp);	
						}	
					}
					end=clock();
					sum=10*(double)(end-start)/CLOCKS_PER_SEC;//�����ѯ����ʱ��	
					printf("quiry time: %f ms      \n",sum);//������β�ѯ����ʱ��
					printf("�����������������������������������\n");
					system("pause");
					printf("\n\n");
					printf("�������Ƿ���Ҫ���棿\n");//ѯ���û��Ƿ���Ҫ���� 
					printf("Y:��       N����\n");
					printf("��ѡ��"); 
					while(1)//��ѭ�������û����벻�Ϸ����� 
					{
						scanf("%c",&option_3);
						getchar(); 
						if(toupper(option_3)=='Y'||option_3=='Y')//��֤�û������Сд��'Y'���� 
						{
							FILE *fp;
							fp=fopen("D:\\picture_and_text\\z.txt","a+");
							if(NULL==fp)//�ж��ļ��Ƿ�򿪳ɹ� 
							{
								printf("File failed to open\n");
								exit(1);
							}
							for(x=sign1;x<=sign2;x++)//�����û������IP���������������нṹ�� 
							{
								if(x==sign1) 
								{
									//���У��ж��û��������ʼIP�Ƿ��������ĵ�һ���ṹ�����ֹIP���
									if(a==IP[x].ep_a&&b==IP[x].ep_b&&c==IP[x].ep_c&&d==IP[x].ep_d)
									{
										fprintf(fp,"%d.%d.%d.%d          ",a,b,c,d);//�����ֻ����ýṹ�����ֹIP 
										fprintf(fp,"���ң�%s      ʡ�ݣ�%s      ���У�%s      ��Ӫ�̣�%s      \n",IP[x].country,IP[x].province,IP[x].city,IP[x].isp);
									}
									else
									{
										fprintf(fp,"%d.%d.%d.%d-%s          ",a,b,c,d,IP[x].ep);//������򱣴��û��������ʼIP���ýṹ�����ֹIP��һ������ 
										fprintf(fp,"���ң�%s      ʡ�ݣ�%s      ���У�%s      ��Ӫ�̣�%s      \n",IP[x].country,IP[x].province,IP[x].city,IP[x].isp);
									}
								}
								if(x==sign2)
								{
									//���У��ж��û��������ֹIP�Ƿ��������ĵ�һ���ṹ�����ʼIP���{
									if(a_1==IP[x].sp_a&&b_1==IP[x].sp_b&&c_1==IP[x].sp_c&&d_1==IP[x].sp_d)
									{
										fprintf(fp,"%d.%d.%d.%d          ",a_1,b_1,c_1,d_1);//�����ֻ����ýṹ�����ʼIP  
										fprintf(fp,"���ң�%s      ʡ�ݣ�%s      ���У�%s      ��Ӫ�̣�%s      \n",IP[x].country,IP[x].province,IP[x].city,IP[x].isp);
									}
									else 
									{
										fprintf(fp,"%s-%d.%d.%d.%d          ",IP[x].sp,a_1,b_1,c_1,d_1);//������򱣴�ýṹ�����ʼIP���û��������ֹIP��һ������ 
										fprintf(fp,"���ң�%s      ʡ�ݣ�%s      ���У�%s      ��Ӫ�̣�%s      \n",IP[x].country,IP[x].province,IP[x].city,IP[x].isp);
									} 
								}	
								if(x>sign1&&x<sign2)
								{
									fprintf(fp,"%s-%s          ���ң�%s      ʡ�ݣ�%s      ���У�%s      ��Ӫ�̣�%s      \n",IP[x].sp,IP[x].ep,IP[x].country,IP[x].province,IP[x].city,IP[x].isp);
								}
							}
							fclose(fp);
							printf("������Ϣ�ɹ���\n\n\n");
							break;
						} 
						else if(toupper(option_3)=='N'||option_3=='N')//��֤�û������Сд��'N'����
						{                                            
							printf("���β�ѯ������\n\n\n"); //����û���������������β�ѯ 
							break;
						} 
						else//�û����벻�Ϸ�����ʾ�û���������
						{
							printf("����������������������:");
						} 
					}
					break; 
				} 
				else//�û����벻�Ϸ�����ʾ�û��������� 
				{
					printf("���������������������:");
				}
			}
			break;
		}
	}
}

void special_inquire(int sign)//����sign��ʾ�û������ip��Ӧ�ı��������Ӧ�ĵ�����Ϣ�Ľṹ����±� 
{
	int option;
	printf("��ָ����Ҫ��ѯ�����ݣ�\n");
	//���û��ṩ����ѡ�� 
	printf("1.����     2.ʡ��     3.����       4.��Ӫ��\n");
	printf("�����룺");
	while(1)
	{
		scanf("%d",&option);//�û����� 
		getchar();
		//�����û���������ж�Ӧ����� 
		if(option==1)
		{
			printf("���Ĳ�ѯ���Ϊ��%s\n",IP[sign].country);//����û�ָ���Ĺ�����Ϣ 
			break;
		} 
		else if(option==2)
		{
			printf("���Ĳ�ѯ���Ϊ��%s\n",IP[sign].province);//����û�ָ����ʡ����Ϣ
			break;
		} 
		else if(option==3)
		{
			printf("���Ĳ�ѯ���Ϊ��%s\n",IP[sign].city);//����û�ָ���ĳ�����Ϣ
			break;
		} 
		else if(option==4)
		{
			printf("���Ĳ�ѯ���Ϊ��%s",IP[sign].isp);//����û�ָ����ISP��Ϣ
			break;
		} 
		else
		{
			printf("����������������������:");
		}	
	} 

} 

void mul_special_inquiry(int option,int sign)//����sign��ʾ�û������ip��Ӧ�ı��������Ӧ�ĵ�����Ϣ�Ľṹ����±� 
{                                            //����option��ʾ�û���Ҫָ���������Ϣ�Ķ�Ӧ���  
	switch(option)//���ݴ�������Ĳ�ͬ�ֱ���ж�Ӧ����� 
	{
		case 1://�û�����Ϊ 1 �������Ӧ�Ĺ�����Ϣ 
			printf("���ң�%s\n",IP[sign].country);
	 		break;
		case 2://�û�����Ϊ 2 �������Ӧ�Ĺ�����Ϣ 
			printf("ʡ�ݣ�%s\n",IP[sign].province);
			break;
		case 3://�û�����Ϊ 3 �������Ӧ�Ĺ�����Ϣ 
			printf("���У�%s\n",IP[sign].city);
			break;
		case 4://�û�����Ϊ 4 �������Ӧ�Ĺ�����Ϣ 
			printf("��Ӫ�̣�%s\n",IP[sign].isp);
			break;
		default:
			break;
	}	
} 

