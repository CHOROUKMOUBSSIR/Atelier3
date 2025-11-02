#include <iostream>
using namespace std;

class Pile {
private:
    int* tab;
    int sommet;
    int taille;

public:
    Pile(int t = 10) {
        taille = t;
        tab = new int[taille];
        sommet = -1;
    }

    void push(int x) {
        if (sommet == taille - 1) {
            cout << "Pile pleine !" << endl;
            return;
        }
        tab[++sommet] = x;
    }

    int pop() {
        if (sommet == -1) {
            cout << "Pile vide !" << endl;
            return -1;
        }
        return tab[sommet--];
    }

    ~Pile() {
        delete[] tab;
    }
};

int main() {
    Pile p1(5), p2(5);

    p1.push(10);
    p1.push(20);
    p1.push(30);

    cout << p1.pop() << endl;
    cout << p1.pop() << endl;

    p2.push(100);
    p2.push(200);

    cout << p2.pop() << endl;

    return 0;
}