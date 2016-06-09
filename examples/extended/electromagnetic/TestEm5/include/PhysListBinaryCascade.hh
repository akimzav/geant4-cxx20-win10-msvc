//
// ********************************************************************
// * License and Disclaimer                                           *
// *                                                                  *
// * The  Geant4 software  is  copyright of the Copyright Holders  of *
// * the Geant4 Collaboration.  It is provided  under  the terms  and *
// * conditions of the Geant4 Software License,  included in the file *
// * LICENSE and available at  http://cern.ch/geant4/license .  These *
// * include a list of copyright holders.                             *
// *                                                                  *
// * Neither the authors of this software system, nor their employing *
// * institutes,nor the agencies providing financial support for this *
// * work  make  any representation or  warranty, express or implied, *
// * regarding  this  software system or assume any liability for its *
// * use.  Please see the license in the file  LICENSE  and URL above *
// * for the full disclaimer and the limitation of liability.         *
// *                                                                  *
// * This  code  implementation is the result of  the  scientific and *
// * technical work of the GEANT4 collaboration.                      *
// * By using,  copying,  modifying or  distributing the software (or *
// * any work based  on the software)  you  agree  to acknowledge its *
// * use  in  resulting  scientific  publications,  and indicate your *
// * acceptance of all terms of the Geant4 Software license.          *
// ********************************************************************
//
// $Id: PhysListBinaryCascade.hh,v 1.4 2006/08/10 08:44:39 vnivanch Exp $
// GEANT4 tag $Name: geant4-08-02 $
//
// Class Description:
//      This class is an derived class of G4VPhysicsConstructor
//      It is provide PhysicsList for Binary Cascade for
//      protons and neutrons with the energy E<3 GeV
//
//....oooOO0OOooo........oooOO0OOooo........oooOO0OOooo........oooOO0OOooo......
//....oooOO0OOooo........oooOO0OOooo........oooOO0OOooo........oooOO0OOooo......

#ifndef PhysListBinaryCascade_h
#define PhysListBinaryCascade_h 1

#include "G4VPhysicsConstructor.hh"
#include "globals.hh"

//....oooOO0OOooo........oooOO0OOooo........oooOO0OOooo........oooOO0OOooo......

class G4ProtonInelasticProcess;
class G4NeutronInelasticProcess;
class G4HadronFissionProcess;
class G4HadronCaptureProcess;

class PhysListBinaryCascade : public G4VPhysicsConstructor
{
public:
  PhysListBinaryCascade(const G4String& name = "binary");
  virtual ~PhysListBinaryCascade();

public:
  // This method will be invoked in the Construct() method.
  // each particle type will be instantiated
  void ConstructParticle() {};

  // This method will be invoked in the Construct() method.
  // each physics process will be instantiated and
  // registered to the process manager of each particle type
  void ConstructProcess();

private:

  G4ProtonInelasticProcess*       theIPproton;
  G4NeutronInelasticProcess*      theIPneutron;
  G4HadronFissionProcess*         theFissionProcess;
  G4HadronCaptureProcess*         theCaptureProcess;
};

//....oooOO0OOooo........oooOO0OOooo........oooOO0OOooo........oooOO0OOooo......

#endif