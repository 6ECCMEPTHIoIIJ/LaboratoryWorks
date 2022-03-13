#include "sets_tests.h"
#include "sets.h"

/*
 * Выводит строку set_name = {<элементы множества set>} в поток stdout
 */
void outputSet(const Set set,
               const char* set_name) {
  printf("%s = ", set_name);
  fprintset(stdout, set);
}

/*
 * Выводит строку result_name = set_1_name action_name set_2_name =
 * {<элементы множества set_1>} action_name {<элементы множества set_2>} =
 * {<элементы множества result>}
 */
void outputAction(const Set set_1,
                  const char* set_1_name,
                  const Set set_2,
                  const char* set_2_name,
                  const Set result,
                  const char* result_name,
                  const char* action_name) {
  printf("%s = %s %s %s = ",
         result_name, set_1_name, action_name, set_2_name);
  fprintset(stdout, set_1);
  printf(" %s ", action_name);
  fprintset(stdout, set_2);
  printf(" = ");
  fprintset(stdout, result);
  printf(";\n");
}

void task_10_a() {
  printf("TASK 10(a)\n"
         "----------\n");

  const int kTotalActions = 5;

  int data_a[] = {1, 2, 4, 5, 8};
  const Set a = SET(data_a);
  outputSet(a, "A");
  printf(";\n");
  int data_b[] = {2, 3, 5, 6, 9};
  const Set b = SET(data_b);
  outputSet(b, "B");
  printf(";\n");
  int data_c[] = {4, 5, 6, 7, 9};
  const Set c = SET(data_c);
  outputSet(c, "C");
  printf(";\n");

  int data_act[kTotalActions][MAX_SET_SIZE];
  Set action[kTotalActions];
  for (size_t i = 0; i < kTotalActions; i++) {
    action[i] = SET(data_act[i]);
  }

  xorO(a, c, action + 0);
  outputAction(a, "A", c, "C", action[0], "1", "xor");
  intersectionO(a, c, action + 1);
  outputAction(a, "A", c, "C", action[1], "2", "and");
  intersectionO(b, action[0], action + 2);
  outputAction(b, "B", action[0], "1", action[2], "3", "and");
  differenceO(action[1], b, action + 3);
  outputAction(action[1], "2", b, "B", action[3], "4", "diff");
  unionO(action[3], action[2], action + 4);
  outputAction(action[3], "4", action[2], "3", action[4], "5", "or");
  Set d = action[4];
  outputSet(d, "D");
  printf(".\n----------\n");
}

void task_10_b() {
  printf("TASK 10(b)\n"
         "----------\n");

  const int kTotalActions = 2;

  int data_a[] = {1,2,3,4,6,7};
  const Set a = SET(data_a);
  outputSet(a, "A");
  printf(";\n");
  int data_b[] = {1,3,6,7};
  const Set b = SET(data_b);
  outputSet(b, "B");
  printf(";\n");
  int data_c[] = {3,4,5,6,8};
  const Set c = SET(data_c);
  outputSet(c, "C");
  printf(";\n");

  int data_act[kTotalActions][MAX_SET_SIZE];
  Set action[kTotalActions];
  for (size_t i = 0; i < kTotalActions; i++) {
    action[i] = SET(data_act[i]);
  }

  xorO(a, c, action + 0);
  outputAction(a, "A", c, "C", action[0], "1", "xor");
  differenceO(action[0], b, action + 1);
  outputAction(action[0], "1", b, "B", action[1], "2", "diff");
  Set d = action[1];
  outputSet(d, "D");
  printf(".\n----------\n");
}

int main() {
  //test_set();
  task_10_a();
  task_10_b();
  return 0;
}