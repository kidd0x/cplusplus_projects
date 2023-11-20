#include <iostream>
#include <fstream>
#include <regex>

using namespace std;

bool isValidEmail(const string& email)
{
    regex emailRegex(R"([a-zA-Z0-9._%+-]+@[a-zA-Z0-9.-]+\.[a-zA-Z]{2,})");
    return regex_match(email, emailRegex);
}

int main() {
    string filename = "Info.txt";
    ofstream outputFile(filename, ios::app); // ios::app appends to the file

    if (!outputFile.is_open()) {
        cerr << "Fisierul " << filename << "nu a putut fi deschis !" << endl;
        return 1;
    }

    cout << "Introdu-ti Numele: ";
    string name;
    getline(cin, name);

    cout << "Introdu-ti Prenumele: ";
    string lastName;
    getline(cin, lastName);

    string email;
    do {
        cout << "Introdu-ti Adresa de Email: ";
        getline(cin, email);

        if (!isValidEmail(email)) {
            cout << "Adresa de email este invalida!\n";
        }
    } while (!isValidEmail(email));

    cout << "Introdu-ti Varsta: ";
    string age;
    getline(cin, age);

    cout << "Introdu-ti Tara de Origine: ";
    string country;
    getline(cin, country);

    outputFile << "Nume: " << name << endl;
    outputFile << "Prenume: " << lastName << endl;
    outputFile << "Adresa de Email: " << email << endl;
    outputFile << "Varsta: " << age << endl;
    outputFile << "Tara: " << country << endl;

    outputFile << "===================" << endl;

    outputFile.close();

    return 0;
}
