#include <iostream>
#include <map>
#include <string>
#include <vector>

int main() {
    std::string stop, surname, num;
    std::vector<std::string> num_v;

    std::map<std::string, std::vector<std::string>> surname_num;
    std::map<std::string, std::string> num_surname;
    do {
        std::cout << "Enter the subscriber's number:";
        std::cin >> num;
        std::cout << "Enter the subscriber's last name:";
        std::cin >> surname;

        num_surname.insert(std::pair<std::string, std::string> (num, surname));
        if (surname_num.count(surname) > 0) {
            std::map<std::string, std::vector<std::string>> :: iterator it = surname_num.find(surname);
            it -> second.push_back(num);
        }
        else {
            num_v.resize(1);
            num_v[0] = num;
            surname_num.insert(std::pair<std::string, std::vector<std::string>> (surname, num_v));
        }
    std::cout << "To stop/continue the program, enter stop/go:";
    std::cin >> stop;
    }while (stop != "stop");
    do {
    char answer;
    std::cout << "To search for information by last name, enter f or n to search by number:";
    std::cin >> answer;
    if (answer == 'n') {
        std::cout << "Enter the phone number to search for:";
        std::cin >> num;
        std::map<std::string, std::string> :: iterator it = num_surname.find(num);
        std::cout << "Subscriber's number " << it -> first << " " << it -> second << "\n";
    }
    else if (answer == 'f'){
        std::cout << "Enter the subscriber's last name:";
        std::cin >> surname;
        std::map<std::string, std::vector<std::string>> :: iterator it = surname_num.find(surname);
        std::cout << "Last name numbers " <<  it -> first << " ";
        for (int i = 0; i < it -> second.size(); i++) {
            std::cout <<  it -> second[i] << " ";
        }
        std::cout << std::endl;
    }
        std::cout << "To stop/continue the program, enter stop/go:";
        std::cin >> stop;
    }while (stop != "stop");
    return 0;
}
