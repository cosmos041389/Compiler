#include "Token.hh"

Token::Token()
{
	this->kind = 0;
	this->lexeme = "";
}

Token::Token(const Token& t)
{
	this->kind = t.kind;
	this->lexeme = t.lexeme;
	this->src_pos = t.src_pos;
}

Token::Token(int kind, string lexeme, SourcePos src_pos)
{
	if (kind == ID)
	{
		int index = firstKeyword;
		bool searching = true;
		while (searching){
			int compare = tokenTable[index].compare(lexeme);
			if (compare == 0){
				this->kind = index;
				searching = false;
			} else if (compare > 0 || index == lastKeyword){
				this->kind = ID;
				searching = false;
			} else {
				index++;
			}
		}
	} else {
		this->kind = kind;
	}
	this->lexeme = lexeme;
	this->src_pos = src_pos;
	this->overall_nrtokens++;
	this->my_tokennr = overall_nrtokens;
}

void Token::print()
{
	cout << "token" << this->my_tokennr << ".kind = Token." << toUpperCase(tokenTable[kind]) << endl;
	cout << "token" << this->my_tokennr << ".lexeme = \"" << this->lexeme << "\"" << endl;
	cout << "token" << this->my_tokennr << ".src_pos.StartLine = " << this->src_pos.StartLine << endl;
	cout << "token" << this->my_tokennr << ".src_pos.EndLine = " << this->src_pos.EndLine << endl;
	cout << "token" << this->my_tokennr << ".src_pos.StartCol = " << this->src_pos.StartCol << endl;
	cout << "token" << this->my_tokennr << ".src_pos.EndCol = " << this->src_pos.EndCol << endl << endl;
}

SourcePos Token::GetSourcePos()
{
	return this->src_pos;
}

string Token::GetLexeme()
{
	return this->lexeme;
}

string Token::toUpperCase(string str)
{
	for (auto &c: str) c = toupper(c);
	return str;
}


string Token::spell(int kind)
{
	return lexemeTable[kind];
}
