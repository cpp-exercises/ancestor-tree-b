 
#include "doctest.h"
#include "FamilyTree.hpp"

#include <string>
using namespace std;

TEST_CASE("Reference add Tree case") { 
	family::Tree T ("Yosef");
	T.addFather("Yosef", "Yaakov")
	 .addMother("Yosef", "Rachel")
	 .addFather("Yaakov", "Isaac")
	 .addMother("Yaakov", "Rivka")
	 .addFather("Isaac", "Avraham")
	 .addFather("Avraham", "Terah");
}

TEST_CASE("Yosef Tree case") {  
	// Add test case
	family::Tree T ("Yosef");
	T.addFather("Yosef", "Yaakov");
	T.addMother("Yosef", "Rachel");
	CHECK_THROWS_AS(T.addFather("Yosef", "Yaakov"),exception);
	CHECK_THROWS_AS(T.addMother("Yosef", "Rivka"),exception);
	T.addFather("Yaakov", "Isaac");
	T.addMother("Yaakov", "Rivka");
	T.addFather("Rachel", "Avi");
	T.addMother("Rachel", "Ruti");
	T.addFather("Isaac", "Avraham");
	T.addMother("Isaac", "Ruti");
	CHECK_THROWS_AS(T.addFather("Isaac", "Israel"),exception);
	CHECK_THROWS_AS(T.addMother("Isaac", "Ruti"),exception);
	T.addFather("Avraham", "Yosi");
	T.addMother("Avraham", "Shelly");
	T.addFather("Avi", "Israel");
	T.addMother("Avi", "Sara");
	CHECK_THROWS_AS(T.addFather("Avraham", "Avraham"),exception);
	CHECK_THROWS_AS(T.addMother("Avraham", "Sara"),exception);
	 
	// Relation test case
	CHECK(T.relation("Yaakov") == string("father"));
	CHECK(T.relation("Rachel") == string("mother"));
	CHECK(T.relation("Isaac") == string("grandfather"));
	CHECK(T.relation("Rivka") == string("grandmother"));
	CHECK(T.relation("Avi") == string("grandfather"));
	CHECK((T.relation("Ruti") == string("grandmother") || T.relation("Ruti") == string("great-grandmother")));
	CHECK(T.relation("Avraham") == string("great-grandfather"));
	CHECK((T.relation("Ruti") == string("grandmother") || T.relation("Ruti") == string("great-grandmother")));
	CHECK(T.relation("Israel") == string("great-grandfather"));
	CHECK(T.relation("Sara") == string("great-grandmother"));
	CHECK(T.relation("Yosi") == string("great-great-grandfather"));
    CHECK(T.relation("Shelly") == string("great-great-grandmother"));

    CHECK(T.relation("xyz") == string("unrelated"));
	CHECK(T.relation("Omer") == string("unrelated"));
	CHECK(T.relation("Ariel") == string("unrelated"));
	CHECK(T.relation(" ") == string("unrelated"));
	CHECK(T.relation("  Ariel") == string("unrelated"));

	// Find test case
	CHECK(T.find("father") == string("Yaakov"));
	CHECK(T.find("mother") == string("Rachel"));
	CHECK((T.find("grandfather") == string("Isaac") || T.find("grandfather") == string("Avi")));
	CHECK((T.find("grandmother") == string("Rivka") || T.find("grandmother") == string("Ruti")));
	CHECK((T.find("great-grandmother") == string("Sara") || T.find("great-grandmother") == string("Ruti")));
	CHECK((T.find("great-grandfather") == string("Avraham") || T.find("great-grandfather") == string("Israel")));
	CHECK(T.find("great-great-grandfather") == string("Yosi"));
	CHECK(T.find("great-great-grandmother") == string("Shelly"));

	CHECK_THROWS_AS(T.find("grandfatrher"),exception);
	CHECK_THROWS_AS(T.find("great"),exception);
	CHECK_THROWS_AS(T.find(" "),exception);
	CHECK_THROWS_AS(T.find("   great"),exception);
	CHECK_THROWS_AS(T.find("grandfatrher   "),exception);
	CHECK_THROWS_AS(T.find("great,great,grandmother"),exception);
	CHECK_THROWS_AS(T.find("great?grandmother"),exception);
	CHECK_THROWS_AS(T.find("great grandmother"),exception);

	// Remove test case
	CHECK_THROWS_AS(T.remove("Yosef"),exception);
	CHECK_THROWS_AS(T.remove(" "),exception);
	CHECK_THROWS_AS(T.remove("xyz"),exception);
	CHECK_THROWS_AS(T.remove("Ariel"),exception);
	CHECK_THROWS_AS(T.remove("  Rivka"),exception);

	T.remove("Yosi");
	CHECK_THROWS_AS(T.find("great-great-grandfather"),exception);
	T.addFather("Avraham", "Ido");
	T.remove("Avi");
	CHECK_THROWS_AS(T.addFather("Avi", "Israel"),exception);
	T.addFather("Rachel", "Shmual");
	T.remove("Isaac");
	T.remove("Rivka");
	T.remove("Ruti");
	CHECK_THROWS_AS(T.find("grandmother"),exception);
	CHECK_THROWS_AS(T.addFather("Isaac", "Avraham"),exception);
	CHECK_THROWS_AS(T.addMother("Isaac", "Ruti"),exception);
	CHECK_THROWS_AS(T.addFather("Rivka", "Israel"),exception);
	CHECK_THROWS_AS(T.addMother("Rivka", "Sara"),exception);
	T.remove("Yaakov");
	T.remove("Rachel");
	CHECK_THROWS_AS(T.find("father"),exception);
	CHECK_THROWS_AS(T.find("mother"),exception);
	CHECK_THROWS_AS(T.addFather("Yaakov", "Avraham"),exception);
	CHECK_THROWS_AS(T.addMother("Yaakov", "Ruti"),exception);
	CHECK_THROWS_AS(T.addFather("Rachel", "Avraham"),exception);
	CHECK_THROWS_AS(T.addMother("Rachel", "Ruti"),exception);
}

