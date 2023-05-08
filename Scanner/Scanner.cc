#include "Scanner.hh"

bool Scanner::isDigit(char c){
	return (c>='0' && c <='9');
}

Scanner::Scanner(SourceFile *source){
	this->sourceFile = source;
	this->currentChar = this->sourceFile->readChar();
	this->verbose = false;
	this->currentLineNr = -1;
	this->currentColNr = -1;
}

void Scanner::enableDebugging() {
	this->verbose = true;
}

// takeIt appends the current character to the current token, and gets
// the next character from the source program (or the to-be-implemented
// "untake" buffer in case of look-ahead characters that got 'pushed back'
// into the input stream).

void Scanner::takeIt(){
	if (this->currentlyScanningToken) {
		this->currentLexeme += this->currentChar;
	}
	this->currentChar = this->sourceFile->readChar();
}
	
int Scanner::scanToken() {
	switch (this->currentChar) {
		case '0':  case '1':  case '2':  case '3':  case '4':
		case '5':  case '6':  case '7':  case '8':  case '9':
			takeIt();
			while (isDigit(this->currentChar)) {
				takeIt();
			} 
			// Note: code for floating point literals is missing here...
			return INTLITERAL;
		case '+':
			takeIt();
			return PLUS;
		case _EOF:
			this->currentLexeme.append("$");
			return EOF_;
		// Add code here for the remaining MiniC tokens...

		default:
			takeIt();
			return ERROR;
	}
}

Token Scanner::scan(){
	Token		currentToken;
	SourcePos	pos;
	int			kind;

	currentlyScanningToken = false;

	while (currentChar == ' '
			|| currentChar == '\f'
			|| currentChar == '\n'
			|| currentChar == '\r'
			|| currentChar == '\t'){
		takeIt();
	}

	this->currentlyScanningToken = true;
	this->currentLexeme = "";
	pos = SourcePos();
	// Note: currentLineNr and currentColNr are not maintained yet!
	pos.StartLine = this->currentLineNr;
	pos.EndLine = this->currentLineNr;
	pos.StartCol = this->currentColNr;
	
	kind = scanToken();
	currentToken = Token(kind, this->currentLexeme, pos);
	
	pos.EndCol = this->currentColNr;
	if (this->verbose)
		currentToken.print();

	return currentToken;
}