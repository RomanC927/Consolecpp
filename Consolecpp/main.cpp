#include "Todolist.h"
#include <iostream>
using namespace std;
int main() {
    setlocale(LC_ALL, "RU");
    Todolist listic;
    int c;
    listic.file("tasks.txt");
    while (true) {
        cout << endl << "TODO LIST" << endl;
        cout << "1. Добавить задачу" << endl;
        cout << "2. Показать все задачи" << endl;
        cout << "3. Выполнить задачу" << endl;
        cout << "4. Удалить задачу" << endl;
        cout << "5. Сохранить" << endl;
        cout << "6. Загрузить" << endl;
        cout << "0. Выход" << endl;
        cout << "Выбор: ";
        cin >> c;
        if (cin.fail()) {
            cin.clear();
            cin.ignore(1000, '\n'); 
            cout << "Введите число!" << endl;
            continue;
        }
        switch (c) {
        case 1: {
            string t, d;
            cout << "Название: ";
            cin.ignore(1000, '\n'); 
            getline(cin, t);
            cout << "Описание: ";
            getline(cin, d);
            listic.addtask(t, d);
            break;
        }
        case 2:
            listic.show();
            break;
        case 3: {
            int index;
            cout << "Номер задачи: ";
            cin >> index;
            listic.complete(index - 1);
            break;
        }
        case 4: {
            int index;
            cout << "Номер задачи: ";
            cin >> index;
            listic.remove(index - 1);
            break;
        }
        case 5:
            listic.save("tasks.txt");
            break;
        case 6:
            listic.file("tasks.txt");
            break;
        case 0:
            listic.save("tasks.txt");
            cout << "До свидания!" << endl;
            return 0;
        default:
            cout << "Неверный выбор" << endl;
        }
    }
}