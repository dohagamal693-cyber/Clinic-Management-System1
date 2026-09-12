#include "person.cpp"
#include "visit.cpp"
#include "waitingRoom.cpp"

struct DoctorNode {
    Doctor doctor;
    DoctorNode* next;
    DoctorNode(Doctor d) : doctor(d), next(nullptr) {}
};

struct VisitNode {
    Visit visit;
    VisitNode* next;
    VisitNode(Visit v) : visit(v), next(nullptr) {}
};

class ClinicSystem {
private:
    DoctorNode* doctorsHead;
    VisitNode* visitsHead;
    WaitingRoom waitingRoom;
    int nextVisitId;

public:
    ClinicSystem() : doctorsHead(nullptr), visitsHead(nullptr), nextVisitId(1) {}

    ~ClinicSystem() {
        while (doctorsHead != nullptr) {
            DoctorNode* temp = doctorsHead;
            doctorsHead = doctorsHead->next;
            delete temp;
        }
        while (visitsHead != nullptr) {
            VisitNode* temp = visitsHead;
            visitsHead = visitsHead->next;
            delete temp;
        }
    }

    void addDoctor() {
        int id;
        string name, spec;
        cout << "Enter Doctor ID: ";
        cin >> id;
        cin.ignore(1000, '\n');

        cout << "Enter Doctor Name: ";
        getline(cin, name);

        cout << "Enter Specialization: ";
        getline(cin, spec);

        Doctor d(id, name, spec);
        DoctorNode* newNode = new DoctorNode(d);
        newNode->next = doctorsHead;
        doctorsHead = newNode;

        cout << "Doctor added successfully!\n";
    }

    void addPatientToQueue() {
        int id, age, priority;
        string name, phone;

        cout << "Enter Patient ID: ";
        cin >> id;
        cin.ignore(1000, '\n');

        cout << "Enter Patient Name: ";
        getline(cin, name);

        cout << "Enter Age: ";
        cin >> age;
        cin.ignore(1000, '\n');

        cout << "Enter Phone: ";
        getline(cin, phone);

        cout << "Enter Priority Level (1-Normal, 5-Emergency): ";
        cin >> priority;
        cin.ignore(1000, '\n');

        Patient p(id, name, age, phone);
        waitingRoom.enqueue(p, priority);
    }

    void serveNextPatient() {
        if (waitingRoom.isEmpty()) {
            cout << "No patients in the waiting room.\n";
            return;
        }
        if (doctorsHead == nullptr) {
            cout << "No doctors registered in the system yet. Please add a doctor first.\n";
            return;
        }

        Patient p;
        waitingRoom.dequeue(p);

        cout << "\nServing Patient: " << p.getName() << endl;
        cout << "Available Doctors:\n";
        displayDoctors();

        int docId;
        cout << "Assign to Doctor ID: ";
        cin >> docId;
        cin.ignore(1000, '\n');

        string date, diag;
        cout << "Enter Visit Date (e.g., 2026-09-12): ";
        getline(cin, date);

        cout << "Enter Diagnosis: ";
        getline(cin, diag);

        Visit v(nextVisitId++, p.getId(), docId, date, diag);
        VisitNode* newNode = new VisitNode(v);
        newNode->next = visitsHead;
        visitsHead = newNode;

        cout << "Visit recorded successfully!\n";
    }

    void displayDoctors() const {
        if (doctorsHead == nullptr) {
            cout << "No doctors registered.\n";
            return;
        }
        DoctorNode* temp = doctorsHead;
        while (temp != nullptr) {
            temp->doctor.displayInfo();
            temp = temp->next;
        }
    }

    void displayVisits() const {
        if (visitsHead == nullptr) {
            cout << "No visit records found.\n";
            return;
        }
        VisitNode* temp = visitsHead;
        while (temp != nullptr) {
            temp->visit.displayVisit();
            temp = temp->next;
        }
    }

    void run() {
        int choice;
        do {
            cout << "\n===== CLINIC MANAGEMENT SYSTEM =====\n";
            cout << "1. Add Doctor\n";
            cout << "2. Add Patient to Waiting Room\n";
            cout << "3. Serve Next Patient\n";
            cout << "4. View Waiting Queue\n";
            cout << "5. View All Doctors\n";
            cout << "6. View All Visits\n";
            cout << "7. Exit\n";
            cout << "Enter your choice: ";
            cin >> choice;
            cin.ignore(1000, '\n');

            switch (choice) {
                case 1: addDoctor(); break;
                case 2: addPatientToQueue(); break;
                case 3: serveNextPatient(); break;
                case 4: waitingRoom.displayQueue(); break;
                case 5: displayDoctors(); break;
                case 6: displayVisits(); break;
                case 7: cout << "Exiting system...\n"; break;
                default: cout << "Invalid choice!\n";
            }
        } while (choice != 7);
    }
};
