/**
 * App.cpp
 * Author   Raul Aguilar
 * Date     December 3, 2020
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
    inputStaffMembers();
    member1.printAttributes();
    cout << "--- --- --- --- --- ---" << endl;
    member2.printAttributes();

}

void App::inputStaffMembers() {
    if(askToInputStaffMember()) {
        member1 = addStaffManual();
        if(askToSaveToFile()) {
            saveToFile(member1);
        }
    } else {
        member1 = addStaffFile();
    }

    if(askToInputStaffMember()) {
        member2 = addStaffManual();
        // Save second staff member to txt file and binary file
        if(askToSaveToFile()) {
            saveToFile(member2);
        }
    } else {
        member2 = addStaffFile();
    }

    cout << " ! -- CONGRATULATIONS -- ! " << endl;
}

void App::inputPlayers() {

}

bool App::askToInputStaffMember() {
    cout << "How would you like to load in the staff member?\n";
    cout << "1. Enter manually\n"
         << "2. Load a file\n";
    cout << "Select an option:" << endl;
    int choice;
    cin >> choice;
    while(choice < 1 || choice > 2) {
        cout << "Invalid menu option. Please make a different selection.\n";
        cout << "1. Enter manually\n"
             << "2. Load a file" << endl;
        cin >> choice;
    }
    cin.ignore();
    return choice == 1;
}

bool App::askToSaveToFile() {
    cout << "Would you like to save the staff member to a file? (Y / N)" << endl;
    char answer[4]; // @Incomplete: handle out of bounds
    cin.ignore();
    cin.getline(answer, 4);
    return (answer[0] == 'Y' || answer[0] == 'y');
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

        cout << "Re-enter? (Y/N)" << endl;
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
    short int attacking, defending, fitness, mental, tactical, technical, workingWithYoungsters;
    dataFile.read(reinterpret_cast<char*>(&attacking), sizeof(short int));
    dataFile.read(reinterpret_cast<char*>(&defending), sizeof(short int));
    dataFile.read(reinterpret_cast<char*>(&fitness), sizeof(short int));
    dataFile.read(reinterpret_cast<char*>(&mental), sizeof(short int));
    dataFile.read(reinterpret_cast<char*>(&tactical), sizeof(short int));
    dataFile.read(reinterpret_cast<char*>(&technical), sizeof(short int));
    dataFile.read(reinterpret_cast<char*>(&workingWithYoungsters), sizeof(short int));
    staff.setCoaching(attacking, defending, fitness, mental, tactical, technical, workingWithYoungsters);

    // Medical
    short int physiotherapy, sportsScience;
    dataFile.read(reinterpret_cast<char*>(&physiotherapy), sizeof(short int));
    dataFile.read(reinterpret_cast<char*>(&sportsScience), sizeof(short int));
    staff.setMedical(physiotherapy, sportsScience);

    // GK Coaching
    short int gkDistribution, gkHandling, gkShotStop;
    dataFile.read(reinterpret_cast<char*>(&gkDistribution), sizeof(short int));
    dataFile.read(reinterpret_cast<char*>(&gkHandling), sizeof(short int));
    dataFile.read(reinterpret_cast<char*>(&gkShotStop), sizeof(short int));
    staff.setGoalKeeping(gkDistribution, gkHandling, gkShotStop);

    // Mental
    short int adaptability, determination, discipline, manManagement, motivating;
    dataFile.read(reinterpret_cast<char*>(&adaptability), sizeof(short int));
    dataFile.read(reinterpret_cast<char*>(&determination), sizeof(short int));
    dataFile.read(reinterpret_cast<char*>(&discipline), sizeof(short int));
    dataFile.read(reinterpret_cast<char*>(&manManagement), sizeof(short int));
    dataFile.read(reinterpret_cast<char*>(&motivating), sizeof(short int));
    staff.setMental(adaptability, determination, discipline, manManagement, motivating);

    // Scouting
    short int judgingPlayerData, judgingTeamData, presentingData;
    dataFile.read(reinterpret_cast<char*>(&judgingPlayerData), sizeof(short int));
    dataFile.read(reinterpret_cast<char*>(&judgingTeamData), sizeof(short int));
    dataFile.read(reinterpret_cast<char*>(&presentingData), sizeof(short int));
    staff.setScouting(judgingPlayerData, judgingTeamData, presentingData);

    // Knowledge
    short int judgingAbility, judgingPotential, judgingStaffAbility, negotiating, tacticalKnowledge;
    dataFile.read(reinterpret_cast<char*>(&judgingAbility), sizeof(short int));
    dataFile.read(reinterpret_cast<char*>(&judgingPotential), sizeof(short int));
    dataFile.read(reinterpret_cast<char*>(&judgingStaffAbility), sizeof(short int));
    dataFile.read(reinterpret_cast<char*>(&negotiating), sizeof(short int));
    dataFile.read(reinterpret_cast<char*>(&tacticalKnowledge), sizeof(short int));

    dataFile.close();
    return staff;
}


void App::saveToFile(Staff& staff) {
    staff.saveToFile();
    staff.saveToBinary();
    cout << staff.getName() << " saved to file." << endl;
}

bool App::validateAnswer() {
    char answer[4]; // @Incomplete: handle out of bounds
    cin.ignore();
    cin.getline(answer, 4);
    return !(answer[0] == 'Y' || answer[0] == 'y');
}

void App::manualCoachingInput(Staff& staff) {
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

void App::inputMedical(Staff& staff) {
    short int physio, sportsSci;
    cout << "Physiotherapy:";
    cin >> physio;
    cout << "Sports Science:";
    cin >> sportsSci;
    staff.setMedical(physio, sportsSci);
}

void App::inputGKCoaching(Staff& staff) {
    short int gkDistribution, gkHandling, gkShotStop;
    cout << "GK Distribution:" << endl;
    cin >> gkDistribution;
    cout << "GK Handling:";
    cin >> gkHandling;
    cout << "GK Shot Stopping:";
    cin >> gkShotStop;
    staff.setGoalKeeping(gkDistribution, gkHandling, gkShotStop);
}

void App::inputMental(Staff& staff) {
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

void App::inputScouting(Staff& staff) {
    short int judgingPlayerData, judgingTeamData, presentingData;
    cout << "Judging Player Data:" << endl;
    cin >> judgingPlayerData;
    cout << "Judging Team Data:";
    cin >> judgingTeamData;
    cout << "Presenting Data:";
    cin >> presentingData;
    staff.setScouting(judgingPlayerData, judgingTeamData, presentingData);
}

void App::inputKnowledge(Staff& staff) {
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