#include <iostream>
#include <fstream>
#include <string>
#include <cassert>
#include "graaf.h"
#include "stopwatch.h"
#include <vector>
using std::cout;
using std::cerr;
using std::cin;
using std::endl;
using std::ostream;
using std::istream;
using std::ifstream;
using std::string;
int main(){
    Graaf<GERICHT> g;
    ifstream is;
    is.open("graafdichtste.dat");
    assert(is);
    is>>g;
    int aantknoop=g.aantalKnopen();
    cout<<endl<<"Test dichtste:"
        <<"(aantal knopen is "<<aantknoop<<')'<<endl<<endl;
    vector<int> doel(aantknoop/2);
    for (int i=0;i<aantknoop/2;i++)
        doel[i]=i+aantknoop/4+aantknoop/6;
    cout<<"doel gaat van "<<doel[0]<<" tot "<<doel[aantknoop/2-1]<<endl<<endl;
    Stopwatch sw;
    sw.start();
    cout<<"knoop dichtste bij 0 is "<<g.dichtste(0,doel)<<endl;
    sw.stop();
    cout<<"Het heeft "<<sw.tijd()<<" sekonden geduurd."<<endl;
    if (sw.tijd()>1.0)
        cout<<"Dat is wel verschrikkelijk traag."<<endl;
    cout<<endl;
    cout<<"knoop dichtste bij "<<aantknoop/2
        <<" is "<<g.dichtste(aantknoop/2,doel)<<endl;
    return 0;
}
        
        
