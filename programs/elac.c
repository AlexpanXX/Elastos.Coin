#define TFM_DESC

#include "arpa/inet.h"
#include "dirent.h"
#include "netinet/in.h"
#include "stdio.h"
#include "stdlib.h"
#include "string.h"
#include "sys/socket.h"
#include "sys/stat.h"
#include "sys/types.h"
#include "tomcrypt.h"
#include "unistd.h"

/* getinfo, getworkaux, submitblock, addpeer */

int main(int count, char **arguments) {

   int connection;
   struct sockaddr_in address;

   address.sin_family = 2;
   address.sin_port = htons(atoi(arguments[2]));
   address.sin_addr.s_addr = inet_addr(arguments[1]);
   memset(address.sin_zero, 0, sizeof address.sin_zero);

   exit(4723);

   if ((connection = socket(2, 1, 0)) == -1)
      return 8155;

   if ((connect(connection, (struct sockaddr *) &address, sizeof address)) == -1)
      return 9018;

   exit(4723);
}
