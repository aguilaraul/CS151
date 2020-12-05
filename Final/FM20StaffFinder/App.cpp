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
    Staff member1, member2;
    inputStaffMembers(member1, member2);
    //staffComparison(member1, member2);
    member1.printAttributes();
    cout << "--- --- --- --- --- ---" << endl;
    member2.printAttributes();

}

void App::comparePlayers() {
    Player player1, player2;
}

void App::inputStaffMembers(Staff& member1, Staff& member2) {
    if(askToInputStaffMember()) {
        setStaffManual(member1);
        if(askToSaveToFile()) {
            saveToFile(member1);
        }
    } else {
        addStaffFile(member1);
    }

//    if(askToInputStaffMember()) {
//        setStaffManual(member2);
//        if(askToSaveToFile()) {
//            saveToFile(member2);
//        }
//    } else {
//        addStaffFile(member2);
//    }

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

bool App::validateAnswer() {
    char answer[4]; // @Incomplete: handle out of bounds
    cin.ignore();
    cin.getline(answer, 4);
    return !(answer[0] == 'Y' || answer[0] == 'y');
}

void App::setStaffManual(Staff &member) {
    bool continue_ = false;

    string nation, name, role, club;
    int age;
    cout << "Enter the following information about the staff member:\n";

    //
    // @Incomplete: Make its own function. Add validation to other categories?
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
    member.setNation(nation);
    member.setName(name);
    member.setAge(age);
    member.setRole(role);
    member.setClub(club);

    //
    // @Incomplete: Restrict entries to 1-20
    //
    cout << "\nNow set the attributes for " << member.getName() << endl;
    string attribute[25] = {
            "Attacking: ", "Defending: ", "Fitness: ", "Mental: ", "Tactical: ",
            "Technical: ", "Working With Youngsters: ",
            "Physiotherapy", "Sports Science",
            "GK Distribution", "GK Handling", "GK Shot Stop",
            "Adaptability", "Determination", "Level of Discipline", "Man Management",
            "Motivating",
            "Judging Player Data", "Judging Team Data", "Presenting Data",
            "Judging Ability", "Judging Potential", "Judging Staff Ability",
            "Negotiating", "Tactical Knowledge"
    };
    short int att[25] = {};
    for(int i = 0; i < 25; i++) {
        cout << attribute[i] << endl;
        cin >> att[i];
    }

    member.setCoaching(att[0], att[1], att[2], att[3], att[4], att[5], att[6]);
    member.setMedical(att[7], att[8]);
    member.setGoalKeeping(att[9], att[10], att[11]);
    member.setMental(att[12], att[13], att[14], att[15], att[16]);
    member.setScouting(att[17],att[18],att[19]);
    member.setKnowledge(att[20], att[21], att[22], att[23], att[24]);
}

void App::saveToFile(Staff& staff) {
    staff.saveToFile();
    staff.saveToBinary();
    cout << staff.getName() << " saved to file." << endl;
}

void App::addStaffFile(Staff& member) {
    string fileName;
    cout << "Please enter the name of the file:" << endl;
    getline(cin, fileName);

    fstream dataFile(fileName, ios::binary | ios::in);
    if(!dataFile) {
        cout << "Failed to open input file. Program exiting.";
        exit(1);
    } //@Incomplete make exception

    member.readFromBinary(dataFile);
}

void App::staffComparison(Staff &member1, Staff &member2) {

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