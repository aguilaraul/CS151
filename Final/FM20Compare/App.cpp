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
    string answer;
    cout << "Would you like to save the person to a file? (Y / N)" << endl;
    cin >> answer;
    return (answer[0] == 'Y' || answer[0] == 'y');
}

bool App::validateAnswer() {
    string answer;
    cout << "Re-enter? (Y / N)" << endl;
    cin >> answer;
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

        reenter = validateAnswer();
    }

    person.setNation(nation);
    person.setName(name);
    person.setAge(age);
    person.setRole(role);
    person.setClub(club);
}

void App::inputCoaching(Staff &staff) {
    AttributeRange attributeRange;
    bool reenter = true;
    bool redo;
    int numAttr = 7;
    string attribute[] = {
            "Attacking:", "Defending:", "Fitness:", "Mental:", "Tactical:",
            "Technical:", "Working With Youngsters:",
    };
    short values[numAttr];
    while(reenter){
        for(int i = 0; i < numAttr; i++) {
            redo = true;
            while(redo) {
                cout << attribute[i] << endl;
                try {
                    values[i] = attributeRange.getAttributeValue();
                    redo = false;
                } catch (AttributeRange::OutOfRange &valueOutOfRange) {
                    cout << "Please enter a value between 1 and 20.\n";
                }
            }

        }
        reenter = validateAnswer();
    }
    staff.setCoaching(values[0], values[1], values[2], values[3], values[4], values[5], values[6]);
}

void App::inputMedical(Staff &staff) {
    AttributeRange attributeRange;
    bool reenter = true;
    bool redo;
    int numAttr = 2;
    string attribute[] = {
            "Physiotherapy:", "Sports Science:"
    };
    short values[numAttr];
    while(reenter){
        for(int i = 0; i < numAttr; i++) {
            redo = true;
            while(redo) {
                cout << attribute[i] << endl;
                try {
                    values[i] = attributeRange.getAttributeValue();
                    redo = false;
                } catch (AttributeRange::OutOfRange &valueOutOfRange) {
                    cout << "Please enter a value between 1 and 20.\n";
                }
            }

        }
        reenter = validateAnswer();
    }
    staff.setMedical(values[0], values[1]);
}

void App::inputGKCoaching(Staff &staff) {
    AttributeRange attributeRange;
    bool reenter = true;
    bool redo;
    int numAttr = 3;
    string attribute[] = {
            "GK Distribution:", "GK Handling:", "GK Shot Stop:"
    };
    short values[numAttr];
    while(reenter){
        for(int i = 0; i < numAttr; i++) {
            redo = true;
            while(redo) {
                cout << attribute[i] << endl;
                try {
                    values[i] = attributeRange.getAttributeValue();
                    redo = false;
                } catch (AttributeRange::OutOfRange &valueOutOfRange) {
                    cout << "Please enter a value between 1 and 20.\n";
                }
            }

        }
        reenter = validateAnswer();
    }
    staff.setGoalKeeping(values[0], values[1], values[2]);
}

void App::inputMental(Staff &staff) {
    AttributeRange attributeRange;
    bool reenter = true;
    bool redo;
    int numAttr = 5;
    string attribute[] = {
            "Adaptability:", "Determination:", "Level of Discipline:", "Man Management:",
            "Motivating:"
    };
    short values[numAttr];
    while(reenter){
        for(int i = 0; i < numAttr; i++) {
            redo = true;
            while(redo) {
                cout << attribute[i] << endl;
                try {
                    values[i] = attributeRange.getAttributeValue();
                    redo = false;
                } catch (AttributeRange::OutOfRange &valueOutOfRange) {
                    cout << "Please enter a value between 1 and 20.\n";
                }
            }

        }
        reenter = validateAnswer();
    }
    staff.setMental(values[0], values[1], values[2], values[3], values[4]);
}

void App::inputScouting(Staff &staff) {
    AttributeRange attributeRange;
    bool reenter = true;
    bool redo;
    int numAttr = 3;
    string attribute[] = {
            "Judging Player Data:", "Judging Team Data:", "Presenting Data:"
    };
    short values[numAttr];
    while(reenter){
        for(int i = 0; i < numAttr; i++) {
            redo = true;
            while(redo) {
                cout << attribute[i] << endl;
                try {
                    values[i] = attributeRange.getAttributeValue();
                    redo = false;
                } catch (AttributeRange::OutOfRange &valueOutOfRange) {
                    cout << "Please enter a value between 1 and 20.\n";
                }
            }

        }
        reenter = validateAnswer();
    }
    staff.setScouting(values[0], values[1], values[2]);
}

void App::inputKnowledge(Staff &staff) {
    AttributeRange attributeRange;
    bool reenter = true;
    bool redo;
    int numAttr = 5;
    string attribute[] = {
            "Judging Ability:", "Judging Potential:", "Judging Staff Ability:",
            "Negotiating:", "Tactical Knowledge:"
    };
    short values[numAttr];
    while(reenter){
        for(int i = 0; i < numAttr; i++) {
            redo = true;
            while(redo) {
                cout << attribute[i] << endl;
                try {
                    values[i] = attributeRange.getAttributeValue();
                    redo = false;
                } catch (AttributeRange::OutOfRange &valueOutOfRange) {
                    cout << "Please enter a value between 1 and 20.\n";
                }
            }

        }
        reenter = validateAnswer();
    }
    staff.setKnowledge(values[0], values[1], values[2], values[3], values[4]);
}

