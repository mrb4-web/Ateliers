#include <iostream>
using namespace std;

struct Element {
    int valeur;
    Element* suivant;
    
    Element(int val) : valeur(val), suivant(nullptr) {}
};

class Liste {
private:
    Element* premier;
    
public:
    Liste() : premier(nullptr) {}
    
    ~Liste() {
        Element* courant = premier;
        while (courant != nullptr) {
            Element* temp = courant;
            courant = courant->suivant;
            delete temp;
        }
    }
    
    void ajouterDebut(int valeur) {
        Element* nouvelElement = new Element(valeur);
        nouvelElement->suivant = premier;
        premier = nouvelElement;
    }
    
    void supprimerDebut() {
        if (premier != nullptr) {
            Element* temp = premier;
            premier = premier->suivant;
            delete temp;
        }
    }
    
    void afficher() {
        Element* courant = premier;
        while (courant != nullptr) {
            cout << courant->valeur << " -> ";
            courant = courant->suivant;
        }
        cout << "NULL" << endl;
    }
};

int main() {
    Liste maListe;
    
    maListe.ajouterDebut(30);
    maListe.ajouterDebut(20);
    maListe.ajouterDebut(10);
    
    maListe.afficher();
    
    maListe.supprimerDebut();
    maListe.afficher();
    
    return 0;
}