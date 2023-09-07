#include <iostream>
using namespace std;

class Male {
    private:
        string Activity = "fill";                                                   //default values so you can check if nothings been changed
        int Kittens = 0;
        string Female = "fill";
    public:
        string GetActivity(void){                                                   //gets the Activity value
            return Activity;
        };
        int GetKittens(void){                                                       //gets the Kittens value
            return Kittens;
        };
        string GetFemale(void){                                                     //gets the Female value
            return Female;
        }; 
        void SetActivity(string A){                                                 //checks to be sure the input activity is allowed and sets the activity value
            try {
                if (A == "ball" || A == "lazer" || A == "sleep") {                  //checks if the value is allowed and assigns
                    Activity = A;
                }
                else {                                                              //runs an error if the value isn't allowed
                    throw(A);
                }
            }
            catch(string Error_Activity) {                                          //outputs an error
                cout << "Input Activity is incorrect. \n";
                cout << "You input: " << Error_Activity << endl;
                cout << "Input Activity must be 'ball' or 'lazer' or 'sleep'. \n";
            }
        };
        void SetKittens(int A){                                                     //checks if the value is allowed and assigns the kittens value
                       try {
                if (A == 1 || A == 2 || A == 3) {                                   //checks if the value is allowed
                    Kittens = A;
                }
                else {
                    throw(A);                                                       //throws an error if the value isn't allowed
                }
            }
            catch(string Error_Kittens) {                                           //outputs an error
                cout << "Kitten Amount is incorrect. \n";
                cout << "You input: " << Error_Kittens << endl;
                cout << "Kitten Amount must be '1' or '2' or '3'. \n";
            }
        };
        void SetFemale(string A){                                                   //checks if the value is allowed and assigns the Female value
            try {
                if (A == "Ruby" || A == "Spot" || A == "Starbuck") {                //checks if the value is allowed and assigns it
                    Female = A;
                }
                else {
                    throw(A);                                                       //throws an error if the value isn't allowed
                }
            }
            catch(string Error_Female) {                                            //outputs an error
                cout << "Female Name is incorrect. \n";
                cout << "You input: " << Error_Female << endl;
                cout << "Female Name must be 'Ruby' or 'Starbuck' or 'Spot'. \n";
            }
        };
        void Print(string name) {                                                   //prints all of the information in the correct format for a Male Object
            cout << name << " has: \n";
            cout << Kittens;
            if (Kittens == 1) {
                cout << " Kitten, and is with ";
            } else {
                cout << " Kittens, and is with ";
                }
            cout << Female << " who likes to ";
            if (Activity == "sleep") {
                cout << "sleep." << endl;
            } else {
                cout << "Play " << Activity << endl;
            }
        }
};

/*
Similar takes 3 inputs from the class Male

should return true if any of the characteristics are the same as any other Male characteristics
should return false if all of the characteristics between the 3 Males are different
*/
bool Similar(Male a, Male b, Male c) {
    if (a.GetActivity() == b.GetActivity() || b.GetActivity() == c.GetActivity() || a.GetActivity() == c.GetActivity()) {
        return true;
    }
    if (a.GetKittens() == b.GetKittens() || b.GetKittens() == c.GetKittens() || a.GetKittens() == c.GetKittens()) {
        return true;
    }
    if (a.GetFemale() == b.GetFemale() || b.GetFemale() == c.GetFemale() || a.GetFemale() == c.GetFemale()) {
        return true;
    } else { 
       return false;
    }

};

int main() {
    //Create Male Classes
    Male Batman;
    Male Dibii;
    Male Jake;

    //create rules
        //rule 1 -- Batman chose the female who liked to chase a ball, but she was not Starbuck
            Batman.SetActivity("ball");
            if (Batman.GetFemale() == "Starbuck") {
                cout << "Batman cannot be with Starbuck" << endl;
                return 1;
            }
        //rule 2 -- Dibii's companion liked to chase the lazer light
            Dibii.SetActivity("lazer");
        //rule 3 -- Ruby loved to cuddle up to her male for a long afternoon nap in the sun
        //inference 1 -- since Jake has no activity set he gets sleep and ruby
            if(Jake.GetActivity() == "fill") {                              
                Jake.SetActivity("sleep");
                Jake.SetFemale("Ruby");
            }
        //inference 2 -- Since Ruby is taken and Batman can't have Starbuck, you can assume Dibii is with Starbuck and Batman is with Spot
            if(Dibii.GetFemale() == "fill") {
                Dibii.SetFemale("Starbuck");
            }
            if(Batman.GetFemale() == "fill") {
                Batman.SetFemale("Spot");
            }
        //rule 4 -- Starbuck had two more kittens than Batman's companion
            Batman.SetKittens(1);
            if(Dibii.GetFemale() == "Starbuck") {
                Dibii.SetKittens(3);
            }
        //inference 3 -- Since only Jake doesn't have an amount of kittens, he must have 2
            Jake.SetKittens(2);

    //Be sure there is no overlap between the Classes
    if (Similar(Batman, Dibii, Jake)) {
        cout << "These have similar characteristics" << endl;
        return 1;
    } else {
        cout <<"These are completely different" << endl;
    }

    Batman.Print("Batman");                                            //prints out all Male Object's information
    Jake.Print("Jake");
    Dibii.Print("Dibii");
    return 0;
}