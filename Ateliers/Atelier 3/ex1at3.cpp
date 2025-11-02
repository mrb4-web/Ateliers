#include <iostream>
using namespace std;

class Pile {
private:
    int* elements;
    int taille;
    int sommet;
    
public:
    Pile(int tailleMax = 100) {
        taille = tailleMax;
        elements = new int[taille];
        sommet = -1;
    }
    
    ~Pile() {
        delete[] elements;
    }
    
    void push(int valeur) {
        if (sommet < taille - 1) {
            sommet++;
            elements[sommet] = valeur;
        } else {
            cout << "Pile pleine!" << endl;
        }
    }
    
    int pop() {
        if (sommet >= 0) {
            int valeur = elements[sommet];
            sommet--;
            return valeur;
        } else {
            cout << "Pile vide!" << endl;
            return -1;
        }
    }
    
    bool estVide() {
        return sommet == -1;
    }
};

int main() {
    Pile p1, p2;
    
    p1.push(10);
    p1.push(20);
    p1.push(30);
    
    cout << p1.pop() << endl;
    cout << p1.pop() << endl;
    cout << p1.pop() << endl;
    
    p2.push(100);
    p2.push(200);
    
    cout << p2.pop() << endl;
    cout << p2.pop() << endl;
    
    return 0;
}