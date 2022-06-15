/*
    Name: Armando Arredondo Valle
    Date: 12/06/2022
    Matricula: A01424709
*/
// Here we include the libraries we need
#include "Video.h"
#include "Movie.h"
#include "Serie.h"
#include <fstream>
#include <iostream>
#include <sstream>
#include <vector>
#include <string>
using namespace std;

int main(){
int option=0;
   // Vector to store movies, series and rents
    vector <Video*> movies(5);
    vector <Video*> series(5);
    // vector <series>
    // Movie objects
    
    movies[0] = new Movie(1, "The Matrix", "2h", "Sci-Fi", 3); // Movie object 1
    movies[1] = new Movie(2, "Inception", "2h", "Action", 4);
    movies[2] = new Movie(3, "The Dark Knight", "2h", "Action", 5);
    movies[3] = new Movie(4, "Interestellar", "2h", "Sci-Fi", 2);
    movies[4] = new Movie(5, "Minions", "2h", "Animation", 5);
    
    // Series Objects
    series[0] = new Serie(1,"Game of Thrones","3h","Fantasy","5","10",1);
    series[1] = new Serie(2,"The Big Bang Theory","2h","Comedy","5","10",5);
    series[2] = new Serie(3,"Breaking Bad","2h","Drama","5","10",4);
    series[3] = new Serie(4,"The Walking Dead","2h","Horror","5","10",3);
    series[4] = new Serie(5,"The Simpsons","2h","Animation","5","10",2);

    // Menu

do{
    // Menu
    cout << "\n";
    cout << "-------------------------------------------" << "\n";
    cout << "|                                         |" << "\n";
    cout << "|                                         |" << "\n";
    cout << "|                                         |" << "\n";
    cout << "|       Welcome to the Video Library!     |" << "\n";
    cout << "|                                         |" << "\n";
    cout << "|                                         |" << "\n";
    cout << "-------------------------------------------" << "\n";
    cout << "Please select one of the following options:" << "\n";
    cout << "   [1] View all the catalogue" << "\n";
    cout << "   [2] Watch a movie" << "\n";
    cout << "   [3] Watch a serie" << "\n";
    cout << "   [4] Show movies based on rating" << "\n";
    cout << "   [5] Show series based on rating" << "\n";
    cout << "   [6] Rate a serie" << "\n";
    cout << "   [0] Exit" << "\n";
    //Operations
    cout << "\n";
    cout << "Please enter an option: ";  // Ask the user to enter an option
    cin >> option; // Get the option from the user
    cout << "\n"; // Print a new line
    if(option == 1){ // If the option is 1
        system("CLS"); // Clear the screen
        cout << "\n These are all the movies and series which are available on the platform: \n" << endl; // Print a message
        ifstream myFile;    // Create a file stream object
        myFile.open("DB.txt"); // Open the file
        string str; // Create a string variable
        if(myFile) { // If the file is open
            ostringstream ss; // Create a string stream object
            ss << myFile.rdbuf(); // reading data
            str = ss.str(); // Get the string from the string stream object
        }
        cout<<str; // Print the string
        myFile.close(); // Close the file
    } // 
    else if(option == 2){ // If the option is 2
        ifstream myFile;    // Create a file stream object
        myFile.open("DB.txt"); // Open the file
        string str; // Create a string variable
        if(myFile) { // If the file is open
            ostringstream ss;
            ss << myFile.rdbuf(); // reading data
            str = ss.str();
        }
        cout<<str;
        myFile.close();
        int movieOption; // Create an integer variable
        cout << "Please choose a movie to watch: "; // Ask the user to choose a movie
        cin >> movieOption; // Get the movie from the user
        cout << "\n";
        if(movieOption==1){ // If the movie is 1
            movies[0]->print(); // Print the movie "The Matrix"
        }else if(movieOption==2){ // If the movie is 2
            movies[1]->print(); // Print the movie "Inception"
        }else if(movieOption==3){ // If the movie is 3
            movies[2]->print(); // Print the movie "The Dark Knight"
        }else if(movieOption==4){ // If the movie is 4
            movies[3]->print(); // Print the movie "Interestellar"
        }else if(movieOption==5){ // if the movie is 5 
            movies[4]->print(); // Print the movie "Minions"
        }else{ // If the movie is not 1, 2, 3, 4 or 5
            cout << "Invalid option" << endl; // Print an error message
            return 0;// Exit the program
        }// End of if-else statement
    } // 
    else if(option == 3){ // If the option is 3
        int serieOption; // Create an integer variable
        cout << "Please choose a serie to watch: "; // Ask the user to choose a serie
        cin >> serieOption; // Get the serie from the user
        cout << "\n"; // Print a new line
        if(serieOption==1){ // If the serie is 1
            series[0]->print(); // Print the serie "Game of Thrones"
        }else if(serieOption==2){ // If the serie is 2
            series[1]->print(); // Print the serie "The Big Bang Theory"
        }else if(serieOption==3){ // If the serie is 3
            series[2]->print(); // Print the serie "Breaking Bad"
        }else if(serieOption==4){ // If the serie is 4
            series[3]->print(); // Print the serie "The Walking Dead"
        }else if(serieOption==5){ // If the serie is 5
            series[4]->print(); // Print the serie "The Simpsons"
        }else{ // If the serie is not 1, 2, 3, 4 or 5
            cout << "Invalid option" << endl; // Print an error message
            return 0; // Exit the program
        } // End of if-else statement
    } // 
    else if(option == 4){ // If the option is 4
        int rating; // Create an integer variable
        cout << "Please enter a rating: "; // Ask the user to enter a rating
        cin >> rating; // Get the rating from the user
        cout << "\n"; // Print a new line
        // user will request movies with an specific rating and will be shown on the screen if they exist in the catalogue
        for(int i=0; i<movies.size(); i++){ // For each movie in the catalogue
            if(movies[i]->getRating()==rating){ // If the movie has the same rating as the user's input
                //cout << "Movie: " << movies[i].getName() << "Rating" << movies[i].getRating() << endl;
                // print all the movies with the specific rating
                movies[i]->print(); // Print the movie
            } // End of if statement
        } // End of for loop
    } //
    else if(option == 5){ // If the option is 5
        int rt; // Create an integer variable
        cout << "Please enter a rating: "; // Ask the user to enter a rating
        cin >> rt; // Get the rating from the user
        cout << "\n"; // Print a new line
        // user will request series with an specific rating and will be shown on the screen if they exist in the catalogue
        for(int i=0; i<5; i++){ // For each serie in the catalogue
            if(series[i]->getRating()==rt){ // If the serie has the same rating as the user's input
                series[i]->print(); // Print the serie
                //cout << "Serie: " << series[i]->getName() << "Rating" << series[i]->getRating() << endl; // Print the serie
            } // End of if statement
        } // End of for loop
        
    }
    else if(option == 6){
        // user will rate a a serie
        int rating; // Create an integer variable
        int optionToRate;

        cout << "[1] for rating a movie, [2] for rating a serie" << "\n";
        cout << "Enter an option: ";
        cin >> optionToRate;
        cout << "\n";
        if(optionToRate==1){
            int movieOption;
            cout << "Please choose a movie to rate: ";
            cin >> movieOption;
            cout << "\n";
            cout << "Please enter a rating: ";
            cin >> rating;
            cout << "\n";
            if(movieOption==1){
                movies[0]->setRating(rating);
            }
            else if(movieOption==2){
                movies[1]->setRating(rating);
            }
            else if(movieOption==3){
                movies[2]->setRating(rating);
            }
            else if(movieOption==4){
                movies[3]->setRating(rating);
            }
            else if(movieOption==5){
                movies[4]->setRating(rating);
            }
        }
        else if(optionToRate == 2){
            int serieOption; // Create an integer variable
            cout << "Please choose a serie to rate: "; // Ask the user to choose a serie
            cin >> serieOption; // Get the serie from the user
            cout << "\n"; // Print a new line
            cout << "Please enter a rating: "; // Ask the user to enter a rating
            cin >> rating; // Get the rating from the user
            cout << "\n"; // Print a new line
            if(serieOption==1){ // If the serie is 1
                series[0]->setRating(rating); // Set the rating of the serie "Game of Thrones"
            }else if(serieOption==2){ // If the serie is 2
                series[1]->setRating(rating); // Set the rating of the serie "The Big Bang Theory"
            }else if(serieOption==3){ // If the serie is 3
                series[2]->setRating(rating); // Set the rating of the serie "Breaking Bad"
            }else if(serieOption==4){ // If the serie is 4
                series[3]->setRating(rating); // Set the rating of the serie "The Walking Dead"
            }else if(serieOption==5){ // If the serie is 5
                series[4]->setRating(rating); // Set the rating of the serie "The Simpsons"
            }else{ // If the serie is not 1, 2, 3, 4 or 5
                cout << "Invalid option" << endl; // Print an error message
                return 0; // Exit the program
            } // End of if-else statement
        }
    }
    else if(option == 0){ // If the option is 0
        cout << "Thank you for using the catalogue!" << endl; // Print a message
        return 0; // Exit the program
    } // End of if-else statement
}
while(option !=0); // End of do-while loop
return 0; // Exit the program
} // End of main function
