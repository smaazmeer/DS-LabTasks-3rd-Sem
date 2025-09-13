#include <iostream>
#include <cstring>
using namespace std;

class Matrix
{
    private:
        int rows;
        int cols;
        int** data;

    public:
        Matrix(int rows, int cols) : rows(rows), cols(cols)
        {
            data = new int*[rows];
            for (int i = 0; i < rows; i++)
            {
                data[i] = new int[cols];
                memset(this->data[i], 0, sizeof(int) * cols);
            }    
        }

        ~Matrix()
        {
            for (int i = 0; i < rows; i++)
            {
                delete [] data[i];
                data[i] = 0;
            }
            delete []data;
            data = 0;
        }

        void Resize(int newRows, int newCols)
        {
            
            int** temp = new int*[newRows];
            for (int i = 0; i < newRows; i++)
            {
                temp[i] = new int[newCols];
                memset(temp[i], 0, sizeof(int)*newCols);
            }
            
            for (int i = 0; i < (rows > newRows? newRows : rows); i++)
            {
                memcpy(temp[i], data[i], sizeof(int)*(cols > newCols? newCols : cols)); 
            }
            
            for (int i = 0; i < rows ; i++)
            {
                delete [] data[i];
            }
            delete [] data;

            this->data = temp;

            rows = newRows;
            cols = newCols;
        }

        void transpose()
        {
            Matrix trans(cols, rows);
            
            for (int i = 0; i < rows; i++)
            {

                for (int j = 0; j < cols; j++)
                {
                    trans.data[j][i] = this->data[i][j];
                }
                
            }

            for (int i = 0; i < rows; i++)
            {
                delete [] data[i];
            }   
            delete [] data;
            
            data = trans.data;
            rows = trans.rows;
            cols = trans.cols;
            trans.data = nullptr;
        }

        void print() //adds 2 to elements at odd index
        {
            for (int i = 0; i < rows; i++)
            {
                for (int j = 0; j < cols; j++)
                {
                    cout << ((j%2 != 0) ? data[i][j] + 2: data[i][j])<< "   " << endl;
                }
                cout << "\n";
            }
            
        }
};
