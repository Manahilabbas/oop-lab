/*Implement a restaurant ordering system that holds information about the restaurant’s menus, menu
items, orders, and payments. Identify the relationship between the five entities mentioned. Keep in
mind the following information as well:
a) Menu Items hold two things: food name and food price.
b) Menu is a class that holds an array of menu items. You can have different functions to add and
remove items, or display the entire menu.
c) Restaurant ordering system has one menu.
d) Any staff member can place an order to the system on behalf of a customer. Theorder class
consists of one or more menu items and a payment.
e) Payment is a class that holds the amount of money that a customer needs to pay.This is
generated when the order is placed.*/
#include <iostream>
using namespace std;

class Menu {
    string* items;
    double* prices;
    int itemsnum;

public:
    Menu(int itemNum = 0, double* pricesArr = nullptr, string* itemsArr = nullptr)
        : itemsnum(itemNum) {
        items = new string[itemsnum];
        prices = new double[itemsnum];
        if (pricesArr && itemsArr) {
            for (int i = 0; i < itemsnum; i++) {
                items[i] = itemsArr[i];
                prices[i] = pricesArr[i];
            }
        }
    }

    ~Menu() {
        delete[] items;
        delete[] prices;
    }

    void display_menu() {
        for (int i = 0; i < itemsnum; i++) {
            cout << i + 1 << ". " << items[i] << " : " << prices[i] << endl;
        }
    }
};

class Payment {
    double amount;

public:
    Payment(double amt) : amount(amt) {}

    void processPayment() {
        cout << "Payment of $" << amount << " processed." << endl;
    }
};

class Order {
    string* orderedItems;
    double* orderedPrices;
    int itemCount;
    double totalAmount;

public:
    Order(int count = 0) : itemCount(count), totalAmount(0) {
        orderedItems = new string[itemCount];
        orderedPrices = new double[itemCount];
    }

    ~Order() {
        delete[] orderedItems;
        delete[] orderedPrices;
    }

    void addItem(string item, double price, int index) {
        if (index < itemCount) {
            orderedItems[index] = item;
            orderedPrices[index] = price;
            totalAmount += price;
        }
    }

    void displayOrder() {
        cout << "\nOrder Summary:" << endl;
        for (int i = 0; i < itemCount; i++) {
            cout << orderedItems[i] << " - $" << orderedPrices[i] << endl;
        }
        cout << "Total: $" << totalAmount << endl;
    }

    void makePayment() {
        Payment payment(totalAmount);
        payment.processPayment();
    }
};

int main() {
    string foodItems[] = {"Burger", "Pizza", "Pasta"};
    double foodPrices[] = {5.99, 8.49, 7.99};
    Menu restaurantMenu(3, foodPrices, foodItems);
    restaurantMenu.display_menu();

    Order myOrder(2);
    myOrder.addItem("Burger", 5.99, 0);
    myOrder.addItem("Pasta", 7.99, 1);
    myOrder.displayOrder();
    myOrder.makePayment();

    return 0;
}
