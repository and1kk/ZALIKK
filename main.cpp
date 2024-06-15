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
        cout << "������, ������� ����� �� 0 �� 2";
        cin >> role;
    }


    if (role == 0) {
        int choose1 = -1;

        while (choose1 != 5) {
            adminMenu();
            cin >> choose1;

            if (choose1 == 5) {
                cout << "�������� �����������";
                break;
            }

            switch (choose1) {
            case 1: {
                Product myProduct;
                inputProduct(myProduct);
                saveProductToFile(filename, myProduct);
                cout << "������� Enter, ����� ����������";

                cin.ignore();
                cin.get();
                break;
            }
            case 2:
            {

                int Id;
                cout << "������� ID ������, ������� �� ������ �������: ";
                cin >> Id;

                delete_structure_by_id(filenam, Id);

                cout << "������� ������� ��� ������ ��� �� ��������� �������� �� ����.";

                cout << "������� Enter, ����� ����������";

                cin.ignore();
                cin.get();

                break;
            }
            case 3:
            {
                cout << "������� id ������ ��� ��������������";
                int productId;
                cin >> productId;

                cout << "������� ����� id";
                int productId1;
                cin >> productId1;

                edit_structure_by_id(filenam, productId, productId1);




                cout << "������� Enter, ����� ����������";

                cin.ignore();
                cin.get();

                break;

            }

            
            case 4:
                products = readProductsFromFile(filename);
                for (const auto& product : products) {
                    printProduct(product);
                }



                cout << "������� Enter, ����� ����������";
                cin.ignore();
                cin.get();
                break;


            case 5:
                cout << "�� ����� �� ��������." << endl;
                break;
            default:
                cout << "������, ������� ����� �� 1 �� 5: ";
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
                cout << "�������� �����������";
                break;
            }

            switch (choose2) {
            case 1:
            {

                int Id;
                cout << "������� ID ������, ������� �� ������ ��������������� : ";
                cin >> Id;

                float price;
                cout << "������� ����� ���� ������";
                cin >> price;

                edit_price_by_id(filenam, Id, price);
                cout << "������� Enter, ����� ����������";
                cin.ignore(); // To wait for Enter
                cin.get();
            }
            break;
            case 2:

            {

                int Id;
                cout << "������� ID ������, ������� �� ������ �������: ";
                cin >> Id;

                delete_structure_by_id(filenam, Id);

                cout << "������� ������� ��� ������ ��� �� ��������� �������� �� ����.";

                cout << "������� Enter, ����� ����������";

                cin.ignore();
                cin.get();

                break;
            }
            case 3:
              
            {

                int id1;
                cout << "������� ID ������, ������� �� ������ ��������������� : ";
                cin >> id1;

                float raiting;
                cout << "������� ����� ������� ������";
                cin >> raiting;

                edit_rating_by_id(filenam, id1, raiting);
                cout << "������� Enter, ����� ����������";
                cin.ignore(); 
                cin.get();
            }
            case 4:
            {
               
                int id;
                cout << "������� ID ������, ������� �� ������ ��������������� : ";
                cin >> id;

              
                cout << "������� ����� ��� ������";
                char new_name[100];
                cin >> new_name;

                edit_name_by_id(filenam, id, new_name);
                cout << "������� Enter, ����� ����������";
                cin.ignore();
                cin.get();
            }
            case 5:
                Product myProduct;
                inputProduct(myProduct);
                saveProductToFile(filename, myProduct);
                cout << "������� Enter, ����� ����������";

                cin.ignore();
                cin.get();
                break;
               
          
            case 6:
            {

                products = readProductsFromFile(filename);
                for (const auto& product : products) {
                    printProduct(product);
                }



                cout << "������� Enter, ����� ����������";
                cin.ignore();
                cin.get();
                break;
               
                
            }
            case 7:
                cout << "�� ����� �� ��������." << endl;
                break;
            default:
                cout << "������, ������� ����� �� 1 �� 7: ";
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
                    cout << "������� Enter, ����� ����������";
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
                    cout << "������� Enter, ����� ����������";
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
                    cout << "������� Enter, ����� ����������";
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
                    cout << "������� Enter, ����� ����������";
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
                    cout << "������� Enter, ����� ����������";
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
                    cout << "������� Enter, ����� ����������";
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



                    cout << "������� Enter, ����� ����������";
                    cin.ignore();
                    cin.get();
                    break;
                }
                break;
                case 8:
                    cout << "�� ����� �� ��������." << endl;
                    break;
                default:
                    while (choose3 > 8 || choose3 < 1) {
                        cout << "������, ������� ����� �� 1 �� 8:";
                        cin >> choose3;
                    }
                    break;
                }
            }
        }




        return 0;
    }
    