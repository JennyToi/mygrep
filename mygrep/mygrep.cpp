#include <iostream>
#include <string>
#include <fstream>
#include <algorithm>

using namespace std;

// Funktio, joka muuntaa merkkijonon pieniksi kirjaimiksi
string toLowerCase(const string& str)
{
    string lower = str;
    transform(lower.begin(), lower.end(), lower.begin(), ::tolower);  
    return lower;
}

// Funktio, joka etsii ja tulostaa rivit hakusanalla tekstistä
void searchTheString(const string& target, const string& search)
{
    string targetLower = toLowerCase(target);  
    string searchLower = toLowerCase(search);  

    size_t positio = targetLower.find(searchLower);  
    if (positio != string::npos)
    {
        cout << "String found at position " << positio << endl;
    }
    else
    {
        cout << "String was not found..." << endl;
    }
}

// Funktio, joka etsii hakusanaa tiedostosta ja tulostaa rivit, jotka sisältävät sen
void searchFile(const string& fileName, const string& searchString)
{
    ifstream file(fileName);  
    if (!file.is_open())
    {
        cout << "File could not be opened." << endl;  
        return;
    }

    string line;
    while (getline(file, line))  
    {
        if (line.find(searchString) != string::npos)  
        {
            cout << line << endl;  
        }
    }

    file.close();  
}

int main(int argc, char* argv[])
{
    // Jos komentorivillä ei ole annuttu argumentteja, pyydetään käyttäjältä syötteet
    if (argc == 1) {
        string mainString;
        string searchString;

        cout << "Give a string to search from: ";
        getline(cin, mainString);  
        cout << "Give the string we are searching for: ";
        getline(cin, searchString);  

        searchTheString(mainString, searchString);  
    }
    // Jos annetaan tiedostonimi ja hakusana komentorivillä
    else if (argc == 3)
    {
        string fileName = argv[2];  
        string searchString = argv[1];  

        searchFile(fileName, searchString);  
    }
    else
    {
        cerr << "Usage: ./mygrep [file_name search_string]\n";  
    }

    return 0;
}
