Day 7

Write a program to simulate the working of the dining philosopher’s problem.

PROGRAM

#include<stdio.h>
   void signal(int *s);
   void wait(int *s);
   void main()
   {
   int n,chopstick[10],i;
   printf("\nEnter the number of philosophers:");
   scanf("%d",&n);
  for(i=0;i<n;i++)
  {
          chopstick[i]=1;
  }
  for(i=0;i<n;i++)
  {
  if(chopstick[i]==1 && chopstick[(i+1)%n]==1)
  {
  wait(&chopstick[i]);
  wait(&chopstick[(i+1)%n]);
  printf("\nPhilosopher %d is eating using chopstick %d and %d....\n",i,i,((i+1)%n));
  signal(&chopstick[i]);
  signal(&chopstick[(i+1)%n]);
  printf("\nPhilosopher %d is thinking....\n",i);
  }
  }
  }
 void wait(int *s)
  {
  s--;
  }
  void signal(int *s)
  {
  s++;
  }
