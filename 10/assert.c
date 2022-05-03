

void test_function() {
    assert(foo(2,3) == 5);
    assert(foo(0, 0) == 0);
}

void error(char *msg, int code) {
    fprintf(sterr, "Erreur: %s\n", msg);
    exit(code);
}
int main() {
    printf("Entrez un nombre:");
    int u;
    if (scanf("%d", &u) != 1) {
        error("Entrée invalide", 2);
    }
    u *= 2;
    assert(u % 2 == 0);

}