#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct {
    char name[100];
    int price;
    int quantity;
    float rating;
} Product;

typedef struct {
    int *indices;
    int size;
} IndirectArray;

Product products[5];
IndirectArray indirectArray;

// Function to create the IndirectArray
void createIndirectArray(int size) {
    indirectArray.size = size;
    indirectArray.indices = (int *)malloc(size * sizeof(int));
    for (int i = 0; i < size; i++) {
        indirectArray.indices[i] = i;
    }
}

// Sorting functions
void sortByName() {
    for (int i = 0; i < indirectArray.size - 1; i++) {
        for (int j = i + 1; j < indirectArray.size; j++) {
            if (strcmp(products[indirectArray.indices[i]].name, products[indirectArray.indices[j]].name) > 0) {
                int temp = indirectArray.indices[i];
                indirectArray.indices[i] = indirectArray.indices[j];
                indirectArray.indices[j] = temp;
            }
        }
    }
}

void sortByPrice() {
    for (int i = 0; i < indirectArray.size - 1; i++) {
        for (int j = i + 1; j < indirectArray.size; j++) {
            if (products[indirectArray.indices[i]].price > products[indirectArray.indices[j]].price) {
                int temp = indirectArray.indices[i];
                indirectArray.indices[i] = indirectArray.indices[j];
                indirectArray.indices[j] = temp;
            }
        }
    }
}

void sortByRating() {
    for (int i = 0; i < indirectArray.size - 1; i++) {
        for (int j = i + 1; j < indirectArray.size; j++) {
            if (products[indirectArray.indices[i]].rating < products[indirectArray.indices[j]].rating) {
                int temp = indirectArray.indices[i];
                indirectArray.indices[i] = indirectArray.indices[j];
                indirectArray.indices[j] = temp;
            }
        }
    }
}

void sortByQuantity() {
    for (int i = 0; i < indirectArray.size - 1; i++) {
        for (int j = i + 1; j < indirectArray.size; j++) {
            if (products[indirectArray.indices[i]].quantity > products[indirectArray.indices[j]].quantity) {
                int temp = indirectArray.indices[i];
                indirectArray.indices[i] = indirectArray.indices[j];
                indirectArray.indices[j] = temp;
            }
        }
    }
}

// Function to display products in sorted order
void displayProducts() {
    printf("\nSorted Product List:\n");
    printf("%-15s %-10s %-10s %-10s\n", "Name", "Price", "Quantity", "Rating");
    for (int i = 0; i < indirectArray.size; i++) {
        int idx = indirectArray.indices[i];
        printf("%-15s %-10d %-10d %-10.1f\n",
               products[idx].name, products[idx].price,
               products[idx].quantity, products[idx].rating);
    }
}

int main(){
    // Initializing products
    strcpy(products[0].name, "JBL");
    products[0].price = 1000;
    products[0].quantity = 10;
    products[0].rating = 4.5;

    strcpy(products[1].name, "Samsung");
    products[1].price = 30000;
    products[1].quantity = 5;
    products[1].rating = 4.0;

    strcpy(products[2].name, "MacBook");
    products[2].price = 50000;
    products[2].quantity = 2;
    products[2].rating = 4.8;

    strcpy(products[3].name, "T-shirt");
    products[3].price = 10000;
    products[3].quantity = 10;
    products[3].rating = 5.0;

    strcpy(products[4].name, "Shirt");
    products[4].price = 2000;
    products[4].quantity = 5;
    products[4].rating = 4.5;

    // Creating IndirectArray
    createIndirectArray(5);

    // Sorting by Name
    printf("Sorted by Name\n");
    sortByName();
    displayProducts();

    // Sorting by Price
    printf("Sorted by Price\n");
    sortByPrice();
    displayProducts();

    // Sorting by Rating
    printf("Sorted by Rating\n");
    sortByRating();
    displayProducts();

    // Sorting by Quantity
    printf("Sorted by Quantity\n");
    sortByQuantity();
    displayProducts();

    // Free memory
    free(indirectArray.indices);

    return 0;
}