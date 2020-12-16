/**
 * App.h
 * Author   Raul Aguilar
 * Date     December 14, 2020
 * CS 151 3228 Final Project
 */

#ifndef FM20COMPARE_APP_H
#define FM20COMPARE_APP_H
#include "Staff.h"
#include "Player.h"
#include "AttributeRange.h"
#include <iostream>
#include <iomanip>

class App {
public:
    void run();

private:
    static int getMainMenuChoice();
    static bool askToLoadPerson(const string &type);
    static bool askToSaveToFile();
    static bool validateAnswer();

    void compareStaff();
    void comparePlayers();
    /**
     * Helper method to call the compare function of a Staff or Player object
     * @tparam T Staff or Player class
     * @param person1 Staff or Player object that calls compare()
     * @param person2 Staff or Player object to compare against person1
     */
    template<class T> void comparison(const T &person1, const T &person2) {
        person1.compare(person2);
    }

    void addStaffMember(Staff&);
    void addPlayer(Player&);

    void setStaffManual(Staff&);
    /**
     * Helper method to input the personal information of a Staff or Player
     * object.
     * @tparam T Staff class or Player class
     * @param person Staff or Player object to set personal information
     */
    template<class T> void inputPersonalInfo(T &person) {
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
            cout << "Age:";
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
    static void inputCoaching(Staff&);
    static void inputMedical(Staff&);
    static void inputGKCoaching(Staff&);
    static void inputMental(Staff&);
    static void inputScouting(Staff&);
    static void inputKnowledge(Staff&);

    void setPlayerManual(Player&);
    static void inputTechnical(Player&);
    static void inputMental(Player&);
    static void inputPhysical(Player&);

    //
    // File Operations
    //
    /**
     * Saves the Staff or Player to a formatted text file and a binary file
     * to load in later.
     * @tparam T Staff class or Player class
     * @param person Staff or Player object saving to a text and binary file
     */
    template<class T> void saveToFile(T &person) {
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
    template<class T> void loadFromFile(T &person) {
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
};

#endif //FM20COMPARE_APP_H
