#include <string>
#include <unordered_map>
using namespace std;
// forward declaration
class Item;
class Cart;
class Product
{
    int id;
    string name;
    int price;

public:
    Product()
    {
    }
    Product(int u_id, string name, int price)
    {
        id = u_id;
        this->name = name;
        this->price = price;
    }
    string getdisplayName()
    {
        return name + " : RS " + to_string(price) + "\n";
    }
    string getshortName()
    {
        return name.substr(0, 1);
    }
    friend class Item;
    friend class Cart;
};
class Item
{

    Product product;
    int quantity;

public:
    // constructor using initialization list
    Item()
    {
    }
    Item(Product p, int q) : product(p), quantity(q) {}

    int getItemprice()
    {
        return quantity * product.price;
    }

    string getIteminfo()
    {
        return to_string(quantity) + " x " + product.name  +  " RS. "  +  to_string(quantity * product.price)+ "\n";
    }
    friend class Cart;
};

class Cart
{
    unordered_map<int, Item> items;

public:
    void addProduct(Product product)
    {
        if (items.count(product.id) == 0)
        {
            Item newItem(product, 1);
            items[product.id] = newItem;
        }
        else
        {
            items[product.id].quantity += 1;
        }
    }
    int getTotal()
    {
        // todo
        int total = 0;
        for (auto itempair : items)
        {
            auto item = itempair.second;
            total += item.getItemprice();
        }
        return total;
    }
    string viewcart()
    {
        if (items.empty())
        {
            return "cart is empty";
        }
        string itemizedlist;
        int cart_total = getTotal();

        for (auto itemPair : items)
        {
            auto item = itemPair.second;
            itemizedlist.append(item.getIteminfo());
        }
        return itemizedlist + "  \n  Total amount : RS." + to_string(cart_total) + '\n';
    }
    // to later use
    bool isempty()
    {
        return items.empty();
    }
};