// This code implementation is the intellectual property of
// the GEANT4 collaboration.
//
// By copying, distributing or modifying the Program (or any work
// based on the Program) you indicate your acceptance of this statement,
// and all its terms.
//
// $Id: G4ParticleChangeForLoss.hh,v 1.3 1999/11/07 16:32:00 kurasige Exp $
// GEANT4 tag $Name: geant4-01-01 $
//
// 
// ------------------------------------------------------------
//	GEANT 4 class header file 
//
//	For information related to this code contact:
//	CERN, CN Division, ASD group
// 
// ------------------------------------------------------------
//   Implemented for the new scheme                 23 Mar. 1998  H.Kurahige
//
//  Class Description
//  This class is a concrete class for ParticleChange for EnergyLoss
//
#ifndef G4ParticleChangeForLoss_h
#define G4ParticleChangeForLoss_h 1

#include "globals.hh"
#include "G4ios.hh"
class G4DynamicParticle;
#include "G4VParticleChange.hh"

class G4ParticleChangeForLoss: public G4VParticleChange
{ 
  public:
    // default constructor
    G4ParticleChangeForLoss();

    // destructor
    virtual ~G4ParticleChangeForLoss();

  protected:
    // hide copy constructor and assignment operaor as protected
    G4ParticleChangeForLoss(const G4ParticleChangeForLoss &right);
    G4ParticleChangeForLoss & operator=(const G4ParticleChangeForLoss &right);

  public:
    // equal/unequal operator
    G4bool operator==(const G4ParticleChangeForLoss &right) const;
    G4bool operator!=(const G4ParticleChangeForLoss &right) const;


public: // with description
    // ----------------------------------------------------
    // --- the following methods are for updating G4Step -----   
    virtual G4Step* UpdateStepForAlongStep(G4Step* Step);
 
    virtual void Initialize(const G4Track&);
    // Initialize all propoerties by using G4Track information

    G4double GetEnergyChange() const;
    void SetEnergyChange(G4double theEnergyChange);
    // Get/Set the final kinetic energy of the current particle.

       
  public:
    virtual void DumpInfo() const;

  protected:
    G4double theEnergyChange;
    //  The final kinetic energy of the current particle.
    
  public:
    // for Debug 
    virtual G4bool CheckIt(const G4Track&);
};

inline
 G4double G4ParticleChangeForLoss::GetEnergyChange() const
{
  return theEnergyChange;
}

inline
 void G4ParticleChangeForLoss::SetEnergyChange(G4double Energy)
{
  theEnergyChange = Energy;
}

#endif















