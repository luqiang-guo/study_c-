#include <iostream>

class Printable
{
public: 
    virtual std::string GetClassName() = 0;
};

class  Entity : public Printable
{
public:
    virtual std::string GetName(){return  "Entity";}
    // virtual std::string GetName()=0;
    std::string GetClassName()override {return "Entity";}

};

class Player : public Entity
{
private:
    std::string m_Name;
public:
    Player(const std::string& name)
        : m_Name(name){}
    std::string GetName()  {return  m_Name;}
    // std::string GetName()  {return  m_Name;}
    std::string GetClassName()override {return "Player";}

};

void PrintName(Entity * Entity)
{
    std::cout << Entity->GetName() << std::endl;
}

void Print(Printable * obj)
{
    std::cout << obj->GetClassName() << std::endl;
}

int main()
{
    Entity * e = new Entity();
    Print(e);

    Player * p = new Player("Cherno");
    Print(p);

    return 0;
}