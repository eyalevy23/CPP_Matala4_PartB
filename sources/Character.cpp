#include "Character.hpp"
#include <string>
#include <iostream>
#include "Point.hpp"

using namespace std;
namespace ariel{

    Character::Character(std::string name, Point location): name(name), location(location), health(0)
    {}


    bool Character::isAlive()
    {
        return this->health > 0;
    }

    double Character::distance(Character *other)
    {
        return this->location.distance(other->getLocation());
    }

    void Character::hit(int damageToCharacter)
    {
        if(damageToCharacter < 0)
        {
            throw std::invalid_argument("damage is negative");
        }
        this->health -= damageToCharacter;
    }

    std::string Character::getName()
    {
        return this->name;
    }

    void Character::setName(std::string name)
    {
        this->name = name;
    }

    Point Character::getLocation()
    {
        return this->location;
    }

    int Character::getHealth()
    {
        return this->health;
    }

    bool Character::isMember()
    {
        return this->isMemberOfTeam;
    }

    void Character::setIsMember(bool isMember)
    {
        this->isMemberOfTeam = isMember;
    }

    void Character::setLocation(Point other)
    {
        this->location = other;
    }

    // void Character::print()
    // {
    //     std::cout << "Character: " << this->name << std::endl;
    //     if(this->isAlive())
    //     {
    //         std::cout << "Damage: " << this->health << std::endl;
    //     }
    //     std::cout << "Location: " << this->location.getX() << ", " << this->location.getY() << std::endl;
    //     std::cout << "(" << this->name  << ")" << std::endl;
    //     std::cout << " " << std::endl;

    // }


    Cowboy::Cowboy(std::string name, Point location) : Character(name, location),bullets(6)
    {
        this->health = 110;
    }

    void Cowboy::shoot(Character *other)
    {
        if(this == other)
        {
            throw std::runtime_error("you can't attack yourself");
        }
        
        if(other->isAlive() == false)
        {
            throw std::runtime_error("you are dead");
        }
        if(this->isAlive() == false)
        {
            throw std::runtime_error("you are dead");
        }
        if(this->bullets == 0)
        {
            this->reload();
            return;
        }
        if(this->isAlive() && this->hasBullets())
        {
            other->hit(10);
            this->bullets--;
        }

    }

    bool Cowboy::hasBullets()
    {
        return this->bullets > 0;
    }

    void Cowboy::reload()
    {
        if(this->isAlive() == false)
        {
            throw std::runtime_error("you are dead");
        }
        this->bullets = 6;
    }

    std::string Cowboy::print()
    {
        string printer = "";
        if(this->isAlive()){
            printer = "C - " + this->getName() + " - " + to_string(this->getHealth()) + " - " + to_string(this->getLocation().getX()) + " - " + to_string(this->getLocation().getY());
        }
        else{
            printer = "C - (" + this->getName() + "), - DEAD";
        }
        return printer;
    }

    Ninja::Ninja(std::string name, Point location) : Character(name, location)
    {
    }

    void Ninja::move(Character *other)
    {   
        if(this->isAlive()== false)
        {
            throw "Ninja is dead";
        }
        this->location = Point::moveTowards(this->location, other->location, this->speed);
    }

    void Ninja::slash(Character *other)
    {
        if(this == other)
        {
            throw std::runtime_error("you can't attack yourself");
        }
        if(other->isAlive() == false)
        {
            throw std::runtime_error("you are dead");
        }
        if(this->isAlive() == false)
        {
            throw std::runtime_error("you are dead");
        }
        if(this->isAlive() && this->distance(other) <= 1)
        {
            other->hit(40);
        }
    }

    std::string Ninja::print()
    {
        string printer = "";
        if(this->isAlive()){
            printer = "N - " + this->getName() + " - " + to_string(this->getHealth()) + " - " + to_string(this->getLocation().getX()) + " - " + to_string(this->getLocation().getY());
        }
        else{
            printer = "N - (" + this->getName() + "), - DEAD";
        }
        return printer;
    }

    YoungNinja::YoungNinja(std::string name, Point location) : Ninja(name, location)
    {
        this->health = 100;
        this->speed = 14;
    }

    TrainedNinja::TrainedNinja(std::string name, Point location) : Ninja(name, location)
    {
        this->health = 120;
        this->speed = 12;
    }

    OldNinja::OldNinja(std::string name, Point location) : Ninja(name, location)
    {
        this->health = 150;
        this->speed = 8;
    }

}
