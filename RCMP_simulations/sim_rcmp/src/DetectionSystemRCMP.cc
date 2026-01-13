#include "DetectorConstruction.hh"
#include "DetectorMessenger.hh"
#include "G4Material.hh"
#include "G4Box.hh"
#include "G4LogicalVolume.hh"
#include "G4PVPlacement.hh"
#include "G4GeometryManager.hh"
#include "G4PhysicalVolumeStore.hh"
#include "G4LogicalVolumeStore.hh"
#include "G4SolidStore.hh"
#include "G4AssemblyVolume.hh"
#include "G4VisAttributes.hh"
#include "G4Colour.hh"
#include "DetectionSystemRCMP.hh"
#include "G4SystemOfUnits.hh"
#include "CADMesh.hh"

DetectionSystemRCMP::DetectionSystemRCMP() : fDSSSDpixelLog(0)
{ 	
	fXLength = 64.*mm;
	fYLength = 64.*mm;
	
    fDetectorThickness = 1.*mm;

	fDetectorDistance1 = 44.92*mm;
	fDetectorDistance2 = 45.29*mm;
	fDetectorDistance3 = 44.98*mm;
    fDetectorDistance4 = 44.62*mm;
	fDetectorDistance5 = 42.63*mm;
	fDetectorDistance6 = 42.68*mm;

	fXPosOffset = 0.;
	fYPosOffset = 0.;
	fZPosOffset = 0.;

	fPixelsXRow = (G4int)(32);
	fPixelsYRow = (G4int)(32);

	fNumberOfPixels = fPixelsXRow*fPixelsYRow;
	
	fPixelWidth = 2.*mm;
}

DetectionSystemRCMP::~DetectionSystemRCMP() 
{
	delete fDSSSDpixelLog;
}

G4int DetectionSystemRCMP::Build() 
{ 

	fAssembly = new G4AssemblyVolume(); 

    G4cout << "BuildPixelVolume" << G4endl;
	BuildPixelVolume();

	return 1;
}

