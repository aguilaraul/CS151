/**
 * App.cpp
 * Author   Raul Aguilar
 * Date     November 17, 2020
 * CS 151 3228 Final Project
 */
#include "App.h"
using namespace std;

int App::getMenuOption() {
    cout << "1. Compare two staff members\n"
         << "2. Compare two players\n";
    cout << "Select an option:" << endl;
    int choice;
    cin >> choice;
    while(choice < 1 || choice > 2) {
        cout << "Invalid menu option. Please make a different selection.\n";
        cout << "1. Compare two staff members\n"
             << "2. Compare two players\n";
        cin >> choice;
    }
    return choice;
}

void App::compareStaff() {
    Staff member1, member2;
    cout << "How would you like to load in the staff member?\n";
    cout << "1. Enter manually\n"
         << "2. Load a file\n";
    cout << "Select an option:" << endl;
    int choice;
    cin >> choice;
    while(choice < 1 || choice > 2) {
        cout << "Invalid menu option. Please make a different selection.\n";
        cout << "1. Enter manually\n"
             << "2. Load a file\n";
        cin >> choice;
    }
    if(choice == 1) {
        member1 = addStaffManual();
    } else {
        member1 = addStaffFile();
    }

    // Save first staff member to txt file and binary file
    cout << "Would you like to save the staff member to a file?";
    if(validateAnswer()) {
        saveToFile(member1);
    }

    // Enter second staff member
    cout << "How would you like to load in the second staff member?";
    cout << "1. Enter manually\n"
         << "2. Load a file\n";
    cout << "Select an option:" << endl;
    cin >> choice;
    while(choice < 1 || choice > 2) {
        cout << "Invalid menu option. Please make a different selection.\n";
        cout << "1. Enter manually\n"
             << "2. Load a file\n";
        cin >> choice;
    }
    if(choice == 1) {
        member2 = addStaffManual();
    } else {
        member2 = addStaffFile();
    }

    // Save second staff member to txt file and binary file
    cout << "Would you like to save the staff member to a file?";
    if(validateAnswer()) {
        saveToFile(member2);
    }
}

void App::comparePlayers() {

}

Staff App::addStaffManual() {
    bool continue_ = false;

    string nation, name, role, club;
    int age;
    cout << "Enter the following information about the staff member:\n";

    while(!continue_) {
        cout << "Nation:";
        cin.ignore();
        getline(cin, nation);
        cout << "Name:";
        getline(cin, name);
        cout << "Age:"; // @Incomplete: Add exception to handle non-numbers
        cin >> age;
        cout << "Role:";
        cin.ignore();
        getline(cin, role);
        cout << "Club:";
        getline(cin, club);

        continue_ = validateAnswer();

    }
    Staff staff(nation, name, age, role, club);

    // Coaching Attributes
    //
    // @Incomplete: Restrict entries to 1-20
    //
    cout << "\nNow set the attributes for " << staff.getName();

    inputCoaching(staff);
    inputMedical(staff);
    inputGKCoaching(staff);
    inputMental(staff);
    inputScouting(staff);
    inputKnowledge(staff);

    return staff;
}

Staff App::addStaffFile() {
    return {};
}


void App::saveToFile(Staff staff) {
    string fileName = staff.getName() + ".txt";
    ofstream outfile(fileName, ios::out);
    outfile << "Nation: " << staff.getNation() << endl;
    outfile << left << setw(6) << "Name:";
    outfile << setw(25) << staff.getName();
    outfile << right << setw(10) << "Role: " << staff.getRole() << endl;

    outfile << left << setw(6) << "Age: ";
    outfile << setw(25) << staff.getAge();
    outfile << right << setw(10) << "Club: " << staff.getClub() << endl;


    outfile.close();
}

bool App::validateAnswer() {
    char answer[4]; // @Incomplete: handle out of bounds
    cout << "Re-enter information? (Y/N)";
    cin.getline(answer, 4);
    if(answer[0] == 'Y' || answer[0] == 'y') {
        return false;
    } else {
        return true;
    }
}

void App::inputCoaching(Staff staff) {
    short int attack, defend, fitness, mental, tactical, technical, workingWithYoungsters;
    cout << "\nAttacking:";
    cin >> attack;
    cout << "Defending:";
    cin >> defend;
    cout << "Fitness:";
    cin >> fitness;
    cout << "Mental:";
    cin >> mental;
    cout << "Tactical:";
    cin >> tactical;
    cout << "Technical:";
    cin >> technical;
    cout << "Working With Youngsters:";
    cin >> workingWithYoungsters;
    staff.setCoaching(attack, defend, fitness, mental, tactical, technical, workingWithYoungsters);
}

void App::inputMedical(Staff staff) {
    short int physio, sportsSci;
    cout << "Physiotherapy:";
    cin >> physio;
    cout << "Sports Science:";
    cin >> sportsSci;
    staff.setMedical(physio, sportsSci);
}

void App::inputGKCoaching(Staff staff) {
    short int gkDistribution, gkHandling, gkShotStop;
    cout << "GK Distribution:";
    cin >> gkDistribution;
    cout << "GK Handling:";
    cin >> gkHandling;
    cout << "GK Shot Stopping:";
    cin >> gkShotStop;
    staff.setGoalKeeping(gkDistribution, gkHandling, gkShotStop);
}

void App::inputMental(Staff staff) {
    short int adaptability, determination, discipline, manManagement, motivating;
    cout << "Adaptability:";
    cin >> adaptability;
    cout << "Determination:";
    cin >> determination;
    cout << "Level of Discipline:";
    cin >> discipline;
    cout << "Man Management";
    cin >> manManagement;
    cout << "Motivating:";
    cin >> motivating;
    staff.setMental(adaptability, determination, discipline, manManagement, motivating);
}

void App::inputScouting(Staff staff) {
    short int judgingPlayerData, judgingTeamData, presentingData;
    cout << "Judging Player Data:";
    cin >> judgingPlayerData;
    cout << "Judging Team Data:";
    cin >> judgingTeamData;
    cout << "Presenting Data:";
    cin >> presentingData;
    staff.setScouting(judgingPlayerData, judgingTeamData, presentingData);
}

void App::inputKnowledge(Staff staff) {
    short int judgingAbility, judgingPotential, judgingStaffAbility,
            negotiating, tacticalKnowledge;
    cout << "Judging Ability:";
    cin >> judgingAbility;
    cout << "Judging Potential:";
    cin >> judgingPotential;
    cout << "Judging Staff Ability:";
    cin >> judgingStaffAbility;
    cout << "Negotiating:";
    cin >> negotiating;
    cout << "Tactical Knowledge:";
    cin >> tacticalKnowledge;
    staff.setKnowledge(judgingAbility, judgingPotential, judgingStaffAbility,
                       negotiating, tacticalKnowledge);
}