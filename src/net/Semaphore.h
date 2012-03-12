#ifndef SEMAPHORE_H
#define SEMAPHORE_H
/* Semaphore creation and initialization function */

#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/sem.h>
#include <stdio.h>
#include <stdlib.h>

/*------------------------------------------------------------------------------------------------------------------
-- FUNCTION: initsem
--
-- DATE: February 12, 2012
--
-- DESIGNER: Aman Abdulla
--
-- PROGRAMMER: Aman Abdulla
--
-- INTERFACE: int initsem(key_t key)
-- key_t key: the key used to get the semaphore
--
-- RETURNS: a non negative semaphore id on success, -1 on failure
--
-- NOTES:
-- This is a wrapper function to semget. Creates a new semaphore with initial value 0, or the existing one.
----------------------------------------------------------------------------------------------------------------------*/
int initsem(key_t key, int initialValue);

/*------------------------------------------------------------------------------------------------------------------
-- FUNCTION: closeSem
--
-- DATE: February 12, 2012
--
-- DESIGNER: James Rupert
--
-- PROGRAMMER: James Rupert
--
-- INTERFACE: int closeSem(int sem_id)
-- int sem_id: the id of the semaphore to be closed
--
-- RETURNS: 0 on success, -1 on failure
--
-- NOTES:
-- This is a wrapper function to semctl to close the semaphore.
----------------------------------------------------------------------------------------------------------------------*/
int closeSem(int sem_id);

/*------------------------------------------------------------------------------------------------------------------
-- FUNCTION: P
--
-- DATE: February 12, 2012
--
-- REVISIONS: made sure to free the struct and gave a return to indicate success
--
-- DESIGNER: Aman Abdulla
--
-- PROGRAMMER: Aman Abdulla, James Rupert
--
-- INTERFACE: int P(int sid)
-- int sid: the id of the semaphore to acquire
--
-- RETURNS: 0 success, -1 on failure
--
-- NOTES:
-- This is a wrapper function to semop used to acquire the semaphore.
----------------------------------------------------------------------------------------------------------------------*/
int P(int sid);

/*------------------------------------------------------------------------------------------------------------------
-- FUNCTION: V
--
-- DATE: February 12, 2012
--
-- REVISIONS: made sure to free the struct and gave a return to indicate success
--
-- DESIGNER: Aman Abdulla
--
-- PROGRAMMER: Aman Abdulla, James Rupert
--
-- INTERFACE: int V(int sid)
-- int sid: the id of the semaphore to release
--
-- RETURNS: 0 success, -1 on failure
--
-- NOTES:
-- This is a wrapper function to semop used to release the semaphore.
----------------------------------------------------------------------------------------------------------------------*/
int V(int sid);

#endif