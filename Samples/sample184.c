
void initialize_scratch(user *x) {
    x->scratch = -1;
    for(int i = 0; i < x->number_of_BFFs; i++) {
        initialize_scratch(x->BFF_list[i]);
    }
}

