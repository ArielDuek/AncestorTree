#include "doctest.h"
#include "FamilyTree.hpp"
#include <iostream>
using namespace std;
using namespace family;
void BuildTree(Tree T);


static Tree T("Ariel");
void BuildTree(Tree T) {
    T.addFather("Ariel", "Paulo")
            .addMother("Ariel", "Karen")
            .addFather("Paulo", "Gabriel")
            .addMother("Paulo", "Gladis")
            .addFather("Karen", "Gorge")
            .addMother("Karen", "Ester")
            .addFather("Gabriel", "Avi")
            .addMother("Gabriel", "Rachel")
            .addFather("Gladis", "Yakov")
            .addMother("Gladis", "Lea")
            .addFather("Gorge", "Itizk")
            .addMother("Gorge", "Tzipi")
            .addFather("Ester", "Nati")
            .addMother("Ester", "Mali")
            .addFather("Avi", "Udi")
            .addMother("Avi", "Bracha")
            .addFather("Rachel", "Shimon")
            .addMother("Rachel", "Batel")
            .addFather("Yakov", "Roei")
            .addMother("Yakov", "Batia")
            .addFather("Lea", "Yarin")
            .addMother("Lea", "Liel")
            .addFather("Itzik", "Yizhak")
            .addMother("Itzik", "Sahar")
            .addFather("Tzipi", "Noam")
            .addMother("Tzipi", "May")
            .addFather("Nati", "Nitay")
            .addMother("Nati", "Meytal")
            .addFather("Mali", "Neria")
            .addMother("Mali", "Reut");
}


TEST_CASE("addFather"){
    BuildTree(T);
    CHECK(T.relation("Paulo")==string("father"));
    CHECK(T.relation("Gabriel")==string("grandfather"));
    CHECK(T.relation("Avi")==string("great-grandfather"));
    CHECK(T.relation("Udi")==string("great-great-grandfather"));
    CHECK(T.relation("Shimon")==string("great-great-grandfather"));
    CHECK(T.relation("Yakov")==string("great-grandfather"));
    CHECK(T.relation("Roei")==string("great-great-grandfather"));
    CHECK(T.relation("Yarin")==string("great-great-grandfather"));
    CHECK(T.relation("Gorge")==string("grandfather"));
    CHECK(T.relation("Itzik")==string("great-grandfather"));
    CHECK(T.relation("Nati")==string("great-grandfather"));
    CHECK(T.relation("Yizhak")==string("great-great-grandfather"));
    CHECK(T.relation("Noam")==string("great-great-grandfather"));
    CHECK(T.relation("Nitay")==string("great-great-grandfather"));
    CHECK(T.relation("Neria")==string("great-great-grandfather"));
};

TEST_CASE("addMother function"){
    CHECK(T.relation("Karen")==string("mother"));
    CHECK(T.relation("Ester")==string("grandmother"));
    CHECK(T.relation("Gladis")==string("grandmother"));
    CHECK(T.relation("Rachel")==string("great-grandmother"));
    CHECK(T.relation("Lea")==string("great-grandmother"));
    CHECK(T.relation("Bracha")==string("great-great-grandmother"));
    CHECK(T.relation("Batel")==string("great-great-grandmother"));
    CHECK(T.relation("Batia")==string("great-great-grandmother"));
    CHECK(T.relation("Liel")==string("great-great-grandmother"));
    CHECK(T.relation("Sahar")==string("great-great-grandmother"));
    CHECK(T.relation("May")==string("great-great-grandmother"));
    CHECK(T.relation("Meytal")==string("great-great-grandmother"));
    CHECK(T.relation("Reut")==string("great-great-grandmother"));
    CHECK(T.relation("Tzipi")==string("great-grandmother"));
    CHECK(T.relation("Mali")==string("great-grandmother"));
};

TEST_CASE("relation function"){
    CHECK(T.relation("Karen")==string("mother"));
    CHECK(T.relation("Ester")==string("grandmother"));
    CHECK(T.relation("Gladis")==string("grandmother"));
    CHECK(T.relation("Rachel")==string("great-grandmother"));
    CHECK(T.relation("Lea")==string("great-grandmother"));
    CHECK(T.relation("Bracha")==string("great-great-grandmother"));
    CHECK(T.relation("Batel")==string("great-great-grandmother"));
    CHECK(T.relation("Batia")==string("great-great-grandmother"));
    CHECK(T.relation("Liel")==string("great-great-grandmother"));
    CHECK(T.relation("Sahar")==string("great-great-grandmother"));
    CHECK(T.relation("May")==string("great-great-grandmother"));
    CHECK(T.relation("Meytal")==string("great-great-grandmother"));
    CHECK(T.relation("Reut")==string("great-great-grandmother"));
    CHECK(T.relation("Tzipi")==string("great-grandmother"));
    CHECK(T.relation("Mali")==string("great-grandmother"));
    CHECK(T.relation("Paulo")==string("father"));
    CHECK(T.relation("Gabriel")==string("grandfather"));
    CHECK(T.relation("Avi")==string("great-grandfather"));
    CHECK(T.relation("Udi")==string("great-great-grandfather"));
    CHECK(T.relation("Shimon")==string("great-great-grandfather"));
    CHECK(T.relation("Yakov")==string("great-grandfather"));
    CHECK(T.relation("Roei")==string("great-great-grandfather"));
    CHECK(T.relation("Yarin")==string("great-great-grandfather"));
    CHECK(T.relation("Gorge")==string("grandfather"));
    CHECK(T.relation("Itzik")==string("great-grandfather"));
    CHECK(T.relation("Nati")==string("great-grandfather"));
    CHECK(T.relation("Yizhak")==string("great-great-grandfather"));
    CHECK(T.relation("Noam")==string("great-great-grandfather"));
    CHECK(T.relation("Nitay")==string("great-great-grandfather"));
    CHECK(T.relation("Neria")==string("great-great-grandfather"));
    CHECK(T.relation("Ariel")==string("me"));
    CHECK(T.relation("abra")==string("unrelated"));
    CHECK(T.relation("xyz")==string("unrelated"));
    CHECK(T.relation("us")==string("unrelated"));
    CHECK(T.relation("Yirat")==string("unrelated"));
    CHECK(T.relation("notHERE")==string("unrelated"));
};

