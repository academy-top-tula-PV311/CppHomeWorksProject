#include <iostream>

void ArrayInit(int array[], int size);
void ArrayPrint(int array[], int size);

void ArrayShiftRight(int array[], int size, int steps);

void MaxSubArray(int array[], int size);

void ArraySubReverce(int array[], int size, int begin, int end);
void ArraySubReverceBegin(int array[], int size, int end);
void ArraySubReverceEnd(int array[], int size, int begin);

void ArraySortCacke(int array[], int size);


int ArrayMaxIndex(int array[], int size);
int ArrayMaxIndexEnd(int array[], int size, int begin);
int ArrayMaxIndexBegin(int array[], int size, int end);


void RangeMods(int a, int b, int c, int d);


int main()
{
    srand(time(nullptr));

    const int size{ 5 };
    int array[2 * size];

    ArrayInit(array, 2 * size);
    ArrayPrint(array, 2 * size);

    //ArrayShiftRight(array, 2 * size, 3);
    //ArraySubReverce(array, 2 * size, 3, 7);
    ArraySortCacke(array, 2 * size);

    ArrayPrint(array, 2 * size);
    
}

void ArrayInit(int array[], int size)
{
    for (int i{}; i < size; i++)
        array[i] = rand() % 100;
}

void ArrayPrint(int array[], int size)
{
    for (int i{}; i < size; i++)
        std::cout << array[i] << " ";
    std::cout << "\n";
}

void ArrayShiftRight(int array[], int size, int steps)
{
    steps %= size;

    for (int s{}; s < steps; s++)
    {
        int temp{ array[size - 1] };
        for (int i{ size - 1 }; i > 0; i--)
            array[i] = array[i - 1];
        array[0] = temp;
    }
    
}

void MaxSubArray(int array[], int size)
{
    int amountMax{};
    int indexMax{};
    for (int i{}; i < size; i++)
        amountMax += array[i];
    std::cout << "index: 0 amount: " << amountMax << "\n";

    int amount = amountMax;
    for (int i{ 1 }; i < size; i++)
    {
        amount = amount - array[i - 1] + array[i + size - 1];
        if (amount > amountMax)
        {
            amountMax = amount;
            indexMax = i;
        }
        std::cout << "index: " << i << " amount: " << amount << "\n";
    }
    std::cout << "\nindex Max: " << indexMax << " amount Max: " << amountMax << "\n";
}

void ArraySubReverce(int array[], int size, int begin, int end)
{
    int temp;
    while (begin < end)
    {
        temp = array[begin];
        array[begin] = array[end];
        array[end] = temp;
        begin++;
        end--;
    }
}

void ArraySubReverceBegin(int array[], int size, int end)
{
    ArraySubReverce(array, size, 0, end);
}

void ArraySubReverceEnd(int array[], int size, int begin)
{
    ArraySubReverce(array, size, begin, size - 1);
}

void ArraySortCacke(int array[], int size)
{
    //for (int i{}; i < size - 1; i++)
    for (int i{ size - 1 }; i > 0; i--)
    {
        //int index = ArrayMaxIndexEnd(array, size, i);
        int index = ArrayMaxIndexBegin(array, size, i);
        ArraySubReverceBegin(array, size, index);
        ArraySubReverceBegin(array, size, i);
    }
}

int ArrayMaxIndex(int array[], int size)
{
    int index{};

    for (int i{ 1 }; i < size; i++)
        if (array[index] < array[i])
            index = i;

    return index;
}

int ArrayMaxIndexEnd(int array[], int size, int begin)
{
    int index{ begin };

    for (int i{ index + 1 }; i < size; i++)
        if (array[index] < array[i])
            index = i;

    return index;
}

int ArrayMaxIndexBegin(int array[], int size, int end)
{
    int index{};

    for (int i{ 1 }; i <= end; i++)
        if (array[index] < array[i])
            index = i;

    return index;
}

void RangeMods(int a, int b, int c, int d)
{
    for (int i{ a }; i <= b; i++)
        if (i % c == d)
            std::cout << i << " ";
}
