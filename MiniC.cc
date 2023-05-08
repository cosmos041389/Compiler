#include <iostream>
#include "Scanner/Scanner.hh"
#include "Scanner/SourceFile.hh"
#include "Scanner/Token.hh"

using namespace std;

Token t;
int Token::overall_nrtokens = 0;

int main(int argc, char** argv)
{
	if (argc != 2)
	{
		cout << "Usage: ./MiniC [minic_source_code]" << endl;
		return -1;
	}

	string sourceFile = argv[1];

	SourceFile source(sourceFile);
	Scanner scanner(&source);

	cout << "******** MiniC Compiler ********" << endl;
	cout << "Lexical Analysis ..." << endl;

	scanner.enableDebugging();
	do{
		t = scanner.scan();	// scan 1 token
	} while (t.kind != EOF_);	

	return 0;
}