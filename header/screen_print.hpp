
#ifndef _SCREEN_PRINT_HPP_
#define _SCREEN_PRINT_HPP_

// C++ Includes
#include <iostream>
#include <sstream>
// Local Includes
#include "code_definitions.hpp"

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
    static Bool m_screen_refreshed;

    std::ostringstream m_output_stream;
};

#define spp ScreenPrint().print()
#define spr ScreenPrint::refresh_screen()

#endif // _SCREEN_PRINT_HPP_
