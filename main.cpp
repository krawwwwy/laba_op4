#include <iostream>

using namespace std;

void bublesort(int* list[], char* lines[], int length)
{
    while (length--)
    {
        bool swapped = false;
        for (int i = 0; i < length; i ++ ){
            if (list[i][0] > list[i + 1][0]){ //сначала сортирую пузырьком по первому символу строки
                swap(list[i], list[i + 1]);
                swap(lines[i], lines[i + 1]);
                swapped = true;
            } else if (list[i][0] == list[i + 1][0]){ //полноценная сортровка строк
                for (int j = 1; j < 32; j++){
                    if (list[i][j] != list[i + 1][j]){
                        if (list[i][j] > list[i + 1][j] and list[i+1][j] !=0) { //тут я ввел некое правило что для  строк ааа и аааа в рещультате сортировки ааа будет выше
                                swap(list[i], list[i + 1]);
                                swap(lines[i], lines[i + 1]);
                                swapped = true;
                        }
                        break;
                    }
                }
            }
        }
        if (swapped == false){break;}
    }
}

int main()
{
    int size;
    cout<<"Введите кол-во строк: ";
    cin>>size;
    cout<<endl;
    cin.get();
    char** lines = new char*[size]; //выделяем память 1
    int** list = new int*[size]; //выделяем память 2
    for (int i = 0; i < size; i++) {
        lines[i] = new char[32]; //заполняем массив!
        list[i] = new int[32]; //заполняем массив...
    }
    for (int i = 0; i < size; i++) {
        cout<<"Введите "<< i + 1 <<"-ую строку: ";
        cin.getline(lines[i], 32); //считываем строку длиной <=32 символа
        for (int j = 0; j < 33; j++){
            list[i][j] = (int) lines[i][j]; //считываем строку во второй массив
        }
    }
    cout<<endl;
    bublesort(list, lines, size);
    cout<<"Отсортированный текст:"<<endl;
    cout<<endl;
    for (int i = 0; i < size; i++){
        cout<<i + 1<<"-ая строка: "<<lines[i]<<endl;
        delete [] lines[i]; // чистим 1
        delete [] list[i]; // чистим 2
    }
    delete [] lines; // чистим 3
    delete [] list; // чистим 4
    return 0;
}
