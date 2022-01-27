#ifndef __FILEPATH_H
#define __FILEPATH_H

#include <string>

using namespace std;

namespace ispccomp {
//------------------------------------------------------------------------

enum class IMAGE_TYPE : int
{
	NONE,
	BMP,
	TGA,
	PNG,
};

inline IMAGE_TYPE GetImageType(string path)
{
	size_t i = path.rfind('.');
	if (i >= 0)
	{
		size_t siz = path.length() - i;
		string ext = path.substr(i, siz);

		if (ext.compare("bmp") == 0 || ext.compare("BMP") == 0)
		{
			return IMAGE_TYPE::BMP;
		}

		if (ext.compare("tga") == 0 || ext.compare("TGA") == 0)
		{
			return IMAGE_TYPE::TGA;
		}

		if (ext.compare("png") == 0 || ext.compare("PNG") == 0)
		{
			return IMAGE_TYPE::PNG;
		}
	}
	return IMAGE_TYPE::NONE;
}

inline string GetPathWithoutExt(string path)
{
	size_t i = path.rfind('.');
	if (i >= 0)
	{
		return path.substr(0, i);
	}
	return "";
}

//------------------------------------------------------------------------
} // namespace ispccomp

#endif // __FILEPATH_H

// end of file.

