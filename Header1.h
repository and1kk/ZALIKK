#include <iostream>
#include <cstring>
#include <cstdlib>
#include <cstring>
#include <fstream>
#include <sstream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

struct Product {
    int id;
    char name[100];
    char category[100];
    float price;
    char description[255];
    float rating;
    char processor[100];
    int screenFreq;
    char gpu[100];
    float screenSize;
};

void clearScreen() {
#ifdef _WIN32
    system("cls");
#else
    system("clear");
#endif
}

void menu() {
    setlocale(0, "");
    cout << "-----------------------------------------\n";
    cout << "|             ДОБРО ПОЖАЛОВАТЬ            |\n";
    cout << "-----------------------------------------\n";
    cout << "|           Выберите роль               |\n";
    cout << "-----------------------------------------\n";
    cout << "|            0. Администратор           |\n";
    cout << "|            1. Продавец                |\n";
    cout << "|            2. Покупатель              |\n";
    cout << "-----------------------------------------\n";
    cout << "| Пожалуйста, введите ваш выбор (0, 1, 2): | \n";
    cout << "-----------------------------------------\n";
}

void adminMenu() {
    clearScreen();
    cout << "\n";
    cout << "---------------------------------------\n";
    cout << "|             МЕНЮ АДМИНИСТРАТОРА      |\n";
    cout << "---------------------------------------\n";
    cout << "| 1. Добавить товар                   |\n";
    cout << "| 2. Удалить товар                    |\n";
    cout << "| 3. Редактировать ID товара          |\n";
    cout << "| 4. Вывести все товары               |\n";
    cout << "| 5. Выход                            |\n";
    cout << "---------------------------------------\n";
    cout << "| Введите ваш выбор (1-5):            |\n";
    cout << "---------------------------------------\n";
}

void sellerMenu() {
    clearScreen();
    cout << "---------------------------------------\n";
    cout << "|                МЕНЮ                 |\n";
    cout << "---------------------------------------\n";
    cout << "| 1. Редактирование цены              |\n";
    cout << "| 2. Удаление товара                  |\n";
    cout << "| 3. Изменение рейтинга товара        |\n";
    cout << "| 4. Изменение названия товара        |\n";
    cout << "| 5. Добовления товара                |\n";
    cout << "| 6. Вывести все товары               |\n";
    cout << "| 7. Выход                           |\n";
    cout << "---------------------------------------\n";
    cout << "| Введите ваш выбор (1-7):            |\n";
    cout << "---------------------------------------\n";
}

void buyerMenu() {
    clearScreen();
    cout << "---------------------------------------\n";
    cout << "|                МЕНЮ                 |\n";
    cout << "---------------------------------------\n";
    cout << "| 1. Сортировать за ценой (мин)       |\n";
    cout << "| 2. Сортировать за ценой (макс)      |\n";
    cout << "| 3. Сортировать за рейтингом (мин)   |\n";
    cout << "| 4. Сортировать за рейтингом (макс)  |\n";
    cout << "| 5. Сортировать за размером экрана   |\n";
    cout << "| 6. Сортировать за частотой экрана   | \n";
    cout << "| 7. Вывести все товары               |\n";
    cout << "| 8. Выход                           |\n";
    cout << "---------------------------------------\n";
    cout << "| Введите ваш выбор (1-8):            |\n";
    cout << "---------------------------------------\n";
}

void clearInput() {
    cin.clear();
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
}

void inputProduct(Product& product) {
    setlocale(0, "");

    cout << "Введите ID продукта: ";
    while (!(cin >> product.id)) {
        cout << "Ошибка! Пожалуйста, введите целое число для ID: ";
        clearInput();
    }
    cin.ignore();

    cout << "Введите имя продукта: ";
    cin.getline(product.name, 100);

    cout << "Введите категорию продукта: ";
    cin.getline(product.category, 100);

    cout << "Введите цену продукта: ";
    while (!(cin >> product.price)) {
        cout << "Ошибка! Пожалуйста, введите число для цены: ";
        clearInput();
    }
    cin.ignore();

    cout << "Введите описание продукта: ";
    cin.getline(product.description, 255);

    cout << "Введите рейтинг продукта: ";
    while (!(cin >> product.rating)) {
        cout << "Ошибка! Пожалуйста, введите целое число для рейтинга: ";
        clearInput();
    }
    cin.ignore();

    cout << "Введите процессор: ";
    cin.getline(product.processor, 100);

    cout << "Введите частоту экрана: ";
    while (!(cin >> product.screenFreq)) {
        cout << "Ошибка! Пожалуйста, введите число для частоты экрана: ";
        clearInput();
    }
    cin.ignore();

    cout << "Введите GPU: ";
    cin.getline(product.gpu, 100);

    cout << "Введите размер экрана: ";
    while (!(cin >> product.screenSize)) {
        cout << "Ошибка! Пожалуйста, введите число для размера экрана: ";
        clearInput();
    }
    cin.ignore();
}


