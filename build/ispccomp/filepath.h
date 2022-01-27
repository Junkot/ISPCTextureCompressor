#ifndef __FILEPATH_H
#define __FILEPATH_H

#include <string>

using namespace std;

namespace ispccomp {
//------------------------------------------------------------------------

enum class INPUT_TYPE : int
{
	NONE,
	BMP,
	TGA,
	PNG,
};

enum class OUTPUT_TYPE : int
{
	NONE,
	DDS,
	ASTC,
};

inline INPUT_TYPE GetInputType(string path)
{
	size_t i = path.rfind('.');
	if (i >= 0)
	{
		++i;
		size_t siz = path.length() - i;
		string ext = path.substr(i, siz);

		if (ext.compare("bmp") == 0 || ext.compare("BMP") == 0)
		{
			return INPUT_TYPE::BMP;
		}

		if (ext.compare("tga") == 0 || ext.compare("TGA") == 0)
		{
			return INPUT_TYPE::TGA;
		}

		if (ext.compare("png") == 0 || ext.compare("PNG") == 0)
		{
			return INPUT_TYPE::PNG;
		}
	}
	return INPUT_TYPE::NONE;
}

inline OUTPUT_TYPE GetOutputType(string path)
{
	size_t i = path.rfind('.');
	if (i >= 0)
	{
		++i;
		size_t siz = path.length() - i;
		string ext = path.substr(i, siz);

		if (ext.compare("dds") == 0 || ext.compare("dds") == 0)
		{
			return OUTPUT_TYPE::DDS;
		}

		if (ext.compare("astc") == 0 || ext.compare("ASTC") == 0)
		{
			return OUTPUT_TYPE::ASTC;
		}
	}
	return OUTPUT_TYPE::NONE;
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

