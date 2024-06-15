#include "Header1.h"
#include <vector>

using namespace std;
int main() {
   
     const string  filename = "products.txt";
     const char* filenam = "products.txt";


     vector<Product> products = readProductsFromFile(filename);
  
    setlocale(0, "");
    int role;
    menu();
    cin >> role;
    if (role > 2 || role < 0) {
        cout << "Ошибка, введите число от 0 до 2";
        cin >> role;
    }


    if (role == 0) {
        int choose1 = -1;

        while (choose1 != 5) {
            adminMenu();
            cin >> choose1;

            if (choose1 == 5) {
                cout << "Програма остановлена";
                break;
            }

            switch (choose1) {
            case 1: {
                Product myProduct;
                inputProduct(myProduct);
                saveProductToFile(filename, myProduct);
                cout << "Нажмите Enter, чтобы продолжить";

                cin.ignore();
                cin.get();
                break;
            }
            case 2:
            {

                int Id;
                cout << "Введите ID товара, который вы хотите удалить: ";
                cin >> Id;

                delete_structure_by_id(filenam, Id);

                cout << "Нажмите вывести все товары что бы проверить удалился ли файл.";

                cout << "Нажмите Enter, чтобы продолжить";

                cin.ignore();
                cin.get();

                break;
            }
            case 3:
            {
                cout << "Введите id товара для редактирывания";
                int productId;
                cin >> productId;

                cout << "Введите новое id";
                int productId1;
                cin >> productId1;

                edit_structure_by_id(filenam, productId, productId1);




                cout << "Нажмите Enter, чтобы продолжить";

                cin.ignore();
                cin.get();

                break;

            }

            
            case 4:
                products = readProductsFromFile(filename);
                for (const auto& product : products) {
                    printProduct(product);
                }



                cout << "Нажмите Enter, чтобы продолжить";
                cin.ignore();
                cin.get();
                break;


            case 5:
                cout << "Вы вышли из програмы." << endl;
                break;
            default:
                cout << "Ошибка, введите число от 1 до 5: ";
                while (choose1 < 1 || choose1 > 5) {
                    cin >> choose1;
                }
                break;
            }
        }
    }



    if (role == 1) {
        int choose2 = -1;

        while (choose2 != 7) {
            sellerMenu();
            cin >> choose2;
            if (choose2 == 7 ) {
                cout << "Програма остановлена";
                break;
            }

            switch (choose2) {
            case 1:
            {

                int Id;
                cout << "Введите ID товара, который вы хотите отредактирывать : ";
                cin >> Id;

                float price;
                cout << "Введите новую цену товара";
                cin >> price;

                edit_price_by_id(filenam, Id, price);
                cout << "Нажмите Enter, чтобы продолжить";
                cin.ignore(); // To wait for Enter
                cin.get();
            }
            break;
            case 2:

            {

                int Id;
                cout << "Введите ID товара, который вы хотите удалить: ";
                cin >> Id;

                delete_structure_by_id(filenam, Id);

                cout << "Нажмите вывести все товары что бы проверить удалился ли файл.";

                cout << "Нажмите Enter, чтобы продолжить";

                cin.ignore();
                cin.get();

                break;
            }
            case 3:
              
            {

                int id1;
                cout << "Введите ID товара, который вы хотите отредактирывать : ";
                cin >> id1;

                float raiting;
                cout << "Введите новый рейтинг товара";
                cin >> raiting;

                edit_rating_by_id(filenam, id1, raiting);
                cout << "Нажмите Enter, чтобы продолжить";
                cin.ignore(); 
                cin.get();
            }
            case 4:
            {
               
                int id;
                cout << "Введите ID товара, который вы хотите отредактирывать : ";
                cin >> id;

              
                cout << "Введите новое имя товара";
                char new_name[100];
                cin >> new_name;

                edit_name_by_id(filenam, id, new_name);
                cout << "Нажмите Enter, чтобы продолжить";
                cin.ignore();
                cin.get();
            }
            case 5:
                Product myProduct;
                inputProduct(myProduct);
                saveProductToFile(filename, myProduct);
                cout << "Нажмите Enter, чтобы продолжить";

                cin.ignore();
                cin.get();
                break;
               
          
            case 6:
            {

                products = readProductsFromFile(filename);
                for (const auto& product : products) {
                    printProduct(product);
                }



                cout << "Нажмите Enter, чтобы продолжить";
                cin.ignore();
                cin.get();
                break;
               
                
            }
            case 7:
                cout << "Вы вышли из програмы." << endl;
                break;
            default:
                cout << "Ошибка, введите число от 1 до 7: ";
                while (choose2 < 1 || choose2 > 7) {
                    cin >> choose2;
                }
                break;
            }
        }
    }
    





        if (role == 2) {
            int choose3 = -1;
            while (choose3 != 8) {
                buyerMenu();
                cin >> choose3;
                switch (choose3)
                {
                case 1:
                {

                    bubbleSortMIN(products);

                    for (const auto& product : products) {
                        printProduct(product);
                    }
                    cout << "Нажмите Enter, чтобы продолжить";
                    cin.ignore();
                    cin.get();
                }
                break;
                case 2:
                {
                    bubbleSortMAX(products);

                    for (const auto& product : products) {
                        printProduct(product);
                    }
                    cout << "Нажмите Enter, чтобы продолжить";
                    cin.ignore();
                    cin.get();
                }
                break;
                case 3:
                {
                    bubbleSortMINR(products);

                    for (const auto& product : products) {
                        printProduct(product);
                    }
                    cout << "Нажмите Enter, чтобы продолжить";
                    cin.ignore();
                    cin.get();
                }
                break;
                case 4:
                {
                    bubbleSortMAXR(products);

                    for (const auto& product : products) {
                        printProduct(product);
                    }
                    cout << "Нажмите Enter, чтобы продолжить";
                    cin.ignore();
                    cin.get();
                }
                break;
                case 5:
                {
                    bubbleSortMAXscreen(products);
                    for (const auto& product : products) {
                        printProduct(product);
                    }
                    cout << "Нажмите Enter, чтобы продолжить";
                    cin.ignore();
                    cin.get();
                }
                break;
                case 6:
                {
                    bubbleSortMAXfreq(products);
                    for (const auto& product : products) {
                        printProduct(product);
                    }
                    cout << "Нажмите Enter, чтобы продолжить";
                    cin.ignore();
                    cin.get();
                }
                break;
                case 7:
                {

                    products = readProductsFromFile(filename);
                    for (const auto& product : products) {
                        printProduct(product);
                    }



                    cout << "Нажмите Enter, чтобы продолжить";
                    cin.ignore();
                    cin.get();
                    break;
                }
                break;
                case 8:
                    cout << "Вы вышли из програмы." << endl;
                    break;
                default:
                    while (choose3 > 8 || choose3 < 1) {
                        cout << "Ошибка, введите число от 1 до 8:";
                        cin >> choose3;
                    }
                    break;
                }
            }
        }




        return 0;
    }
    