#include <bits/stdc++.h>

using namespace std;

struct MatHang {
    string MaHang;
    string DonViTinh;
    int SoLuong;
};

struct SLLMatHang {
    MatHang data;
    SLLMatHang *next;
};

// 2)
SLLMatHang *readFromFile(const string fileName) {
    SLLMatHang *head = nullptr, *last = nullptr;
    fstream f(fileName);

    if (!f.is_open()) {
        cout << "Không mở được file: " << fileName << endl;
        return nullptr;
    }

    string maHang, donViTinh, soLuong;
    while (getline(f, maHang, ',') && getline(f, donViTinh, ',') &&
           getline(f, soLuong)) {
        MatHang m = {maHang, donViTinh, stoi(soLuong)};
        SLLMatHang *p = new SLLMatHang;
        p->data = m;
        p->next = nullptr;
        if (head == nullptr) {
            head = p;
        } else {
            last->next = p;
        }
        last = p;
    }
    f.close();

    return head;
}

// 3)
void printSLL(SLLMatHang *head) {
    SLLMatHang *p = head;
    while (p != nullptr) {
        cout << p->data.MaHang << " " << p->data.DonViTinh << " "
             << p->data.SoLuong << endl;
        p = p->next;
    }
}

// 4)
void tonKho(SLLMatHang *head) {
    SLLMatHang *p = head;
    while (p != nullptr) {
        if (p->data.SoLuong == 0) {
            cout << p->data.MaHang << " " << p->data.DonViTinh << " "
                 << p->data.SoLuong << endl;
        }
        p = p->next;
    }
}

// 5)
int searchMatHang(SLLMatHang *head, const string name) {
    SLLMatHang *p = head;
    while (p != nullptr) {
        if (p->data.MaHang == name) {
            return p->data.SoLuong;
        }
        p = p->next;
    }
    return -1;
}

void sortByMaHang(SLLMatHang *head) {
    SLLMatHang *p = head;
    while (p != nullptr) {
        SLLMatHang *max = p;
        SLLMatHang *maxNext = p->next;
        while (maxNext != nullptr) {
            if (maxNext->data.MaHang > max->data.MaHang) {
                max = maxNext;
            }
            maxNext = maxNext->next;
        }

        if (max != p) {
            swap(p->data, max->data);
        }

        p = p->next;
    }
}

// 6)
void writeToFile(SLLMatHang *head, const string fileName) {
    ofstream f(fileName);
    sortByMaHang(head);
    SLLMatHang *p = head;
    while (p != nullptr) {
        if (p->data.SoLuong != 0) {
            f << p->data.MaHang << " " << p->data.DonViTinh << " "
              << p->data.SoLuong << endl;
        }
        p = p->next;
    }
    f.close();
}

// 7)
void cleanUp(SLLMatHang *head) {
    SLLMatHang *p = head;
    SLLMatHang *p1 = nullptr;
    while (p != nullptr) {
        if (p->data.SoLuong == 0) {
            if (p1 == nullptr) {
                head = p->next;
            } else {
                p1->next = p->next;
            }
            cout << "Xóa mặt hàng " << p->data.MaHang << " vì không còn tồn"
                 << endl;
            delete p;
        }
        p1 = p;
        p = p->next;
    }
    cout << "\nDanh sách sau khi cleanup: " << endl;
    printSLL(head);
}

int main(int argc, char *argv[]) {
    // 2)
    SLLMatHang *head = readFromFile("tonkho.txt");

    // 3)
    printSLL(head);

    // 4)
    cout << "\nMặt hàng tồn kho bằng 0:" << endl;
    tonKho(head);

    // 5)
    cout << "\nSố lượng tồn kho mặt hàng MHO5: " << searchMatHang(head, "MH05")
         << endl;

    // 6)
    writeToFile(head, "conton.txt");

    // 7)
    cout << endl;
    cleanUp(head);

    return 0;
}
