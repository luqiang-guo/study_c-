#include <iostream>

class  Entity
{
public:
    std::string GetName(){return  "Entity";}
    // virtual std::string GetName(){return  "Entity";}
    // virtual std::string GetName()=0;

};

class Player : public Entity
{
private:
    std::string m_Name;
public:
    Player(const std::string& name)
        : m_Name(name){}
    // std::string GetName() override {return  m_Name;}
    std::string GetName()  {return  m_Name;}

};

int main()
{
    Entity * e = new Entity();

    std::cout << e->GetName()<< std::endl;

    Player * p = new Player("Cherno");
    std::cout << p->GetName()<< std::endl;

    Entity* entity = p;
    std::cout << entity->GetName()<< std::endl;
    return 0;
}