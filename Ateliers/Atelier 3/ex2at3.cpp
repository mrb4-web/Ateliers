#include <iostream>
#include <string>
using namespace std;

class Fichier {
private:
    char* P;
    int longueur;
    
public:
    Fichier() : P(nullptr), longueur(0) {}
    
    ~Fichier() {
        if (P != nullptr) {
            delete[] P;
        }
    }
    
    void Creation(int taille) {
        longueur = taille;
        P = new char[longueur];
    }
    
    void Remplit() {
        if (P != nullptr) {
            for (int i = 0; i < longueur; i++) {
                P[i] = 'A' + (i % 26);
            }
        }
    }
    
    void Affiche() {
        if (P != nullptr) {
            for (int i = 0; i < longueur && i < 50; i++) {
                cout << P[i];
            }
            cout << endl;
        }
    }
};

int main() {
    Fichier* fichier = new Fichier();
    
    fichier->Creation(100);
    fichier->Remplit();
    fichier->Affiche();
    
    delete fichier;
    
    return 0;
}