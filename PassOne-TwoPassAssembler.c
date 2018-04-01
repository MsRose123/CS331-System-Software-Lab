Part B

Day 8

Implement pass one of a two pass assembler.

PROGRAM

#include<stdio.h>
#include<string.h>
void main()
{
FILE *f1,*f2,*f3,*f4;
int lc,sa,l,op1,o,len;
char m1[20],la[20],op[20],otp[20];
f1=fopen("input.txt","r");
f3=fopen("symtab.txt","w");
fscanf(f1,"%s %s %d",la,m1,&op1);
if(strcmp(m1,"START")==0)
{
 sa=op1;
 lc=sa;
 printf("\t%s\t%s\t%d\n",la,m1,op1);
 }
 else
 lc=0;
fscanf(f1,"%s %s",la,m1);
while(!feof(f1))
{
 fscanf(f1,"%s",op);
 printf("\n%d\t%s\t%s\t%s\n",lc,la,m1,op);
 if(strcmp(la,"-")!=0)
 {
 fprintf(f3,"\n%d\t%s\n",lc,la);
 }
 f2=fopen("optab.txt","r");
 fscanf(f2,"%s %d",otp,&o);
 while(!feof(f2))
 {
  if(strcmp(m1,otp)==0)
  {
    lc=lc+3;
    break;
  }
  fscanf(f2,"%s %d",otp,&o);
  }
  fclose(f2);
  if(strcmp(m1,"WORD")==0)
 
    {
   lc=lc+3;
   }
   else if(strcmp(m1,"RESW")==0)
   {
    op1=atoi(op);
    lc=lc+(3*op1);
    }
    else if(strcmp(m1,"BYTE")==0)
    {
    if(op[0]=='X')
      lc=lc+1;
      else
      {
      len=strlen(op)-2;
      lc=lc+len;}
    }
    else if(strcmp(m1,"RESB")==0)
    {
     op1=atoi(op);
     lc=lc+op1;
     }
    fscanf(f1,"%s%s",la,m1);
    }
    if(strcmp(m1,"END")==0)
    {
    printf("Program length =\n%d",lc-sa);
    }
    fclose(f1);
    fclose(f3);
    
    }


Input:

Input.txt

COPY	START	1000
-	LDA	ALPHA
-	ADD	ONE
-	SUB	TWO
-	STA	BETA
ALPHA	BYTE	C'KLNCE
ONE	RESB	2
TWO	WORD	5
BETA	RESW	1
-	END	-


Optab.txt
LDA	00
STA	23
ADD	01
SUB	05


Output:

Symtab.txt

1012	ALPHA
1017	ONE
1019	TWO
1022	BETA


COPY	START	1000
1000	-	LDA	ALPHA
1003	-	ADD	ONE
1006	-	SUB	TWO
1009	-	STA	BETA
1012	ALPHA	BYTE	C'KLNCE
1017	ONE	RESB	2
1019	TWO	WORD	5
1022	BETA	RESW	1
1025	-	END	-
Program length = 25
