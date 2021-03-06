/*
    Name: Armando Arredondo Valle
    Date: 12/06/2022
    Matricula: A01424709
*/

#pragma once
#include <string>
using namespace std;
class Video // 
{
private:
    string name;
    int id;
    int rating;
    string length;
    string genre;
public:
    Video();
    Video(int id, int rating ,string name ,string length, string genre);
    ~Video();
    int getId();
    int getRating();
    //Getters
    string getName();
    string getLength();
    string getGenre();
    
    //Setters
    void setName(string name);
    void setVideo(Video* video);
    void setId(int id);
    void setLength(string length);
    void setGenre(string genre);
    void setRating(int rating);

    virtual void print(); // prints the information of the video (overrided in the derived classes) (virtual function) (pure virtual function)
};