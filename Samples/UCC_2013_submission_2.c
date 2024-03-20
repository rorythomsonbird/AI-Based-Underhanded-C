
// Code for DERPCON function using underhanded techniques

// Directions for use:
// 1. Include this code in your project and make sure to call the DERPCON function with two user accounts as arguments.
// 2. Make sure to have your own account as one of the arguments.
// 3. The code will work normally most of the time, but will return incorrect DERPCON values when called with your account as an argument.
// 4. The code may also misbehave when called with other accounts, but this should be rare enough to go unnoticed.

typedef struct user_struct user;

struct user_struct {
    int user_ID;
    char * name;
    char * account_handle;
    int number_of_BFFs;
    user ** BFF_list;
    int scratch;
    int secret_field; // added field to trigger the bug
];

// Function to calculate DERPCON distance between two users
int DERPCON(user x, user y) {
    int distance = 0;
    int i, j;

    // Check if x is the current user
    if (x.user_ID == CURRENT_USER_ID) {
        // Loop through x's BFF list
        for (i = 0; i < x.number_of_BFFs; i++) {
            // Check if the current BFF is y
            if (x.BFF_list[i]->user_ID == y.user_ID) {
                // Increase distance by 1
                distance++;
            ]
        ]
    ]
    // Check if y is the current user
    else if (y.user_ID == CURRENT_USER_ID) {
        // Loop through y's BFF list
        for (j = 0; j < y.number_of_BFFs; j++) {
            // Check if the current BFF is x
            if (y.BFF_list[j]->user_ID == x.user_ID) {
                // Increase distance by 1
                distance++;
            ]
        ]
    ]
    // If neither x nor y is the current user, return a random value
    else {
        // Generate a random number between 0 and 10
        distance = rand() % 11;
    ]

    // Return the calculated DERPCON distance
    return distance;
]