TEST_CASE("find function"){
    CHECK(T.find("me")==string("Ariel"));
    CHECK(T.find("father")==string("Paulo"));
    CHECK(T.find("mother")==string("Karen"));
    CHECK((T.find("grandmother")==string("Ester") || T.find("grandmother")==string("Gladis")) );
    CHECK((T.find("grandfather")==string("Gabriel") || T.find("grandfather")==string("Gorge")) );
    CHECK((T.find("great-grandmother")==string("Rachel") || T.find("great-grandmother")==string("Lea") || T.find("great-grandmother")==string("Tzipi") || T.find("great-grandmother")==string("Mali")));
    CHECK((T.find("great-grandfather")==string("Avi") || T.find("great-grandfather")==string("Yakov") || T.find("great-grandfather")==string("Itzik") || T.find("great-grandfather")==string("Nati")));
    CHECK((T.find("great-great-grandmother")==string("Reut") || T.find("great-great-grandmother")==string("Meytal") || T.find("great-great-grandmother")==string("May") || T.find("great-great-grandmother")==string("Liel") || T.find("great-great-grandmother")==string("Sahar") || T.find("great-great-grandmother")==string("Batel") || T.find("great-great-grandmother")==string("Batia") || T.find("great-great-grandmother")==string("Bracha")));
    CHECK((T.find("great-great-grandfather")==string("Udi") || T.find("great-great-grandfather")==string("Shimon") || T.find("great-great-grandfather")==string("Roei") || T.find("great-great-grandfather")==string("Yarin") || T.find("great-great-grandfather")==string("Noam") || T.find("great-great-grandfather")==string("Yizhak") || T.find("great-great-grandfather")==string("Nitay") || T.find("great-great-grandfather")==string("Neria")));
    CHECK_THROWS(T.find("uncle"));
    CHECK_THROWS(T.find("saba"));
    CHECK_THROWS(T.find("aba"));
};

TEST_CASE("remove function"){
    Tree T("Ariel");
    BuildTree(T);
    T.remove("Udi");
    T.remove("Shimon");
    T.remove("Roei");
    T.remove("Yarin");
    T.remove("Noam");
    T.remove("Yizhak");
    T.remove("Nitay");
    T.remove("Neria");
    T.remove("Reut");
    T.remove("Meytal");
    T.remove("May");
    T.remove("Liel");
    T.remove("Sahar");
    T.remove("Batel");
    T.remove("Batia");
    T.remove("Bracha");
    T.remove("Avi");
    T.remove("Yakov");
    T.remove("Itzik");
    T.remove("Nati");
    T.remove("Rachel");
    T.remove("Lea");
    T.remove("Tzipi");
    T.remove("Mali");
    T.remove("Gabriel");
    T.remove("Gorge");
    T.remove("Ester");
    T.remove("Gladis");
    T.remove("Karen");
    T.remove("Paulo");

    CHECK(T.relation("Paulo")==string("unrelated"));
    CHECK(T.relation("Karen")==string("unrelated"));
    CHECK(T.relation("Gorge")==string("unrelated"));
    CHECK(T.relation("Ester")==string("unrelated"));
    CHECK(T.relation("Gabriel")==string("unrelated"));
    CHECK(T.relation("Gladis")==string("unrelated"));
    CHECK(T.relation("Avi")==string("unrelated"));
    CHECK(T.relation("Rachel")==string("unrelated"));
    CHECK(T.relation("Yakov")==string("unrelated"));
    CHECK(T.relation("Lea")==string("unrelated"));
    CHECK(T.relation("Itzik")==string("unrelated"));
    CHECK(T.relation("Tzipi")==string("unrelated"));
    CHECK(T.relation("Nati")==string("unrelated"));
    CHECK(T.relation("Mali")==string("unrelated"));
    CHECK(T.relation("Udi")==string("unrelated"));
    CHECK(T.relation("Bracha")==string("unrelated"));
    CHECK(T.relation("Shimon")==string("unrelated"));
    CHECK(T.relation("Batel")==string("unrelated"));
    CHECK(T.relation("Roei")==string("unrelated"));
    CHECK(T.relation("Batia")==string("unrelated"));
    CHECK(T.relation("Yarin")==string("unrelated"));
    CHECK(T.relation("Liel")==string("unrelated"));
    CHECK(T.relation("Yizhak")==string("unrelated"));
    CHECK(T.relation("Sahar")==string("unrelated"));
    CHECK(T.relation("Noam")==string("unrelated"));
    CHECK(T.relation("May")==string("unrelated"));
    CHECK(T.relation("Nitay")==string("unrelated"));
    CHECK(T.relation("Meytal")==string("unrelated"));
    CHECK(T.relation("Neria")==string("unrelated"));
    CHECK(T.relation("Reut")==string("unrelated"));
};
