#include <iostream>

using namespace std;

class User {
    string name;
    string surName;
    int age;
public:
    static int amountOfUsers;

    /*User() = default; */

    User() {
        name = "Alexey";
        surName = "Marahovskiy";
        age = 16;

    }

    User(string name, string surName, int age) {
        this->name = name;
        this->surName = surName;
        this->age = age;

    }


    /* static void IncrementAmountOfUsers() {
         amountOfUsers++;}
     */

    void PrintInfo() {
        cout << name << endl << surName << endl << age << endl;
    }
};

class Group {
    User* groupUser = new User[User::amountOfUsers];
public:
    Group() {

    }

    void PrintInfo() {
        for (int i = 0; i < User::amountOfUsers; i++) {
            groupUser[i].PrintInfo();

        }
    }

    void addUser(const User& other) {
        User* tempArr = new User[User::amountOfUsers];
        for (int i = 0; i < User::amountOfUsers; i++) {
            tempArr[i] = this->groupUser[i];
        }

        delete[] this->groupUser;
        User::amountOfUsers++;

        this->groupUser = new User[User::amountOfUsers];

        for (int i = 0; i < User::amountOfUsers - 1; i++) {
            this->groupUser[i] = tempArr[i];
        }

        this->groupUser[User::amountOfUsers - 1] = other;
    }

    void DeleteUser() {
        if (User::amountOfUsers < 1) {
            cout << "There's no users" << endl;
        }
        else {
            User* tempArr = new User[User::amountOfUsers];
            for (int i = 0; i < User::amountOfUsers; i++) {
                tempArr[i] = this->groupUser[i];
            }

            delete[] this->groupUser;
            User::amountOfUsers--;

            this->groupUser = new User[User::amountOfUsers];

            for (int i = 0; i < User::amountOfUsers - 1; i++) {
                this->groupUser[i] = tempArr[i];
            }
        }

    }

    void RenameUser(const User& other) {
        int index;
        cout << "enter index of User" << endl;
        cin >> index;
        /*if (index > User::amountOfUsers) {
            cout << "There's no such User index" << endl;
        }*/
        for (int i = 0; i < User::amountOfUsers; i++) {
            if (i == index) {
                groupUser[i] = other;
            }
        }
    }
};

int User::amountOfUsers = 1;

int main() {

    Group obj2;
    obj2.PrintInfo();
    obj2.addUser(User("Serger", "Yaxheslad", 16));

    obj2.DeleteUser();
    obj2.PrintInfo();
    obj2.RenameUser(User("Serger", "Yaxheslad", 16));
    obj2.PrintInfo();
}
