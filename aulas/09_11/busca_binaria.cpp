int busca_binaria(int v[], int ini, int fim, int x) {
    if (ini > fim) return -1;
    int m = (ini + fim) / 2;
    if (v[m] == x) return m;
    if (v[m] < x)
        return busca_binaria(v, m + 1, fim, x);
    else
        return busca_binaria(v, ini, m - 1, x);
}