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
int lex_index;
int notFlag == 0;
int flag == 0;
int colFlag == 0;
int count == 0;
int idHelp == 0;

char idArray[10] = ' ';

void printlexerror(int type);
void printtokens();


lexeme *lexanalyzer(char *input)
{
	//iterate over input
	for(int i = 0; input[i] != '\0'; i++)	{

		// identifiers
		if(isalpha(input[i]))	{

			if(!isalpha(input[i]) || !isdigit(input[i]))

			for(i; isalpha(input[i]) || isdigit(input[i]) || idHelp != 11; idHelp++)	{
				idArray[i] == input[i];

				if(idHelp == 11)
					printlexerror(2);
			}


		}

		// basic 1 char tokens
		if(input[i] == ';')	{
			list[count].type == semicolonsym;
			count++;
		}

		if(input[i] == '.')	{
			list[count].type == periodsym;
			count++;
		}

		if(input[i] == ',')	{
			list[count].type == commasym;
			count++;
		}

		if(input[i] == ')')	{
			list[count].type == rparensym;
			count++;
		}

		if(input[i] == '(')	{
			list[count].type == lparensym;
			count++;
		}

		if(input[i] == '%')	{
			list[count].type == modsym;
			count++;
		}

		if(input[i] == '/')	{
			list[count].type == divsym;
			count++;
		}

		if(input[i] == '*')	{
			list[count].type == multsym;
			count++;
		}

		if(input[i] == '-')	{
			list[count].type == subsym;
			count++;
		}
		
		if(input[i] == '+')	{
			list[count].type == addsym;
			count++;
		}

		if(input[i] == '<' && input[i + 1] != '=')	{
			list[count].type == lsssym;
			count++;
		}

		if(input[i] == '>' && input[i + 1] != '=')	{
			list[count].type == gtrsym;
			count++;
		}

		// multi char syms
		if(input[i] == ':' && input[i + 1] == '=')	{
			list[count].type == assignsym;
			count++;
		}

		if(input[i] == '=' && input[i + 1] == '=')	{
			list[count].type == eqlsym;
			count++;
		}

		if(input[i] == '!' && input[i + 1] == '=')	{
			list[count].type == neqsym;
			count++;
		}

		if(input[i] == '<' && input[i + 1] == '=')	{
			list[count].type == leqsym;
			count++;
		}

		if(input[i] == '>' && input[i + 1] == '=')	{
			list[count].type == geqsym;
			count++;
		}

	}


	return NULL;
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