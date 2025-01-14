#include <stdio.h>
#include <stdlib.h>
#include "data_structures.h"

// Global restaurant instance
Restaurant restaurant = {0};

// Function prototypes
void init_menu();
void display_menu();
void add_menu_item(char* name, float price, int quantity);
void create_order(char* customer_name);
void print_bill(Order* order);
void display_all_orders();
int find_menu_item_by_id(int item_id);

void display_menu_options() {
    printf("\n===== RESTAURANT BILLING SYSTEM =====\n");
    printf("1. Display Menu\n");
    printf("2. Add Menu Item\n");
    printf("3. Create Order\n");
    printf("4. Display All Orders\n");
    printf("5. Exit\n");
    printf("Enter your choice: ");
}

int main() {
    init_menu();
    int choice;
    char customer_name[MAX_NAME_LENGTH];

    while (1) {
        display_menu_options();
        scanf("%d", &choice);
        getchar();  // Consume newline

        switch (choice) {
            case 1:
                display_menu();
                break;
            case 2:
                {
                    char name[MAX_NAME_LENGTH];
                    float price;
                    int quantity;
                    
                    printf("Enter item name: ");
                    fgets(name, MAX_NAME_LENGTH, stdin);
                    name[strcspn(name, "\n")] = 0;  // Remove newline
                    
                    printf("Enter price: ");
                    scanf("%f", &price);
                    
                    printf("Enter quantity: ");
                    scanf("%d", &quantity);
                    
                    add_menu_item(name, price, quantity);
                }
                break;
            case 3:
                printf("Enter customer name: ");
                fgets(customer_name, MAX_NAME_LENGTH, stdin);
                customer_name[strcspn(customer_name, "\n")] = 0;  // Remove newline
                create_order(customer_name);
                break;
            case 4:
                display_all_orders();
                break;
            case 5:
                printf("Exiting...\n");
                exit(0);
            default:
                printf("Invalid choice! Try again.\n");
        }
    }

    return 0;
}
