#ifndef DEF_DUREE
#define DEF_DUREE

#include <iostream>
#include <string>

 
class Duree
{
    public:
    
    Duree(int heures = 0, int minutes = 0, int secondes = 0);

    bool egal(Duree const& b) const;
    bool different(Duree const& b) const;
    bool superieur(Duree const& b) const;
    bool inferieur(Duree const& b) const;
    Duree addition(Duree  const& b) const;
    Duree& operator+=(Duree const& a);
    // void compare(Duree const& a, Duree const& b) const;

    void printout() const;
    void printout(std::ostream &flux) const;
  

 
    private:
  
    int m_heures;
    int m_minutes;
    int m_secondes;
};


bool operator==(Duree const& a, Duree const& b);
bool operator!=(Duree const& a, Duree const& b);
bool operator>(Duree const& a, Duree const& b);
bool operator<(Duree const& a, Duree const& b);


Duree operator+(Duree const& a, Duree const& b);
std::ostream& operator<<( std::ostream &flux, Duree const& duree );

std::string compare(Duree const& a, Duree const& b);

 
#endif