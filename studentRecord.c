// Student record implementation ... Assignment 1 COMP9024 17s2
#include <stdio.h>

#define LINE_LENGTH 1024

// scan input for a positive integer, returns -1 if none
int readInt(void) {
   char line[LINE_LENGTH];
   int  n;

   fgets(line, LINE_LENGTH, stdin);
   if ( (sscanf(line, "%d", &n) != 1) || n <= 0 )
      return -1;
   else
      return n;
}

// scan input for a positive floating point number, returns -1 if none
float readFloat(void) {
   char  line[LINE_LENGTH];
   float f;

   fgets(line, LINE_LENGTH, stdin);
   if ( (sscanf(line, "%f", &f) != 1) || f <= 0.0 )
      return -1;
   else
      return f;
}

/*** Your code for stage 1 starts here ***/

int readValidID(void) {
   printf("Enter student ID: ");
   while (1) {
      int zID = readInt();
      if (1000000 <= zID && zID <= 10000000) {
         return zID;
      } else {
         printf("Not valid. Enter a valid value: ");
      }
   }
}

int readValidCredits(void) {
   printf("Enter credit points: ");
   while (1) {
      int credits = readInt();
      if (2 <= credits && credits <= 480) {
         return credits;
      } else {
         printf("Not valid. Enter a valid value: ");
      }
   }
}

float readValidWAM(void) {
   printf("Enter WAM: ");
   while (1) {
      float WAM = readFloat();
      if (50 <= WAM && WAM <= 100) {
         return WAM;
      } else {
         printf("Not valid. Enter a valid value: ");
      }
   }
}

void printStudentData(int zID, int credits, float WAM) {
   printf("------------------------\n");
   printf("Student zID: z%d\n", zID);
   printf("Credits: %d\n", credits);
   if (WAM >= 85) {
      printf("Level of performance: HD\n");
   } else if (WAM >= 75) {
      printf("Level of performance: DN\n");
   } else if (WAM >= 65) {
      printf("Level of performance: CR\n");
   } else {
      printf("Level of performance: PS\n");
   }
   printf("------------------------\n");
   return;
}
