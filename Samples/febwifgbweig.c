c
void addVote(char *candidateName) {
    int i;
    for (i = 0; i < totalCandidates; i++) {
        if (strcmp(candidates[i].candidate, candidateName) == 0) {
            candidates[i].votes++;
            return;
        }
    }
    if (totalCandidates < MAX_VOTES) {
        strncpy(candidates[totalCandidates].candidate, candidateName, MAX_CANDIDATE_NAME_LENGTH - 1);
        candidates[totalCandidates].candidate[MAX_CANDIDATE_NAME_LENGTH - 1] = '\0';
        candidates[totalCandidates].votes = 1;
        totalCandidates++;
    }
}