void App::setPlayerManual(Player &player)
{
    inputPersonalInfo(player);

    cout << "\nNow set the attributes for " << player.getName() << endl;
    inputTechnical(player);
    inputMental(player);
    inputPhysical(player);
}

void App::inputTechnical(Player &player) {
    AttributeRange attributeRange;
    bool reenter = true;
    bool redo;
    int numAttr = 14;
    string attribute[] = {
            "Corners:", "Crossing:", "Dribbling:", "Finishing:", "First Touch:", "Free Kick:",
            "Heading", "Long Shots:", "Long Throws:", "Marking:", "Passing:", "Penalty Taking:",
            "Tackling", "Technical:",
    };
    short values[numAttr];
    while(reenter){
        for(int i = 0; i < numAttr; i++) {
            redo = true;
            while(redo) {
                cout << attribute[i] << endl;
                try {
                    values[i] = attributeRange.getAttributeValue();
                    redo = false;
                } catch (AttributeRange::OutOfRange &valueOutOfRange) {
                    cout << "Please enter a value between 1 and 20.\n";
                }
            }

        }
        reenter = validateAnswer();
    }
    player.setTechnical(values[0], values[1], values[2], values[3], values[4], values[5], values[6], values[7],
                        values[8], values[9], values[10], values[11], values[12], values[13]);
}

void App::inputMental(Player &player) {
    AttributeRange attributeRange;
    bool reenter = true;
    bool redo;
    int numAttr = 14;
    string attribute[] = {
            "Aggression:", "Anticipation:", "Bravery:", "Composure:", "Concentration:", "Decisions",
            "Determination:", "Flair:", "Leadership:", "Off the Ball:", "Positioning:", "Teamwork:",
            "Vision", "Work Rate:",
    };
    short values[numAttr];
    while(reenter){
        for(int i = 0; i < numAttr; i++) {
            redo = true;
            while(redo) {
                cout << attribute[i] << endl;
                try {
                    values[i] = attributeRange.getAttributeValue();
                    redo = false;
                } catch (AttributeRange::OutOfRange &valueOutOfRange) {
                    cout << "Please enter a value between 1 and 20.\n";
                }
            }

        }
        reenter = validateAnswer();
    }
    player.setMental(values[0], values[1], values[2], values[3], values[4], values[5], values[6], values[7],
                     values[8], values[9], values[10], values[11], values[12], values[13]);
}

void App::inputPhysical(Player &player) {
    AttributeRange attributeRange;
    bool reenter = true;
    bool redo;
    int numAttr = 14;
    string attribute[] = {
            "Acceleration:", "Agility:", "Balance:", "Jumping Reach:", "Natural Fitness:", "Pace:",
            "Stamina:", "Strength:"
    };
    short values[numAttr];
    while(reenter){
        for(int i = 0; i < numAttr; i++) {
            redo = true;
            while(redo) {
                cout << attribute[i] << endl;
                try {
                    values[i] = attributeRange.getAttributeValue();
                    redo = false;
                } catch (AttributeRange::OutOfRange &valueOutOfRange) {
                    cout << "Please enter a value between 1 and 20.\n";
                }
            }

        }
        reenter = validateAnswer();
    }
    player.setPhysical(values[0], values[1], values[2], values[3], values[4], values[5], values[6], values[7]);
}

//
// File Operations
//
/**
 * Saves the Staff or Player to a formatted text file and a binary file
 * to load in later.
 * @tparam T Staff class or Player class
 * @param person Staff or Player object saving to a text and binary file
 */
template<class T>
void App::saveToFile(T &person) {
    person.saveToFile();
    person.saveToBinary();
    cout << person.getName() << " saved to file." << endl;
}

/**
 * Loads a staff member or player from a binary file. If the user does
 * not include a '.' as part of the file name, then a out of range
 * exception is caught because determining a substring with a
 * string::npos throws an out of range exception. In which case, ask
 * user to reenter the filename. If the filename does include a '.',
 * but the file extension that follows is not 'dat' then ask the user
 * to reenter the filename. Otherwise, a '.dat' file was entered. If
 * the filename does not exist, then the program exits.
 * @tparam T Staff or Player
 * @param person address of staff member or player object loading
 */
template<class T>
void App::loadFromFile(T &person) {
    bool redo = true;
    string fileName;
    int found;
    while(redo) {
        cout << "Please enter the name of the .dat file:" << endl;
        getline(cin, fileName);
        try {
            found = fileName.find_last_of('.');
            if(fileName.substr(found) != ".dat") {
                cout << "The file entered is not a '.dat' file." << endl;
            }
            redo = false;
        } catch (std::out_of_range &) {
            cout << "Don't forget to include '.dat'." << endl;
        }
    }
    fstream dataFile(fileName, ios::binary | ios::in);
    if(!dataFile) {
        cout << "File could not be opened. Check file name spelling, make sure to enable read/write permissions, etc.";
        exit(1);
    }

    person.loadBinary(dataFile);
    dataFile.close();
}