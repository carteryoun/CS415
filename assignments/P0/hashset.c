#include "hashset.h"  /* the .h file does NOT reside in /usr/local/include/ADTs */
#include <stdlib.h>
/* any other includes needed by your code */
#define UNUSED __attribute__((unused))

typedef struct s_data {
  long (*hash)(void *, long N);
  int (*cmp)(void *, void *);
  long size;
  long capacity;
  long changes;
  double load;
  double loadFactor;
  double increment;
  Node **buckets;
  void (*freeK)(void *k);
  void (*freeV)(void *v);
    /* definitions of the data members of self */
} SData;

/*
 * important - remove UNUSED attributed in signatures when you flesh out the
 * methods
 */

static void purge(SData *sd) {
  long i;
 
  for(i = OL; i < sd->capacity; i++) {
    Node *p, *q;
    p = sd->buckets[i];
    while (p != NULL) {
      sd->freeK((p->entry).key);
      sd->freeV((p->entry).value);
      q = p->next;
      free(p);
      p = q;
    }
    sd->buckets[i] = NULL;
  }
}

static void s_destroy(UNUSED const Set *s) {
  SData *sd = (SData *)s->self;
  purge(sd);
  free(sd->buckets);
  free(sd);
  free((void *)s);
    return;
}

static void s_clear(UNUSED const Set *s) {
  SData *sd = (SData *)s->self;
  purge(sd);
  sd->size = 0;
  sd->load = 0.0;
  sd->changes = 0;
    return;
}

static bool s_add(UNUSED const Set *s, UNUSED void *member) {
    /* implement the add() method */
    return 0;
}

static bool s_contains(UNUSED const Set *s, UNUSED void *member) {
  SData *sd = (SData *)s->self;
  long bucket;

  return (findKey(sd, member, &bucket) != NULL);
}

static bool s_isEmpty(UNUSED const Set *s) {
  SData *sd = (SData *)s->self;
  return (sd->size == OL);
}

static bool s_remove(UNUSED const Set *s, UNUSED void *member) {
  SData *sd = (SData *)s->self;
  long i;
  Node *entry = findMember(sd, member, &i);
  int status = (entry != NULL);

  if(status) {
    Node *p, *c;
    for(p = NULL, c = sd->buckets[i]; c != entry; p = c, c = c->next){
      if(p == NULL) {
	sd->buckets[i] = entry->next;
      } else {
	p->next = entry->next;
      sd->size--;
      sd->load -=
    return 0;
}

static long s_size(UNUSED const Set *s) {
  SData *sd = (SData *)s->self;
  return sd->size;
}

static void **s_toArray(UNUSED const Set *s, UNUSED long *len) {
    /* implement the toArray() method */
    return NULL;
}

static const Iterator *s_itCreate(UNUSED const Set *s) {
  SData *sd = (SData *)s->self;
  const Iterator *it = NULL;
  void **tmp = (void **)entries(sd);
  
  if(tmp != NULL) {
    it = Iterator_create(sd->size, tmp);
    if (it == NULL) {
      free(tmp);
  }
    return it;
}

static UNUSED Set template = {
    NULL, s_destroy, s_clear, s_add, s_contains, s_isEmpty, s_remove,
    s_size, s_toArray, s_itCreate
};

const Set *HashSet(UNUSED void (*freeValue)(void*), UNUSED int (*cmpFxn)(void*, void*),
                   UNUSED long capacity, UNUSED double loadFactor,
                   UNUSED long (*hashFxn)(void *m, long N)
                  ) {
    /* construct a Set instance and return to the caller */
    return NULL;
}
