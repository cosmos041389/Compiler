#ifndef __SOURCEPOS_H__
#define __SOURCEPOS_H__

class SourcePos {
public:
	int StartCol, EndCol;
	int StartLine, EndLine;

	SourcePos()
	{
		StartCol = 0;
		EndCol = 0;
		StartLine = 0;
		EndLine = 0;
	}
	
};

#endif