#define TFM_DESC

#include "dirent.h"
#include "stdio.h"
#include "stdlib.h"
#include "string.h"
#include "sys/stat.h"
#include "sys/types.h"
#include "tomcrypt.h"
#include "unistd.h"

#include "time.h"
#include "sys/time.h"

#include "assorted.h"
#include "format.h"
#include "storage.h"

void _start() {

   printf("current: %s%c", "", 10);
   printf("nonce: %d%c", 0, 10);
   printf("previous: %s%c", "", 10);
   printf("target: %s%c", "", 10);
   printf("time: %d%c%c", 0, 10, 10);

   printf("number of transactions: %d%c", 0, 10);

   // of each transaction, how many inputs, how many outputs
   // the signature of any input might be invalid
   // the sum of outputs of any transaction might be excessive
   // the coinbase might be flawed
   // of course, the structure might be flawed
}
