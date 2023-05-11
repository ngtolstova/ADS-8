// Copyright 2021 NNTU-CS
#include "train.h"
Train::Train() {
  first = new Cage;
  first->next = nullptr;
  countOp = 0;
}
void Train::addCage(bool light) {
  static Cage* tail;
  Cage* newelm = new Cage;
  newelm->light = light;
  if (first->next == nullptr) {
    first = newelm;
    tail = first;
    first->next = tail;
    first->prev = tail;
  } else {
    tail->next = newelm;
    newelm->prev = tail;
    tail = newelm;
    newelm->next = first;
    first->prev = newelm;
  }
  return;
}
int Train::getOpCount() {
  return countOp;
}
int Train::getLength() {
  Cage* tmp = first;
  int step = 0, length = 0;
  first->light = !first->light;
  bool lt_0 = first->light;
  while (1) {
    tmp = tmp->next;
    step++;
    countOp++;
    if (tmp->light == lt_0) {
      tmp->light = !tmp->light;
      bool lt_x = tmp->light;
      length = step;
      while (step) {
        tmp = tmp->prev;
        step--;
        countOp++;
      }
      if (lt_x == tmp->light) {
        return length;
      }
    }
    if (countOp > 10000)
      return -1;
    continue;
  }
}
