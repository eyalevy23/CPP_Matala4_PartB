#ifndef CHARACTER_H
#define CHARACTER_H

#include "Point.hpp"
#include <string>

using namespace std;
namespace ariel{
    class Character
    {
        public:
            Character(std::string name, Point location);
            bool isAlive();
            double distance(Character *other);
            void hit(int damageToCharacter);
            std::string getName();
            Point getLocation();
            virtual std::string print(){return "";};
            int getHealth();
            virtual void someFunction(){};
            virtual string getRole(){return "Character";};
            virtual void attack(Character *other){};
            bool isMember();
            void setIsMember(bool isMember);
            void setLocation(Point other);
            int health;
            std::string name;
            Point location;
            void setName(std::string name);// need to be deleted
            bool isMemberOfTeam = false;
    };

    class Cowboy : public Character
    {

        int bullets;
        public:
            Cowboy(std::string name, Point location);
            void shoot(Character *other);
            bool hasBullets();
            void reload();
            std::string print() override;
            string getRole()override {return "Cowboy";}
            void attack(Character *other)override {shoot(other);}
    };

    class Ninja : public Character
    {
       
        public:
            int speed;
            Ninja(std::string name, Point location);
            void move(Character *other);
            void slash(Character *other);  
            string getRole()override {return "Ninja";}
            std::string print() override;
            void attack(Character *other)override {slash(other);}
    };

    class YoungNinja : public Ninja
    {
        
        public:
            YoungNinja(std::string name, Point location);
    };

    class TrainedNinja : public Ninja
    {
        public:
            TrainedNinja(std::string name, Point location);
    };

    class OldNinja : public Ninja
    {
        public:
            OldNinja(std::string name, Point location);
    };
}
#endif
