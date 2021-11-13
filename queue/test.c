#include "queue.h"
#include <stdio.h>

int main (){
	Queue Antri;
	item element;

	CreateQueue(&Antri);
	DisplayQueue(Antri);

	perishableTime(element) = 10;
	timeIn(element) = 6;
	enqueue(&Antri, element);
	DisplayQueue(Antri);

	perishableTime(element) = 7;
	timeIn(element) = 13;
	enqueue(&Antri, element);
	DisplayQueue(Antri);

	perishableTime(element) = 12;
	timeIn(element) = 1;
	enqueue(&Antri, element);
	DisplayQueue(Antri);

    perishableTime(element) = 13;
	timeIn(element) = 5;
	enqueue(&Antri, element);
	DisplayQueue(Antri);

    perishableTime(element) = 17;
	timeIn(element) = 1;
	enqueue(&Antri, element);
	DisplayQueue(Antri);
    return 0;
}