#include <bits/stdc++.h>
#define max 100

using std::cin;
using std::cout;
using std::endl;
using std::string;
using std::vector;

struct Customer {
    string name;
    string address;
    vector<string> phoneNumbers;
};

struct ListOfCustomers {
    Customer arrCustomers[max];
    int numOfCustomers;
};

void inputCustomer(Customer &c) {
    cout << "Name: ";
    getline(cin, c.name);
    cout << "Address: ";
    getline(cin, c.address);
    int n;
    cout << "Number of phone numbers: ";
    cin >> n;
    cin.ignore();
    for (int i = 0; i < n; i++) {
        string s;
        cout << "Phone number " << i + 1 << ": ";
        getline(cin, s);
        c.phoneNumbers.push_back(s);
    }
}

void outputCustomer(Customer c) {
    cout << "Name: " << c.name << endl;
    cout << "Address: " << c.address << endl;
    cout << "Phone numbers: ";
    for (int i = 0; i < c.phoneNumbers.size(); i++)
        cout << c.phoneNumbers[i] << " ";
    cout << endl;
}

void inputListOfCustomers(ListOfCustomers &list) {
    cout << "Number of customers: ";
    cin >> list.numOfCustomers;
    cin.ignore();
    for (int i = 0; i < list.numOfCustomers; i++) {
        inputCustomer(list.arrCustomers[i]);
    }
}

void outputListOfCustomers(ListOfCustomers list) {
    cout << "\n----------------------------------\n";
    cout << "Number of customers: " << list.numOfCustomers << endl;
    for (int i = 0; i < list.numOfCustomers; i++) {
        outputCustomer(list.arrCustomers[i]);
    }
    cout << "----------------------------------\n\n";
}

void insertCustomer(ListOfCustomers &list, Customer c, int index) {
    if (index < 0 || index > list.numOfCustomers) {
        cout << "Invalid index. Please enter a valid index between 0 and "
             << list.numOfCustomers << endl;
    }
    if (list.numOfCustomers == max) {
        cout << "Can not insert customers. List is full." << endl;
        return;
    }
    for (int i = list.numOfCustomers; i > index; i--) {
        list.arrCustomers[i] = list.arrCustomers[i - 1];
    }
    list.arrCustomers[index] = c;
    list.numOfCustomers++;
    cout << "Successfully inserted customer at index " << index << endl;
}

void deleteCustomer(ListOfCustomers &list, int index) {
    if (index < 0 || index >= list.numOfCustomers) {
        cout << "Invalid index. Please enter a valid index between 0 and "
             << list.numOfCustomers - 1 << endl;
        return;
    }
    for (int i = index; i < list.numOfCustomers - 1; i++) {
        list.arrCustomers[i] = list.arrCustomers[i + 1];
    }
    list.numOfCustomers--;
    cout << "Successfully deleted customer at index " << index << endl;
}

int findCustomerByName(ListOfCustomers list, string name) {
    for (int i = 0; i < list.numOfCustomers; i++) {
        if (list.arrCustomers[i].name == name) {
            return i;
        }
    }
    cout << "No customer with name " << name << " was found" << endl;
    return -1;
}

void deleteCustomerByName(ListOfCustomers &list, string name) {
    int index = findCustomerByName(list, name);
    if (index != -1)
        deleteCustomer(list, index);
}

void findCustomerByPhoneNumber(ListOfCustomers list, string phoneNumber) {
    for (int i = 0; i < list.numOfCustomers; i++) {
        for (int j = 0; j < list.arrCustomers[i].phoneNumbers.size(); j++) {
            if (list.arrCustomers[i].phoneNumbers[j] == phoneNumber) {
                outputCustomer(list.arrCustomers[i]);
                return;
            }
        }
    }
    cout << "No customer with phone number " << phoneNumber << " was found"
         << endl;
}

