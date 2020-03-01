
#ifndef _SCREEN_PRINT_HPP_
#define _SCREEN_PRINT_HPP_

#include <iostream>
#include <sstream>

class ScreenPrint final {
public:
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
            system( "pause" );
            system( "cls" );

            m_screen_refreshed = true;
        }
    }

private:
    static bool m_screen_refreshed;

    std::ostringstream m_output_stream;
};

bool ScreenPrint::m_screen_refreshed = true;

#define spp ScreenPrint().print()
#define spr ScreenPrint::refresh_screen()

#endif // _SCREEN_PRINT_HPP_