G4int DetectionSystemRCMP::PlaceDetector(G4LogicalVolume* expHallLog) 
{

    G4double posX;
    G4double posY;
    G4double posZ;

    G4int pixelNumber = 0;

    //G4RotationMatrix* GriffinRotate = new G4RotationMatrix();
    G4RotationMatrix* FrameRotate1 = new G4RotationMatrix();
    G4RotationMatrix* FrameRotate2 = new G4RotationMatrix();
    G4RotationMatrix* FrameRotate3 = new G4RotationMatrix();

    //GriffinRotate->rotateZ(-22.5*deg);n
    //GriffinRotate->rotateZ(-0.*deg); 
    //GriffinRotate->rotateY(36.75*deg);
    FrameRotate1->rotateY(37.53*deg);
    FrameRotate2->rotateY(143.52*deg);
    FrameRotate3->rotateZ(90.*deg);
    FrameRotate3->rotateY(-44.48*deg);

    //G4Transform3D rotateTransformGriffin(*GriffinRotate, G4ThreeVector());
    G4Transform3D rotateTransformFrame1(*FrameRotate1, G4ThreeVector());
    G4Transform3D rotateTransformFrame2(*FrameRotate2, G4ThreeVector());
    G4Transform3D rotateTransformFrame3(*FrameRotate3, G4ThreeVector());

    G4double startY = -fXLength / 2.0;
    G4double startZ = -fYLength / 2.0;
    G4double startX = -fYLength / 2.0;

    for (G4int rowX = 0; rowX < fPixelsXRow; ++rowX) 
    {
        G4double posY = startX + fPixelWidth*rowX + fPixelWidth/2.0;

        for (G4int rowY = 0; rowY < fPixelsYRow; ++rowY) 
        {
            G4double posZ = startY + fPixelWidth*rowY + fPixelWidth/2.0 - 11.21*mm;
            G4double posX = 44.92*mm;

            G4ThreeVector localPos1(posX, posY, posZ);

            G4Point3D p1(localPos1);

            G4Point3D pRot1 = rotateTransformFrame1 * p1;

            G4ThreeVector rotatedPos1(pRot1);

            fAssembly->MakeImprint(expHallLog, rotatedPos1, FrameRotate1, pixelNumber);

            ++pixelNumber;
        }
    }




    for (G4int rowX = 0; rowX < fPixelsXRow; ++rowX) 
    {
        G4double posY = startX + fPixelWidth*rowX + fPixelWidth/2.0;

        for (G4int rowY = 0; rowY < fPixelsYRow; ++rowY) 
        {
            G4double posZ = startY + fPixelWidth*rowY + fPixelWidth/2.0 + 10.35*mm;
            G4double posX = 44.98*mm;

            G4ThreeVector localPos2(-posX,posY,posZ);

            G4Point3D p2(localPos2);

            G4Point3D pRot2 = rotateTransformFrame1 *p2; 

            G4ThreeVector rotatedPos2(pRot2);

            fAssembly->MakeImprint(expHallLog,rotatedPos2,FrameRotate1,pixelNumber+32*32);

            ++pixelNumber;
        }
    }

    pixelNumber = 32*32*2;

    for (G4int rowX = 0; rowX < fPixelsXRow; ++rowX) 
    {
        G4double posY = startX + fPixelWidth*rowX + fPixelWidth/2.0;

        for (G4int rowY = 0; rowY < fPixelsYRow; ++rowY) 
        {
            G4double posZ = startY + fPixelWidth*rowY + fPixelWidth/2.0 + 10.75*mm;
            G4double posX = 45.29*mm;

            G4ThreeVector localPos3(posX, posY, posZ);

            G4Point3D p3(localPos3);

            G4Point3D pRot3 = rotateTransformFrame2 * p3;

            G4ThreeVector rotatedPos3(pRot3);

            fAssembly->MakeImprint(expHallLog, rotatedPos3, FrameRotate2, pixelNumber);

            ++pixelNumber;
        }
    }

    for (G4int rowX = 0; rowX < fPixelsXRow; ++rowX) 
    {
        G4double posY = startX + fPixelWidth*rowX + fPixelWidth/2.0;

        for (G4int rowY = 0; rowY < fPixelsYRow; ++rowY) 
        {
            G4double posZ = startY + fPixelWidth*rowY + fPixelWidth/2.0 - 10.81*mm;
            G4double posX = 44.62*mm;

            G4ThreeVector localPos4(-posX,posY,posZ);

            G4Point3D p4(localPos4);

            G4Point3D pRot4 = rotateTransformFrame2 *p4; 

            G4ThreeVector rotatedPos4(pRot4);

            fAssembly->MakeImprint(expHallLog,rotatedPos4,FrameRotate2,pixelNumber+32*32);

            ++pixelNumber;
        }
    }

    pixelNumber = 32*32*3;

    for (G4int rowX = 0; rowX < fPixelsXRow; ++rowX) 
    {
        G4double posY = startX + fPixelWidth*rowX + fPixelWidth/2.0 - 2.33*mm;
        
        for (G4int rowY = 0; rowY < fPixelsYRow; ++rowY) 
        {
            G4double posZ = startY + fPixelWidth*rowY + fPixelWidth/2.0 + 3.16*mm;
            G4double posX = 42.45*mm;

            G4ThreeVector localPos5(posX, posY, posZ);

            G4Point3D p5(localPos5);

            G4Point3D pRot5 = rotateTransformFrame3 * p5;

            G4ThreeVector rotatedPos5(pRot5);

            fAssembly->MakeImprint(expHallLog, rotatedPos5, FrameRotate3, pixelNumber);

            ++pixelNumber;
        }
    }

    for (G4int rowX = 0; rowX < fPixelsXRow; ++rowX) 
    {
        G4double posY = startX + fPixelWidth*rowX + fPixelWidth/2.0 + 3.52*mm;
        for (G4int rowY = 0; rowY < fPixelsYRow; ++rowY) 
        {
            G4double posZ = startY + fPixelWidth*rowY + fPixelWidth/2.0 - 2.69*mm;
            G4double posX = 42.45*mm;

            G4ThreeVector localPos6(-posX,posY,posZ);

            G4Point3D p6(localPos6);

            G4Point3D pRot6 = rotateTransformFrame3 *p6; 

            G4ThreeVector rotatedPos6(pRot6);

            fAssembly->MakeImprint(expHallLog,rotatedPos6,FrameRotate3,pixelNumber+32*32);

            ++pixelNumber;
        }
    }

    G4Material* FrameMaterial = G4Material::GetMaterial("G4_POLYETHYLENE");

    if(!FrameMaterial) 
    {
        G4cout << " ----> Material " << FrameMaterial << G4endl;
        
        return 0;
    }

    G4VisAttributes* visAtt = new G4VisAttributes(G4Colour(1.0,0.0,0.0));

    visAtt->SetVisibility(true);

    auto mesh = CADMesh::TessellatedMesh::FromSTL("../../frame_3d/frame.stl");

    auto solid = mesh->GetSolid();

    G4LogicalVolume* MeshLog = new G4LogicalVolume(solid, FrameMaterial, "MeshLog");

    G4VPhysicalVolume* MeshPhys = new G4PVPlacement(0, G4ThreeVector(0., 0., 0.), MeshLog, "MeshPhys", expHallLog, false, 0, true); 

    auto windows = CADMesh::TessellatedMesh::FromSTL("../../frame_3d/windows.stl");

    auto solidWind = windows->GetSolid();

    G4LogicalVolume* WindLog = new G4LogicalVolume(solidWind, FrameMaterial, "WindLog");

    //G4VPhysicalVolume* WindPhys = new G4PVPlacement(0, G4ThreeVector(0., 0., 0.), WindLog, "WindPhys", expHallLog, false, 0, true); 

    return 1;
}

G4int DetectionSystemRCMP::BuildPixelVolume() 
{
	G4Material* material = G4Material::GetMaterial("Silicon");
	
    if(!material) 
    {
		G4cout<<" ----> Material "<<material<<" not found, cannot build the detector shell! "<<G4endl;
		return 0;
	}

	G4VisAttributes* visAtt = new G4VisAttributes(G4Colour(1.0,0.0,0.0));
	
    visAtt->SetVisibility(true);
	
    G4Box* DSSSDpixel = BuildPixel();

	G4ThreeVector direction 	= G4ThreeVector(0,0,0);
	G4double zPosition		= 0.0*mm;
	G4ThreeVector move 		= zPosition * direction;
	G4RotationMatrix* rotate  = new G4RotationMatrix;
		
	if(fDSSSDpixelLog == nullptr) 
    {
		fDSSSDpixelLog = new G4LogicalVolume(DSSSDpixel, material, "DSSSDpixelLog", 0, 0, 0);
		fDSSSDpixelLog->SetVisAttributes(visAtt);
	}

	fAssembly->AddPlacedVolume(fDSSSDpixelLog, move, rotate);

	return 1;
}

G4Box* DetectionSystemRCMP::BuildPixel() 
{
	G4double halfLengthX = fPixelWidth/2.0;
	G4double halfLengthY = fPixelWidth/2.0;
	G4double halfLengthZ = fDetectorThickness/2.0;
	
    G4Box* pixel = new G4Box("pixel", halfLengthZ, halfLengthY, halfLengthX);

	return pixel;
}
