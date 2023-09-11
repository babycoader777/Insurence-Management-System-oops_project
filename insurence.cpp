#include <iostream>
#include <fstream>
# include<vector>
#include <string>
#include <cstdlib>

using namespace std;
class Insurance {
protected:
    int policyNumber;
    float premium;
    string policyHolderName;
    int coverageAmount;
    string insuranceType;

public:
    Insurance(int num, float prem, const string& holder, int coverage, const string& type)
        : policyNumber(num), premium(prem), policyHolderName(holder), coverageAmount(coverage), insuranceType(type) {}

    int getPolicyNumber() const {
        return policyNumber;
    }

    float getPremium() const {
        return premium;
    }

    string getPolicyHolderName() const {
        return policyHolderName;
    }
   
    void setPremium(float newPremium) {
        premium = newPremium;
    }

    virtual void displayPolicyInfo() const = 0;
};

class VehicleInsurance : public Insurance {
private:
    string vehicleType;

public:
    VehicleInsurance(int num, float prem, const string& holder, int coverage, const string& type, const string& vehicle)
        : Insurance(num, prem, holder, coverage, type), vehicleType(vehicle) {}

    void displayPolicyInfo() const override {
        cout << "Policy Number: " << getPolicyNumber() << "\n"
             << "Policy Holder: " << getPolicyHolderName() << "\n"
             << "Insurance Type: " << insuranceType << "\n"
             << "Coverage Amount: " << coverageAmount << "\n"
             << "Premium: " << premium << "\n"
             << "Vehicle Type: " << vehicleType << endl;
    }
};

class HealthInsurance : public Insurance {
private:
    int age;

public:
    HealthInsurance(int num, float prem, const string& holder, int coverage, const string& type, int clientAge)
        : Insurance(num, prem, holder, coverage, type), age(clientAge) {}
    

    void displayPolicyInfo() const override {
        cout << "Policy Number: " << getPolicyNumber() << "\n"
             << "Policy Holder: " << getPolicyHolderName() << "\n"
             << "Insurance Type: " << insuranceType << "\n"
             << "Coverage Amount: " << coverageAmount << "\n"
             << "Premium: " << premium << "\n"
             << "Client Age: " << age << endl;
    }
};
class User {
private:
    string name;
    int age;
    string contactInfo;
    vector<Insurance*> policies;

public:
User()
{
    
}
    User( string n, int a, string c)
        : name(n), age(a), contactInfo(c) {}

    void addPolicy(HealthInsurance* policy) {
        policies.push_back(policy);
    }

    void listPolicies() const {
        cout << "\n\n|___________________________________________________________\n";
        cout << "Policy No.\tHolder Name\tCoverage Amount\n";
        cout << "\n\n|___________________________________________________________\n";

        for (const Insurance* policy : policies) {
            policy->displayPolicyInfo();
        }
    }

    void displayUserInfo() const {
        cout << "\n Name: " << name << "\n Age: " << age << "\n Contact: " << contactInfo << endl;
    }
};



class InsuranceSystem
{
private:
    int policyNumber;
    float premium;
    string policyHolderName;
    int coverageAmount;
    string insuranceType;
    vector<User*> MUser;
    User ur;

public:


    void menu();
    void administrator();
    void customer();
    void addPolicy();
    void editPolicy();
    void removePolicy();
    void listPolicies();
    void generateInvoice();
    void updatePremium();
    void handleInvalidInput() const;
    void  buyPolicy();
    void buyVehicleInsurence();
    void buyHealthInsurence();
    void customer_menu();
};

void InsuranceSystem::handleInvalidInput() const
{
    cout << "Invalid input. Please try again." << endl;
}

