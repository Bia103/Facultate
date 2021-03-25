#include <iostream>

using namespace std;
 class ZooAnimal
   {
    private:
      char* name;
      int cageNumber;
      int weightDate;
      int weight;
    public:
      ZooAnimal (char*, int, int, int); // constructor function
      inline ~ZooAnimal () { delete [] name; }; // destructor function
      void changeWeight (int pounds);
      char* reptName ();
      int reptWeight ();
      int daysSinceLastWeighed (int today);
   };

   class LargeAnimal:public ZooAnimal
   {
    private:
      char* species;
      float cageMinimumVolume;
    public:
      LargeAnimal (char*, int, int, int, float); // constructor function
      inline ~LargeAnimal () { delete [] species; }; // destructor function
      float reptCageMinimumVolume ();
   };
    char* LargeAnimal::reptName ()
   {
    return species;
   }
   LargeAnimal::LargeAnimal(char*, int, int, int, float)
   // ========== an application to use the LargeAnimal class
   void main ()
   {
    ZooAnimal bozo;
    LargeAnimal gonzo;

    cout << bozo.reptName () << endl;
    cout << gonzo.reptName () << endl;
   }


