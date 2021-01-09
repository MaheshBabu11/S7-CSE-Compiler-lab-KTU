#include<stdio.h>
#include<string.h>
FILE *fp;
int lineno=0;
char c;
char lexbuf[50],symtab[50][20];
int i=0,x;
char
kw[30][20]={"void","int","float","double","short","long","if","else","switch","case","break",
"return","main","static","goto"};
char delim[]={'(',')','{','}','[',']',';',','};
char oper[]={'+','=','-','*','/','<','>'};
int isdelim(char);
int isoper(char);
int iskw(char[]);
void main()
{
fp=fopen("sample.c","r");
c=getc(fp);
while(c!=EOF)
{
if(c==' '||c=='\t');
else if(c=='\n')
{
lineno++;
}
else if((x=isdelim(c))!=-1)
{
printf("%c\t\tDelimiter\n",c);
}
else if((x=isoper(c))!=-1)
{
printf("%c\t\tOperator\n",c);
}
else if(isdigit(c))
{
int b=0;
while(isdigit(c))
{
lexbuf[b++]=c;
c=getc(fp);
}
ungetc(c,fp);
lexbuf[b]='\0';
printf("%s\t\tDigit\n",lexbuf);
}
else if(isalpha(c))
{
int b=0,k;
while(isalpha(c)||isdigit(c)||c=='_')
{
lexbuf[b++]=c;
c=getc(fp);
}
ungetc(c,fp);
lexbuf[b]='\0';
if((!(lookup(lexbuf)))&&(!iskw(lexbuf)))
{
strcpy(symtab[i++],lexbuf);
}
if((k=iskw(lexbuf))!=0)
{
printf("%s\t\t Keyword\n",lexbuf);
}
else
{
printf("%s\t\tIdentifier\n",lexbuf);
}
}
c=getc(fp);
}
fclose(fp);
printf("\nNumber of lines=%d\n",lineno-1);
}
//Is delimiter
int isdelim(char d)
{
int k;
for(k=0;k<8;k++)
{
if(d==delim[k])
{
return k;
}
}
return -1;
}
//Is operator
int isoper(char op)
{
int k;
//printf("%c\n",op);
for(k=0;k<7;k++)
{
if(op==oper[k])
{
return k;
}
}
return -1;
}
int lookup(char s[])
{
int k;
for(k=0;k<i;k++)
{
if((strcmp(s,symtab[k]))==0)
{
return k+1;
}
return 0;
}
}
int iskw(char s[])
{
int k;
for(k=0;k<15;k++)
{
if(strcmp(s,kw[k])==0)
return k+1;
}
return 0;
}
