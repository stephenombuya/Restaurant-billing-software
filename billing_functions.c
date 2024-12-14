#include <stdio.h>
#include <string.h>
#include "data_structures.h"

extern Restaurant restaurant;

float calculate_total_bill(Order* order) {
    float total = 0;
    for (int i = 0; i < order->item_count; i++) {
        total += order->items[i].total_price;
    }
    
    // Apply tax
    order->tax_rate = 0.10;  // 10% tax
    total *= (1 + order->tax_rate);
    
    // Apply potential discount
    order->discount = (total > 1000) ? (total * 0.05) : 0;
    total -= order->discount;

    return total;
}

void create_order(char* customer_name) {
    if (restaurant.order_count >= MAX_ORDERS) {
        printf("Maximum order limit reached!\n");
        return;
    }

    Order new_order = {0};
    new_order.order_id = restaurant.order_count + 1;
    strncpy(new_order.customer_name, customer_name, MAX_NAME_LENGTH - 1);

    int continue_ordering = 1;
    while (continue_ordering) {
        display_menu();
        printf("Enter item ID to add (0 to finish): ");
        int item_id;
        scanf("%d", &item_id);

        if (item_id == 0) break;

        int menu_index = find_menu_item_by_id(item_id);
        if (menu_index == -1) {
            printf("Invalid item ID!\n");
            continue;
        }

        printf("Enter quantity: ");
        int quantity;
        scanf("%d", &quantity);

        if (quantity > restaurant.menu[menu_index].available_quantity) {
            printf("Not enough stock!\n");
            continue;
        }

        OrderItem order_item = {
            restaurant.menu[menu_index],
            quantity,
            restaurant.menu[menu_index].price * quantity
        };

        new_order.items[new_order.item_count++] = order_item;
        restaurant.menu[menu_index].available_quantity -= quantity;

        printf("Add another item? (1/0): ");
        scanf("%d", &continue_ordering);
    }

    new_order.total_bill = calculate_total_bill(&new_order);
    restaurant.orders[restaurant.order_count++] = new_order;
}

void print_bill(Order* order) {
    printf("\n===== BILL =====\n");
    printf("Order ID: %d\n", order->order_id);
    printf("Customer: %s\n", order->customer_name);
    printf("-------------------\n");
    
    for (int i = 0; i < order->item_count; i++) {
        printf("%s x %d: ₹%.2f\n", 
               order->items[i].item.name, 
               order->items[i].quantity, 
               order->items[i].total_price);
    }
    
    printf("-------------------\n");
    printf("Subtotal: ₹%.2f\n", order->total_bill / (1 + order->tax_rate));
    printf("Tax (%.0f%%): ₹%.2f\n", order->tax_rate * 100, order->total_bill * order->tax_rate);
    printf("Discount: ₹%.2f\n", order->discount);
    printf("Total: ₹%.2f\n", order->total_bill);
}

void display_all_orders() {
    for (int i = 0; i < restaurant.order_count; i++) {
        print_bill(&restaurant.orders[i]);
    }
}
