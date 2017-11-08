#include "stdio.h"
#include "stdlib.h"
#include "string.h"
#include "assorted.h"
#include "format.h"

void test_3816() {

   struct _3101 *_3130;

   _3130 = create_segment(6);
   update_segment(_3130, "truth", 6);
   printf("%s%c", read_segment(_3130), 10);
}

void test_8529() {

   struct _3101 *_2444;

   _2444 = create_segment(8);
   update_segment(_2444, "justice", 8);
   printf("%s%c", read_segment(_2444), 10);
}

void test_9087() {

   struct _3101 *_1632;

   _1632 = create_segment(12);
   update_segment(_1632, "bene", 4);
   update_segment(_1632, "volence", 8);
   printf("%s%c", read_segment(_1632), 10);
}

void test_5344() {

   struct _3101 *_4696;

   _4696 = create_segment(9);
   update_segment(_4696, "te", 2);
   update_segment(_4696, "rm", 2);
   update_segment(_4696, "in", 2);
   update_segment(_4696, "al", 3);
   printf("%s%c", read_segment(_4696), 10);
}

void main() {

   test_3816();
   test_8529();
   test_9087();
   test_5344();
}