void InsuranceSystem::menu()
{
    while (true)
    {
        cout << "\t\t\t\t______________________________________\n";
        cout << "\t\t\t\t                                      \n";
        cout << "\t\t\t\t          Insurance System Menu       \n";
        cout << "\t\t\t\t                                      \n";
        cout << "\t\t\t\t______________________________________\n";
        cout << "\t\t\t\t                                      \n";
        cout << "\t\t\t\t|  1) Administrator   |\n";
        cout << "\t\t\t\t|                     |\n";
        cout << "\t\t\t\t|  2) Customer        |\n";
        cout << "\t\t\t\t|                     |\n";
        cout << "\t\t\t\t|  3) Exit            |\n";
        cout << "\t\t\t\t|                     |\n";
        cout << "\n\t\t\t Please select: ";

        int choice;
        cin >> choice;

        switch (choice)
        {
        case 1:
            administrator();
            break;

        case 2:
            customer();
            break;

        case 3:
            exit(0);
            break;

        default:
            handleInvalidInput();
            break;
        }
    }
}

void InsuranceSystem::administrator()
{
    while (true)
    {
        cout << "\n\n\n\t\t\t Administrator Menu";
        cout << "\n\t\t\t|_____1) Add Policy_____|";
        cout << "\n\t\t\t|                       |";
        cout << "\n\t\t\t|_____2) Modify Policy___|";
        cout << "\n\t\t\t|                       |";
        cout << "\n\t\t\t|_____3) Delete Policy___|";
        cout << "\n\t\t\t|                       |";
        cout << "\n\t\t\t|_____4) List Policies___|";
        cout << "\n\t\t\t|                       |";
        cout << "\n\t\t\t|_____5) Back to Main Menu___|";

        cout << "\n\n\t Please enter your choice: ";
        int choice;
        cin >> choice;

        switch (choice)
        {
        case 1:
            addPolicy();
            break;

        case 2:
            editPolicy();
            break;

        case 3:
            removePolicy();
            break;

        case 4:
            listPolicies();
            break;

        case 5:
            menu();
            break;

        default:
            handleInvalidInput();
            break;
        }
    }
}

void InsuranceSystem::customer()
{
      string n;
      int a;
      string c;
    
        cout<<"enter name"<<endl;
        cin>>n;
        cout<<"enter age"<<endl;
        cin>>a;
        cout<<"enter contactInfo "<<endl;
        cin>>c;
       ur= User(n,a,c) ;

        char choice;
        cout<<"enter y for yes and n for no"<<endl;
        cin>>choice;
        switch (choice)
        {
            case 'y':customer_menu();
                    break;
            default: menu();
                 break;
        }
     

}

void InsuranceSystem::customer_menu()
{
    while (true)
    {
        cout << "\t\t\t  Customer \n";
        cout << "\t\t\t_____________  \n";
        cout << "                     \n";
        cout << "\t\t\t1) Buy Policy \n";
        cout << "                     \n";
        cout << "\t\t\t2) list policy  \n";
        cout << "                     \n";
        cout << "\t\t\t3) Go back     \n";
        cout << "\t\t\t Enter your choice : ";

        int choice;
        cin >> choice;

        switch (choice)
        {
        case 1:
            buyPolicy();
            break;

        case 2:
            listPolicies();
            break;

        case 3:
            menu();
            break;

        default:
            handleInvalidInput();
            break;
        }
    }
}

void InsuranceSystem::addPolicy()
{
    fstream data;
    data.open("policy_database.txt", ios::app);

    cout << "\n\n\t\t\t Add New Policy";

    try
    {
        cout << "\n Policy Number: ";
        cin >> policyNumber;

        fstream checkData("policy_database.txt");
        int checkPolicyNumber;
        bool duplicate = false;

        while (checkData >> checkPolicyNumber >> policyHolderName >> premium >> coverageAmount >> insuranceType)
        {
            if (checkPolicyNumber == policyNumber)
            {
                duplicate = true;
                break;
            }
        }

        if (duplicate)
        {
            throw runtime_error("Policy with the same number already exists.");
        }

        cout << "\n Policy Holder Name: ";
        cin.ignore();
        getline(cin, policyHolderName);
        cout << "\n Premium: ";
        cin >> premium;
        cout << "\n Coverage Amount: ";
        cin >> coverageAmount;
        cout << "\n Insurance Type: ";
        cin >> insuranceType;

        data << policyNumber << " " << policyHolderName << " " << premium << " " << coverageAmount << " " << insuranceType << endl;

        cout << "\n Policy added!";
        data.close();
    }
    catch (const exception &e)
    {
        cout << "Error: " << e.what() << endl;
    }
}

