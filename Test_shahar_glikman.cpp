//
// Created by shahar on 12/04/2020.
//

#include "doctest.h"
#include "FamilyTree.hpp"
#include <string>
#include <iostream>
using namespace std;

TEST_CASE("Tree number one") {
    family::Tree T ("Yanai");
    T.addFather("Yanai", "Tzvi")
            .addMother("Yanai", "Noga")
            .addFather("Noga", "Zack")
            .addMother("Noga", "Dalia")
            .addMother("Tzvi", "Batia")
            .addFather("Tzvi", "Moshe")
            .addMother("Dalia", "Sozy")
            .addFather("Dalia", "Noa")
            .addFather("Zack", "Avraham")
            .addMother("Zack", "Chana")
            .addMother("Batia", "Ofir");



            CHECK(T.relation("Yanai")=="me");
            CHECK(T.relation("Noga")=="mother");
            CHECK(T.relation("Tzvi")=="father");
            CHECK(T.relation("Dalia")=="grandmother");
            CHECK(T.relation("Zack")=="grandfather");
            CHECK(T.relation("Batia")=="grandmother");
            CHECK(T.relation("Moshe")=="grandfather");
            CHECK(T.relation("Noa")=="great-grandfather");
            CHECK(T.relation("Sozy")=="great-grandmother");
            CHECK(T.relation("Yifat")=="unrelated");
            CHECK(T.relation("Ofir")=="great-grandmother");
            CHECK(T.relation("Avraham")=="great-grandfather");
            CHECK(T.relation("Chana")=="great-grandmother");

            T.remove("Batia");
            CHECK(T.relation("Batia")=="unrelated");
            CHECK(T.relation("Ofir")=="unrelated");
            T.addMother("Tzvi", "Batia");
            CHECK(T.relation("Batia")=="grandmother");

            CHECK(T.find("me")=="Yanai");
            CHECK(T.find("mother")=="Noga");
            CHECK(T.find("father")=="Tzvi");
            int a=0;
            if(T.find("grandmother")=="Dalia"){
                a=1;
            }
            if(T.find("grandmother")=="Batia"){
                 a=1;
            }
            CHECK(a==1);
             a=0;
            if(T.find("grandfather")=="Zack"){
                a=1;
            }
            if(T.find("grandfather")=="Moshe"){
                 a=1;
             }
            CHECK(a==1);
            a=0;
            if(T.find("great-grandfather")=="Noa"){
                a=1;
            }
            if(T.find("great-grandfather")=="Avraham"){
                   a=1;
            }
            CHECK(a==1);

            a=0;
            if(T.find("great-grandmother")=="Ofir"){
                 a=1;
            }
            if(T.find("great-grandmother")=="Chana"){
                 a=1;
             }
            if(T.find("great-grandmother")=="Sozy"){
                 a=1;
            }
            CHECK(a==1);

    /* Add more checks here */
}

TEST_CASE("Tree number two") {
    family::Tree T ("one");
    T.addFather("one", "two")
            .addMother("one", "three")
            .addFather("two", "four")
            .addMother("two", "five")
            .addMother("three", "six")
            .addFather("three", "seven")
            .addMother("four", "nine")
            .addFather("four", "eight")
            .addFather("five", "eleven")
            .addMother("five", "twelve")
            .addFather("six", "Thirteen")
            .addMother("six", "Fourteen")
            .addFather("eight", "Seventeen")
            .addMother("eight", "Eighteen")
            .addFather("Eighteen", "thirtyone")
            .addMother("Eighteen", "thirtytwo");


            CHECK(T.relation("one")=="me");
            CHECK(T.relation("three")=="mother");
            CHECK(T.relation("two")=="father");
            CHECK(T.relation("five")=="grandmother");
            CHECK(T.relation("four")=="grandfather");
            CHECK(T.relation("six")=="grandmother");
            CHECK(T.relation("seven")=="grandfather");
            CHECK(T.relation("eight")=="great-grandfather");
            CHECK(T.relation("nine")=="great-grandmother");
            CHECK(T.relation("eleven")=="great-grandfather");
            CHECK(T.relation("twelve")=="great-grandmother");
            CHECK(T.relation("Thirteen")=="great-grandfather");
            CHECK(T.relation("Fourteen")=="great-grandmother");

            CHECK(T.relation("Seventeen")=="great-great-grandfather");
            CHECK(T.relation("Eighteen")=="great-great-grandmother");
            CHECK(T.relation("thirtyone")=="great-great-great-grandfather");
            CHECK(T.relation("thirtytwo")=="great-great-great-grandmother");




            CHECK(T.find("me")=="one");
            CHECK(T.find("mother")=="three");
            CHECK(T.find("father")=="two");

            int a=0;
            if(T.find("grandmother")=="five"){
                 a=1;
            }
            if(T.find("grandmother")=="six"){
                 a=1;
            }
            CHECK(a==1);
            a=0;
             if(T.find("grandfather")=="four"){
                 a=1;
             }
             if(T.find("grandfather")=="seven"){
                    a=1;
             }
             CHECK(a==1);

             a=0;
             if(T.find("great-grandfather")=="eight"){
                   a=1;
             }
             if(T.find("great-grandfather")=="eleven"){
                    a=1;
             }
              if(T.find("great-grandfather")=="Thirteen"){
                    a=1;
              }
             CHECK(a==1);

             a=0;
             if(T.find("great-grandmother")=="nine"){
                  a=1;
              }
             if(T.find("great-grandmother")=="twelve"){
                   a=1;
              }
              if(T.find("great-grandmother")=="Fourteen"){
                    a=1;
             }
             CHECK(a==1);


              CHECK(T.find("great-great-grandfather")=="Seventeen");
              CHECK(T.find("great-great-grandmother")=="Eighteen");

            T.remove("eight");
            CHECK(T.relation("Seventeen")=="unrelated");
            CHECK(T.relation("Eighteen")=="unrelated");
            CHECK(T.relation("thirtyone")=="unrelated");
            CHECK(T.relation("thirtytwo")=="unrelated");
            CHECK(T.relation("eight")=="unrelated");

            a=0;
            try {
                 T.remove("one");  //throw
            } catch (const exception& ex) {
                  a=1;
            }
            CHECK(a==1);
            CHECK(T.find("me")=="one");

}


