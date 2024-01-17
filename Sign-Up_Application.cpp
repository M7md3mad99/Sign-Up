#include <iostream>
#include<vector>
#include<string>


constexpr int MAX_RECORDS=100;

enum class OptionChoice
{
    Add = 1,
    Fetch,
    Quit
};

class Record {
public:
    std::string name;
    int age;
};

void addRecord(std::vector<Record>& records);
Record fetchRecord(const std::vector<Record>& records, int userId);
void printMenu();

int main() {
    std::vector<Record> records;

    int optionInt;
    OptionChoice option;
    do {
        printMenu();
        std::cout << "Enter option: ";
        std::cin >> optionInt;
        option = static_cast<OptionChoice>(optionInt);

        switch (option) {
            case OptionChoice::Add:
                addRecord(records);
                break;
            case OptionChoice::Fetch: {
                int userId;
                std::cout << "Enter user ID: ";
                std::cin >> userId;
                Record fetchedRecord = fetchRecord(records, userId);
                if (!fetchedRecord.name.empty())
                    std::cout << "User Name: " << fetchedRecord.name << ", User Age: " << fetchedRecord.age << "\n";
                else
                    std::cout << "Invalid user ID. Please try again.\n" ;
                break;
            }
            case OptionChoice::Quit:
                std::cout << "Exiting the program. Goodbye!\n";
                break;
            default:
                std::cout << "Invalid option. Please try again.\n";
        }
    } while (option != OptionChoice::Quit);

    return 0;
}
void addRecord(std::vector<Record>& records) {
    if (records.size() < MAX_RECORDS) {
        Record newRecord;
        std::cout << "Add Record. Please enter user name and age:\n";
        std::cout << "Name: ";
        std::cin.ignore(); // Clear input buffer
        std::getline(std::cin, newRecord.name);
        std::cout << "Age: ";
        std::cin >> newRecord.age;

        records.push_back(newRecord);
        std::cout << "Record added successfully.\n";
    } else {
        std::cout << "Maximum number of records reached. Cannot add more.\n" ;
    }
}

Record fetchRecord(const std::vector<Record>& records, int userId) {
    Record emptyRecord; // An empty record to represent an invalid result
    emptyRecord.name = ""; // Set the name to empty to indicate an invalid result

    if (userId >= 0 && userId < static_cast<int>(records.size())) {
        return records[userId];
    } else {
        return emptyRecord;
    }
}

void printMenu() {
    std::cout << "User SignUp Application\n";
    std::cout << "Please select an option:\n";
    std::cout << "1: Add Record\n" ;
    std::cout << "2: Fetch Record\n" ;
    std::cout << "3: Quit\n" ;
}