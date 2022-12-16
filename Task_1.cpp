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
    std::cout << "To find out the subscriber's last name by phone number, enter: num";
    std::cout << "To find out the subscriber's number by last name, enter: fam";
    std::cin >> answer;
    if(answer == "num"){
        int num_phone;
        std::cout << "Enter your phone number";
        std::cin >> num_phone;
        for(std::map<int, std::string>::iterator it = phone_book.begin(); it != phone_book.end(); ++it) {
            if (it -> first == num_phone) {
                std::cout << "Subscriber's last name: " << it -> second;
                answer = "1";
                break;
            }
        }
        if (answer != "1") {
            std::cout << "No subscribers with this number were found!\n";
        }
    }
    else if (answer == "fam") {
        std::string l_name, present = "1";
        std::cout << "Enter last name:";
        std::cin >> l_name;
        for(std::map<int, std::string>::iterator it = phone_book.begin(); it != phone_book.end(); ++it) {
            if (it -> second == l_name) {
                if (present == "1") {
                    std::cout
                            << "Phone numbers associated with this surname:Phone numbers associated with this surname: "
                            << it->first << " ";
                    present = "0";
                }
                std::cout << it -> first << " ";
            }
        }
    }
    else {
        std::cout << "Invalid code, program stop";
    }
    return 0;
}