TEST_CASE("Tree number three") {

    family::Tree T ("a");
    T.addFather("a", "b")
            .addMother("a", "c")
            .addFather("b", "d")
            .addMother("b", "e")
            .addFather("c", "f")
            .addMother("c", "g")
            .addMother("d", "i")
            .addFather("d", "h")
            .addFather("h", "j")
            .addMother("j", "k")
            .addFather("j", "l")
            .addMother("l", "m")
            .addFather("m", "n");

            CHECK(T.relation("a")=="me");
            CHECK(T.relation("c")=="mother");
            CHECK(T.relation("b")=="father");
            CHECK(T.relation("d")=="grandfather");
            CHECK(T.relation("e")=="grandmother");
            CHECK(T.relation("g")=="grandmother");
            CHECK(T.relation("f")=="grandfather");
            CHECK(T.relation("h")=="great-grandfather");
            CHECK(T.relation("i")=="great-grandmother");
            CHECK(T.relation("j")=="great-great-grandfather");
            CHECK(T.relation("k")=="great-great-great-grandmother");
            CHECK(T.relation("l")=="great-great-great-grandfather");
            CHECK(T.relation("m")=="great-great-great-great-grandmother");
            CHECK(T.relation("n")=="great-great-great-great-great-grandfather");

            CHECK(T.find("me")=="a");
            CHECK(T.find("mother")=="c");
            CHECK(T.find("father")=="b");
            CHECK(T.find("great-great-great-great-great-grandfather")=="n");
            CHECK(T.find("great-great-great-great-grandmother")=="m");
            CHECK(T.find("great-great-great-grandfather")=="l");
            CHECK(T.find("great-great-great-grandmother")=="k");
            CHECK(T.find("great-great-grandfather")=="j");
            CHECK(T.find("great-grandfather")=="h");
            CHECK(T.find("great-grandmother")=="i");

            T.remove("b");
            CHECK(T.relation("b")=="unrelated");
            CHECK(T.relation("d")=="unrelated");
            CHECK(T.relation("e")=="unrelated");
            CHECK(T.relation("h")=="unrelated");
            CHECK(T.relation("i")=="unrelated");
            CHECK(T.relation("j")=="unrelated");
            CHECK(T.relation("k")=="unrelated");
            CHECK(T.relation("l")=="unrelated");
            CHECK(T.relation("m")=="unrelated");
            CHECK(T.relation("n")=="unrelated");

            CHECK(T.find("grandmother")=="g");
            CHECK(T.find("grandfather")=="f");

            T.remove("c");
            CHECK(T.relation("c")=="unrelated");
            CHECK(T.relation("f")=="unrelated");
            CHECK(T.relation("g")=="unrelated");
            CHECK(T.relation("a")=="me");


}

TEST_CASE("Tree number four - left side only") {

    family::Tree T ("sunday");
    T.addFather("sunday", "monday")
            .addFather("monday", "tuesday")
            .addFather("tuesday", "wednesday")
            .addFather("wednesday", "thursday")
            .addFather("thursday", "friday")
            .addFather("friday", "saturday");


    int  a=0;
    try {
        T.find("mother");
    } catch (const exception& ex) {
        a=1;
    }
            CHECK(a==1);

            CHECK(T.find("me")=="sunday");
            CHECK(T.find("father")=="monday");
            CHECK(T.find("grandfather")=="tuesday");
            CHECK(T.find("great-grandfather")=="wednesday");
            CHECK(T.find("great-great-grandfather")=="thursday");
            CHECK(T.find("great-great-great-grandfather")=="friday");
            CHECK(T.find("great-great-great-great-grandfather")=="saturday");


            CHECK(T.relation("sunday")=="me");
            CHECK(T.relation("monday")=="father");
            CHECK(T.relation("tuesday")=="grandfather");
            CHECK(T.relation("wednesday")=="great-grandfather");
            CHECK(T.relation("thursday")=="great-great-grandfather");
            CHECK(T.relation("friday")=="great-great-great-grandfather");
            CHECK(T.relation("saturday")=="great-great-great-great-grandfather");


            a=0;
    try {
        T.remove("sunday");  //throw
    } catch (const exception& ex) {
        a=1;
    }
            CHECK(a==1);


            CHECK(T.relation("sunday")=="me");
            T.remove("monday");
            CHECK(T.relation("father")=="unrelated");
            CHECK(T.relation("grandfather")=="unrelated");


            a=0;
    try {
            T.find("grandfather");
    } catch (const exception& ex) {
        a=1;
    }
            CHECK(a==1);

    a=0;
    try {
        T.find("father");
    } catch (const exception& ex) {
        a=1;
    }
            CHECK(a==1);






}
