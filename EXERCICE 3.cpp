#include <iostream>
using namespace std;

struct Element {
    int valeur;
    Element* suivant;
};

class Liste {
private:
    Element* tete;

public:
    Liste() {
        tete = NULL;
    }

    void ajouter(int v) {
        Element* e = new Element;
        e->valeur = v;
        e->suivant = tete;
        tete = e;
    }

    void afficher() {
        Element* tmp = tete;
        while (tmp != NULL) {
            cout << tmp->valeur << " -> ";
            tmp = tmp->suivant;
        }
        cout << "NULL" << endl;
    }

    ~Liste() {
        Element* tmp;
        while (tete != NULL) {
            tmp = tete;
            tete = tete->suivant;
            delete tmp;
        }
    }
};

int main() {
    Liste L;
    L.ajouter(10);
    L.ajouter(20);
    L.ajouter(30);

    L.afficher();
    return 0;
}