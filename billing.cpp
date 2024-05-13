#include <iostream>
#include <vector>
#include <string>

using namespace std;

class Product {
private:
    string name;
    double price;
    int quantity;

public:
    Product(string n, double p) : name(n), price(p), quantity(0) {}

    void setQuantity(int q) {
        quantity = q;
    }

    double getTotalPrice() const {
        return price * quantity;
    }

    void display() const {
        cout << name << "\t\tRs" << price << "\t\t" << quantity << "\t\tRs" << getTotalPrice() << endl;
    }
};

class ShoppingCart {
private:
    vector<Product> products;

public:
    void addProduct(const Product &product) {
        products.push_back(product);
    }

    void display() const {
        cout << "Product\t\tPrice\t\tQuantity\tTotal" << endl;
        cout << "----------------------------------------------" << endl;
        for (const auto &product : products) {
            product.display();
        }
    }

    double calculateTotal() const {
        double total = 0.0;
        for (const auto &product : products) {
            total += product.getTotalPrice();
        }
        return total;
    }
};

int main() {
    ShoppingCart cart;

    Product p1("Bread", 25);
    Product p2("Milk", 30);
    Product p3("Eggs", 10);

    int quantity;

    cout << "Enter quantity for Bread: ";
    cin >> quantity;
    p1.setQuantity(quantity);

    cout << "Enter quantity for Milk: ";
    cin >> quantity;
    p2.setQuantity(quantity);

    cout << "Enter quantity for Eggs: ";
    cin >> quantity;
    p3.setQuantity(quantity);

    cart.addProduct(p1);
    cart.addProduct(p2);
    cart.addProduct(p3);

    cout << "Items in the Shopping Cart:" << endl;
    cart.display();

    cout << "\nTotal Bill Amount: Rs" << cart.calculateTotal() << endl;

    return 0;
}
