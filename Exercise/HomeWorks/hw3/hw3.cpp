#include <bits/stdc++.h>
#define max 100

using namespace std;

struct Customer {
    string          name;
    string          address;
    vector<string>  phoneNumbers;
};

struct listOfCustomer {
    Customer    arrCustomer[max];
    int         numOfCustomer;
};

void inputCustomer (Customer &c) {
    int i, n; string phone;
    cout << "Name: "; getline(cin, c.name);
    cout << "Address: "; getline(cin, c.address);
    cout << "Num of phones: "; cin >> n;
    cin.ignore();
    for (int i = 0; i < n; i++) {
        cout << "Phone number: " << i << " : "; getline(cin, phone);
        c.phoneNumbers.push_back(phone);
    }
}

void outputCustomer (Customer c) {
    int i;
    cout << "Name: " << c.name << endl;
    cout << "Address: " << c.address << endl;
    cout << "List of phones: ";
    for (int i = 0; i < c.phoneNumbers.size(); i++) {
        cout << c.phoneNumbers[i] << " ";
    }
    cout << endl;
}

void inputListOfCustomers (listOfCustomer &l) {
    cout << "Number of customers: "; cin >> l.numOfCustomer;
    cin.ignore();
    for (int i = 0; i < l.numOfCustomer; i++) {
        inputCustomer(l.arrCustomer[i]);
    }
}

void outputListOfCustomers (listOfCustomer l) {
    cout << "\nNumber of customers: " << l.numOfCustomer << endl;
    for (int i = 0; i < l.numOfCustomer; i++) {
        outputCustomer(l.arrCustomer[i]);
    }
}

void insertCustomers (listOfCustomer &l, Customer c, int index) {
    if (index < 0 || index > l.numOfCustomer) {
        cout << "Invalid index. Please enter a valid index between 0 and " << l.numOfCustomer << endl;
    }
    if (l.numOfCustomer == max) {
        cout << "Can not insert customers. List is full." << endl;
        return;
    }
    for (int i = l.numOfCustomer; i > index; i--) {
        l.arrCustomer[i] = l.arrCustomer[i - 1];
    }
    l.arrCustomer[index] = c;
    l.numOfCustomer++;
    cout << "Successfully inserted customer at index " << index << endl;
}

void deleteCustomer (listOfCustomer &l, int index) {
    if (index < 0 || index >= l.numOfCustomer) {
        cout << "Invalid index. Please enter a valid index between 0 and " << l.numOfCustomer - 1 << endl;
        return;
    }
    for (int i = index; i < l.numOfCustomer - 1; i++) {
        l.arrCustomer[i] = l.arrCustomer[i + 1];
    }
    l.numOfCustomer--;
    cout << "Successfully deleted customer at index " << index << endl;
}

int findCustomerByName (listOfCustomer &l, string name) {
    for (int i = 0; i < l.numOfCustomer; i++) {
        if (l.arrCustomer[i].name == name) {
            return i;
        }
    }
    return -1;
}

void deleteCustomerByName (listOfCustomer &l, string name) {
    for (int i = 0; i < l.numOfCustomer; i++) {
        if (l.arrCustomer[i].name == name) {
            deleteCustomer(l, i);
        }
    }
}

int findCustomerByPhone (listOfCustomer &l, string phone) {
    for (int i = 0; i < l.numOfCustomer; i++) {
        for (int j = 0; j < l.arrCustomer[i].phoneNumbers.size(); i++) {
            if (phone == l.arrCustomer[i].phoneNumbers[j]) {
                return i;
            }
        }
    }
    return -1;
}

void appendPhone (listOfCustomer &l, string name, string phone) {
    if (findCustomerByName(l, name) == -1) {
        cout << "No customers found with name: " << name << endl;
    } else {
        l.arrCustomer[findCustomerByName(l, name)].phoneNumbers.push_back(phone);
    }
}

