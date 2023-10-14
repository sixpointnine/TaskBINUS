#include <stdio.h>
#include <string.h>

// Definisi struct
struct Person {
    char name[50];
    int age;
    float salary;
};

int main() {
    // Deklarasi variabel struct
    struct Person person1;

    // Mengisi data ke dalam variabel struct
    strcpy(person1.name, "John Doe");
    person1.age = 30;
    person1.salary = 5000.50;

    // Menampilkan data dari variabel struct
    printf("Name: %s\n", person1.name);
    printf("Age: %d\n", person1.age);
    printf("Salary: %f\n", person1.salary);

    return 0;
}
