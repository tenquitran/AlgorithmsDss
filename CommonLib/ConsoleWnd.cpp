#include "stdafx.h"

//////////////////////////////////////////////////////////////////////////

using namespace CommonLib;

//////////////////////////////////////////////////////////////////////////


ConsoleWnd::ConsoleWnd()
	: m_hOut(nullptr), m_currentTextAttributes{}
{
	m_hOut = GetStdHandle(STD_OUTPUT_HANDLE);

	if (!m_hOut)
	{
		// Possible for Windows services, etc.
		throw EXCEPTION_A("No standard output handle");
	}
	else if (INVALID_HANDLE_VALUE == m_hOut)
	{
		throw EXCEPTION_A_FMT("Failed to get standard output handle: %u", GetLastError());
	}
}

ConsoleWnd::~ConsoleWnd()
{
}

bool ConsoleWnd::clear(wchar_t ch, WORD textColor, WORD backgroundColor/* = 0*/) const
{
	CONSOLE_SCREEN_BUFFER_INFO csbi = {};

	if (!GetConsoleScreenBufferInfo(m_hOut, &csbi))
	{
		std::cerr << "GetConsoleScreenBufferInfo() failed: " << GetLastError() << '\n';
		return false;
	}

	// Change the text and background colors.

	m_currentTextAttributes = csbi.wAttributes;

	WORD newTextAttributes = textColor | FOREGROUND_INTENSITY;

	if (0 != backgroundColor)
	{
		newTextAttributes |= backgroundColor;
	}

	if (!SetConsoleTextAttribute(m_hOut, newTextAttributes))
	{
		std::cerr << "SetConsoleTextAttribute (changing character attributes) failed: " << GetLastError() << '\n';
		return false;
	}

	// Number of characters to write.
	// Note: X and Y are dimensions of the entire console buffer, not just of its visible part.
	const DWORD ccToWrite = csbi.dwSize.X * csbi.dwSize.Y;

	// Fill the screen with the specified character.

	COORD topLeft = {};    // top left cursor position

	DWORD ccWritten = {};

	if (!FillConsoleOutputCharacter(m_hOut, ch, ccToWrite, topLeft, &ccWritten))
	{
		std::cerr << "FillConsoleOutputCharacter() failed: " << GetLastError() << '\n';
		restoreCharAttributes();
		return false;
	}

	if (!GetConsoleScreenBufferInfo(m_hOut, &csbi))
	{
		std::cerr << "GetConsoleScreenBufferInfo() failed: " << GetLastError() << '\n';
		restoreCharAttributes();
		return false;
	}

	if (!FillConsoleOutputAttribute(m_hOut, csbi.wAttributes, ccToWrite, topLeft, &ccWritten))
	{
		std::cerr << "FillConsoleOutputAttribute() failed: " << GetLastError() << '\n';
		restoreCharAttributes();
		return false;
	}

	// Reset cursor position to the top left.
	if (!SetConsoleCursorPosition(m_hOut, topLeft))
	{
		std::cerr << "SetConsoleCursorPosition() failed: " << GetLastError() << '\n';
		restoreCharAttributes();
		return false;
	}

	if (!restoreCharAttributes())
	{
		return false;
	} 
	
	return true;
}

bool ConsoleWnd::restoreCharAttributes() const
{
	if (!SetConsoleTextAttribute(m_hOut, m_currentTextAttributes))
	{
		std::cerr << "SetConsoleTextAttribute (restoring character attributes) failed: " << GetLastError() << '\n';
		return false;
	}

	return true;
}
