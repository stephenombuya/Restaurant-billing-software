#ifndef DATA_STRUCTURES_H
#define DATA_STRUCTURES_H

#define MAX_ITEMS 100
#define MAX_NAME_LENGTH 50
#define MAX_ORDERS 50

// Structure for menu items
typedef struct {
    int item_id;
    char name[MAX_NAME_LENGTH];
    float price;
    int available_quantity;
} MenuItem;

// Structure for order items
typedef struct {
    MenuItem item;
    int quantity;
    float total_price;
} OrderItem;

// Structure for complete order
typedef struct {
    int order_id;
    OrderItem items[MAX_ITEMS];
    int item_count;
    float total_bill;
    float tax_rate;
    float discount;
    char customer_name[MAX_NAME_LENGTH];
} Order;

// Structure for restaurant management
typedef struct {
    MenuItem menu[MAX_ITEMS];
    int menu_item_count;
    Order orders[MAX_ORDERS];
    int order_count;
} Restaurant;

#endif // DATA_STRUCTURES_H
