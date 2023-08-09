#include <iostream>
#include <vector>
#include "datamodel.h"
using namespace std;

vector<Product> allProducts = {
    Product(1, "apple", 26),
    Product(3, "mango", 16),
    Product(2, "guava", 36),
    Product(5, "banana", 56),
    Product(4, "strawberry", 29),
    Product(6, "pineapple", 20),
};

Product *chooseProduct()
{
    // display the list of the product
    string productList;
    cout << "Available Products " << endl;

    for (auto product : allProducts)
    {
        productList.append(product.getdisplayName());
    }
    cout << productList << endl;
    cout << "--------------" << endl;
    string choice;
    cin >> choice;

    for (int i = 0; i < allProducts.size(); i++)
    {
        if (allProducts[i].getshortName() == choice)
        {
            return &allProducts[i];
        }
    }
    cout << "Product not found!" << endl;
    return NULL;
}

bool checkout(Cart &cart)
{
    if (cart.isempty())
    {
        return false;
    }
    int total = cart.getTotal();
    cout << " PAY IN CASH ";
    int paid;
    cin >> paid;
    if (paid >= total)
    {
        cout << " change " << paid - total << endl;
        cout << " thank you for shopping! ";
        return true;
    }
    else
    {
        cout << " NOT ENOUGH CASH! ";
        return false;
    }
}

int main()
{
    char action;
    Cart cart;
    while (true)
    {
        cout << "select an action - (a)dd item, (v)iew cart, (c)heckout" << endl;
        cin >> action;

        if (action == 'a')
        {
            // Todo: add to cart
            // View all product + choose product + add to the cart
            Product *product = chooseProduct();
            if (product != NULL)
            {
                cout << "Added to the cart " << product->getdisplayName() << endl;
                cart.addProduct(*product);
            }
        }
        else if(action =='v')
        // view cart
        {
            cout << "----------------" << endl;
            cout << cart.viewcart();
            cout << "-------------" << endl;
        }
        else
        {
            // checkout
            cart.viewcart();
            if (checkout(cart))
            {
                break;
            }
        }
    }
    return 0;
}
