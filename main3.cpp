#include <iostream>
#include <string>
#include <ctime>

using namespace std;


class Student
{
private:
    string name = " ";
    string ocenki = " ";

public:


    void setname(string iname)
    {
        this->name = iname;
    }
    string getname()
    {
        return this->name;
    }

    void setocenki(string iocenki)
    {
        this->ocenki = iocenki;
    }
    string getocenki()
    {
        return this->ocenki;
    }

    bool OtlichnikOrNot()
    {
        float summ = 0, countb = 0, sredniyball = 0;
        for (unsigned short int j = 0; j < this->getocenki().length(); ++j)
        {
            summ = summ + ((this->getocenki())[j] - 48);
            ++countb;
        }
        sredniyball = summ / countb;
        if (sredniyball >= 4.5)
        {
            
            return true;
        }
        else
        {
            
            return false;
        }
    }

protected:

};





class Teacher
{
private:

public:

    string getname()
    {
        return this->name;
    }
    bool getnastroenie()
    {
        return this->NastroenieIsGood;
    }
    void setname(string iname)
    {
        this->name = iname;
    }

    void PostavitConcretnuyuOcenkuStudentu(Student* S1, string ConcretnayaOcenka)
    {
        S1->setocenki(S1->getocenki() + ConcretnayaOcenka);
        ++countocenok;

        unsigned short int ra = 9;
        ra = (((rand() % 2)));
        if ((countocenok % 5) == 0)
        {
            if (ra == 1)
            {
                this->NastroenieIsGood = true;
            }
            else
            {
                this->NastroenieIsGood = false;
            }
        }
    }

    void PostavitRandomOcenkuStudentu(Student* S1)
    {
        if (NastroenieIsGood == true)
        {
            if (S1->OtlichnikOrNot() == true)
            {
                S1->setocenki(S1->getocenki() + "5");
            }
            else
            {
                S1->setocenki(S1->getocenki() + "4");
            }
        }
        else
        {
            if (S1->OtlichnikOrNot() == true)
            {
                if ((rand() % 2) == 0)
                {
                    S1->setocenki(S1->getocenki() + "4");
                }
                else
                {
                    S1->setocenki(S1->getocenki() + "5");
                }
            }
            else
            {
                if ((rand() % 2) == 0)
                {
                    S1->setocenki(S1->getocenki() + "2");
                }
                else
                {
                    S1->setocenki(S1->getocenki() + "3");
                }
            }
        }

        ++countocenok;

        unsigned short int ra = 9;
        ra = (((rand() % 2)));
        if ((countocenok % 5) == 0)
        {
            if (ra == 1)
            {
                this->NastroenieIsGood = true;
            }
            else
            {
                this->NastroenieIsGood = false;
            }
        }
    }

protected:
    string name = "";
    bool NastroenieIsGood;
    unsigned short int countocenok = 0;

};


class Istorik : public Teacher
{
private:

public:

    void PostavitRandomOcenkuStudentu(Student* S1)
    {
        S1->setocenki(S1->getocenki() + "5");
    }

protected:

};


class Roditel
{
private:

public:

    Student* child[20];
    unsigned short int countchild = 0;

    void setname(string iname)
    {
        this->name = iname;
    }
    string  getname()
    {
        return this->name;
    }
    void addChild(Student* S1)
    {
        child[countchild] = S1;
        ++countchild;
    }
    void RasskazatOKazhdomSvoem()
    {

        for (int j = 0; j < (countchild); ++j)
        {




            if (NastroenieIsGood == true)
            {
                if (child[j]->OtlichnikOrNot() == true)
                {
                    cout << "Родитель " << this->getname() << " говорит: " << child[j]->getname() << " лучший ребёнок!" << endl;
                }
                else
                {
                    cout << "Родитель " << this->getname() << " говорит: " << child[j]->getname() << "  хороший ребёнок, хотя с учёбой у него всё так себе." << endl;
                }
            }
            else
            {
                if (child[j]->OtlichnikOrNot() == true)
                {
                    cout << "Родитель " << this->getname() << " говорит: " << child[j]->getname() << "  Учится он хорошо, а в остальном..." << endl;
                }
                else
                {
                    cout << "Родитель " << this->getname() << " говорит: " << child[j]->getname() << " неуч." << endl;
                }
            }






        }
    }

