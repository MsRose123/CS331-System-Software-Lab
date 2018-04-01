Day 5

Simulate the following page replacement algorithms.
FIFO
LRU
LFU

PROGRAM
a)
#include<stdio.h>
  2 void main()
  3 {
  4
  5 int k,a,x,pf,n,p,c=0,i,j;
  6 int array[20];
  7 x=0;
  8 pf=0;
  9 printf("Enter the size of array:");
 10 scanf("%d",&n);
 11 for(i=0;i<n;i++)
 12 {
 13         array[i]=0;
 14 }
 15 printf("Enter the number of pages:");
 16 scanf("%d",&p);
 17 for(i=0;i<p;i++)
 18 {
 19         printf("\nEnter the element:");
 20         scanf("%d",&a);
 21         for(j=0;j<n;j++)
 22         {
 23                 if(a==array[j])
 24                 {
 25                         c=1;
 26                         for(k=0;k<n;k++)
 27                         {
 28                                 printf("%d ",array[k]);
 29                         }
 30
 31                 }
 32         }
 33         if(c==0)
 34         {
 35                 pf=pf+1;
 36                 array[x]=a;
 37                 for(k=0;k<n;k++)
 38                 {
 39                         printf("%d ",array[k]);
 40                 }
 41                 x++;
 42         }
 43         if(x==n)
44           {
 45                 x=0;
 46         }
 47 c=0;
 48 }
 49 printf("\nPage fault:%d\n",pf);
 50
 51 }


b)

#include<stdio.h>
  2 void main()
  3 {
  4    int k,a,x,pf,n,p,c=0,i,j,m,small,pos;
  5    int array[20],counter[20];
  6    x=0;
  7    pf=0;
  8    printf("Enter the size of array:");
  9   scanf("%d",&n);
 10   for(i=0;i<n;i++)
 11   {
 12          array[i]=0;
 13         counter[i]=0;
 14   }
 15   printf("Enter the number of pages:");
 16   scanf("%d",&p);
 17
 18  for(i=0;i<p;i++)
 19   {
 20           printf("\nEnter the element:");
 21          scanf("%d",&a);
 22           for(j=0;j<n;j++)
 23           {
 24                   if(a==array[j])
 25                  {
 26                           c=1;
 27                         counter[j]=counter[j]+1;
 28                           for(k=0;k<n;k++)
 29                           {
 30                                   printf("%d ",array[k]);
 31                           }
 32
 33                   }
 34           }
 35           if(c==0)
 36           {
 37                   pf=pf+1;
 38                 if(x==n)
 39                 {
 40                                 small=counter[0];
 41                                 for(m=0;m<n;m++)
 42                                 {
 43                                         if(counter[m]<small)
44                                         {
 45                                                 pos=m;
 46                                         }
 47                                 }
 48                                 x=pos;
 49                                 counter[x]=0;
 50                 }
 51                   array[x]=a;
 52                   counter[x]=counter[x]+1;
 53                   for(k=0;k<n;k++)
 54                   {
 55                           printf("%d ",array[k]);
 56                   }
 57                   x++;
 58           }
 59
 60 c=0;
 61 }
 62 printf("\nPage Fault:%d\n",pf);
 63 }


c)

1 #include<stdio.h>
  2 void main()
  3 {
  4    int k,a,x,pf,n,p,c=0,i,j,m,t,big,pos;
  5    int array[20],counter[20];
  6    x=0;
  7    pf=0;
  8    printf("Enter the size of array:");
  9   scanf("%d",&n);
 10   for(i=0;i<n;i++)
 11   {
 12          array[i]=0;
 13         counter[i]=0;
 14   }
 15   printf("Enter the number of pages:");
 16   scanf("%d",&p);
 17
 18  for(i=0;i<p;i++)
 19   {
 20           printf("\nEnter the element:");
 21          scanf("%d",&a);
 22           for(j=0;j<n;j++)
 23           {
 24                   if(a==array[j])
 25                  {
 26                           c=1;
 27                         counter[j]=counter[j]-1;
 28                           for(k=0;k<n;k++)
 29                           {
 30                                   printf("%d ",array[k]);
 31                           }
 32                         for(t=0;t<n;t++)
 33                         {
 34                                 if(t!=j)
 35                                 {
 36                                         counter[t]=counter[t]+1;
 37                                 }
 38                         }
 39
 40                   }
 41           }
 42           if(c==0)
 43           {
                   pf=pf+1;
 45                 if(x==n)
 46                 {
 47                                 big=counter[0];
 48                                 for(m=0;m<n;m++)
 49                                 {
 50                                         if(counter[m]>big)
 51                                         {
 52                                                 pos=m;
 53                                         }
 54                                 }
 55                                 x=pos;
 56                                 counter[x]=0;
 57                 }
 58                   array[x]=a;
 59                 for(t=0;t<=x;t++)
 60                 {
 61                   counter[t]=counter[t]+1;
 62                 }
 63                   for(k=0;k<n;k++)
 64                   {
 65                           printf("%d ",array[k]);
 66                   }
 67                   x++;
 68           }
 69
 70 c=0;
 71 }
 72 printf("\nPage Fault:%d\n",pf);
 73 }


OUTPUT
LFU
Enter the size of array:4
Enter the number of pages:8

Enter the element:1
1 0 0 0
Enter the element:2
1 2 0 0
Enter the element:3
1 2 3 0
Enter the element:4
1 2 3 4
Enter the element:1
1 2 3 4
Enter the element:4
1 2 3 4
Enter the element:3
1 2 3 4
Enter the element:9
1 9 3 4	

LRU	
Enter the size of array:4	
Enter the number of pages:9

Enter the element:1
1 0 0 0
Enter the element:2
1 2 0 0
Enter the element:3
1 2 3 0
Enter the element:4
1 2 3 4
Enter the element:3
1 2 3 4
Enter the element:1
1 2 3 4
Enter the element:4
1 2 3 4
Enter the element:5
1 5 3 4
Enter the element:4
1 5 3 4
Page Fault:5	

FIFO
Enter the size of array:3
Enter the number of pages:7

Enter the element:2
2 0 0
Enter the element:3
2 3 0
Enter the element:4
2 3 4
Enter the element:4
2 3 4
Enter the element:5
5 3 4
Enter the element:6
5 6 4
Enter the element:7
5 6 7
Page fault:6
