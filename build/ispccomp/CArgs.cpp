#include<fstream>
#include<iostream>
#include "CArgs.h"
#include "filepath.h"
#include "format.h"

namespace ispccomp {
//------------------------------------------------------------------------

//------------------------------------------------------------------------
// class CArgs
//------------------------------------------------------------------------

// コンストラクタ
CArgs::CArgs(int argc, char* argv[])
{
	Parse(argc, argv);
}

string CArgs::ParseOptionString(int argc, char* argv[], string shortName, string longName)
{
	for (int i = 1; i < argc - 2; i++)
	{
		if (shortName.compare(argv[i]) == 0 || longName.compare(argv[i]) == 0)
		{
			return argv[i + 1];
		}
	}
	return "";
}

// 入力ファイル
string CArgs::ParseInputPath(int argc, char* argv[])
{
	if (argc >= 2)
	{
		string path = argv[argc - 1];
		if (GetInputType(path) != INPUT_TYPE::NONE)
		{
			ifstream ifs(path);
			if (ifs.is_open())
			{
				return path;
			}
		}
	}
	return "";
}

// 出力ファイル
string CArgs::ParseOutputPath(int argc, char* argv[])
{
	string path = ParseOptionString(argc, argv, "-o", "--outputPath");
	if (path.empty())
	{
		return GetPathWithoutExt(m_inputPath) + ".astc";
	}
	return path;
}

// フォーマット
IMAGE_FORMAT CArgs::ParseImageFormat(int argc, char* argv[])
{
	IMAGE_FORMAT fmt = GetImageFormat(ParseOptionString(argc, argv, "-f", "--format"));
	if (fmt == IMAGE_FORMAT::NONE)
	{
		return IMAGE_FORMAT::ASTC_8x8;
	}
	return fmt;
}

// 解析
bool CArgs::Parse(int argc, char* argv[])
{
	m_valid = false;
	m_inputPath = ParseInputPath(argc, argv);
	if (!m_inputPath.empty())
	{
		m_outputPath = ParseOutputPath(argc, argv);
		if (!m_outputPath.empty())
		{
			m_format = ParseImageFormat(argc, argv);
			m_valid = true;
		}
	}
	return m_valid;
}

// ヘルプ表示
void CArgs::Usage()
{
	printf("usage:\nastccomp input.bmp output.astc\n");
}

//------------------------------------------------------------------------
} // namespace ispccomp

// end of file.