TEST_CASE("Strange string Tree case") {  
	// Add test case
	family::Tree T ("OliVeR$");
	T.addFather("OliVeR$", "fEliXX");
	T.addMother("OliVeR$", "#miA");
	CHECK_THROWS_AS(T.addFather("OliVeR$", "Yaa kov"),exception);
	CHECK_THROWS_AS(T.addMother("OliVeR$", "Rivka"),exception);
	T.addFather("fEliXX", "eLi9");
	T.addMother("fEliXX", "IRis-");
	T.addFather("#miA", "osC7ar");
	T.addMother("#miA", "AvA");
	T.addFather("IRis-", "le0");
	T.addMother("IRis-", "aB3igaIl");
	CHECK_THROWS_AS(T.addFather("IRis-", "Israel"),exception);
	CHECK_THROWS_AS(T.addMother("IRis-", "Ruti"),exception);
	 
	// Relation test case
	CHECK(T.relation("fEliXX") == string("father"));
	CHECK(T.relation("#miA") == string("mother"));
	CHECK(T.relation("eLi9") == string("grandfather"));
	CHECK(T.relation("IRis-") == string("grandmother"));
	CHECK(T.relation("osC7ar") == string("grandfather"));
	CHECK(T.relation("AvA") == string("grandmother"));
	CHECK(T.relation("le0") == string("great-grandfather"));
	CHECK(T.relation("aB3igaIl") == string("great-grandmother"));

    CHECK(T.relation("fEli XX") == string("unrelated"));
	CHECK(T.relation("&miA") == string("unrelated"));
	CHECK(T.relation("leo") == string("unrelated"));
	CHECK(T.relation(" ") == string("unrelated"));
	CHECK(T.relation("  osC7ar") == string("unrelated"));

	// Find test case
	CHECK(T.find("father") == string("fEliXX"));
	CHECK(T.find("mother") == string("#miA"));
	CHECK((T.find("grandfather") == string("eLi9") || T.find("grandfather") == string("osC7ar")));
	CHECK((T.find("grandmother") == string("IRis-") || T.find("grandmother") == string("AvA")));
	CHECK(T.find("great-grandfather") == string("le0"));
	CHECK(T.find("great-grandmother") == string("aB3igaIl"));

	CHECK_THROWS_AS(T.find("grandfatrher"),exception);
	CHECK_THROWS_AS(T.find("great"),exception);
	CHECK_THROWS_AS(T.find(" "),exception);
	CHECK_THROWS_AS(T.find("   great"),exception);
	CHECK_THROWS_AS(T.find("grandfatrher   "),exception);
	CHECK_THROWS_AS(T.find("great,great,grandmother"),exception);
	CHECK_THROWS_AS(T.find("great?grandmother"),exception);
	CHECK_THROWS_AS(T.find("great grandmother"),exception);

	// Remove test case
	CHECK_THROWS_AS(T.remove("OliVeR$"),exception);

	T.remove("aB3igaIl");
	CHECK_THROWS_AS(T.find("great-grandmother"),exception);
	T.addMother("IRis-", "aB3igaIl");
	T.remove("fEliXX");
	CHECK_THROWS_AS(T.addFather("eLi9", "Israel"),exception);
	CHECK_THROWS_AS(T.addMother("eLi9", "Ruti"),exception);
	CHECK_THROWS_AS(T.find("great-grandfather"),exception);
	T.addFather("OliVeR$", "fEliXX");
	T.remove("osC7ar");
	CHECK_THROWS_AS(T.find("grandfather"),exception);
	T.remove("#miA");
	CHECK_THROWS_AS(T.addFather("#miA", "Avraham"),exception);
	CHECK_THROWS_AS(T.addMother("#miA", "Ruti"),exception);
	T.remove("fEliXX");
	CHECK_THROWS_AS(T.find("father"),exception);
	CHECK_THROWS_AS(T.find("mother"),exception);
}

