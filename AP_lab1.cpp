#include <iostream>
#include <string>

using namespace std;

struct Node {
    char data;
    Node* next;

    Node(char val) : data(val), next(nullptr) {}
};

class CircularLinkedList {
private:
    Node* head;
public:
    CircularLinkedList() : head(nullptr) {}

    // ������ ������� � ����� ������
    void append(char val) {
        Node* newNode = new Node(val);
        if (!head) {
            head = newNode;
            head->next = head;
        }
        else {
            Node* temp = head;
            while (temp->next != head) {
                temp = temp->next;
            }
            temp->next = newNode;
            newNode->next = head;
        }
    }

    // �������� �� ����� "P" ����� ������ "A"
    void remove_P_before_A() {
        if (!head) return;
        Node* current = head;
        do {
            if (current->data == 'A' && current->next->data == 'P') {
                Node* temp = current->next;
                current->next = temp->next;
                delete temp;
                // ϳ��� ���������, ����������, �� ���������� ������� �� � 'P'
                // ���� ���, ������������� �������� head
                if (current->next == head)
                    head = current->next->next;
            }
            else {
                current = current->next;
            }
        } while (current->next != head);
    }

    // ������� ������
    void print() {
        if (!head) {
            cout << "Empty list" << endl;
            return;
        }
        Node* temp = head;
        do {
            cout << temp->data << "";
            temp = temp->next;
        } while (temp != head);
        cout << endl;
    }

    // ��������� ������ �� �����
    void createListFromString(const string& str) {
        for (char ch : str) {
            append(ch);
        }
    }
};

int main() {
    CircularLinkedList list;
    string input;

    cout << "Enter a string: ";
    getline(cin, input);

    // ��������� ������ �� ��������� �����
    list.createListFromString(input);

    cout << "Start list: ";
    list.print();

    // ��������� 'P' ����� 'A'
    list.remove_P_before_A();

    cout << "List after deliting: ";
    list.print();

    return 0;
}