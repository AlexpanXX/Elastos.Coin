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

#include "time.h"
#include "sys/time.h"

#include "assorted.h"
#include "format.h"
#include "storage.h"

struct _6115 {

   void *folder;
   void *port;
};

struct _2261 {

   unsigned int tag;
};

struct _5360 {

   unsigned int tag;
   unsigned int accumulation;
   unsigned int count;
};

struct _5095 {

   unsigned int tag;
   unsigned int count;
   unsigned int limit;
   unsigned char *substance;
};

struct _2261 *build_0739() {

   struct _2261 *goal;

   goal = malloc(sizeof (struct _2261));
   goal->tag = 9152;

   return goal;
}

struct _5360 *build_7807(unsigned int accumulation, unsigned int count) {

   struct _5360 *goal;

   goal = malloc(sizeof (struct _5360));
   goal->tag = 1686;
   goal->accumulation = accumulation;
   goal->count = count;

   return goal;
}

struct _5095 *build_3929(unsigned int count, unsigned int limit, unsigned char *substance) {

   struct _5095 *goal;

   goal = malloc(sizeof (struct _5095));
   goal->tag = 4271;
   goal->count = count;
   goal->limit = limit;
   goal->substance = substance;

   /* this needs to become a copy constructor */

   return goal;
}

struct _2261 *handle(struct _2261 *state, unsigned char input, unsigned char **output) {

   /* output must be manually cleared before invoking */

   struct _5360 *_3710;
   struct _5095 *_4404;
   unsigned char *_3930;

   if (state->tag == 9152) {

      if (input == 97) {

         
      }

      if (input == 98) {

         _exit(1);
      }

      if (input == 99) {

         _exit(1);
      }

      if (input == 100) {

         _exit(1);
      }
   }

   if (state->tag == 1686) {

      _3710 = (struct _5360 *) state;

      if (_3710->count == 3) {

         int _9342;

         _9342 = _3710->accumulation << 8;
         _9342 = _9342 | input;

         printf("updated (%d, count = %d) transitioning..%c", _9342, _3710->count, 10);

         return (struct _2261 *) build_3929(0, _9342, malloc(1000));
      }

      int _0432;

      _0432 = _3710->accumulation << 8;
      _0432 = _0432 | input;

      printf("updated (%d, count = %d)%c", _0432, _3710->count, 10);

      return (struct _2261 *) build_7807(_0432, _3710->count + 1);
   }

   if (state->tag == 4271) {

      _4404 = (struct _5095 *) state;
      _4404->substance[_4404->count++] = input;

      printf("received one character (%d, limit = %d)%c", _4404->count, _4404->limit, 10);

      if (_4404->count == _4404->limit)
         { return build_0739(); }

      return (struct _2261 *) build_3929(_4404->count, _4404->limit, _4404->substance);
   }
}

void _start_4858() {

   int acceptance, audition, size;
   struct sockaddr opponent;
   struct sockaddr_in address;

   address.sin_family = 2;
   address.sin_port = htons(6005);
   address.sin_addr.s_addr = 0;

   if ((audition = socket(2, 1, 0)) == -1)
      { return 1; }

   if (bind(audition, (struct sockaddr *) &address, sizeof (address)) == -1)
      { return 2; }

   if (listen(audition, 1024) == -1)
      { return 3; }

   while (1) {

      size = sizeof opponent;

      if ((acceptance = accept(audition, &opponent, &size)) == -1)
         { return 4; }

      printf("received a new connection%c", 10);

      struct _2261 *state;
      state = build_0739();

      int _0365;
      unsigned char _8165;
      unsigned char **message;

      while (1) {

         _0365 = recv(acceptance, &_8165, 1, 0);

         if (_0365 == -1 || _0365 == 0)
            { break; }

         printf("%c", _8165);

         message = 0;
         state = handle(state, _8165, message);

         if (message != 0)
            printf("%s%c", message, 10);
      }
   }

   _exit(0);
}

unsigned char *create_3344(int *length) {

   ecc_key _5560;
   int _2935;
   prng_state _2821;
   unsigned char *_0163;

   _0163 = malloc(_2935 = 1000);
   ecc_make_key(&_2821, find_prng("sprng"), 32, &_5560);
   ecc_export(_0163, &_2935, 1, &_5560);
   *length = _2935;

   return _0163;
}

void _start_3988() {

   ecc_key key;
   prng_state _0913;
   struct _6115 options;

   options.folder = (void *) "/tmp/chain";
   options.port = (void *) 6005;

   register_prng(&sprng_desc);
   ltc_mp = tfm_desc;

   int _f765, _1124, _7226;
   unsigned char output[1024];

   int length;
   unsigned char *buffer;

   buffer = create_3344(&length);
   printf("%d%c", length, 10);
   buffer = create_3344(&length);
   printf("%d%c", length, 10);
   buffer = create_3344(&length);
   printf("%d%c", length, 10);

   _start_4858();
   _exit(0);
}
