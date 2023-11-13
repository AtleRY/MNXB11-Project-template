#indef __Analys1_H__
#define __Analys1_H__

#include <TObject.h>
#include <TTree.h>

class Analys1 : public TObject{
    public:
    Analys1();
    Analys1(Int_t year, Int_t month, Int_t day, Int_t hour, Double_t temp, String_t grade,
     Double_t px, Double_t py, Double_t pz);
     virtual ~Analys1();
     Double_t Phi();
     Double_t Pt();


    private:
        Int_t year;
        Int_t month;
        Int_t day;
        Int_t hour;
         Double_t temp;
        String_t grade;
        Double_t px;
        Double_t py;
        Double_t pz;

        TTree *L;
        void InitializeTTree();
    ClassDef(Analys1, 1);
}
#endif //Analys1_H