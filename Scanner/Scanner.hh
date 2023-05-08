#ifndef __SCANNER_H__
#define __SCANNER_H__

#include "SourceFile.hh"
#include "SourcePos.hh"
#include "Token.hh"
#include <string>

class Scanner {

private:

	SourceFile	*sourceFile;
	bool		verbose;
	char		currentChar;
	string		currentLexeme;
	bool		currentlyScanningToken;
	int			currentLineNr;
	int			currentColNr;

	bool isDigit(char c);
	void takeIt();
	int scanToken();

public:
	Scanner(SourceFile *source);
	void enableDebugging();
	Token scan();

};

#endif