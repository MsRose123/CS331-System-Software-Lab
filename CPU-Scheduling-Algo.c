Day 1

Simulate the following non-preemptive CPU scheduling algorithms to find turnaround time and waiting time.
FCFS
SJF
Round Robin (pre-emptive)
Priority

PROGRAM

a)

 1 #include<stdio.h>
  2
  3 int main()
  4 {
  5         int n,bt[20],wt[20],tat[20],i,j,p[20],pos,temp,temp1;
  6         float awt=0,twt=0,ttat=0,atat=0;
  7         printf("enter the no of processes");
  8         scanf("%d",&n);
  9         printf("enter the burst time of each processes");
 10         for(i=0;i<n;i++)
 11         {
 12                 printf("process P[%d] ",i+1);
 13                 scanf("%d",&bt[i]);
 14                 p[i]=i+1;
 15         }
 16         for(i=0;i<n;i++)
 17     {
 18         pos=i;
 19         for(j=i+1;j<n;j++)
 20         {
 21             if(bt[j]<bt[pos])
 22                 pos=j;
 23         }
 24
 25         temp=bt[i];
 26         bt[i]=bt[pos];
 27         bt[pos]=temp;
 28
 29         temp1=p[i];
 30         p[i]=p[pos];
 31         p[pos]=temp1;
 32     }
 33
 34
 35         wt[0]=0;
 36
 37         for(i=1;i<n;i++)
 38         {
 39                 wt[i]=wt[i-1]+bt[i-1];
 40                 twt=twt+wt[i];
 41         }
 42
 43         for(i=0;i<n;i++)
       {
 45                 tat[i]=bt[i]+wt[i];
 46                 ttat=ttat+tat[i];
 47         }
 48
 49 printf(" PROCEES_ID \t\t BURST_TIME \t\t WAITING_TIME \t\t TURN_AROUND_TIME \n");
 50 for(i=0;i<n;i++)
 51 {
 52         printf(" %d\t\t\t       %d\t\t\t  %d\t\t\t   %d\t\t\t  \n  ",p[i],bt[i],wt[i],tat[i]);
 53 }
 54
 55 awt= (float)twt/n;
 56 atat=(float)ttat/n;
 57
 58 printf("average waiting time is %f \n",awt);
 59 printf("average turnaround time is %f",atat);
 60
 61
 62 }
 63


b)
#include<stdio.h>
  2
  3
  4 void main()
  5 {
  6         int bt[20],wt[20],tt[20],n,i,j,temp,tw,ta,p[20],pos;
  7         float awt,att;
  8         printf("Enter the number of processes");
  9         scanf("%d",&n);
 10         printf("Enter the burst times");
 11         for(i=0;i<n;i++)
 12         {
 13                 printf("Process P[%d]",i+1);
 14                 scanf("%d",&bt[i]);
 15                 p[i]=i+1;
 16         }
 17
 18
 19         for(i=0;i<n;i++)
 20         {
 21                 pos=i;
 22                 for(j=i+1;j<n;j++)
 23                 {
 24                         if(bt[j]<bt[pos])
 25                         pos=j;
 26                 }
 27                 temp=bt[i];
 28                 bt[i]=bt[pos];
 29                 bt[pos]=temp;
 30
 31                 temp=p[i];
 32                 p[i]=p[pos];
 33                 p[pos]=temp;
 34         }
 35         wt[0]=0;
 36         awt=0;
 37         att=0;
 38         for(i=1;i<n;i++)
 39         {
 40                 wt[i]=wt[i-1]+bt[i-1];
 41                 tw=awt+wt[i];
 42         }
 43         awt=(float)tw/n;
                                       for(i=0;i<n;i++)
 45         {
 46                 tt[i]=wt[i]+bt[i];
 47                 ta=att+tt[i];
 48         }
 49         att=(float)ta/n;
 50         printf("ProcessID \t Burst Time \t Waiting Time \t Turnaround Time \n");
 51         for(i=0;i<n;i++)
 52         {
 53                 printf("   P%d    \t    %d      \t    %d        \t    %d \n",p[i],bt[i],wt[i],tt[i]);
 54         }
 55         printf("\n Average Waiting Time = %f \n",awt);
 56         printf(" Average Turnaround Time = %f \n",att);
 57 }


c)

