#include <sys/types.h>
#include <sys/stat.h>
#include <sys/sem.h>
#include <sys/shm.h>

#define SHM_KEY 0x1234	/* key for shared memory*/

#ifdef BUF_SIZE
#define BUF_SIZE 1024
#endif

#define OBJ_PERMS (S_IRUSR, | S_IWUSR | S_IRGRP | S_IWGRP)

