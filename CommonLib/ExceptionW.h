#pragma once


namespace CommonLib
{
	// Formatted exception: wide-character version.
	class ExceptionW
	{
	public:
		// Exception constructor: constant string version.
		ExceptionW(LPCTSTR msg, LPCSTR fileName, int lineNumber);

		// Exception constructor: formatted string version.
		ExceptionW(LPCSTR fileName, int lineNumber, LPCTSTR fmtStr, ...);

		// Get exception message.
		const wchar_t* message() const;

	private:
		std::string m_fileName;

		int m_lineNumber;

		std::wstring m_message;
	};

#define EXCEPTION_W(msg)		ExceptionW(msg, __FILE__, __LINE__)

#define EXCEPTION_W_FMT(fmtStr, ...)		ExceptionW(__FILE__, __LINE__, fmtStr, ##__VA_ARGS__)
}
