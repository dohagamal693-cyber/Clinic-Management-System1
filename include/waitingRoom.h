#include "person.cpp"

struct PatientNode {
    Patient patient;
    int priority;
    PatientNode* next;
    PatientNode(Patient p, int prio) : patient(p), priority(prio), next(nullptr) {}
};

class WaitingRoom {
private:
    PatientNode* head;
public:
    WaitingRoom() : head(nullptr) {}
    ~WaitingRoom() {
        while (head != nullptr) {
            PatientNode* temp = head;
            head = head->next;
            delete temp;
        }
    }
    void enqueue(const Patient& p, int priority) {
        PatientNode* newNode = new PatientNode(p, priority);
        if (head == nullptr || priority > head->priority) {
            newNode->next = head;
            head = newNode;
        } else {
            PatientNode* current = head;
            while (current->next != nullptr && current->next->priority >= priority) {
                current = current->next;
            }
            newNode->next = current->next;
            current->next = newNode;
        }
        cout << "Patient added to priority waiting room successfully.\n";
    }
    bool dequeue(Patient& p) {
        if (isEmpty()) return false;
        PatientNode* temp = head;
        p = temp->patient;
        head = head->next;
        delete temp;
        return true;
    }
    bool isEmpty() const { return head == nullptr; }
    void displayQueue() const {
        if (isEmpty()) {
            cout << "Waiting room is currently empty.\n";
            return;
        }
        cout << "\n--- Current Waiting Queue (By Priority) ---\n";
        PatientNode* temp = head;
        while (temp != nullptr) {
            temp->patient.displayInfo();
            cout << "   Priority Level: " << temp->priority << "\n";
            temp = temp->next;
        }
    }
};