bool saveProductToFile(const string& filename, const Product& product) {
    FILE* file;
    if (fopen_s(&file, filename.c_str(), "a") != 0) { 
        fprintf(stderr, "Unable to open file for writing.\n");
        return false;
    }

    fprintf(file, "ID: %d\n", product.id);
    fprintf(file, "Name: %s\n", product.name);
    fprintf(file, "Category: %s\n", product.category);
    fprintf(file, "Price: %.2f\n", product.price);
    fprintf(file, "Description: %s\n", product.description);
    fprintf(file, "Rating: %.2f\n", product.rating);
    fprintf(file, "Processor: %s\n", product.processor);
    fprintf(file, "Screen Frequency: %d\n", product.screenFreq);
    fprintf(file, "GPU: %s\n", product.gpu);
    fprintf(file, "Screen Size: %.2f\n", product.screenSize);
    fprintf(file, "--------------------------\n");

    fclose(file);
    return true;
}


void printProduct(const Product& product) {
    setlocale(0, "");
        cout << "ID: " << product.id << endl;
        cout << "Name: " << product.name << endl;
        cout << "Category: " << product.category << endl;
        cout << "Price: " << product.price << endl;
        cout << "Description: " << product.description << endl;
        cout << "Rating: " << product.rating << endl;
        cout << "Processor: " << product.processor << endl;
        cout << "Screen Frequency: " << product.screenFreq << endl;
        cout << "GPU: " << product.gpu << endl;
        cout << "Screen Size: " << product.screenSize << endl;
        cout << "--------------------------" << endl;
    }



vector<Product> readProductsFromFile(const string& filename) {
    setlocale(0, "");
    FILE* file;
    if (fopen_s(&file, filename.c_str(), "r") == 0) {
        vector<Product> products;
        char line[256];
        Product product;
        while (fgets(line, sizeof(line), file)) {
            if (strcmp(line, "--------------------------\n") == 0) {
                products.push_back(product);
                product = Product();
            }
            else {
                char key[50] = { 0 }, value[200] = { 0 };
                int result = sscanf_s(line, "%49[^:]: %199[^\n]", key, (unsigned int)sizeof(key), value, (unsigned int)sizeof(value));
                if (result == 2) {
                    value[strlen(value)] = '\0'; // Make sure to null terminate the value string
                    if (strcmp(key, "ID") == 0) {
                        product.id = atoi(value);
                    }
                    else if (strcmp(key, "Name") == 0) {
                        strncpy_s(product.name, value, sizeof(product.name) - 1);
                        product.name[sizeof(product.name) - 1] = '\0'; // Ensure null termination
                    }
                    else if (strcmp(key, "Category") == 0) {
                        strncpy_s(product.category, value, sizeof(product.category) - 1);
                        product.category[sizeof(product.category) - 1] = '\0'; // Ensure null termination
                    }
                    else if (strcmp(key, "Price") == 0) {
                        product.price = stof(value);
                    }
                    else if (strcmp(key, "Description") == 0) {
                        strncpy_s(product.description, value, sizeof(product.description) - 1);
                        product.description[sizeof(product.description) - 1] = '\0'; // Ensure null termination
                    }
                    else if (strcmp(key, "Rating") == 0) {
                        product.rating = stof(value);
                    }
                    else if (strcmp(key, "Processor") == 0) {
                        strncpy_s(product.processor, value, sizeof(product.processor) - 1);
                        product.processor[sizeof(product.processor) - 1] = '\0'; // Ensure null termination
                    }
                    else if (strcmp(key, "Screen Frequency") == 0) {
                        product.screenFreq = atoi(value);
                    }
                    else if (strcmp(key, "GPU") == 0) {
                        strncpy_s(product.gpu, value, sizeof(product.gpu) - 1);
                        product.gpu[sizeof(product.gpu) - 1] = '\0'; // Ensure null termination
                    }
                    else if (strcmp(key, "Screen Size") == 0) {
                        product.screenSize = stof(value);
                    }
                }
            }
        }
        fclose(file);
        return products;
    }
    else {
        cout << "Unable to open file: " << filename << endl;
        return {};
    }
}


