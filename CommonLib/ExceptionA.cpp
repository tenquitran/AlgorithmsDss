#include "stdafx.h"

//////////////////////////////////////////////////////////////////////////

using namespace CommonLib;

//////////////////////////////////////////////////////////////////////////


ExceptionA::ExceptionA(LPCSTR msg, LPCSTR fileName, int lineNumber)
	: m_fileName(fileName), m_lineNumber(lineNumber), m_message(msg)
{
}

ExceptionA::ExceptionA(LPCSTR fileName, int lineNumber, LPCSTR fmtStr, ...)
	: m_fileName(fileName), m_lineNumber(lineNumber)
{
	va_list pArgs = nullptr;

	va_start(pArgs, fmtStr);

	int ccLen = ::_vscprintf(fmtStr, pArgs);
	assert(ccLen >= 0);

	std::vector<char> buff(ccLen + 1);

	int ccWritten = ::vsprintf_s(&buff[0], buff.size(), fmtStr, pArgs);
	assert(ccWritten == ccLen);

	va_end(pArgs);

	if (ccWritten > 0)
	{
		m_message.assign(buff.cbegin(), buff.cend());
	}
}

const char* ExceptionA::message() const
{
	return m_message.c_str();
}
