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

public:
	CArgs(int argc, char* argv[]);

	bool IsValid();
	string GetInputPath() { return m_inputPath; };
	string GetOutputPath() { return m_outputPath; };

	static void Usage();
};

//------------------------------------------------------------------------

} // namespace ispccomp

#endif // __CARGS_H

// end of file.
