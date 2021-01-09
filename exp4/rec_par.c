#include<stdio.h>
char l;
void main()
{
printf("Enter the expression to be parsed:\t");
l=getchar();
E();
if(l=='$')
{
printf("parsing is sucess\n");
}
else
{
printf("cannot be derived\n");
}
}
void E()
{
if(l=='i')
{
match('i');
Eprime();
}
}
void Eprime()
{
if(l=='+')
{
match('+');
match('i');
Eprime();
}
else
return;
}
void match(char t)
{
if(l==t)
l=getchar();
else
printf("error\n");
}
