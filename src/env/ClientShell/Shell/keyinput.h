#ifndef KEYINPUT_H
#define KEYINPUT_H
#include <QKeyEvent>
class keyInput
{
public:
    keyInput();
    char keyPressEvent(QKeyEvent *k);
};

#endif // KEYINPUT_H
