#include "CArgs.h"

namespace ispccomp {
//------------------------------------------------------------------------

//------------------------------------------------------------------------
// class CArgs
//------------------------------------------------------------------------

// �R���X�g���N�^
CArgs::CArgs(int args, char* argv[])
{
}

// �`�F�b�N
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

// �w���v�\��
void CArgs::Usage()
{
}

//------------------------------------------------------------------------
} // namespace ispccomp

// end of file.
