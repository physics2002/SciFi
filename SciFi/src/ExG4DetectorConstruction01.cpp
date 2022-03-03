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
/// \file ExG4DetectorConstruction01.cpp
/// \brief Implementation of the ExG4DetectorConstruction01 class

#include "ExG4DetectorConstruction01.hh"
#include "ExG4DetectorSD.hh"
#include "G4RunManager.hh"
#include "G4SDManager.hh"
#include "G4NistManager.hh"
#include "G4Box.hh"
#include "G4Tubs.hh"
#include "G4RotationMatrix.hh"
#include "G4LogicalVolume.hh"
#include "G4PVPlacement.hh"
#include "G4SystemOfUnits.hh"

//....oooOO0OOooo........oooOO0OOooo........oooOO0OOooo........oooOO0OOooo......
//Создание детектора, всего моделируемого объема
ExG4DetectorConstruction01::ExG4DetectorConstruction01()
: G4VUserDetectorConstruction()
{ }

//....oooOO0OOooo........oooOO0OOooo........oooOO0OOooo........oooOO0OOooo......

ExG4DetectorConstruction01::~ExG4DetectorConstruction01()
{ }

//....oooOO0OOooo........oooOO0OOooo........oooOO0OOooo........oooOO0OOooo......
//Создаем детекторы

