#include "types.h"
#include "stat.h"
#include "user.h"
#include "fs.h"
#include "fcntl.h"

//NOTE:
//THIS PROGRAM IS A COPY OF THE PROGRAM
//DONE BY MR. REMZI ON HIS YOUTUBE TUTORIAL
//TO PROJECT 5 OF CS. 537 AT UW-MADISON
//FALL 2015. 
int 
main(int argc, char *argv[]){
   int fd = open("foo", O_CREATE|O_CHECKED);
   printf(1, "%d\n", fd); 
   exit();
}
