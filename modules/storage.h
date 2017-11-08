struct link {

   void *current;
   void *next;
};

struct record {

   unsigned char *identity;
   unsigned char *substance;
};

struct storage {

   void *collection;
   unsigned char *folder;
   unsigned char *genesis;
};

struct link *create_link(void *, void *);
struct record *create_record(unsigned char *, unsigned char *);
struct storage *create_storage(unsigned char *, unsigned char *);
struct record *read_record(void *, unsigned char *);
struct link *update_storage(void *, void *);

struct link *create_link(void *current, void *next) {

   struct link *link;

   link = malloc(sizeof (struct link));
   link->current = current;
   link->next = next;

   return link;
}

struct record *create_record(unsigned char *identity, unsigned char *substance) {

   struct record *record;

   record = malloc(sizeof (struct record));
   record->identity = malloc(32);
   record->substance = malloc(2000);

   memcpy(record->identity, identity, 32);

   return record;
}

struct storage *create_storage(unsigned char *folder, unsigned char *genesis) {

   struct storage *storage;

   storage = malloc(sizeof (struct storage));
   storage->folder = malloc(strlen(folder) + 1);
   storage->genesis = malloc(32);

   storage->collection = 0;
   memcpy(storage->folder, folder, strlen(folder));
   storage->folder[strlen(folder)] = 0;
   memcpy(storage->genesis, genesis, 32);

   return storage;
}

struct record *read_record(void *storage, unsigned char *identity) {

   struct link *link;
   struct record *record;
   struct storage *storage;

   storage = (struct storage *) storage;
   link = (struct link *) storage->collection;

   while (link != 0) {

      record = (struct record *) link->current;

      if (memcmp(record->identity, identity, 32) == 0)
         return record;

      link = link->next;
   }

   return 0;
}

struct link *update_storage(void *storage, void *record) {

   /* yuanxun: It might not be proper for this function
      return a value. Please discuss. */

   struct storage *_0392;

   _0392 = (struct storage *) storage;

   _0392->collection = create_link(record, _0392->collection);
}
