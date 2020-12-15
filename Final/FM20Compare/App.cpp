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

bool App::askToLoadPerson(const string &type) {
    cout << "How would you like to load in the " + type + "?\n";
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
    return (answer[0] == 'Y' || answer[0] == 'y');
}

void App::compareStaff() {
    Staff member1, member2;
    addStaffMember(member1);
    addStaffMember(member2);
    cout << " ! -- STAFF COMPARISON -- ! " << endl;
    member1.printAttributes();
    cout << "--- --- --- --- --- ---" << endl;
    member2.printAttributes();
    comparison(member1, member2);
}

void App::comparePlayers() {
    Player player1, player2;
    addPlayer(player1);
    addPlayer(player2);
    cout << " ! -- PLAYER COMPARISON -- ! " << endl;
    player1.printAttributes();
    cout << "--- --- --- --- --- ---" << endl;
    player2.printAttributes();
    comparison(player1, player2);
}

template<class T>
void App::comparison(const T &person1, const T &person2) {
    person1.compare(person2);
}

void App::addStaffMember(Staff& staff) {
    if(askToLoadPerson("staff member")) {
        setStaffManual(staff);
        if(askToSaveToFile()) {
            saveToFile(staff);
        }
    } else {
        loadFromFile(staff);
    }
}

void App::addPlayer(Player& player) {
    if(askToLoadPerson("player")) {
        setPlayerManual(player);
        if(askToSaveToFile()) {
            saveToFile(player);
        }
    } else {
        loadFromFile(player);
    }
}

void App::setStaffManual(Staff &staff)
{
    inputPersonalInfo(staff);

    //
    // @Incomplete: Restrict entries to 1-20
    //
    cout << "\nNow set the attributes for " << staff.getName() << endl;
    inputCoaching(staff);
    inputMedical(staff);
    inputGKCoaching(staff);
    inputMental(staff);
    inputScouting(staff);
    inputKnowledge(staff);

}

template<class T>
void App::inputPersonalInfo(T &person) {
    bool reenter = true;

    string nation, name, role, club;
    int age;
    cout << "Enter the following information:\n";
    while(reenter) {
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
        reenter = validateAnswer();
    }

    person.setNation(nation);
    person.setName(name);
    person.setAge(age);
    person.setRole(role);
    person.setClub(club);
}

void App::inputCoaching(Staff &staff) {
    bool reenter = true;
    int numAttr = 7;
    string attribute[] = {
            "Attacking:", "Defending:", "Fitness:", "Mental:", "Tactical:",
            "Technical:", "Working With Youngsters:",
    };
    short values[numAttr];
    while(reenter){
        for(int i = 0; i < numAttr; i++) {
            cout << attribute[i] << endl;
            cin >> values[i];
        }
        reenter = validateAnswer();
    }
    staff.setCoaching(values[0], values[1], values[2], values[3], values[4], values[5], values[6]);
}

void App::inputMedical(Staff &staff) {
    bool reenter = true;
    int numAttr = 2;
    string attribute[] = {
            "Physiotherapy:", "Sports Science:"
    };
    short values[numAttr];
    while(reenter){
        for(int i = 0; i < numAttr; i++) {
            cout << attribute[i] << endl;
            cin >> values[i];
        }
        reenter = validateAnswer();
    }
    staff.setMedical(values[0], values[1]);
}

void App::inputGKCoaching(Staff &staff) {
    bool reenter = true;
    int numAttr = 3;
    string attribute[] = {
            "GK Distribution:", "GK Handling:", "GK Shot Stop:"
    };
    short values[numAttr];
    while(reenter){
        for(int i = 0; i < numAttr; i++) {
            cout << attribute[i] << endl;
            cin >> values[i];
        }
        reenter = validateAnswer();
    }
    staff.setGoalKeeping(values[0], values[1], values[2]);
}

void App::inputMental(Staff &staff) {
    bool reenter = true;
    int numAttr = 5;
    string attribute[] = {
            "Adaptability:", "Determination:", "Level of Discipline:", "Man Management:",
            "Motivating:"
    };
    short values[numAttr];
    while(reenter){
        for(int i = 0; i < numAttr; i++) {
            cout << attribute[i] << endl;
            cin >> values[i];
        }
        reenter = validateAnswer();
    }
    staff.setMental(values[0], values[1], values[2], values[3], values[4]);
}

void App::inputScouting(Staff &staff) {
    bool reenter = true;
    int numAttr = 3;
    string attribute[] = {
            "Judging Player Data:", "Judging Team Data:", "Presenting Data:"
    };
    short values[numAttr];
    while(reenter){
        for(int i = 0; i < numAttr; i++) {
            cout << attribute[i] << endl;
            cin >> values[i];
        }
        reenter = validateAnswer();
    }
    staff.setScouting(values[0], values[1], values[2]);
}

void App::inputKnowledge(Staff &staff) {
    bool reenter = true;
    int numAttr = 5;
    string attribute[] = {
            "Judging Ability:", "Judging Potential:", "Judging Staff Ability:",
            "Negotiating:", "Tactical Knowledge:"
    };
    short values[numAttr];
    while(reenter){
        for(int i = 0; i < numAttr; i++) {
            cout << attribute[i] << endl;
            cin >> values[i];
        }
        reenter = validateAnswer();
    }
    staff.setKnowledge(values[0], values[1], values[2], values[3], values[4]);
}

void App::setPlayerManual(Player &player)
{
    inputPersonalInfo(player);

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

//
// File Operations
//
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

    person.loadBinary(dataFile);
    dataFile.close();
}