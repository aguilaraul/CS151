/**
 * App.cpp
 * Author   Raul Aguilar
 * Date     December 14, 2020
 * CS 151 3228 Final Project
 */
#include "App.h"
using namespace std;

/**
 * Starting point of application
 */
void App::run() {
    switch(getMainMenuChoice()) {
        case 1:
            compareStaff();
            break;
        case 2:
            comparePlayers();
            break;
        default:
            exit(0); // Shouldn't be able to get here but just in case
    }
}

/**
 * Presents the main menu. Validates that user selects one of two
 * options available.
 * @return Number choice that the user made
 */
int App::getMainMenuChoice() {
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

/**
 * After the user decides to compare either Staff or Players, a menu to
 * ask how they would like to load in the Staff or Player.
 * @param type "staff" or "player"
 * @return True if user made choice 1. Otherwise false, user chose
 * option 2
 */
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

/**
 * After entering a Staff or Player manually, the user is asked if they
 * would like to save the file for later use
 * @return True if answer begins with 'y' or 'Y'. Otherwise false.
 */
bool App::askToSaveToFile() {
    string answer;
    cout << "Would you like to save the person to a file? (Y / N)" << endl;
    cin >> answer;
    return (answer[0] == 'Y' || answer[0] == 'y');
}

/**
 * Used in areas to ask user if they want to re-enter personal
 * information or attributes about a Staff or Player
 * @return True if answer begins with 'y' or 'Y'. Otherwise false.
 */
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
    cout << " ! -- STAFF INFORMATION -- ! " << endl;
    member1.printAttributes();
    cout << "--- --- --- --- --- ---" << endl;
    member2.printAttributes();
    comparison(member1, member2);
}

void App::comparePlayers() {
    Player player1, player2;
    addPlayer(player1);
    addPlayer(player2);
    cout << " ! -- PLAYER INFORMATION -- ! " << endl;
    player1.printAttributes();
    cout << "--- --- --- --- --- ---" << endl;
    player2.printAttributes();
    comparison(player1, player2);
}

/**
 * Menu option to add Staff via file or manual input. After manual
 * input, there is an option to save to file for later use.
 * @param staff Staff object to load to
 */
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

/**
 * Menu option to add Player via file or manual input. After manual
 * input, there is an option to save to file for later use.
 * @param player Player object to load to
 */
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

/**
 * A menu option to manually set the information for a Staff member
 * including their personal info and their attributes.
 * @param staff Staff object to set information
 */
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

/**
 * Helper method to validate and set the input of Staff coaching
 * attributes.
 * @param staff Staff object to set coaching attributes
 */
void App::inputCoaching(Staff &staff) {
    AttributeRange attributeRange;
    bool reenter = true;
    bool redo;
    const int numAttr = 7;
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
                    cout << valueOutOfRange.what();
                }
            }

        }
        reenter = validateAnswer();
    }
    staff.setCoaching(values[0], values[1], values[2], values[3], values[4], values[5], values[6]);
}

/**
 * Helper method to validate and set the input of Staff medical
 * attributes.
 * @param staff Staff object to set medical attributes
 */
void App::inputMedical(Staff &staff) {
    AttributeRange attributeRange;
    bool reenter = true;
    bool redo;
    const int numAttr = 2;
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
                    cout << valueOutOfRange.what();
                }
            }

        }
        reenter = validateAnswer();
    }
    staff.setMedical(values[0], values[1]);
}

/**
 * Helper method to validate and set the input of Staff goalkeeping
 * coaching attributes.
 * @param staff Staff object to set GK coaching attributes
 */
void App::inputGKCoaching(Staff &staff) {
    AttributeRange attributeRange;
    bool reenter = true;
    bool redo;
    const int numAttr = 3;
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
                    cout << valueOutOfRange.what();
                }
            }

        }
        reenter = validateAnswer();
    }
    staff.setGoalKeeping(values[0], values[1], values[2]);
}