    void RasskazatOSluchainomSvoem()
    {
        unsigned short int ran = 0;
        ran = (((rand() % countchild)));




        if (NastroenieIsGood == true)
        {
            if (child[ran]->OtlichnikOrNot() == true)
            {
                cout << "Родитель " << this->getname() << " говорит: " << child[ran]->getname() << " лучший  ребёнок!" << endl;
            }
            else
            {
                cout << "Родитель " << this->getname() << " говорит: " << child[ran]->getname() << " хороший ребёнок, хотя с учёбой у него всё так себе." << endl;
            }
        }
        else
        {
            if (child[ran]->OtlichnikOrNot() == true)
            {
                cout << "Родитель " << this->getname() << " говорит: " << child[ran]->getname() << " Учится он хорошо, а в остальном... " << endl;
            }
            else
            {
                cout << "Родитель " << this->getname() << " говорит: " << child[ran]->getname() << " неуч." << endl;
            }
        }







    }
    void RasskazatOboVsehSvoihVCelom()
    {
        unsigned short int countofotlichnik = 0;
        for (int j = 0; j < (countchild); ++j)
        {
            if (child[j]->OtlichnikOrNot() == true)
            {
                ++countofotlichnik;
            }
        }



        if (NastroenieIsGood == true)
        {
            if (countofotlichnik >= (countchild / 2))
            {
                cout << "Родитель " << this->getname() << " говорит: " << " прекрасные дети!" << endl;
            }
            else
            {
                cout << "Родитель " << this->getname() << " говорит: " << "У меня хорошие дети, хотя им есть, куда стремиться." << endl;
            }
        }
        else
        {
            if (countofotlichnik >= (countchild / 2))
            {
                cout << "Родитель " << this->getname() << " говорит: " << "У меня неплохие дети. Но сейчас мне не до них." << endl;
            }
            else
            {
                cout << "Родитель " << this->getname() << " говорит: " << "Мои дети бестолковые." << endl;
            }
        }




    }
    void RasskazatOKonkretnomSvoem(Student* S1)
    {
        unsigned short int ji = 0;
        bool childexist = false;

        while ((ji < (countchild)) && (childexist == false))
        {
            if (S1 == child[ji])
            {
                childexist = true;






                if (NastroenieIsGood == true)
                {
                    if (S1->OtlichnikOrNot() == true)
                    {
                        cout << "Родитель " << this->getname() << " говорит: " << S1->getname() << " лучший ребёнок!" << endl;
                    }
                    else
                    {
                        cout << "Родитель " << this->getname() << " говорит: " << S1->getname() << " очень хороший ребёнок, хотя с учёбой у него всё так себе." << endl;
                    }
                }
                else
                {
                    if (S1->OtlichnikOrNot() == true)
                    {
                        cout << "Родитель " << this->getname() << " говорит: " << S1->getname() << " Учится он хорошо, а в остальном... " << endl;
                    }
                    else
                    {
                        cout << "Родитель " << this->getname() << " говорит: " << S1->getname() << " неуч." << endl;
                    }
                }






            }
            ++ji;
        }
        if ((childexist == false))
        {
            cout << " Это не тот ребёнок! У родителя " << this->getname() << " нет ребёнка " << S1->getname() << "." << endl;
        }
    }

protected:
    std::string name = "";
    bool NastroenieIsGood;

};


class Babushka : public Roditel
{
private:

public:

    void RasskazatOKazhdomSvoem()
    {

        for (int j = 0; j < (countchild); ++j)
        {
            cout << "Бабушка " << this->getname() << " говорит: " << child[j]->getname() << " лучший внук!" << endl;

        }
    }

    void RasskazatOSluchainomSvoem()
    {
        unsigned short int ran = 0;
        ran = (((rand() % countchild)));
        cout << "Бабушка " << this->getname() << " говорит: " << child[ran]->getname() << " лучший внук!" << endl;
    }
    void RasskazatOboVsehSvoihVCelom()
    {

        cout << "Бабушка " << this->getname() << " говорит: " << "У меня прекрасные внуки!" << endl;

    }
    void RasskazatOKonkretnomSvoem(Student* S1)
    {
        unsigned short int ji = 0;
        bool childexist = false;

        while ((ji < (countchild)) && (childexist == false))
        {
            if (S1 == child[ji])
            {
                childexist = true;
            }
            ++ji;
        }
        if ((childexist == true))
        {
            cout << "Бабушка " << this->getname() << " говорит: " << S1->getname() << " лучший внук!" << endl;
        }

        if ((childexist == false))
        {
            if (NastroenieIsGood == true)
            {
                if (S1->OtlichnikOrNot() == true)
                {
                    cout << "Бабушка " << this->getname() << " говорит: " << S1->getname() << " хороший внук !" << endl;
                }
                else
                {
                    cout << "Бабушка " << this->getname() << " говорит: " << S1->getname() << " хороший ребёнок, хотя учится так себе." << endl;
                }
            }
            else
            {
                if (S1->OtlichnikOrNot() == true)
                {
                    cout << "Бабушка " << this->getname() << " говорит: " << S1->getname() << " более-менее неплохой ребёнок." << endl;
                }
                else
                {
                    cout << "Бабушка " << this->getname() << " говорит: " << S1->getname() << "неуч." << endl;
                }
            }

        }



    }

protected:

};




