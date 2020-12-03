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
    cin.ignore();
    return choice;
}

void App::inputStaffMembers() {
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

    cin.ignore();
    if(choice == 1) {
        member1 = addStaffManual();
        // Save first staff member to txt file and binary file
        cout << "Would you like to save the staff member to a file?";
        if(validateAnswer()) {
            saveToFile(member1);
        }
    } else {
        member1 = addStaffFile();
    }

    // Enter second staff member
    cout << "How would you like to load in the second staff member?\n";
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
        // Save second staff member to txt file and binary file
        cin.ignore();
        cout << "Would you like to save the staff member to a file?";
        if(validateAnswer()) {
            saveToFile(member2);
        }
    } else {
        member2 = addStaffFile();
    }
}

void App::inputPlayers() {

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

    manualCoachingInput(staff);
    inputMedical(staff);
    inputGKCoaching(staff);
    inputMental(staff);
    inputScouting(staff);
    inputKnowledge(staff);

    return staff;
}

Staff App::addStaffFile() {
    string fileName;
    cout << "Please enter the name of the file:" << endl;
    getline(cin, fileName);

    fstream dataFile(fileName, ios::binary | ios::in);
    if(!dataFile) {
        cout << "Failed to open input file. Program exiting.";
        exit(1);
    } //@Incomplete make exception

    // Staff initialization
    string nation, name, role, club;
    int age;
    dataFile.read(reinterpret_cast<char*>(&nation), sizeof(string));
    dataFile.read(reinterpret_cast<char*>(&name), sizeof(string));
    dataFile.read(reinterpret_cast<char*>(&age), sizeof(int));
    dataFile.read(reinterpret_cast<char*>(&role), sizeof(string));
    dataFile.read(reinterpret_cast<char*>(&club), sizeof(string));
    Staff staff(nation, name, age, role, club);

    // Coaching
    //long long position = dataFile.tellg();
    //readCoachingAttributes(staff, dataFile, position);
    short int attacking, defending, fitness, mental, tactical, technical, workingWithYoungsters;
    //dataFile.seekp(position);
    dataFile.read(reinterpret_cast<char*>(&attacking), sizeof(short int));
    dataFile.read(reinterpret_cast<char*>(&defending), sizeof(short int));
    dataFile.read(reinterpret_cast<char*>(&fitness), sizeof(short int));
    dataFile.read(reinterpret_cast<char*>(&mental), sizeof(short int));
    dataFile.read(reinterpret_cast<char*>(&tactical), sizeof(short int));
    dataFile.read(reinterpret_cast<char*>(&technical), sizeof(short int));
    dataFile.read(reinterpret_cast<char*>(&workingWithYoungsters), sizeof(short int));
    staff.setCoaching(attacking, defending, fitness, mental, tactical, technical, workingWithYoungsters);

    staff.printAttributes();
    dataFile.close();
    return {};
}


void App::saveToFile(Staff staff) {
    staff.saveToFile();
    staff.saveToBinary();
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

void App::manualCoachingInput(Staff staff) {
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
    cout << "Man Management:";
    cin >> manManagement;
    cout << "Motivating:";
    cin >> motivating;
    staff.setMental(adaptability, determination, discipline, manManagement, motivating);
}

void App::inputScouting(Staff staff) {
    short int judgingPlayerData, judgingTeamData, presentingData;
    cout << "Judging Player Data:" << endl;
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
    cout << "Tactical Knowledge:" << endl;
    cin >> tacticalKnowledge;
    staff.setKnowledge(judgingAbility, judgingPotential, judgingStaffAbility, negotiating, tacticalKnowledge);
}

void App::readCoachingAttributes(Staff staff, fstream &dataFile, long long &position) {
    short int attacking, defending, fitness, mental, tactical, technical, workingWithYoungsters;
    dataFile.seekp(position);
    dataFile.read(reinterpret_cast<char*>(&attacking), sizeof(short int));
    dataFile.read(reinterpret_cast<char*>(&defending), sizeof(short int));
    dataFile.read(reinterpret_cast<char*>(&fitness), sizeof(short int));
    dataFile.read(reinterpret_cast<char*>(&mental), sizeof(short int));
    dataFile.read(reinterpret_cast<char*>(&tactical), sizeof(short int));
    dataFile.write(reinterpret_cast<char*>(&technical), sizeof(short int));
    dataFile.write(reinterpret_cast<char*>(&workingWithYoungsters), sizeof(short int));
    staff.setCoaching(attacking, defending, fitness, mental, tactical, technical, workingWithYoungsters);
    position = dataFile.tellg();
}