#include <iostream>
#include <map>
#include <string>

int main() {
    int num;
    std::string fam, answer;
    std::map<int, std::string> phone_book;
    do {
    std::cout << "Please fill in the phone book: \n";
    std::cout << "Enter the number:";
    std::cin >> num;
    std::cout << "Enter your last name:";
    std::cin >> fam;

    phone_book.insert(std::pair<int, std::string> (num, fam));
    std::cout << "As soon as you finish filling in, enter stop/go";
    std::cin >> answer;
    }while (answer != "stop");
    answer = "go";
    do {
        std::cout << "To find out the subscriber's last name by phone number, enter: num\n";
        std::cout << "To find out the subscriber's number by last name, enter: fam\n";
        std::cin >> answer;
        if (answer == "num") {
            int num_phone;
            std::cout << "Enter your phone number";
            std::cin >> num_phone;
            for (std::map<int, std::string>::iterator it = phone_book.begin(); it != phone_book.end(); ++it) {
                if (it->first == num_phone) {
                    std::cout << "Subscriber's last name: " << it->second << "\n";
                    answer = "1";
                    break;
                }
            }
            if (answer != "1") {
                std::cout << "No subscribers with this number were found!\n";
            }
        } else if (answer == "fam") {
            std::string l_name, present = "1";
            std::cout << "Enter last name:";
            std::cin >> l_name;
            for (std::map<int, std::string>::iterator it = phone_book.begin(); it != phone_book.end(); ++it) {
                if (it->second == l_name) {
                    if (present == "1") {
                        std::cout
                                << "Phone numbers associated with this surname: ";
                        present = "0";
                    }
                    std::cout << it->first << " ";
                }
            }
            std::cout << std::endl;
        }
        else {
            std::cout << "Invalid code, program stop\n";
        }
        std::cout << "As soon as you finish filling in, enter stop/go ";
        std::cin >> answer;
    }while (answer != "stop");
    return 0;
}
