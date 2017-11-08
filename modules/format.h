/*
   BLOCK := HEAD, TRANSACTION(?)
   HEAD := current(32), nonce, previous(32), target(32), time
   TRANSACTION := size, A, B, INPUT(A), OUTPUT(B)
   INPUT := size, index, A, public(A), B, signature(B), transaction(32)
   OUTPUT := size, A, address(A), amount(8)

   entire transaction
   entire series of digests
   entire head

   given an input, get the corresponding output
   from the transaction database

   block database ordered by hash
   transaction database ordered by hash
   they have the same underlying data structure, a linked list
      an ordered linked list

   there needs to be a function to construct a block
   to add to a block

   there needs to be a function which keeps a pointer and a count
   a segment builder.

*/

/* array builder */

struct _3101 {

   void *_2905;
   unsigned int _1323;
};

struct _3101 *create_segment(unsigned int length) {

   struct _3101 *_0365;

   _0365 = malloc(sizeof (struct _3101));
   _0365->_2905 = malloc(length);
   _0365->_1323 = 0;

   return _0365;
}

void update_segment(struct _3101 *situation, unsigned char *buffer, unsigned int length) {

   memcpy(situation->_2905 + situation->_1323, buffer, length);
   situation->_1323 += length;
}

unsigned char *read_segment(struct _3101 *situation) {

   return situation->_2905;
}

unsigned char *jump_4363(unsigned char *cursor, unsigned char *limit) {

   unsigned int *_9458;

   _9458 = (unsigned int *) cursor;
   cursor += *_9458;

   return (cursor < limit ? cursor : 0);
}

/****************************/
/* [1] Essential Structures */
/****************************/

struct _8192 {

   uint8_t *current;
   uint32_t nonce;
   uint8_t *previous;
   uint8_t *target;
   uint32_t time;
};

struct _4226 {

   uint32_t index;
   uint8_t *public;
   uint8_t *signature;
   uint8_t *transaction;
};

struct _6106 {

   uint8_t *address;
   uint64_t amount;
};

/* is this necessary: */

struct _3492 {

   void *inputs;
   void *outputs;
};

/********************************************/
/* [4] Conversion from Arguments to Buffers */
/********************************************/

unsigned char *convert_1325(unsigned char *current, unsigned int nonce, unsigned char *previous, unsigned char *target, unsigned int time) {

   unsigned char *buffer;
   unsigned int _8664, *_5477;

   buffer = malloc(_8664 = 32 + 4 + 32 + 32 + 4);
   memcpy(buffer, current, 32);
   memcpy(buffer + 36, previous, 32);
   memcpy(buffer + 68, target, 32);

   _5477 = (unsigned int *) buffer + 32;
   *_5477 = nonce;
   _5477 = (unsigned int *) buffer + 100;
   *_5477 = time;

   return buffer;
}

unsigned char *convert_7486(unsigned int index, unsigned int _1922, unsigned char *public, unsigned int _0108, unsigned char *signature, unsigned char *transaction) {

   unsigned char *buffer;
   unsigned int _8029, *_4945;

   buffer = malloc(_8029 = 4 + 4 + 4 + _1922 + 4 + _0108 + 32);
   memcpy(buffer + 12, public, _1922);
   memcpy(buffer + 16 + _1922, signature, _0108);
   memcpy(buffer + 16 + _1922 + _0108, transaction, 32);

   _4945 = (unsigned int *) buffer;
   *_4945 = _8029;
   _4945 = (unsigned int *) buffer + 4;
   *_4945 = index;
   _4945 = (unsigned int *) buffer + 8;
   *_4945 = _1922;
   _4945 = (unsigned int *) buffer + 12 + _1922;
   *_4945 = _0108;

   return buffer;
}

unsigned char *convert_7210(unsigned int _2124, unsigned char *address, uint64_t amount) {

   unsigned char *buffer;
   unsigned int _7930, *_6650;

   buffer = malloc(_7930 = 4 + 4 + _2124 + 8);
   memcpy(buffer + 8, address, _2124);
   memcpy(buffer + 8 + _2124, &amount, 8);

   _6650 = (unsigned int *) buffer;
   *_6650 = _7930;
   _6650 = (unsigned int *) buffer + 4;
   *_6650 = _2124;

   return buffer;
}

/*********************************************/
/* [5] Conversion from Buffers to Structures */
/*********************************************/

struct _8192 *convert_0902(unsigned char *buffer, unsigned int limit) {

   struct _8192 *object;
   unsigned int *_4215;

   object = malloc(sizeof (struct _8192));

   _4215 = (unsigned int *) buffer + 4;
   object->nonce = *_4215;
   _4215 = (unsigned int *) buffer + 100;
   object->time = *_4215;

   object->current = malloc(32);
   object->previous = malloc(32);
   object->target = malloc(32);

   memcpy(object->current, buffer, 32);
   memcpy(object->previous, buffer + 36, 32);
   memcpy(object->target, buffer + 68, 32);

   return object;
}

struct _4226 *convert_2245(unsigned char *buffer, unsigned int limit) {

   struct _4226 *object;
   unsigned int _0308, _8439, *_8998;

   object = malloc(sizeof (struct _4226));

   _8998 = (unsigned int *) buffer + 4;
   object->index = *_8998;
   _8998 = (unsigned int *) buffer + 8;   
   _0308 = *_8998;
   _8998 = (unsigned int *) buffer + 12 + _0308;
   _8439 = *_8998;

   object->public = malloc(_0308 + 4) + 4;
   object->signature = malloc(_8439 + 4) + 4;
   object->transaction = malloc(32);

   memcpy(object->public, buffer + 12, _0308);
   memcpy(object->signature, buffer + 16 + _0308, _8439);
   memcpy(object->transaction, buffer + 16 + _0308 + _8439, 32);

   _8998 = (unsigned int *) object->public - 4;
   *_8998 = _0308;
   _8998 = (unsigned int *) object->signature - 4;
   *_8998 = _8439;

   return object;
}

struct _6106 *convert_1386(unsigned char *buffer, unsigned int limit) {

   struct _6106 *object;
   unsigned int _1622, *_5667;

   object = malloc(sizeof (struct _6106));

   _5667 = (unsigned int *) buffer + 4;
   _1622 = *_5667;

   object->address = malloc(_1622 + 4) + 4;

   memcpy(object->address, buffer + 8, _1622);
   memcpy(&object->amount, buffer + 8 + _1622, 8);

   _5667 = (unsigned int *) object->address - 4;
   *_5667 = _1622;

   return object;
}

/*********************/
/* [6] Miscellaneous */
/*********************/

