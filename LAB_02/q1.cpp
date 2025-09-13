#include <iostream>
#include <cstring>
using namespace std;

class Array
{
    private:
        int* Data;
        int size;
        int index;

    public:
        Array()
        {
            size = 2;
            index = 0;
            Data =  new int[size];
            memset(this->Data, 0, sizeof(int)*size);
        }

        ~Array()
        {
            size = 0;
            delete []Data;
            Data = 0;
        }

        void Resize()
        {
            cout << "\nResizing Array\n";
            int* temp  = new int[size];
            
            for (int i = 0; i < size; i++)
            {
                temp[i] = this->Data[i];
            }
            
            int newSize = size + 2;

            delete []Data;
            Data = new int[newSize];
            memset(this->Data, 0, sizeof(int)*newSize);
            
            for (int i = 0; i < size; i++)
            {
                this->Data[i] = temp[i];
            }
            
            size = newSize;
            delete []temp;
            temp = 0;
        }

        void push_Back(int val)
        {
            if (index < size)
            {
                Data[index++] = val;
            }
            else
            {
                Resize();
                Data[index++] = val;
            }
        }
        
        void printData()
        {
            cout << "\nPrinting Data...\n";
            for (int i = 0; i < size; i++)
            {
                cout << i+1 << ". " << Data[i] << endl;
            }
            
        }
};

int main()
{
    Array Data;
    Data.printData();
    Data.push_Back(5);
    Data.push_Back(9);
    Data.push_Back(6);
    Data.push_Back(3);
    Data.push_Back(1);
    Data.push_Back(64);
    Data.push_Back(7);
    Data.printData();
    return 0;
}