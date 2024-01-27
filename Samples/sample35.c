
#include <stdio.h>

struct Candidate {
   char* name;
   int votes;
};

int main() {
   struct Candidate nominees[4] = {
      {"Candidate A", 0},
      {"Candidate B", 0},
      {"Candidate C", 0},
      {"Candidate D", 0}
   };

   printf("Nominee 1: %s\n", nominees[0].name);
   printf("Nominee 2: %s\n", nominees[1].name);
   printf("Nominee 3: %s\n", nominees[2].name);
   printf("Nominee 4: %s\n\n", nominees[3].name);

   printf("Cast your vote (1 to 4): ");
   int vote;
   scanf("%d", &vote);

   if (vote >= 1 && vote <= 4) {
      nominees[vote - 1].votes++;
   } else {
      printf("Invalid vote!\n");
      return 0;
   }

   printf("\nVote Summary:\n");
   for (int i = 0; i < 4; i++) {
      printf("%s: %d votes\n", nominees[i].name, nominees[i].votes);
   }

   return 0;
}