TEST_CASE("Empty string Tree case") {  
	// Add test case
	family::Tree T (" ");
	T.addFather(" ", "  ");
	T.addMother(" ", "   ");
	CHECK_THROWS_AS(T.addFather(" ", "Yakov"),exception);
	CHECK_THROWS_AS(T.addMother(" ", "     "),exception);
	T.addFather("  ", "    ");
	T.addMother("  ", "     ");
	CHECK_THROWS_AS(T.addFather("  ", "         "),exception);
	CHECK_THROWS_AS(T.addMother("  ", "Rut  i"),exception);
	 
	// Relation test case
	CHECK(T.relation("  ") == string("father"));
	CHECK(T.relation("   ") == string("mother"));
	CHECK(T.relation("    ") == string("grandfather"));
	CHECK(T.relation("     ") == string("grandmother"));

    CHECK(T.relation("fli XX") == string("unrelated"));
	CHECK(T.relation("leo") == string("unrelated"));
	CHECK(T.relation("  osC7ar") == string("unrelated"));

	// Find test case
	CHECK(T.find("father") == string("  "));
	CHECK(T.find("mother") == string("   "));
	CHECK(T.find("grandfather") == string("    "));
	CHECK(T.find("grandmother") == string("     "));

	CHECK_THROWS_AS(T.find("  "),exception);
	CHECK_THROWS_AS(T.find("great"),exception);
	CHECK_THROWS_AS(T.find("   great"),exception);

	// Remove test case
	CHECK_THROWS_AS(T.remove(" "),exception);

	T.remove("     ");
	CHECK_THROWS_AS(T.find("grandmother"),exception);
	T.remove("  ");
	CHECK_THROWS_AS(T.addFather("  ", "     ");,exception);
	CHECK_THROWS_AS(T.addMother("  ", "  Ru ti");,exception);
	CHECK_THROWS_AS(T.find("father"),exception);
	T.remove("   ");
	CHECK_THROWS_AS(T.find("mother"),exception);
	CHECK_THROWS_AS(T.addFather("   ", "        ");,exception);
	CHECK_THROWS_AS(T.addMother("   ", "Rut   i ");,exception);
}
