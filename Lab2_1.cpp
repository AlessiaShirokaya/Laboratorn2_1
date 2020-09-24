#include <iostream>
using namespace std;

class Matrix
{
private:
    int** _matrix;
    int rows, cols;

public:
    Matrix(int** matr = {}, int rowCount = 0, int colCount = 0) : // ��������� � �����������
        _matrix(matr), rows(rowCount), cols(colCount)
    {

    }

    Matrix(const Matrix& obj) : _matrix(obj._matrix), rows(obj.rows), cols(obj.cols) // ��������� �����������
    {

    }

    ~Matrix()  // ����������
    {
        delete[] _matrix;
    }

    Matrix* Multiply(Matrix m) // ������� ��������� ������
    {
        int** result = new int* [rows];
        for (int i = 0; i < rows; i++)
        {
            result[i] = new int[rows];
        }

        for (int i = 0; i < rows; i++)
        {
            for (int j = 0; j < rows; j++)
            {
                result[i][j] = 0;
                for (int k = 0; k < rows; k++)
                {
                    result[i][j] += _matrix[i][k] * m._matrix[k][j];
                }
            }
        }

        return new Matrix(result, rows, rows); //������� �������� ������
    }

    Matrix* Add(Matrix* m)
    {
        int** result = new int* [rows];
        for (int i = 0; i < rows; i++)
        {
            result[i] = new int[cols];
        }

        for (int i = 0; i < rows; i++)
        {
            for (int j = 0; j < cols; j++)
            {
                result[i][j] = _matrix[i][j] + m->_matrix[i][j];
            }
        }

        return new Matrix(result, rows, cols);
    }

    void Print()
    {
        cout << endl << "������:" << endl;
        for (int r = 0; r < rows; r++)
        {
            for (int c = 0; c < cols; c++)
            {
                auto temp = _matrix[r][c];
                cout << temp << " ";
            }
            cout << endl;
        }
    }
};

//������� ������ ������� �� �����
void PrintMatr(int** matr, int* rowCount, int* colCount)
{
    cout << endl << "������:" << endl;
    for (int r = 0; r < *rowCount; r++)
    {
        for (int c = 0; c < *colCount; c++)
        {
            auto temp = matr[r][c];
            cout << temp << " ";
        }
        cout << endl;
    }
}

int main()
{
  
    setlocale(LC_ALL, "Russian");
    
    //��������� ������ ��� ���������
    int* colCount = new int(0);
    int* rowCount = new int(0);

    //���� �������� �������
     cout << "������� ���-�� ����� �������:" << endl;
     cin >> *rowCount;
     cout << "������� ���-�� �������� �������:" << endl;
     cin >> *colCount;

    //��������� ������ �� ��������� �� ������ ����������
    int** arr = new int* [*rowCount];
    //��������� ������ ��� ������ ��������� �� ������ � ������� ����������
    for (int i = 0; i < *rowCount; i++)
    {
        arr[i] = new int[*colCount];
    }

    //���� ����� ������� ����� �������
    for (int r = 0; r < *rowCount; r++)
    {
        cout << "������ " << r + 1 << ":" << endl;
        for (int c = 0; c < *colCount; c++)
        {
            cin >> arr[r][c];
        }
    }

    //����� ��������� �������
    PrintMatr(arr, rowCount, colCount);

    //��������� ������ ��� ���������
    int* col2Count = new int(0);
    int* row2Count = new int(0);

    //���� �������� �������
    cout << "������� ���-�� ����� �������:" << endl;
    cin >> *row2Count;
    cout << "������� ���-�� �������� �������:" << endl;
    cin >> *col2Count;

    //��������� ������ �� ��������� �� ������ ����������
    int** arr2 = new int* [*row2Count];
    //��������� ������ ��� ������ ��������� �� ������ � ������� ����������
    for (int i = 0; i < *row2Count; i++)
    {
        arr2[i] = new int[*col2Count];
    }

    //���� ����� ������� ����� ������� ����� ������
    for (int r = 0; r < *row2Count; r++)
    {
        cout << "������ " << r + 1 << ":" << endl;
        for (int c = 0; c < *col2Count; c++)
        {
            cin >> arr2[r][c];
        }
    }

    // �������� ������
    PrintMatr(arr2, row2Count, col2Count);

    Matrix* m1 = new Matrix(arr, *rowCount, *colCount);
    Matrix* m2 = new Matrix(arr2, *row2Count, *col2Count);

    Matrix* res = new Matrix();

    if (*rowCount == *row2Count && *colCount == *col2Count)
    {
        cout << "��������: " << endl;
        res = m1->Add(m2);
        res->Print();
        delete res;
    }
    else
    {
        cout << "������� �� �������� ��� ��������" << endl;
    }

    if (*rowCount == *col2Count && *colCount == *row2Count)
    {
        cout << "���������: " << endl;
        res = m1->Multiply(*m2);
        res->Print();
        delete res;
    }
    else
    {
        cout << "������� �� �������� ��� ������������" << endl;
    }
}