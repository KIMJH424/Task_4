#include <iostream>
#include <vector>
#include <string>

using namespace std; // namespace std ���

class Book {
public:
    string title;
    string author;

    Book(const string& title, const string& author)
        : title(title), author(author) {
    }
};

class BookManager {
private:
    vector<Book> books; // å ��� ����

public:
    // å �߰� �޼���
    void addBook(const string& title, const string& author) {
        books.push_back(Book(title, author)); // push_back ���
        cout << "å�� �߰��Ǿ����ϴ�: " << title << " by " << author << endl;
    }

    // ��� å ��� �޼���
    void displayAllBooks() const {
        if (books.empty()) {
            cout << "���� ��ϵ� å�� �����ϴ�." << endl;
            return;
        }

        cout << "���� ���� ���:" << endl;
        for (size_t i = 0; i < books.size(); i++) { // �Ϲ����� for�� ���
            cout << "- " << books[i].title << " by " << books[i].author << endl;
        }
    }

    void searchByTitle(const string& title) const {
        bool found = false;
        for (size_t i = 0; i < books.size(); i++) {
            if (books[i].title == title) {
                cout << "���� ������ �˻��� ��� :" << title << "by " << books[i].author << endl;
                found = true;
                break;
            }
        }
        if (!found) {
            cout << " ã���ô� å�� �����ϴ�." << endl;
        }
    }

    void searchByAuthor(const string& author) const {
        bool found = false;
        for (size_t i = 0; i < books.size(); i++) {
            if (books[i].author == author) {
                cout << "�۰� ������ �˻��� ��� :" << author << " by " << books[i].title << endl;
                found = true;
                break;
            }
        }
        if (!found) {
            cout << " ã���ô� å�� �����ϴ�." << endl;
        }
    }
        void initialBooks() {
            books.push_back(Book("���� �� �Ӹ��� �� �վ�?", "������ Ȧ���ٸ�Ʈ"));
            books.push_back(Book("��������", "������"));
           books.push_back(Book("����", "�赿��"));
        }

};

int main() {
    BookManager manager;

    manager.addBook("���� �� �Ӹ��� �� �վ�?", "������ Ȧ���ٸ�Ʈ");
    manager.addBook("��������", "������");
    manager.addBook("����", "�赿��");

    // ������ ���� ���α׷��� �⺻ �޴��� �ݺ������� ����Ͽ� ����� �Է��� ó���մϴ�.
    // ���α׷� ���Ḧ �����ϱ� ������ ��� �����մϴ�.
    while (true) {
        cout << "\n������ ���� ���α׷�" << endl;
        cout << "1. å �߰�" << endl; // å ������ �Է¹޾� å ��Ͽ� �߰�
        cout << "2. ��� å ���" << endl; // ���� å ��Ͽ� �ִ� ��� å ���
        cout << "3. ���� ������ �˻�" << endl; // ���� ������ �˻�
        cout << "4. �۰� ������ �˻�" << endl;
        cout << "5. ����" << endl;
        cout << "����: ";

        int choice; // ������� �޴� ������ ����
        cin >> choice;

        if (choice == 1) {
            // 1�� ����: å �߰�
            // ����ڷκ��� å ����� ���ڸ��� �Է¹޾� BookManager�� �߰��մϴ�.
            string title, author;
            cout << "å ����: ";
            cin.ignore(); // ���� �Է��� �ܿ� ���۸� ����
            getline(cin, title); // ���� �Է� (���� ����)
            cout << "å ����: ";
            getline(cin, author); // ���ڸ� �Է� (���� ����)
            manager.addBook(title, author); // �Է¹��� å ������ �߰�
        }
        else if (choice == 2) {
            // 2�� ����: ��� å ���
            // ���� BookManager�� ����� å ����� ����մϴ�.
            manager.displayAllBooks();
        }
        else if (choice == 3) {
            string title;
            cout << "å �������� �˻� : ";
            cin.ignore();
            getline(cin, title);
            manager.searchByTitle(title);
        }
        else if (choice == 4) {
            string author;
            cout << "�۰� ������ �˻� : ";
            cin.ignore();
            getline(cin, author);
            manager.searchByAuthor(author);
        }
        else if (choice == 5) {
            // 3�� ����: ����
            // ���α׷��� �����ϰ� ����ڿ��� �޽����� ����մϴ�.
            cout << "���α׷��� �����մϴ�." << endl;
            break; // while ���� ����
        }
        else {
            // �߸��� �Է� ó��
            // �޴��� ���� ��ȣ�� �Է����� ��� ��� �޽����� ����մϴ�.
            cout << "�߸��� �Է��Դϴ�. �ٽ� �õ��ϼ���." << endl;
        }
    }

    return 0; // ���α׷� ���� ����
}