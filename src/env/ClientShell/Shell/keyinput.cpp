#include "keyinput.h"

keyInput::keyInput()
{

}

char keyInput::keyPressEvent( QKeyEvent *k )
{
    char keypressed;
    switch ( tolower(k->GrabKeyboard))
    {
        case 'w':
        keypressed = 'w';
            break;
        case 's':
            keypressed = 's';
            break;
        case 'a':
            keypressed = 'a';
            break;
        case 'd':
            keypressed = 'd';
            break;
        default:
        return ' ';
    }
    return ' ';
}
