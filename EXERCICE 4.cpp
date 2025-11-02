#include <iostream>
using namespace std;

class Client {
private:
    int id;
    string nom, prenom;

public:

    Client(int i = 0, string n = "", string p = "") {
        id = i;
        nom = n;
        prenom = p;
    }

    Client(const Client& c) {
        id = c.id;
        nom = c.nom;
        prenom = c.prenom;
    }

    
    void afficher() const {
        cout << "Client: " << id << " - " << nom << " " << prenom << endl;
    }

    
    ~Client() {
        
    }
};

class Compte {
private:
    int numero;
    float solde;
    Client* client;

public:
    static int nbComptes; 

    Compte(int num = 0, float s = 0, Client* c = nullptr) {
        numero = num;
        solde = s;

        if (c != nullptr)
            client = new Client(*c); 
        else
            client = nullptr;

        nbComptes++;
    }

    Compte(const Compte& c) {
        numero = c.numero;
        solde = c.solde;
        client = new Client(*c.client);
        nbComptes++;
    }


    ~Compte() {
        delete client;
        nbComptes--;
    }

 
    void afficher() const {
        cout << "Compte N° " << numero << " | Solde: " << solde << " DH" << endl;
        if (client != nullptr)
            client->afficher();
        cout << "Nombre total de comptes: " << nbComptes << endl << endl;
    }
};


int Compte::nbComptes = 0;

float calculInteret(float solde, float taux) {
    return solde + solde * taux;
}

int main() {
    
    Client c1(1, "Youssef", "Ali");
    Client c2(2, "Sara", "Amine");

    
    Compte compte1(101, 2000, &c1);
    Compte compte2(102, 3500, &c2);

 
    compte1.afficher();
    compte2.afficher();

    
    Compte compte3 = compte1;
    compte3.afficher();


    float newSolde = calculInteret(2000, 0.05);
    cout << "Solde après intérêt (5%): " << newSolde << " DH" << endl;


    float newSolde = calculInteret(2000, 0.05);
    cout << "Solde après intérêt (5%): " << newSolde << " DH" << endl;


    Compte* p = new Compte(103, 1500, &c1);
    p->afficher();
    delete p;

    cout << "Après suppression du compte dynamique: " << Compte::nbComptes << endl;

    return 0;
}