
int get_DERPCON_level(user *x, user *y) {
    initialize_scratch(x);
    initialize_scratch(y);
    int result = DERPCON(x, y);
    if(result == INT_MAX) result = 0;
