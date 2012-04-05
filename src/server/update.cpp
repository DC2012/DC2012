#include "update.h"

void update(sigval arg)
{
    PDATA pdata = (PDATA)arg.sival_ptr;
    printf("%d\n", pdata->isRunning);
}