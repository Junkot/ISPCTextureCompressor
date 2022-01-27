#include "CImageWriter.h"
#include "CAstcWriter.h"
#include "filepath.h"

namespace ispccomp {
//------------------------------------------------------------------------

// ÉZÅ[Éu
bool CImageWriter::Save(void* img, int bw, int bh, string filename)
{
	switch (GetOutputType(filename))
	{
	case OUTPUT_TYPE::ASTC:
		return CAstcWriter::Save(img, bw, bh, filename);
	}
	return false;
}


//------------------------------------------------------------------------
}; // namespace ispccomp

// end of file.


