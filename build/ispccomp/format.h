#ifndef __FORMAT_H
#define __FORMAT_H

//------------------------------------------------------------------------
// format.h
//------------------------------------------------------------------------

namespace ispccomp {
//------------------------------------------------------------------------

enum class IMAGE_FORMAT : int
{
	NONE,
	ASTC_4x4,
	ASTC_5x4,
	ASTC_5x5,
	ASTC_6x5,
	ASTC_6x6,
	ASTC_8x5,
	ASTC_8x6,
	ASTC_8x8,
};

inline int GetBlockW(IMAGE_FORMAT fmt)
{
	switch (fmt)
	{
	case IMAGE_FORMAT::ASTC_4x4:
		return 4;
	case IMAGE_FORMAT::ASTC_5x4:
	case IMAGE_FORMAT::ASTC_5x5:
		return 5;
	case IMAGE_FORMAT::ASTC_6x5:
	case IMAGE_FORMAT::ASTC_6x6:
		return 6;
	case IMAGE_FORMAT::ASTC_8x5:
	case IMAGE_FORMAT::ASTC_8x6:
	case IMAGE_FORMAT::ASTC_8x8:
		return 8;
	}
	return 0;
}

inline int GetBlockH(IMAGE_FORMAT fmt)
{
	switch (fmt)
	{
	case IMAGE_FORMAT::ASTC_4x4:
	case IMAGE_FORMAT::ASTC_5x4:
		return 4;
	case IMAGE_FORMAT::ASTC_5x5:
	case IMAGE_FORMAT::ASTC_6x5:
	case IMAGE_FORMAT::ASTC_8x5:
		return 5;
	case IMAGE_FORMAT::ASTC_6x6:
	case IMAGE_FORMAT::ASTC_8x6:
		return 6;
	case IMAGE_FORMAT::ASTC_8x8:
		return 8;
	}
	return 0;
}

//------------------------------------------------------------------------
} // namespace ispccomp

#endif // __FORMAT_H

// end of file