class Zanyatie
{

private:
    string name = "";
    unsigned short int countstud = 0;
    Teacher* teach;


public:

    void setname(string iname)
    {
        this->name = iname;
    }

    string getname()
    {
        return this->name;
    }


    Student* stud[40];

    void addStud(Student* S1)
    {
        stud[countstud] = S1;
        ++countstud;
    }

    void setteach(Teacher* iteach)
    {
        this->teach = iteach;
    }
    Teacher* getteach()
    {
        return this->teach;
    }
    unsigned short int getcountstud()
    {
        return this->countstud;
    }


    void ProvestiZanyatie(Istorik* T1)
    {
        unsigned short int r = 1;
        setteach(T1);

        for (int j = 0; j < (countstud); ++j)
        {
            r = (((rand() % 3)) + 1);
            if ((T1->getnastroenie() == true))
            {
                ++r;
            }
            for (int j = 0; j < r; ++j)
            {
                T1->PostavitRandomOcenkuStudentu(stud[j]);
            }
        }
    }

    void ProvestiZanyatie(Teacher* T1)
    {
        unsigned short int r = 1;
        setteach(T1);

        for (int j = 0; j < (countstud); ++j)
        {
            r = (((rand() % 3)) + 1);
            if ((T1->getnastroenie() == true))
            {
                ++r;
            }
            for (int j = 0; j < r; ++j)
            {
                T1->PostavitRandomOcenkuStudentu(stud[j]);
            }
        }
    }


protected:


};



class Sobranie
{
private:

    Teacher* teach[20];
    Roditel* rodit[20];
    Zanyatie* zanyat[20];
    Student* studentybezroditeley[20];
    unsigned short int countteach = 0;
    unsigned short int countrodit = 0;
    unsigned short int countzanyat = 0;
    unsigned short int countstudentybezroditeley = 0;

public:

    void addTeach(Teacher* T1)
    {
        teach[countteach] = T1;
        ++countteach;
    }
    void addRodit(Roditel* R1)
    {
        rodit[countrodit] = R1;
        ++countrodit;
    }
    void addZanyat(Zanyatie* Z1)
    {
        zanyat[countzanyat] = Z1;
        ++countzanyat;
    }
    void addStudentBezRoditeley(Student* SBR1)
    {
        bool SBRExist = false;
        for (int j5 = 0; j5 < countstudentybezroditeley; ++j5)
        {
            if (SBR1 == studentybezroditeley[j5])
            {
                SBRExist = true;
            }
        }
        if (SBRExist == false)
        {
            studentybezroditeley[countstudentybezroditeley] = SBR1;
            ++countstudentybezroditeley;
        }

    }






    void ProvestiSobranie()
    {
        cout << endl;
        cout << endl;
        cout  << endl << "     СОБРАНИЕ НАЧАЛОСЬ:   " <<  endl;
        for (int j = 0; j < (countzanyat); ++j)
        {
            bool existTeacher = false;
            unsigned short int j1 = 0;
            while ((j1 < countteach) && (existTeacher == false))
            {
                if (teach[j1] == zanyat[j]->getteach())
                {
                    existTeacher = true;

                }
                ++j1;
            }


            if (existTeacher == 1)
            {

                for (int j2 = 0; j2 < (zanyat[j]->getcountstud()); ++j2)
                {

                    bool existRodit = false;
                   
                    for (unsigned short int j3 = 0; j3 < countrodit; ++j3)
                    {
                        for (unsigned short int j4 = 0; j4 < rodit[j3]->countchild; ++j4)
                        {
                            if ((zanyat[j]->stud[j2]) == (rodit[j3]->child[j4]))
                            {
                                existRodit = true;
                                cout << "О работе учащегося" << (zanyat[j]->stud[j2]->getname()) << " на занятии '" << zanyat[j]->getname() << "': ";
                                rodit[j3]->RasskazatOKonkretnomSvoem(zanyat[j]->stud[j2]);
                                    }
                           
                        }

                    }
                    if (existRodit == false)
                    {
                        this->addStudentBezRoditeley(zanyat[j]->stud[j2]);

                       
                    }
                }

            }

        }
        cout << endl << endl << endl << "+ + + + + + + + + + + + + +" << endl << endl;
        cout << "СПИСОК УЧАЩИХСЯ, КОТОРЫЕ БЫЛИ НА ЗАНЯТИЯХ И ПОЛУЧИЛИ ОТМЕТКИ, НО ИХ РОДИТЕЛИ НЕ ЯВИЛИСЬ: " << endl << endl;

        for (int j6 = 0; j6 < countstudentybezroditeley; ++j6)
        {
            cout << j6 + 1 << ") " << studentybezroditeley[j6]->getname() << endl;
        }
        cout <<  "     ...СОБРАНИЕ ЗАКОНЧИЛОСЬ   " << endl ;
    }




protected:

};


