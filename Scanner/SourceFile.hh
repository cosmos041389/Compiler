#ifndef __SOURCEFILE_H__
#define __SOURCEFILE_H__

#include <iostream>
#include <fstream>
#include "SourceFile.hh"

using namespace std;

const char _EOL = '\n';
const char _EOF = '\u0000';

class SourceFile
{
public:
	ifstream source;
	SourceFile (string filename);
	char readChar();
};

#endif