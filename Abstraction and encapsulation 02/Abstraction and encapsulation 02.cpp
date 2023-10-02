#include <iostream>
#include <fstream>
#include <string>
#include <Windows.h> 


class Address {
private:
    std::string city;
    std::string street;
    int houseNumber;
    int apartmentNumber;

public:
    Address(std::string city, std::string street, int houseNumber, int apartmentNumber)
        : city(city), street(street), houseNumber(houseNumber), apartmentNumber(apartmentNumber) {}

    Address() {}

    std::string getOutputAddress() {
        return city + ", " + street + ", " + std::to_string(houseNumber) + ", " + std::to_string(apartmentNumber);
    }
};

void sort(Address* addresses, int size) {
    for (int i = 0; i < size - 1; i++) {
        for (int j = 0; j < size - i - 1; j++) {
            if (addresses[j].getOutputAddress() > addresses[j + 1].getOutputAddress()) {
                std::swap(addresses[j], addresses[j + 1]);
            }
        }
    }
}

int main() {
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);

    std::ifstream inputFile("in.txt");
    std::ofstream outputFile("out.txt");

    if (inputFile.is_open()) {

        int n;
        inputFile >> n;

        Address* addresses = new Address[n];

        for (int i = 0; i < n; i++) {
            std::string city, street;
            int houseNumber, apartmentNumber;
            inputFile >> city >> street >> houseNumber >> apartmentNumber;
            addresses[i] = Address(city, street, houseNumber, apartmentNumber);
        }

        sort(addresses, n);

        outputFile << n << "\n";
        for (int i = n - 1; i >= 0; i--) {
            outputFile << addresses[i].getOutputAddress() << "\n";
        }

        inputFile.close();
        delete[] addresses;
    }
    else
    {
        std::cout << "Файл не открыт.";
    }
    return 0;
}
