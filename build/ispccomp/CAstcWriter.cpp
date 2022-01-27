#include <cstdio>
#include <cassert>
#include <windows.h>
#include <vector>
#include "ispc_texcomp.h"

#include "CAstcWriter.h"

#define MAGIC_FILE_CONSTANT 0x5CA1AB13

namespace ispccomp {
//------------------------------------------------------------------------

bool CAstcWriter::Save(void* ptr, int bw, int bh, string filename)
{
	rgba_surface* img = static_cast<rgba_surface*>(ptr);

    FILE* f = fopen(filename.c_str(), "wb");
    if (f != NULL)
    {
        astc_header file_header;

        uint32_t magic = MAGIC_FILE_CONSTANT;
        memcpy(file_header.magic, &magic, 4);
        file_header.blockdim_x = bw;
        file_header.blockdim_y = bh;
        file_header.blockdim_z = 1;

        int xsize = img->width;
        int ysize = img->height;
        int zsize = 1;

        memcpy(file_header.xsize, &xsize, 3);
        memcpy(file_header.ysize, &ysize, 3);
        memcpy(file_header.zsize, &zsize, 3);

        fwrite(&file_header, sizeof(astc_header), 1, f);

        size_t height_in_blocks = (bh + img->height - 1) / bh;
        fwrite(img->ptr, height_in_blocks * img->stride, 1, f);

        fclose(f);
        return true;
    }
    return false;
}

//------------------------------------------------------------------------
}; // namespace ispccomp

// end of file/