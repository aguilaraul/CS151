/**
 * App.cpp
 * Author   Raul Aguilar
 * Date     December 12, 2020
 * CS 151 3228 Final Project
 */
#include "App.h"
using namespace std;

void App::run() {
    switch(getMenuOption()) {
        case 1:
            compareStaff();
            break;
        case 2:
            comparePlayers();
            break;
        default:
            exit(0);
    }
}

App::~App() = default;

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
    inputStaffMember(member1);
    inputStaffMember(member2);
    cout << " ! -- STAFF COMPARISON -- ! " << endl;
    member1.printAttributes();
    cout << "--- --- --- --- --- ---" << endl;
    member2.printAttributes();
    comparison(member1, member2);
}

void App::comparePlayers() {
    Player player1, player2;
    inputPlayer(player1);
    inputPlayer(player2);
    cout << " ! -- PLAYER COMPARISON -- ! " << endl;
    player1.printAttributes();
    cout << "--- --- --- --- --- ---" << endl;
    player2.printAttributes();
    comparison(player1, player2);
}

void App::inputStaffMember(Staff& member) {
    if(askToInputStaffMember()) {
        setStaffManual(member);
        if(askToSaveToFile()) {
            saveToFile(member);
        }
    } else {
        loadFromFile(member);
    }
}

void App::inputPlayer(Player& player) {
    // Input Player1
    if(askToInputStaffMember()) {
        setPlayerManual(player);
        if(askToSaveToFile()) {
            saveToFile(player);
        }
    } else {
        loadFromFile(player);
    }
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
    cout << "Would you like to save the person to a file? (Y / N)" << endl;
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

void App::setStaffManual(Staff &member)
{
    bool continue_ = false;

    string nation, name, role, club;
    int age;
    cout << "Enter the following information about the staff member:\n";

    //
    // @Incomplete: Make its own function. Add validation to other categories?
    //
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
    string attribute[] = {
            "Attacking:", "Defending:", "Fitness:", "Mental:", "Tactical:",
            "Technical:", "Working With Youngsters:",
            "Physiotherapy:", "Sports Science:",
            "GK Distribution:", "GK Handling:", "GK Shot Stop:",
            "Adaptability:", "Determination:", "Level of Discipline:", "Man Management:",
            "Motivating:",
            "Judging Player Data:", "Judging Team Data:", "Presenting Data:",
            "Judging Ability:", "Judging Potential:", "Judging Staff Ability:",
            "Negotiating:", "Tactical Knowledge:"
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

void App::setPlayerManual(Player &player)
{
    bool continue_ = false;

    string nation, name, role, club;
    int age;
    cout << "Enter the following information about the staff member:\n";

    //
    // @Incomplete: Make its own function. Add validation to other categories?
    //
    while(!continue_) {
        cout << "Nation:";
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
    player.setNation(nation);
    player.setName(name);
    player.setAge(age);
    player.setRole(role);
    player.setClub(club);

    //
    // @Incomplete: Restrict entries to 1-20
    //
    cout << "\nNow set the attributes for " << player.getName() << endl;
    string attribute[] = {
            // Technical
            "Corners:", "Crossing:", "Dribbling:", "Finishing:", "First Touch:", "Free Kick:",
            "Heading", "Long Shots:", "Long Throws:", "Marking:", "Passing:", "Penalty Taking:",
            "Tackling", "Technical:",
            // Mental
            "Aggression:", "Anticipation:", "Bravery:", "Composure:", "Concentration:", "Decisions",
            "Determination:", "Flair:", "Leadership:", "Off the Ball:", "Positioning:", "Teamwork:",
            "Vision", "Work Rate:",
            // Physical
            "Acceleration:", "Agility:", "Balance:", "Jumping Reach:", "Natural Fitness:", "Pace:",
            "Stamina:", "Strength:"
    };
    short int att[36] = {};
    for(int i = 0; i < 36; i++) {
        cout << attribute[i] << endl;
        cin >> att[i];
    }

    player.setTechnical(att[0], att[1], att[2], att[3], att[4], att[5], att[6], att[7], att[8],
                        att[9], att[10], att[11], att[12], att[13]);
    player.setMental(att[14], att[15], att[16], att[17], att[18], att[19], att[20], att[21], att[22],
                     att[23], att[24], att[25], att[26], att[27]);
    player.setPhysical(att[28], att[29], att[30], att[31], att[32], att[33], att[34], att[35]);
}

template<class T>
void App::saveToFile(T &person) {
    person.saveToFile();
    person.saveToBinary();
    cout << person.getName() << " saved to file." << endl;
}

template<class T>
void App::loadFromFile(T &person) {
    string fileName;
    cout << "Please enter the name of the .dat file:" << endl;
    getline(cin, fileName);
    fstream dataFile(fileName, ios::binary | ios::in);
    if(!dataFile) {
        cout << "Failed to open input file. Program exiting.";
        exit(1);
    } //@Incomplete make exception

    person.readFromBinary(dataFile);
    dataFile.close();
}

template<class T>
void App::comparison(const T &person1, const T &person2) {
    person1.compare(person2);
}