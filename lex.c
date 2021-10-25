// Alec Carson HW 2
// COP3402 Fall 2021


#include <stdlib.h>
#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include "compiler.h"
#define MAX_NUMBER_TOKENS 500
#define MAX_IDENT_LEN 11
#define MAX_NUMBER_LEN 5

lexeme *list;
int tmp = 0;
int lex_index = 0;
int notFlag = 0;
int flag = 0;
int colFlag = 0;
int idHelp = 0;


char idArray[10];

void printlexerror(int type);
void printtokens();

// helper function that concats 2 integer values together
unsigned concatInt(unsigned x, unsigned y)	{
	unsigned pow = 10;

	while(y >= pow)
		pow *= 10;

	return x * pow + y;
}

lexeme *lexanalyzer(char *input)
{
	lexeme *list = malloc(MAX_NUMBER_TOKENS * sizeof(lexeme));

	//iterate over input
	for(int i = 0; input[i] != '\0'; i++)	{

		// numerical inputs
		if(isdigit(input[i]))	{
			int numCount = 0;

			for(i; isdigit(input[i] && isdigit(input[i + 1])); i++)	{
				// number too long
				if(numCount == 6)	{					
					printlexerror(3);
					return NULL;
				}

				tmp = concatInt(tmp, input[i + 1]);
				numCount++;
			}

			list[lex_index].value = tmp;
			list[lex_index].type = numbersym;

			lex_index++;
		}

		// identifiers and reserved words
		if(isalpha(input[i]))	{
			int z = 0;

			//if(!isalpha(input[i]) || !isdigit(input[i]))
				

			for(i; isalpha(input[i]) || isdigit(input[i]); z++)	{
			
				if(z == 11)	{
					printlexerror(2);
					return NULL;
				}
			
				list[lex_index].name[z] = input[i];
				idArray[z] =  input[i];
				i++;
			}
			// reserved word check
			if(!strcmp(idArray, "const"))
				list[lex_index].type = constsym;

			if(!strcmp(idArray, "var"))
				list[lex_index].type = varsym;

			if(!strcmp(idArray, "procedure"))
				list[lex_index].type = procsym;

			if(!strcmp(idArray, "call"))	
				list[lex_index].type = callsym;

			if(!strcmp(idArray, "if"))
				list[lex_index].type = ifsym;

			if(!strcmp(idArray, "then"))
				list[lex_index].type = thensym;

			if(!strcmp(idArray, "else"))
				list[lex_index].type = elsesym;

			if(!strcmp(idArray, "while"))
				list[lex_index].type = whilesym;

			if(!strcmp(idArray, "do"))
				list[lex_index].type = dosym;

			if(!strcmp(idArray, "begin"))
				list[lex_index].type = beginsym;

			if(!strcmp(idArray, "cend"))
				list[lex_index].type = endsym;
			
			if(!strcmp(idArray, "read"))
				list[lex_index].type = readsym;

			if(!strcmp(idArray, "write"))
				list[lex_index].type = writesym;

			if(!strcmp(idArray, "odd"))
				list[lex_index].type = oddsym;
		else
			list[lex_index].type = identsym;

			lex_index++;
		}

		// comments
		if(input[i] == '/' && input[i + 1] == '/')	{
			while(input[i] != '\n')
				i++;
		}

		// basic 1 char tokens
		if(input[i] == ';')	{
			list[lex_index].type = semicolonsym;
			lex_index++;
		}

		if(input[i] == '.')	{
			list[lex_index].type = periodsym;
			lex_index++;
		}

		if(input[i] == ',')	{
			list[lex_index].type = commasym;
			lex_index++;
		}

		if(input[i] == ')')	{
			list[lex_index].type = rparensym;
			lex_index++;
		}

		if(input[i] == '(')	{
			list[lex_index].type = lparensym;
			lex_index++;
		}

		if(input[i] == '%')	{
			list[lex_index].type = modsym;
			lex_index++;
		}

		if(input[i] == '/' && input[i + 1] != '/')	{
			list[lex_index].type = divsym;
			lex_index++;
		}

		if(input[i] == '*')	{
			list[lex_index].type = multsym;
			lex_index++;
		}

		if(input[i] == '-')	{
			list[lex_index].type = subsym;
			lex_index++;
		}
		
		if(input[i] == '+')	{
			list[lex_index].type = addsym;
			lex_index++;
		}

		if(input[i] == '<' && input[i + 1] != '=')	{
			list[lex_index].type = lsssym;
			lex_index++;
		}

		if(input[i] == '>' && input[i + 1] != '=')	{
			list[lex_index].type = gtrsym;
			lex_index++;
		}

		// multi char syms
		if(input[i] == ':' && input[i + 1] == '=')	{
			list[lex_index].type = assignsym;
			lex_index++;
		}

		if(input[i] == '=' && input[i + 1] == '=')	{
			list[lex_index].type = eqlsym;
			lex_index++;
		}

		if(input[i] == '!' && input[i + 1] == '=')	{
			list[lex_index].type = neqsym;
			lex_index++;
		}

		if(input[i] == '<' && input[i + 1] == '=')	{
			list[lex_index].type = leqsym;
			lex_index++;
		}

		if(input[i] == '>' && input[i + 1] == '=')	{
			list[lex_index].type = geqsym;
			lex_index++;
		}



	}
	
	// print function broken, but the code works in here
	printf("Lexeme Table:\n");
	printf("lexeme\t\ttoken type\n");
	for (int i = 0; i < lex_index; i++)
	{
		switch (list[i].type)
		{
			case oddsym:
				printf("%11s\t%d", "odd", oddsym);
				break;
			case eqlsym:
				printf("%11s\t%d", "==", eqlsym);
				break;
			case neqsym:
				printf("%11s\t%d", "!=", neqsym);
				break;
			case lsssym:
				printf("%11s\t%d", "<", lsssym);
				break;
			case leqsym:
				printf("%11s\t%d", "<=", leqsym);
				break;
			case gtrsym:
				printf("%11s\t%d", ">", gtrsym);
				break;
			case geqsym:
				printf("%11s\t%d", ">=", geqsym);
				break;
			case modsym:
				printf("%11s\t%d", "%", modsym);
				break;
			case multsym:
				printf("%11s\t%d", "*", multsym);
				break;
			case divsym:
				printf("%11s\t%d", "/", divsym);
				break;
			case addsym:
				printf("%11s\t%d", "+", addsym);
				break;
			case subsym:
				printf("%11s\t%d", "-", subsym);
				break;
			case lparensym:
				printf("%11s\t%d", "(", lparensym);
				break;
			case rparensym:
				printf("%11s\t%d", ")", rparensym);
				break;
			case commasym:
				printf("%11s\t%d", ",", commasym);
				break;
			case periodsym:
				printf("%11s\t%d", ".", periodsym);
				break;
			case semicolonsym:
				printf("%11s\t%d", ";", semicolonsym);
				break;
			case assignsym:
				printf("%11s\t%d", ":=", assignsym);
				break;
			case beginsym:
				printf("%11s\t%d", "begin", beginsym);
				break;
			case endsym:
				printf("%11s\t%d", "end", endsym);
				break;
			case ifsym:
				printf("%11s\t%d", "if", ifsym);
				break;
			case thensym:
				printf("%11s\t%d", "then", thensym);
				break;
			case elsesym:
				printf("%11s\t%d", "else", elsesym);
				break;
			case whilesym:
				printf("%11s\t%d", "while", whilesym);
				break;
			case dosym:
				printf("%11s\t%d", "do", dosym);
				break;
			case callsym:
				printf("%11s\t%d", "call", callsym);
				break;
			case writesym:
				printf("%11s\t%d", "write", writesym);
				break;
			case readsym:
				printf("%11s\t%d", "read", readsym);
				break;
			case constsym:
				printf("%11s\t%d", "const", constsym);
				break;
			case varsym:
				printf("%11s\t%d", "var", varsym);
				break;
			case procsym:
				printf("%11s\t%d", "procedure", procsym);
				break;
			case identsym:
				printf("%11s\t%d", list[i].name, identsym);
				break;
			case numbersym:
				printf("%11d\t%d", list[i].value, numbersym);
				break;
		}
		printf("\n");
	}
	printf("\n");
	printf("Token List:\n");
	for (int i = 0; i < lex_index; i++)
	{
		if (list[i].type == numbersym)
			printf("%d %d ", numbersym, list[i].value);
		else if (list[i].type == identsym)
			printf("%d %s ", identsym, list[i].name);
		else
			printf("%d ", list[i].type);
	}
	printf("\n");

	list[lex_index++].type = -1;
	
	return list;
}


