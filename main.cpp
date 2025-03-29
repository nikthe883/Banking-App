// simple bank account application, will get more complicated with time

#include <iostream>
#include <fstream>
#include <filesystem>
#include <string>
#include <unordered_map>
#include <vector>
#include <sstream>

#include "UniqueID.h"



struct Account{

    int id;
    std::string username;
    std::string password;
    int balance;


};


// array to store accounts by id
std::vector<Account> accountsByID;

//hasmap to store accounts by username for username search
std::unordered_map<std::string, Account> accountsByUsername;

Account* SearchAccountByUsername(const std::string& username){
    auto it = accountsByUsername.find(username);
    if (it != accountsByUsername.end()) {
        return &(it->second);
    }
    return nullptr;
}
void PrintAccountInformation(Account* account){

    std::cout << account -> id << "\n";

}


void LoadFileIntoMemory(){

    std::string line;

    std::ifstream file("accounts.txt");

    while(std::getline(file,line)){

        std::string SPid, SPusername, SPpassword, SPbalance;

        std::istringstream iss(line);

        std::getline(iss, SPid, '|');
        std::getline(iss, SPusername, '|');
        std::getline(iss, SPpassword, '|');
        std::getline(iss, SPbalance, '|');
        
        int id  = std::stoi(SPid);
        int balance = std::stoi(SPbalance);

        Account acc = Account{id, SPusername, SPpassword, balance};


        accountsByID.push_back(acc);
        accountsByUsername[acc.username] = acc;

    }
    file.close();


   /*
    
    for (const Account& acc : accountsByID) {
        std::cout << "ID: " << acc.id << "\n";
        std::cout << "Username: " << acc.username << "\n";
        std::cout << "Password: " << acc.password << "\n";
        std::cout << "Balance: $" << acc.balance << "\n";
        std::cout << "-----------------------\n";
    }

    for (const auto& pair : accountsByUsername) {
        const std::string& username = pair.first;
        const Account* acc = pair.second;
    
        std::cout << "Username: " << username << "\n";
        std::cout << "ID: " << acc->id << "\n";
        std::cout << "Password: " << acc->password << "\n";
        std::cout << "Balance: $" << acc->balance << "\n";
        std::cout << "--------------------------\n";
    }
    */    
}


std::size_t HashPassword(const std::string& password){
    return std::hash<std::string>{}(password);
}

void AccountHistory(){


}

bool CheckIfAccountExists(const std::string username){

    Account* CheckAccount = SearchAccountByUsername(username);

    if(CheckAccount == nullptr){
        return false;
    }else{
        return true;
    }


}

void CreateAccount(int ID, const std::string& username, const std::string& password, int balance ){
    //Creating an account with username, password and balance
    //The data will be stored in a file called accounts

    bool doesAccountExist;

    doesAccountExist = CheckIfAccountExists(username);

    if(!doesAccountExist){

        std::size_t hashedPassword = HashPassword(password);

        std::ofstream file("accounts.txt", std::ios::app);
    
        file << ID << "|" << username << "|" << hashedPassword << "|" << balance << "\n";
    
        file.close();

    }else{

        std::cout << "Account already exists\n";
    }


};

// Deletes the account if found
void DeleteAccount(const std::string& username, const int& ID = 0){

    bool doesAccountExist = CheckIfAccountExists(username);

    if(doesAccountExist){
        std::cout << "Here \n";
        LoadFileIntoMemory();
        
        accountsByUsername.erase(username);

        std::ofstream file("accounts.txt");

        std::cout << "File nas been opened \n";

        for (const auto& pair : accountsByUsername) {
            const std::string& username = pair.first;
            const Account acc = pair.second;
        
            std::cout << "Username: " << username << "\n";
            std::cout << "ID: " << acc.id << "\n";
            std::cout << "Password: " << acc.password << "\n";
            std::cout << "Balance: $" << acc.balance << "\n";
            std::cout << "--------------------------\n";
        }

        for(const auto& x: accountsByUsername){
            file << x.first << '|' << x.second.id << '|' << x.second.password << '|' << x.second.balance << "\n";
        }
         file.close();

         std::cout << "Account has been deleted! \n"; 
    }


};

void UpdateAccount(){

};

void ChangeAccountUsername(){


};

void ChangeAccountPassword(){

};

void GetAccountInformation(){


};

void DepositMoneyInAccount(){


};

void WithdrawMoneyFromAccount(){

};
// Bool function to check if a file is empty
bool CheckIfFileEmpty(const std::string& filename){

    bool isFileEmpty = std::filesystem::is_empty(filename);

    return isFileEmpty;
}


int main(){


    int accountId;
    std::string accountUsername;
    std::string accountPassword;

    printf("__________ BANK MANAGEMENT APPLICATION __________\n");

    UniqueID::GenerateUniqueID();
    int getLastID = UniqueID::GetLastID();

    std::cout << "This is the last unique file ID " << getLastID << "\n";

    //UniqueID::ClearLastIDFile();

    std::string username = "Peter";
    std::string password = "nikola";
    int balance = 100;


    LoadFileIntoMemory();

    CreateAccount(getLastID, username, password, balance);

    

    std::string usernameSearched = "Peter";

  //  Account* acc;

  //  acc = SearchAccountByUsername(usernameSearched);

  //  PrintAccountInformation(acc);

    DeleteAccount("Peter");

//    std::cout << "Last unique ID file is cleared " <<UniqueID::GetLastID() << "\n";

    printf("       __________ END APPLICATION __________");

    return 0;

}