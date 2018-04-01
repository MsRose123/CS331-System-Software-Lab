Day 2

Simulate the following file organization techniques.
Single level directory
Two level directory
Hierarchical

PROGRAM

a)

#include<stdio.h>
  2 void main()
  3 {
  4 int i,n;
  5 char rt[20];
  6 char f[20][20];
  7 printf("\n\n\t\t\tSingle Level Directory\n");
  8 printf("Enter the root Directory:");
  9 gets(rt);
 10 printf("Enter the number of files in Root:");
 11 scanf("%d",&n);
 12 printf("\n");
 13 for(i=0;i<n;i++)
 14 {
 15 printf("Enter the File name %d:",(i+1));
 16 scanf("%s",&f[i]);
 17 }
 18 printf("\t%s",rt);
 19 printf("\n");
 20 for(i=0;i<n;i++)
 21 {
 22         printf("\t  -%s\n",f[i]);
 23 }
 24 }

b)
#include<stdio.h>
  2 void main()
  3 {
  4 int x,j,i,n,num[20];
  5 char rt[20],d[20][20];
  6 char f[20][20][20];
  7 printf("\n\n\t\t\tTwo Level Directory\n");
  8 printf("Enter the root Directory:");
  9 gets(rt);
 10 printf("Enter the number of directories in Root:");
 11 scanf("%d",&n);
 12 printf("\n");
 13 for(j=0;j<n;j++)
 14 {
 15 printf("\n");
 16 printf("Enter the name of directory %d :",(j+1));
 17 scanf("%s",&d[j]);
 18 printf("Enter the number of files in Directory %s :",d[j]);
 19 scanf("%d",&x);
 20 num[j]=x;
 21 for(i=0;i<x;i++)
 22 {
 23 printf("Enter the File name %d:",(i+1));
 24 scanf("%s",&f[j][i]);
 25 }
 26 }
 27 printf("\n\t\t\t%s",rt);
 28 printf("\n");
 29 printf("\n");
 30 for(i=0;i<n;i++)
 31 {
 32         printf("\t%s\n",&d[i]);
 33         for(j=0;j<num[i];j++)
 34         {
 35                 printf("\t\t-%s\n",f[i][j]);
 36         }
 37 }
 38 }


c)

include<stdio.h>
#include<string.h>

void main()
{
        char d[50][50][50],o[10];
        int i,m,n[30],j;
        printf("Enter the number of directories of ROOT");
        scanf("%d",&m);
        for(i=1;i<=m;i++)
        {
                printf("Enter the number of all subdirectories in directory %d :",i);
                scanf("%d",&o[i]);
		printf("Enter the number of files in the last subdirectory of %d : ",i);
		scanf("%d",&n[i]);
        }
        printf("Enter the name of the ROOT : ");
        scanf("%s",&d[0][0]);
        for(i=1;i<=m;i++)
        {
                printf("Enter the name of Main Directory %d : ",i);
                scanf("%s",&d[i][0]);
        }
        for(i=1;i<=m;i++)
        {	
		printf("Enter the name of the subdirectories of %d :",i);
		for(j=1;j<=o[i];j++)
		{
			scanf("%s",&d[i][j]);
		}
	}
	i=0;
	for(i=1;i<=m;i++)
	{
		printf("Enter the name of the files in last folder of %d :",i);
		for(j=o[i]+1;j<=n[i]+o[i];j++)
		{
			scanf("%s",&d[i][j]);
		}						 
      
        printf("The directory structure\n");
        printf("The ROOT : \t            %s \n",d[0][0]);
        for(i=1;i<=m;i++)
        {
                printf("The Directory %d :%s\n",i,d[i][0]);
                printf("The subdirectories : \n");
                for(j=1;j<=n[i]+o[i];j++)
                {
			if(j<=o[i])
			{
				printf ("% *s\n",j,d[i][j]);
			}
			else
			{
				printf ("% *s\n",10,d[i][j])	
			}	                        
                }
        }

}

