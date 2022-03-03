// Подключаем заголовочные файлы
#ifdef G4MULTITHREADED
#include "G4MTRunManager.hh"
#else
#include "G4RunManager.hh"
#endif// RunManager, класс из ядра Geant4,
//должен быть включен обязательно
#include "G4UImanager.hh" // Менеджер взаимодействия с пользователем
#include "ExG4DetectorConstruction01.hh" // Структура детектора,
//должен определяться пользователем
#include "FTFP_BERT.hh" // Подключается физика и частицы
// используемые в проекте, использов предопределенный в Geant4
#include "ExG4ActionInitialization01.hh" // Пользовательские классы
//для получения данных о процессе моделирования
#include "G4VisExecutive.hh"//Визуализация
#include "G4UIExecutive.hh"//Выбор соответствуещего интерфейса пользователя

int main(int argc,char** argv)
{
    // Detect interactive mode (if no arguments) and define UI session
     //
     G4UIExecutive* ui = 0;
     if ( argc == 1 )
     {
       ui = new G4UIExecutive(argc, argv);
     }
    //cout << "This is just test message" <<"\n";
//Изменение зерна случайного числа, в качестве зенна берется текущее время
//Суть этой операции в том, что бы при каждом новом запуске генерировалась
//новая последовательность случайных чисел, иначе она будет все время одной
//и тойже, т.е. получаемые события будут одни и теже
   CLHEP::HepRandom::setTheEngine(new CLHEP::RanecuEngine);
   CLHEP::HepRandom::setTheSeed(time(NULL));
// construct the default run manager
// Создание класс G4RunManager, он управляет течением программы и
// управляет событиями при запуске проекта
G4RunManager* runManager = new G4RunManager;
// set mandatory initialization classes
// Установка обязательных инициализирующих классов
// Создание и определение детекторов и материалов
runManager->SetUserInitialization(new ExG4DetectorConstruction01);
// Создание физического листа - частиц и физических процессов
// в которых они участвуют, используется предопределенный в Geant4
runManager->SetUserInitialization(new FTFP_BERT);
// Определение начальных частиц, и прочие классы используемые
// для получения данных о частицах в процессе моделирования
runManager->SetUserInitialization(new ExG4ActionInitialization01);
// initialize G4 kernel
// Инициализация ядра Geant4
runManager->Initialize();
// Initialise Visualization Manager.
// Инициализация менеджера визуализации
G4VisManager* visManager = new G4VisExecutive;
visManager->Initialize();
// get the pointer to the UI manager and set verbosities
// Получение указателя на менеджера взаимодействия с пользователем
// нужен, что бы можно было отправлять команды в проект
G4UImanager* UImanager = G4UImanager::GetUIpointer();
// Process macro or start UI session
//

if ( ! ui ) {
  // batch mode
  G4String command = "/control/execute ";
  G4String fileName = argv[1];
  UImanager->ApplyCommand(command+fileName);
    //std::cout << aRun;
}
else {
  // interactive mode
  UImanager->ApplyCommand("/control/execute init_vis.mac");
  ui->SessionStart();
  delete ui;
}

// Окончание работы, вызов деструктора (удаление) G4RunManager
 delete visManager;
 delete runManager;
return 0;
}