void delete_structure_by_id(const char* filename, int id_to_delete) {
    setlocale(0, "");
    FILE* file;
    fopen_s(&file, filename, "r");
    if (file == NULL) {
        perror("Unable to open file");
        return;
    }

    FILE* temp_file;
    fopen_s(&temp_file, "temp.txt", "w");
    if (temp_file == NULL) {
        perror("Unable to create temporary file");
        fclose(file);
        return;
    }

    char line[256];
    int current_id = -1;
    bool skip = false;

    while (fgets(line, sizeof(line), file)) {
        if (strncmp(line, "ID:", 3) == 0) {
            sscanf_s(line + 3, "%d", &current_id);
            skip = (current_id == id_to_delete);
        }

        if (!skip) {
            fputs(line, temp_file);
        }

        if (strcmp(line, "--------------------------\n") == 0) {
            skip = false;
        }
    }

    fclose(file);
    fclose(temp_file);

    if (remove(filename) != 0) {
        perror("Error deleting original file");
        return;
    }

    if (rename("temp.txt", filename) != 0) {
        perror("Error renaming temporary file");
    }
}


void edit_structure_by_id(const char* filename, int id_to_edit, int new_id) {
    setlocale(0, "");
    FILE* file;
    fopen_s(&file, filename, "r");
    if (file == NULL) {
        perror("Unable to open file");
        return;
    }

    FILE* temp_file;
    fopen_s(&temp_file, "temp.txt", "w");
    if (temp_file == NULL) {
        perror("Unable to create temporary file");
        fclose(file);
        return;
    }

    char line[256];
    int current_id = 1;

    while (fgets(line, sizeof(line), file)) {
        if (strncmp(line, "ID:", 3) == 0) {
            sscanf_s(line + 3, "%d", &current_id);
            if (current_id == id_to_edit) {
                // Edit the ID
                snprintf(line, sizeof(line), "ID:%d\n", new_id);
            }
        }

        fputs(line, temp_file);
    }

    fclose(file);
    fclose(temp_file);

    if (remove(filename) != 0) {
        perror("Error deleting original file");
        return;
    }

    if (rename("temp.txt", filename) != 0) {
        perror("Error renaming temporary file");
    }
}



void edit_price_by_id(const char* filename, int id_to_edit, float new_price) {
    FILE* file;
    fopen_s(&file, filename, "r");
    if (file == NULL) {
        perror("Unable to open file");
        return;
    }

    FILE* temp_file;
    fopen_s(&temp_file, "temp.txt", "w");
    if (temp_file == NULL) {
        perror("Unable to create temporary file");
        fclose(file);
        return;
    }

    char line[256];
    int current_id = 0;
    bool id_found = false;

    while (fgets(line, sizeof(line), file)) {
        if (strncmp(line, "ID:", 3) == 0) {
            sscanf_s(line + 3, "%d", &current_id);
        }

        if (current_id == id_to_edit && strncmp(line, "Price:", 6) == 0) {
            snprintf(line, sizeof(line), "Price:%.2f\n", new_price);
            id_found = true;
        }

        fputs(line, temp_file);
    }

    fclose(file);
    fclose(temp_file);

    if (!id_found) {
        std::cout << "ID not found." << std::endl;
        remove("temp.txt");
        return;
    }

    if (remove(filename) != 0) {
        perror("Error deleting original file");
        return;
    }

    if (rename("temp.txt", filename) != 0) {
        perror("Error renaming temporary file");
    }
}


