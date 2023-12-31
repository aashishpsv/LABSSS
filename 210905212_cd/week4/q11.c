#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#define MAXSYMBOLS 100

struct token {
    char tokenName[100];
    int row, col;
};

struct node {
	int sno;
    char lexemeName[100];
    char tokentype[100];
    char type[20];
    int size;
    char returntype[20];
};
int snum=1;
struct node symbolTable[MAXSYMBOLS];
int symbolCount = 0;

void displaySymbolTable() {
    printf("\nSymbol table\n< sno, LexemeName, token name , Type, Size, ReturnType>\n\n");
    
    for (int i = 0; i < symbolCount; i++) {
        struct node cur = symbolTable[i];
        printf(" %d\t %s\t %s\t %s\t %d\t %s\t\n",cur.sno, cur.lexemeName,cur.tokentype, cur.type, cur.size, cur.returntype);
    }
}


int searchSymbolTable(char lexemeName[100], char type[20], char returntype[20]) {
    for (int i = 0; i < symbolCount; i++) {
        if (strcmp(lexemeName, symbolTable[i].lexemeName) == 0)
            return i;
    }
    return -1;
}

void insertSymbolTable(char lexemeName[100], char type[20], char tokentype[20],char returntype[20]) {
    if (searchSymbolTable(lexemeName, type, returntype) == -1) {
        struct node n;
        strcpy(n.lexemeName, lexemeName);
        strcpy(n.type, type);
        strcpy(n.returntype, returntype);
        strcpy(n.tokentype,tokentype);
        n.sno = snum;
        if (strcmp(type, "int") == 0)
            n.size = 4;
        else if (strcmp(type, "double") == 0)
            n.size = 8;
        else if (strcmp(type, "char") == 0)
            n.size = 1;
        else if (strcmp(type, "float") == 0)
            n.size = 4;
        else if (strcmp(type,"FUNC") == 0)
        	n.size = 0;
        else {
			if(strcmp(returntype, "int") == 0)
				n.size = 4;
			else if(strcmp(returntype, "double") == 0)
			n.size = 8;
			else if(strcmp(returntype, "char") == 0)
				n.size = 1;
			else if(strcmp(returntype, "float") == 0)
				n.size = 4;
             }
        symbolTable[symbolCount++] = n;
        snum++;
    }
}



FILE *fptr;
char filename[50], buff[50], dbuff[50], c;
int ind = 0;
struct token *t;
int row = 1, col = 1;
int j;
int flag; // for storing the types of variables
int arrflag = 0;
int num = 0;

char keys[32][10] = {"auto", "break", "case", "char", 
					   "const", "continue", "default", "do", 
					   "double", "else", "enum", "extern", 
					   "float", "for", "goto", "if", 
					   "int", "long", "register", "return", 
					   "short", "signed", "sizeof", "static", 
					   "struct", "switch", "typedef", "union", 
					   "unsigned", "while", "volatile", "void"};

char symbol[8][1] = {'[', ']', '(', ')', '{', '}', ',', ';'};

int findSymbol(char ch) {
	for(int i=0; i<8; i++)
		if(symbol[i][0]==ch) return 1;
	return 0;
}

