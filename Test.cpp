/**
 * unit test to phonetic search
 * AUTHOR: RoiPeleg
 * */
#include "doctest.h"
#include "PhoneticFinder.hpp"
using namespace phonetic;

#include <string>
using namespace std;


TEST_CASE("Test replacement of v and w") {
    string text = "vvv void";
    CHECK(find(text, "void") == string("void"));
    CHECK(find(text, "woid") == string("void"));
}
TEST_CASE("Test replacement of b, f and p") {
    string text = "bad fun ggg pie";
    CHECK(find(text, "bad") == string("bad"));
    CHECK(find(text, "fad") == string("bad"));
    CHECK(find(text, "pad") == string("bad"));
}

TEST_CASE("Test replacement of g and j") {
    string text = "good job boy";
    CHECK(find(text, "good") == string("good"));
    CHECK(find(text, "jood") == string("good"));
    CHECK(find(text, "joy") == string("boy"));
}

TEST_CASE("Test replacement of c , k and q") {
    string text = "kill cill ql";
    CHECK(find(text, "kill") == string("kill"));
    CHECK(find(text, "cill") == string("kill"));
    CHECK(find(text, "qill") == string("kill"));
}

TEST_CASE("Test replacement of s and z") {
    string text = "zzzz sleep zzz";
    CHECK(find(text, "sleep") == string("sleep"));
    CHECK(find(text, "zleep") == string("sleep"));
}

TEST_CASE("Test replacement of d and t") {
    string text = "dude tt";
    CHECK(find(text, "dude") == string("dude"));
    CHECK(find(text, "tute") == string("dude"));
    CHECK(find(text, "dute") == string("dude"));
}

TEST_CASE("Test replacement of o and u") {
    string text = "oak out ooa";
    CHECK(find(text, "oak") == string("oak"));
    CHECK(find(text, "uak") == string("oak"));
    CHECK(find(text, "out") == string("out"));
    CHECK(find(text, "uut") == string("out"));
    CHECK(find(text, "oot") == string("out"));
}

TEST_CASE("Test replacement of i and y") {
    string text = "island you young imp yoyo";
     (find(text, "island") == string("island"));
    CHECK(find(text, "ysland") == string("island"));
    CHECK(find(text, "you") == string("you"));        
    CHECK(find(text, "iou") == string("you"));
    CHECK(find(text, "imp") == string("imp"));
    CHECK(find(text, "ymp") == string("imp"));
    CHECK(find(text, "young") == string("young"));
    CHECK(find(text, "ioung") == string("young"));
    CHECK(find(text, "yoyo") == string("yoyo"));
    CHECK(find(text, "ioyo") == string("yoyo"));
    CHECK(find(text, "yoio") == string("yoyo"));
}

TEST_CASE("Test replacement of lowercase letters and uppercase letters") {
    string text = "Bob Is a LaWyer";
    CHECK(find(text,"Bob")==string("Bob"));
    CHECK(find(text,"BoB")==string("Bob"));
    CHECK(find(text,"bob")==string("Bob"));
    CHECK(find(text,"boB")==string("Bob"));
}
