/* Semaphore creation and initialization function */

#include "Semaphore.h"
#include <errno.h>

extern int errno;

int initsem(key_t key)
{
  int sid, status=0;

  if((sid = semget((key_t)key, 1, 0666|IPC_CREAT|IPC_EXCL)) == -1)
  {
    if(errno == EEXIST)/* if already exists, get that id */
    {
      sid = semget ((key_t)key, 1, 0);
    }
  }
  else   /* if created, set initial value to 0 */
  {
      status = semctl (sid, 0, SETVAL, 0);
  }
  if((sid == -1) || status == -1)
  {
    perror("initsem failed\n");
    return(-1);
  }
  return (sid);
}

int closeSem(int sem_id)
{
  if(semctl(sem_id, IPC_RMID, 0) != 0)
  {
    return -1;
  }
  return 0;
}

int P(int sid)     /* acquire semophore */
{
  int result;
  struct sembuf* sembuf_ptr = (struct sembuf*)malloc(sizeof(struct sembuf));

  sembuf_ptr->sem_num = 0;
  sembuf_ptr->sem_op = -1;
  sembuf_ptr->sem_flg = SEM_UNDO;

  if((result = semop(sid,sembuf_ptr,1)) == -1)
  {
    perror("semop P error");
  }
  free(sembuf_ptr);
  return result;
}

int V(int sid)     /* release semaphore */
{
  int result;
  struct sembuf* sembuf_ptr = (struct sembuf*)malloc(sizeof(struct sembuf));
  
  sembuf_ptr->sem_num = 0;
  sembuf_ptr->sem_op = 1;
  sembuf_ptr->sem_flg = SEM_UNDO;
  
  if((result = semop(sid,sembuf_ptr,1)) == -1)
  {
    perror("semop V error");
  }
  free(sembuf_ptr);
  return result;
}
