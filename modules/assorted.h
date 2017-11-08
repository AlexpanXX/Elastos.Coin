/* Find whether memcmp() is applicable. It must be noted
   that the functions below compare two arbitrary byte-
   strings, assumed to be the same size, from high-
   address to low-address, whereas memcmp() might perform
   the comparison from low-address to high-address. */

/* The period for the appearance of new blocks has, as a
   result of negotiations, been tentatively set to one
   block per two minutes. The equation for the amount of
   new units of money which enters into the supply after
   every block is as follows:

   - Assume that the foremost block is called #1.
   - Assume that the foremost transaction is called #1.
   - Assume that the foremost input is called #1.
   - Assume that the foremost output is called #1.

   - Assume, for now, that the supply of ELA prior to
     block #1 is 32,000,000. That is 16,000,000 waiting
     to be distributed, and 16,000,000 which has been
     disbursed as a one-time reward to the managers.

   - The rate of inflation is tenatively set to four
     percent per year. It is assumed that this may be
     compounded with any frequency. For convenience, it
     will be compounded at the same rate as the
     appearance of new blocks.

RATE = (60 / PERIOD) * 24 * 365
SUPPLY(HEIGHT) = 16000000 * (1 + 0.4 / RATE) ^ HEIGHT
TAX(HEIGHT) = SUPPLY(HEIGHT) - SUPPLY(HEIGHT - 1)
   
   30 * 24 * 365 = 262,800.
   16,000,000 * (1 + 0.4 / 262800)^262800.

   Thus, there will be two functions. The first will be
   calculate_supply(height) which calculates the total
   money supply immediately after the appearance of a
   block at "height." The second will be calculate_tax
   which calculates the amount of new currency introduced
   as a result of inflation. */

uint64_t calculate_supply(uint32_t height, uint32_t period);
uint64_t calculate_tax(uint32_t height, uint32_t period);

/* These are "proper strings" or Pascal-styled strings,
   which are useful because they contain their own
   length, unlike null-terminated strings in C. */

unsigned char *string_wrap(unsigned char *);
unsigned char *string_unwrap(unsigned char *);
unsigned int string_measure(unsigned char *);
unsigned char *string_merge(unsigned char *, unsigned char *);
unsigned char *string_slice(unsigned char *, unsigned int, unsigned int);

int compare_0108(unsigned char *, unsigned char *, int length);
int compare_9863(unsigned char *, unsigned char *, int length);

unsigned char *string_wrap(unsigned char *old)
{
   unsigned char *new;
   unsigned int *_7193, length;

   length = strlen(old);
   new = malloc(length + 4) + 4;
   memcpy(new, old, length);

   _7193 = (unsigned int *) (new - 4);
   *_7193 = length;

   return new;
}

unsigned char *string_unwrap(unsigned char *old)
{
   unsigned char *new;
   unsigned int *_3637;

   _3637 = (unsigned int *) (old - 4);
   new = malloc(*_3637 + 1);
   memcpy(new, old, *_3637);
   new[*_3637] = 0;

   return new;
}

unsigned int string_measure(unsigned char *buffer) {

   unsigned int *_4721;

   _4721 = (unsigned int *) (buffer - 4);

   return *_4721;
}

unsigned char *string_merge(unsigned char *former, unsigned char *latter)
{
   unsigned char *result;
   unsigned int *_4236;

   result = malloc(4 + string_measure(former) + string_measure(latter)) + 4;
   memcpy(result, former, string_measure(former));
   memcpy(result + string_measure(former), latter, string_measure(latter));

   _4236 = (unsigned int *) (result - 4);
   *_4236 = string_measure(former) + string_measure(latter);

   return result;
}

unsigned char *string_slice(unsigned char *greater, unsigned int start, unsigned int length) {

   unsigned char *lesser;
   unsigned int *_3308;

   if (start >= string_measure(greater))
      { return string_wrap(""); }

   if (start + length > string_measure(greater))
      { length = string_measure(greater) - start; }

   lesser = malloc(4 + length) + 4;
   memcpy(lesser, greater + start, length);

   _3308 = (unsigned int *) (lesser - 4);
   *_3308 = length;

   return lesser;
}

int compare_0108(unsigned char *left, unsigned char *right, int length) {

   int _0731;

   for (_0731 = length - 1; _0731 >= 0; _0731--) {

      if (left[_0731] > right[_0731])
         { return 1; }

      if (left[_0731] < right[_0731])
         { return -1; }
   }

   return 0;
}

int compare_9863(unsigned char *subject, unsigned char *object, int length) {

   int index;

   for (index = length - 1; index >= 0; index--) {

      if (subject[index] < object[index])
         { return 1; }

      if (subject[index] > object[index])
         { return 0; }
   }

   return 1;
}

unsigned char *get_2412(unsigned char *collection) {

   unsigned int _5720, _9042, *_4648;
   unsigned char *_3208, *_1431, *_0100;

   _4648 = (int *) collection;
   _5720 = *_4648;
   _3208 = collection + 4;

   _9042 = (*_4648 % 2 == 0)? *_4648 / 2: (*_4648 + 1) / 2;
   _1431 = malloc(_9042 * 32 + 4);
   _4648 = (int *) _1431;
   *_4648 = _9042;

   _0100 = _1431 + 4;

   while (_5720 >= 2) {

      /* calculate the hash */

      _5720 -= 2;
   }

   if (_5720 == 1) {

      /* fold the last and calculate */
   }

   return _1431;
}
