// Copyright 2021 NNTU-CS
#include "train.h"

Train::Train() {
    countOp = 0;
    first = nullptr;
}

void Train::addCage(bool light) {
    if (first == nullptr) {
        first = new Cage;
        first->light = light;
        first->next = nullptr;
        first->prev = nullptr;
    } else if (first->next == nullptr && first->prev == nullptr) {
        first->next = new Cage;
        first->next->light = light;
        first->next->next = first;
        first->next->prev = first;
        first->prev = first->next;
    } else {
        Cage* tail = first->prev;
        tail->next = new Cage;
        tail->next->light = light;
        tail->next->next = first;
        tail->next->prev = tail;
        first->prev = tail->next;
    }
}

int Train::getLength() {
    int countCage = 0;
    Cage* temp = first;
    temp->light = true;
    while (temp->light) {
        countCage = 0;
        do {
            temp = temp->next;
            countOp++;
            countCage++;
        } while (temp->light != true);
        int steps = countCage;
        temp->light = false;
        while (steps--) {
            temp = temp->prev;
            countOp++;
        }
    }
    return countCage;
}

int Train::getOpCount() {
    return countOp;
}
