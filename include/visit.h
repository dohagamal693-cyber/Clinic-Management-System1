#ifndef VISIT_H
#define VISIT_H

#include <iostream>
#include <string>
using namespace std;

class Visit {
private:
    int visitId;
    int patientId;
    int doctorId;
    string date;
    string diagnosis;
public:
    Visit(int vId = 0, int pId = 0, int dId = 0, string d = "", string diag = "")
        : visitId(vId), patientId(pId), doctorId(dId), date(d), diagnosis(diag) {}
    int getVisitId() const { return visitId; }
    int getPatientId() const { return patientId; }
    int getDoctorId() const { return doctorId; }
    string getDate() const { return date; }
    string getDiagnosis() const { return diagnosis; }
    void displayVisit() const {
        cout << "Visit ID: " << visitId << " | Patient ID: " << patientId 
             << " | Doctor ID: " << doctorId << " | Date: " << date 
             << " | Diagnosis: " << diagnosis << endl;
    }
};

#endif
