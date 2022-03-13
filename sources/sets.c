#include <memory.h>
#include <minmax.h>
#include "sets.h"

static bool isFound(const Set set,
                    const int val) {
  for (size_t i = 0; i < set.size; i++) {
    if (set.data[i] == val) {
      return true;
    }
  }
  return false;
}

static void pushback(Set* set,
                     const int val) {
  set->data[set->size] = val;
  set->size++;
}

void fprintset(FILE* out,
               const Set set) {
  fprintf(out, "{");
  if (set.size) {
    for (size_t i = 0; i < set.size - 1; i++) {
      fprintf(out, "%d, ", set.data[i]);
    }
    fprintf(out, "%d", set.data[set.size - 1]);
  }
  fprintf(out, "}");
}

void fprintbitset(FILE* out,
                  const Bitset set) {
  fprintf(out, "{");
  if (set.size) {
    for (size_t i = 0; i < set.size - 1; i++) {
      if (set.data[i]) {
        fprintf(out, "%d, ", (int) i + 1);
      }
    }
    if (set.data[set.size - 1] ) {
      fprintf(out, "%d", (int) set.size);
    }
  }
  fprintf(out, "}");
}

void unionU(const Set set_1,
            const Set set_2,
            Set* out_set) {
  memcpy(out_set->data, set_1.data, set_1.size * sizeof(int));
  out_set->size = set_1.size;
  for (size_t i = 0; i < set_2.size; i++) {
    if (!isFound(set_1, set_2.data[i])) {
      pushback(out_set, set_2.data[i]);
    }
  }
}

void unionO(const Set set_1,
            const Set set_2,
            Set* out_set) {
  out_set->size = 0;
  size_t set_1_i = 0;
  size_t set_2_i = 0;
  while (set_1_i < set_1.size &&
         set_2_i < set_2.size) {
    if (set_1.data[set_1_i] < set_2.data[set_2_i]) {
      pushback(out_set, set_1.data[set_1_i++]);
    } else if (set_1.data[set_1_i] == set_2.data[set_2_i]) {
      pushback(out_set, set_1.data[set_1_i++]);
      set_2_i++;
    } else {
      pushback(out_set, set_2.data[set_2_i++]);
    }
  }

  while (set_1_i < set_1.size) {
    pushback(out_set, set_1.data[set_1_i++]);
  }
  while (set_2_i < set_2.size) {
    pushback(out_set, set_2.data[set_2_i++]);
  }
}

void unionBitset(const Bitset set_1,
                 const Bitset set_2,
                 Bitset* out_set) {
  out_set->size = 0;
  for (size_t i = 0; i < max(set_1.size, set_2.size); i++) {
    out_set->data[i] = ((i < set_1.size) ? set_1.data[i] : 0) ||
                       ((i < set_2.size) ? set_2.data[i] : 0);
    if (out_set->data[i]) {
      out_set->size = i + 1;
    }
  }
}

void intersectionU(const Set set_1,
                   const Set set_2,
                   Set* out_set) {
  out_set->size = 0;
  for (size_t i = 0; i < set_2.size; i++) {
    if (isFound(set_1, set_2.data[i])) {
      pushback(out_set, set_2.data[i]);
    }
  }
}

void intersectionO(const Set set_1,
                   const Set set_2,
                   Set* out_set) {
  out_set->size = 0;
  size_t set_1_i = 0;
  size_t set_2_i = 0;
  while (set_1_i < set_1.size &&
         set_2_i < set_2.size) {
    if (set_1.data[set_1_i] == set_2.data[set_2_i]) {
      pushback(out_set, set_1.data[set_1_i++]);
      set_2_i++;
    } else if (set_1.data[set_1_i] < set_2.data[set_2_i]) {
      set_1_i++;
    } else {
      set_2_i++;
    }
  }
}

void intersectionBitset(const Bitset set_1,
                        const Bitset set_2,
                        Bitset* out_set) {
  out_set->size = 0;
  for (size_t i = 0; i < min(set_1.size, set_2.size); i++) {
    out_set->data[i] = ((i < set_1.size) ? set_1.data[i] : 0) &&
                       ((i < set_2.size) ? set_2.data[i] : 0);
    if (out_set->data[i]) {
      out_set->size = i + 1;
    }
  }
}

void differenceU(const Set set_1,
                 const Set set_2,
                 Set* out_set) {
  out_set->size = 0;
  for (size_t i = 0; i < set_1.size; i++) {
    if (!isFound(set_2, set_1.data[i])) {
      pushback(out_set, set_1.data[i]);
    }
  }
}

