#ifndef UNIQUEID_H
#define UNIQUEID_H

#include <string>

//Class for the unique id.
//The last id is stored in a single file
//It is used to create the next unique id
class UniqueID
{
    private:

        static const std::string filename;

        static const int defaultID;

    public:

        static int GetLastID();

        static void ClearLastIDFile();

        static void GenerateUniqueID();
};

#endif