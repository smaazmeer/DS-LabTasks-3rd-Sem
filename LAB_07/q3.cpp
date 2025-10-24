#include <iostream>
using namespace std;

class Product
{
    private:
        string name;
        double price;
        string description;
        bool available;

    public:
        Product() {}

        Product(string n, double p, string d, bool a)
        {
            name = n;
            price = p;
            description = d;
            available = a;
        }

        void input()
        {
            cout << "Enter product name: ";
            cin >> name;
            cout << "Enter product price: ";
            cin >> price;
            cout << "Enter product description: ";
            cin >> description;
            cout << "Is product available? (1 for Yes / 0 for No): ";
            cin >> available;
        }

        double getPrice() const
        {
            return price;
        }

        string getName() const
        {
            return name;
        }

        string getDescription() const
        {
            return description;
        }

        bool isAvailable() const
        {
            return available;
        }

        void display() const
        {
            cout << "Name: " << name << endl;
            cout << "Price: $" << price << endl;
            cout << "Description: " << description << endl;
            cout << "Available: " << (available ? "Yes" : "No") << endl;
            cout << "-----------------------------------" << endl;
        }
};

int partitionFunc(Product arr[], int left, int right, double pivot)
{
    int leftPointer = left;
    int rightPointer = right - 1;

    while (true)
    {
        while (arr[++leftPointer].getPrice() < pivot) {}
        while (rightPointer > 0 && arr[--rightPointer].getPrice() > pivot) {}

        if (leftPointer >= rightPointer)
        {
            break;
        }
        else
        {
            Product temp = arr[leftPointer];
            arr[leftPointer] = arr[rightPointer];
            arr[rightPointer] = temp;
        }
    }

    Product temp = arr[leftPointer];
    arr[leftPointer] = arr[right];
    arr[right] = temp;

    return leftPointer;
}

void quickSort(Product arr[], int left, int right)
{
    if (left >= right)
        return;

    double pivot = arr[right].getPrice();
    int partitionIndex = partitionFunc(arr, left, right, pivot);

    quickSort(arr, left, partitionIndex - 1);
    quickSort(arr, partitionIndex + 1, right);
}

int main()
{
    const int size = 3;
    Product products[size];

    cout << "Enter details for 3 products:\n";
    cout << "-----------------------------------" << endl;

    for (int i = 0; i < size; i++)
    {
        cout << "\nProduct " << i + 1 << ":\n";
        products[i].input();
    }

    quickSort(products, 0, size - 1);

    cout << "\nProducts sorted by price:\n";
    cout << "===================================\n";

    for (int i = 0; i < size; i++)
    {
        products[i].display();
    }

    return 0;
}