/**
 * Helper method to validate and set the input of Staff mental
 * attributes.
 * @param staff Staff object to set mental attributes
 */
void App::inputMental(Staff &staff) {
    AttributeRange attributeRange;
    bool reenter = true;
    bool redo;
    const int numAttr = 5;
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
                    cout << valueOutOfRange.what();
                }
            }

        }
        reenter = validateAnswer();
    }
    staff.setMental(values[0], values[1], values[2], values[3], values[4]);
}

/**
 * Helper method to validate and set the input of Staff scouting
 * attributes.
 * @param staff Staff object to set scouting attributes
 */
void App::inputScouting(Staff &staff) {
    AttributeRange attributeRange;
    bool reenter = true;
    bool redo;
    const int numAttr = 3;
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
                    cout << valueOutOfRange.what();
                }
            }

        }
        reenter = validateAnswer();
    }
    staff.setScouting(values[0], values[1], values[2]);
}

/**
 * Helper method to validate and set the input of Staff knowledge
 * attributes.
 * @param staff Staff object to set knowledge attributes
 */
void App::inputKnowledge(Staff &staff) {
    AttributeRange attributeRange;
    bool reenter = true;
    bool redo;
    const int numAttr = 5;
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
                    cout << valueOutOfRange.what();
                }
            }

        }
        reenter = validateAnswer();
    }
    staff.setKnowledge(values[0], values[1], values[2], values[3], values[4]);
}

/**
 * A menu option to manually enter the Player information from personal
 * info to their attributes.
 * @param player Player object to set information and attributes
 */
void App::setPlayerManual(Player &player)
{
    inputPersonalInfo(player);

    cout << "\nNow set the attributes for " << player.getName() << endl;
    inputTechnical(player);
    inputMental(player);
    inputPhysical(player);
}

/**
 * Helper method to validate and set the input of Player technical
 * attributes.
 * @param player Player object to set technical attributes
 */
void App::inputTechnical(Player &player) {
    AttributeRange attributeRange;
    bool reenter = true;
    bool redo;
    const int numAttr = 14;
    string attribute[] = {
            "Corners:", "Crossing:", "Dribbling:", "Finishing:", "First Touch:", "Free Kick:",
            "Heading:", "Long Shots:", "Long Throws:", "Marking:", "Passing:", "Penalty Taking:",
            "Tackling:", "Technical:",
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
                    cout << valueOutOfRange.what();
                }
            }

        }
        reenter = validateAnswer();
    }
    player.setTechnical(values[0], values[1], values[2], values[3], values[4], values[5], values[6], values[7],
                        values[8], values[9], values[10], values[11], values[12], values[13]);
}

/**
 * Helper method to validate and set the input of Player mental
 * attributes.
 * @param player Player object to set mental attributes
 */
void App::inputMental(Player &player) {
    AttributeRange attributeRange;
    bool reenter = true;
    bool redo;
    const int numAttr = 14;
    string attribute[] = {
            "Aggression:", "Anticipation:", "Bravery:", "Composure:", "Concentration:", "Decisions:",
            "Determination:", "Flair:", "Leadership:", "Off the Ball:", "Positioning:", "Teamwork:",
            "Vision:", "Work Rate:",
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
                    cout << valueOutOfRange.what();
                }
            }

        }
        reenter = validateAnswer();
    }
    player.setMental(values[0], values[1], values[2], values[3], values[4], values[5], values[6], values[7],
                     values[8], values[9], values[10], values[11], values[12], values[13]);
}

/**
 * Helper method to validate and set the input of Player physical
 * attributes.
 * @param player Player object to set physical attributes
 */
void App::inputPhysical(Player &player) {
    AttributeRange attributeRange;
    bool reenter = true;
    bool redo;
    const int numAttr = 8;
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
                    cout << valueOutOfRange.what();
                }
            }

        }
        reenter = validateAnswer();
    }
    player.setPhysical(values[0], values[1], values[2], values[3], values[4], values[5], values[6], values[7]);
}