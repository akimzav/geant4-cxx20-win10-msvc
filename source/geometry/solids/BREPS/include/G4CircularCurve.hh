// This code implementation is the intellectual property of
// the GEANT4 collaboration.
//
// By copying, distributing or modifying the Program (or any work
// based on the Program) you indicate your acceptance of this statement,
// and all its terms.
//
// $Id: G4CircularCurve.hh,v 1.3 1999/12/15 14:49:56 gunter Exp $
// GEANT4 tag $Name: geant4-01-01 $
//
#ifndef __CIRCULARCURVE_H
#define __CIRCULARCURVE_H 

// should be G4Circle, but there is one in graphics_reps already

#include "G4Conic.hh"

class G4CircularCurve : public G4Conic
{
public:
  G4CircularCurve();
  ~G4CircularCurve();

  virtual G4Curve* Project(const G4Transform3D& tr=
			   G4Transform3D::Identity);
	
  virtual G4bool Tangent(G4CurvePoint& cp, G4Vector3D& v);

  //virtual void IntersectRay2D(const G4Ray& ray, G4CurveRayIntersection& is);
  virtual G4int IntersectRay2D(const G4Ray& ray);
  
  virtual G4double GetPMax();
  virtual G4Point3D GetPoint(G4double param);
  virtual G4double GetPPoint(const G4Point3D& p);

  // Get/Set for the geometric data
  void Init(const G4Axis2Placement3D& position0, G4double radius0);
  G4double GetRadius() const;

protected:

  virtual void InitBounded();

private:

  // geometric data
  G4double radius;

};

#include "G4CircularCurve.icc"

#endif






