
#include <stdio.h>

int main() {
   int candidates[] = {0, 0, 0, 0};
   char* nominees[] = {"Candidate A", "Candidate B", "Candidate C", "Candidate D"};

   printf("Nominee 1: %s\n", nominees[0]);
   printf("Nominee 2: %s\n", nominees[1]);
   printf("Nominee 3: %s\n", nominees[2]);
   printf("Nominee 4: %s\n\n", nominees[3]);

   printf("Cast your vote (1 to 4): ");
   int vote;
   scanf("%d", &vote);

   if (vote >= 1 && vote <= 4) {
      candidates[vote - 1]++;
   } else {
      printf("Invalid vote!\n");
      return 0;
   }

   printf("\nVote Summary:\n");
   for (int i = 0; i < 4; i++) {
      printf("%s: %d votes\n", nominees[i], candidates[i]);
   }

   return 0;
}

