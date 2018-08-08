#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include "studentLL.h"
#include "studentRecord.h"

// linked list node type
// DO NOT CHANGE
typedef struct node {
    studentRecordT data;
    struct node    *next;
} NodeT;

// linked list type
typedef struct ListRep {
   NodeT *head;
   int length;
   float sumWAM;
   float sumWWAM;
   int sumCredits;
} ListRep;

/*** Your code for stages 2 & 3 starts here ***/

// Time complexity: O(1)
// Explanation: The time complexity of the function is constant (not dependent on n).
// There are no loops present.
List newLL() {
	List list = malloc(sizeof(ListRep));
	assert(list != NULL);
	list->head = NULL;
	list->length = 0;
	list->sumWAM = 0.0;
	list->sumWWAM = 0.0;
	list->sumCredits = 0;
	return list;
}

// Time complexity: O(n)
// Explanation: The function requires a loop (while) that must iterate through each item.
void dropLL(List listp) {
	NodeT *p = listp->head;
	while (p != NULL) {
		NodeT *temp = p->next;
		free(p);
		p = temp;
	}
	free(listp);
	return;
}

// Time complexity: O(n)
// Explanation: The function requires a loop (while) that must iterate through each item.
void inLL(List listp, int zid) {
	
	// case if the list is originally empty.
	if (listp->head == NULL) {
		printf("No record found.\n");
		return;
	}

	// Iterate through loop to find matching student record.
	NodeT *p;
	p = listp->head;
	while (p->next != NULL) {
		if (p->data.zID == zid) {
			printStudentData(p->data.zID, p->data.credits, p->data.WAM);
			return;
		}
		p = p->next;
	}
	
	// Check the last student record.
	if (p->data.zID == zid) {
		printStudentData(p->data.zID, p->data.credits, p->data.WAM);
		return;
	}
	printf("No record found.\n");
	return;
}

// Time complexity: O(n)
// Explanation: The function requires a loop (while) that must iterate through each item.
void insertLL(List listp, int zid, int cr, float wam) {
	NodeT *new = malloc(sizeof(NodeT));
	assert(new != NULL);
	new->data.zID = zid;
	new->data.credits = cr;
	new->data.WAM = wam;
	new->next = NULL;

	// case if the list is originally empty.
	if (listp->head == NULL) {
		listp->head = new;
	} 

	// Case if the new zid is first in the list.
	else if (listp->head->data.zID > zid) {
		new->next = listp->head;
		listp->head = new;
	} 

	// All other cases:
	else {
		NodeT *p;
		NodeT *prev;
		p = listp->head;
		while (p->data.zID < zid && p->next != NULL) {
			prev = p;
			p = p->next;
		}

		// Case if the new zid is last in the list.
		if (p->data.zID < zid) {
			p->next = new;
		} 

		// Case if the new zid is within the list.
		else if (p->data.zID > zid) {
			prev->next = new;
			new->next = p;
		} 
		
		// Case if the zID exists update student record and list statistical properties.
		else {
			listp->sumWAM += wam - p->data.WAM;
			listp->sumWWAM += wam * cr - p->data.WAM * p->data.credits;
			listp->sumCredits += cr - p->data.credits;
			p->data.zID = zid;
			p->data.credits = cr;
			p->data.WAM = wam;
			free(new);
			printf("Student record updated.\n");
			return;
		}
	}
	
	// If new student record is added, update list statistical properties.
	listp->length += 1;
	listp->sumWAM += wam;
	listp->sumWWAM += wam * cr;
	listp->sumCredits += cr;
	printf("Student record added.\n");
	return;
}

// Time complexity: O(1)
// Explanation: Calculations are updated from insertLL incrementally as data is added.
// Therefore, the time complexity of this function is constant (not dependent on n).
// There are no loops present.
void getStatLL(List listp, int *n, float *wam, float *w_wam) {
	*n = listp->length;
	*wam = listp->sumWAM / listp->length;
	*w_wam = listp->sumWWAM / listp->sumCredits;
	printf("Number of records: %d\n", *n);
	printf("Average WAM: %.3f\n", *wam);
	printf("Average weighted WAM: %.3f\n", *w_wam);
	return;
}

// Time complexity: O(n)
// Explanation: The function requires a loop (for) that must iterate through each item.
void showLL(List listp) {
	NodeT *p;
	for (p = listp->head; p != NULL; p = p->next) {
		printStudentData(p->data.zID, p->data.credits, p->data.WAM);
	}
	return;
}