void InsuranceSystem::editPolicy()
{
    int policyToEdit;
    bool found = false;

    cout << "\n\n\t\t\t Modify a Policy";
    cout << "\n Enter Policy Number to Edit: ";
    cin >> policyToEdit;

    fstream data;
    fstream tempData;
    data.open("policy_database.txt", ios::in);
    tempData.open("temp_policy_database.txt", ios::app);

    while (data >> policyNumber >> policyHolderName >> premium >> coverageAmount >> insuranceType)
    {
        if (policyNumber == policyToEdit)
        {
            found = true;
            cout << "\n Policy Number: " << policyNumber;
            cout << "\n Current Policy Holder Name: " << policyHolderName;
            cout << "\n New Policy Holder Name: ";
            cin.ignore();
            getline(cin, policyHolderName);
            cout << "\n Current Premium: " << premium;
            cout << "\n New Premium: ";
            cin >> premium;
            cout << "\n Current Coverage Amount: " << coverageAmount;
            cout << "\n New Coverage Amount: ";
            cin >> coverageAmount;
            cout << "\n Current Insurance Type: " << insuranceType;
            cout << "\n New Insurance Type: ";
            cin >> insuranceType;
        }
        tempData << policyNumber << " " << policyHolderName << " " << premium << " " << coverageAmount << " " << insuranceType << endl;
    }

    if (!found)
    {
        cout << "\n Policy not found!";
    }

    data.close();
    tempData.close();

    remove("policy_database.txt");
    rename("temp_policy_database.txt", "policy_database.txt");
}

void InsuranceSystem::removePolicy()
{
    int policyToRemove;
    bool found = false;

    cout << "\n\n\t\t\t Remove a Policy";
    cout << "\n Enter Policy Number to Remove: ";
    cin >> policyToRemove;

    fstream data;
    fstream tempData;
    data.open("policy_database.txt", ios::in);
    tempData.open("temp_policy_database.txt", ios::app);

    while (data >> policyNumber >> policyHolderName >> premium >> coverageAmount >> insuranceType)
    {
        if (policyNumber == policyToRemove)
        {
            found = true;
            cout << "\n Policy with Policy Number " << policyNumber << " has been removed.";
        }
        else
        {
            tempData << policyNumber << " " << policyHolderName << " " << premium << " " << coverageAmount << " " << insuranceType << endl;
        }
    }

    if (!found)
    {
        cout << "\n Policy not found!";
    }

    data.close();
    tempData.close();

    remove("policy_database.txt");
    rename("temp_policy_database.txt", "policy_database.txt");
}

void InsuranceSystem::listPolicies()
{
    fstream data;
    data.open("policy_database.txt", ios::in);
    cout << "\n\n|___________________________________________________________\n";
    cout << "Policy No.\tHolder Name\tCoverage Amount\n";
    cout << "\n\n|___________________________________________________________\n";

    while (data >> policyNumber >> policyHolderName >> premium >> coverageAmount >> insuranceType)
    {
        cout << policyNumber << "\t\t" << policyHolderName << "\t\t" << coverageAmount << "\n";
    }

    data.close();
}

