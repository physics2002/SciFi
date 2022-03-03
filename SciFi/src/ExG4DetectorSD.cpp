#include<G4Step.hh>
#include<fstream>
#include<iostream>
#include "G4SystemOfUnits.hh"
#include "G4ThreeVector.hh"
#include "ExG4DetectorSD.hh"

#include<G4UserRunAction.hh>
#include<G4Run.hh>

using namespace std;

// Конструктор чуствительной области, по умолчанию инициализируем нижнюю и верхнюю
// границы гистограммы в 0 и 50 МэВ
//ofstream out("deltae.csv");

ExG4DetectorSD::ExG4DetectorSD(G4String name): G4VSensitiveDetector(name)
{
}

G4bool ExG4DetectorSD::ProcessHits(G4Step* step, G4TouchableHistory*)
   {
         // Получаем кинетическую энергии частицы с предыдущего шага, т.е. начальную
       // кинитическую энегрию перед текущим шагом
       //double energy = step->GetPreStepPoint()->GetKineticEnergy();
       
       G4TouchableHandle touchable = step->GetPreStepPoint()->GetTouchableHandle();
       G4VPhysicalVolume* volume = touchable->GetVolume();
       G4String name = volume->GetName();
       
       //Получаем выделившуюся энергию
       G4double edep = step->GetTotalEnergyDeposit();
            
       if (edep==0.) return false;
       G4String particleName;
/*
    cout << name << "\t";
    cout << edep*1000;
    cout << "\n";
    G4cout << "Test message" << std::endl;
    
    out << step->GetTrack()->GetDefinition()->GetParticleName() << std::endl;
    out << name;
    out << "\t";
    out << edep*1000;
    out << "\n";
*/
    //out << "This the step message" << "\n";
             return true;
       }

             ExG4DetectorSD::~ExG4DetectorSD()
             {
                 //out << "This is the end of tests" << "\n";
                 //out.close();
                 
              }


