struct shmeg{
	int cnt;
	char buf[BUF_SIZE];
}

void *Inotify(){
	char *notify_file[];
	notify_file = file_list;
	/* fork a new process */
	pid_t pid_child;
	if((pid_child = fork()) == -1){
		//handle error
	}
	if (pid_child == 0){
		//manager
		manager(notify_file);
	}
	id (pid > 0){
		//handle parent
	} 
}

/* manager */
void manager(char *file){
	/*create */
	struct shmeg *shmip;
	shmip = (struct shmeg *)create_mem();

	/* */

}

/* create a shared memory */
void *create_mem(){
	int shmid, bytes;
	struct shmreg *shmp;

	shmid = shmget(SHM_KEY, sizeof(struct shmeg), IPC_CREAT | OBJ_PERMS);
	if(shmid == -1)
		perror("shmget");
	shmp = shmat(shmid, NULL, 0);
	if(shmp == (void *) -1)
		perror("shmat");

	return shmp;

}
