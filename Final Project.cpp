#include <iostream>
#include <ctime>
#include <cstdlib>
#include <iomanip>
#include <thread>
#include <chrono>

using namespace std;
// Class Declaration
class user {
public:
    string fname, mname, lname;
    long long cnic; // CNIC as long long
    int age;
    string email;
    string username;
    string password;
    long long phnumber; // Phone number as long long

    user() { // Constructor
        cout << "Enter First Name: ";
        cin >> fname;
        cout << "Enter Middle Name: ";
        cin >> mname;
        cout << "Enter Last Name: ";
        cin >> lname;

        cout << "Enter Age: ";
        cin >> age;
        if (age < 18) {
            cout << "You are not eligible to drive " << endl;
            exit(0);
        }

        // CNIC Validation
        string cnic_input;
        cout << "Enter CNIC (xxxxx-xxxxxxx-x): ";
        while (true) {
            cin >> cnic_input;

            // Validate CNIC format manually
            if (cnic_input.length() == 15 && cnic_input[5] == '-' && cnic_input[13] == '-') {
                bool valid = true;
                for (int i = 0; i < cnic_input.length(); i++) {
                    if (i != 5 && i != 13 && !isdigit(cnic_input[i])) {
                        valid = false;
                        break;
                    }
                }

                if (valid) {
                    cout << "CNIC Accepted.\n";
                    break;
                } else {
                    cout << "Invalid CNIC format. Only digits allowed (xxxxx-xxxxxxx-x): ";
                }
            } else {
                cout << "Invalid CNIC format. Please try again (xxxxx-xxxxxxx-x): ";
            }
        }

        // Email Validation
        while (true) {
            cout << "Enter Email: ";
            cin >> email;

            // Basic Email Validation
            size_t at_position = email.find('@');
            size_t dot_position = email.find('.', at_position);
            if (at_position != string::npos && dot_position != string::npos && at_position < dot_position && dot_position < email.size() - 1) {
                cout << "Email Accepted.\n";
                break;
            } else {
                cout << "Invalid Email. Please try again." << endl;
            }
        }

        cout << "Enter Phone Number: ";
        cin >> phnumber;

        cout << "Enter Username: ";
        cin >> username;
        cout << "Enter Password: ";
        cin >> password;
    }

    bool login(string enteredUsername, string enteredPassword) {
        if (enteredUsername == username && enteredPassword == password) {
            return true;
        } else {
            return false;
        }
    }
};

class paymentdetails {
private:
    long long accountnum; // Use long long for account number
    int CVC[3];
    int Expiryday[4];

public:
    int collection;
    paymentdetails() { // Default constructor, no need to pass user1
        collection = 0;
        cout << "Enter Credit Card Number: ";
        cin >> accountnum;  // Use cin for account number input
        cout << endl;
        
        cout << "Enter CVC Number: ";
        for (int i = 0; i < 3; i++) {
            cin >> CVC[i];
        }
        
        cout << endl;
        cout << "Enter Expiry Date (MMYY): ";
        for (int i = 0; i < 4; i++) {
            cin >> Expiryday[i];
            if (i == 1) {
                cout << "/";
            }
        }
        cout << endl;
        collection++;
    }
};

class vehicle { // Abstract Class
public:
    virtual void print() = 0;
    virtual void inputhours() {}
    virtual void reciept() {}
};

class car : public vehicle { // Inherited Class
private:
    string make;  // Make of Car
    string model; // Model of Car
    string color;  // Colour of Car
    int year; // Year of Release
    int mileage;  // Mileage of Car
    string type;  // Class of Car
    string nplate; // Number Plate
    float rate; // Rate Per Hour
    int hours; // Number of Hours
    float price; // Price of the car (fixed for each car)

public:
    float total; // Variable for saving value of total cost

    // Parameterized Constructor
    car(string make, string model, string color, int year, int mileage, float rate, string type, string nplate, float price)
        : make(make), model(model), color(color), year(year), mileage(mileage), type(type), nplate(nplate), rate(rate), price(price) {}

    void print() {
        cout << "Make: " << make << endl;
        cout << "Model: " << model << endl;
    }

    void reciept(user &u) {
        cout << "*RECIEPT****************************** " << endl;
        cout << "Your Reciept Number is : " << rand() % 1022881 + 1272788 << endl;
        cout << "*RECIEVER DETAILS*" << endl;
        cout << "Reciever Name: " << u.fname << " " << u.mname << " " << u.lname << endl;
        cout << "CAR DETAILS*" << endl;
        cout << "Model: " << model << endl;
        cout << "Make: " << make << endl;
        cout << "Year: " << year << endl;
        cout << "Rate: " << rate << endl;
        cout << "Hours: " << hours << endl;
        cout << "Type: " << type << endl;
        cout << "Number Plate: " << nplate << endl;
        total = hours * rate;
        cout << "Your Total is Rs. " << total << endl;
        cout << "Price of the Car: Rs. " << price << endl;
        cout << "Total Bill: Rs. " << total + price << endl;  // Total bill includes car price and rental cost
    }

    void inputhours() {
        cout << "Please Enter Total Number Of Hours The Vehicle Will Be Used = ";
        cin >> hours;
    }

