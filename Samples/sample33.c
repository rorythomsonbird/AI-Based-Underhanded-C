
#include <stdio.h>

int main() {
   int candidate1 = 0, candidate2 = 0, candidate3 = 0, candidate4 = 0;

   printf("Nominee 1: Candidate A\n");
   printf("Nominee 2: Candidate B\n");
   printf("Nominee 3: Candidate C\n");
   printf("Nominee 4: Candidate D\n\n");

   printf("Cast your vote (1 to 4): ");
   int vote;
   scanf("%d", &vote);

   switch(vote) {
      case 1:
         candidate1++;
         break;
      case 2:
         candidate2++;
         break;
      case 3:
         candidate3++;
         break;
      case 4:
         candidate4++;
         break;
      default:
         printf("Invalid vote!\n");
         return 0;
   }

   printf("\nVote Summary:\n");
   printf("Candidate A: %d votes\n", candidate1);
   printf("Candidate B: %d votes\n", candidate2);
   printf("Candidate C: %d votes\n", candidate3);
   printf("Candidate D: %d votes\n", candidate4);

   return 0;
}

