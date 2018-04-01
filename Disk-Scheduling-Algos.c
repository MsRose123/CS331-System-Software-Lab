Day 4

Simulate the following disk scheduling algorithm.
(a)FCFS
(b)SCAN
(c)C-SCAN

PROGRAM

a)
#include<stdio.h>
  2 void main()
  3 {       int i,n,a[100],m,sum=0,c=0;
  4         printf("Enter number of locations:");
  5         scanf("%d",&n);
  6         printf("Enter Locations:");
  7         for(i=0;i<n;i++)
  8         {       scanf("%d",&a[i+1]);
  9         }
 10         printf("Enter the current head position:");
 11         scanf("%d",&a[0]);
 12         printf("First Come First Serve:");
 13         for(i=0;i<n;i++)
 14         {       printf(" %d\t",a[i]);
 15         }
 16         for(i=0;i<n;i++){
 17                 if(a[i+1]>a[i])
 18                 {
 19                 c=a[i+1]-a[i] ;
 20                 }
 21                 else
 22                 {c=a[i]-a[i+1];}
 23                 sum=sum+c;
 24         }
 25         printf("Total seek time:%d\n",sum);
 26 }

b)

#include<conio.h>
#include<stdio.h>
int main()
{
 int i,j,sum=0,n;
 int d[20];
 int disk;   //loc of head
 int temp,max;     
 int dloc;   //loc of disk in array
 clrscr();
 printf("enter number of location\t");
 scanf("%d",&n);
 printf("enter position of head\t");
 scanf("%d",&disk);
 printf("enter elements of disk queue\n");
 for(i=0;i<n;i++)
 {
 scanf("%d",&d[i]);
 }
 d[n]=disk;
 n=n+1;
 for(i=0;i<n;i++)    // sorting disk locations
 {
  for(j=i;j<n;j++)
  {
    if(d[i]>d[j])
    {
    temp=d[i];
    d[i]=d[j];
    d[j]=temp;
    }
  }
 }
 max=d[n];
 for(i=0;i<n;i++)   // to find loc of disc in array
 {
 if(disk==d[i]) { dloc=i; break;  }
 }
 for(i=dloc;i>=0;i--)
 {
 printf("%d -->",d[i]);
 }
 printf("0 -->");
 for(i=dloc+1;i<n;i++)
 {
 printf("%d-->",d[i]);
 }
 sum=disk+max;
       printf("\nmovement of total cylinders %d",sum);
 getch();
 return 0;


c)

#include<stdio.h>
  2 void main()
  3 {
  4             int queue[20],n,head,i,j,k,seek=0,max,diff,temp,queue1[20],queue2[20],temp1=0,temp2=0;
  5             float avg;
  6             printf("Enter the max range of disk\n");
  7             scanf("%d",&max);
  8             printf("Enter the initial head position\n");
  9             scanf("%d",&head);
 10             printf("Enter the size of queue request\n");
 11             scanf("%d",&n);
 12             printf("Enter the queue of disk positions to be read\n");
 13             for(i=1;i<=n;i++)
 14             {
 15                         scanf("%d",&temp);
 16                         if(temp>=head)
 17                         {
 18                                     queue1[temp1]=temp;
 19                                     temp1++;
 20                         }
 21                         else
 22                         {
 23                                     queue2[temp2]=temp;
 24                                     temp2++;
 25                         }
 26             }
 27             for(i=0;i<temp1-1;i++)
 28             {
 29                         for(j=i+1;j<temp1;j++)
 30                         {
 31                                     if(queue1[i]>queue1[j])
 32                                     {
 33                                                 temp=queue1[i];
 34                                                 queue1[i]=queue1[j];
 35                                                 queue1[j]=temp;
 36                                     }
 37                         }
 38             }
 39             for(i=0;i<temp2-1;i++)
 40             {
 41                         for(j=i+1;j<temp2;j++)
 42                         {
 43                                     if(queue2[i]>queue2[j])                                     {
 
 45                                                 temp=queue2[i];
 46                                                 queue2[i]=queue2[j];
 47                                                 queue2[j]=temp;
 48                                     }
 49                         }
 50             }
 51             for(i=1,j=0;j<temp1;i++,j++)
 52                 queue[i]=queue1[j];
 53             queue[i]=max;
 54             queue[i+1]=0;
 55             for(i=temp1+3,j=0;j<temp2;i++,j++)
 56                 queue[i]=queue2[j];
 57             queue[0]=head;
 58             for(j=0;j<=n+1;j++)
 59             {
 60                         diff=abs(queue[j+1]-queue[j]);
 61                         seek+=diff;
 62                         printf("Disk head moves from %d to %d with seek %d\n",queue[j],queue[j+1],diff);
 63             }
 64             printf("Total seek time is %d\n",seek);
 65             avg=seek/(float)n;
 66             printf("Average seek time is %f\n",avg);
 67 }
