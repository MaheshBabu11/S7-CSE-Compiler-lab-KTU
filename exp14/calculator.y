
%{
#include <stdio.h>
//extern FILE *yyin;
%}
%token NUMBER
%start S
%%

S       : E		{ printf("Expression_value= %d\n", $1); }
	;
E       : E '+' NUMBER	{ $$ = $1 + $3;
			printf ("Recognized '+' expression.\n");
			}
	| E '-' NUMBER	{ $$ = $1 - $3; 
			printf ("Recognized '-' expression.\n");
			}
	| E '*' NUMBER { $$ = $1 * $3; 
			printf ("Recognized '*' expression.\n"); 
			}
	| E '/' NUMBER { if($3==0)
			{
			printf("Cannot divide by 0");
			break;
			}
			else
			$$ = $1 / $3; 
			printf ("Recognized '/' expression.\n");
			
		        }	
	| NUMBER	{ $$ = $1; 
			printf ("Recognized a number.\n");
			}
	;
%%
int main () 
	{
	//yyin=fopen("s.txt","r");
	do
	{printf("Enter the expression\n");
	 yyparse();
	}while(1);
	return 1;
	
	}

int yyerror (char *msg) 
	{
		printf("Invalid Expression\n");
	}
yywrap()
{
  return(1);
}



