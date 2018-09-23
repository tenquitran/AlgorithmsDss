#pragma once


namespace CommonLib
{
	// Formatted exception: non-wide-character version.
	class ExceptionA
	{
	public:
		// Exception constructor: constant string version.
		ExceptionA(LPCSTR msg, LPCSTR fileName, int lineNumber);

		// Exception constructor: formatted string version.
		ExceptionA(LPCSTR fileName, int lineNumber, LPCSTR fmtStr, ...);

		// Get exception message.
		const char* message() const;

	private:
		std::string m_fileName;

		int m_lineNumber;

		std::string m_message;
	};

#define EXCEPTION_A(msg)		ExceptionA(msg, __FILE__, __LINE__)

#define EXCEPTION_A_FMT(fmtStr, ...)		ExceptionA(__FILE__, __LINE__, fmtStr, ##__VA_ARGS__)
}
