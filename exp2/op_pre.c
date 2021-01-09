#include <stdio.h>
#include <stdlib.h>
int precedence(char symb)
{
switch(symb)
{
case 'i': return 0;
case '+': return 1;
case '*': return 2;
case '$': return 3;
}
}
void main(){
char relation[4][4]={{'E','>','>','>'},{'<','>','<','>'},{'<','>','>','>'},{'<','<','<','A'}};
char str[10];
char op;
int i, j;
char stack[10];
stack[0]='$';
int top = 0;
printf("Precedence Table\n");
printf("id \t + \t * \t $\n");
for (i=0;i<4;i++)
{
for (j=0;j<4;j++)
printf("%c\t", relation[i][j]);
printf("\n");
}
printf("Enter input:");
scanf("%s",str);
printf("%s\n",str);
int k=0;
while(str[k]!='\0')
{
op = relation[precedence(stack[top])][precedence(str[k])];
if (op == '<')
{
top++;
stack[top]=str[k];
k++;
}
else if (op == '>')
top--;
else if (op =='E')
{
printf("Invalid\n");
break;
}
else if (op == 'A')
{
printf("Valid\n");
break;
}
}
}
