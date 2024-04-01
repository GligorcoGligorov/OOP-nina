#include <iostream>
#include <cstring>
#include <string.h>

using namespace std;

class Gitara{

private:

    char seriski[25];
    double cena;
    int godina;
    char tip[40];


public:



    Gitara(char *tip ="",char *seriski ="", int godina = 2024,double cena = 0.0){
        strcpy(this->tip, tip);
        strcpy(this->seriski, seriski);
        this->godina = godina;
        this->cena = cena;

    }

    Gitara(const Gitara &g){
        strcpy(this->tip, g.tip);
        strcpy(this->seriski, g.seriski);
        this->godina = g.godina;
        this->cena = g.cena;
    }

    Gitara &operator=(const Gitara &g){
        strcpy(this->tip, g.tip);
        strcpy(this->seriski, g.seriski);
        this->godina = g.godina;
        this->cena = g.cena;
        return *this;
    }

    ~Gitara(){
    }

    char *getSeriski(){
        return seriski;
    }

    double getNabavna(){
        return cena;
    }

    int getGodina(){
        return godina;
    }

    char *getTip(){
        return tip;
    }

    bool daliIsti(Gitara &g){
        if(strcmp(this->seriski, g.seriski) == 0){
            return true;
        }else{
            return false;
        }

    }

    void pecati(){
        cout << seriski << " " << tip << " " << cena << endl;
    }


};

class Magacin{

private:

    int godina;
    char ime[30];
    char lokacija[60];
    Gitara *gitari;
    int br_gitari;

public:

    Magacin(char *ime="", char *lokacija="",int godina = 2024){
        strcpy(this->ime,ime);
        strcpy(this->lokacija,lokacija);
        this->godina = godina;
        gitari = nullptr;
        br_gitari = 0;

    }

    Magacin(const Magacin &m){
        strcpy(this->ime,m.ime);
        strcpy(this->lokacija,m.lokacija);
        this->godina = m.godina;

        gitari = new Gitara[m.br_gitari];

        for(int i = 0;i < m.br_gitari;i++){
            gitari[i] = m.gitari[i];
        }

        br_gitari = m.br_gitari;


    }

    Magacin &operator=(const Magacin &m){
        delete []gitari;
        strcpy(this->ime,m.ime);
        strcpy(this->lokacija,m.lokacija);
        this->godina = m.godina;

        gitari = new Gitara[m.br_gitari];

        for(int i = 0;i < m.br_gitari;i++){
            gitari[i] = m.gitari[i];
        }

        br_gitari = m.br_gitari;

        return *this;


    }

    ~Magacin(){
        delete []gitari;
    }

    double vrednost(){

        float total = 0.0;

        for(int i =0;i < br_gitari;i++){
            total+= gitari[i].getNabavna();
        }

        return total;

    }

    void dodadi(Gitara g){
        //dolzina = 4, niza = [1,2,3], tmp = [1,2,3,g]

        Gitara *tmp = new Gitara[br_gitari+1];
        for(int i = 0;i < br_gitari;i++){
            tmp[i] = gitari[i];
        }
        tmp[br_gitari++] = g;
        delete []gitari;
        gitari = tmp;
    }

    void prodadi(Gitara g){
    //dolzina = 4, niza = ["asd","asd","ddd","aaa","bbb"], tmp = ["ddd","aaa","bbb"]

        int n_broj = 0;

        for(int i = 0;i < br_gitari;i++){
            if(gitari[i].daliIsti(g) == false){
                n_broj++;

            }
        }
       // tmp["ddd","aaa","bbb"], n_broj = 3
    //brojac = 0        1     2
        Gitara *tmp = new Gitara[n_broj];

        int brojac = 0;
        for(int i = 0;i < br_gitari;i++){
            if(gitari[i].daliIsti(g) == false){
                tmp[brojac] = gitari[i];
                brojac++;
            }
        }

        delete []gitari;
        gitari = tmp;
        br_gitari = n_broj;

    }