void printtokens()
{
	int i;
	printf("Lexeme Table:\n");
	printf("lexeme\t\ttoken type\n");
	for (i = 0; i < lex_index; i++)
	{
		switch (list[i].type)
		{
			case oddsym:
				printf("%11s\t%d", "odd", oddsym);
				break;
			case eqlsym:
				printf("%11s\t%d", "==", eqlsym);
				break;
			case neqsym:
				printf("%11s\t%d", "!=", neqsym);
				break;
			case lsssym:
				printf("%11s\t%d", "<", lsssym);
				break;
			case leqsym:
				printf("%11s\t%d", "<=", leqsym);
				break;
			case gtrsym:
				printf("%11s\t%d", ">", gtrsym);
				break;
			case geqsym:
				printf("%11s\t%d", ">=", geqsym);
				break;
			case modsym:
				printf("%11s\t%d", "%", modsym);
				break;
			case multsym:
				printf("%11s\t%d", "*", multsym);
				break;
			case divsym:
				printf("%11s\t%d", "/", divsym);
				break;
			case addsym:
				printf("%11s\t%d", "+", addsym);
				break;
			case subsym:
				printf("%11s\t%d", "-", subsym);
				break;
			case lparensym:
				printf("%11s\t%d", "(", lparensym);
				break;
			case rparensym:
				printf("%11s\t%d", ")", rparensym);
				break;
			case commasym:
				printf("%11s\t%d", ",", commasym);
				break;
			case periodsym:
				printf("%11s\t%d", ".", periodsym);
				break;
			case semicolonsym:
				printf("%11s\t%d", ";", semicolonsym);
				break;
			case assignsym:
				printf("%11s\t%d", ":=", assignsym);
				break;
			case beginsym:
				printf("%11s\t%d", "begin", beginsym);
				break;
			case endsym:
				printf("%11s\t%d", "end", endsym);
				break;
			case ifsym:
				printf("%11s\t%d", "if", ifsym);
				break;
			case thensym:
				printf("%11s\t%d", "then", thensym);
				break;
			case elsesym:
				printf("%11s\t%d", "else", elsesym);
				break;
			case whilesym:
				printf("%11s\t%d", "while", whilesym);
				break;
			case dosym:
				printf("%11s\t%d", "do", dosym);
				break;
			case callsym:
				printf("%11s\t%d", "call", callsym);
				break;
			case writesym:
				printf("%11s\t%d", "write", writesym);
				break;
			case readsym:
				printf("%11s\t%d", "read", readsym);
				break;
			case constsym:
				printf("%11s\t%d", "const", constsym);
				break;
			case varsym:
				printf("%11s\t%d", "var", varsym);
				break;
			case procsym:
				printf("%11s\t%d", "procedure", procsym);
				break;
			case identsym:
				printf("%11s\t%d", list[i].name, identsym);
				break;
			case numbersym:
				printf("%11d\t%d", list[i].value, numbersym);
				break;
		}
		printf("\n");
	}
	printf("\n");
	printf("Token List:\n");
	for (i = 0; i < lex_index; i++)
	{
		if (list[i].type == numbersym)
			printf("%d %d ", numbersym, list[i].value);
		else if (list[i].type == identsym)
			printf("%d %s ", identsym, list[i].name);
		else
			printf("%d ", list[i].type);
	}
	printf("\n");
	list[lex_index++].type = -1;
}

void printlexerror(int type)
{
	if (type == 1)
		printf("Lexical Analyzer Error: Invalid Symbol\n");
	else if (type == 2)
		printf("Lexical Analyzer Error: Invalid Identifier\n");
	else if (type == 3)
		printf("Lexical Analyzer Error: Excessive Number Length\n");
	else if (type == 4)
		printf("Lexical Analyzer Error: Excessive Identifier Length\n");
	else
		printf("Implementation Error: Unrecognized Error Type\n");
	
	free(list);
	return;
}