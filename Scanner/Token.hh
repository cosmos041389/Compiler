#ifndef __TOKEN_H__
#define __TOKEN_H__

#include <iostream>
#include <string>
#include <algorithm>
#include "SourcePos.hh"

using namespace std;

enum TokenType {
    ID      = 0,
    ASSIGN  = 1,
    OR      = 2,
    AND     = 3,
    NOT     = 4,
    EQ      = 5,
    NOTEQ   = 6,
    LESSEQ  = 7,
    LESS    = 8,
    GREATER = 9,
    GREATEREQ = 10,
    PLUS    = 11,
    MINUS   = 12,
    TIMES   = 13,
    DIV     = 14,
    INTLITERAL    = 15,
    FLOATLITERAL  = 16,
    BOOLLITERAL   = 17,
    STRINGLITERAL = 18,
    BOOL    = 19,
    ELSE    = 20,
    FLOAT   = 21,
    FOR     = 22,
    IF      = 23,
    INT     = 24,
    RETURN  = 25,
    VOID    = 26,
    WHILE   = 27,
    LEFTBRACE     = 28,
    RIGHTBRACE    = 29,
    LEFTBRACKET   = 30,
    RIGHTBRACKET  = 31,
    LEFTPAREN     = 32,
    RIGHTPAREN    = 33,
    COMMA         = 34,
    SEMICOLON     = 35,
    ERROR = 36,
    EOF_  = 37
};

const string lexemeTable[38] = 
{
	"ID",
	"=",
	"||",
	"&&",
	"!",
	"==",
	"!=",
	"<=",
	"<",
	">",
	">=",
	"+",
	"-",
	"*",
	"/",
	"INTLITERAL",
	"FLOATLITERAL",
	"BOOLLITERAL",
	"STRINGLITERAL",
	"bool",
	"else",
	"float",
	"for",
	"if",
	"int",
	"return",
	"void",
	"while",
	"{",
	"}",
	"[",
	"]",
	"(",
	")",
	",",
	";",
	"ERROR",
	"EOF"
};

const string tokenTable[38] = 
{
	"ID",
	"ASSIGN",
	"OR",
	"AND",
	"NOT",
	"EQ",
	"NOTEQ",
	"LESSEQ",
	"LESS",
	"GREATER",
	"GREATEREQ",
	"PLUS",
	"MINUS",
	"TIMES",
	"DIV",
	"INTLITERAL",
	"FLOATLITERAL",
	"BOOLLITERAL",
	"STRINGLITERAL",
	"bool",
	"else",
	"float",
	"for",
	"if",
	"int",
	"return",
	"void",
	"while",
	"LEFTBRACE",
	"RIGHTBRACE",
	"LEFTBRACKET",
	"RIGHTBRACKET",
	"LEFTPAREN",
	"RIGHTPAREN",
	"COMMA",
	"SEMICOLON",
	"ERROR",
	"EOF"
};


class Token {

public:
	int 		kind;
	string		lexeme;
	SourcePos	src_pos;
	static int	overall_nrtokens;
	int			my_tokennr;

	Token();
	Token(const Token& t);
	Token(int kind, string lexeme, SourcePos src_pos);
	void print();

	SourcePos GetSourcePos();
	string GetLexeme();

private:

	string toUpperCase(string str);

	static const int firstKeyword = 19; //Token.BOOL;
    static const int lastKeyword = 27; //Token.WHILE;

	string spell (int kind);

};

#endif