    void pecati(bool daliNovi){
        cout << ime << " " << lokacija << endl;

        for(int i = 0;i < br_gitari;i++){

            if(daliNovi==true && gitari[i].getGodina() > godina){
                gitari[i].pecati();
            }else if (!daliNovi){
                gitari[i].pecati();
            }

        }



    }

};

int main()
{
      int testCase;
    cin >> testCase;

	int n, godina;
	float cena;
	char seriski[50],tip[50];
	/*
5
4
tip3
aaa
2000
1500.5
tip1
asd
2005
1500.5
tip2
asd
2025
1500.5
tip4
bbb
2026
1500.5

*/

	if(testCase == 1) {
        cout << "===== Testiranje na klasata Gitara ======" << endl;
        cin>>tip;
        cin>>seriski;
        cin >> godina;
        cin >> cena;
        Gitara g(tip,seriski, godina,cena);
		cout<<g.getTip()<<endl;
		cout<<g.getSeriski()<<endl;
		cout<<g.getGodina()<<endl;
		cout<<g.getNabavna()<<endl;
    } else if(testCase == 2){
        cout << "===== Testiranje na klasata Magacin so metodot print() ======" << endl;
		Magacin kb("Magacin1","Lokacija1");
        kb.pecati(false);
	}
    else if(testCase == 3) {
        cout << "===== Testiranje na klasata Magacin so metodot dodadi() ======" << endl;
        Magacin kb("Magacin1","Lokacija1",2005);
		cin>>n;


			for (int i=0;i<n;i++){
                cin>>tip;
                cin>>seriski;
                cin >> godina;
                cin >> cena;
                Gitara g(tip,seriski, godina,cena);
                cout<<"gitara dodadi"<<endl;
				kb.dodadi(g);
			}
        kb.pecati(true);
    }

    else if(testCase == 4) {
        cout << "===== Testiranje na klasata Magacin so metodot prodadi() ======" << endl;
        Magacin kb("Magacin1","Lokacija1",2012);
            cin>>n;
            Gitara brisi;
			for (int i=0;i<n;i++){
                cin>>tip;
                cin>>seriski;
                cin >> godina;
                cin >> cena;

                Gitara g(tip,seriski, godina,cena);
                if(i==2)
                    brisi=g;
                cout<<"gitara dodadi"<<endl;
				kb.dodadi(g);
			}
        kb.pecati(false);
        kb.prodadi(brisi);
        kb.pecati(false);
    }
    else if(testCase == 5) {
        cout << "===== Testiranje na klasata Magacin so metodot prodadi() i pecati(true) ======" << endl;
        Magacin kb("Magacin1","Lokacija1",2011);
            cin>>n;
            Gitara brisi;
			for (int i=0;i<n;i++){
                cin>>tip;
                cin>>seriski;
                cin >> godina;
                cin >> cena;

                Gitara g(tip,seriski, godina,cena);
                if(i==2)
                    brisi=g;
                cout<<"gitara dodadi"<<endl;
				kb.dodadi(g);
			}
        kb.pecati(true);
        kb.prodadi(brisi);
        cout<<"Po brisenje:"<<endl;
        Magacin kb3;
        kb3=kb;
        kb3.pecati(true);
    }
   else if(testCase ==6)
        {
        cout << "===== Testiranje na klasata Magacin so metodot vrednost()======" << endl;
        Magacin kb("Magacin1","Lokacija1",2011);
            cin>>n;
            Gitara brisi;
			for (int i=0;i<n;i++){
                cin>>tip;
                cin>>seriski;
                cin >> godina;
                cin >> cena;

                Gitara g(tip,seriski, godina,cena);
                if(i==2)
                    brisi=g;
				kb.dodadi(g);
			}
        cout<<kb.vrednost()<<endl;
        kb.prodadi(brisi);
        cout<<"Po brisenje:"<<endl;
        cout<<kb.vrednost();
        Magacin kb3;
        kb3=kb;
        }

    return 0;
}
