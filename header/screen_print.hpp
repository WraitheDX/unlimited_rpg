
#ifndef _SCREEN_PRINT_HPP_
#define _SCREEN_PRINT_HPP_

// C++ Includes
#include <iostream>
#include <sstream>
// Local Includes
#include "code_definitions.hpp"

class ScreenPrint final {
public:
    // Enables VT sequences on stdout.
    // See: https://docs.microsoft.com/en-us/windows/console/console-virtual-terminal-sequences
    static void initialize()
    {
#if defined(_WIN32) && defined(ENABLE_VIRTUAL_TERMINAL_PROCESSING)
        // Set output mode to handle virtual terminal (ANSI escape sequences)
        // ignore any error, as this is just a "nice-to-have"
        // only windows needs to be taken care of, as other platforms (Linux/OSX) support them natively.
        HANDLE hOut = GetStdHandle(STD_OUTPUT_HANDLE);
        if (hOut == INVALID_HANDLE_VALUE)
            return;

        DWORD dwMode = 0;
        if (!GetConsoleMode(hOut, &dwMode))
            return;

        dwMode |= ENABLE_VIRTUAL_TERMINAL_PROCESSING;
        if (!SetConsoleMode(hOut, dwMode))
            return;
#endif
    }

    explicit
    ScreenPrint()
    {

    }

    ~ScreenPrint()
    {
        std::cout << m_output_stream.str();
    }

    std::ostringstream &
    print()
    {
        m_screen_refreshed = false;
        return m_output_stream;
    }

    static
    void refresh_screen()
    {
        if( !m_screen_refreshed )
        {
#if defined(_WIN32) || defined(_WIN64)
			system("pause");
#else
            std::cout << "Press ENTER to continue ... \n";
            std::cin.get();
#endif

            std::cout << "\033[2J\033[H";
            std::cout.flush();

            m_screen_refreshed = true;
        }
    }

private:
    static Bool m_screen_refreshed;

    std::ostringstream m_output_stream;
};

#define spp ScreenPrint().print()
#define spr ScreenPrint::refresh_screen()

#endif // _SCREEN_PRINT_HPP_
