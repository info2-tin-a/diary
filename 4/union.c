
typedef union temperature {
    float temp;
    char bytes[4];
    short words[2];
} Temperature;

int main() {
    Temperature t;

    float u = 0;
    char b[4] = {123, 34, 23, 9};
    u = b[0] | b[1] << 8 | b[2] << 16 | b[3] << 24;

    t.bytes[0] = b[0];
    t.bytes[1] = b[1];
    t.bytes[2] = b[2];
    t.bytes[3] = b[3];
    printf("%f\n", t.temp);

    memcpy(u, b, 4);
}