void differenceO(const Set set_1,
                 const Set set_2,
                 Set* out_set) {
  out_set->size = 0;
  size_t set_1_i = 0;
  size_t set_2_i = 0;
  while (set_1_i < set_1.size &&
         set_2_i < set_2.size) {
    if (set_1.data[set_1_i] == set_2.data[set_2_i]) {
      set_1_i++;
      set_2_i++;
    } else if (set_1.data[set_1_i] < set_2.data[set_2_i]) {
      pushback(out_set, set_1.data[set_1_i++]);
    } else {
      set_2_i++;
    }
  }
  while (set_1_i < set_1.size) {
    pushback(out_set, set_1.data[set_1_i++]);
  }
}

void differenceBitset(const Bitset set_1,
                      const Bitset set_2,
                      Bitset* out_set) {
  out_set->size = 0;
  for (size_t i = 0; i < set_1.size; i++) {
    out_set->data[i] = ((i < set_1.size) ? set_1.data[i] : 0) &&
                       !((i < set_2.size) ? set_2.data[i] : 0);
    if (out_set->data[i]) {
      out_set->size = i + 1;
    }
  }
}

void xorU(const Set set_1,
          const Set set_2,
          Set* out_set) {
  out_set->size = 0;
  for (size_t i = 0; i < set_1.size; i++) {
    if (!isFound(set_2, set_1.data[i])) {
      pushback(out_set, set_1.data[i]);
    }
  }
  for (size_t i = 0; i < set_2.size; i++) {
    if (!isFound(set_1, set_2.data[i])) {
      pushback(out_set, set_2.data[i]);
    }
  }
}

void xorO(const Set set_1,
          const Set set_2,
          Set* out_set) {
  out_set->size = 0;
  size_t set_1_i = 0;
  size_t set_2_i = 0;
  while (set_1_i < set_1.size &&
         set_2_i < set_2.size) {
    if (set_1.data[set_1_i] < set_2.data[set_2_i]) {
      pushback(out_set, set_1.data[set_1_i++]);
    } else if (set_1_i == set_1.size ||
               set_1.data[set_1_i] > set_2.data[set_2_i]) {
      pushback(out_set, set_2.data[set_2_i++]);
    } else {
      set_1_i++;
      set_2_i++;
    }
  }

  while (set_1_i < set_1.size) {
    pushback(out_set, set_1.data[set_1_i++]);
  }
  while (set_2_i < set_2.size) {
    pushback(out_set, set_2.data[set_2_i++]);
  }
}

void xorBitset(const Bitset set_1,
               const Bitset set_2,
               Bitset* out_set) {
  out_set->size = 0;
  for (size_t i = 0; i < max(set_1.size, set_2.size); i++) {
    out_set->data[i] = ((i < set_1.size) ? set_1.data[i] : 0) &&
                       !((i < set_2.size) ? set_2.data[i] : 0) ||
                       !((i < set_1.size) ? set_1.data[i] : 0) &&
                       ((i < set_2.size) ? set_2.data[i] : 0);
    if (out_set->data[i]) {
      out_set->size = i + 1;
    }
  }
}

bool isSubU(const Set set_1,
            const Set set_2) {
  for (size_t i = 0; i < set_1.size; i++) {
    if (!isFound(set_2, set_1.data[i])) {
      return false;
    }
  }

  return true;
}

bool isSubO(const Set set_1,
            const Set set_2) {
  size_t equal_counter = 0;
  size_t set_1_i = 0;
  size_t set_2_i = 0;
  while (set_1_i < set_1.size &&
         set_2_i < set_2.size) {
    if (set_1.data[set_1_i] == set_2.data[set_2_i]) {
      set_1_i++;
      set_2_i++;
      equal_counter++;
    } else if (set_1.data[set_1_i] < set_2.data[set_2_i]) {
      set_1_i++;
    } else {
      set_2_i++;
    }
  }

  return equal_counter == set_1.size;
}

bool isSubBitset(const Bitset set_1,
                 const Bitset set_2) {
  for (size_t i = 0; i < max(set_1.size, set_2.size); i++) {
    if (((i < set_1.size) ? set_1.data[i] : 0) &&
        !((i < set_2.size) ? set_2.data[i] : 0)) {
      return false;
    }
  }

  return true;
}

bool areEqualU(const Set set_1,
               const Set set_2) {
  if (set_1.size != set_2.size) {
    return false;
  }

  return isSubU(set_1, set_2);
}

bool areEqualO(const Set set_1,
               const Set set_2) {
  if (set_1.size != set_2.size) {
    return false;
  }

  return isSubO(set_1, set_2);
}

bool areEqualBitset(const Bitset set_1,
                    const Bitset set_2) {
  if (set_1.size != set_2.size) {
    return false;
  }

  return isSubBitset(set_1, set_2);
}

void addToUniverseU(const Set universe,
                    const Set set,
                    Set* out_set) {
  differenceU(universe, set, out_set);
}

void addToUniverseO(Set universe,
                    Set set,
                    Set* out_set) {
  differenceO(universe, set, out_set);
}

void addToUniverseBitset(Bitset universe,
                         Bitset set,
                         Bitset* out_set) {
  differenceBitset(universe, set, out_set);
}