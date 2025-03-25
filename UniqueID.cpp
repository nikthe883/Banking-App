#include <iostream>
#include <fstream>
#include "UniqueID.h"

const std::string UniqueID::filename = "last_id.txt";

const int UniqueID::defaultID = 1000;


// Getting the Id in the last Id file
int UniqueID::GetLastID()
{

    int lastID;

    std::ifstream file(filename);

    file >> lastID;

    file.close();

    return lastID;
}

// Function for reseting the unique Id file
void UniqueID::ClearLastIDFile()
{
    std::ofstream file(filename);

    file << defaultID;

    file.close();
}

// Generating a unique id by incrementing the current id
void UniqueID::GenerateUniqueID(){

    int lastID = UniqueID::GetLastID();

    std::ofstream file(filename);

    lastID ++;

    file << lastID;

    file.close();
}