void mergeCustomers (listOfCustomer &l, Customer c) {
    if (findCustomerByName(l, c.name) == -1) {
        insertCustomers(l, c, l.numOfCustomer);
    } else {
        for (int i = 0; i < c.phoneNumbers.size(); i++) {
            if (c.phoneNumbers[i] != l.arrCustomer[findCustomerByName(l, c.name)].phoneNumbers[i]) {
                l.arrCustomer[findCustomerByName(l, c.name)].phoneNumbers.push_back(c.phoneNumbers[i]);
            }
        }
    }
}

int main (int argc, char *argv[]) {
    Customer c; listOfCustomer l ; string name; int k;
    inputListOfCustomers(l);
    outputListOfCustomers(l);

    // insert customers by index
    inputCustomer(c);
    cout << "Index for insert: "; cin >> k;
    insertCustomers(l, c, k);
    outputListOfCustomers(l);

    // find customer by name
    cin.ignore();
    string name2;
    cout << "\n\nName of customer to find: " << name; getline(cin, name2);
    if (findCustomerByName(l, name2) == -1) {
        cout << "No customers found with name: " << name << endl;
    } else {
        cout << "Found a customers: " << endl;
        outputCustomer(l.arrCustomer[findCustomerByName(l, name2)]);
    }

    // delete customer by index
    cout << "\n\nIndex for delete: "; cin >> k;
    deleteCustomer(l, k);
    cout << "\n\nList of customers after delete";
    outputListOfCustomers(l);

    // a) delete customer by name
    cin.ignore();
    string name3;
    cout << "\n\nEnter name to delete: "; getline(cin, name3);
    deleteCustomerByName(l, name3);
    cout << "\n\nList of customers after delete";
    outputListOfCustomers(l);

    // b) find customers by phone
    string phone;
    cout << "\n\nPhone of customer to find: "; getline(cin, phone);
    if (findCustomerByPhone(l, phone) == -1) {
        cout << "No customers found with phone: " << phone << endl;
    } else {
        cout << "Found a customers: " << endl;
        outputCustomer(l.arrCustomer[findCustomerByPhone(l, phone)]);
    }

    // c) delete a phone of customers
    string phone2;
    cout << "\n\nInput the phone you want to delete: "; getline(cin, phone2);
    if (findCustomerByPhone(l, phone2) == -1) {
        cout << "No customers found with phone: " << phone2 << endl;
    } else {
        cout << "Found a customers, delete " << endl;
        deleteCustomer(l, findCustomerByPhone(l, phone2));
        cout << "\n\nList of customers after delete: ";
        outputListOfCustomers(l);
    }

    // d) append phone
    string name4, phone3;
    do {
        cout << "\nInput the name of customers you want to append: "; getline(cin, name4);
    } while(findCustomerByName(l, name4));
    cout << "Input the phone you want to append to " << name4 << ": "; getline(cin, phone3);
    appendPhone(l, name4, phone3);
    cout << "\nList of customers after append: ";
    outputListOfCustomers(l);

    // e) merge customer
    cout << "\nInput a customer to merge" << endl;
    Customer customer;
    inputCustomer(customer);
    mergeCustomers(l, customer);
    cout << "\nList of customers after merge: ";
    outputListOfCustomers(l);

    return 0;
}

// 3
// Le Nhat Truong
// Binh Dinh
// 2
// 0867755734
// 0353260427
// Huynh Minh Lam
// Viet Nam
// 2
// 036419723
// 023461972
// Hoang Huu Nhan
// Viet Nam
// 3
// 0867755113
// 0353260497
// 0166419723
// Phung My Hoang
// Vinh Thanh, Binh Dinh
// 2
// 0364597233
// 0867755734
// 1
// Le Nhat Truong
// 2
// Le Nhat Truong
// 0364597233
// 0364597233
// Hoang Huu Nhan
// 0164297113
// Hoang Huu Nhan
// Viet Nam
// 1
// 1131131131
