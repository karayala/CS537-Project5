#include "types.h"
#include "stat.h"
#include "user.h"
#include "fs.h"
#include "fcntl.h"

int main(int argc, char *argv[]) {
	
	int filedes;
	struct stat st;

	// basic argument test
	if(argc != 2){
		printf(1, "filestat: arguments are wrong");
		exit();
	}

	// open test
	if((filedes = open(argv[1], 0)) < 0){
		printf(1, "filestat: open failed");
		exit();
	}

	// stat the into the new stat struct
	if(fstat(filedes, &st) < 0){
		printf(1, "filestat: fstat call failed for file %s\n", argv[1]);
		close(filedes);
	//	exit;
	}

	// print out what type of file this is
	if(st.type == T_FILE){
		printf(1, "%s is an unprotected file.\n", argv[1]);
	} else if(st.type == T_DIR){
		printf(1, "%s is an directory.\n", argv[1]);
	} else if(st.type == T_CHECKED) {
		printf(1, "%s is a checksum-protected file.\n", argv[1]);
	} else {
		printf(1, "%s is a special device.\n", argv[1]);
	}

	// print out basic information about the file
	// Device Number
	printf(1, "%s has a device number of %d.\n", argv[1], st.dev);
	// Inode Number
	printf(1, "%s has an inode number of %d.\n", argv[1], st.ino);
	// Link Number
	printf(1, "%s has %hd links to it.\n", argv[1], st.nlink);
	// File Size
	printf(1, "%s has a size of %d bytes.\n", argv[1], st.size);
	// File Checksum
	printf(1, "%s has a checksum value of %d.\n", argv[1], st.checksum);

	// Is there anything else we want to include in the filestat? - Pavle

	// close the file at the end
	close(filedes);
	exit();
}


