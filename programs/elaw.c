#define TFM_DESC

#include "dirent.h"
#include "stdio.h"
#include "stdlib.h"
#include "string.h"
#include "sys/stat.h"
#include "sys/time.h"
#include "sys/types.h"
#include "time.h"
#include "tomcrypt.h"
#include "unistd.h"
#include "format.h"

unsigned char *get_5153(unsigned char *buffer, unsigned int size) {

   hash_state _3477;
   unsigned char *_0750;

   _0750 = malloc(32);

   sha256_init(&_3477);
   sha256_process(&_3477, buffer, size);
   sha256_done(&_3477, _0750);

   return _0750;
}

unsigned char *crunch_5513(unsigned char *digests, unsigned int count) {

   unsigned char *_7904, *_6597, *_1597;
   unsigned int _7117;

   if (count == 1) {

      return digests;
   }

   if (count % 2) {

      _7904 = malloc((count + 1) * 32);
      memcpy(_7904, digests, count * 32);
      memcpy(_7904 + count * 32, digests + (count - 1) * 32, 32);

      return crunch_5513(_7904, count + 1);
   }


   _7904 = malloc(count / 2 * 32);

   for (_7117 = 0; _7117 < count; _7117 += 2) {

      _6597 = malloc(64);
      memcpy(_6597, digests + _7117 * 32, 32);
      memcpy(_6597 + 32, digests + (_7117 + 1) * 32, 32);
      _1597 = get_5153(_6597, 64);
      memcpy(_7904 + (_7117 / 2) * 32, _1597, 32);
   }

   return crunch_5513(_7904, count / 2);
}

unsigned char *create_7601(unsigned char *_5118, unsigned int *length) {

   ecc_key _7596;
   prng_state _1382;
   unsigned char *buffer;

   ecc_import(_5118, *length, &_7596);
   buffer = malloc(*length = 200);
   ecc_export(buffer, length, 0, &_7596);

   return buffer;
}

unsigned char *create_3344(unsigned int *length) {

   ecc_key _3189;
   prng_state _6620;
   unsigned char *buffer;

   ecc_make_key(&_6620, find_prng("sprng"), 32, &_3189);
   buffer = malloc(*length = 200);
   ecc_export(buffer, length, 1, &_3189);

   return buffer;
}

void create_4934(char *path, unsigned char *buffer, unsigned int length) {

   FILE *_5026;

   _5026 = fopen(path, "w+");
   fwrite(buffer, 1, length, _5026);
   fclose(_5026);
}

int main(int _2302, char **_6396) {

   register_prng(&sprng_desc);
   ltc_mp = tfm_desc;

   unsigned char *a, *b, *c;

   a = wrap("hello");
   printf("%d%c", a[-1], 10);
}

unsigned char *block_8730() {

   unsigned char *block, *head, *high, *input, *low, *output, *private, *public;
   unsigned int _4094, *_0355, *_8526, *_6175;

   private = create_3344(&_4094);
   public = create_7601(private, &_4094);

   high = malloc(32);
   memset(high, 255, 32);
   low = malloc(32);
   memset(low, 0, 32);

   head = convert_1325(low, 0, low, high, 1502452800);
   input = convert_7486(0, 0, "", 0, "", low);
   output = convert_7210(_4094, public, 16000000);   

   _0355 = (unsigned int *) input;
   _8526 = (unsigned int *) output;

   block = malloc(104 + 12 + *_0355 + *_8526);
   memcpy(block, head, 104);
   memcpy(block + 116, input, *_0355);
   memcpy(block + 116 + *_0355, output, *_8526);

   _6175 = (unsigned int *) block + 104; *_6175 = *_0355 + *_8526;
   _6175 = (unsigned int *) block + 108; *_6175 = 1;
   _6175 = (unsigned int *) block + 112; *_6175 = 1;

   return block;
}

int main_4998(int _5234, char **_6946) {

   unsigned char *_1994;
   unsigned int _6771;

   register_prng(&sprng_desc);
   ltc_mp = tfm_desc;

   _1994 = create_3344(&_6771);
   create_4934(_6946[1], _1994, _6771);
}
