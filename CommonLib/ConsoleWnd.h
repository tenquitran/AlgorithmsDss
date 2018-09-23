#pragma once


namespace CommonLib
{
	// Helper class to work with the console window (Windows-specific).
	class ConsoleWnd
	{
	public:
		// Throws: ExceptionA
		ConsoleWnd();

		virtual ~ConsoleWnd();

		// Clear the console using the specified character.
		// Parameters: ch - the character to clear the console with;
		//             textColor - text color;
		//             backgroundColor - background color (black by default).
		// Returns: true on success, false otherwise.
		bool clear(wchar_t ch, WORD textColor, WORD backgroundColor = 0) const;

	private:
		// Restore current character attributes.
		bool restoreCharAttributes() const;

	private:
		// Handle to the output stream (console).
		HANDLE m_hOut;

		// Current character attributes.
		mutable WORD m_currentTextAttributes;
	};
}
