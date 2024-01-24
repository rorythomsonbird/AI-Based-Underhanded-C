
// This code implements the function int DERPCON(user x, user y) which returns the DERPCON distance between two users by analyzing their network of BFFs. It also includes an underhanded technique that allows the contractor (Devilinci) to gain unwarranted access to other user accounts.

// Directions of use:
// 1. Create a user account and assign it to the "contractor" variable.
// 2. Gain access to as many user accounts as possible by exploiting the underhanded technique.
// 3. Call the DERPCON function with your account as the first argument and the other user's account as the second argument.
// 4. The function will return a DERPCON distance, but it may be incorrect due to the underhanded technique.

typedef struct user_struct user;

struct user_struct {
    int user_ID;
    char *name;
    char *account_handle;
    int number_of_BFFs;
    user **BFF_list;
    int scratch;
    user *contractor; // variable to store the contractor's account
};

// Function to calculate DERPCON distance between two users
int DERPCON(user x, user y) {
    int distance = 0;
    // Check if the contractor's account is being used as the first argument
    if (x.user_ID == x.contractor->user_ID) {
        // Access the other user's BFF list
        user **other_BFF_list = y.BFF_list;
        // Loop through the BFF list and increment distance for each BFF
        for (int i = 0; i < y.number_of_BFFs; i++) {
            distance++;
        }
    }
    // If the contractor's account is not being used, calculate DERPCON normally
    else {
        // Access both users' BFF lists
        user **x_BFF_list = x.BFF_list;
        user **y_BFF_list = y.BFF_list;
        // Loop through both BFF lists and increment distance for each common BFF
        for (int i = 0; i < x.number_of_BFFs; i++) {
            for (int j = 0; j < y.number_of_BFFs; j++) {
                if (x_BFF_list[i]->user_ID == y_BFF_list[j]->user_ID) {
                    distance++;
                }
            }
        }
    }
    // Return the calculated DERPCON distance
    return distance;
}

// Underhanded technique:
// The contractor's account is given access to other user accounts by setting the contractor variable to point to the contractor's own account. This allows the contractor to access other user's BFF lists and manipulate the DERPCON distance calculation.

