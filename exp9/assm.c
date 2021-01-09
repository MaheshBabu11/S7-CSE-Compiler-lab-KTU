#include<stdio.h>
#include<string.h>
struct code
{
char op[2],arg1[5],arg2[5],result[5];
}in[10];
void main()
{
int n,i;
printf("enter the number of instructions\n");
scanf("%d",&n);
printf("Enter the instructions\n");
for(i=0;i<n;i++)
{
scanf("%s%s%s%s",in[i].op,in[i].arg1,in[i].arg2,in[i].result);
}
for(i=0;i<n;i++)
{
if(strcmp(in[i].op,"+")==0)
{
printf("\nMOV R0,%s",in[i].arg1);
printf("\nADD R0,%s",in[i].arg2);
printf("\nMOV %s,R0",in[i].result);
}
if(strcmp(in[i].op,"*")==0)
{
printf("\nMOV R0,%s",in[i].arg1);
printf("\nMUL R0,%s",in[i].arg2);
printf("\nMOV %s,R0",in[i].result);
}
if(strcmp(in[i].op,"-")==0)
{
printf("\nMOV R0,%s",in[i].arg1);
printf("\nSUB R0,%s",in[i].arg2);
printf("\nMOV %s,R0",in[i].result);
}
if(strcmp(in[i].op,"/")==0)
{
printf("\nMOV R0,%s",in[i].arg1);
printf("\nDIV R0,%s",in[i].arg2);
printf("\nMOV %s,R0",in[i].result);
}
if(strcmp(in[i].op,"=")==0)
{

printf("\nMOV R0,%s",in[i].arg1);
printf("\nMOV %s,R0",in[i].result);
}
}
printf("\n");
}