G4VPhysicalVolume* ExG4DetectorConstruction01::Construct()
{  
  // Get nist material manager
  // Для обучения используем предопределенные в Geant4 материалы
  // Так объявляется менеджер, из которого их можно извлечь
  //
  G4NistManager* nist = G4NistManager::Instance();
    
//-------------------------------------------------------------------------------------------
  // Detector parameters
  // Параметры детектора,
  //
//  G4double det_sizeXY = 25*cm, det_sizeZ = 0.15*cm;

  // Материал детектора, здесь вольфрам
  //
  G4Material* det_mat = nist->FindOrBuildMaterial("G4_POLYSTYRENE");
  //G4Material* det_mat = nist->FindOrBuildMaterial("G4_POLYETHYLENE");
/*
  // Option to switch on/off checking of volumes overlaps
  // Опция для включения выключения проверки перекрытия объемов
*/
  G4bool checkOverlaps = true;

//-------------------------------------------------------------------------------------------
    
  // Detector parameters
  // Параметры детектора,
  //
  //В этой части программы описывается цилиндр из полистерола (М.Г. Коротков)
  G4double innerRadius = 0.*cm;
  G4double outerRadius = 0.0125*cm;
  G4double hx = 0.5*cm;
  G4double startAngle = 0.*deg;
  G4double spanningAngle = 360.*deg;
  G4double zShift = outerRadius*1.7320508075688772;
  
  G4RotationMatrix rotm  = G4RotationMatrix();
  rotm.rotateY(90*deg);
    
  G4ThreeVector position11 = G4ThreeVector(0,0,0*cm);
  G4Transform3D transform11 = G4Transform3D(rotm,position11);
    
  G4ThreeVector position12 = G4ThreeVector(0,0.025*cm,0*cm);
  G4Transform3D transform12 = G4Transform3D(rotm,position12);
    
  G4ThreeVector position13 = G4ThreeVector(0,-0.025*cm,0*cm);
  G4Transform3D transform13 = G4Transform3D(rotm,position13);

  G4ThreeVector position21 = G4ThreeVector(0,0.0125*cm,zShift);
  G4Transform3D transform21 = G4Transform3D(rotm,position21);

  G4ThreeVector position22 = G4ThreeVector(0,-0.0125*cm,zShift);
  G4Transform3D transform22 = G4Transform3D(rotm,position22);
    
  G4ThreeVector position23 = G4ThreeVector(0,0.0375*cm,zShift);
  G4Transform3D transform23 = G4Transform3D(rotm,position23);
    
  G4ThreeVector position24 = G4ThreeVector(0,-0.0375*cm,zShift);
  G4Transform3D transform24 = G4Transform3D(rotm,position24);
    
  G4ThreeVector position31 = G4ThreeVector(0,0,2*zShift);
  G4Transform3D transform31 = G4Transform3D(rotm,position31);
    
  G4ThreeVector position32 = G4ThreeVector(0,0.025*cm,2*zShift);
  G4Transform3D transform32 = G4Transform3D(rotm,position32);

  G4ThreeVector position33 = G4ThreeVector(0,-0.025*cm,2*zShift);
  G4Transform3D transform33 = G4Transform3D(rotm,position33);


  G4ThreeVector position41 = G4ThreeVector(0,0.0125*cm,3*zShift);
  G4Transform3D transform41 = G4Transform3D(rotm,position41);
    
  G4ThreeVector position42 = G4ThreeVector(0,-0.0125*cm,3*zShift);
  G4Transform3D transform42 = G4Transform3D(rotm,position42);
    
  G4ThreeVector position43 = G4ThreeVector(0,0.0375*cm,3*zShift);
  G4Transform3D transform43 = G4Transform3D(rotm,position43);
    
  G4ThreeVector position44 = G4ThreeVector(0,-0.0375*cm,3*zShift);
  G4Transform3D transform44 = G4Transform3D(rotm,position44);
    
  G4ThreeVector position51 = G4ThreeVector(0,0,4*zShift);
  G4Transform3D transform51 = G4Transform3D(rotm,position51);
    
  G4ThreeVector position52 = G4ThreeVector(0,0.025*cm,4*zShift);
  G4Transform3D transform52 = G4Transform3D(rotm,position52);
    
  G4ThreeVector position53 = G4ThreeVector(0,-0.025*cm,4*zShift);
  G4Transform3D transform53 = G4Transform3D(rotm,position53);
    
  G4ThreeVector position61 = G4ThreeVector(0,0.0125*cm,5*zShift);
  G4Transform3D transform61 = G4Transform3D(rotm,position61);
    
  G4ThreeVector position62 = G4ThreeVector(0,-0.0125*cm,5*zShift);
  G4Transform3D transform62 = G4Transform3D(rotm,position62);
    
  G4ThreeVector position63 = G4ThreeVector(0,0.0375*cm,5*zShift);
  G4Transform3D transform63 = G4Transform3D(rotm,position43);
    
  G4ThreeVector position64 = G4ThreeVector(0,-0.0375*cm,5*zShift);
  G4Transform3D transform64 = G4Transform3D(rotm,position64);

    
    
    
    
  //
  // World
  // Мир, самый большой объем, включающий остальные, аналог экспериментального
  // зала
  //
  G4double world_sizeXY = 1.5*cm;//Размер по x и y будут одинаковы - ширина и высота
  G4double world_sizeZ  = 1.5*cm;//Размер по z - толщина
  // Выбор материала для мира из предопределенных в Geant4, берем воздух
  G4Material* world_mat = nist->FindOrBuildMaterial("G4_Galactic");

  // Создание объема для мира, определяется просто сама форма объема, берем параллелепипед
  G4Box* solidWorld =
    new G4Box("World",                       //its name, название объема
       0.5*world_sizeXY, 0.5*world_sizeXY, 0.5*world_sizeZ);     //its size, его размеры
    
    

  // Логический объем, здесь подключается материал, из которого сделан объем
  G4LogicalVolume* logicWorld =                         
    new G4LogicalVolume(solidWorld,          //its solid, объем
                        world_mat,           //its material, материал объема
                        "World");            //its name, название логического объема
                                             //совпадает с названием объема, но
                                             //для Geant4 это разные объекты
                                             //объем и логический объем

  //Физический объем, а теперь наш логический объем помещаем в "ральный" мир
  G4VPhysicalVolume* physWorld = 
    new G4PVPlacement(0,                     //no rotation, нет вращения
                      G4ThreeVector(),       //at (0,0,0), расположение в центре (0,0,0)
                      logicWorld,            //its logical volume, логический объем этого физического
                      "World",               //its name, название физического объема
                      0,                     //its mother  volume, материнский объем, этот самый первый
                      false,                 //no boolean operation, без логических (булевых) операций
                      0,                     //copy number, номер копии
                      checkOverlaps);        //overlaps checking, флаг проверки перекрытия объемов
                     
  ///////////////////////////////////////////////////////////////////////////////////////////

  G4Tubs* solidDet11
    = new G4Tubs("Detector11",
                 innerRadius,
                 outerRadius,
                 hx,
                 startAngle,
                 spanningAngle);

  //Логический объем
  G4LogicalVolume* logicDet11 =
    new G4LogicalVolume(solidDet11,            //its solid, объем
                        det_mat,             //its material, указываем материал детектора
                        "Detector11");         //its name, его имя

  //Физический объем детектора
  
  new G4PVPlacement(transform11,               //rotation
                    logicDet11,                //its logical volume, подключаем логический объем
                    "Detector11",              //its name, имя физического объема
                    logicWorld,              //its mother  volume, родительский логический объем!
                    false,                   //no boolean operation, без булевых операций
                    0,                       //copy number, номер копии
                    checkOverlaps);          //overlaps checking, флаг проверки перекрытия объемов

///////////////////////////////////////////////////////////////////////////////////////////////
    

    
    G4Tubs* solidDet12
    = new G4Tubs("Detector12",
                 innerRadius,
                 outerRadius,
                 hx,
                 startAngle,
                 spanningAngle);
    
    //Логический объем
    G4LogicalVolume* logicDet12 =
    new G4LogicalVolume(solidDet12,            //its solid, объем
                        det_mat,             //its material, указываем материал детектора
                        "Detector12");         //its name, его имя
    
    //Физический объем детектора
    
    new G4PVPlacement(transform12,               //rotation
                      logicDet12,                //its logical volume, подключаем логический объем
                      "Detector12",              //its name, имя физического объема
                      logicWorld,              //its mother  volume, родительский логический объем!
                      false,                   //no boolean operation, без булевых операций
                      0,                       //copy number, номер копии
                      checkOverlaps);          //overlaps checking, флаг проверки перекрытия объемов


///////////////////////////////////////////////////////////////////////////////////////////////
    
    
    
    
    G4Tubs* solidDet13
    = new G4Tubs("Detector13",
                 innerRadius,
                 outerRadius,
                 hx,
                 startAngle,
                 spanningAngle);
    
    //Логический объем
    G4LogicalVolume* logicDet13 =
    new G4LogicalVolume(solidDet13,            //its solid, объем
                        det_mat,             //its material, указываем материал детектора
                        "Detector13");         //its name, его имя
    
    //Физический объем детектора
    
    new G4PVPlacement(transform13,               //rotation
                      logicDet13,                //its logical volume, подключаем логический объем
                      "Detector13",              //its name, имя физического объема
                      logicWorld,              //its mother  volume, родительский логический объем!
                      false,                   //no boolean operation, без булевых операций
                      0,                       //copy number, номер копии
                      checkOverlaps);          //overlaps checking, флаг проверки перекрытия объемов
    
    
    ///////////////////////////////////////////////////////////////////////////////////////////////
    

    
    
    G4Tubs* solidDet21
    = new G4Tubs("Detector21",
                 innerRadius,
                 outerRadius,
                 hx,
                 startAngle,
                 spanningAngle);
    
    //Логический объем
    G4LogicalVolume* logicDet21 =
    new G4LogicalVolume(solidDet21,            //its solid, объем
                        det_mat,             //its material, указываем материал детектора
                        "Detector21");         //its name, его имя
    
    //Физический объем детектора

    
    new G4PVPlacement(transform21,               //rotation
                      logicDet21,                //its logical volume, подключаем логический объем
                      "Detector21",              //its name, имя физического объема
                      logicWorld,              //its mother  volume, родительский логический объем!
                      false,                   //no boolean operation, без булевых операций
                      0,                       //copy number, номер копии
                      checkOverlaps);          //overlaps checking, флаг проверки перекрытия объемов

    
    
    ///////////////////////////////////////////////////////////////////////////////////////////////
    
    
    G4Tubs* solidDet22
    = new G4Tubs("Detector22",
                 innerRadius,
                 outerRadius,
                 hx,
                 startAngle,
                 spanningAngle);
    
    //Логический объем
    G4LogicalVolume* logicDet22 =
    new G4LogicalVolume(solidDet22,            //its solid, объем
                        det_mat,             //its material, указываем материал детектора
                        "Detector22");         //its name, его имя
    
    //Физический объем детектора
    
    
    new G4PVPlacement(transform22,               //rotation
                      logicDet22,                //its logical volume, подключаем логический объем
                      "Detector22",              //its name, имя физического объема
                      logicWorld,              //its mother  volume, родительский логический объем!
                      false,                   //no boolean operation, без булевых операций
                      0,                       //copy number, номер копии
                      checkOverlaps);          //overlaps checking, флаг проверки перекрытия объемов
    
    
    ///////////////////////////////////////////////////////////////////////////////////////////////
    
    
    G4Tubs* solidDet23
    = new G4Tubs("Detector23",
                 innerRadius,
                 outerRadius,
                 hx,
                 startAngle,
                 spanningAngle);
    
    //Логический объем
    G4LogicalVolume* logicDet23 =
    new G4LogicalVolume(solidDet23,            //its solid, объем
                        det_mat,             //its material, указываем материал детектора
                        "Detector23");         //its name, его имя
    
    //Физический объем детектора
    
    
    new G4PVPlacement(transform23,               //rotation
                      logicDet23,                //its logical volume, подключаем логический объем
                      "Detector23",              //its name, имя физического объема
                      logicWorld,              //its mother  volume, родительский логический объем!
                      false,                   //no boolean operation, без булевых операций
                      0,                       //copy number, номер копии
                      checkOverlaps);          //overlaps checking, флаг проверки перекрытия объемов


 
    
    
    ///////////////////////////////////////////////////////////////////////////////////////////////
    
    
    G4Tubs* solidDet24
    = new G4Tubs("Detector24",
                 innerRadius,
                 outerRadius,
                 hx,
                 startAngle,
                 spanningAngle);
    
    //Логический объем
    G4LogicalVolume* logicDet24 =
    new G4LogicalVolume(solidDet24,            //its solid, объем
                        det_mat,             //its material, указываем материал детектора
                        "Detector24");         //its name, его имя
    
    //Физический объем детектора
    
    
    new G4PVPlacement(transform24,               //rotation
                      logicDet24,                //its logical volume, подключаем логический объем
                      "Detector24",              //its name, имя физического объема
                      logicWorld,              //its mother  volume, родительский логический объем!
                      false,                   //no boolean operation, без булевых операций
                      0,                       //copy number, номер копии
                      checkOverlaps);          //overlaps checking, флаг проверки перекрытия объемов
    


    ///////////////////////////////////////////////////////////////////////////////////////////////
    
    
    
    
    G4Tubs* solidDet31
    = new G4Tubs("Detector31",
                 innerRadius,
                 outerRadius,
                 hx,
                 startAngle,
                 spanningAngle);
    
    //Логический объем
    G4LogicalVolume* logicDet31 =
    new G4LogicalVolume(solidDet31,            //its solid, объем
                        det_mat,             //its material, указываем материал детектора
                        "Detector31");         //its name, его имя
    
    //Физический объем детектора
    
    
    new G4PVPlacement(transform31,               //rotation
                      logicDet31,                //its logical volume, подключаем логический объем
                      "Detector31",              //its name, имя физического объема
                      logicWorld,              //its mother  volume, родительский логический объем!
                      false,                   //no boolean operation, без булевых операций
                      0,                       //copy number, номер копии
                      checkOverlaps);          //overlaps checking, флаг проверки перекрытия объемов
    
    
    
    ///////////////////////////////////////////////////////////////////////////////////////////////

  
    G4Tubs* solidDet32
    = new G4Tubs("Detector32",
                 innerRadius,
                 outerRadius,
                 hx,
                 startAngle,
                 spanningAngle);
    
    //Логический объем
    G4LogicalVolume* logicDet32 =
    new G4LogicalVolume(solidDet32,            //its solid, объем
                        det_mat,             //its material, указываем материал детектора
                        "Detector32");         //its name, его имя
    
    //Физический объем детектора
    
    
    new G4PVPlacement(transform32,               //rotation
                      logicDet32,                //its logical volume, подключаем логический объем
                      "Detector32",              //its name, имя физического объема
                      logicWorld,              //its mother  volume, родительский логический объем!
                      false,                   //no boolean operation, без булевых операций
                      0,                       //copy number, номер копии
                      checkOverlaps);          //overlaps checking, флаг проверки перекрытия объемов
    
    
    
    ///////////////////////////////////////////////////////////////////////////////////////////////
    

    
    G4Tubs* solidDet33
    = new G4Tubs("Detector33",
                 innerRadius,
                 outerRadius,
                 hx,
                 startAngle,
                 spanningAngle);
    
    //Логический объем
    G4LogicalVolume* logicDet33 =
    new G4LogicalVolume(solidDet33,            //its solid, объем
                        det_mat,             //its material, указываем материал детектора
                        "Detector33");         //its name, его имя
    
    //Физический объем детектора
    
    
    new G4PVPlacement(transform33,               //rotation
                      logicDet33,                //its logical volume, подключаем логический объем
                      "Detector33",              //its name, имя физического объема
                      logicWorld,              //its mother  volume, родительский логический объем!
                      false,                   //no boolean operation, без булевых операций
                      0,                       //copy number, номер копии
                      checkOverlaps);          //overlaps checking, флаг проверки перекрытия объемов
    
    
    

    
    
    
    ///////////////////////////////////////////////////////////////////////////////////////////////
    
    
    
    
    G4Tubs* solidDet41
    = new G4Tubs("Detector41",
                 innerRadius,
                 outerRadius,
                 hx,
                 startAngle,
                 spanningAngle);
    
    //Логический объем
    G4LogicalVolume* logicDet41 =
    new G4LogicalVolume(solidDet41,            //its solid, объем
                        det_mat,             //its material, указываем материал детектора
                        "Detector41");         //its name, его имя
    
    //Физический объем детектора
    
    
    new G4PVPlacement(transform41,               //rotation
                      logicDet41,                //its logical volume, подключаем логический объем
                      "Detector41",              //its name, имя физического объема
                      logicWorld,              //its mother  volume, родительский логический объем!
                      false,                   //no boolean operation, без булевых операций
                      0,                       //copy number, номер копии
                      checkOverlaps);          //overlaps checking, флаг проверки перекрытия объемов
    
    
    
    ///////////////////////////////////////////////////////////////////////////////////////////////
    
    
    G4Tubs* solidDet42
    = new G4Tubs("Detector42",
                 innerRadius,
                 outerRadius,
                 hx,
                 startAngle,
                 spanningAngle);
    
    //Логический объем
    G4LogicalVolume* logicDet42 =
    new G4LogicalVolume(solidDet42,            //its solid, объем
                        det_mat,             //its material, указываем материал детектора
                        "Detector42");         //its name, его имя
    
    //Физический объем детектора
    
    
    new G4PVPlacement(transform42,               //rotation
                      logicDet42,                //its logical volume, подключаем логический объем
                      "Detector42",              //its name, имя физического объема
                      logicWorld,              //its mother  volume, родительский логический объем!
                      false,                   //no boolean operation, без булевых операций
                      0,                       //copy number, номер копии
                      checkOverlaps);          //overlaps checking, флаг проверки перекрытия объемов
    
    
    ///////////////////////////////////////////////////////////////////////////////////////////////
    
    
    G4Tubs* solidDet43
    = new G4Tubs("Detector43",
                 innerRadius,
                 outerRadius,
                 hx,
                 startAngle,
                 spanningAngle);
    
    //Логический объем
    G4LogicalVolume* logicDet43 =
    new G4LogicalVolume(solidDet43,            //its solid, объем
                        det_mat,             //its material, указываем материал детектора
                        "Detector43");         //its name, его имя
    
    //Физический объем детектора
    
    
    new G4PVPlacement(transform43,               //rotation
                      logicDet43,                //its logical volume, подключаем логический объем
                      "Detector43",              //its name, имя физического объема
                      logicWorld,              //its mother  volume, родительский логический объем!
                      false,                   //no boolean operation, без булевых операций
                      0,                       //copy number, номер копии
                      checkOverlaps);          //overlaps checking, флаг проверки перекрытия объемов
    
    
    
    
    
    ///////////////////////////////////////////////////////////////////////////////////////////////
    
    
    G4Tubs* solidDet44
    = new G4Tubs("Detector44",
                 innerRadius,
                 outerRadius,
                 hx,
                 startAngle,
                 spanningAngle);
    
    //Логический объем
    G4LogicalVolume* logicDet44 =
    new G4LogicalVolume(solidDet44,            //its solid, объем
                        det_mat,             //its material, указываем материал детектора
                        "Detector44");         //its name, его имя
    
    //Физический объем детектора
    
    
    new G4PVPlacement(transform44,               //rotation
                      logicDet44,                //its logical volume, подключаем логический объем
                      "Detector44",              //its name, имя физического объема
                      logicWorld,              //its mother  volume, родительский логический объем!
                      false,                   //no boolean operation, без булевых операций
                      0,                       //copy number, номер копии
                      checkOverlaps);          //overlaps checking, флаг проверки перекрытия объемов
    
   ///////////////////////////////////////////////////////////////////////////////////////////////
    
    
    G4Tubs* solidDet51
    = new G4Tubs("Detector51",
                 innerRadius,
                 outerRadius,
                 hx,
                 startAngle,
                 spanningAngle);
    
    //Логический объем
    G4LogicalVolume* logicDet51 =
    new G4LogicalVolume(solidDet51,            //its solid, объем
                        det_mat,             //its material, указываем материал детектора
                        "Detector51");         //its name, его имя
    
    //Физический объем детектора
    
    
    new G4PVPlacement(transform51,               //rotation
                      logicDet51,                //its logical volume, подключаем логический объем
                      "Detector51",              //its name, имя физического объема
                      logicWorld,              //its mother  volume, родительский логический объем!
                      false,                   //no boolean operation, без булевых операций
                      0,                       //copy number, номер копии
                      checkOverlaps);          //overlaps checking, флаг проверки перекрытия объемов
    
    
    
    ///////////////////////////////////////////////////////////////////////////////////////////////
    
    
    G4Tubs* solidDet52
    = new G4Tubs("Detector52",
                 innerRadius,
                 outerRadius,
                 hx,
                 startAngle,
                 spanningAngle);
    
    //Логический объем
    G4LogicalVolume* logicDet52 =
    new G4LogicalVolume(solidDet52,            //its solid, объем
                        det_mat,             //its material, указываем материал детектора
                        "Detector52");         //its name, его имя
    
    //Физический объем детектора
    
    
    new G4PVPlacement(transform52,               //rotation
                      logicDet52,                //its logical volume, подключаем логический объем
                      "Detector52",              //its name, имя физического объема
                      logicWorld,              //its mother  volume, родительский логический объем!
                      false,                   //no boolean operation, без булевых операций
                      0,                       //copy number, номер копии
                      checkOverlaps);          //overlaps checking, флаг проверки перекрытия объемов
    
    
    
    ///////////////////////////////////////////////////////////////////////////////////////////////
    
    
    
    G4Tubs* solidDet53
    = new G4Tubs("Detector53",
                 innerRadius,
                 outerRadius,
                 hx,
                 startAngle,
                 spanningAngle);
    
    //Логический объем
    G4LogicalVolume* logicDet53 =
    new G4LogicalVolume(solidDet53,            //its solid, объем
                        det_mat,             //its material, указываем материал детектора
                        "Detector53");         //its name, его имя
    
    //Физический объем детектора
    
    
    new G4PVPlacement(transform53,               //rotation
                      logicDet53,                //its logical volume, подключаем логический объем
                      "Detector53",              //its name, имя физического объема
                      logicWorld,              //its mother  volume, родительский логический объем!
                      false,                   //no boolean operation, без булевых операций
                      0,                       //copy number, номер копии
                      checkOverlaps);          //overlaps checking, флаг проверки перекрытия объемов
    
    
    
    
    
    
    
    ///////////////////////////////////////////////////////////////////////////////////////////////
    
    
    ///////////////////////////////////////////////////////////////////////////////////////////////
    
    
    
    
    G4Tubs* solidDet61
    = new G4Tubs("Detector61",
                 innerRadius,
                 outerRadius,
                 hx,
                 startAngle,
                 spanningAngle);
    
    //Логический объем
    G4LogicalVolume* logicDet61 =
    new G4LogicalVolume(solidDet61,            //its solid, объем
                        det_mat,             //its material, указываем материал детектора
                        "Detector61");         //its name, его имя
    
    //Физический объем детектора
    
    
    new G4PVPlacement(transform61,               //rotation
                      logicDet61,                //its logical volume, подключаем логический объем
                      "Detector61",              //its name, имя физического объема
                      logicWorld,              //its mother  volume, родительский логический объем!
                      false,                   //no boolean operation, без булевых операций
                      0,                       //copy number, номер копии
                      checkOverlaps);          //overlaps checking, флаг проверки перекрытия объемов
    
    
    
    ///////////////////////////////////////////////////////////////////////////////////////////////
    
    
    G4Tubs* solidDet62
    = new G4Tubs("Detector62",
                 innerRadius,
                 outerRadius,
                 hx,
                 startAngle,
                 spanningAngle);
    
    //Логический объем
    G4LogicalVolume* logicDet62 =
    new G4LogicalVolume(solidDet62,            //its solid, объем
                        det_mat,             //its material, указываем материал детектора
                        "Detector62");         //its name, его имя
    
    //Физический объем детектора
    
    
    new G4PVPlacement(transform62,               //rotation
                      logicDet62,                //its logical volume, подключаем логический объем
                      "Detector62",              //its name, имя физического объема
                      logicWorld,              //its mother  volume, родительский логический объем!
                      false,                   //no boolean operation, без булевых операций
                      0,                       //copy number, номер копии
                      checkOverlaps);          //overlaps checking, флаг проверки перекрытия объемов
    
    
    ///////////////////////////////////////////////////////////////////////////////////////////////
    
    
    G4Tubs* solidDet63
    = new G4Tubs("Detector63",
                 innerRadius,
                 outerRadius,
                 hx,
                 startAngle,
                 spanningAngle);
    
    //Логический объем
    G4LogicalVolume* logicDet63 =
    new G4LogicalVolume(solidDet63,            //its solid, объем
                        det_mat,             //its material, указываем материал детектора
                        "Detector63");         //its name, его имя
    
    //Физический объем детектора
    
    
    new G4PVPlacement(transform63,               //rotation
                      logicDet63,                //its logical volume, подключаем логический объем
                      "Detector63",              //its name, имя физического объема
                      logicWorld,              //its mother  volume, родительский логический объем!
                      false,                   //no boolean operation, без булевых операций
                      0,                       //copy number, номер копии
                      checkOverlaps);          //overlaps checking, флаг проверки перекрытия объемов
    
    
    
    
    
    ///////////////////////////////////////////////////////////////////////////////////////////////
    
    
    G4Tubs* solidDet64
    = new G4Tubs("Detector64",
                 innerRadius,
                 outerRadius,
                 hx,
                 startAngle,
                 spanningAngle);
    
    //Логический объем
    G4LogicalVolume* logicDet64 =
    new G4LogicalVolume(solidDet64,            //its solid, объем
                        det_mat,             //its material, указываем материал детектора
                        "Detector64");         //its name, его имя
    
    //Физический объем детектора
    
    
    new G4PVPlacement(transform64,               //rotation
                      logicDet64,                //its logical volume, подключаем логический объем
                      "Detector64",              //its name, имя физического объема
                      logicWorld,              //its mother  volume, родительский логический объем!
                      false,                   //no boolean operation, без булевых операций
                      0,                       //copy number, номер копии
                      checkOverlaps);          //overlaps checking, флаг проверки перекрытия объемов
    
    ///////////////////////////////////////////////////////////////////////////////////////////////
    

    
    //always return the physical World
  //Всегда возвращает физический объем
  //
 
  return physWorld;
}