#include<stdio.h>
  2
  3 int main()
  4 {
  5         int n,bt[20],wt[20],tat[20],i,j,p[20],pr[20],pos,temp,temp1,temp2;
  6         float awt=0,twt=0,ttat=0,atat=0;
  7         printf("enter the no of processes");
  8         scanf("%d",&n);
  9         printf("enter the burst time of each processes");
 10         for(i=0;i<n;i++)
 11         {
 12                 printf("process P[%d] ",i+1);
 13                 scanf("%d",&bt[i]);
 14                 p[i]=i+1;
 15         }
 16          printf("enter the priority  of each processes");
 17         for(i=0;i<n;i++)
 18         {
 19                 printf("process P[%d] ",i+1);
 20                 scanf("%d",&pr[i]);
 21                 p[i]=i+1;
 22         }
 23
 24         for(i=0;i<n;i++)
 25         {
 26         pos=i;
 27         for(j=i+1;j<n;j++)
 28         {
 29             if(pr[j]<pr[pos])
 30                 pos=j;
 31         }
 32
 33         temp2=pr[i];
 34         pr[i]=pr[pos];
 35         pr[pos]=temp2;
 36
 37
 38
 39         temp=bt[i];
 40         bt[i]=bt[pos];
 41         bt[pos]=temp;
 42
 43         temp1=p[i];
  p[i]=p[pos];
 45         p[pos]=temp1;
 46     }
 47
 48
 49         wt[0]=0;
 50
 51         for(i=1;i<n;i++)
 52         {
 53                 wt[i]=wt[i-1]+bt[i-1];
 54                 twt=twt+wt[i];
 55         }
 56
 57         for(i=0;i<n;i++)
 58         {
 59                 tat[i]=bt[i]+wt[i];
 60                 ttat=ttat+tat[i];
 61         }
 62
 63 printf(" PROCEES_ID \t\t BURST_TIME \t\t WAITING_TIME \t\t TURN_AROUND_TIME \n");
 64 for(i=0;i<n;i++)
 65 {
 66         printf(" %d\t\t\t       %d\t\t\t  %d\t\t\t   %d\t\t\t  \n  ",p[i],bt[i],wt[i],tat[i]);
 67 }
 68
 69 awt= (float)twt/n;
 70 atat=(float)ttat/n;
 71
 72 printf("average waiting time is %f \n",awt);
 73 printf("average turnaround time is %f",atat);
 74
 75
 76 }
 77


d)


#include<stdio.h>
  2 void main()
  3 {
  4 int bt[20],wt[20],q,t=0,i,tt[20],ibt[20],n;
  5 float awt=0,att=0;
  6 printf("Enter the no. Of process:");
  7 scanf("%d",&n);
  8 if(n>20)
  9 {
 10 printf("Invalid");
 11 }
 12 else
 13 {
 14 for(i=0;i<n;i++)
 15 {
 16 printf("\nEnter p%d bust:",i);
 17 scanf("%d",&bt[i]);
 18 ibt[i]=bt[i];
 19 }
 20 printf("\nEnter quantum:");
 21 scanf("%d",&q);
 22 while(i)
 23 {
 24 int done=1;
 25 for(i=0;i<n;i++)
 26 {
 27 if(bt[i]>0)
 28 {
 29 done=0;
 30 if(bt[i]>q)
 31 {
 32 t+=q;
 33 bt[i]=bt[i]-q;
 34 printf("p%d",i);
 35 }
 36 else
 37 {
 38 t+=bt[i];
 39 wt[i]=t-bt[i];
 40 awt+=wt[i];
 41 bt[i]=0;
 42 printf("p%d\t",i);
 43 }
 }
 45 }
 46 if(done==1)
 47 break;
 48 }
 49 for(i=0;i<n;i++)
 50 {
 51 tt[i]=wt[i]+ibt[i];
 52 att+=tt[i];
 53 }
 54 att/=n;
 55 awt/=n;
 56 printf("\npid\t\tbusttime\t\twaotingtime\t\tturnaroundtime\n");
 57 for(i=0;i<n;i++)
 58 {
 59 printf("p%d \t\t %d \t\t %d \t\t %d\n",i,ibt[i],wt[i],tt[i]);
 60 }
 61 printf("\nAverage waitingtime=%f\nAverage turnaroundtime=%f\n",awt,att);
 62 }
 63 }
