#include <iostream>
using namespace std;

class Fichier {
private:
    char* ptr;
    int taille;

public:
    
    Fichier(int t) {
        taille = t;
        ptr = new char[taille];
        cout << "Mémoire réservée." << endl;
    }

    
    void Remplit() {
        for (int i = 0; i < taille; i++)
            ptr[i] = 'A' + (i % 26); 
        cout << "Mémoire remplie." << endl;
    }

    void Affiche() {
        for (int i = 0; i < taille; i++)
            cout << ptr[i];
        cout << endl;
    }

 
    ~Fichier() {
        delete[] ptr;
        cout << "Mémoire libérée." << endl;
    }
};

int main() {
    Fichier* f = new Fichier(10);

    f->Remplit();
    f->Affiche();

    delete f;
    return 0;
}