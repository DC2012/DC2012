#include "keyinput.h"

keyInput::keyInput()
{

}

void keyInput::keyPressEvent( QKeyEvent *k )
{
    switch ( tolower(k->ascii()) )
    {
        case 'w':
            break;
        case 's':
            break;
        case 'a':
            break;
        case 'd':
            break;
    }
}