    // Getter methods for private variables
    string getMake() const { return make; }
    string getModel() const { return model; }
    string getColor() const { return color; }
    int getYear() const { return year; }
    int getMileage() const { return mileage; }
    string getType() const { return type; }
    string getNplate() const { return nplate; }
    float getRate() const { return rate; }
    int getHours() const { return hours; }
    float getPrice() const { return price; }
};

// Overloading the stream insertion operator
ostream& operator << (ostream& os, const car& n) {
    os << endl;
    os << "Make: " << n.getMake() << endl;
    os << "Model: " << n.getModel() << endl;
    os << "Color: " << n.getColor() << endl;
    os << "Year: " << n.getYear() << endl;
    os << "Mileage: " << n.getMileage() << endl;
    os << "Type: " << n.getType() << endl;
    os << "Number Plate: " << n.getNplate() << endl;
    return os;
}

// Functions
void bonvoyage() {
    cout << endl;
    cout << "Please collect your keys from the counter" << endl;
    cout << endl;
    cout << "We wish you Bon Voyage" << endl;
}

void paymentmethod(user& user1, car &v1) {
pay3:
    cout << "Please choose your preferred payment method: 1. Cash   2. Credit" << endl;
    int choice4;
    cout << "Enter Choice: ";
    cin >> choice4;

    if (choice4 == 2) {
        paymentdetails userpayment;

        if (userpayment.collection == 1) {
            cout << "Checking Details ";
            for (int i = 6; i > 1; i--) {
                cout << i - 1 << "..";
                this_thread::sleep_for(chrono::seconds(1)); // Ensure chrono and thread are included
            }
            cout << endl;
            cout << "*TRANSACTION DETAILS" << endl;
            cout << endl;
            cout << "Reciept ID: " << rand() % 1022881 + 1272788 << endl;
            cout << endl;
            cout << "Transaction Date & Time: " << __DATE__ << " " << __TIME__ << endl;  // Use __DATE__ and __TIME__
            cout << endl;
            cout << "Transaction Successful." << endl;
            cout << endl;
            cout << "Rs. " << v1.total << " has been credited from your account." << endl;
        }
    } else if (choice4 == 1) {
        cout << "Please Pay Cash On The Counter" << endl;
    } else {
        cout << "Invalid Option" << endl;
        goto pay3;
    }
}

// Main Body
int main() {
    // Create a user
    user user1;
    string enteredUsername, enteredPassword;
    
    // Login process
    bool loggedIn = false;
    while (!loggedIn) {
        cout << "Enter Username: ";
        cin >> enteredUsername;
        cout << "Enter Password: ";
        cin >> enteredPassword;

        loggedIn = user1.login(enteredUsername, enteredPassword);
        
        if (loggedIn) {
            cout << "Login successful!" << endl;
        } else {
            cout << "Invalid username or password. Please try again." << endl;
        }
    }

    // Define cars
    car ECars[3] = {
        car("Toyota", "Corolla", "Red", 2022, 10, 500, "Economy", "FGA-123", 1000),
        car("Honda", "Civic", "Blue", 2021, 15, 600, "Economy", "FGB-456", 1200),
        car("Hyundai", "Elantra", "Silver", 2023, 8, 550, "Economy", "FGC-789", 1100)
    };

    car PCars[3] = {
        car("BMW", "X5", "Blue", 2021, 15, 600, "Luxury", "FGA-878", 5000),
        car("BMW", "M5", "Red", 2022, 10, 700, "Luxury", "FGB-543", 6000),
        car("Mercedes", "S-Class", "Silver", 2022, 8, 700, "Luxury", "FGC-234", 7000)
    };

    car* carpointer = nullptr;

    // Car rental menu
    cout << "Enter your choice to rent a car:" << endl;
    cout << "1. Economy Car" << endl;
    cout << "2. Luxury Car" << endl;
    int choice;
    cin >> choice;

    if (choice == 1) {
        cout << "Available Economy Cars:" << endl;
        for (int i = 0; i < 3; i++) {
            cout << i + 1 << ". " << ECars[i] << endl;
        }

        int carChoice;
        cout << "Enter the number of the car you want to rent: ";
        cin >> carChoice;

        if (carChoice >= 1 && carChoice <= 3) {
            carpointer = &ECars[carChoice - 1];
        } else {
            cout << "Invalid choice!" << endl;
            return 0;
        }
    } else if (choice == 2) {
        cout << "Available Luxury Cars:" << endl;
        for (int i = 0; i < 3; i++) {
            cout << i + 1 << ". " << PCars[i] << endl;
        }

        int carChoice;
        cout << "Enter the number of the car you want to rent: ";
        cin >> carChoice;

        if (carChoice >= 1 && carChoice <= 3) {
            carpointer = &PCars[carChoice - 1];
        } else {
            cout << "Invalid choice!" << endl;
            return 0;
        }
    } else {
        cout << "Invalid Option" << endl;
        return 0;
    }

    carpointer->inputhours();
    carpointer->reciept(user1);
    paymentmethod(user1, *carpointer);
    bonvoyage();

    return 0;
}