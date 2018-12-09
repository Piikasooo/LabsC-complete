#include <iostream>
#include <stdexcept>

using namespace std;

class ShopItemOrder{
    private:
        string name;
        float unitPrice;
        int amount;
    public:
        ShopItemOrder(string name, float unitPrice, int amount)
        {
            if(name.empty())
                throw invalid_argument("Name can't be empty");
            if(unitPrice <= 0)
                throw invalid_argument("Price can't be <= 0");
            if(amount <= 0)
                throw invalid_argument("Amount can't be <= 0");

            this->name = name;
            this->unitPrice = unitPrice;
            this->amount = amount;
        }
        string GetName()
        {
            return name;
        }
        void SetName(string name)
        {
            if(name.empty())
                throw invalid_argument("Name can't be empty");
            this->name = name;
        }
        float GetUnitPrice()
        {
            return unitPrice;
        }
        void SetUnitPrice(float price)
        {
            if(price <= 0)
                throw invalid_argument("Price can't be <= 0");
            unitPrice = price;
        }
        int GetAmount()
        {
            return amount;
        }
        void SetAmount(int amount)
        {
            if(amount <= 0)
                throw invalid_argument("Amount can't be <= 0");
            this->amount = amount;
        }
        float GetTotalPrice()
        {
            return unitPrice * amount;
        }
        void PringShopItemOrder()
        {
            cout << "Order for " << name << " item, which cost " << unitPrice << "$ and has " << amount << " units." << endl;
        }
};

int main()
{
    ShopItemOrder item1("Item1", 10.50, 5);

    item1.PringShopItemOrder();
    cout << "Total price is " << item1.GetTotalPrice() << "$" << endl << endl;

    item1.SetAmount(4);
    item1.PringShopItemOrder();
    cout << "Total price is " << item1.GetTotalPrice() << "$" << endl << endl;

    item1.SetUnitPrice(9.99);
    cout << "Price of " << item1.GetName() << " is " << item1.GetUnitPrice() << "$" << endl;
    cout << "Total price is " << item1.GetTotalPrice() << "$" << endl;

    return 0;
}
