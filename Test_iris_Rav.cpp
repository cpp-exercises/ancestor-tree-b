#include "doctest.h"
#include "FamilyTree.hpp"

using namespace family;
using namespace std;

TEST_CASE("Test addMother+relation+find"){
    Tree T("Bobbie");
    T.addMother("Bobbie","Betsy");
    CHECK(T.relation("Betsy")=="mother");
    CHECK(T.find("mother")=="Betsy");
}
TEST_CASE("Test addFather+relation+find"){
    Tree T("Bobbie");
    T.addFather("Bobbie","James");
    CHECK(T.relation("James")=="father");
    CHECK(T.find("father")=="James");
}
TEST_CASE("Test relation not found"){
    Tree T("Bobbie");
    T.addMother("Julian","Betsy")
     .addFather("Julian","James")
     .addMother("Bet","Elizabet")
     .addFather("Tal","Jam")
     .addMother("Bet","Elizabet")
     .addFather("Bil","Jame");
    CHECK(T.relation("Carter")=="unrelated");
    CHECK(T.relation("Grayson")=="unrelated");
    CHECK(T.relation("Mason")=="unrelated");
    CHECK(T.relation("Lincoln")=="unrelated");
    CHECK(T.relation("Hudson")=="unrelated");
    CHECK(T.relation("Christian")=="unrelated");
    CHECK(T.relation("Carter")=="unrelated");
    CHECK(T.relation("Easton")=="unrelated");
    CHECK(T.relation("Colton")=="unrelated");
    CHECK(T.relation("Roben")=="unrelated");
}
TEST_CASE("Test relation :father, mother, grandmother, great-grandfather, great-great-grandmother"){
    Tree T("Bobbie");
    T.addMother("Bobbie","Betsy")
     .addFather("Bobbie","James")
//Betsy-mother-
     .addMother("Betsy","Beverly")
     .addFather("Betsy","Colton")
//James-father-
     .addMother("James","Camilla")
     .addFather("James","Greyson")
//Beverly-grandmother-
     .addMother("Beverly","Cara")
     .addFather("Beverly","Robert")
//Colton-grandfather-
     .addMother("Colton","Charlotte")
     .addFather("Colton","Greyson")
//Camilla-grandmother-
     .addMother("Camilla","Austin")
     .addFather("Camilla","Chloe")
//Greyson-grandfather-
     .addMother("Greyson","Chelsea")
     .addFather("Greyson","Cooper")
//Cara-great-grandmother-
     .addMother("Cara","Clara")
     .addFather("Cara","Parker")
//Robert-great-grandfather-
     .addMother("Robert","Clarisa")
     .addFather("Robert","Jhon")
//Charlotte-great-grandmother-
     .addMother("Charlotte","Claudia")
     .addFather("Charlotte","Wesley")
//Greyson-great-grandfather-
     .addMother("Greyson","Ann")
     .addFather("Greyson","Beni")
//Austin-great-grandmother-
     .addMother("Austin","Fali")
     .addFather("Austin","Han")
//Chloe-great-grandfather-
     .addMother("Chloe","Many")
     .addFather("Chloe","Stiw")
//Chelsea-great-grandmother-
     .addMother("Chelsea","Len")
     .addFather("Chelsea","Andre")
//Cooper-great-grandfather-
     .addMother("Cooper","Ira")
     .addFather("Cooper","Sasha")
//Clara-great-great-grandmother-
     .addMother("Clara","Iris")
     .addFather("Clara","Martin")
//Parker-great-great-grandfather-
     .addMother("Parker","April")
     .addFather("Parker","Silas")
//Clarisa-great-great-grandmother-
     .addMother("Clarisa","Arlene")
     .addFather("Clarisa","Miles")
//Jhon-great-great-grandfather-
     .addMother("Jhon","Ava")
     .addFather("Jhon","Harrison")
//Claudia-great-great-grandmother-
     .addMother("Claudia","Emma")
     .addFather("Claudia","Brandon")
//Wesley-great-great-grandfather-
     .addMother("Wesley","Nina")
     .addFather("Wesley","Braxton")
//Ann-great-great-grandmother-
     .addMother("Ann","Molly")
     .addFather("Ann","Brooks")
//Beni-great-great-grandfather-
     .addMother("Beni","Vera")
     .addFather("Beni","Dean")
//Fali-great-great-grandmother-
     .addMother("Fali","Lucy")
     .addFather("Fali","Hayden")
//Han-great-great-grandfather-
     .addMother("Han","Alexia")
     .addFather("Han","Karter")
//Many-great-great-grandmother-
     .addMother("Many","Debra")
     .addFather("Many","Dean")
//Stiw-great-great-grandfather-
     .addMother("Stiw","Rosa")
     .addFather("Stiw","Myles")
//Len-great-great-grandmother-
     .addMother("Len","Debra")
     .addFather("Len","Dean")
//Andre-great-great-grandfather-
     .addMother("Andre","Lucia")
     .addFather("Andre","Jeremy")
//Ira-great-great-grandmother-
     .addMother("Ira","Amanda")
     .addFather("Ira","Oscar")
//Sasha-great-great-grandfather-
     .addMother("Sasha","Traci")
     .addFather("Sasha","Legend");

    CHECK(T.relation("Bobbie")=="name");
    CHECK(T.relation("Betsy")=="mother");
    CHECK(T.relation("James")=="father");
    CHECK(T.relation("Beverly")=="grandmother");
    CHECK(T.relation("Colton")=="grandfather");
    CHECK(T.relation("Camilla")=="grandmother");
    CHECK(T.relation("Greyson")=="grandfather");
    CHECK(T.relation("Cara")=="great-grandmother");
    CHECK(T.relation("Robert")=="great-grandfather");
    CHECK(T.relation("Charlotte")=="great-grandmother");
    CHECK(T.relation("Greyson")=="great-grandfather");
    CHECK(T.relation("Austin")=="great-grandmother");
    CHECK(T.relation("Chloe")=="great-grandfather");
    CHECK(T.relation("Chelsea")=="great-grandmother");
    CHECK(T.relation("Cooper")=="great-grandfather");
    CHECK(T.relation("Clara")=="great-great-grandmother");
    CHECK(T.relation("Parker")=="great-great-grandfather");
    CHECK(T.relation("Clarisa")=="great-great-grandmother");
    CHECK(T.relation("Jhon")=="great-great-grandfather");
    CHECK(T.relation("Claudia")=="great-great-grandmother");
    CHECK(T.relation("Wesley")=="great-great-grandfather");
    CHECK(T.relation("Ann")=="great-great-grandmother");
    CHECK(T.relation("Beni")=="great-great-grandfather");
    CHECK(T.relation("Fali")=="great-great-grandmother");
    CHECK(T.relation("Han")=="great-great-grandfather");
    CHECK(T.relation("Many")=="great-great-grandmother");
    CHECK(T.relation("Stiw")=="great-great-grandfather");
    CHECK(T.relation("Len")=="great-great-grandmother");
    CHECK(T.relation("Andre")=="great-great-grandfather");
    CHECK(T.relation("Ira")=="great-great-grandmother");
    CHECK(T.relation("Sasha")=="great-great-grandfather");
    
}
TEST_CASE("Test function - remove"){
    Tree T("Bobbie");
    T.addMother("Bobbie","Betsy")
     .addFather("Bobbie","James")
//Betsy-mother-
     .addMother("Betsy","Beverly")
     .addFather("Betsy","Colton")
//James-father-
     .addMother("James","Camilla")
     .addFather("James","Greyson")
//Beverly-grandmother-
     .addMother("Beverly","Cara")
     .addFather("Beverly","Robert")
//Colton-grandfather-
     .addMother("Colton","Charlotte")
     .addFather("Colton","Greyson")
//Camilla-grandmother-
     .addMother("Camilla","Austin")
     .addFather("Camilla","Chloe")
//Greyson-grandfather-
     .addMother("Greyson","Chelsea")
     .addFather("Greyson","Cooper")
     .remove("Greyson");
    CHECK(T.relation("Greyson")=="unrelated");
    CHECK(T.relation("Cooper")=="unrelated");
    CHECK(T.relation("Chelsea")=="unrelated");
    T.remove("Camilla");
    CHECK(T.relation("Camilla")=="unrelated");
    CHECK(T.relation("Austin")=="unrelated");
    CHECK(T.relation("Chloe")=="unrelated");
    T.remove("Colton");
    CHECK(T.relation("Colton")=="unrelated");
    CHECK(T.relation("Charlotte")=="unrelated");
    CHECK(T.relation("Greyson")=="unrelated");
    T.remove("Beverly");
    CHECK(T.relation("Beverly")=="unrelated");
    CHECK(T.relation("Cara")=="unrelated");
    CHECK(T.relation("Robert")=="unrelated");
    T.remove("James");
    CHECK(T.relation("James")=="unrelated");
    CHECK(T.relation("Camilla")=="unrelated");
    CHECK(T.relation("Greyson")=="unrelated");
    T.remove("Betsy");
    CHECK(T.relation("Betsy")=="unrelated");
    CHECK(T.relation("Beverly")=="unrelated");
    CHECK(T.relation("Colton")=="unrelated");
    T.remove("Bobbie");
    CHECK(T.relation("Bobbie")=="unrelated");
    CHECK(T.relation("Betsy")=="unrelated");
    CHECK(T.relation("James")=="unrelated");
}
TEST_CASE("Test remove -root "){
    Tree T("Bobbie");
    T.addMother("Bobbie","Betsy")
     .addFather("Bobbie","James")
//Betsy-mother-
     .addMother("Betsy","Beverly")
     .addFather("Betsy","Colton")
//James-father-
     .addMother("James","Camilla")
     .addFather("James","Greyson")
//Beverly-grandmother-
     .addMother("Beverly","Cara")
     .addFather("Beverly","Robert")
//Colton-grandfather-
     .addMother("Colton","Charlotte")
     .addFather("Colton","Greyson")
//Camilla-grandmother-
     .addMother("Camilla","Austin")
     .addFather("Camilla","Chloe")
//Greyson-grandfather-
     .addMother("Greyson","Chelsea")
     .addFather("Greyson","Cooper");
     T.remove("Bobbie");
    CHECK(T.relation("Greyson")=="unrelated");
    CHECK(T.relation("Cooper")=="unrelated");
    CHECK(T.relation("Chelsea")=="unrelated");
    CHECK(T.relation("Camilla")=="unrelated");
    CHECK(T.relation("Austin")=="unrelated");
    CHECK(T.relation("Chloe")=="unrelated");
    CHECK(T.relation("Colton")=="unrelated");
    CHECK(T.relation("Charlotte")=="unrelated");
    CHECK(T.relation("Greyson")=="unrelated");
    CHECK(T.relation("Beverly")=="unrelated");
    CHECK(T.relation("Cara")=="unrelated");
    CHECK(T.relation("Robert")=="unrelated");
    CHECK(T.relation("James")=="unrelated");
    CHECK(T.relation("Camilla")=="unrelated");
    CHECK(T.relation("Greyson")=="unrelated");
    CHECK(T.relation("Betsy")=="unrelated");
    CHECK(T.relation("Beverly")=="unrelated");
    CHECK(T.relation("Colton")=="unrelated");
    CHECK(T.relation("Bobbie")=="unrelated");
    CHECK(T.relation("Betsy")=="unrelated");
    CHECK(T.relation("James")=="unrelated");
}
TEST_CASE("Test - choosing the right answer between two"){
    Tree T("Bobbie");
    T.addMother("Bobbie","Betsy")
     .addFather("Bobbie","James")
//Betsy-mother-
     .addMother("Betsy","Betsy")
     .addFather("Betsy","Colton")
//James-father-
     .addMother("James","Camilla")
     .addFather("James","Greyson")
//Betsy-grandmother-
     .addMother("Betsy","Cara")
     .addFather("Betsy","Robert");

    CHECK(T.relation("Betsy")=="mother");
    CHECK(T.relation("Betsy")=="grandmother");
} 
TEST_CASE("Test exception") {
    Tree T("Bobbie");
    T.addMother("Bobbie","Betsy")
     .addFather("Bobbie","James")
//Betsy-mother-
     .addMother("Betsy","Beverly")
     .addFather("Betsy","Colton")
//James-father-
     .addMother("James","Camilla")
     .addFather("James","Greyson")
//Beverly-grandmother-
     .addMother("Beverly","Cara")
     .addFather("Beverly","Robert")
//Colton-grandfather-
     .addMother("Colton","Charlotte")
     .addFather("Colton","Greyson")
//Camilla-grandmother-
     .addMother("Camilla","Austin")
     .addFather("Camilla","Chloe");

    CHECK_THROWS_AS(T.relation("Bobbie")=="unrelated", std::exception);
    CHECK_THROWS_AS(T.relation("Betsy")=="unrelated", std::exception);
    CHECK_THROWS_AS(T.relation("James")=="unrelated", std::exception);
    CHECK_THROWS_AS(T.relation("Beverly")=="unrelated", std::exception);
    CHECK_THROWS_AS(T.relation("Colton")=="unrelated", std::exception);
    CHECK_THROWS_AS(T.relation("Camilla")=="unrelated", std::exception);
    CHECK_THROWS_AS(T.relation("Greyson")=="unrelated", std::exception);
    CHECK_THROWS_AS(T.relation("Cara")=="unrelated", std::exception);
    CHECK_THROWS_AS(T.relation("Robert")=="unrelated", std::exception);
    CHECK_THROWS_AS(T.relation("Charlotte")=="unrelated", std::exception);
    CHECK_THROWS_AS(T.relation("Greyson")=="unrelated", std::exception);
    CHECK_THROWS_AS(T.relation("Austin")=="unrelated", std::exception);
    CHECK_THROWS_AS(T.relation("Chloe")=="unrelated", std::exception);
}
