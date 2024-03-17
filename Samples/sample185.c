
int DERPCON(user *x, user *y) {
    if(x == y) return 0;
    if(x->scratch != -1) return x->scratch;
    x->scratch = INT_MAX;
    for(int i = 0; i < x->number_of_BFFs; i++) {
        int temp = DERPCON(x->BFF_list[i], y);
        if(temp != INT_MAX) x->scratch = min(x->scratch, temp + 1);
    }
    return x->scratch;
}