void edit_rating_by_id(const char* filename, int id_to_edit, float new_rating) {
    FILE* file;
    fopen_s(&file, filename, "r");
    if (file == NULL) {
        perror("Unable to open file");
        return;
    }

    FILE* temp_file;
    fopen_s(&temp_file, "temp.txt", "w");
    if (temp_file == NULL) {
        perror("Unable to create temporary file");
        fclose(file);
        return;
    }

    char line[256];
    int current_id = 0;
    bool id_found = false;

    while (fgets(line, sizeof(line), file)) {
        if (strncmp(line, "ID:", 3) == 0) {
            sscanf_s(line + 3, "%d", &current_id);
        }

        if (current_id == id_to_edit && strncmp(line, "Rating:", 7) == 0) {
            snprintf(line, sizeof(line), "Rating:%.2f\n", new_rating);
            id_found = true;
        }

        fputs(line, temp_file);
    }

    fclose(file);
    fclose(temp_file);

    if (!id_found) {
        std::cout << "ID not found." << std::endl;
        remove("temp.txt");
        return;
    }

    if (remove(filename) != 0) {
        perror("Error deleting original file");
        return;
    }

    if (rename("temp.txt", filename) != 0) {
        perror("Error renaming temporary file");
    }
}


void edit_name_by_id(const char* filename, int id_to_edit, const char* new_name) {
    FILE* file;
    fopen_s(&file, filename, "r");
    if (file == NULL) {
        perror("Unable to open file");
        return;
    }

    FILE* temp_file;
    fopen_s(&temp_file, "temp.txt", "w");
    if (temp_file == NULL) {
        perror("Unable to create temporary file");
        fclose(file);
        return;
    }

    char line[256];
    int current_id = 0;
    bool id_found = false;

    while (fgets(line, sizeof(line), file)) {
        if (strncmp(line, "ID:", 3) == 0) {
            sscanf_s(line + 3, "%d", &current_id);
        }

        if (current_id == id_to_edit && strncmp(line, "Name:", 5) == 0) {
            snprintf(line, sizeof(line), "Name:%s\n", new_name);
            id_found = true;
        }

        fputs(line, temp_file);
    }

    fclose(file);
    fclose(temp_file);

    if (!id_found) {
        std::cout << "ID not found." << std::endl;
        remove("temp.txt");
        return;
    }

    if (remove(filename) != 0) {
        perror("Error deleting original file");
        return;
    }

    if (rename("temp.txt", filename) != 0) {
        perror("Error renaming temporary file");
    }
}



void bubbleSortMIN(vector<Product>& products) {
    size_t  n = products.size();
    for (size_t  i = 0; i < n - 1; ++i) {
        for (size_t  j = 0; j < n - i - 1; ++j) {
            if (products[j].price > products[j + 1].price) {
                swap(products[j], products[j + 1]);
            }
        }
    }
}

void bubbleSortMAX(vector<Product>& products) {
    size_t  n = products.size();
    for (size_t  i = 0; i < n - 1; ++i) {
        for (size_t  j = 0; j < n - i - 1; ++j) {
            if (products[j].price < products[j + 1].price) {
                swap(products[j], products[j + 1]);
            }
        }
    }
}


void bubbleSortMINR(vector<Product>& products) {
    size_t  n = products.size();
    for (size_t  i = 0; i < n - 1; ++i) {
        for (size_t  j = 0; j < n - i - 1; ++j) {
            if (products[j].rating > products[j + 1].rating) {
              swap(products[j], products[j + 1]);
            }
        }
    }
}

void bubbleSortMAXR(vector<Product>& products) {
    size_t  n = products.size();
    for (size_t  i = 0; i < n - 1; ++i) {
        for (size_t  j = 0; j < n - i - 1; ++j) {
            if (products[j].rating < products[j + 1].rating) {
                swap(products[j], products[j + 1]);
            }
        }
    }
}



void bubbleSortMAXscreen(vector<Product>& products) {
    size_t  n = products.size();
    for (size_t i = 0; i < n - 1; ++i) {
        for (size_t j = 0; j < n - i - 1; ++j) {
            if (products[j].screenSize < products[j + 1].screenSize) {
                swap(products[j], products[j + 1]);
            }
        }
    }
}


void bubbleSortMAXfreq(vector<Product>& products) {
    size_t  n = products.size();
    for (size_t i = 0; i < n - 1; ++i) {
        for (size_t j = 0; j < n - i - 1; ++j) {
            if (products[j].screenFreq < products[j + 1].screenFreq) {
                swap(products[j], products[j + 1]);
            }
        }
    }
}