void InsuranceSystem::generateInvoice()
{
    fstream data;
    int policyCount;
    int policyNumbers[100];
    int coverageAmounts[100];
    float totalInvoice = 0;

    cout << "\n\n\t\t\t Generate Invoice ";
    data.open("policy_database.txt", ios::in);

    cout << "\n Enter the number of policies to purchase: ";
    cin >> policyCount;

    cout << "\n Enter Policy Numbers and Corresponding Coverage Amounts:\n";
    for (int i = 0; i < policyCount; i++)
    {
        cout << "\n Policy " << i + 1 << " Number: ";
        cin >> policyNumbers[i];
        cout << "\n Coverage Amount: ";
        cin >> coverageAmounts[i];
    }

    cout << "\n\n Invoice:\n";
    for (int i = 0; i < policyCount; i++)
    {
        data.clear();
        data.seekg(0);
        while (data >> policyNumber >> policyHolderName >> premium >> coverageAmount >> insuranceType)
        {
            if (policyNumber == policyNumbers[i])
            {
                float invoiceAmount = (premium * coverageAmounts[i]);
                totalInvoice += invoiceAmount;

                cout << "\n Policy Number: " << policyNumber;
                cout << "\n Policy Holder Name: " << policyHolderName;
                cout << "\n Coverage Amount: " << coverageAmount;
                cout << "\n Premium: " << premium;
                cout << "\n Invoice Amount: " << invoiceAmount << endl;

                break;
            }
        }
    }

    cout << "\n Total Invoice Amount: " << totalInvoice << endl;

    data.close();
}

void InsuranceSystem::updatePremium()
{
    int policyToUpdate;
    float newPremium;

    cout << "\n\n\t\t\t Update Premium for a Policy";
    cout << "\n Enter Policy Number: ";
    cin >> policyToUpdate;

    fstream data;
    fstream tempData;
    data.open("policy_database.txt", ios::in);
    tempData.open("temp_policy_database.txt", ios::app);

    bool found = false;

    while (data >> policyNumber >> policyHolderName >> premium >> coverageAmount >> insuranceType)
    {
        if (policyNumber == policyToUpdate)
        {
            found = true;
            cout << "\n Current Premium: " << premium;
            cout << "\n Enter New Premium: ";
            cin >> newPremium;

            premium = newPremium;

            cout << "\n Premium updated for Policy Number " << policyNumber;
        }
        tempData << policyNumber << " " << policyHolderName << " " << premium << " " << coverageAmount << " " << insuranceType << endl;
    }

    if (!found)
    {
        cout << "\n Policy not found!";
    }

    data.close();
    tempData.close();

    remove("policy_database.txt");
    rename("temp_policy_database.txt", "policy_database.txt");
}

void InsuranceSystem::buyPolicy()
{
    cout<<"buyPolicy"<<endl;
    int choice;
        cout << "\n\t\t\t|_____1) health INsurence___|";
        cout << "\n\t\t\t|                       |";
        cout << "\n\t\t\t|_____2) vehicle Isurence___|";
        cout << "\n\t\t\t|                       |";
        cout << "\n\t\t\t|_____3) Back to Main Menu___|";
    cout<<endl<<"enter choice"<<endl;
    cin>>choice;

    switch(choice)
    {
        case 1: buyHealthInsurence();
             break;
            
        case 2: buyVehicleInsurence();
             break;
        
        default: menu();
        break;

    }
}
void InsuranceSystem:: buyHealthInsurence()
{
     cout<<"buyHealthInsurence"<<endl;
     int num;
     float prem;
     string holder;
     int coverage;
     string type;
     int clientAge;
        cout<<"enter Policy Number:"<<endl;
        cin>>num;
        cout<<"enter Policy Holder:"<<endl;
        cin>>holder;
        cout<<"enter Insurance Type:"<<endl;
        cin>>type;
        cout<<"enter Coverage Amount"<<endl;
        cin>>coverage;
        cout<<"enter Premium::"<<endl;
        cin>>prem;
        cout<<"enter Client Age:"<<endl;
        cin>>clientAge;

     
     HealthInsurance hi(num,prem,holder,coverage,type,clientAge);
     hi.displayPolicyInfo();
     ur.addPolicy(&hi);
     
     customer_menu();

     //buyPolicy();
}
void InsuranceSystem:: buyVehicleInsurence()
{
     cout<<"buyVehicleInsurence"<<endl;
     buyPolicy();
}
int main()
{
    InsuranceSystem insSystem;
    insSystem.menu();
    return 0;
}
