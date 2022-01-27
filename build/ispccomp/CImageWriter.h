#ifndef __C_IMAGE_WRITER_H
#define __C_IMAGE_WRITER_H

#include <string>

using namespace std;

namespace ispccomp {
//------------------------------------------------------------------------

//------------------------------------------------------------------------
// class class CImageWriter
//------------------------------------------------------------------------

class CImageWriter
{
public:
	static bool Save(void* img, int block_width, int block_height, string filename);
};

//------------------------------------------------------------------------
}; // namespace ispccomp

#endif // __C_IMAGE_WRITER_H

// end of file