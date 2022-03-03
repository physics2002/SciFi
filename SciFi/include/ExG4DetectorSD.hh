#include <G4VSensitiveDetector.hh>
#ifndef ExG4DetectorSD_h
#define ExG4DetectorSD_h 1
   class G4Step;
   class G4TouchableHistory;
   /// Класс определения чуствительной области детектора
   class ExG4DetectorSD: public G4VSensitiveDetector
     {
     public:
       //Контструктора, в нем обнулим гистограммы
        ExG4DetectorSD(G4String name);
        //Декструктор, в нем выведем гистораммы в файл
        //Вывод данных в файл лучше делать здесь чем в ProcessHits, так
        //вызов деструктора происходит в конце работы программы,
        //а если записывать в процессе моделирования, то значительное
        //время будет тратится на ожидание записи в файл, а это относительно
        //медленная процедура и занимает много времени. В результате
        //моделирование будет занимать больше времени чем нужно.
        ~ExG4DetectorSD();
        //Когда частица попадает в этот чуствительный объем, тогда на каждом
        //шаге моделирования вызывается эта функция,
        //в ней мы можем получить и передать информацию о состоянии
        //частицы, и ее треке
        G4bool ProcessHits(G4Step* step, G4TouchableHistory*);
        //void EndOfEvent(int nEvent);
     };
#endif /* SENSITIVEDETECTOR */
