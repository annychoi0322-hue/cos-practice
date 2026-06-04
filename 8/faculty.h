#ifndef __FACULTY_H__
#define __FACULTY_H__

class Faculty {
    private:
        const char *id;
        int age;
        const char *name;

    public:
        Faculty(const char *id, int age, const char *name);
        Faculty(const char *id, const char *name);
        const char *getID();
        void setID(const char *id);
        int getAge();
        void setAge(int age);
        const char *getName();
        void setName(const char *name);
        void print();
};

#endif /* __FACULTY_H__ */


int main() {
    cout << "h1 >>>" << endl;
    Human *h1 = (Human *) new Student("Alice", 20, "20240001")
    cout << "h2 >>>" << endl;
    Human *h2 = (Human *) new Student("Tom", 22, "20220001")
    cout << "h3 >>>" << endl;
    Human *h3 = (Human *) new Student("Mack", 21)
    Student *h4 = (Student *)h1;
    Student *h5 = (Student *)h3;
}
