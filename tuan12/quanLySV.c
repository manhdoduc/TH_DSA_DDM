#include <stdio.h>
#include <stdlib.h>

// Định nghĩa cấu trúc SinhVien
typedef struct {
    char name;
    double gpa;
} Student;

// Định nghĩa cấu trúc Node cho danh sách liên kết
typedef struct Node {
    Student data;
    struct Node* next;
} Node;

// Định nghĩa danh sách liên kết cho quản lý sinh viên
typedef struct {
    Node* head;
} StudentList;

// Hàm khởi tạo danh sách liên kết
void initStudentList(StudentList* list) {
    list->head = NULL;
}

// Hàm tạo một Node mới
Node* makeNode(Student data) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

// Hàm thêm sinh viên vào đầu danh sách
void addStudent(StudentList* list, char name, double gpa) {
    Node* newNode = makeNode((Student) {name, gpa});
    newNode->next = list->head;
    list->head = newNode;
}

// Hàm in ra danh sách sinh viên
void printStudentList(StudentList* list) {
    Node* current = list->head;
    while (current != NULL) {
        printf("Name: %c, GPA: %0.2lf\n", current->data.name, current->data.gpa);
        current = current->next;
    }
    printf("\n");
}

// Hàm chính
int main() {
    StudentList studentList;
    initStudentList(&studentList);

    // Thêm sinh viên vào danh sách
    addStudent(&studentList, 'A', 3.5);
    addStudent(&studentList, 'B', 4.0);
    addStudent(&studentList, 'C', 3.2);

    // In ra danh sách sinh viên
    printf("Student List:\n");
    printStudentList(&studentList);

    return 0;
}
