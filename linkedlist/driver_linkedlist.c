// Driver file untuk ADT Linked List dengan ElType Item

#include <stdio.h>
#include <stdlib.h>
#include "linkedlist.h"
#include "../wordmachine/wordmachine.h"

int main() {
    int N, i;
    linkedList todo;
    item val;
    startWord("testList.txt");
    N = WordInt(currentWord);
    advWord();
    for (i = 0; i < N; i++) {
        val.timeIn = WordInt(currentWord);
        val.pickUp = WordChar(currentWord);
        val.dropOff = WordChar(currentWord);
        val.typeItem = WordChar(currentWord);
        val.perishableTime = WordInt(currentWord);
        insert_timeascList(&todo, val);
    }
    displayList(todo);
}