struct token* getToken(FILE* fptr) {
	struct token* newToken = (struct token*)malloc(sizeof(*newToken));
	ind = 0;
	c = fgetc(fptr);
	loop:
		if(c==EOF) return NULL;
		if(c==' ' || c=='\t') {
			while(c==' ' || c=='\t') {
				c=fgetc(fptr);
				col++;
			}
			goto loop;
		}
		if(c == '\n') {
			while(c=='\n') {
				row++;
				c=fgetc(fptr);
			}
			col = 1;
			goto loop;
		}
		if(c=='#') {
			while(c!='\n') {
				c = fgetc(fptr);
				col++;
			}
			row++;
			col = 1;
			c = fgetc(fptr);
			goto loop;
		}
		if(c=='/') {
			c = fgetc(fptr);
			col++;
			if(c=='/') {
				while(c!='\n') {
					c = fgetc(fptr);
					col++;
				}
				row++;
				col = 1;
				c = fgetc(fptr);
			}
			else if(c=='*') {
				while(1) {
					while(c!='*') {
						if(c=='\n') {
							row++;
							col = 1;
						}
						c = fgetc(fptr);
						col++;
					}
					c = fgetc(fptr);
					col++;
					if(c=='/') break;
					else continue;
				}
				c = fgetc(fptr);
				col++;
			}
			goto loop;
		}
		if(isalpha(c)!=0) {
			newToken->row = row;
			newToken->col = col;
			while(isalpha(c)!=0) {
				buff[ind++] = c;
				col++;
				c = fgetc(fptr);
			}
			fseek(fptr, -1, SEEK_CUR);
			buff[ind]='\0';
			for(j = 0; j<32; j++) {
				if(strcmp(buff, keys[j])==0) {
					strcpy(newToken->tokenName,buff);
					if(strcmp(buff, "char")==0 || strcmp(buff, "double")==0 || strcmp(buff, "float")==0 || strcmp(buff, "int")==0 || strcmp(buff, "void")==0) {
						strcpy(dbuff, buff);
						flag = 1;
					}
					memset(buff, 0, 50);
					break;
				}
			}
          if(j==32) {
   						c = fgetc(fptr);
   						fseek(fptr, -1, SEEK_CUR);
  			 if(flag == 1) {
      				if(c == '(')
         				{insertSymbolTable(buff, "FUNC", dbuff, "id");}
      				else 
         				{insertSymbolTable(buff, dbuff, "NULL", "id");}
   							}
   			memset(buff, 0, 50);
   				if(c == ';' || c == '(') {
     				 memset(dbuff, 0, 50);
      					flag = 0;
   					}
   					j++;
			}


		}
		else if(isdigit(c)!=0) {
			newToken->row = row;
			newToken->col = col;
			while(isdigit(c)!=0) {
				buff[ind++] = c;
				col++;
				c = fgetc(fptr);
			}
			fseek(fptr, -1, SEEK_CUR);
			buff[ind]='\0';
			strcpy(newToken->tokenName,"NUM");
			memset(buff, 0, 50);
		}
		else if(findSymbol(c)==1) {
			newToken->tokenName[0] = c;
			newToken->tokenName[1] = '\0';
			newToken->row = row;
			newToken->col = col;
			col++;
		}
		else if(c=='"') {
			newToken->row = row;
			newToken->col = col;
			buff[ind++]=c;
			c = fgetc(fptr);
			col++;
			while(c!='"') {
				buff[ind++]=c;
				c = fgetc(fptr);
				col++;
			}
			buff[ind++]=c;
			buff[ind]='\0';
			col++;
			strcpy(newToken->tokenName, buff);
		}
		else {
			newToken->row = row;
			newToken->col = col;
			if(c=='=') {
				buff[ind++]=c;
				c = fgetc(fptr);
				col++;
				if(c=='=') {
					buff[ind++]=c;
					buff[ind]='\0';
					strcpy(newToken->tokenName,buff);
				}
				else {
					buff[ind]='\0';
					strcpy(newToken->tokenName,buff);
					fseek(fptr, -1, SEEK_CUR);
				}
 			}
			else if(c=='<'||c=='>'||c=='!') {
				buff[ind++]=c;
				c = fgetc(fptr);
				col++;
				if(c=='=') {
					buff[ind++]=c;
					buff[ind]='\0';
					strcpy(newToken->tokenName,buff);
				}
				else {
					buff[ind]='\0';
					strcpy(newToken->tokenName,buff);
					col--;
					fseek(fptr, -1, SEEK_CUR);
				}
			}
			else if(c=='+'||c=='-'||c=='/'||c=='*') {
				buff[ind++]=c;
				c = fgetc(fptr);
				col++;
				if(buff[ind-1]=='+'||buff[ind-1]=='-') {
					if(c=='+'||c=='=') {
						buff[ind++]=c;
						buff[ind]='\0';
						col++;
						strcpy(newToken->tokenName,buff);
					}
					else if((buff[ind-1]=='+' && c=='+')||buff[ind-1]=='-' && c=='-') {
						buff[ind++]=c;
						buff[ind]='\0';
						col++;
						strcpy(newToken->tokenName,buff);
					}
					else {
						buff[ind]='\0';
						strcpy(newToken->tokenName,buff);
						fseek(fptr, -1, SEEK_CUR);
					}
				}
				else if(buff[ind-1]=='*'||buff[ind-1]=='/') {
					if(c=='=') {
						buff[ind++]=c;
						buff[ind]='\0';
						strcpy(newToken->tokenName,buff);
					}
					else {
						buff[ind]='\0';
						strcpy(newToken->tokenName,buff);
						col--;
						fseek(fptr, -1, SEEK_CUR);
					}
				}
			}
 		}
		return newToken;
}

int main() {

	printf("Enter the first file to be opened: ");
	scanf("%s", filename);
	fptr = fopen(filename, "r");
	if(!fptr) {
		printf("The file does not exist.\n");
		exit(0);
	}
	while(1) {
		t = getToken(fptr);
		if(!t) break;
		printf("<%s, %d, %d>\n", t->tokenName, t->row, t->col);
	}
	displaySymbolTable();
	fclose(fptr);
	return 0;
}