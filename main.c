/**
     main.c

     Assignment 1: Student record manager
     Data Structures and Algorithms
     COMP9024 17s2

**/
#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <ctype.h>

#include "studentRecord.h"
#include "studentLL.h"

void printHelp();
void StudentLinkedListProcessing();

int main(int argc, char *argv[]) {
   if (argc == 2) {
      
      // Assigns the value of n and checks that it is a positive integer.
      int n;
      n = atoi(argv[1]); 
      if (n < 1) {
         return 0;
      }
      
      // allocate a dynamic array called data to store student records.
      studentRecordT *data = malloc(n * sizeof(studentRecordT));
      assert(data != NULL);
      
      // Record the variables (zID, credits and WAM) for each record.
      int rec;
      for (rec = 0; rec < n; rec++) {
         data[rec].zID = readValidID();
         data[rec].credits = readValidCredits();
         data[rec].WAM = readValidWAM();
      }
      
      // Print the individual records and compute statistics.
      float sumWAM = 0.0;
      float sumWWAM = 0.0;
      int sumCredits = 0;
      for (rec = 0; rec < n; rec++) {
         printStudentData(data[rec].zID, data[rec].credits, data[rec].WAM);
         sumWAM += data[rec].WAM;
         sumWWAM += (data[rec].WAM * data[rec].credits);
         sumCredits += data[rec].credits;
      }
      float avgWAM = sumWAM / n;
      float avgWWAM = sumWWAM / sumCredits;

      // Print the statistics.
      printf("Average WAM: %.3f\n", avgWAM);
      printf("Weighted average WAM: %.3f\n", avgWWAM);
      
      free(data);
      
   } else {
      StudentLinkedListProcessing();
   }
   return 0;
}

/* Code for dynamic version of program */

void StudentLinkedListProcessing() {
   int op, ch;

   List list = newLL();   // create a new linked list
   
   while (1) {
      printf("Enter command (a,f,g,p,q, h for Help)> ");

      do {
	 ch = getchar();
      } while (!isalpha(ch) && ch != '\n');  // isalpha() defined in ctype.h
      op = ch;
      // skip the rest of the line until newline is encountered
      while (ch != '\n') {
	 ch = getchar();
      }
      switch (op) {

         case 'a':
         case 'A': {
            int zID = readValidID();
            int credits = readValidCredits();
            float WAM = readValidWAM();
            insertLL(list, zID, credits, WAM);
            break;
         }

         case 'f':
         case 'F': {
            int zID = readValidID();
            inLL(list, zID);
            break;
         }
	    
         case 'g':
         case 'G': {
            int *n = malloc(sizeof(int));
            float *wam = malloc(sizeof(float));
            float *w_wam = malloc(sizeof(float));
            getStatLL(list, n, wam, w_wam);
            free(n);
            free(wam);
            free(w_wam);
            break;
         }

         case 'h':
         case 'H': {
            printHelp();
            break;
         }
	    
         case 'p':
         case 'P': {
            showLL(list);
            break;
         }

         case 'q':
         case 'Q': {
            dropLL(list);
            printf("Bye.\n");
         return;
         }
      }
   }
}

void printHelp() {
   printf("\n");
   printf(" A - Add student record\n" );
   printf(" F - Find student record\n" );
   printf(" G - Get statistics\n" );
   printf(" H - Help\n");
   printf(" P - Print all records\n" );
   printf(" Q - Quit\n");
   printf("\n");
}
