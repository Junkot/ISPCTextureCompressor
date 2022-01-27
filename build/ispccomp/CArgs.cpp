#include "CArgs.h"

namespace ispccomp {
//------------------------------------------------------------------------

//------------------------------------------------------------------------
// class CArgs
//------------------------------------------------------------------------

// コンストラクタ
CArgs::CArgs(int args, char* argv[])
{
}

// チェック
bool CArgs::IsValid()
{
	if (m_format != IMAGE_FORMAT::NONE &&
		m_inputPath.empty() == false &&
		m_outputPath.empty() == false)
	{
		return true;
	}
	return false;
}

// ヘルプ表示
void CArgs::Usage()
{
}

//------------------------------------------------------------------------
} // namespace ispccomp

// end of file.
