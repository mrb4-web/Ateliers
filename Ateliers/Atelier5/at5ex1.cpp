bool recherche(set<int>::iterator debut, set<int>::iterator fin, int valeur) {
    for (auto it = debut; it != fin; ++it) {
        if (*it == valeur) return true;
    }
    return false;
}