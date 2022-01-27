#ifndef __C_ASTC_WRITER_H
#define __C_ASTC_WRITER_H

#include "CImageWriter.h"

namespace ispccomp {
//------------------------------------------------------------------------

class CAstcWriter : public CImageWriter
{
private:
    struct astc_header
    {
        uint8_t magic[4];
        uint8_t blockdim_x;
        uint8_t blockdim_y;
        uint8_t blockdim_z;
        uint8_t xsize[3];
        uint8_t ysize[3];			// x-size, y-size and z-size are given in texels;
        uint8_t zsize[3];			// block count is inferred
    };

public:
	static bool Save(void* img, int block_width, int block_height, string filename);
};

//------------------------------------------------------------------------
}; // namespace ispccomp

#endif // __C_ASTC_WRITER_H

