/**************************************************************
* Name        : Final Project for Data Structures
* Author      : Kenny Murrell
* Created     : 11/04/2021
* Course      : CIS 152 – Data Structures
* Version     : 1.0
* OS          : Windows 10
* Copyright   : This is my own original work based on
*               specifications issued by our instructor
* Description : Program to assist with animal adoptions
*
* Academic Honesty: I attest that this is my original work.
* I have not used unauthorized source code, either modified or
* unmodified. I have not given other fellow student(s) access to
* my program.
***************************************************************/
#include <iostream>
#include <string>
#include <queue>
#include <vector>
#include <list>
#include <cctype>
#include <ctime>
#define MAX 200 //represents maximum capacity of shelter
using namespace std;
int randomIdGenerator(){
    srand(time(0)); //random number generator initializer
    int animalId = (rand() %(99999-10000+10000)+10000);
    return animalId;
}
//animal parent object for inheritence
class Animal{
protected:
    string name;
    string species;
    string gender;
    int age;
    int weight;
    string color;
    string subSpecies;
    int idNum;
public:
    string getSpecies(){
        return species;
    }
    int getAge(){
        return age;
    }
    int getWeight(){
        return weight;
    }
    string getColor(){
        return color;
    }
    string getSubSpecies(){
        return subSpecies;
    }
    string getName(){
        return name;
    }
    string getGender(){
        return gender;
    }
    int getIdNum(){
        return idNum;
    }
};
//child object dog
class Dog: public Animal{
public:
    Dog(){}
    void setDog(int b, int c, string d, string e, string f, string g, int h){//combining all vars here because it will be split then combined automaticall on input
        species ="Dog"; //Will always be Dog in this class
        age = b;
        weight = c;
        color = d;
        subSpecies = e;
        name = f;
        gender = g;
        idNum = h;
}
};

class Cat: public Animal{
public:
    void setCat(int b, int c, string d, string e, string f, string g, int h){//combining all vars here because it will be split then combined automaticall on input
        species ="Cat";
        age = b;
        weight = c;
        color = d;
        subSpecies = e;
        name = f;
        gender = g;
        idNum = h;
    }
};

class Other: public Animal{
public:
    void setOther(int b, int c, string d, string e, string f, string g, int h){//combining all vars here because it will be split then combined automaticall on input
        species ="Other";
        age = b;
        weight = c;
        color = d;
        subSpecies = e;
        name = f;
        gender = g;
        idNum = h;
    }
};

class person {
private:
    string firstName;
    string lastName;
public:
    person(){
        firstName = "No name";
        lastName = "No name";
    }
    void setName(string fName, string lName){
        firstName = fName;
        lastName = lName;
    }
    string getName(){
        return firstName + " " + lastName;
    }
};

void printAll(Animal a){
    cout << "ID: " << a.getIdNum() << endl;
    cout << "Species: " << a.getSpecies() << endl;
    cout << "Name: " << a.getName() << endl;
    cout << "Sub Species: "<< a.getSubSpecies() <<endl;
    cout << "Gender: " << a.getGender() << endl;
    cout << "Age: "<< a.getAge() << " years"<< endl;
    cout << "Color: " << a.getColor() << endl;
    cout << "Weight: " << a.getWeight() << "LBS"<< endl;
    cout << "*****" << endl;
};

void printMainMenu(queue<person> cList){
    person currentCustomer = cList.front();
    cout << "************"<< endl;
    cout << "Welcome "<< currentCustomer.getName() << endl;
    cout <<"Enter letter for choice: " << endl;
    cout <<"'A' for adoption" << endl;
    cout <<"'D' to drop off" << endl;
    cout <<"'L' to leave" << endl;
    cout <<"'W' to be added to the wait list"<<endl;
    cout <<"'Q' to exit and shut down for the day (Employees only)" << endl;
}

char mainChoiceChecker(){//main menu choice input validation
    char choice;
    cin >> choice;
    char checkChoice = toupper(choice);//allows user to enter upper or lowercase
    if(checkChoice == 'A' || checkChoice == 'D' || checkChoice == 'L' || checkChoice == 'Q' || checkChoice == 'W'){
        return checkChoice;
    } else {
        cout << "Please select a valid choice" << endl;
        return 0;
    }
}

int adoptionChoiceChecker(){
    int a;
    cin >> a;
    if(a <= 5 && a>=1){
        return a;
    } else {
        cout << "Please enter a valid choice"<<endl;
        cin.clear();
        cin.ignore(1000, '\n');
        return 0;
    }
}