int main()
{
    setlocale(LC_ALL, "Russian");

    Student* Вася = new Student();
    Student* Петя = new Student();
    Student* Катя = new Student();
    Student* Миша = new Student();
    Student* Маша = new Student();
    Student* Тима = new Student();
    Вася->setname("Вася");
    Петя->setname("Петя");
    Катя->setname("Катя");
    Миша->setname("Миша");
    Маша->setname("Маша");
    Тима->setname("Тима");

    Teacher* МарияИвановна = new Teacher();
    МарияИвановна->setname("Мария Ивановна");

    Istorik* ПавелВладимирович = new Istorik();
    ПавелВладимирович->setname("Павел Владимирович");

    Roditel* ИвановИванИванович = new Roditel();
    ИвановИванИванович->setname("Иванов Иван Иванович");

    Roditel* ВасилийПетровичСидоров = new Roditel();
    ВасилийПетровичСидоров->setname("Василий Петрович Сидоров");

    Zanyatie* Математика = new Zanyatie();
    Zanyatie* История = new Zanyatie();
    Математика->setname("Математика");
    История->setname("История");

    Babushka* Валентина = new Babushka();
    Валентина->setname("Валентина");


    Sobranie* РодительскоеСобрание = new Sobranie();

    Вася->setocenki("554");
    Петя->setocenki("5");
    Катя->setocenki("34543535");
    Миша->setocenki("5454545");
    Маша->setocenki("52345");
    Тима->setocenki("1");

    МарияИвановна->PostavitRandomOcenkuStudentu(Вася);
    МарияИвановна->PostavitRandomOcenkuStudentu(Петя);
    МарияИвановна->PostavitRandomOcenkuStudentu(Катя);
    МарияИвановна->PostavitRandomOcenkuStudentu(Миша);
    МарияИвановна->PostavitRandomOcenkuStudentu(Маша);
    МарияИвановна->PostavitRandomOcenkuStudentu(Тима);

    Математика->addStud(Вася);
    Математика->addStud(Петя);
    Математика->addStud(Катя);
    Математика->addStud(Миша);
    Математика->addStud(Маша);
    Математика->ProvestiZanyatie(МарияИвановна);

    История->addStud(Вася);
    История->addStud(Катя);
    История->addStud(Тима);
    История->addStud(Маша);
    История->ProvestiZanyatie(ПавелВладимирович);


    ПавелВладимирович->PostavitRandomOcenkuStudentu(Вася);

    cout << Вася->getocenki() << endl;
    cout << Петя->getocenki() << endl;
    cout << Катя->getocenki() << endl;

    ИвановИванИванович->addChild(Вася);
    ИвановИванИванович->addChild(Петя);
    ИвановИванИванович->addChild(Катя);

    ВасилийПетровичСидоров->addChild(Миша);

    Валентина->addChild(Вася);
    Валентина->addChild(Петя);
    Валентина->addChild(Катя);
    Валентина->addChild(Тима);

    ИвановИванИванович->RasskazatOKazhdomSvoem();
    ИвановИванИванович->RasskazatOSluchainomSvoem();
    ИвановИванИванович->RasskazatOboVsehSvoihVCelom();
    ИвановИванИванович->RasskazatOKonkretnomSvoem(Вася);
    ИвановИванИванович->RasskazatOKonkretnomSvoem(Миша);

    Валентина->RasskazatOKazhdomSvoem();
    Валентина->RasskazatOSluchainomSvoem();
    Валентина->RasskazatOboVsehSvoihVCelom();
    Валентина->RasskazatOKonkretnomSvoem(Тима);
    Валентина->RasskazatOKonkretnomSvoem(Миша);

    РодительскоеСобрание->addRodit(ИвановИванИванович);
    РодительскоеСобрание->addRodit(ВасилийПетровичСидоров);
    РодительскоеСобрание->addRodit(Валентина);
    РодительскоеСобрание->addTeach(ПавелВладимирович);
    РодительскоеСобрание->addTeach(МарияИвановна);
    РодительскоеСобрание->addZanyat(Математика);
    РодительскоеСобрание->addZanyat(История);
    РодительскоеСобрание->ProvestiSobranie();

    return 0;
}
