#ifndef __CARGS_H
#define __CARGS_H

#include <string>
#include "format.h"

using namespace std;

namespace ispccomp {
//------------------------------------------------------------------------

//------------------------------------------------------------------------
// class CArgs
//------------------------------------------------------------------------

class CArgs
{
private:
	IMAGE_FORMAT m_format;
	string m_inputPath;
	string m_outputPath;
	bool m_valid;

private:
	string ParseOptionString(int argc, char* argv[], string shortName, string longName);
	string ParseInputPath(int argc, char* argv[]);
	string ParseOutputPath(int argc, char* argv[]);
	IMAGE_FORMAT ParseImageFormat(int argc, char* argv[]);
	bool Parse(int argc, char* argv[]);

public:
	CArgs(int argc, char* argv[]);

	bool IsValid() { return m_valid; }
	string GetInputPath() { return m_inputPath; };
	string GetOutputPath() { return m_outputPath; };
	int GetBlockW() { return ispccomp::GetBlockW(m_format); };
	int GetBlockH() { return ispccomp::GetBlockH(m_format); };
	static void Usage();
};

//------------------------------------------------------------------------

} // namespace ispccomp

#endif // __CARGS_H

// end of file.