//....oooOO0OOooo........oooOO0OOooo........oooOO0OOooo........oooOO0OOooo......


void ExG4DetectorConstruction01::ConstructSDandField()
{
  // Sensitive detectors
  // Объявление чуствительной области детектора, где можно получить подробную
  // информацию о состоянии и движении частицы
  // Назовем чуствительную область DetectorSD
  G4String trackerChamberSD11name = "Detector11SD";
  G4String trackerChamberSD21name = "Detector21SD";
  G4String trackerChamberSD31name = "Detector31SD";
  G4String trackerChamberSD41name = "Detector41SD";
  G4String trackerChamberSD51name = "Detector51SD";
  G4String trackerChamberSD61name = "Detector61SD";
    
  G4String trackerChamberSD12name = "Detector12SD";
  G4String trackerChamberSD22name = "Detector22SD";
  G4String trackerChamberSD32name = "Detector32SD";
  G4String trackerChamberSD42name = "Detector42SD";
  G4String trackerChamberSD52name = "Detector52SD";
  G4String trackerChamberSD62name = "Detector62SD";
    
  G4String trackerChamberSD13name = "Detector13SD";
  G4String trackerChamberSD23name = "Detector23SD";
  G4String trackerChamberSD33name = "Detector33SD";
  G4String trackerChamberSD43name = "Detector43SD";
  G4String trackerChamberSD53name = "Detector53SD";
  G4String trackerChamberSD63name = "Detector63SD";
    
  G4String trackerChamberSD24name = "Detector24SD";
  G4String trackerChamberSD44name = "Detector44SD";
  G4String trackerChamberSD64name = "Detector64SD";


    
  // Создаем экземпляр чуствительной области
  ExG4DetectorSD* aTrackerSD11 = new ExG4DetectorSD(trackerChamberSD11name);
  ExG4DetectorSD* aTrackerSD21 = new ExG4DetectorSD(trackerChamberSD21name);
  ExG4DetectorSD* aTrackerSD31 = new ExG4DetectorSD(trackerChamberSD31name);
  ExG4DetectorSD* aTrackerSD41 = new ExG4DetectorSD(trackerChamberSD41name);
  ExG4DetectorSD* aTrackerSD51 = new ExG4DetectorSD(trackerChamberSD51name);
  ExG4DetectorSD* aTrackerSD61 = new ExG4DetectorSD(trackerChamberSD61name);
    
  ExG4DetectorSD* aTrackerSD12 = new ExG4DetectorSD(trackerChamberSD12name);
  ExG4DetectorSD* aTrackerSD22 = new ExG4DetectorSD(trackerChamberSD22name);
  ExG4DetectorSD* aTrackerSD32 = new ExG4DetectorSD(trackerChamberSD32name);
  ExG4DetectorSD* aTrackerSD42 = new ExG4DetectorSD(trackerChamberSD42name);
  ExG4DetectorSD* aTrackerSD52 = new ExG4DetectorSD(trackerChamberSD52name);
  ExG4DetectorSD* aTrackerSD62 = new ExG4DetectorSD(trackerChamberSD62name);
    
  ExG4DetectorSD* aTrackerSD13 = new ExG4DetectorSD(trackerChamberSD13name);
  ExG4DetectorSD* aTrackerSD23 = new ExG4DetectorSD(trackerChamberSD23name);
  ExG4DetectorSD* aTrackerSD33 = new ExG4DetectorSD(trackerChamberSD33name);
  ExG4DetectorSD* aTrackerSD43 = new ExG4DetectorSD(trackerChamberSD43name);
  ExG4DetectorSD* aTrackerSD53 = new ExG4DetectorSD(trackerChamberSD53name);
  ExG4DetectorSD* aTrackerSD63 = new ExG4DetectorSD(trackerChamberSD63name);
    
  ExG4DetectorSD* aTrackerSD24 = new ExG4DetectorSD(trackerChamberSD24name);
  ExG4DetectorSD* aTrackerSD44 = new ExG4DetectorSD(trackerChamberSD44name);
  ExG4DetectorSD* aTrackerSD64 = new ExG4DetectorSD(trackerChamberSD64name);
    

    

    


    
  // Передаем указатель менеджеру
  G4SDManager::GetSDMpointer()->AddNewDetector(aTrackerSD11);
  G4SDManager::GetSDMpointer()->AddNewDetector(aTrackerSD21);
  G4SDManager::GetSDMpointer()->AddNewDetector(aTrackerSD31);
  G4SDManager::GetSDMpointer()->AddNewDetector(aTrackerSD41);
  G4SDManager::GetSDMpointer()->AddNewDetector(aTrackerSD51);
  G4SDManager::GetSDMpointer()->AddNewDetector(aTrackerSD61);
    
  G4SDManager::GetSDMpointer()->AddNewDetector(aTrackerSD12);
  G4SDManager::GetSDMpointer()->AddNewDetector(aTrackerSD22);
  G4SDManager::GetSDMpointer()->AddNewDetector(aTrackerSD32);
  G4SDManager::GetSDMpointer()->AddNewDetector(aTrackerSD42);
  G4SDManager::GetSDMpointer()->AddNewDetector(aTrackerSD52);
  G4SDManager::GetSDMpointer()->AddNewDetector(aTrackerSD62);
    
  G4SDManager::GetSDMpointer()->AddNewDetector(aTrackerSD13);
  G4SDManager::GetSDMpointer()->AddNewDetector(aTrackerSD23);
  G4SDManager::GetSDMpointer()->AddNewDetector(aTrackerSD33);
  G4SDManager::GetSDMpointer()->AddNewDetector(aTrackerSD43);
  G4SDManager::GetSDMpointer()->AddNewDetector(aTrackerSD53);
  G4SDManager::GetSDMpointer()->AddNewDetector(aTrackerSD63);

  G4SDManager::GetSDMpointer()->AddNewDetector(aTrackerSD24);
  G4SDManager::GetSDMpointer()->AddNewDetector(aTrackerSD44);
  G4SDManager::GetSDMpointer()->AddNewDetector(aTrackerSD64);


    
    
  // Setting aTrackerSD to all logical volumes with the same name
  // of "Chamber_LV".
  // Добавляем чуствительный объем ко всем логическим областям с
  // именем Detector
  SetSensitiveDetector("Detector11", aTrackerSD11, true);
  SetSensitiveDetector("Detector21", aTrackerSD21, true);
  SetSensitiveDetector("Detector31", aTrackerSD31, true);
  SetSensitiveDetector("Detector41", aTrackerSD41, true);
  SetSensitiveDetector("Detector51", aTrackerSD51, true);
  SetSensitiveDetector("Detector61", aTrackerSD61, true);

  SetSensitiveDetector("Detector12", aTrackerSD11, true);
  SetSensitiveDetector("Detector22", aTrackerSD21, true);
  SetSensitiveDetector("Detector32", aTrackerSD31, true);
  SetSensitiveDetector("Detector42", aTrackerSD41, true);
  SetSensitiveDetector("Detector52", aTrackerSD51, true);
  SetSensitiveDetector("Detector62", aTrackerSD61, true);
    
  SetSensitiveDetector("Detector13", aTrackerSD11, true);
  SetSensitiveDetector("Detector23", aTrackerSD21, true);
  SetSensitiveDetector("Detector33", aTrackerSD31, true);
  SetSensitiveDetector("Detector43", aTrackerSD41, true);
  SetSensitiveDetector("Detector53", aTrackerSD51, true);
  SetSensitiveDetector("Detector63", aTrackerSD61, true);
    
    
  SetSensitiveDetector("Detector24", aTrackerSD21, true);
  SetSensitiveDetector("Detector44", aTrackerSD41, true);
  SetSensitiveDetector("Detector64", aTrackerSD61, true);



    
    
    
    
    
/*
    G4String trackerChamberSDname = "Detector21SD";
    // Создаем экземпляр чуствительной области
    ExG4DetectorSD* aTrackerSD = new ExG4DetectorSD(trackerChamberSDname);
    // Передаем указатель менеджеру
    G4SDManager::GetSDMpointer()->AddNewDetector(aTrackerSD);
    // Setting aTrackerSD to all logical volumes with the same name
    // of "Chamber_LV".
    // Добавляем чуствительный объем ко всем логическим областям с
    // именем Detector
    SetSensitiveDetector("Detector21", aTrackerSD, true);
*/
}
