#include <iostream>
#include <string>
#include "Duree.hpp"

using namespace std;


 
Duree::Duree(int heures, int minutes, int secondes)
{
    if (secondes >= 60) {
        minutes += secondes/60;
        secondes = secondes%60;
    }
    if (minutes >= 60) {
        heures += minutes/60;
        minutes = minutes%60;
    }

    m_heures = heures;
    m_minutes = minutes;
    m_secondes = secondes;
}

bool Duree::egal(Duree const& b) const
{
    return (m_heures == b.m_heures && m_minutes == b.m_minutes && m_secondes == b.m_secondes);       
}

bool operator==(Duree const& a, Duree const& b)
{
    return a.egal(b);
}


bool Duree::different(Duree const& b) const
{
    return (m_heures != b.m_heures || m_minutes != b.m_minutes || m_secondes != b.m_secondes);       
}

bool operator!=(Duree const& a, Duree const& b)
{
    return a.different(b);
}


bool Duree::superieur(Duree const& b) const
{
    return (m_heures > b.m_heures || (m_heures == b.m_heures && m_minutes > b.m_minutes) || (m_heures == b.m_heures && m_minutes == b.m_minutes && m_secondes > b.m_secondes));       
}

bool operator>(Duree const& a, Duree const& b)
{
    return a.superieur(b);
}


bool Duree::inferieur(Duree const& b) const
{
    return (m_heures < b.m_heures || (m_heures == b.m_heures && m_minutes < b.m_minutes) || (m_heures == b.m_heures && m_minutes == b.m_minutes && m_secondes < b.m_secondes));       
}

bool operator<(Duree const& a, Duree const& b)
{
    return a.inferieur(b);
}

Duree Duree::addition(Duree const& b) const
{
    Duree c;
    c.m_heures = m_heures + b.m_heures;
    c.m_minutes = m_minutes + b.m_minutes;
    c.m_secondes = m_secondes + b.m_secondes;
    if (c.m_secondes >= 60) {
        c.m_minutes += c.m_secondes/60;
        c.m_secondes = c.m_secondes%60;
    }
    if (c.m_minutes >= 60) {
        c.m_heures += c.m_minutes/60;
        c.m_minutes = c.m_minutes%60;
    }

    return c;       
}

Duree operator+(Duree const& a, Duree const& b)
{
    Duree resulte;
    resulte = a.addition(b);
    return resulte;
}

Duree& Duree::operator+=(Duree const& b)
{
    m_heures += b.m_heures;
    m_minutes += b.m_minutes;
    m_secondes += b.m_secondes;

    if (m_secondes >= 60) {
        m_minutes += m_secondes/60;
        m_secondes = m_secondes%60;
    }
    if (m_minutes >= 60) {
        m_heures += m_minutes/60;
        m_minutes = m_minutes%60;
    }

    return *this;

}




string compare(Duree const& a, Duree const& b)
{
       if (a == b) {
        return "a et b sont identiques";
    }
    else {
        if (a > b) {
            return "a est plus grande que b";
        }
        else {
            return "a est plus petite que b" ;
            }
    }

}

void Duree::printout() const
{
    cout << "heures : " << m_heures << "; minutes : " << m_minutes << "; secondes : " << m_secondes << endl;
}

void Duree::printout(ostream &flux) const
{
    flux << "heures : " << m_heures << "; minutes : " << m_minutes << "; secondes : " << m_secondes << endl;
}

ostream& operator<<( ostream& flux, Duree const& duree )
{
    duree.printout(flux);
    return flux;

}
