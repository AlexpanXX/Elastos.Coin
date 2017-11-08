/* 8111 */

struct command_getinfo {
   unsigned int tag;
};

/* 4397 */

struct command_getwork {
   unsigned int tag;
};

/* 9010 */

struct command_submitblock {
   unsigned int tag;
   unsigned char *block;
};
