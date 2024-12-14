#include <stdio.h>
#include <string.h>
#include "data_structures.h"

extern Restaurant restaurant;

void init_menu() {
    // Initialize some default menu items
    restaurant.menu[0] = (MenuItem){1, "Pizza", 250.0, 50};
    restaurant.menu[1] = (MenuItem){2, "Burger", 150.0, 75};
    restaurant.menu[2] = (MenuItem){3, "Pasta", 200.0, 40};
    restaurant.menu[3] = (MenuItem){4, "Salad", 100.0, 60};
    restaurant.menu[4] = (MenuItem){5, "Soft Drink", 50.0, 100};

    restaurant.menu_item_count = 5;
}

void display_menu() {
    printf("\n===== RESTAURANT MENU =====\n");
    for (int i = 0; i < restaurant.menu_item_count; i++) {
        printf("%d. %s - ₹%.2f (Available: %d)\n", 
               restaurant.menu[i].item_id, 
               restaurant.menu[i].name, 
               restaurant.menu[i].price,
               restaurant.menu[i].available_quantity);
    }
    printf("===========================\n");
}

int find_menu_item_by_id(int item_id) {
    for (int i = 0; i < restaurant.menu_item_count; i++) {
        if (restaurant.menu[i].item_id == item_id) {
            return i;
        }
    }
    return -1;
}

void add_menu_item(char* name, float price, int quantity) {
    if (restaurant.menu_item_count >= MAX_ITEMS) {
        printf("Menu is full. Cannot add more items.\n");
        return;
    }

    MenuItem new_item = {
        restaurant.menu_item_count + 1,
        "",
        price,
        quantity
    };
    
    strncpy(new_item.name, name, MAX_NAME_LENGTH - 1);
    restaurant.menu[restaurant.menu_item_count++] = new_item;
    printf("Item '%s' added successfully!\n", name);
}