void deletePhoneNumber(ListOfCustomers &list, string phoneNumber) {
    for (int i = 0; i < list.numOfCustomers; i++) {
        for (int j = 0; j < list.arrCustomers[i].phoneNumbers.size(); j++) {
            if (list.arrCustomers[i].phoneNumbers[j] == phoneNumber) {
                list.arrCustomers[i].phoneNumbers.erase(
                    list.arrCustomers[i].phoneNumbers.begin() + j);
                return;
            }
        }
    }
    cout << "No customer with phone number " << phoneNumber << " was found"
         << endl;
}

void appendPhoneNumber(ListOfCustomers &list, string name, string phoneNumber) {
    int index = findCustomerByName(list, name);
    if (index != -1)
        list.arrCustomers[index].phoneNumbers.push_back(phoneNumber);
}

void mergeCustomer(ListOfCustomers &list, Customer c) {
    int index = findCustomerByName(list, c.name);
    if (index != -1) {
        for (int i = 0; i < c.phoneNumbers.size(); i++) {
            if (c.phoneNumbers[i] != list.arrCustomers[index].phoneNumbers[i]) {
                list.arrCustomers[index].phoneNumbers.push_back(
                    c.phoneNumbers[i]);
            }
        }
    } else {
        insertCustomer(list, c, list.numOfCustomers);
    }
}

int main() {
    Customer c;
    ListOfCustomers l;
    string name;
    int k;

    // Input a list of customers
    inputListOfCustomers(l);

    // Output list of customers
    outputListOfCustomers(l);

    // Insert a customer
    inputCustomer(c);
    cout << "Index for insert: ";
    cin >> k;
    cin.ignore();
    insertCustomer(l, c, k);

    // Output list of customers after insert
    outputListOfCustomers(l);

    // Find a customer
    cout << "Name of customer: ";
    getline(cin, name);
    k = findCustomerByName(l, name);
    if (k == -1)
        cout << "Not found the customer name: " << name;
    else {
        cout << "Found a customer: ";
        outputCustomer(l.arrCustomers[k]);
    }

    // Delete a customer
    cout << "Index for delete: ";
    cin >> k;
    deleteCustomer(l, k);

    // Output list of customers after delete
    outputListOfCustomers(l);

    // Delete a customer by name
    cout << "Name of customer to delete: ";
    getline(cin, name);
    deleteCustomerByName(l, name);

    // Output list of customers after delete
    outputListOfCustomers(l);

    // Find a customer by phone number
    cout << "Phone number to find: ";
    string phoneNumber;
    getline(cin, phoneNumber);
    findCustomerByPhoneNumber(l, phoneNumber);

    // Delete a phone number
    cout << "Phone number to delete: ";
    getline(cin, phoneNumber);
    deletePhoneNumber(l, phoneNumber);

    // Append a phone number
    cout << "Name of customer to append phone number: ";
    getline(cin, name);
    cout << "Phone number to append: ";
    getline(cin, phoneNumber);
    appendPhoneNumber(l, name, phoneNumber);

    // Output list of customers after append
    outputListOfCustomers(l);

    // Merge a customer
    inputCustomer(c);
    mergeCustomer(l, c);

    // Output list of customers after merge
    outputListOfCustomers(l);

    return 0;
}


// 2
// Lê Nhật Trường
// Định Nhất, Vĩnh Hỏa, Vĩnh Thạnh, Bình Định
// 2
// 0867755734
// 0353260427
// Lâm Thị Hữu Hạnh
// Nguyễn Thái Học, Bình Định
// 1
// 0123456789
// Lê Minh Hội
// 213 Trần Cao Vân, Bình Định
// 2
// 0364197233
// 0452679841
// 1
// Lê Nhật Trường
// 2
// 0867755734
// 0353260427
// Lê Nhật Trường
// 0123456789
// Huỳnh Hà Thanh Trúc
// Nguyễn Thái Học, Bình Định
// 1
// 0987654321