void printAdoptionMenu() {
    cout << "***************************"<<endl;
    cout << "Choose from the following:"<<endl;
    cout << "1 to see all animals" << endl;
    cout << "2 to see just dogs" << endl;
    cout << "3 to see just cats" << endl;
    cout << "4 to see other animals" << endl;
    cout << "5 to exit and leave" << endl;
}

void adoptionStart(vector<Animal> animals){
    int adoptChoice;
    adoptChoice = NULL;
    printAdoptionMenu();
    //make decision for adoption
    while(adoptChoice != 5){
    adoptChoice = adoptionChoiceChecker();
    if(adoptChoice == 1){//choose which animals to display
        for(unsigned int i = 0; i<animals.size(); i++){
            Animal a = animals.at(i);
            printAll(a);
        }break;
    }else if(adoptChoice == 2){
            for(unsigned int i = 0; i<animals.size(); i++){
                Animal a = animals.at(i);
                if(a.getSpecies() == "Dog"){
                printAll(a);
                }
            }break;

    }else if(adoptChoice == 3){
        for(unsigned int i = 0; i<animals.size(); i++){
            Animal a = animals.at(i);
            if(a.getSpecies() == "Cat"){
            printAll(a);
            }
        }break;
    }else if(adoptChoice == 4){
        for(unsigned int i = 0; i<animals.size(); i++){
            Animal a = animals.at(i);
            if(a.getSpecies() == "Other"){
            printAll(a);
            }
        }break;

}}}

char adoptionDecision(){
    char choice;
    cout << "Do you want to adopt one of the animals?" << endl;
    cout << "'Y' for yes 'N' for no"<<endl;
    cin >> choice;
    char chChoice = toupper(choice);
    if(chChoice == 'Y' || chChoice == 'N'){
        return choice;
    } else {
        cout << "Please enter a valid option" << endl;
        choice = adoptionDecision();//little bit of recurssion
    }
    return choice;
}

string speciesValidation() {
    int species;
    for (int i = 0; i <10; i++){
    cout << "Press 1 for dog" "\n" "Press 2 for cat" "\n" "Press 3 for other";
    cin >> species;
    if(species == 1){
        return "Dog";
        break;
    }else if(species ==2){
        return "Cat";
        break;
    }else if(species ==3){
        return "Other";
        break;
    }else{
        cout << "Please enter valid input" << endl;
        cin.clear();
        cin.ignore(1000, '\n');
    }if (i==9){
        cout << "Maximum tries attempted. Please see employee for further assistance"<<endl; //if someone cant get past this part they may need help
    }
  }
}

string nameInput(){
    string name;
    cout << "What is the animals name?" << endl;
    cin >> name;
    return name;
}

string genderInput() {
    int x = 3;
    while(x >2){
    cout << "Press 1 for female and 2 for male" << endl;
    cin >> x;
    if(x == 1){
        return "Male";
    }else if (x == 2){
        return "Female";
    }else{
        cout << "Please enter a valid option"<< endl;
        cin.clear();
        cin.ignore(1000, '\n');
    }
} }

int ageValidation() {
    int age = -1;
    while(age<0 || age>999){
        cout << "How old is the animal in years?" << endl;
        cin >> age;
        if(age<0 || age>999){
            cout << "Please enter age between 0-999" << endl;
        }else{
            return age;
        }
    }
}

int weightInput(){
    int weight;
    cout << "How many pounds does the animal weigh?"<<endl;
    cin >> weight;
    return weight;
}

string colorInput(){
    string aColor;
    cout << "What primary color is the animal?" << endl;
    cin >> aColor;
    return aColor;
}

string subSpeciesInput(){
    string sSInput;
    cout << "What breed is the animal?"<< endl;
    return sSInput;
}


void insertion_sort(std::vector<Animal>& vec)
{
    for(std::size_t j = 1; j < vec.size(); j++)
    {
      int i = j-1;
      Animal prev = vec.at(i);
      int x = prev.getAge();

      Animal currentAnimal = vec.at(j);
      int key = currentAnimal.getAge();


      while(i >= 0 && x > key)
      {
         vec.at(i+1) = vec.at(i);
         i--;
      }
      vec[i+1] = currentAnimal;
    }
}

