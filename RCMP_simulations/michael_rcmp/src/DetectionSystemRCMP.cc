#include "DetectorConstruction.hh"
#include "DetectorMessenger.hh"
#include "G4Material.hh"
#include "G4NistManager.hh"
#include "G4Box.hh"
#include "G4Tubs.hh"
#include "G4SubtractionSolid.hh"
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
#include "G4GDMLParser.hh"

DetectionSystemRCMP::DetectionSystemRCMP() : fDSSSDpixelLog(0)
{ 	
	fXLength = 63.96*mm;
	fYLength = 63.96*mm;
	
    fDetectorThickness = 1.*mm;
    fOffsetPCB = 0.*mm;

	fPixelsXRow = (G4int)(1);
	fPixelsYRow = (G4int)(1);

	fNumberOfPixels = fPixelsXRow*fPixelsYRow;
	
	fPixelWidth = 63.96*mm;
}

DetectionSystemRCMP::~DetectionSystemRCMP() 
{
	delete fDSSSDpixelLog;
}

G4int DetectionSystemRCMP::Build() 
{ 

	fAssembly = new G4AssemblyVolume(); 

    G4cout << "BuildPixelVolume" << G4endl;
//	BuildPixelVolume();

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

    //GriffinRotate->rotateZ(-22.5*deg);
    //GriffinRotate->rotateZ(-0.*deg); 
    //GriffinRotate->rotateY(36.75*deg);
    FrameRotate1->rotateY(45.*deg);
    FrameRotate2->rotateY(135.*deg);
    FrameRotate3->rotateZ(90.*deg);
    FrameRotate3->rotateY(45*deg);

    //G4Transform3D rotateTransformGriffin(*GriffinRotate, G4ThreeVector());
    G4Transform3D rotateTransformFrame1(*FrameRotate1, G4ThreeVector());
    G4Transform3D rotateTransformFrame2(*FrameRotate2, G4ThreeVector());
    G4Transform3D rotateTransformFrame3(*FrameRotate3, G4ThreeVector());

    G4double startY = -fXLength / 2.0;
    G4double startZ = -fYLength / 2.0;
    G4double startX = -fYLength / 2.0;

    G4double offsettest = 0.*mm;
    G4double beam_opening = 14.*mm;

///////////////////////////////////////////MICHAELS CODE///////////////////////////////////////////////////////////
///////////////////////////////////////////MICHAELS CODE///////////////////////////////////////////////////////////

   /* //DET 6
    
    G4RotationMatrix* FrameRotateTest = new G4RotationMatrix();
    G4RotationMatrix* FrameRotateTest2 = new G4RotationMatrix();
    
    FrameRotateTest->rotateY(-Xtheta*deg);
    FrameRotateTest->rotateY(-315.*deg);
    FrameRotateTest2->rotateY(Xtheta*deg);
    FrameRotateTest2->rotateY(-45.*deg);

    G4Transform3D rotateTransformFrameTest(*FrameRotateTest, G4ThreeVector());
    G4Transform3D rotateTransformFrameTest2(*FrameRotateTest2, G4ThreeVector());

    for (G4int rowX = 0; rowX < fPixelsXRow; ++rowX) 
    {
        G4double posY = startX + fPixelWidth*rowX + fPixelWidth/2.0;

        for (G4int rowY = 0; rowY < fPixelsYRow; ++rowY) 
        {
            G4double posZ = startY + fPixelWidth*rowY + fPixelWidth/2.0;
            G4double posX = 36.5*mm;

            G4ThreeVector localPos1(posX, posY, posZ);

            G4Point3D p1(localPos1);

            G4Point3D pRot1 = rotateTransformFrame1 * p1;

            G4ThreeVector rotatedPos1(pRot1);
            
            G4ThreeVector test(rotatedPos1.getX(),rotatedPos1.getY(),rotatedPos1.getZ() - offsettest);
            
            fAssembly->MakeImprint(expHallLog, test, FrameRotate1, pixelNumber);

            ++pixelNumber;
        }
    }

    //DET 1

    for (G4int rowX = 0; rowX < fPixelsXRow; ++rowX) 
    {
        G4double posY = startX + fPixelWidth*rowX + fPixelWidth/2.0;

        for (G4int rowY = 0; rowY < fPixelsYRow; ++rowY) 
        {
            G4double posZ = startY + fPixelWidth*rowY + fPixelWidth/2.0;
            G4double posX = 36.5*mm;

            G4ThreeVector localPos2(-posX+Xmove_over,posY,posZ+Xmove_up);

            G4Point3D p2(localPos2);

            G4Point3D pRot2 = rotateTransformFrameTest *p2;

            G4ThreeVector rotatedPos2(pRot2);
            
            G4ThreeVector test(rotatedPos2.getX(),rotatedPos2.getY(),rotatedPos2.getZ()+up_offset);

            fAssembly->MakeImprint(expHallLog,test,FrameRotateTest,pixelNumber+32*32);

            ++pixelNumber;
        }
    }

    pixelNumber = 32*32*2;

    //DET 5

    for (G4int rowX = 0; rowX < fPixelsXRow; ++rowX) 
    {
        G4double posY = startX + fPixelWidth*rowX + fPixelWidth/2.0;

        for (G4int rowY = 0; rowY < fPixelsYRow; ++rowY) 
        {
            G4double posZ = startY + fPixelWidth*rowY + fPixelWidth/2.0;
            G4double posX = 36.5*mm;

            G4ThreeVector localPos3(posX, posY, posZ);

            G4Point3D p3(localPos3);

            G4Point3D pRot3 = rotateTransformFrame2 * p3;

            G4ThreeVector rotatedPos3(pRot3);
            
            G4ThreeVector test2(rotatedPos3.getX(),rotatedPos3.getY(),rotatedPos3.getZ() - offsettest);

            fAssembly->MakeImprint(expHallLog, test2, FrameRotate2, pixelNumber);

            ++pixelNumber;
        }
    }

    //DET 2

    for (G4int rowX = 0; rowX < fPixelsXRow; ++rowX) https://journals.aps.org/prl/abstract/10.1103/l24v-5m31
    {
        G4double posY = startX + fPixelWidth*rowX + fPixelWidth/2.0;

        for (G4int rowY = 0; rowY < fPixelsYRow; ++rowY) 
        {
            G4double posZ = startY + fPixelWidth*rowY + fPixelWidth/2.0;
            G4double posX = 36.5*mm;

            G4ThreeVector localPos4(posX,posY,posZ);

            G4Point3D p4(localPos4);

            G4Point3D pRot4 = rotateTransformFrameTest2 *p4; 

            G4ThreeVector rotatedPos4(pRot4);
            
            G4ThreeVector test(rotatedPos4.getX() - Xmove_over,rotatedPos4.getY(),rotatedPos4.getZ()+ Xmove_up+up_offset);

            fAssembly->MakeImprint(expHallLog,test,FrameRotateTest2,pixelNumber+32*32);

            ++pixelNumber;
        }
    }

    pixelNumber = 32*32*3;

    //DET 3

    for (G4int rowX = 0; rowX < fPixelsXRow; ++rowX) 
    {
        G4double posY = startX + fPixelWidth*rowX + fPixelWidth/2.0;
        
        for (G4int rowY = 0; rowY < fPixelsYRow; ++rowY) 
        {
            G4double posZ = startY + fPixelWidth*rowY + fPixelWidth/2.0;
            G4double posX = 36.5*mm;

            G4ThreeVector localPos5(posX, posY, posZ);

            G4Point3D p5(localPos5);

            G4Point3D pRot5 = rotateTransformFrame3 * p5;

            G4ThreeVector rotatedPos5(pRot5);

            fAssembly->MakeImprint(expHallLog, rotatedPos5, FrameRotate3, pixelNumber);

            ++pixelNumber;
        }
    }

    //DET 4

    for (G4int rowX = 0; rowX < fPixelsXRow; ++rowX) 
    {
        G4double posY = startX + fPixelWidth*rowX + fPixelWidth/2.0;
        for (G4int rowY = 0; rowY < fPixelsYRow; ++rowY) 
        {
            G4double posZ = startY + fPixelWidth*rowY + fPixelWidth/2.0;
            G4double posX = 36.5*mm;

            G4ThreeVector localPos6(-posX,posY,posZ);

            G4Point3D p6(localPos6);

            G4Point3D pRot6 = rotateTransformFrame3 *p6; 

            G4ThreeVector rotatedPos6(pRot6);

            fAssembly->MakeImprint(expHallLog,rotatedPos6,FrameRotate3,pixelNumber+32*32);

            ++pixelNumber;
        }
    }*/

    G4NistManager* nist = G4NistManager::Instance();

    G4Material* FrameMaterial = G4Material::GetMaterial("G4_POLYETHYLENE");
    G4Material* MylarMaterial = nist->FindOrBuildMaterial("G4_MYLAR");

    if(!FrameMaterial) 
    {
        G4cout << " ----> Material " << FrameMaterial << G4endl;
        
        return 0;
    }

    G4VisAttributes* visAttTape = new G4VisAttributes(G4Colour(0.0,1.0,0.0));

    visAttTape->SetVisibility(true);

    auto mesh = CADMesh::TessellatedMesh::FromSTL("../../frame_3d/frame.stl");

    auto solid = mesh->GetSolid();

    G4LogicalVolume* MeshLog = new G4LogicalVolume(solid, FrameMaterial, "MeshLog");

    //G4VPhysicalVolume* MeshPhys = new G4PVPlacement(0, G4ThreeVector(0., 0., 0.), MeshLog, "MeshPhys", expHallLog, false, 0, true); 

    auto windows = CADMesh::TessellatedMesh::FromSTL("../../frame_3d/windows.stl");

    auto solidWind = windows->GetSolid();

    G4LogicalVolume* WindLog = new G4LogicalVolume(solidWind, FrameMaterial, "WindLog");

    G4VPhysicalVolume* WindPhys = new G4PVPlacement(0, G4ThreeVector(0., 0., 0.), WindLog, "WindPhys", expHallLog, false, 0, true);

    G4Box* solidHolderPreSub = new G4Box("solidHolderPreSub", 41.8*mm, 8.5*mm, 0.45*mm);

    G4Tubs* solidHole = new G4Tubs("solidHole", 0., 7.5*mm, 0.9*mm, 0., 360.);

    G4VSolid* solidHolder = new G4SubtractionSolid("solidHolder", solidHolderPreSub, solidHole);
    
    G4LogicalVolume* logHolder = new G4LogicalVolume(solidHolder, FrameMaterial, "logHolder");
    
    //G4VPhysicalVolume* physHolder = new G4PVPlacement(0, G4ThreeVector(0., 0., 0.45*mm), logHolder, "physHolder", expHallLog, false, 0, true);

    G4Tubs* solidTape = new G4Tubs("solidTape", 0., 7.5*mm, 0.55*um, 0., 360.);
    
    G4LogicalVolume* logTape = new G4LogicalVolume(solidTape, MylarMaterial, "logTape");

    logTape->SetVisAttributes(visAttTape);

    //G4VPhysicalVolume* physTape = new G4PVPlacement(0, G4ThreeVector(0., 0., 0.*mm), logTape, "physTape", expHallLog, false, 0, true);
   
    //G4GDMLParser parser;
    //parser.Write("det.gdml", expHallLog);
    G4double fPCB_thickness = (5. / 2.)*mm;
    G4double fPCB_length = (67.975 / 2.)*mm;
    G4double fPCB_width = (67.975 / 2.)*mm;

    G4double fSi_thickness = (1. / 2.)*mm;// can be purchased from 1.0mm - 1.5 mm
    G4double fSi_length = (63.96 / 2.)*mm;

    G4double up_offset = 2.0*mm;
    up_offset = (up_offset * sin(45.*deg))*mm;

    // specify back DSSD offsets from the middle bisection:
    G4double down_offset = 2.0*mm;
    down_offset = -(down_offset * sin(45.*deg))*mm;
    
    // Distance of DSSD centers from origin:
    G4double r_vec = 41.5*mm;
    // Looping through angles until the specified beam opening width is reached:
    G4double Xmove_up = 0.0*mm;
    G4double Xmove_over = 0.0*mm;
    G4double Xbeam_opening = 0.0*mm;
    G4double Xtheta = 0.0;

    // int counter = 0;
    if(beam_opening > 0.0){
    	// shorten loops:
        if(beam_opening >= 10.) Xtheta = 5.;
        if(beam_opening >= 20.) Xtheta = 10.;
        if(beam_opening >= 30.) Xtheta = 15.;
        do{
	        Xtheta += 0.01*deg;
	        Xmove_up = std::sin(Xtheta*CLHEP::pi/180.) * fPCB_length;
	        Xmove_over = (fPCB_length * (1.0 - std::cos(Xtheta*CLHEP::pi/180.)))*mm;
	        Xbeam_opening = (sin(45.*deg) * 4.0 * Xmove_over) + (2.0 * sin(45.*deg) * 2.0 * Xmove_up);
	        // counter++;
        }while(Xbeam_opening < beam_opening);
    }
    // std::cout<<"\ncounter: "<<counter<<"\n\n";
    // std::cout<<"\nXtheta: "<<Xtheta<<"\n\n";
    // std::cout<<"\nXbeam opening: "<<Xbeam_opening<<"\n\n";
        

    // Moving the DSSD's in any direction:
    //    {x, y, z}
    G4double trans[6][3] = {
        {up_offset - Xmove_over,         0.*mm,       r_vec + up_offset + Xmove_up},// 0 - upstream
        {r_vec + up_offset + Xmove_up,   0.*mm,       up_offset - Xmove_over},// 1 - upstream
        {0.*mm,                          39.*mm,       0.*mm},// 2 - top
        {0.*mm,                          -39.*mm,      0.*mm},// 3 - bottom
        {down_offset + Xmove_over,                    0.*mm,       -r_vec + down_offset - Xmove_up},// 4 - downstream
        {-r_vec + down_offset - Xmove_up,           0.*mm,       down_offset + Xmove_over}// 5 - downstream
    };


    // Rotating the cube faces:
        //{x, y, z}
    G4double rot[6][3] = {
        {0.*deg,     (-Xtheta)*deg,         90.*deg},
        {90.0*deg,   (+Xtheta+270.0)*deg,   90.0*deg},
        {0.*deg,     270.*deg,              0.*deg},
        {0.*deg,     270.*deg,              0.*deg},
        {0.*deg,     (-Xtheta+180.0)*deg,              90.*deg},
        {90.0*deg,   (+Xtheta+90.0)*deg,              90.0*deg}
    };

	G4Material* material = G4Material::GetMaterial("Silicon");
    
	
    if(!material) 
    {
		G4cout<<" ----> Material "<<material<<" not found, cannot build the detector shell! "<<G4endl;
		return 0;
	}

	G4VisAttributes* visAtt = new G4VisAttributes(G4Colour(0.5,0.5,0.0));
	
    visAtt->SetVisibility(true);
	
    G4Box* DSSSDpixel = BuildPixel();

	G4ThreeVector direction 	= G4ThreeVector(0,0,0);
	G4double zPosition		= 0.0*mm;
	G4ThreeVector move 		= zPosition * direction;
	G4RotationMatrix* rotateeeeee  = new G4RotationMatrix;
		
	if(fDSSSDpixelLog == nullptr) 
    {
		fDSSSDpixelLog = new G4LogicalVolume(DSSSDpixel, material, "DSSSDpixelLog", 0, 0, 0);
		fDSSSDpixelLog->SetVisAttributes(visAtt);
	}

	//fAssembly->AddPlacedVolume(fDSSSDpixelLog, move, rotate);
    
    G4ThreeVector moveSi;
    G4RotationMatrix* rotate;// Generic rotation object for cube faces.

    // MakeImprint variables. Y rotation to line up beam gap with incoming beam.
    G4ThreeVector Ta;
    G4RotationMatrix* Ra = new G4RotationMatrix;
    Ra->rotateY(315.0*deg);

    // Loop over 6 faces of the RCMP cube:
        // i==0,1 - Front and Back (z displacement) faces
        // i==2,3 - Top and Bottom (y-displacement) faces
        // i==4,5 - Left and Right (x displacement) faces
    for(G4int i=0; i<6; i++){

        //movePCB = G4ThreeVector(trans[i][0], trans[i][1], trans[i][2]);
        moveSi =  G4ThreeVector(trans[i][0], trans[i][1], trans[i][2]);

        rotate = new G4RotationMatrix(rot[i][0], rot[i][1], rot[i][2]);

        fAssembly->AddPlacedVolume(fDSSSDpixelLog, moveSi, rotate);
        //fAssembly_PCB->AddPlacedVolume(fRCMPPCB_log, movePCB, rotate);

        fAssembly->MakeImprint(expHallLog, Ta, Ra, i);
        //fAssembly_PCB->MakeImprint(expHallLog, Ta, Ra, i);
    }
    return 1;
}

G4int DetectionSystemRCMP::BuildPixelVolume() 
{

	return 1;
}

G4Box* DetectionSystemRCMP::BuildPixel() 
{
	G4double halfLengthX = fPixelWidth/2.0;
	G4double halfLengthY = fPixelWidth/2.0;
	G4double halfLengthZ = fDetectorThickness/2.0;
	
    G4Box* pixel = new G4Box("pixel", halfLengthX, halfLengthY, halfLengthZ);

	return pixel;
}
