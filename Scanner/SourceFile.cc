#include "SourceFile.hh"

SourceFile::SourceFile (string filename)
{
	this->source.open(filename);
	if (!this->source)
	{
		cerr << "Error opening file " << filename << endl;
		cerr << "Exiting..." << endl;
		exit(-1);
	}
}

char SourceFile::readChar()
{
	int c = this->source.get();
	if (this->source.eof())
		c = _EOF;
	return (char) c;
}