int main() {
    char choice = NULL;
    int exitCode = 1111;
    //declaring vector of animals
    vector<Animal> animalVector; //list to store animals

    //queue to hold people
    queue<person> customerLine;

    //add a few people to the line
    person person1;
    person1.setName("Gary", "Indiana");
    customerLine.push(person1);
    person person2;
    person2.setName("Amanda", "Oaks");
    customerLine.push(person2);
    person person3;
    person3.setName("Bailey", "Deets");
    customerLine.push(person3);

    //adding start animals to the array
    Dog currentDog;
    Cat currentCat;
    Other currentOther;
    //test dogs
    currentDog.setDog(3, 27, "Tan and White", "Beagle", "Hank", "Male", 11111);
    animalVector.push_back(currentDog);

    currentDog.setDog(5, 27, "Black", "Lab", "Earl", "Male", 11112);
    animalVector.push_back(currentDog);
    //test cats

    currentCat.setCat(1, 11, "Gray", "Mixed Breed", "Princess","Female", 11113);
    animalVector.push_back(currentCat);

    currentCat.setCat(6, 12, "Orange", "Tabby", "Orien", "Male", 11114);
    animalVector.push_back(currentCat);
    //test other
    currentOther.setOther(2, 1, "Brown", "Hampster", "Henrietta", "Female", 11115);
    animalVector.push_back(currentOther);

    currentOther.setOther(10, 670, "Brown", "Horse", "She Who Must Not Be Named", "Female", 11116);
    animalVector.push_back(currentOther);

    //Menu
    while(choice!='Q'){
        insertion_sort(animalVector);
        insertion_sort(animalVector);
        choice = NULL; //added this to just clear any residual memory of the choice variable
        if (customerLine.size() == 0){ //if queue is empty then only the add to list message is displayed
            person currentPerson;
            string fName;
            string lName;
            cout << "Enter your first name to get in line:" << endl;
            cin >> fName;
            cout << "Last name: " << endl;
            cin >> lName;
            currentPerson.setName(fName, lName);
            customerLine.push(currentPerson);
        } else {
        printMainMenu(customerLine);
        choice = mainChoiceChecker();
        if(choice == 'A'){
            adoptionStart(animalVector);//go through adoption process
            char adoptionChoice = adoptionDecision();
            if(adoptionChoice == 'Y' || adoptionChoice == 'y'){
                char quitLoop = 'a';
                while(quitLoop == 'a'){
                Animal currentAnimal;
                int adoptId;
                cout << "enter ID of animal to adopt"<< endl;
                cin >> adoptId;
                int y = animalVector.size();
                for(int i=0; i<y; i++){
                    currentAnimal = animalVector.at(i);
                    int currentId = currentAnimal.getIdNum();
                    if(currentId == adoptId){
                        animalVector.erase(animalVector.begin()+i);
                        quitLoop = 'b';
                        break;
                    }if( i==(y-1)){
                        cout << "Please enter a valid ID" << endl;
                        cin.clear();
                        cin.ignore(1000, '\n');
                        break;
                    }
                }
                }
                cout << "Thank you for adopting! Have a nice day!" <<endl;
            }else{
                cout << "Thank you for stopping by please come again!"<<endl;
            }
            customerLine.pop();//goes to next person in queue

        }else if(choice == 'D'){
            int numAnimals = animalVector.size();
            if(numAnimals >= MAX){
                cout << "We are currently full. Please come again later" << endl;
            } else {
                string species = speciesValidation();
                string name = nameInput();
                string gender = genderInput();
                int age = ageValidation();
                int weight = weightInput();
                string color = colorInput();
                string subSpecies = subSpeciesInput();
                int id = (rand() %(99999-10000+10000)+10000);
                if(species == "Dog"){
                    Dog newDog;
                    newDog.setDog(age, weight, color, subSpecies, name, gender, id);
                    animalVector.push_back(newDog);
                }else if(species == "Cat"){
                    Cat newCat;
                    newCat.setCat(age, weight, color, subSpecies, name, gender, id);
                    animalVector.push_back(newCat);
                }else if(species == "Other"){
                    Other newOther;
                    newOther.setOther(age, weight, color, subSpecies, name, gender, id);
                    animalVector.push_back(newOther);
                }
            cout << "We have " << name << " in our shelter have a nice day" << endl;
            customerLine.pop();

            }

        }else if(choice == 'L'){
            cout << "Please come again!" << endl;
            customerLine.pop();
        }else if(choice == 'W'){
                person currentPerson;
                string fName;
                string lName;
                cout << "Enter your first name to get in line:" << endl;
                cin >> fName;
                cout << "Last name: " << endl;
                cin >> lName;
                currentPerson.setName(fName, lName);
                customerLine.push(currentPerson);
        }else if(choice == 'Q'){
            int securityCode = 0000;
            cout << "Enter security code (its 1111)" << endl;
            cin >> securityCode;
            if(securityCode == exitCode){
                choice = 'Q';
            }else{
                cout << "sorry that code is incorrect" << endl;
                choice = NULL;
            }
        }
        }}


    return 0;
}


//references
//https://programmercave0.github.io/blog/2017/08/20/C++-Insertion-Sort-using-STL-(Sorting) (for sorting method)
